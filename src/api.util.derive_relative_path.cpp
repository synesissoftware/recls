/* /////////////////////////////////////////////////////////////////////////
 * File:        api.extended.cpp
 *
 * Purpose:     recls API extended functions.
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
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.cover.h"

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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util")
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util.derive_relative_path")
RECLS_MARK_FILE_START()

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

    RECLS_COVER_MARK_LINE();

    typedef platformstl::basic_path<recls_char_t>           path_t;
    typedef platformstl::filesystem_traits<recls_char_t>    traits_t;

    path_t      originPath(origin);
    path_t      targetPath(target);
    const bool  bTargetHasSeparator =   targetPath.has_sep();

    // Make paths absolute, canonicalise, and remove any trailing separators
    originPath.make_absolute().canonicalise().pop_sep();
    targetPath.make_absolute().canonicalise().pop_sep();

    if(originPath.empty())
    {
        RECLS_COVER_MARK_LINE();

        return targetPath.copy(result, cchResult);
    }

#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(EMULATE_UNIX_ON_WINDOWS)
    if( traits_t::is_path_UNC(originPath.c_str()) ||
        traits_t::is_path_UNC(targetPath.c_str()))
    {
        RECLS_ASSERT('\\' == originPath[0] && '\\' == originPath[1]);
        RECLS_ASSERT('\\' == targetPath[0] && '\\' == targetPath[1]);

        RECLS_COVER_MARK_LINE();

        recls_char_t const* originShare    =   traits_t::str_chr(&originPath[2], '\\');
        recls_char_t const* targetShare    =   traits_t::str_chr(&targetPath[2], '\\');

        if( (originShare - &originPath[2]) != (targetShare - &targetPath[2]) ||
            0 != traits_t::str_n_compare(&originPath[2], &targetPath[2], static_cast<size_t>(originShare - &originPath[2])))
        {
            RECLS_COVER_MARK_LINE();

            // Different shares, so return target

            return targetPath.copy(result, cchResult);
        }
    }
    else
    {
        RECLS_ASSERT(isalpha(originPath[0]) && ':' == originPath[1]);
        RECLS_ASSERT(isalpha(targetPath[0]) && ':' == targetPath[1]);

        RECLS_COVER_MARK_LINE();

        if(toupper(originPath[0]) != toupper(targetPath[0]))
        {
            RECLS_COVER_MARK_LINE();

            // Different drives, so return target

            return targetPath.copy(result, cchResult);
        }
    }
#endif /* RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */

    // now trim the common 
    recls_char_t const* po  =   &originPath[0];
    recls_char_t const* pt  =   &targetPath[0];

    for(;;)
    {
        RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(EMULATE_UNIX_ON_WINDOWS)
        if(toupper(*po) != toupper(*pt))
#else /* ? RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */
        if(*po != *pt)
#endif /* RECLS_PLATFORM_IS_WINDOWS || EMULATE_UNIX_ON_WINDOWS */
        {
            RECLS_COVER_MARK_LINE();

            break;
        }

        ++po;
        ++pt;

        if('\0' == *po)
        {
            RECLS_COVER_MARK_LINE();

            break;
        }
        if('\0' == *pt)
        {
            RECLS_COVER_MARK_LINE();

            break;
        }
    }

    // We may need to rewind, since "h:\abc\def" and "H:\abc\defghi" would yield
    // ghi

    if( po != &originPath[0] &&
        (   '\0' != *po ||
            '\0' != *pt))
    {
        RECLS_COVER_MARK_LINE();

        // There is some commonality

        if(traits_t::is_path_name_separator(*(po - 1)))
        {
            RECLS_COVER_MARK_LINE();

            // Don't do anything, because both strings are at a unique whole point
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            // Previous was not a separator

            if( (   '\0' == *po &&
                    traits_t::is_path_name_separator(*pt)) ||
                (   '\0' == *pt &&
                    traits_t::is_path_name_separator(*po)))
            {
                RECLS_COVER_MARK_LINE();

                // One is at end, other at path-name-sep
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                for(; po != &originPath[0] && !traits_t::is_path_name_separator(*(po - 1)); --po)
                {
                    RECLS_COVER_MARK_LINE();
                }
                for(; pt != &originPath[0] && !traits_t::is_path_name_separator(*(pt - 1)); --pt)
                {
                    RECLS_COVER_MARK_LINE();
                }
            }
        }

        if('\0' == *po)
        {
            RECLS_COVER_MARK_LINE();

            if(traits_t::is_path_name_separator(*pt))
            {
                RECLS_COVER_MARK_LINE();

                ++pt;
            }
        }
        else if('\0' == *pt)
        {
            RECLS_COVER_MARK_LINE();

            if(traits_t::is_path_name_separator(*po))
            {
                RECLS_COVER_MARK_LINE();

                ++po;
            }
        }

    }

    // Now we take any dir parts from target, and turn them into .. for the
    // origin.

    path_t  originFragment(po);
    path_t  targetFinal;

    for(; 0 != originFragment.size(); originFragment.pop(true))
    {
        RECLS_COVER_MARK_LINE();

        targetFinal /= RECLS_LITERAL("..");
    }

    targetFinal /= pt;

    if(bTargetHasSeparator)
    {
        RECLS_COVER_MARK_LINE();

        targetFinal.push_sep();
    }

    return targetFinal.copy(result, cchResult);
}

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

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
