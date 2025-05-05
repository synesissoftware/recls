/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearch.cpp
 *
 * Purpose: Implementation of the ReclsFileSearch class.
 *
 * Created: 16th August 2003
 * Updated: 5th May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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
#include "impl.assert.h"
#include "impl.root.h"
#include "impl.util.h"
#include "impl.string.hpp"

#include "ReclsSearch.hpp"
#include "ReclsFileSearch.hpp"
#include "ReclsFileSearchDirectoryNode.hpp"
#include "ReclsFileSearchDirectoryControlAlwaysAllow.hpp"
#include "ReclsFileSearchDirectoryControlPreventInfiniteLoops.hpp"

#if __cplusplus < 201103L
# include <stlsoft/conversion/union_cast.hpp>
#endif

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

inline
void*
ReclsFileSearch::operator new(
    size_t  cb
,   size_t  cDirParts
,   size_t  cbRootDir
,   size_t  cbPatterns
)
{
    function_scope_trace("ReclsFileSearch::operator new");

    cbRootDir = recls_align_up_size_(cbRootDir);

#if !defined(STLSOFT_COMPILER_IS_GCC)
    RECLS_ASSERT(cb > STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data));
#endif /* compiler */

    cb  =   STLSOFT_RAW_OFFSETOF(ReclsFileSearch, data);
    cb  +=  (cDirParts) * sizeof(recls_strptrs_t);
    cb  +=  cbRootDir;
    cb  +=  cbPatterns;

    void* const pv = malloc(cb);

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

inline
void
ReclsFileSearch::operator delete(
    void*       pv
,   size_t   /* cDirParts */
,   size_t   /* cbRootDir */
,   size_t   /* cbPatterns */
)
{
    function_scope_trace("ReclsFileSearch::operator delete");

    free(pv);
}
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */

inline
void
ReclsFileSearch::operator delete(void* pv)
{
    function_scope_trace("ReclsFileSearch::operator delete");

    free(pv);
}

/* static */ recls_rc_t
ReclsFileSearch::FindAndCreate(
    char_type const*            searchDir
,   size_t                      searchDirLen
,   char_type const*            patterns
,   size_t                      patternsLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_progress_fn_param_t   param
,   ReclsFileSearch**           ppsi
)
{
    function_scope_trace("ReclsFileSearch::FindAndCreate");

    // pre-conditions

    RECLS_ASSERT(ss_nullptr_k != searchDir);
    RECLS_ASSERT(searchDirLen == types::traits_type::str_len(searchDir));
    RECLS_ASSERT(types::traits_type::is_path_absolute(searchDir, searchDirLen));
    RECLS_ASSERT(types::traits_type::has_dir_end(searchDir, searchDirLen));

    RECLS_ASSERT(ss_nullptr_k != patterns);
    RECLS_ASSERT(patternsLen == types::traits_type::str_len(patterns));

    RECLS_ASSERT(ss_nullptr_k != ppsi);


    recls_debug1_trace_printf_(
        RECLS_LITERAL("ReclsFileSearch::FindAndCreate(%.*s, %.*s, 0x%08x, %p, %p, ...)")
    ,   int(searchDirLen), searchDir
    ,   int(patternsLen), patterns
    ,   flags
#if __cplusplus < 201103L
    ,   static_cast<void const*>(stlsoft::union_cast<void*>(pfn))
#else
    ,   STLSOFT_C_CAST(void*, pfn)
#endif
    ,   param
    );

    return FindAndCreate_(searchDir, searchDirLen, patterns, patternsLen, flags, pfn, param, ppsi);
}

/* static */ recls_rc_t
ReclsFileSearch::FindAndCreate_(
    char_type const*            searchDir
,   size_t                      searchDirLen
,   char_type const*            patterns
,   size_t                      patternsLen
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_progress_fn_param_t   param
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
    RECLS_ASSERT(ss_nullptr_k != patterns);
    RECLS_ASSERT(types::traits_type::str_len(patterns) == patternsLen);
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX)
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(patterns, ';'));
#else /* ? UNIX */
#if 0
    // Does not work, because pattern might be "C:\\dir\\file.ext"
    RECLS_ASSERT(ss_nullptr_k == types::traits_type::str_chr(patterns, ':'));
#endif /* 0 */
#if 1
    // Would only work for pattern with only one pattern argument
    RECLS_ASSERT(ss_nullptr_k != types::traits_type::str_chr(patterns, ';') || types::traits_type::is_path_absolute(patterns) || ss_nullptr_k == types::traits_type::str_chr(patterns, ':'));
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
        char_type const*        dir0        =   recls_find_directory_0_(searchDir);
        char_type const* const  end         =   searchDir + searchDirLen;
        size_t const            cDirParts   =   types::count_dir_parts(dir0, end);

        // Create the search handle
        ReclsFileSearch* si;

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
        try
        {
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */
            si = new(cDirParts, sizeof(char_type) * (1 + searchDirLen), sizeof(char_type) * (1 + patternsLen)) ReclsFileSearch(cDirParts, searchDir, searchDirLen, patterns, patternsLen, pfn, param, flags, &rc);
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

ReclsSearchDirectoryControl*
ReclsFileSearch::create_dc_(
    recls_uint32_t      flags
)
{
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    flags |= RECLS_F_NO_BREAK_INFINITE_LOOPS;
#endif

    if (0 == (RECLS_F_NO_BREAK_INFINITE_LOOPS & flags))
    {
        return new ReclsFileSearchDirectoryControlPreventInfiniteLoops(flags);
    }
    else
    {
        return new ReclsFileSearchDirectoryControlAlwaysAllow(flags);
    }
}

ReclsFileSearch::char_type const*
ReclsFileSearch::emplace_patterns_(
    size_t              cDirParts
,   size_t              searchDirLen
,   char_type const*    patterns
,   size_t              patternsLen
)
{
    function_scope_trace("ReclsFileSearch::emplace_patterns_");

    // Patterns located after directory parts and patterns

    size_t const        cbOffset    =   0
                                    +   sizeof(recls_strptrs_t) * cDirParts
                                    +   sizeof(char_type) * (1 + searchDirLen)
                                    +   0;
    char_type* const    s           =   ::stlsoft::sap_cast<char_type*>(&data[cbOffset]);

    types::traits_type::char_copy(s, patterns, patternsLen);
    s[patternsLen] = '\0';

    return s;
}

ReclsFileSearch::char_type const*
ReclsFileSearch::emplace_rootDir_(
    size_t              cDirParts
,   char_type const*    searchDir
,   size_t              searchDirLen
)
{
    function_scope_trace("ReclsFileSearch::emplace_rootDir_");

    // Search-dir located after directory parts, and before patterns

    size_t const        cbOffset    =   0
                                    +   sizeof(recls_strptrs_t) * cDirParts
                                    +   0;
    char_type* const    s           =   ::stlsoft::sap_cast<char_type*>(&data[cbOffset]);

    types::traits_type::char_copy(s, searchDir, searchDirLen);
    s[searchDirLen] = '\0';

    return s;
}

ReclsFileSearch::ReclsFileSearch(
    size_t                      cDirParts
,   char_type const*            searchDir
,   size_t                      searchDirLen
,   char_type const*            patterns
,   size_t                      patternsLen
,   hrecls_progress_fn_t        pfn
,   recls_progress_fn_param_t   param
,   recls_uint32_t              flags
,   recls_rc_t*                 prc
)
    : m_flags(flags)
    , m_dc(create_dc_(flags))
    , m_searchDir(emplace_rootDir_(cDirParts, searchDir, searchDirLen))
    , m_searchDirLen(searchDirLen)
    , m_patterns(emplace_patterns_(cDirParts, searchDirLen, patterns, patternsLen))
    , m_patternsLen(patternsLen)
    , m_pfn(pfn)
    , m_param(param)
{
    function_scope_trace("ReclsFileSearch::ReclsFileSearch");

    RECLS_ASSERT(ss_nullptr_k != searchDir);
    RECLS_ASSERT(types::traits_type::str_len(searchDir) == searchDirLen);
    RECLS_ASSERT(types::traits_type::is_path_absolute(searchDir));
    RECLS_ASSERT(types::traits_type::has_dir_end(searchDir, searchDirLen));

    RECLS_ASSERT(ss_nullptr_k != patterns);
    RECLS_ASSERT(ss_nullptr_k != types::traits_type::str_chr(patterns, types::traits_type::path_separator()) || types::traits_type::str_len(patterns) < types::traits_type::path_max());

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
    m_dnode = ReclsFileSearchDirectoryNode::FindAndCreate(
        m_flags
    ,   m_dc
    ,   m_searchDir, m_searchDirLen
    ,   m_patterns, m_patternsLen
    ,   m_pfn, m_param
    ,   prc
    );
}

ReclsFileSearch::~ReclsFileSearch() STLSOFT_NOEXCEPT
{
    function_scope_trace("ReclsFileSearch::~ReclsFileSearch");

    delete m_dc;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

