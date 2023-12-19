/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.util.unix.cpp
 *
 * Purpose:     Windows utility functions for the recls API.
 *
 * Created:     17th August 2003
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
    RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    if(':' == path[1])
    {
        RECLS_COVER_MARK_LINE();

        // It's a drive-prefixed absolute path, so ...
# if RECLS_TRACE_LEVEL > 0
        if(!isalpha(path[0]))
        {
            RECLS_COVER_MARK_LINE();

            recls_trace_printf_("recls_find_directory_0_() given an invalid path: %s", path);
        }
# endif /* RECLS_TRACE_LEVEL > 0 */

        // ... we just skip the drive
        return &path[2];
    }
    else if('\\' == path[0] &&
            '\\' == path[1])
    {
        RECLS_COVER_MARK_LINE();

        // It's a UNC absolute path, so we have to find the share name (with a '\')
        // and then the next slash or backslash
        recls_char_t const* share = types::traits_type::str_chr(path + 2, '\\');

        if(NULL == share)
        {
            RECLS_COVER_MARK_LINE();

            goto bad_path_given;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            recls_char_t const* slash   =   types::traits_type::str_chr(share + 1, '\\');
            recls_char_t const* slash_a =   types::traits_type::str_chr(share + 1, '/');

            if( NULL == slash ||
                (   NULL != slash_a &&
                    slash_a < slash))
            {
                RECLS_COVER_MARK_LINE();

                slash = slash_a;
            }

            if(NULL == slash)
            {
                RECLS_COVER_MARK_LINE();

                goto bad_path_given;
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                return slash;
            }
        }
    }
    else
    {
        RECLS_ASSERT(2 < types::traits_type::str_len(path));

        RECLS_COVER_MARK_LINE();

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
    if('/' != path[0])
    {
        RECLS_COVER_MARK_LINE();

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
    RECLS_COVER_MARK_LINE();

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
    if(NULL == ::getenv("HOME"))
    {
        RECLS_COVER_MARK_LINE();

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

    if( 0 == cchHomeDir ||
        homeDir.size() == cchHomeDir)
    {
        RECLS_COVER_MARK_LINE();

        return 0;
    }

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
    // On Windows systems that are being used to test the UNIX build, we will
    // translate all the backslashes in UNIX-like paths to forward slashes.
    std::replace(homeDir.data(), homeDir.data() + cchHomeDir, '\\', types::traits_type::path_name_separator());
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */

    if(!types::traits_type::has_dir_end(homeDir.c_str()))
    {
        RECLS_COVER_MARK_LINE();

        types::traits_type::ensure_dir_end(&homeDir[0] + cchHomeDir - 1);
        ++cchHomeDir;
    }

    if(NULL == buff)
    {
        RECLS_COVER_MARK_LINE();

        return cchHomeDir;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        if(cchBuff <= cchHomeDir)
        {
            RECLS_COVER_MARK_LINE();

            types::traits_type::char_copy(&buff[0], homeDir.c_str(), cchBuff);

            return cchBuff;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            types::traits_type::char_copy(&buff[0], homeDir.c_str(), cchHomeDir);
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
