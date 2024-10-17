/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/ftp.h
 *
 * Purpose: FTP-specific header file for recls API.
 *
 * Created: 18th August 2003
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


#ifndef RECLS_INCL_RECLS_H_FTP
#define RECLS_INCL_RECLS_H_FTP

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_H_FTP_MAJOR    3
# define RECLS_VER_RECLS_H_FTP_MINOR    2
# define RECLS_VER_RECLS_H_FTP_REVISION 2
# define RECLS_VER_RECLS_H_FTP_EDIT     16
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/ftp.h
 *
 * \brief [C, C++] FTP-specific parts of the \ref group__recls API.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#ifndef RECLS_API_FTP
# error FTP not supported on the current platform
#endif /* !RECLS_API_FTP */


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
 * Search control
 */

/** \name Search control functions
 *
 * \ingroup group__recls
 */
/** @{ */


/** Searches a given directory for matching files of the given pattern
 *
 * \ingroup group__recls
 *
 * \param host The host on which to search
 * \param username The username with which to gain access
 * \param password The password with which to gain access
 * \param searchRoot The directory representing the root of the search
 * \param pattern The search pattern, e.g. "*.c"
 * \param flags A combination of 0 or more RECLS_FLAG values
 * \param phSrch Address of the search handle. This is set to NULL on failure
 * \return A status code indicating success/failure
 *
 * \note This function is currently only available on Windows.
 */
RECLS_FNDECL(recls_rc_t)
Recls_SearchFtp(
    recls_char_t const* host
,   recls_char_t const* username
,   recls_char_t const* password
,   recls_char_t const* searchRoot
,   recls_char_t const* pattern
,   recls_uint32_t      flags
,   hrecls_t*           phSrch
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

#endif /* !RECLS_INCL_RECLS_H_FTP */

/* ///////////////////////////// end of file //////////////////////////// */

