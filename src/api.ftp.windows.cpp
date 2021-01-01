/* /////////////////////////////////////////////////////////////////////////
 * File:        api.ftp.windows.cpp
 *
 * Purpose:     This file contains the Windows versions of the FTP part of
 *              the recls API.
 *
 * Created:     15th August 2004
 * Updated:     1st January 2021
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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
#include <recls/ftp.h>
#include "impl.root.h"
#include "incl.winstl.h"
#include "impl.util.h"
#include "impl.string.hpp"
#include "impl.entryfunctions.h"
#include "impl.types.ftp.hpp"

#include "ReclsSearch.hpp"
#include "ReclsFtpSearch.hpp"

#include "impl.trace.h"

#include <algorithm>

#include <ctype.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::ReclsSearch;
using ::recls::impl::ReclsFtpSearch;
using ::recls::impl::types;

using ::recls::impl::recls_is_valid_pattern_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * search control
 */

RECLS_API
Recls_SearchFtp(
    recls_char_t const* host
,   recls_char_t const* username
,   recls_char_t const* password
,   recls_char_t const* searchRoot
,   recls_char_t const* pattern
,   recls_uint32_t      flags
,   hrecls_t*           phSrch
)
{
    function_scope_trace("Recls_SearchFtp");

    RECLS_ASSERT(ss_nullptr_k != phSrch);

    *phSrch = static_cast<hrecls_t>(0);

    recls_rc_t  rc;

    // Default the input parameters

    // Default the search root
    if (ss_nullptr_k == searchRoot ||
        0 == *searchRoot)
    {
        searchRoot = RECLS_LITERAL("/"); // FTP always rooted at ./.
    }

    // Default the pattern
    if (ss_nullptr_k == pattern)
    {
        pattern = RECLS_LITERAL("*"); // FTP always uses '*' as wildcard
    }

    // Default the flags
    if (0 == (flags & RECLS_F_TYPEMASK))
    {
        flags |= RECLS_F_FILES;
    }

    // Validate the pattern
    rc = recls_is_valid_pattern_(pattern, flags, _MAX_PATH);

    if (RECLS_SUCCEEDED(rc))
    {
        ReclsFtpSearch* si;
        size_t          rootDirLen = types::traits_type::str_len(searchRoot);
        size_t          patternLen = types::traits_type::str_len(pattern);

        rc = ReclsFtpSearch::FindAndCreate(
            host
        ,   username
        ,   password
        ,   searchRoot
        ,   rootDirLen
        ,   pattern
        ,   patternLen
        ,   flags
        ,   &si
        );

        if (RECLS_SUCCEEDED(rc))
        {
            *phSrch = ReclsSearch::ToHandle(si);

            rc = RECLS_RC_OK;
        }
    }

    return rc;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

