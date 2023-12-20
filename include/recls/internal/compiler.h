/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/compiler.h
 *
 * Purpose:     Compiler discrimination for the recls API.
 *
 * Created:     15th August 2003
 * Updated:     20th December 2023
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_COMPILER
#define RECLS_INCL_RECLS_INTERNAL_H_COMPILER

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_MAJOR      4
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_MINOR      1
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_REVISION   2
# define RECLS_VER_RECLS_INTERNAL_H_COMPILER_EDIT       23
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/compiler.h
 *
 * \brief [C, C++] Compiler detection for the \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * compiler detection
 */

#if defined(RECLS_FORCE_COMPILER_GCC)
# if !defined(__GNUC__)
#  error Cannot force compiler GCC because it is not detected
# endif
#endif

#if 0
#elif 1 &&\
      defined(__clang__) && \
      !defined(RECLS_FORCE_COMPILER_GCC) &&\
      1
# define RECLS_COMPILER_IS_CLANG
#elif defined(__COMO__)
# define RECLS_COMPILER_IS_COMO
#elif defined(__BORLANDC__)
# define RECLS_COMPILER_IS_BORLAND
#elif defined(_CH_)
# define RECLS_COMPILER_IS_CH
#elif defined(__DMC__)
# define RECLS_COMPILER_IS_DMC
#elif defined(__GNUC__)
# define RECLS_COMPILER_IS_GCC
#elif defined(__INTEL_COMPILER)
# define RECLS_COMPILER_IS_INTEL
#elif defined(__MWERKS__)
# define RECLS_COMPILER_IS_MWERKS
#elif defined(__VECTORC)
# define RECLS_COMPILER_IS_VECTORC
#elif defined(__WATCOMC__)
# define RECLS_COMPILER_IS_WATCOM
#elif defined(_MSC_VER)
# define RECLS_COMPILER_IS_MSVC
#else
# error Compiler not recognised
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#if 0
#elif defined(RECLS_COMPILER_IS_BORLAND)
# include <recls/internal/compiler_borland.h>
#elif defined(RECLS_COMPILER_IS_CH)
# include <recls/internal/compiler_ch.h>
#elif defined(RECLS_COMPILER_IS_CLANG)
# include <recls/internal/compiler_clang.h>
#elif defined(RECLS_COMPILER_IS_COMO)
# include <recls/internal/compiler_como.h>
#elif defined(RECLS_COMPILER_IS_DMC)
# include <recls/internal/compiler_dmc.h>
#elif defined(RECLS_COMPILER_IS_GCC)
# include <recls/internal/compiler_gcc.h>
#elif defined(RECLS_COMPILER_IS_INTEL)
# include <recls/internal/compiler_intel.h>
#elif defined(RECLS_COMPILER_IS_MSVC)
# include <recls/internal/compiler_msvc.h>
#elif defined(RECLS_COMPILER_IS_MWERKS)
# include <recls/internal/compiler_mwerks.h>
#elif defined(RECLS_COMPILER_IS_VECTORC)
# include <recls/internal/compiler_vectorc.h>
#elif defined(RECLS_COMPILER_IS_WATCOM)
# include <recls/internal/compiler_watcom.h>
#else
# error Compiler not recognised. recls recognises Borland, CodeWarrior, Digital Mars, GCC, Intel, Visual C++ and Watcom.
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * calling convention
 */

/** \def RECLS_CALLCONV_NULL
 * Unspecified calling convention for the \c recls API.
 */
/** \def RECLS_CALLCONV_CDECL
 * \c cdecl calling convention for the \c recls API.
 */
/** \def RECLS_CALLCONV_STDDECL
 * \c stdcall calling convention for the \c recls API.
 */
/** \def RECLS_CALLCONV_FASTDECL
 * \c fastcall calling convention for the \c recls API.
 */
/** \def RECLS_CALLCONV_DEFAULT
 * Default calling convention for the \c recls API.
 */

#define RECLS_CALLCONV_NULL
#if defined(RECLS_OVERRIDE_PLATFORM)
# ifndef RECLS_CALLCONV_CDECL
#  define RECLS_CALLCONV_CDECL
# endif /* !RECLS_CALLCONV_CDECL */
# ifndef RECLS_CALLCONV_STDDECL
#  define RECLS_CALLCONV_STDDECL
# endif /* !RECLS_CALLCONV_STDDECL */
# ifndef RECLS_CALLCONV_FASTDECL
#  define RECLS_CALLCONV_FASTDECL
# endif /* !RECLS_CALLCONV_FASTDECL */
# ifndef RECLS_CALLCONV_DEFAULT
#  define RECLS_CALLCONV_DEFAULT
# endif /* !RECLS_CALLCONV_DEFAULT */
#elif defined(RECLS_DOCUMENTATION_SKIP_SECTION)
# define RECLS_CALLCONV_CDECL
# define RECLS_CALLCONV_STDDECL
# define RECLS_CALLCONV_FASTDECL
# define RECLS_CALLCONV_DEFAULT
#elif defined(RECLS_PLATFORM_IS_WIN64)
# define RECLS_CALLCONV_CDECL
# define RECLS_CALLCONV_STDDECL
# define RECLS_CALLCONV_FASTDECL
# define RECLS_CALLCONV_DEFAULT
#elif defined(RECLS_PLATFORM_IS_WIN32)
# define RECLS_CALLCONV_CDECL                               __cdecl
# define RECLS_CALLCONV_STDDECL                             __stdcall
# define RECLS_CALLCONV_FASTDECL                            __fastcall
# define RECLS_CALLCONV_DEFAULT                             __cdecl
#elif defined(RECLS_PLATFORM_IS_WIN16)
# define RECLS_CALLCONV_CDECL                               _cdecl
# define RECLS_CALLCONV_STDDECL                             _pascal
# define RECLS_CALLCONV_FASTDECL                            _pascal
# define RECLS_CALLCONV_DEFAULT                             _cdecl
#elif defined(RECLS_PLATFORM_IS_UNIX)
# define RECLS_CALLCONV_CDECL
# define RECLS_CALLCONV_STDDECL
# define RECLS_CALLCONV_FASTDECL
# define RECLS_CALLCONV_DEFAULT
#else /* ? OS */
# error Platform not recognised
#endif /* __SYNSOFT_VAL_OS_WIN16 */

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

/** \def recls_bool_t The boolean type of the \c recls API */
typedef unsigned int                                        recls_bool_t;

/* /////////////////////////////////////////////////////////////////////////
 * namespace typedefs
 */

#if !defined(RECLS_NO_NAMESPACE)
typedef recls_sint8_t                                       sint8_t;
typedef recls_uint8_t                                       uint8_t;

typedef recls_sint16_t                                      sint16_t;
typedef recls_uint16_t                                      uint16_t;

typedef recls_sint32_t                                      sint32_t;
typedef recls_uint32_t                                      uint32_t;

typedef recls_sint64_t                                      sint64_t;
typedef recls_uint64_t                                      uint64_t;

typedef recls_bool_t                                        bool_t;
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

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_COMPILER */

/* ///////////////////////////// end of file //////////////////////////// */

