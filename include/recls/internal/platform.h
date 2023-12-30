/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/platform.h
 *
 * Purpose:     Platform discrimination for the recls API.
 *
 * Created:     15th August 2003
 * Updated:     30th December 2023
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_PLATFORM
#define RECLS_INCL_RECLS_INTERNAL_H_PLATFORM

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_MAJOR      3
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_MINOR      3
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_REVISION   1
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_EDIT       29
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/platform.h
 *
 * \brief [C, C++] Platform detection for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * platform recognition
 *
 * Define the symbol RECLS_OVERRIDE_PLATFORM to provide your own platform
 * discrimination
 */

#if defined(_WIN64)
# if defined(EMULATE_UNIX_ON_WIN64) && \
     !defined(EMULATE_UNIX_ON_WINDOWS)
#  define EMULATE_UNIX_ON_WINDOWS
# endif /* EMULATE_UNIX_ON_WIN64 && !EMULATE_UNIX_ON_WINDOWS */
# if !defined(EMULATE_UNIX_ON_WIN64) && \
     defined(EMULATE_UNIX_ON_WINDOWS)
#  define EMULATE_UNIX_ON_WIN64
# endif /* !EMULATE_UNIX_ON_WIN64 && EMULATE_UNIX_ON_WINDOWS */
#elif defined(_WIN32)
# if defined(EMULATE_UNIX_ON_WIN32) && \
     !defined(EMULATE_UNIX_ON_WINDOWS)
#  define EMULATE_UNIX_ON_WINDOWS
# endif /* EMULATE_UNIX_ON_WIN32 && !EMULATE_UNIX_ON_WINDOWS */
# if !defined(EMULATE_UNIX_ON_WIN32) && \
     defined(EMULATE_UNIX_ON_WINDOWS)
#  define EMULATE_UNIX_ON_WIN32
# endif /* !EMULATE_UNIX_ON_WIN32 && EMULATE_UNIX_ON_WINDOWS */
#endif /* _WIN32 || _WIN64 */


#ifndef RECLS_OVERRIDE_PLATFORM
# if defined(unix) || \
     defined(UNIX) || \
     defined(__unix) || \
     defined(__unix__) || \
     (   defined(__xlC__) && \
         defined(_POWER) && \
         defined(_AIX))
   /* Platform is UNIX */
#  define RECLS_PLATFORM_IS_UNIX
   /* Now determine whether this is being emulated on Windows */
#  if defined(_WIN64) && \
      ( defined(EMULATE_UNIX_ON_WIN64) || \
        defined(EMULATE_UNIX_ON_WINDOWS))
#   define RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WIN64
#   define RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
#  elif defined(_WIN32) && \
      ( defined(EMULATE_UNIX_ON_WIN32) || \
        defined(EMULATE_UNIX_ON_WINDOWS))
#   define RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WIN32
#   define RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
#  endif /* Windows */
# elif defined(WIN64)
   /* Platform is Win64 */
#  define RECLS_PLATFORM_IS_WIN64
#  define RECLS_PLATFORM_IS_WINDOWS
# elif defined(WIN32)
   /* Platform is Win32 */
#  define RECLS_PLATFORM_IS_WIN32
#  define RECLS_PLATFORM_IS_WINDOWS
# else /* ? platform */
#  error Platform not (yet) recognised
# endif /* platform */
#endif /* !RECLS_OVERRIDE_PLATFORM */

#if defined(RECLS_PLATFORM_IS_UNIX)
# if defined(__amd64__) || \
     defined(__amd64) || \
     defined(_AMD64_) || \
     defined(_M_AMD64) || \
     defined(_M_X64)
#  define RECLS_ARCH_IS_X64
# elif defined(__ia64__) || \
       defined(__ia64) || \
       defined(_IA64_) || \
       defined(_M_IA64)
#  define RECLS_ARCH_IS_IA64
# elif defined(__i386__) || \
       defined(__i386) || \
       defined(_X86_) || \
       defined(_M_IX86)
#  define RECLS_ARCH_IS_X86
# endif /* _M_?? */
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# if defined(_M_IA64)
#  define RECLS_ARCH_IS_IA64
# elif defined(_M_X64) || \
       defined(_M_AMD64)
#  define RECLS_ARCH_IS_X64
# elif defined(_M_IX86)
#  define RECLS_ARCH_IS_X86
# endif /* _M_?? */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#if defined(RECLS_PLATFORM_IS_WINDOWS)
# if !defined(RECLS_PURE_API)
#  include <windows.h>
# endif /* !RECLS_PURE_API */
#elif defined(RECLS_PLATFORM_IS_UNIX)
# include <unistd.h>
#elif defined(RECLS_OVERRIDE_PLATFORM)
  /* Assume that the appropriate inclusions are made */
#else
# error Platform not (yet) recognised
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * FTP support
 */

#if defined(RECLS_API_FTP)
# if !defined(WIN32) && \
     !defined(WIN64)
#  undef RECLS_API_FTP
# endif
#endif /* RECLS_API_FTP */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * constants and definitions
 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_PLATFORM */

/* ///////////////////////////// end of file //////////////////////////// */

