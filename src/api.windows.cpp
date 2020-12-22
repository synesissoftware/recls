/* /////////////////////////////////////////////////////////////////////////
 * File:        api.windows.cpp
 *
 * Purpose:     This file contains the Windows versions of the recls API.
 *
 * Created:     16th August 2003
 * Updated:     22nd December 2020
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
#include "incl.winstl.h"
#include "impl.util.h"
#include "impl.string.hpp"

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
 * helper functions
 */

#if defined(RECLS_COMPILER_IS_WATCOM)
static size_t check_drives(char* drives, recls_uint32_t flags)
#else /* ? compiler */
static size_t check_drives(char (*drives)[26], recls_uint32_t flags)
#endif /* compiler */
{
    typedef winstl::filesystem_traits<char> trait_t;

    size_t n = 0;

    for(size_t i = 0; i < 26; ++i)
    {
        const char letter = static_cast<char>('A' + i);

        if(0 == flags)
        {
            if(!trait_t::drive_exists(letter))
            {
                continue;   // No match
            }
        }
        else
        {
            const DWORD type = trait_t::get_drive_type(letter);

            switch(type)
            {
                case    DRIVE_UNKNOWN:

                    continue;
                case    DRIVE_NO_ROOT_DIR:

                    continue;
                case    DRIVE_REMOVABLE:

                    if(0 == (flags & RECLS_F_REMOVABLE_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_FIXED:

                    if(0 == (flags & RECLS_F_FIXED_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_REMOTE:

                    if(0 == (flags & RECLS_F_NETWORK_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_CDROM:

                    if(0 == (flags & RECLS_F_CDROM_DRIVES))
                    {
                        continue;
                    }
                    break;
                case    DRIVE_RAMDISK:

                    if(0 == (flags & RECLS_F_RAM_DRIVES))
                    {
                        continue;
                    }
                    break;
                default:

                    continue;   // No match
            }
        }

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

    return recls_get_string_property_(&fileInfo->shortFile, buffer, cchBuffer);
}

RECLS_FNDECL(void) Recls_GetDriveProperty(  recls_entry_t   fileInfo
                                        ,   recls_char_t*   pchDrive)
{
    function_scope_trace("Recls_GetDriveProperty");

    RECLS_ASSERT(NULL != fileInfo);
    RECLS_ASSERT(NULL != pchDrive);

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

    char    drives[26];
#if defined(RECLS_COMPILER_IS_WATCOM)
    size_t  n   =   check_drives(&drives[0], flags);
#else /* ? compiler */
    size_t  n   =   check_drives(&drives, flags);
#endif /* compiler */

    if(NULL != roots)
    {
        if(n < cRoots)
        {
            cRoots = n;
        }

        for(size_t i = 0; i < cRoots; ++i)
        {
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
        // To support the stupidity of .NET, we need to respond to -ve
        // indexes, hence: 

        recls_root_t    roots_[26];
        size_t          index   =   static_cast<size_t>(-static_cast<signed_t>(cRoots) - 1);
        size_t          cch     =   Recls_GetRoots_(&roots_[0], STLSOFT_NUM_ELEMENTS(roots_), 0);

        recls_debug1_trace_printf_(RECLS_LITERAL("Recls_GetRoots() [.NET hack]: index=%u"), index);

        if(index < cch)
        {
            return roots_[index].name[0];
        }
        else
        {
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

    // Same disgusting measure necessitated by the same disgusting, poorly
    // designed and shockingly documented facilities in .NET
    typedef stlsoft::sign_traits<size_t>::signed_type   signed_t;

    if(static_cast<signed_t>(cRoots) < 0)
    {
        // To support the stupidity of .NET, we need to respond to -ve
        // indexes, hence: 

        recls_root_t    roots_[26];
        size_t          index   =   static_cast<size_t>(-static_cast<signed_t>(cRoots) - 1);
        size_t          cch     =   Recls_GetRoots_(&roots_[0], STLSOFT_NUM_ELEMENTS(roots_), flags);

        if(index < cch)
        {
            return roots_[index].name[0];
        }
        else
        {
            return 0;
        }
    }

    return Recls_GetRoots_(roots, cRoots, flags);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

