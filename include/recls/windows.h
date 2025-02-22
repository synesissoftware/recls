/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/windows.h
 *
 * Purpose: Windows-specific header file for recls API.
 *
 * Created: 18th August 2003
 * Updated: 23rd February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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


#ifndef RECLS_INCL_RECLS_H_WINDOWS
#define RECLS_INCL_RECLS_H_WINDOWS

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_H_WINDOWS_MAJOR    4
# define RECLS_VER_RECLS_H_WINDOWS_MINOR    2
# define RECLS_VER_RECLS_H_WINDOWS_REVISION 1
# define RECLS_VER_RECLS_H_WINDOWS_EDIT     29
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/windows.h
 *
 * \brief [C, C++; Windows-only] Windows-specific parts of the \ref group__recls API.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <windows.h>

#if !defined(RECLS_PLATFORM_IS_WIN32) && \
    !defined(RECLS_PLATFORM_IS_WIN64)
# error recls/windows.h is to be included in Windows compilations only
#endif /* RECLS_PLATFORM_IS_WINDOWS */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/***************************************
 * Property elicitation
 */

/** \name Property elicitation functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Gets the drive associated with the given file entry info structure
 *
 * \ingroup group__recls
 *
 * \param hEntry The info entry structure.
 * \param pchDrive Pointer to a character to receive the drive character. Cannot be NULL. The character will be in uppercase.
 */
RECLS_FNDECL(void)
Recls_GetDriveProperty(
    recls_entry_t   hEntry
,   recls_char_t    *pchDrive
);
/** @} */


/***************************************
 * Error handling
 */

/** \name Windows-specific error handling functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Translates a recls result code into a Windows result code
 */
RECLS_FNDECL(DWORD)
Recls_ResultCodeToWindowsErrorCode(
    /* [in] */ recls_rc_t rc
);
/** @} */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef RECLS_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* RECLS_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_RECLS_H_WINDOWS */

/* ///////////////////////////// end of file //////////////////////////// */

