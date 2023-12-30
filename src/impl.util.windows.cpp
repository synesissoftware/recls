/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.util.windows.cpp
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
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.cover.h"

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

/* ////////////////////////////////////////////////////////////////////// */

RECLS_LINKAGE_C recls_char_t const* recls_find_directory_0_(recls_char_t const* path)
{
    RECLS_COVER_MARK_LINE();

    if (':' == path[1])
    {
        RECLS_COVER_MARK_LINE();

        // It's a drive-prefixed absolute path, so ...
#if RECLS_TRACE_LEVEL > 0
        if (!isalpha(path[0]))
        {
            RECLS_COVER_MARK_LINE();

            recls_trace_printf_("recls_find_directory_0_() given an invalid path: %s", path);
        }
#endif /* RECLS_TRACE_LEVEL > 0 */

        // ... we just skip the drive
        return &path[2];
    }
    else if ('\\' == path[0] &&
            '\\' == path[1])
    {
        RECLS_COVER_MARK_LINE();

        // It's a UNC absolute path, so we have to find the share name (with a '\')
        // and then the next slash or backslash
        recls_char_t const* share = types::traits_type::str_chr(path + 2, '\\');

        if (NULL == share)
        {
            RECLS_COVER_MARK_LINE();

            goto bad_path_given;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            recls_char_t const* slash   =   types::traits_type::str_chr(share + 1, '\\');
            recls_char_t const* slash_a =   types::traits_type::str_chr(share + 1, '/');

            if (NULL == slash ||
                (   NULL != slash_a &&
                    slash_a < slash))
            {
                RECLS_COVER_MARK_LINE();

                slash = slash_a;
            }

            if (NULL == slash)
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
#if RECLS_TRACE_LEVEL > 0
    recls_trace_printf_("recls_find_directory_0_() given an invalid path: %s", path);
#endif /* RECLS_TRACE_LEVEL > 0 */

    return path + types::traits_type::str_len(path);
}

RECLS_LINKAGE_C size_t recls_get_home_(recls_char_t* buff, size_t cchBuff)
{
    RECLS_COVER_MARK_LINE();

    recls_char_t    homeDrive[1 + _MAX_DRIVE];
    recls_char_t    homeDir[1 + _MAX_DIR];

    const size_t    cchHomeDrive    =   types::traits_type::get_environment_variable( RECLS_LITERAL("HOMEDRIVE")
                                                                        ,   &homeDrive[0]
                                                                        ,   RECLS_NUM_ELEMENTS(homeDrive));
    size_t          cchHomeDir      =   types::traits_type::get_environment_variable( RECLS_LITERAL("HOMEPATH")
                                                                        ,   &homeDir[0]
                                                                        ,   RECLS_NUM_ELEMENTS(homeDir));

    if (0 == cchHomeDrive ||
        RECLS_NUM_ELEMENTS(homeDrive) == cchHomeDrive)
    {
        RECLS_COVER_MARK_LINE();

        return 0;
    }
    if (0 == cchHomeDir ||
        RECLS_NUM_ELEMENTS(homeDir) == cchHomeDir)
    {
        RECLS_COVER_MARK_LINE();

        return 0;
    }

    if (!types::traits_type::has_dir_end(homeDir))
    {
        RECLS_COVER_MARK_LINE();

        types::traits_type::ensure_dir_end(&homeDir[0] + cchHomeDir - 1);
        ++cchHomeDir;
    }

    if (NULL == buff)
    {
        RECLS_COVER_MARK_LINE();

        return cchHomeDrive + cchHomeDir;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        if (cchBuff <= cchHomeDrive)
        {
            RECLS_COVER_MARK_LINE();

            recls_strncpy_(buff, cchBuff, homeDrive, cchHomeDrive);

            return cchHomeDrive;
        }
        else if (cchBuff <= cchHomeDrive + cchHomeDir)
        {
            RECLS_COVER_MARK_LINE();

            recls_strncpy_(buff, cchBuff, homeDrive, cchHomeDrive);
            recls_strncpy_(buff + cchHomeDrive, cchBuff - cchHomeDrive, homeDir, cchHomeDir);

            return cchBuff;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            recls_strncpy_(buff, cchBuff, homeDrive, cchHomeDrive);
            recls_strncpy_(buff + cchHomeDrive, cchBuff - cchHomeDrive, homeDir, cchHomeDir);

            RECLS_ASSERT('\0' == buff[cchHomeDrive + cchHomeDir]);

            return cchHomeDrive + cchHomeDir;
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

/* ///////////////////////////// end of file //////////////////////////// */

