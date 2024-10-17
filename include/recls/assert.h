/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/assert.h
 *
 * Purpose: Assertion macros for recls API.
 *
 * Created: 15th August 2003
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


#ifndef RECLS_INCL_RECLS_H_ASSERT
#define RECLS_INCL_RECLS_H_ASSERT

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_H_ASSERT_MAJOR     3
# define RECLS_VER_RECLS_H_ASSERT_MINOR     1
# define RECLS_VER_RECLS_H_ASSERT_REVISION  2
# define RECLS_VER_RECLS_H_ASSERT_EDIT      29
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/assert.h
 *
 * \brief [C, C++] Assertions for the \ref group__recls API.
 */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

/** \def RECLS_ASSERT
 * Contract enforcement macro for the recls API
 *
 * \ingroup group__recls
 *
 * If the given expressions evaluates to false (0), the execution is halted and
 * an error message given.
 *
 * \param x The expression that must evaluate to \c true
 */

#if defined(RECLS_PLATFORM_IS_WINDOWS) && \
    defined(_MSC_VER) && \
    (   defined(_DEBUG) || \
        defined(DEBUG))
# include <crtdbg.h> /* Prefer MSVCRT for VC++ and compatible compilers */
# define RECLS_ASSERT(x)                    _ASSERTE(x)
#else
# include <assert.h>
# define RECLS_ASSERT(x)                    assert(x)
#endif /* compiler */

/** \def recls_assert(expr)
 *
 * \ingroup group__recls
 *
 * Defines a compile-time assertion
 *
 * \param expr Must be non-zero, or compilation will fail.
 *
 * \deprecated This is deprecated in favour of RECLS_ASSERT().
 *
 * \note This is a simple \#define for RECLS_ASSERT().
 */
#define recls_assert(expr)                  RECLS_ASSERT(expr)


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

/** \def RECLS_MESSAGE_ASSERT
 * Contract enforcement macro for the recls API
 *
 * \ingroup group__recls
 *
 * If the given expressions evaluates to false (0), the execution is halted and
 * an error message given.
 *
 * \param m The literal string describing the failed condition
 * \param x The expression that must evaluate to \c true
 */

#if defined(__WATCOMC__)
# define RECLS_MESSAGE_ASSERT(m, x)         RECLS_ASSERT(x)
#elif defined(__COMO__) || \
       defined(__GNUC__) || \
       defined(__MWERKS__)
# define RECLS_MESSAGE_ASSERT(m, x)         RECLS_ASSERT(((m) && (x)))
#else /* ? compiler */
# define RECLS_MESSAGE_ASSERT(m, x)         RECLS_ASSERT(((m), (x)))
#endif /* compiler */

/** \def recls_message_assert(msg, expr)
 *
 * \ingroup group__recls
 *
 * Defines a compile-time assertion.
 *
 * \param msg The message to be displayed to the user if the \c expr evaluates to 0
 * \param expr Must be non-zero, or compilation will fail.
 *
 * \deprecated This is deprecated in favour of RECLS_MESSAGE_ASSERT().
 *
 * \note This is a simple \#define for RECLS_MESSAGE_ASSERT().
 */
#define recls_message_assert(msg, expr)     RECLS_MESSAGE_ASSERT(msg, expr)


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


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

#endif /* !RECLS_INCL_RECLS_H_ASSERT */

/* ///////////////////////////// end of file //////////////////////////// */

