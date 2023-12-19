/* /////////////////////////////////////////////////////////////////////////
 * File:        api.windows.cpp
 *
 * Purpose:     This file contains the Windows versions of the recls API.
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
#include "incl.winstl.h"
#include "impl.util.h"
#include "impl.string.hpp"
#include "impl.cover.h"

#include "impl.trace.h"

#include <stlsoft/util/sign_traits.hpp>
#include <winstl/filesystem/filesystem_traits.hpp>

#include <algorithm>

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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.core.search")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#if defined(RECLS_COMPILER_IS_WATCOM)
static size_t check_drives(char* drives, recls_uint32_t flags)
#else /* ? compiler */
static size_t check_drives(char (*drives)[26], recls_uint32_t flags)
#endif /* compiler */
{
    RECLS_COVER_MARK_LINE();

    typedef winstl::filesystem_traits<char> trait_t;

    size_t n = 0;

    for(size_t i = 0; i < 26; ++i)
    {
        RECLS_COVER_MARK_LINE();

        const char letter = static_cast<char>('A' + i);

        if(0 == flags)
        {
            RECLS_COVER_MARK_LINE();

            if(!trait_t::drive_exists(letter))
            {
                RECLS_COVER_MARK_LINE();

                continue;   // No match
            }
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            const DWORD type = trait_t::get_drive_type(letter);

            switch(type)
            {
                case    DRIVE_UNKNOWN:
                    RECLS_COVER_MARK_LINE();
                    continue;
                case    DRIVE_NO_ROOT_DIR:
                    RECLS_COVER_MARK_LINE();
                    continue;
                case    DRIVE_REMOVABLE:
                    RECLS_COVER_MARK_LINE();
                    if(0 == (flags & RECLS_F_REMOVABLE_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_FIXED:
                    RECLS_COVER_MARK_LINE();
                    if(0 == (flags & RECLS_F_FIXED_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_REMOTE:
                    RECLS_COVER_MARK_LINE();
                    if(0 == (flags & RECLS_F_NETWORK_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_CDROM:
                    RECLS_COVER_MARK_LINE();
                    if(0 == (flags & RECLS_F_CDROM_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_RAMDISK:
                    RECLS_COVER_MARK_LINE();
                    if(0 == (flags & RECLS_F_RAM_DRIVES))
                    {
                        continue;
                    }
                    break;
                default:
                    RECLS_COVER_MARK_LINE();
                    continue;   // No match
            }
        }

        RECLS_COVER_MARK_LINE();

#if defined(RECLS_COMPILER_IS_WATCOM)
        drives[n] = letter;
#else /* ? compiler */
        (*drives)[n] = letter;
#endif /* compiler */

        ++n;
    }

    return n;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

using ::recls::impl::check_drives;
using ::recls::impl::recls_get_string_property_;
using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_warning_trace_printf_;
using ::recls::impl::recls_info_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * property elicitation
 */

RECLS_FNDECL(size_t) Recls_GetShortFileProperty(    recls_entry_t   fileInfo
                                                ,   recls_char_t*   buffer
                                                ,   size_t          cchBuffer)
{
    function_scope_trace("Recls_GetShortFileProperty");

    RECLS_ASSERT(NULL != fileInfo);

    RECLS_COVER_MARK_LINE();

    return recls_get_string_property_(&fileInfo->shortFile, buffer, cchBuffer);
}

RECLS_FNDECL(void) Recls_GetDriveProperty(  recls_entry_t   fileInfo
                                        ,   recls_char_t*   pchDrive)
{
    function_scope_trace("Recls_GetDriveProperty");

    RECLS_ASSERT(NULL != fileInfo);
    RECLS_ASSERT(NULL != pchDrive);

    RECLS_COVER_MARK_LINE();

    // Because, as of version 1.5.1, this function can also be called for
    // FTP files, which will not have a drive, we need to check for it,
    // and return a nul char if it's not a

    *pchDrive = (':' == fileInfo->path.begin[1]) ? static_cast<recls_char_t>(toupper(fileInfo->drive)) : '\0';
}

/* /////////////////////////////////////////////////////////////////////////
 * roots
 */

static size_t Recls_GetRoots_(  recls_root_t*   roots
                            ,   size_t          cRoots
                            ,   recls_uint32_t  flags)
{
    RECLS_ASSERT(NULL == roots || 0 != cRoots);

    RECLS_COVER_MARK_LINE();

    char    drives[26];
#if defined(RECLS_COMPILER_IS_WATCOM)
    size_t  n   =   check_drives(&drives[0], flags);
#else /* ? compiler */
    size_t  n   =   check_drives(&drives, flags);
#endif /* compiler */

    if(NULL != roots)
    {
        RECLS_COVER_MARK_LINE();

        if(n < cRoots)
        {
            RECLS_COVER_MARK_LINE();

            cRoots = n;
        }

        for(size_t i = 0; i < cRoots; ++i)
        {
            RECLS_COVER_MARK_LINE();

            roots[i].name[0] = drives[i];
            roots[i].name[1] = ':';
            roots[i].name[2] = '\\';
            roots[i].name[3] = '\0';
        }
    }

    return n;
}

RECLS_LINKAGE_C size_t Recls_GetRoots(  recls_root_t*   roots
                                    ,   size_t          cRoots)
{
    function_scope_trace("Recls_GetRoots");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_GetRoots(..., %u)"), unsigned(cRoots));

    RECLS_COVER_MARK_LINE();

    // Stupid, stupid, stupid, Microsoft P/Invoke crapola has eaten 12 hours
    // of my life, and I still can't get it to work, so we're going to use a
    // disgusting hack.
    //
    // I officially declare .NET to be a disgusting pile of stinking
    // garbage, and I look forward to the day when I can know that I will
    // never have to go anywhere near it again.
    typedef stlsoft::sign_traits<size_t>::signed_type   signed_t;

    if(static_cast<signed_t>(cRoots) < 0)
    {
        RECLS_COVER_MARK_LINE();

        // To support the stupidity of .NET, we need to respond to -ve
        // indexes, hence:

        recls_root_t    roots_[26];
        size_t          index   =   static_cast<size_t>(-static_cast<signed_t>(cRoots) - 1);
        size_t          cch     =   Recls_GetRoots_(&roots_[0], STLSOFT_NUM_ELEMENTS(roots_), 0);

        recls_debug1_trace_printf_(RECLS_LITERAL("Recls_GetRoots() [.NET hack]: index=%u"), index);

        if(index < cch)
        {
            RECLS_COVER_MARK_LINE();

            return roots_[index].name[0];
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            return 0;
        }
    }

    return Recls_GetRoots_(roots, cRoots, 0);
}

RECLS_LINKAGE_C size_t Recls_GetSelectedRoots(  recls_root_t*   roots
                                            ,   size_t          cRoots
                                            ,   recls_uint32_t  flags)
{
    function_scope_trace("Recls_GetSelectedRoots");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_GetSelectedRoots(..., %u, %08x)"), unsigned(cRoots), flags);

    RECLS_COVER_MARK_LINE();

    // Same disgusting measure necessitated by the same disgusting, poorly
    // designed and shockingly documented facilities in .NET
    typedef stlsoft::sign_traits<size_t>::signed_type   signed_t;

    if(static_cast<signed_t>(cRoots) < 0)
    {
        RECLS_COVER_MARK_LINE();

        // To support the stupidity of .NET, we need to respond to -ve
        // indexes, hence:

        recls_root_t    roots_[26];
        size_t          index   =   static_cast<size_t>(-static_cast<signed_t>(cRoots) - 1);
        size_t          cch     =   Recls_GetRoots_(&roots_[0], STLSOFT_NUM_ELEMENTS(roots_), flags);

        if(index < cch)
        {
            RECLS_COVER_MARK_LINE();

            return roots_[index].name[0];
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            return 0;
        }
    }

    return Recls_GetRoots_(roots, cRoots, flags);
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
