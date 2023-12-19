/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/compiler_watcom.h
 *
 * Purpose:     Watcom C++ specific types and includes for the recls API.
 *
 * Created:     23rd September 2003
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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
# error recls/internal/compiler_watcom.h cannot be included directly. Include recls/recls.h
#else

#ifndef RECLS_COMPILER_IS_WATCOM
# error recls/internal/compiler_watcom.h can only be used for Watcom C++ compiler builds
#endif /* !RECLS_COMPILER_IS_WATCOM */

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_WATCOM_MAJOR       2
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_WATCOM_MINOR       3
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_WATCOM_REVISION    1
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_WATCOM_EDIT        14
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/compiler_watcom.h
 *
 * \brief [C, C++] watcom c++-specific compiler definitions for the
 *  \ref group__recls api.
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
 * messaging
 */

#define RECLS_PRAGMA_MESSAGE_SUPPORT
#define RECLS_PRAGMA_MESSAGE_IS_INTRUSIVE

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

typedef unsigned char       recls_byte_t;

typedef signed char         recls_sint8_t;
typedef unsigned char       recls_uint8_t;

typedef signed short        recls_sint16_t;
typedef unsigned short      recls_uint16_t;

typedef signed long         recls_sint32_t;
typedef unsigned long       recls_uint32_t;

typedef signed __int64      recls_sint64_t;
typedef unsigned __int64    recls_uint64_t;

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
 * warnings
 */

#pragma warning 14  10 /* Suppresses "Warning! W014: no reference to symbol ..." */
#pragma warning 555 10 /* Suppresses "Warning! W555: expression for 'while' is always false" */
#pragma warning 594 10 /* Suppresses "Warning! W594: construct resolved as a declaration/type" */
#pragma warning 604 10 /* Suppresses "Warning! W604: must look ahead to determine whether construct is a declaration/type or an expression" */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* RECLS_INCL_RECLS_INTERNAL_H_COMPILER */

/* ///////////////////////////// end of file //////////////////////////// */
