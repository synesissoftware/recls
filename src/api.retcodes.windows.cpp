/* /////////////////////////////////////////////////////////////////////////
 * File:        api.retcodes.windows.cpp
 *
 * Purpose:     This file contains the Windows versions of the recls API.
 *
 * Created:     13th November 2010
 * Updated:     11th September 2011
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2010-2011, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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
 * Includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "incl.winstl.h"
#include "impl.util.h"
#include "impl.string.hpp"
#include "impl.cover.h"

#include <stlsoft/conversion/union_cast.hpp>
#include <winstl/winstl.h>

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.core.retcodes")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * Helper functions
 */



/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

//using ::recls::impl::check_drives;
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Error handling
 */

RECLS_FNDECL(DWORD) Recls_ResultCodeToWindowsErrorCode(
    /* [in] */ recls_rc_t rc
)
{
    switch(stlsoft::union_cast<winstl::ws_uintptr_t>(rc))
    {
        case    RECLS_RC_SEARCH_NO_CURRENT:         break;
        case    RECLS_RC_PATH_IS_NOT_DIRECTORY:     return ERROR_INVALID_NAME;
        case    RECLS_RC_NO_MORE_DATA:              return S_FALSE;
        case    RECLS_RC_OUT_OF_MEMORY:             return static_cast<DWORD>(E_OUTOFMEMORY);
        case    RECLS_RC_NOT_IMPLEMENTED:           return static_cast<DWORD>(E_NOTIMPL);
        case    RECLS_RC_INVALID_SEARCH_TYPE:       return ERROR_INVALID_PARAMETER;
        case    RECLS_RC_INVALID_SEARCH_PROTOCOL:   return ERROR_INVALID_PARAMETER;
        case    RECLS_RC_UNEXPECTED:                return static_cast<DWORD>(E_UNEXPECTED);
        case    RECLS_RC_DOT_RECURSIVE_SEARCH:      return ERROR_INVALID_PARAMETER;
        case    RECLS_RC_SEARCH_CANCELLED:          return ERROR_CANCELLED;
        case    RECLS_RC_FTP_INIT_FAILED:           break;
        case    RECLS_RC_FTP_CONNECTION_FAILED:     break;
        case    RECLS_RC_CANNOT_STAT_ROOT:          break;
        case    RECLS_RC_PATH_LIMIT_EXCEEDED:       return ERROR_INVALID_NAME;
        case    RECLS_RC_USER_CANCELLED_SEARCH:     return ERROR_CANCELLED;
        case    RECLS_RC_NO_HOME:                   break;
        case    RECLS_RC_INVALID_NAME:              return ERROR_INVALID_NAME;
        case    RECLS_RC_ACCESS_DENIED:             return ERROR_ACCESS_DENIED;
        case    RECLS_RC_DIRECTORY_NOT_FOUND:       return ERROR_PATH_NOT_FOUND;

        case    RECLS_RC_ENTRY_IS_DIRECTORY:        return ERROR_INVALID_NAME;
        case    RECLS_RC_ENTRY_IS_NOT_DIRECTORY:    return ERROR_DIRECTORY;
    }

    return static_cast<DWORD>(E_FAIL);
}

/* /////////////////////////////////////////////////////////////////////////
 * Coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
