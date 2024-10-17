/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.api.search.cpp
 *
 * Purpose: implementation behind API functions.
 *
 * Created: 16th August 2003
 * Updated: 9th July 2024
 *
 * Home:    http://recls.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include "impl.api.search.h"
#include <recls/assert.h>
#include "impl.constants.hpp"
#include "impl.string.hpp"
#include "impl.types.hpp"
#include "impl.util.h"

#include "ReclsSearch.hpp"
#include "ReclsFileSearch.hpp"

#include <stlsoft/string/c_string/strnchr.h>
#include <stlsoft/string/tokeniser_functions.hpp>

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if 0
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
#elif defined(RECLS_PLATFORM_IS_UNIX)
#else

# error
#endif

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
 * types
 */

enum search_checks_t
{
        CheckNone                           =   0
    ,   CheckRootEmpty                      =   0x00000001
    ,   CheckRootHomeStart                  =   0x00000002
    ,   CheckRootAbsolute                   =   0x00000004
    ,   CheckRootSlashes                    =   0x00000008
    ,   CheckPatternsCanonicalSeparators    =   0x00000010
    ,   CheckPatternsSingleAbsolute         =   0x00000020
};

inline search_checks_t operator |(search_checks_t lhs, search_checks_t rhs)
{
    return search_checks_t(int(lhs) | int(rhs));
}

inline search_checks_t operator &(search_checks_t lhs, search_checks_t rhs)
{
    return search_checks_t(int(lhs) & int(rhs));
}

bool
has_checked(
    search_checks_t checks
,   search_checks_t mask
)
{
    return 0 != (checks & mask);
}

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

recls_char_t const s_path_separators[] =
{
        '|'
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)
    ,   ':'
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    ,   ';'
#else

# error Operating system is not discriminated
#endif
    ,   '\0'
};

/* /////////////////////////////////////////////////////////////////////////
 * helper/internal functions
 */

static
recls_rc_t
Recls_SearchFeedback_x_(
    /* [in] */ char const*                  function
,   /* [in] */ search_checks_t const        checks
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ size_t                       searchRootLen
,   /* [in] */ recls_char_t const*          patterns
,   /* [in] */ size_t                       patternsLen
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_progress_fn_t         pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [out] */ hrecls_t*                   phSrch
);

/* /////////////////////////////////////////////////////////////////////////
 * search control
 */

/* Semantics and responsibility:
 *
 * - take string lengths
 * - catch exceptions
 *
 */
recls_rc_t
Recls_SearchFeedback_(
    /* [in] */ char const*                  function
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          patterns
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_progress_fn_t         pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [out] */ hrecls_t*                   phSrch
)
{
    function_scope_trace("Recls_SearchFeedback_");

    RECLS_ASSERT(ss_nullptr_k == param || ss_nullptr_k != pfn);

    RECLS_ASSERT(ss_nullptr_k != phSrch);

    *phSrch = static_cast<hrecls_t>(0);

#ifdef RECLS_EXCEPTION_SUPPORT_
    try
    {
#endif /* RECLS_EXCEPTION_SUPPORT_ */

        return Recls_SearchFeedback_x_(
            function
        ,   CheckNone
        ,   searchRoot
        ,   stlsoft::c_str_len(searchRoot)
        ,   patterns
        ,   stlsoft::c_str_len(patterns)
        ,   flags
        ,   pfn
        ,   param
        ,   phSrch
        );
#ifdef RECLS_EXCEPTION_SUPPORT_
    }
# if _STLSOFT_VER >= 0x010d0000
    catch (platformstl::filesystem_exception& x)
    {
        return RECLS_RC_?;
    }
#  error Implement these changes to STLSoft, including winstl::path_too_long_exception.
# endif /* 0 */
# ifdef STLSOFT_CF_THROW_BAD_ALLOC
    catch (std::bad_alloc&)
    {
        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        return RECLS_RC_OUT_OF_MEMORY;
    }
# endif /* STLSOFT_CF_THROW_BAD_ALLOC */
    catch (std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_Search(): %s"), x.what());

        return RECLS_RC_UNEXPECTED;
    }
#endif /* RECLS_EXCEPTION_SUPPORT_ */
}

/* Semantics and responsibility:
 *
 * - convert all paths to absolute paths
 * - handle implicit values, such as search-root and pattern(s)
 *
 *
 * - null / "" directory means cwd
 * - null patterns means wilcards-all; "" means no files
 */
static
recls_rc_t
Recls_SearchFeedback_x_(
    /* [in] */ char const*                  function
,   /* [in] */ search_checks_t              checks
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ size_t                       searchRootLen
,   /* [in] */ recls_char_t const*          patterns
,   /* [in] */ size_t                       patternsLen
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_progress_fn_t         pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [out] */ hrecls_t*                   phSrch
)
{
    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SearchFeedback_(%s, %s, 0x%04x, %p, %p, ...)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(patterns)
    ,   flags
    ,   pfn
    ,   param
    );

    // Algorithm;
    //
    // 1. see if search-root contains path separators or wildcards
    // 2. see if patterns contains an absolute path
    // 3. no search-root -> cwd / home?
    // 4. search-root begins with '~' -> expand
    // 5. pattern is absolute path
    // 6. null patterns means wilcards-all; "" means no files
    // 7. ensure back/forward-slashes are correct


    // 1. see if search-root contains path separators or wildcards

    if (0 != searchRootLen)
    {
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX) && \
      defined(_WIN32)

        recls_char_t const* colon0  =   types::traits_type::str_chr(searchRoot, RECLS_LITERAL(':'));
        recls_char_t const* colon1  =   (ss_nullptr_k != colon0) ? types::traits_type::str_chr(colon0 + 1, RECLS_LITERAL(':')) : ss_nullptr_k;

        if (ss_nullptr_k != types::traits_type::str_chr(searchRoot, RECLS_LITERAL('|')) ||
            ss_nullptr_k != colon1)
#else
        if (ss_nullptr_k != types::traits_type::str_pbrk(searchRoot, s_path_separators))
#endif
        {
            return RECLS_RC_SEARCH_DIRECTORY_INVALID_CHARACTERS;
        }

        if (ss_nullptr_k != types::traits_type::str_pbrk(searchRoot, RECLS_LITERAL("*?")))
        {
            return RECLS_RC_SEARCH_DIRECTORY_INVALID_CHARACTERS;
        }
    }

    // 2. see if patterns contains an absolute path

    if (0 != patternsLen)
    {
        // first, canonicalise if necessary, so the parts-check (with stlsoft::find_next_token() will work)

        if (!has_checked(checks, CheckPatternsCanonicalSeparators))
        {
            if (ss_nullptr_k != types::traits_type::str_pbrk(patterns, s_path_separators))
            {
                types::buffer_type  buffer(1 + patternsLen);

                types::traits_type::char_copy(buffer.data(), patterns, patternsLen + 1);

                std::replace(&buffer[0], &buffer[0] + patternsLen, s_path_separators[0], s_path_separators[1]);

                return Recls_SearchFeedback_x_(
                    function
                ,   checks | CheckPatternsCanonicalSeparators
                ,   searchRoot
                ,   searchRootLen
                ,   buffer.data()
                ,   patternsLen
                ,   flags
                ,   pfn
                ,   param
                ,   phSrch
                );
            }
        }

        // now parse the patterns and check that no parts are an absolute or rooted path

        if (!has_checked(checks, CheckPatternsSingleAbsolute))
        {
            types::path_buffer_type pb;

            recls_char_t const*     p0;
            recls_char_t const*     p1;
            unsigned                n   =   0;

            for (p0 = p1 = patterns; stlsoft::find_next_token(p0, p1, s_path_separators[0]); ++n)
            {
                size_t const    len =   static_cast<size_t>(p1 - p0);

                if (0 != len)
                {
                    if (types::traits_type::is_path_absolute(p0, len))
                    {
                        if (pb.empty())
                        {
                            pb.assign(p0, len);
                        }
                        else
                        {
                            return RECLS_RC_ROOTED_PATHS_IN_PATTERNS;
                        }
                    }
                }
            }

            STLSOFT_SUPPRESS_UNUSED(n);

            if (!pb.empty())
            {
                flags &= ~(RECLS_F_RECURSIVE);

                checks = checks | CheckPatternsSingleAbsolute;
            }
        }
    }

    // 3. no search-root -> cwd / home?

    RECLS_ASSERT(0 != searchRootLen || !has_checked(checks, CheckRootEmpty));

    if (0 == searchRootLen /* &&
        !has_checked(checks, CheckRootEmpty) && */)
    {
        if (0 != (USE_TILDE_ON_NO_SEARCHROOT & flags))
        {
            return Recls_SearchFeedback_x_(
                function
            ,   checks | CheckRootEmpty
            ,   RECLS_LITERAL("~")
            ,   1
            ,   patterns
            ,   patternsLen
            ,   flags
            ,   pfn
            ,   param
            ,   phSrch
            );
        }
        else
        {
            // get the cwd and use that (unless USE_TILDE_ON_NO_SEARCHROOT specified)

            types::buffer_type      cwd(1);
            size_t const            cwdLen  =   types::traits_type::get_current_directory(cwd);

            if (0 == cwdLen)
            {
#ifdef RECLS_STLSOFT_1_12_OR_LATER
                types::traits_type::error_type const e = types::traits_type::get_last_error();

                if (!types::traits_type::is_memory_error_code(e))
                {
                    return RECLS_RC_NO_HOME;
                }
                else
#endif
                {
                    return RECLS_RC_OUT_OF_MEMORY;
                }
            }
            else
            {
                return Recls_SearchFeedback_x_(
                    function
                ,   checks | CheckRootEmpty
                ,   cwd.data()
                ,   cwdLen
                ,   patterns
                ,   patternsLen
                ,   flags
                ,   pfn
                ,   param
                ,   phSrch
                );
            }
        }
    }

    // 4. search-root begins with '~' -> expand

    if (recls_is_home_start_(searchRoot, searchRootLen) &&
        !has_checked(checks, CheckRootHomeStart))
    {
        // expand the search-root for home ('~') (or for empty if USE_TILDE_ON_NO_SEARCHROOT specified) and use that

        types::buffer_type      home(1);
        size_t const            homeLen  =   types::traits_type::get_home_directory(home);

        if (0 == homeLen)
        {
#ifdef RECLS_STLSOFT_1_12_OR_LATER
            types::traits_type::error_type const e = types::traits_type::get_last_error();

            if (types::traits_type::is_memory_error_code(e))
            {
                return RECLS_RC_OUT_OF_MEMORY;
            }
            else
#endif
            {
                return RECLS_RC_NO_HOME;
            }
        }
        else
        {
            size_t const lenRequired = homeLen + (searchRootLen - 1);

            if (!home.resize(lenRequired + 1))
            {
                return RECLS_RC_OUT_OF_MEMORY;
            }
            else
            {
                types::traits_type::char_copy(home.data() + homeLen, searchRoot + 1, (searchRootLen - 1) + 1);

                return Recls_SearchFeedback_x_(
                    function
                ,   checks | CheckRootHomeStart
                ,   home.data()
                ,   lenRequired
                ,   patterns
                ,   patternsLen
                ,   flags
                ,   pfn
                ,   param
                ,   phSrch
                );
            }
        }
    }

    // 5. pattern is absolute path

    if (!has_checked(checks, CheckRootEmpty) &&
        !has_checked(checks, CheckRootHomeStart) &&
        !has_checked(checks, CheckRootAbsolute))
    {
        types::traits_type::path_classification_results_type    results;
        types::traits_type::path_classification_type const      pcls = types::traits_type::path_classify(searchRoot, searchRootLen, 0, &results);

        if (!types::traits_type::path_is_absolute(pcls))
        {
            types::path_type p(searchRoot, searchRootLen);

            p.make_absolute(false);

            return Recls_SearchFeedback_x_(
                function
            ,   checks | CheckRootAbsolute
            ,   p.data()
            ,   p.size()
            ,   patterns
            ,   patternsLen
            ,   flags
            ,   pfn
            ,   param
            ,   phSrch
            );
        }
    }

    // 6. null patterns means wilcards-all; "" means no files

    if (ss_nullptr_k == patterns)
    {
        patterns    =   types::traits_type::pattern_all();
        patternsLen =   types::traits_type::str_len(patterns);
    }

    // 7. ensure back/forward-slashes are correct

    if (!has_checked(checks, CheckRootSlashes))
    {
#if 0
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

        if (ss_nullptr_k != stlsoft::c_string::strnchr(searchRoot, searchRootLen, '/'))
#elif defined(RECLS_PLATFORM_IS_UNIX) && \
      defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)

        if (ss_nullptr_k != stlsoft::c_string::strnchr(searchRoot, searchRootLen, '\\'))
#else
        if (false)
#endif
        {
            types::path_type p(searchRoot, searchRootLen);

            p.canonicalise(false);

            return Recls_SearchFeedback_x_(
                function
            ,   checks | CheckRootSlashes
            ,   p.data()
            ,   p.size()
            ,   patterns
            ,   patternsLen
            ,   flags
            ,   pfn
            ,   param
            ,   phSrch
            );
        }
    }


    recls_rc_t  rc = RECLS_RC_OK;

    // Default the flags
    if (0 == (flags & RECLS_F_TYPEMASK))
    {
        flags |= RECLS_F_FILES;
    }

    if (0 == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
    {
        rc = RECLS_RC_INVALID_SEARCH_TYPE;
    }
    // Validate the pattern.
    else
    {
        rc = recls_is_valid_pattern_(patterns, patternsLen, flags, types::traits_type::path_max());
    }

    if (RECLS_SUCCEEDED(rc))
    {
        types::buffer_type  sde(1);
        ReclsFileSearch*    si;

        if (!types::traits_type::has_dir_end(searchRoot, searchRootLen))
        {
            if (!sde.resize(1 + searchRootLen))
            {
                return RECLS_RC_OUT_OF_MEMORY;
            }
            else
            {
                types::traits_type::char_copy(&sde[0], searchRoot, searchRootLen + 1);

                searchRootLen   =   types::traits_type::ensure_dir_end(sde);
                searchRoot      =   sde.data();
            }
        }

        rc = ReclsFileSearch::FindAndCreate(
            searchRoot
        ,   searchRootLen
        ,   patterns
        ,   patternsLen
        ,   flags
        ,   pfn
        ,   param
        ,   &si
        );

        if (RECLS_SUCCEEDED(rc))
        {
            *phSrch = ReclsSearch::ToHandle(si);

            rc = RECLS_RC_OK;
        }
    }

    RECLS_MESSAGE_ASSERT(RECLS_LITERAL("Must not return a success code with a null search handle"), RECLS_RC_OK != rc || ss_nullptr_k != *phSrch);

    return rc;
}

recls_rc_t
Recls_SearchProcessFeedback_(
    /* [in] */ char const*                  function
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          pattern
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_process_fn_t          pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [in] */ hrecls_progress_fn_t         pfnProgress
,   /* [out] */ recls_process_fn_param_t    paramProgress
)
{
    RECLS_ASSERT(ss_nullptr_k != pfn);

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SearchProcessFeedback_(??, %s, %s, 0x%08x, %p, %p, %p, %p)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(pattern)
    ,   flags
    ,   pfn
    ,   param
    ,   pfnProgress
    ,   paramProgress
    );

    hrecls_t    hSrch;
    recls_rc_t  rc  =   Recls_SearchFeedback_(
                            function
                        ,   searchRoot
                        ,   pattern
                        ,   flags
                        ,   pfnProgress
                        ,   paramProgress
                        ,   &hSrch
                        );

    if (RECLS_SUCCEEDED(rc))
    {
        recls_entry_t info;

        do
        {
            rc = Recls_GetDetails(hSrch, &info);

            if (RECLS_FAILED(rc))
            {
                break;
            }
            else
            {
                int res;

#if defined(RECLS_PLATFORM_IS_WINDOWS)

                if (flags & RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS)
                {
                    typedef int (RECLS_CALLCONV_STDDECL *stdcall_process_fn_t)( recls_entry_t               hEntry
                                                                            ,   recls_process_fn_param_t    param);

                    union
                    {
                        stdcall_process_fn_t    pfn_stdcall;
                        hrecls_process_fn_t     pfn_cdecl;
                    } u;

                    u.pfn_cdecl = pfn;

                    res = (*u.pfn_stdcall)(info, param);
                }
                else
#endif /* RECLS_PLATFORM_IS_WINDOWS */
                {
                    res = (*pfn)(info, param);
                }

                Recls_CloseDetails(info);

                if (0 == res)
                {
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
        rc = RECLS_RC_OK;
    }

    return rc;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

