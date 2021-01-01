/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.util.unix.cpp
 *
 * Purpose:     Windows utility functions for the recls API.
 *
 * Created:     17th August 2003
 * Updated:     1st January 2021
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
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

RECLS_LINKAGE_C size_t recls_get_home_(
    recls_char_t*   buff
,   size_t          cchBuff
)
{
#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
    if (ss_nullptr_k == ::getenv("HOME"))
    {
        typedef RECLS_STRING_TEMPLATE_1(char)   string_t;

        string_t home("HOME=");

        home += ::getenv("HOMEDRIVE");
        home += ::getenv("HOMEPATH");

        ::_putenv(home.c_str());
    }
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

    types::file_path_buffer_type    homeDir;
    size_t                          cchHomeDir = types::traits_type::get_environment_variable(  RECLS_LITERAL("HOME")
                                                                                ,   &homeDir[0]
                                                                                ,   homeDir.size());

    if (0 == cchHomeDir ||
        homeDir.size() == cchHomeDir)
    {
        return 0;
    }

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
    // On Windows systems that are being used to test the UNIX build, we will
    // translate all the backslashes in UNIX-like paths to forward slashes.
    std::replace(homeDir.data(), homeDir.data() + cchHomeDir, '\\', types::traits_type::path_name_separator());
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

    if (!types::traits_type::has_dir_end(homeDir.data()))
    {
        types::traits_type::ensure_dir_end(&homeDir[0] + cchHomeDir - 1);
        ++cchHomeDir;
    }

    if (ss_nullptr_k == buff)
    {
        return cchHomeDir;
    }
    else
    {
        if (cchBuff <= cchHomeDir)
        {
            types::traits_type::char_copy(&buff[0], homeDir.data(), cchBuff);

            return cchBuff;
        }
        else
        {
            types::traits_type::char_copy(&buff[0], homeDir.data(), cchHomeDir);
            buff[cchHomeDir] = '\0';

            return cchHomeDir;
        }
    }
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

