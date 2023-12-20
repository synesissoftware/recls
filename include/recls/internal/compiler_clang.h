/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/compiler_clang.h
 *
 * Purpose:     Clang specific types and includes for the recls API.
 *
 * Created:     20th December 2023
 * Updated:     20th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2023, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#if !defined(RECLS_INCL_RECLS_INTERNAL_H_COMPILER) && \
    !defined(RECLS_DOCUMENTATION_SKIP_SECTION)
# error recls/internal/compiler_clang.h cannot be included directly. Include recls/recls.h
#else

#ifndef RECLS_COMPILER_IS_CLANG
# error recls/internal/compiler_clang.h can only be used for Clang compiler builds
#endif /* !RECLS_COMPILER_IS_CLANG */

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_CLANG_MAJOR      1
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_CLANG_MINOR      0
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_CLANG_REVISION   0
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_CLANG_EDIT       1
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/compiler_clang.h
 *
 * \brief [C, C++] Clang-specific compiler definitions for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stddef.h>
#include <stdint.h>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * #pragma once
 */

#define RECLS_CF_PRAGMA_ONCE_SUPPORT

/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/** \def recls_byte_t The byte type for the \ref group__recls  API */
/** \def recls_sint8_t The 8-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint8_t The 8-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint16_t The 16-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint16_t The 16-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint32_t The 32-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint32_t The 32-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint64_t The 64-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint64_t The 64-bit unsigned integer type for the \ref group__recls  API */

typedef uint8_t                                             recls_byte_t;

typedef int8_t                                              recls_sint8_t;
typedef uint8_t                                             recls_uint8_t;

typedef int16_t                                             recls_sint16_t;
typedef uint16_t                                            recls_uint16_t;

typedef int32_t                                             recls_sint32_t;
typedef uint32_t                                            recls_uint32_t;

typedef int64_t                                             recls_sint64_t;
typedef uint64_t                                            recls_uint64_t;

typedef uintptr_t                                           recls_uintptr_t;

/** \def recls_char_a_t The ANSI character type for the \ref group__recls  API */
/** \def recls_char_w_t The Unicode character type for the \ref group__recls  API */
typedef char                                                recls_char_a_t;
typedef wchar_t                                             recls_char_w_t;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* RECLS_INCL_RECLS_INTERNAL_H_COMPILER */

/* ///////////////////////////// end of file //////////////////////////// */

