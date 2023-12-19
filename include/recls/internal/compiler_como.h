/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/compiler_como.h
 *
 * Purpose:     Como specific types and includes for the recls API.
 *
 * Created:     8th June 2004
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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
# error recls/internal/compiler_como.h cannot be included directly. Include recls/recls.h
#else

#ifndef RECLS_COMPILER_IS_COMO
# error recls/internal/compiler_como.h can only be used for Ch compiler builds
#endif /* !RECLS_COMPILER_IS_COMO */

#if _MSC_VER < 1100
# error recls is not supported on versions of Visual C++ prior to version 5.0
#endif /* _MSC_VER < 1100 */

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_COMO_MAJOR     3
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_COMO_MINOR     2
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_COMO_REVISION  1
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_COMO_EDIT      11
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/compiler_como.h
 *
 * \brief [C, C++] Comeau-specific compiler definitions for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <stddef.h>

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

/** \def recls_byte_t The byte type for the \ref group__recls  API */
/** \def recls_sint8_t The 8-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint8_t The 8-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint16_t The 16-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint16_t The 16-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint32_t The 32-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint32_t The 32-bit unsigned integer type for the \ref group__recls  API */
/** \def recls_sint64_t The 64-bit signed integer type for the \ref group__recls  API */
/** \def recls_uint64_t The 64-bit unsigned integer type for the \ref group__recls  API */

typedef unsigned char       recls_byte_t;

typedef signed char         recls_sint8_t;
typedef unsigned char       recls_uint8_t;

typedef signed short        recls_sint16_t;
typedef unsigned short      recls_uint16_t;

typedef signed long         recls_sint32_t;
typedef unsigned long       recls_uint32_t;

typedef signed long long    recls_sint64_t;
typedef unsigned long long  recls_uint64_t;

#if defined(_WIN64)
typedef recls_uint64_t      recls_uintptr_t;
#else /* ? _WIN64 */
typedef recls_uint32_t      recls_uintptr_t;
#endif /* _WIN64 */

/** \def recls_char_a_t The ANSI character type for the \ref group__recls  API */
/** \def recls_char_w_t The Unicode character type for the \ref group__recls  API */
typedef char                recls_char_a_t;
typedef wchar_t             recls_char_w_t;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* RECLS_INCL_RECLS_INTERNAL_H_COMPILER */

/* ///////////////////////////// end of file //////////////////////////// */

