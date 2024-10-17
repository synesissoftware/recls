/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearch.cpp
 *
 * Purpose: Implementation of the ReclsFileSearch class for Windows.
 *
 * Created: 16th August 2003
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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

    cbRootDir = recls_align_up_size_(cbRootDir);

#if !defined(STLSOFT_COMPILER_IS_GCC)
    RECLS_ASSERT(cb > STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data));
#endif /* compiler */

    cb  =   STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data);
    cb  +=  (cDirParts) * sizeof(recls_strptrs_t);
    cb  +=  cbRootDir;

    void* pv = malloc(cb);

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
    if (ss_nullptr_k == pv)
    {
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

    free(pv);
}
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */

inline void ReclsFileSearch::operator delete(void* pv)
{
    function_scope_trace("ReclsFileSearch::operator delete");

    free(pv);
}

/* static */ recls_rc_t
ReclsFileSearch::FindAndCreate(
    recls_char_t const*         searchDir
,   size_t                      searchDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   ReclsFileSearch**           ppsi
)
{
    function_scope_trace("ReclsFileSearch::FindAndCreate");


    // pre-conditions

    RECLS_ASSERT(ss_nullptr_k != searchDir);
    RECLS_ASSERT(searchDirLen == types::traits_type::str_len(searchDir));
    RECLS_ASSERT(types::traits_type::is_path_absolute(searchDir, searchDirLen));
    RECLS_ASSERT(types::traits_type::has_dir_end(searchDir, searchDirLen));

    RECLS_ASSERT(ss_nullptr_k != pattern);
    RECLS_ASSERT(patternLen == types::traits_type::str_len(pattern));

    RECLS_ASSERT(ss_nullptr_k != ppsi);


    recls_debug1_trace_printf_(
        RECLS_LITERAL("ReclsFileSearch::FindAndCreate(%.*s, %.*s, 0x%08x, %p, %p, ...)")
    ,   int(searchDirLen), searchDir
    ,   int(patternLen), pattern
    ,   flags
    ,   pfn
    ,   param
    );

    return FindAndCreate_(searchDir, searchDirLen, pattern, patternLen, flags, pfn, param, ppsi);
}

/* static */ recls_rc_t
ReclsFileSearch::FindAndCreate_(
    recls_char_t const*         searchDir
,   size_t                      searchDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   class_type**                ppsi
)
{
    function_scope_trace("ReclsFileSearch::FindAndCreate_");

    RECLS_ASSERT(ss_nullptr_k != searchDir);
    RECLS_ASSERT(types::traits_type::str_len(searchDir) == searchDirLen);
    RECLS_ASSERT(types::traits_type::is_path_absolute(searchDir, searchDirLen));
    RECLS_ASSERT(types::traits_type::has_dir_end(searchDir, searchDirLen));
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX)
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(searchDir, '\\'));
#else /* ? UNIX */
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(searchDir, '/'));
#endif /* UNIX */
    RECLS_ASSERT(ss_nullptr_k != pattern);
    RECLS_ASSERT(types::traits_type::str_len(pattern) == patternLen);
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX)
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(pattern, ';'));
#else /* ? UNIX */
#if 0
    // Does not work, because pattern might be "C:\\dir\\file.ext"
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(pattern, ':'));
#endif /* 0 */
#if 1
    // Would only work for pattern with only one pattern argument
    RECLS_ASSERT(ss_nullptr_k != types::traits_type::str_chr(pattern, ';') || types::traits_type::is_path_absolute(pattern) || ss_nullptr_k == types::traits_type::str_chr(pattern, ':'));
#endif /* 0 */
#endif /* UNIX */

    *ppsi = ss_nullptr_k;

    recls_rc_t rc = RECLS_RC_OK;

    if (!types::traits_type::file_exists(searchDir))
    {
        rc = RECLS_RC_DIRECTORY_NOT_FOUND;
    }
    else if (!types::traits_type::is_directory(searchDir))
    {
        rc = RECLS_RC_PATH_IS_NOT_DIRECTORY;
    }
    else
    {
        // Count the directory parts. This is always done for the ReclsFileSearch class, since it
        // uses them to recurse.
        recls_char_t const*         dir0        =   recls_find_directory_0_(searchDir);
        recls_char_t const* const   end         =   searchDir + searchDirLen;
        size_t const                cDirParts   =   types::count_dir_parts(dir0, end);

        // Create the search handle
        ReclsFileSearch* si;

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
        try
        {
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */
            si = new(cDirParts, sizeof(recls_char_t) * (1 + searchDirLen)) ReclsFileSearch(cDirParts, searchDir, searchDirLen, pattern, patternLen, pfn, param, flags, &rc);
#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
        }
        catch (std::bad_alloc&)
        {
            recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

            si = ss_nullptr_k;
        }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

        if (ss_nullptr_k == si)
        {
            RECLS_ASSERT(RECLS_RC_OK != rc);
        }
        else
        {
            // This is a nasty hack. It's tantamount to ctor & create function, so
            // should be made more elegant soon.
            if (ss_nullptr_k == si->m_dnode)
            {
                delete si;

                if (RECLS_SUCCEEDED(rc))
                {
                    rc = RECLS_RC_NO_MORE_DATA;
                }
            }
            else
            {
                *ppsi = si;

                rc = RECLS_RC_OK;
            }
        }
    }

    RECLS_ASSERT(RECLS_RC_OK == rc || ss_nullptr_k == *ppsi);

    return rc;
}

recls_char_t const*
ReclsFileSearch::calc_rootDir_(
    size_t              cDirParts
,   recls_char_t const* searchDir
,   size_t              searchDirLen
)
{
    function_scope_trace("ReclsFileSearch::calc_rootDir_");

    // Root dir is located after file parts, and before pattern
    recls_char_t* s = ::stlsoft::sap_cast<recls_char_t*>(&data[cDirParts * sizeof(recls_strptrs_t)]);

    types::traits_type::char_copy(s, searchDir, searchDirLen);
    s[searchDirLen] = '\0';

    return s;
}

ReclsFileSearch::ReclsFileSearch(
    size_t                      cDirParts
,   recls_char_t const*         searchDir
,   size_t                      searchDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   recls_uint32_t              flags
,   recls_rc_t*                 prc
)
    : m_flags(flags)
    , m_searchDir(calc_rootDir_(cDirParts, searchDir, searchDirLen))
    , m_searchDirLen(searchDirLen)
    , m_pfn(pfn)
    , m_param(param)
{
    function_scope_trace("ReclsFileSearch::ReclsFileSearch");

    RECLS_ASSERT(ss_nullptr_k != searchDir);
    RECLS_ASSERT(types::traits_type::str_len(searchDir) == searchDirLen);
    RECLS_ASSERT(types::traits_type::is_path_absolute(searchDir));
    RECLS_ASSERT(types::traits_type::has_dir_end(searchDir, searchDirLen));

    RECLS_ASSERT(ss_nullptr_k != pattern);
    RECLS_ASSERT(ss_nullptr_k != types::traits_type::str_chr(pattern, types::traits_type::path_separator()) || types::traits_type::str_len(pattern) < types::traits_type::path_max());

    RECLS_ASSERT(ss_nullptr_k != prc);

#if 0
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    RECLS_MESSAGE_ASSERT("Root directory has improper format",  (isalpha(searchDir[0]) && searchDir[1] == ':') || (searchDir[0] == '\\' && searchDir[1] == '\\'));
#elif defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    RECLS_MESSAGE_ASSERT("Root directory has improper format",  searchDir[0] == '/' || (isalpha(searchDir[0]) && searchDir[1] == ':') || (searchDir[0] == '\\' && searchDir[1] == '\\'));
#elif defined(RECLS_PLATFORM_IS_UNIX) /* ? really unix */
    RECLS_MESSAGE_ASSERT("Root directory has improper format", searchDir[0] == '/');
    RECLS_MESSAGE_ASSERT("UNIX filesystems do not allow drive specifications", searchDir[1] != ':');
#else /* ? platform*/
# error Platform not recognised
#endif /* platform*/

    // Now start the search
    m_dnode = ReclsFileSearchDirectoryNode::FindAndCreate(m_flags, searchDir, m_searchDirLen, pattern, patternLen, pfn, param, prc);
}

ReclsFileSearch::~ReclsFileSearch() STLSOFT_NOEXCEPT
{
    function_scope_trace("ReclsFileSearch::~ReclsFileSearch");
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

