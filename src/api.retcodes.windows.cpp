/* /////////////////////////////////////////////////////////////////////////
 * File:        api.retcodes.windows.cpp
 *
 * Purpose:     This file contains the Windows versions of the recls API.
 *
 * Created:     13th November 2010
 * Updated:     22nd December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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

#include <stlsoft/conversion/union_cast.hpp>
#include <winstl/winstl.h>

#include "impl.trace.h"

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

#if 0 || \
	defined(STLSOFT_COMPILER_IS_CLANG) || \
	defined(STLSOFT_COMPILER_IS_GCC) || \
	0

# define SWITCH_BEGIN_()        if(0) {}
# define SWITCH_END_()          return static_cast<DWORD>(E_FAIL);

# define CASE_1_(r)             else if(rc == (r)) {}
# define CASE_2_(r, wec)        else if(rc == (r)) { return (wec); }
#else /* ? compiler */

# define SWITCH_BEGIN_()        switch(STLSOFT_REINTERPRET_CAST(recls_uintptr_t, rc)) {
# define SWITCH_END_()          } return static_cast<DWORD>(E_FAIL);

# define CASE_1_(r)             case STLSOFT_REINTERPRET_CAST(recls_uintptr_t, r): break;
# define CASE_2_(r, wec)        case STLSOFT_REINTERPRET_CAST(recls_uintptr_t, r): return (wec);
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

//using ::recls::impl::check_drives;
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * error handling
 */

RECLS_FNDECL(DWORD) Recls_ResultCodeToWindowsErrorCode(
    /* [in] */ recls_rc_t rc
)
{
    SWITCH_BEGIN_()

        CASE_1_(RECLS_RC_SEARCH_NO_CURRENT)
        CASE_2_(RECLS_RC_PATH_IS_NOT_DIRECTORY,     ERROR_INVALID_NAME)
        CASE_2_(RECLS_RC_NO_MORE_DATA,              static_cast<DWORD>(S_FALSE))
        CASE_2_(RECLS_RC_OUT_OF_MEMORY,             static_cast<DWORD>(E_OUTOFMEMORY))
        CASE_2_(RECLS_RC_NOT_IMPLEMENTED,           static_cast<DWORD>(E_NOTIMPL))
        CASE_2_(RECLS_RC_INVALID_SEARCH_TYPE,       ERROR_INVALID_PARAMETER)
        CASE_2_(RECLS_RC_INVALID_SEARCH_PROTOCOL,   ERROR_INVALID_PARAMETER)
        CASE_2_(RECLS_RC_UNEXPECTED,                static_cast<DWORD>(E_UNEXPECTED))
        CASE_2_(RECLS_RC_DOT_RECURSIVE_SEARCH,      ERROR_INVALID_PARAMETER)
        CASE_2_(RECLS_RC_SEARCH_CANCELLED,          ERROR_CANCELLED)
        CASE_1_(RECLS_RC_FTP_INIT_FAILED)
        CASE_1_(RECLS_RC_FTP_CONNECTION_FAILED)
        CASE_1_(RECLS_RC_CANNOT_STAT_ROOT)
        CASE_2_(RECLS_RC_PATH_LIMIT_EXCEEDED,       ERROR_INVALID_NAME)
        CASE_2_(RECLS_RC_USER_CANCELLED_SEARCH,     ERROR_CANCELLED)
        CASE_1_(RECLS_RC_NO_HOME)
        CASE_2_(RECLS_RC_INVALID_NAME,              ERROR_INVALID_NAME)
        CASE_2_(RECLS_RC_ACCESS_DENIED,             ERROR_ACCESS_DENIED)
        CASE_2_(RECLS_RC_DIRECTORY_NOT_FOUND,       ERROR_PATH_NOT_FOUND)

        CASE_2_(RECLS_RC_ENTRY_IS_DIRECTORY,        ERROR_INVALID_NAME)
        CASE_2_(RECLS_RC_ENTRY_IS_NOT_DIRECTORY,    ERROR_DIRECTORY)

    SWITCH_END_()
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

