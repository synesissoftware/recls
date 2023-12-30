/* /////////////////////////////////////////////////////////////////////////
 * File:        api.search.cpp
 *
 * Purpose:     Main (platform-independent) implementation file for the recls API.
 *
 * Created:     16th August 2003
 * Updated:     30th December 2023
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
#include "impl.types.hpp"
#include "impl.util.h"     // for recls_strlen_(), recls_strncpy_()
#include "impl.entryfunctions.h"
#include "impl.constants.hpp"
#include "impl.cover.h"

#include "ReclsSearch.hpp"
#include "ReclsFileSearch.hpp"

#include "impl.trace.h"

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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.core.search")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#if defined(RECLS_PLATFORM_IS_WINDOWSx)
struct cdecl_process_fn_translator
{
    typedef int (RECLS_CALLCONV_STDDECL *stdcall_process_fn_t)( recls_entry_t               hEntry
                                                            ,   recls_process_fn_param_t    param);

    cdecl_process_fn_translator(hrecls_process_fn_t         pfn
                            ,   recls_process_fn_param_t    param)
        : m_pfn((stdcall_process_fn_t)pfn)
        , m_param(param)
    {
        RECLS_COVER_MARK_LINE();
    }

    operator recls_process_fn_param_t()
    {
        RECLS_COVER_MARK_LINE();

        return this;
    }

    static int RECLS_CALLCONV_DEFAULT func( recls_entry_t               hEntry
                                        ,   recls_process_fn_param_t    param)
    {
        RECLS_COVER_MARK_LINE();

        cdecl_process_fn_translator *pThis = (cdecl_process_fn_translator*)param;

        return (*pThis->m_pfn)(hEntry, pThis->m_param);
    }

private:
    stdcall_process_fn_t        m_pfn;
    recls_process_fn_param_t    m_param;
};

struct cdecl_progress_fn_translator
{
    typedef int (RECLS_CALLCONV_STDDECL *stdcall_progress_fn_t)(recls_char_t const*         dir
                                                            ,   size_t                      dirLen
                                                            ,   recls_process_fn_param_t    param
                                                            ,   void*                       reserved0
                                                            ,   recls_uint32_t              reserved1);

    cdecl_progress_fn_translator(hrecls_progress_fn_t           pfn
                            ,   recls_process_fn_param_t    param)
        : m_pfn((stdcall_progress_fn_t)pfn)
        , m_param(param)
    {
        RECLS_COVER_MARK_LINE();
    }

    operator recls_process_fn_param_t()
    {
        RECLS_COVER_MARK_LINE();

        return this;
    }

    static int RECLS_CALLCONV_DEFAULT func( recls_char_t const*         dir
                                        ,   size_t                      dirLen
                                        ,   recls_process_fn_param_t    param
                                        ,   void*                       reserved0
                                        ,   recls_uint32_t              reserved1)
    {
        RECLS_COVER_MARK_LINE();

        cdecl_progress_fn_translator* pThis = (cdecl_progress_fn_translator*)param;

        return (*pThis->m_pfn)(dir, dirLen, pThis->m_param, reserved0, reserved1);
    }

private:
    stdcall_progress_fn_t       m_pfn;
    recls_process_fn_param_t    m_param;
};

#endif /* RECLS_PLATFORM_IS_WINDOWS */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

using ::recls::impl::ReclsFileSearch;
using ::recls::impl::ReclsSearch;
using ::recls::impl::constants;
using ::recls::impl::types;

using ::recls::impl::Entry_BlockCount;
using ::recls::impl::Entry_Copy;
using ::recls::impl::Entry_Release;

using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_warning_trace_printf_;
using ::recls::impl::recls_info_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;
using ::recls::impl::recls_get_home_;
using ::recls::impl::recls_is_home_start_;
using ::recls::impl::recls_is_valid_pattern_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * search control
 */

RECLS_API Recls_Search(
    recls_char_t const* searchRoot
,   recls_char_t const* pattern
,   recls_uint32_t      flags
,   hrecls_t*           phSrch
)
{
    function_scope_trace("Recls_Search");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_Search(%s, %s, %08x, ...)"), stlsoft::c_str_ptr(searchRoot), stlsoft::c_str_ptr(pattern), flags);

    RECLS_COVER_MARK_LINE();

    return Recls_SearchFeedback(searchRoot, pattern, flags, NULL, NULL, phSrch);
}

RECLS_API Recls_SearchFeedback(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   hrecls_t*                   phSrch
)
{
    function_scope_trace("Recls_SearchFeedback");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SearchFeedback(%s, %s, 0x%04x, ..., %p, ...)"), stlsoft::c_str_ptr(searchRoot), stlsoft::c_str_ptr(pattern), flags, param);

    RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_WINDOWSx)
    cdecl_progress_fn_translator    translator(pfn, param);

    if (NULL != pfn &&
        (flags & RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS))
    {
        RECLS_COVER_MARK_LINE();

        pfn     =   &cdecl_progress_fn_translator::func;
        param   =   translator;
    }
#endif /* RECLS_PLATFORM_IS_WINDOWS */

    RECLS_ASSERT(NULL != phSrch);

    *phSrch = static_cast<hrecls_t>(0);

    recls_rc_t  rc;

#ifdef RECLS_EXCEPTION_SUPPORT_
    try
    {
#endif /* RECLS_EXCEPTION_SUPPORT_ */
        RECLS_COVER_MARK_LINE();

        // Default the input parameters
        types::file_path_buffer_type   home;

        // Default the pattern?
        if (NULL == pattern)
        {
            RECLS_COVER_MARK_LINE();

            // Pre-1.8.6, this always defaulted to '*.*' (or '*')

            if (NULL != searchRoot &&
                (   NULL != types::traits_type::str_pbrk(searchRoot, RECLS_LITERAL("*?")) ||
                    types::traits_type::is_file(searchRoot)))
            {
                RECLS_COVER_MARK_LINE();

                std::swap(searchRoot, pattern);
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                // Set to '*' / '*.*'
                pattern = types::traits_type::pattern_all();
            }
        }

        // Default the search root?
        if (NULL == searchRoot ||
            0 == *searchRoot)
        {
            RECLS_COVER_MARK_LINE();

            if (USE_TILDE_ON_NO_SEARCHROOT & flags)
            {
                RECLS_COVER_MARK_LINE();

                searchRoot = constants::home().data();
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                // Pre-1.8.6, this always defaulted to '.'

#if defined(RECLS_PLATFORM_IS_UNIX)
                recls_char_t const* sep =   types::traits_type::str_pbrk(pattern, RECLS_LITERAL("|:"));
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
                recls_char_t const* sep =   types::traits_type::str_pbrk(pattern, RECLS_LITERAL("|;"));
#endif /* platform */
                recls_char_t const* wc  =   NULL;

                STLSOFT_SUPPRESS_UNUSED(wc);

                if (NULL == sep &&
                    types::traits_type::is_path_rooted(pattern) &&
                    NULL != (wc = types::traits_type::str_pbrk(pattern, RECLS_LITERAL("*?"))))
                {
                    RECLS_COVER_MARK_LINE();

//                  const size_t    len     =   types::traits_type::str_len(pattern);
                    recls_char_t*   file0   =   types::traits_type::str_rchr(pattern, RECLS_LITERAL('/'));
#if defined(RECLS_PLATFORM_IS_UNIX)
                    recls_char_t*   file1   =   NULL;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
                    recls_char_t*   file1   =   types::traits_type::str_rchr(pattern, RECLS_LITERAL('\\'));
#endif /* platform */
                    recls_char_t*   file    =   (NULL == file0) ? file1 : (NULL == file1) ? file0 : (file0 < file1) ? file1 : file0;

                    // Not valid if wildcard comes before file, or pattern too long
                    if (wc < file ||
                        static_cast<size_t>(file - pattern) > home.size() - 1)
                    {
                        RECLS_COVER_MARK_LINE();

                        searchRoot = constants::default_search_root().data();
                    }
                    else
                    {
                        RECLS_COVER_MARK_LINE();

                        size_t cch = static_cast<size_t>(file - pattern) + 1;
                        types::traits_type::char_copy(&home[0], pattern, cch);
                        home[cch] = RECLS_LITERAL('\0');

                        searchRoot  =   home.data();
                        pattern     =   file + 1;
                    }
                }
                else
                {
                    RECLS_COVER_MARK_LINE();

                    searchRoot = constants::default_search_root().data();
                }
            }
        }
        else
        // Handle tilde
        if (recls_is_home_start_(searchRoot))
        {
            RECLS_COVER_MARK_LINE();

            size_t  n       =   recls_get_home_(&home[0], home.size());
            size_t  rootLen =   types::traits_type::str_len(searchRoot);

            if (0 == n)
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_NO_HOME;
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                // recls_get_home_() always has a trailing path-name separator
                RECLS_ASSERT(types::traits_type::has_dir_end(&home[0]));

                if (rootLen + n > home.size())
                {
                    RECLS_COVER_MARK_LINE();

                    return RECLS_RC_PATH_LIMIT_EXCEEDED;
                }
                else
                {
                    RECLS_COVER_MARK_LINE();

                    // append the search root, skipping the tilde
                    //
                    // - &home[0] + (n - 1) drops the trailing separator on the home directory
                    // - searchRoot + 1 skips the tilde
                    // - rootLen includes the NUL terminator
                    types::traits_type::char_copy(&home[0] + (n - 1), searchRoot + 1, rootLen);

                    /* rootLen = n + rootLen - 1; */

                    searchRoot = home.c_str();
                }
            }
        }

        const size_t        patternLen = types::traits_type::str_len(pattern);
        types::buffer_type  pattern_(1 + patternLen);

#ifndef RECLS_EXCEPTION_SUPPORT_
        if (0 == pattern_.size())
        {
            RECLS_COVER_MARK_LINE();

            rc = RECLS_RC_OUT_OF_MEMORY;
        }
        else
#endif /* !RECLS_EXCEPTION_SUPPORT_ */
        {
            RECLS_COVER_MARK_LINE();

            types::path_type path;

            if (NULL != types::traits_type::str_chr(pattern, types::traits_type::path_separator()) ||
                NULL != types::traits_type::str_chr(pattern, RECLS_LITERAL('|')))
            {
                RECLS_COVER_MARK_LINE();

                // Has the separator, so we can proceed. (If any are too long, they will be
                // caught by recls_is_valid_pattern_()

                pattern = types::traits_type::char_copy(&pattern_[0], pattern, pattern_.size());

                // We need to alter the path name separator, to the appropriate slash-form
                //
                // We also replace | with the appropriate path-name separator.

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
                std::replace(&pattern_[0], &pattern_[0] + patternLen, RECLS_LITERAL('\\'), RECLS_LITERAL('/'));
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

#if defined(RECLS_PLATFORM_IS_UNIX)
                std::replace(&pattern_[0], &pattern_[0] + patternLen, RECLS_LITERAL('|'), RECLS_LITERAL(':'));
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
                std::replace(&pattern_[0], &pattern_[0] + patternLen, RECLS_LITERAL('/'), RECLS_LITERAL('\\'));
                std::replace(&pattern_[0], &pattern_[0] + patternLen, RECLS_LITERAL('|'), RECLS_LITERAL(';'));
# endif /* platform */

                rc = RECLS_RC_OK;
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                // Cater for the situation whereby the pattern is a file

                if (types::traits_type::str_len(pattern) > types::traits_type::path_max())
                {
                    RECLS_COVER_MARK_LINE();

                    rc = RECLS_RC_PATH_LIMIT_EXCEEDED;
                }
                else
                {
                    RECLS_COVER_MARK_LINE();

                    rc = RECLS_RC_OK;

                    types::file_path_buffer_type searchRoot_;

                    path = pattern;

                    if (path.exists())
                    {
                        RECLS_COVER_MARK_LINE();

                        path.make_absolute(true);
#ifdef RECLS_EXCEPTION_SUPPORT_
                        path.canonicalise(true);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

#ifdef RECLS_STLSOFT_1_10_B01_OR_LATER
                        recls_char_t const* file    =   path.get_file().ptr;
#else /* ? RECLS_STLSOFT_1_10_B01_OR_LATER */
                        recls_char_t const* file    =   path.get_file();
#endif /* RECLS_STLSOFT_1_10_B01_OR_LATER */
                        const size_t        cch     =   static_cast<size_t>(file - path.c_str());

                        types::traits_type::char_copy(&searchRoot_[0], path.c_str(), cch);
                        searchRoot_[cch] = '\0';
                        searchRoot = searchRoot_.c_str();

                        pattern = file;

                        if (0 == (flags & RECLS_F_TYPEMASK))
                        {
                            RECLS_COVER_MARK_LINE();

                            if (types::traits_type::is_directory(path.c_str()))
                            {
                                RECLS_COVER_MARK_LINE();

                                flags |= RECLS_F_DIRECTORIES;
                            }
                            else
                            {
                                RECLS_COVER_MARK_LINE();

                                flags |= RECLS_F_FILES;
                            }
                        }
                    }
                }
            }

            if (RECLS_SUCCEEDED(rc))
            {
                RECLS_COVER_MARK_LINE();

                // Default the flags
                if (0 == (flags & RECLS_F_TYPEMASK))
                {
                    RECLS_COVER_MARK_LINE();

                    flags |= RECLS_F_FILES;
                }

                if (0 == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
                {
                    RECLS_COVER_MARK_LINE();

                    rc = RECLS_RC_INVALID_SEARCH_TYPE;
                }
                // Validate the pattern.
                else
                {
                    RECLS_COVER_MARK_LINE();

                    rc = recls_is_valid_pattern_(pattern, flags, types::traits_type::path_max());
                }
            }

            if (RECLS_SUCCEEDED(rc))
            {
                RECLS_COVER_MARK_LINE();

                ReclsFileSearch *si;
                size_t const    rootDirLen  =   types::traits_type::str_len(searchRoot);
                size_t const    patternLen2 =   types::traits_type::str_len(pattern);

                RECLS_ASSERT(NULL != searchRoot);
                RECLS_ASSERT(NULL != pattern);

                rc = ReclsFileSearch::FindAndCreate(searchRoot, rootDirLen, pattern, patternLen2, flags, pfn, param, &si);

                if (RECLS_SUCCEEDED(rc))
                {
                    RECLS_COVER_MARK_LINE();

                    *phSrch = ReclsSearch::ToHandle(si);

                    rc = RECLS_RC_OK;
                }
            }
        }
#ifdef RECLS_EXCEPTION_SUPPORT_
    }
# if _STLSOFT_VER >= 0x010d0000
    catch(platformstl::filesystem_exception& x)
    {
        RECLS_COVER_MARK_LINE();

        return RECLS_RC_?;
    }
#  error Implement these changes to STLSoft, including winstl::path_too_long_exception.
# endif /* 0 */
# ifdef STLSOFT_CF_NOTHROW_BAD_ALLOC
    catch(std::bad_alloc&)
    {
        RECLS_COVER_MARK_LINE();

        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        rc = RECLS_RC_OUT_OF_MEMORY;
    }
# endif /* STLSOFT_CF_NOTHROW_BAD_ALLOC */
    catch(std::exception &x)
    {
        RECLS_COVER_MARK_LINE();

        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_Search(): %s"), x.what());

        rc = RECLS_RC_UNEXPECTED;
    }
#endif /* RECLS_EXCEPTION_SUPPORT_ */

    RECLS_MESSAGE_ASSERT(RECLS_LITERAL("Must not return a success code with a null search handle"), RECLS_RC_OK != rc || NULL != *phSrch);

    RECLS_COVER_MARK_LINE();

    return rc;
}

/** Closes the given search */
RECLS_FNDECL(void) Recls_SearchClose(hrecls_t hSrch)
{
    function_scope_trace("Recls_SearchClose");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SearchClose(%p)"), hSrch);

    ReclsSearch *si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", NULL != si);

    RECLS_COVER_MARK_LINE();

    delete si;
}

/* /////////////////////////////////////////////////////////////////////////
 * search enumeration
 */

RECLS_API Recls_SearchProcessFeedback(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_process_fn_t         pfn
,   recls_process_fn_param_t    param
,   hrecls_progress_fn_t        pfnProgress
,   recls_process_fn_param_t    paramProgress
)
{
    function_scope_trace("Recls_SearchProcess");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SearchProcessFeedback(%s, %s, 0x%04x, ..., %p, ..., %p)"), stlsoft::c_str_ptr(searchRoot), stlsoft::c_str_ptr(pattern), flags, param, paramProgress);

    RECLS_ASSERT(NULL != pfn);

    RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_WINDOWSx)
    cdecl_process_fn_translator translator(pfn, param);

    if (NULL != pfn &&
        (flags & RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS))
    {
        RECLS_COVER_MARK_LINE();

        pfn     =   &cdecl_process_fn_translator::func;
        param   =   translator;
    }
#endif /* RECLS_PLATFORM_IS_WINDOWS */

    hrecls_t    hSrch;
    recls_rc_t  rc  =   Recls_SearchFeedback(searchRoot, pattern, flags, pfnProgress, paramProgress, &hSrch);

    if (RECLS_SUCCEEDED(rc))
    {
        RECLS_COVER_MARK_LINE();

        recls_entry_t info;

        do
        {
            RECLS_COVER_MARK_LINE();

            rc = Recls_GetDetails(hSrch, &info);

            if (RECLS_FAILED(rc))
            {
                RECLS_COVER_MARK_LINE();

                break;
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                int res;

#if defined(RECLS_PLATFORM_IS_WINDOWS)
                if (flags & RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS)
                {
                    RECLS_COVER_MARK_LINE();

                    typedef int (RECLS_CALLCONV_STDDECL *stdcall_process_fn_t)( recls_entry_t               hEntry
                                                                            ,   recls_process_fn_param_t    param);

                    union
                    {
                        stdcall_process_fn_t    pfn_stdcall;
                        hrecls_process_fn_t     pfn_cdecl;
                    } u;

                    RECLS_COVER_MARK_LINE();

                    u.pfn_cdecl = pfn;

                    res = (*u.pfn_stdcall)(info, param);
                }
                else
#endif /* RECLS_PLATFORM_IS_WINDOWS */
                {
                    RECLS_COVER_MARK_LINE();

                    res = (*pfn)(info, param);
                }

                Recls_CloseDetails(info);

                if (0 == res)
                {
                    RECLS_COVER_MARK_LINE();

                    rc = RECLS_RC_SEARCH_CANCELLED;

                    break;
                }
            }
        }
        while (RECLS_SUCCEEDED(rc = Recls_GetNext(hSrch)));

        Recls_SearchClose(hSrch);
    }

    if (RECLS_RC_NO_MORE_DATA == rc)
    {
        RECLS_COVER_MARK_LINE();

        rc = RECLS_RC_OK;
    }

    RECLS_COVER_MARK_LINE();

    return rc;
}

RECLS_API Recls_SearchProcess(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_process_fn_t         pfn
,   recls_process_fn_param_t    param
)
{
    function_scope_trace("Recls_SearchProcess");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SearchProcess(%s, %s, 0x%04x, ..., %p)"), stlsoft::c_str_ptr(searchRoot), stlsoft::c_str_ptr(pattern), flags, param);

    RECLS_COVER_MARK_LINE();

    return Recls_SearchProcessFeedback(searchRoot, pattern, flags, pfn, param, NULL, NULL);
}

RECLS_API Recls_GetNext(hrecls_t hSrch)
{
    function_scope_trace("Recls_GetNext");

    ReclsSearch *si =   ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", NULL != si);

    RECLS_COVER_MARK_LINE();

    return si->GetNext();
}

RECLS_API Recls_GetDetails(
    hrecls_t        hSrch
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_GetDetails");

    ReclsSearch* si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", NULL != si);
    RECLS_ASSERT(NULL != pinfo);

    RECLS_COVER_MARK_LINE();

    return si->GetDetails(pinfo);
}

RECLS_API Recls_GetNextDetails(
    hrecls_t        hSrch
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_GetNextDetails");

    ReclsSearch *si =   ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", NULL != si);

    RECLS_COVER_MARK_LINE();

    return si->GetNextDetails(pinfo);
}

/***************************************
 * File entry info structure
 */

RECLS_FNDECL(void) Recls_CloseDetails(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_CloseDetails");

    RECLS_ASSERT(NULL != fileInfo);

    RECLS_COVER_MARK_LINE();

    Entry_Release(fileInfo);
}

RECLS_API Recls_CopyDetails(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_CopyDetails");

    RECLS_ASSERT(NULL != pinfo);

    RECLS_COVER_MARK_LINE();

    return Entry_Copy(fileInfo, pinfo);
}

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

