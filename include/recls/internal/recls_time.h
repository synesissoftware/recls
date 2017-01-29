/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/recls_time.h (formerly in platform_types.h)
 *
 * Purpose:     Partially platform-independent time type for recls.
 *
 * Created:     18th August 2003
 * Updated:     10th January 2017
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2017, Matthew Wilson and Synesis Software
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
 * - Neither the names of Matthew Wilson and Synesis Software nor the names
 *   of any contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_RECLS_TIME
#define RECLS_INCL_RECLS_INTERNAL_H_RECLS_TIME

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_TIME_MAJOR    1
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_TIME_MINOR    0
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_TIME_REVISION 1
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_TIME_EDIT     2
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/recls_time.h
 *
 * \brief [C, C++] Partially platform-independent time type for .
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RECLS_INCL_RECLS_INTERNAL_H_PLATFORM
# error recls/internal/recls_time.h must not be included directly. You should include recls/recls.h
#endif /* !RECLS_INCL_RECLS_INTERNAL_H_PLATFORM */

#include <time.h>

#if defined(RECLS_PLATFORM_IS_UNIX)
# include <sys/types.h>
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# include <windows.h>
#elif defined(RECLS_OVERRIDE_PLATFORM)
 /* You're expected to ensure that the appropriate inclusions are made */
#else
# error Platform not (yet) recognised
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** \def recls_time_t
 * The time type for the recls API.
 */

#if defined(RECLS_PURE_API) || \
    defined(RECLS_PLATFORM_IS_UNIX)

 typedef time_t                     recls_time_t;

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

 typedef FILETIME                   recls_time_t;

#elif defined(RECLS_OVERRIDE_PLATFORM)

# ifndef RECLS_CUSTOM_TIME_T
#  error Must define RECLS_CUSTOM_TIME_T if compiling with RECLS_OVERRIDE_PLATFORM
# endif /* !RECLS_CUSTOM_TIME_T */

# ifndef RECLS_CUSTOM_FILESIZE_T
#  error Must define RECLS_CUSTOM_FILESIZE_T if compiling with RECLS_OVERRIDE_PLATFORM
# endif /* !RECLS_CUSTOM_TIME_T */

 typedef RECLS_CUSTOM_TIME_T        recls_time_t;

#else

# error Platform not (yet) recognised

 typedef <platform-dependent-type>  recls_time_t;

#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_RECLS_TIME */

/* ///////////////////////////// end of file //////////////////////////// */
