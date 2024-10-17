/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/common.hpp
 *
 * Purpose: recls C++ mapping - common types and feature discrimination.
 *
 * Created: 18th August 2003
 * Updated: 30th December 2023
 *
 * Home:    https://github.com/synesissoftware/recls
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


/** \file recls/cpp/common.hpp
 *
 * \brief [C++] Common types and feature discrimination
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_COMMON
#define RECLS_INCL_RECLS_CPP_HPP_COMMON

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_COMMON_MAJOR       4
# define RECLS_VER_RECLS_CPP_HPP_COMMON_MINOR       0
# define RECLS_VER_RECLS_CPP_HPP_COMMON_REVISION    15
# define RECLS_VER_RECLS_CPP_HPP_COMMON_EDIT        52
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <recls/recls.h>

#include <stlsoft/stlsoft.h>

/* /////////////////////////////////////////////////////////////////////////
 * version checks
 */

#if !defined(_STLSOFT_VER) || \
    _STLSOFT_VER < 0x010b0148
# error The recls C++ mapping now requires version 1.11.1 (alpha 8) or later of the STLSoft libraries. (www.stlsoft.org/downloads.html)
#endif /* STLSoft version */

#if defined(_STLSOFT_NO_NAMESPACE)
# error The recls C++ mapping cannot be used with STLSoft in namespace suppression mode
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * feature support - 1: Properties (see chapter 35 of Imperfect C++; http://imperfectcplusplus.com/)
 */

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
# undef RECLS_CPP_METHOD_PROPERTY_SUPPORT
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

#if defined(RECLS_CPP_FORCE_METHOD_PROPERTY_SUPPORT)
# define RECLS_CPP_METHOD_PROPERTY_SUPPORT
#elif defined(RECLS_CPP_NO_METHOD_PROPERTY_SUPPORT)
 /* Do not define RECLS_CPP_METHOD_PROPERTY_SUPPORT */
#else /* ? RECLS_CPP_???_METHOD_PROPERTY_SUPPORT */
# if defined(STLSOFT_COMPILER_IS_BORLAND)
 /* Do not define RECLS_CPP_METHOD_PROPERTY_SUPPORT */
# elif defined(STLSOFT_COMPILER_IS_DMC)
#  if __DMC__ >= 0x0846
#   define RECLS_CPP_METHOD_PROPERTY_SUPPORT
#  endif /* __DMC__ */
# elif defined(STLSOFT_COMPILER_IS_GCC)
 /* Do not define RECLS_CPP_METHOD_PROPERTY_SUPPORT */
# elif defined(STLSOFT_COMPILER_IS_INTEL)
#  define RECLS_CPP_METHOD_PROPERTY_SUPPORT
# elif defined(STLSOFT_COMPILER_IS_MSVC)
#  if _MSC_VER >= 1310
#   define RECLS_CPP_METHOD_PROPERTY_SUPPORT
#  endif /* _MSC_VER */
# elif defined(STLSOFT_COMPILER_IS_MWERKS)
#  define RECLS_CPP_METHOD_PROPERTY_SUPPORT
# endif /* compiler */
#endif /* RECLS_CPP_???_METHOD_PROPERTY_SUPPORT */

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
# define RECLS_CPP_OPT_METHOD_PROPERTY_GET(V, R, C, GM, P)                  STLSOFT_METHOD_PROPERTY_GET(V, R, C, GM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(R, C, GM, P)                STLSOFT_METHOD_PROPERTY_GET_EXTERNAL_PROP(R, C, GM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GETSET(V, RG, RS, C, GM, SM, P)      STLSOFT_METHOD_PROPERTY_GETSET_EXTERNAL(RG, RS, C, GM, SM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(C, P)                  STLSOFT_METHOD_PROPERTY_DEFINE_OFFSET(C, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GETSET_PROP(RG, RS, C, GM, SM, P)    STLSOFT_METHOD_PROPERTY_GETSET_EXTERNAL_PROP(RG, RS, C, GM, SM, P)
#else /* ? RECLS_CPP_METHOD_PROPERTY_SUPPORT */
# define RECLS_CPP_OPT_METHOD_PROPERTY_GET(V, R, C, GM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(R, C, GM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GETSET(V, RG, RS, C, GM, SM, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(C, P)
# define RECLS_CPP_OPT_METHOD_PROPERTY_GETSET_PROP(RG, RS, C, GM, SM, P)
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

/* /////////////////////////////////////////////////////////////////////////
 * feature support - 2: string type
 */

#define RECLS_CPP_USE_STD_STRING

/* /////////////////////////////////////////////////////////////////////////
 * includes - 2
 */

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
# include <stlsoft/properties/method_properties.hpp>
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

#if defined(RECLS_CPP_USE_STD_STRING)
# include <string>
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
/** The namespace within which all the C++ mapping symbols are actually
 * defined. You need only qualify your use of them with
 * <code>recls::cpp</code> if you individually include the components'
 * headers. If you include recls/recls.hpp all the C++ mapping symbols are
 * introduced into the <code>recls</code> namespace.
 */
namespace cpp
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

typedef recls_char_t                                        char_t;

#if defined(RECLS_CPP_USE_STD_STRING)
typedef std::string                                         string_a_t;
typedef std::wstring                                        string_w_t;
typedef std::basic_string<recls_char_t>                     string_t;
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_COMMON */

/* ///////////////////////////// end of file //////////////////////////// */

