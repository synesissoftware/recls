/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.util.unix.cpp
 *
 * Purpose:     Windows utility functions for the recls API.
 *
 * Created:     17th August 2003
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
#include "incl.unixstl.h"
#include "impl.types.hpp"

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
# include "impl.string.hpp"
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

#include "impl.trace.h"

#include <ctype.h>

/* /////////////////////////////////////////////////////////////////////////
 * compiler warnings
 */

#if (       defined(STLSOFT_COMPILER_IS_MSVC) || \
                defined(STLSOFT_COMPILER_IS_INTEL)) && \
      defined(STLSOFT_USING_SAFE_STR_FUNCTIONS)
# if _MSC_VER >= 1200
#  pragma warning(push)
# endif /* compiler */
# pragma warning(disable : 4996)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

RECLS_LINKAGE_C recls_char_t const* recls_find_directory_0_(recls_char_t const* path)
{
#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    if (':' == path[1])
    {
        // It's a drive-prefixed absolute path, so ...
# if RECLS_TRACE_LEVEL > 0
        if (!isalpha(path[0]))
        {
            recls_trace_printf_("recls_find_directory_0_() given an invalid path: %s", path);
        }
# endif /* RECLS_TRACE_LEVEL > 0 */

        // ... we just skip the drive
        return &path[2];
    }
    else if ('\\' == path[0] &&
            '\\' == path[1])
    {
        // It's a UNC absolute path, so we have to find the share name (with a '\')
        // and then the next slash or backslash
        recls_char_t const* share = types::traits_type::str_chr(path + 2, '\\');

        if (ss_nullptr_k == share)
        {
            goto bad_path_given;
        }
        else
        {
            recls_char_t const* slash   =   types::traits_type::str_chr(share + 1, '\\');
            recls_char_t const* slash_a =   types::traits_type::str_chr(share + 1, '/');

            if (ss_nullptr_k == slash ||
                (   ss_nullptr_k != slash_a &&
                    slash_a < slash))
            {
                slash = slash_a;
            }

            if (ss_nullptr_k == slash)
            {
                goto bad_path_given;
            }
            else
            {
                return slash;
            }
        }
    }
    else
    {
        RECLS_ASSERT(2 < types::traits_type::str_len(path));

        return path;
    }

bad_path_given:

    // Can't really do _anything_ sensible here, so we just return the
    // end of the string.
# if RECLS_TRACE_LEVEL > 0
    recls_trace_printf_("recls_find_directory_0_() given an invalid path: %s", path);
# endif /* RECLS_TRACE_LEVEL */

    return path + types::traits_type::str_len(path);
#else /* ? Windows */
# if RECLS_TRACE_LEVEL > 0
    if ('/' != path[0])
    {
        recls_trace_printf_("recls_find_directory_0_() given a non-rooted path: %s", path);
    }
# endif /* RECLS_TRACE_LEVEL */

    return path;
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * compiler warnings
 */

#if (       defined(STLSOFT_COMPILER_IS_MSVC) || \
                defined(STLSOFT_COMPILER_IS_INTEL)) && \
      defined(STLSOFT_USING_SAFE_STR_FUNCTIONS)
# if _MSC_VER >= 1200
#  pragma warning(pop)
# else /* ? compiler */
#  pragma warning(default : 4996)
# endif /* _MSC_VER */
#endif /* compiler */

/* ///////////////////////////// end of file //////////////////////////// */

