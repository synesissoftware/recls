/* /////////////////////////////////////////////////////////////////////////
 * File:        api.extended.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     24th December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "impl.types.hpp"
#include "impl.util.h"

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::types;

using ::recls::impl::recls_log_printf_;
using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_warning_trace_printf_;
using ::recls::impl::recls_info_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

RECLS_FNDECL(size_t) Recls_DeriveRelativePath(
    recls_char_t const* origin
,   recls_char_t const* target
,   recls_char_t*       result
,   size_t              cchResult
)
{
    function_scope_trace("Recls_DeriveRelativePath");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_DeriveRelativePath(%s, %s, ..., %u)"), stlsoft::c_str_ptr(origin), stlsoft::c_str_ptr(target), unsigned(cchResult));

    typedef platformstl::basic_path<recls_char_t>           path_t;
    typedef platformstl::filesystem_traits<recls_char_t>    traits_t;

    path_t      originPath(origin);
    path_t      targetPath(target);
    bool const  bTargetHasSeparator =   targetPath.has_sep();

    // Make paths absolute, canonicalise, and remove any trailing separators
    originPath.make_absolute().canonicalise().pop_sep();
    targetPath.make_absolute().canonicalise().pop_sep();

    if (originPath.empty())
    {
        return targetPath.copy(result, cchResult);
    }

#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(EMULATE_UNIX_ON_WINDOWS)
    if (traits_t::is_path_UNC(originPath.c_str()) ||
        traits_t::is_path_UNC(targetPath.c_str()))
    {
        RECLS_ASSERT('\\' == originPath[0] && '\\' == originPath[1]);
        RECLS_ASSERT('\\' == targetPath[0] && '\\' == targetPath[1]);

        recls_char_t const* originShare    =   traits_t::str_chr(&originPath[2], '\\');
        recls_char_t const* targetShare    =   traits_t::str_chr(&targetPath[2], '\\');

        if ((originShare - &originPath[2]) != (targetShare - &targetPath[2]) ||
            0 != traits_t::str_n_compare(&originPath[2], &targetPath[2], static_cast<size_t>(originShare - &originPath[2])))
        {
            // Different shares, so return target

            return targetPath.copy(result, cchResult);
        }
    }
    else
    {
        RECLS_ASSERT(isalpha(originPath[0]) && ':' == originPath[1]);
        RECLS_ASSERT(isalpha(targetPath[0]) && ':' == targetPath[1]);

        if (toupper(originPath[0]) != toupper(targetPath[0]))
        {
            // Different drives, so return target

            return targetPath.copy(result, cchResult);
        }
    }
#endif /* RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */

    // now trim the common
    recls_char_t const* po  =   &originPath[0];
    recls_char_t const* pt  =   &targetPath[0];

    for (;;)
    {
#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(EMULATE_UNIX_ON_WINDOWS)
        if (toupper(*po) != toupper(*pt))
#else /* ? RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */
        if (*po != *pt)
#endif /* RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */
        {
            break;
        }

        ++po;
        ++pt;

        if ('\0' == *po)
        {
            break;
        }
        if ('\0' == *pt)
        {
            break;
        }
    }

    // We may need to rewind, since "h:\abc\def" and "H:\abc\defghi" would yield
    // ghi

    if (po != &originPath[0] &&
        (   '\0' != *po ||
            '\0' != *pt))
    {
        // There is some commonality

        if (traits_t::is_path_name_separator(*(po - 1)))
        {
            // Don't do anything, because both strings are at a unique whole point
        }
        else
        {
            // Previous was not a separator

            if ((   '\0' == *po &&
                    traits_t::is_path_name_separator(*pt)) ||
                (   '\0' == *pt &&
                    traits_t::is_path_name_separator(*po)))
            {
                // One is at end, other at path-name-sep
            }
            else
            {
                for (; po != &originPath[0] && !traits_t::is_path_name_separator(*(po - 1)); --po)
                {}
                for (; pt != &originPath[0] && !traits_t::is_path_name_separator(*(pt - 1)); --pt)
                {}
            }
        }

        if ('\0' == *po)
        {
            if (traits_t::is_path_name_separator(*pt))
            {
                ++pt;
            }
        }
        else if ('\0' == *pt)
        {
            if (traits_t::is_path_name_separator(*po))
            {
                ++po;
            }
        }

    }

    // Now we take any dir parts from target, and turn them into .. for the
    // origin.

    path_t  originFragment(po);
    path_t  targetFinal;

    for (; 0 != originFragment.size(); originFragment.pop(true))
    {
        targetFinal /= RECLS_LITERAL("..");
    }

    targetFinal /= pt;

    if (bTargetHasSeparator)
    {
        targetFinal.push_sep();
    }

    return targetFinal.copy(result, cchResult);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

