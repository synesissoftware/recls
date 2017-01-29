/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/language.h
 *
 * Purpose:     Platform discrimination for the recls API.
 *
 * Created:     15th August 2003
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_LANGUAGE
#define RECLS_INCL_RECLS_INTERNAL_H_LANGUAGE

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_MAJOR      3
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_MINOR      1
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_REVISION   1
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_EDIT       17
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/language.h
 *
 * \brief [C, C++] Language detection for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * linkage
 */

/** \def RECLS_LINKAGE_C The linkage for <b>recls</b> functions. Is \c extern \c "C" in C++ and \c extern in C. */

#ifdef __cplusplus
# define RECLS_LINKAGE_C            extern "C"
# define RECLS_LINKAGE_CPP          extern "C++"
#else
# define RECLS_LINKAGE_C            extern
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(__cplusplus)
# define RECLS_NO_NAMESPACE
#endif /* !__cplusplus */

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

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_LANGUAGE */

/* ///////////////////////////// end of file //////////////////////////// */
