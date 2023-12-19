/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearch.cpp
 *
 * Purpose:     Implementation of the ReclsFileSearch class for Windows.
 *
 * Created:     16th August 2003
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "impl.util.h"
#include "impl.string.hpp"
#include "impl.cover.h"

#include "ReclsSearch.hpp"
#include "ReclsFileSearch.hpp"
#include "ReclsFileSearchDirectoryNode.hpp"

#include "impl.trace.h"

#include <ctype.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * utility functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * ReclsFileSearch
 */

inline void* ReclsFileSearch::operator new(size_t cb, size_t cDirParts, size_t cbRootDir)
{
    function_scope_trace("ReclsFileSearch::operator new");

    RECLS_COVER_MARK_LINE();

    cbRootDir = recls_align_up_size_(cbRootDir);

#if !defined(STLSOFT_COMPILER_IS_GCC)
    RECLS_ASSERT(cb > STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data));
#endif /* compiler */

    cb  =   STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data);
    cb  +=  (cDirParts) * sizeof(recls_strptrs_t);
    cb  +=  cbRootDir;

    void* pv = malloc(cb);

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
    if(NULL == pv)
    {
        RECLS_COVER_MARK_LINE();

        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        throw std::bad_alloc();
    }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

    return pv;
}

#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
inline void ReclsFileSearch::operator delete(void* pv, size_t /* cDirParts */, size_t /* cbRootDir */)
{
    function_scope_trace("ReclsFileSearch::operator delete");

    RECLS_COVER_MARK_LINE();

    free(pv);
}
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */

inline void ReclsFileSearch::operator delete(void* pv)
{
    function_scope_trace("ReclsFileSearch::operator delete");

    RECLS_COVER_MARK_LINE();

    free(pv);
}

/* static */ recls_rc_t ReclsFileSearch::FindAndCreate(
    recls_char_t const*         rootDir
,   size_t                      /* rootDirLen */
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   ReclsFileSearch**           ppsi
)
{
    RECLS_ASSERT(NULL != rootDir);
    RECLS_ASSERT(NULL != pattern);
    RECLS_ASSERT(NULL != ppsi);

    function_scope_trace("ReclsFileSearch::FindAndCreate");

    RECLS_COVER_MARK_LINE();

    recls_debug1_trace_printf_(RECLS_LITERAL("ReclsFileSearch::FindAndCreate(%s, %s, 0x%08x)"), rootDir, pattern, flags);

    types::file_path_buffer_type    fullPath;
    size_t                          cchFullPath;

    cchFullPath = types::traits_type::get_full_path_name(rootDir, fullPath.size(), &fullPath[0]);
    if(0 == cchFullPath)
    {
        recls_debug0_trace_printf_(RECLS_LITERAL("could not retrieve full path of given search directory '%s'"), rootDir);

        RECLS_COVER_MARK_LINE();

        return RECLS_RC_INVALID_NAME;
    }
    else
    {
        recls_debug2_trace_printf_(RECLS_LITERAL("retrieved full path of given search directory '%s' => '%s'"), rootDir, fullPath.c_str());
    }
    if('"' == fullPath[0])
    {
        RECLS_ASSERT('"' == fullPath[cchFullPath - 1]);

        memmove(&fullPath[0], &fullPath[1], sizeof(recls_char_t) * (cchFullPath - 1));
        cchFullPath -= 2;
        fullPath[cchFullPath] = '\0';

    }

    RECLS_COVER_MARK_LINE();

    if(types::traits_type::has_dir_end(&fullPath[0]))
    {
        RECLS_COVER_MARK_LINE();

        cchFullPath = types::traits_type::str_len(types::traits_type::remove_dir_end(&fullPath[0]));
    }

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
    // On Windows systems that are being used to test the UNIX build, we will
    // translate all the backslashes in UNIX-like paths to forward slashes.
    {
        RECLS_COVER_MARK_LINE();

        recls_char_t* const dir0    =   const_cast<recls_char_t *>(recls_find_directory_0_(&fullPath[0]));
        recls_char_t* const end     =   &fullPath[0] + cchFullPath;

        std::replace(dir0, end, '\\', types::traits_type::path_name_separator());
    }

    RECLS_STRING_TEMPLATE_1(recls_char_t)   pattern_(pattern);

    std::replace(pattern_.begin(), pattern_.end(), ';', ':');

    pattern = stlsoft::c_str_ptr(pattern_);

#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

    return FindAndCreate_(fullPath.c_str(), cchFullPath, pattern, patternLen, flags, pfn, param, ppsi);
}

/* static */ recls_rc_t ReclsFileSearch::FindAndCreate_(
    recls_char_t const*         rootDir
,   size_t                      rootDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   class_type**                ppsi
)
{
    function_scope_trace("ReclsFileSearch::FindAndCreate_");

    RECLS_ASSERT(NULL != rootDir);
    RECLS_ASSERT(types::traits_type::str_len(rootDir) == rootDirLen);
    RECLS_ASSERT(types::traits_type::is_path_absolute(rootDir));
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX)
    RECLS_ASSERT(NULL == types::traits_type::str_chr(rootDir, '\\'));
#else /* ? UNIX */
    RECLS_ASSERT(NULL == types::traits_type::str_chr(rootDir, '/'));
#endif /* UNIX */
    RECLS_ASSERT(NULL != pattern);
    RECLS_ASSERT(types::traits_type::str_len(pattern) == patternLen);
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX)
    RECLS_ASSERT(NULL == types::traits_type::str_chr(pattern, ';'));
#else /* ? UNIX */
#if 0
    // Does not work, because pattern might be "C:\\dir\\file.ext"
    RECLS_ASSERT(NULL == types::traits_type::str_chr(pattern, ':'));
#endif /* 0 */
#if 1
    // Would only work for pattern with only one pattern argument
    RECLS_ASSERT(NULL != types::traits_type::str_chr(pattern, ';') || types::traits_type::is_path_absolute(pattern) || NULL == types::traits_type::str_chr(pattern, ':'));
#endif /* 0 */
#endif /* UNIX */

    RECLS_COVER_MARK_LINE();

    *ppsi = NULL;

    recls_rc_t rc = RECLS_RC_OK;

    if(!types::traits_type::file_exists(rootDir))
    {
        RECLS_COVER_MARK_LINE();

        rc = RECLS_RC_DIRECTORY_NOT_FOUND;
    }
    else if(!types::traits_type::is_directory(rootDir))
    {
        RECLS_COVER_MARK_LINE();

        rc = RECLS_RC_PATH_IS_NOT_DIRECTORY;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        // Now we ensure that rootDir has trailing separator

        types::file_path_buffer_type    fullPath_;

        if(!types::traits_type::has_dir_end(rootDir))
        {
            RECLS_COVER_MARK_LINE();

            types::traits_type::char_copy(&fullPath_[0], rootDir, rootDirLen + 1);
            RECLS_ASSERT('\0' == fullPath_[rootDirLen]);

            rootDirLen = types::traits_type::str_len(types::traits_type::ensure_dir_end(&fullPath_[0]));

            rootDir = fullPath_.c_str();
        }

        // Count the directory parts. This is always done for the ReclsFileSearch class, since it
        // uses them to recurse.
        recls_char_t const*         dir0       =   recls_find_directory_0_(rootDir);
        recls_char_t const* const   end         =   rootDir + rootDirLen;
        const size_t                cDirParts   =   types::count_dir_parts(dir0, end);

        // Create the search handle
        ReclsFileSearch* si;

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
        try
        {
            RECLS_COVER_MARK_LINE();

#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */
            si = new(cDirParts, sizeof(recls_char_t) * (1 + rootDirLen)) ReclsFileSearch(cDirParts, rootDir, rootDirLen, pattern, patternLen, pfn, param, flags, &rc);
#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
        }
        catch(std::bad_alloc&)
        {
            RECLS_COVER_MARK_LINE();

            recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

            si = NULL;
        }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

        if(NULL == si)
        {
            RECLS_COVER_MARK_LINE();

            RECLS_ASSERT(RECLS_RC_OK != rc);
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            // This is a nasty hack. It's tantamount to ctor & create function, so
            // should be made more elegant soon.
            if(NULL == si->m_dnode)
            {
                RECLS_COVER_MARK_LINE();

                delete si;

                if(RECLS_SUCCEEDED(rc))
                {
                    rc = RECLS_RC_NO_MORE_DATA;
                }
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                *ppsi = si;

                rc = RECLS_RC_OK;
            }
        }
    }

    RECLS_ASSERT(RECLS_RC_OK == rc || NULL == *ppsi);

    return rc;
}

recls_char_t const* ReclsFileSearch::calc_rootDir_(
    size_t              cDirParts
,   recls_char_t const* rootDir
,   size_t              rootDirLen
)
{
    function_scope_trace("ReclsFileSearch::calc_rootDir_");

    RECLS_COVER_MARK_LINE();

    // Root dir is located after file parts, and before pattern
    recls_char_t* s = ::stlsoft::sap_cast<recls_char_t*>(&data[cDirParts * sizeof(recls_strptrs_t)]);

    types::traits_type::char_copy(s, rootDir, rootDirLen);
    s[rootDirLen] = '\0';

    return s;
}

ReclsFileSearch::ReclsFileSearch(
    size_t                      cDirParts
,   recls_char_t const*         rootDir
,   size_t                      rootDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   recls_uint32_t              flags
,   recls_rc_t*                 prc
)
    : m_flags(flags)
    , m_rootDir(calc_rootDir_(cDirParts, rootDir, rootDirLen))
    , m_rootDirLen(rootDirLen)
    , m_pfn(pfn)
    , m_param(param)
{
    function_scope_trace("ReclsFileSearch::ReclsFileSearch");

    RECLS_ASSERT(NULL != rootDir);
    RECLS_ASSERT(NULL != pattern);
    RECLS_ASSERT(types::traits_type::str_len(rootDir) < types::traits_type::path_max());
    RECLS_ASSERT(NULL != types::traits_type::str_chr(pattern, types::traits_type::path_separator()) || types::traits_type::str_len(pattern) < types::traits_type::path_max());
    RECLS_ASSERT(m_rootDirLen == types::traits_type::str_len(rootDir));
    RECLS_ASSERT(NULL != prc);

#if defined(RECLS_PLATFORM_IS_WINDOWS)
    RECLS_MESSAGE_ASSERT("Root directory has improper format",  (isalpha(rootDir[0]) && rootDir[1] == ':') || (rootDir[0] == '\\' && rootDir[1] == '\\'));
#elif defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    RECLS_MESSAGE_ASSERT("Root directory has improper format",  rootDir[0] == '/' || (isalpha(rootDir[0]) && rootDir[1] == ':') || (rootDir[0] == '\\' && rootDir[1] == '\\'));
#elif defined(RECLS_PLATFORM_IS_UNIX) /* ? really unix */
    RECLS_MESSAGE_ASSERT("Root directory has improper format", rootDir[0] == '/');
    RECLS_MESSAGE_ASSERT("UNIX filesystems do not allow drive specifications", rootDir[1] != ':');
#else /* ? platform*/
# error Platform not recognised
#endif /* platform*/

    RECLS_COVER_MARK_LINE();

    // Now start the search
    m_dnode = ReclsFileSearchDirectoryNode::FindAndCreate(m_flags, rootDir, m_rootDirLen, pattern, patternLen, pfn, param, prc);
}

ReclsFileSearch::~ReclsFileSearch()
{
    function_scope_trace("ReclsFileSearch::~ReclsFileSearch");

    RECLS_COVER_MARK_LINE();
}

/* static */ recls_rc_t ReclsFileSearch::Stat(  recls_char_t const* path
                                            ,   recls_uint32_t      flags
                                            ,   recls_entry_t*      phEntry)
{
    function_scope_trace("ReclsFileSearch::Stat");

    RECLS_COVER_MARK_LINE();

    return ReclsFileSearchDirectoryNode::Stat(path, flags, phEntry);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
