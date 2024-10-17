/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.root.h
 *
 * Purpose: Implementation root header.
 *
 * Created: 7th March 2005
 * Updated: 17th October 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_H_IMPL_ROOT
#define RECLS_INCL_SRC_H_IMPL_ROOT


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#ifdef RECLS_PURE_API
# error Cannot define RECLS_PURE_API for the implementation of recls
#endif /* RECLS_PURE_API */

#ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
# include <windows.h>
#endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */


/* /////////////////////////////////////////////////////////////////////////
 * C++ stuff
 */

#ifdef __cplusplus
# include "incl.stlsoft.h"
# include <stlsoft/conversion/sap_cast.hpp>
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * exceptions
 */

#ifdef __cplusplus

# if defined(STLSOFT_CF_EXCEPTION_SUPPORT)

#  define RECLS_EXCEPTION_SUPPORT_
#  ifdef STLSOFT_CF_THROW_BAD_ALLOC

#   define RECLS_COMPILER_THROWS_ON_NEW_FAIL
#  endif /* STLSOFT_CF_THROW_BAD_ALLOC */
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * debugging?
 */

/** \def RECLS_DEBUG
 *
 * \brief Used to discriminate intrinsic debug level.
 *
 * Defined if NDEBUG is not defined on UNIX, or either DEBUG or _DEBUG are
 * defined on Windows.
 */

#ifdef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_DEBUG
#endif /* RECLS_DOCUMENTATION_SKIP_SECTION */

#if 0
#elif defined(NDEBUG)

# ifdef RECLS_DEBUG
#  undef RECLS_DEBUG
# endif /* RECLS_DEBUG */
#elif defined(DEBUG) || \
      defined(_DEBUG)

# ifndef RECLS_DEBUG
#  define RECLS_DEBUG
# endif /* !RECLS_DEBUG */
#else /* ? */

 /* Neither NDEBUG nor DEBUG (/_DEBUG) are defined */
# if defined(RECLS_PLATFORM_IS_UNIX)

  /* On UNIX, we define RECLS_DEBUG */
#  ifndef RECLS_DEBUG
#   define RECLS_DEBUG
#  endif /* !RECLS_DEBUG */
# elif defined(RECLS_PLATFORM_IS_WINDOWS)

  /* On Windows, we do not define RECLS_DEBUG */
#  ifndef RECLS_DEBUG
#   define RECLS_DEBUG
#  endif /* !RECLS_DEBUG */
# else /* ? platform */

#  error Platform not discriminated
# endif /* platform */
#endif /* debug */


/* /////////////////////////////////////////////////////////////////////////
 * contract enforcement
 */

/** \def RECLS_ENFORCING_CONTRACTS If defined, it indicates that contract enforcement will be active */

#if defined(RECLS_DEBUG) || \
    defined(RECLS_ENFORCE_CONTRACTS)
# define RECLS_ENFORCING_CONTRACTS
#endif /* RECLS_DEBUG || RECLS_ENFORCE_CONTRACTS */


/* /////////////////////////////////////////////////////////////////////////
 * multithreading
 */

/** \def RECLS_MT If defined, it indicates a multithreaded build */

#if defined(RECLS_PLATFORM_IS_UNIX)

# if defined(_REENTRANT)

#  define RECLS_MT
# elif defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS) && \
       (    defined(_MT) || \
            defined(__MT__))

#  define RECLS_MT
#  ifndef _REENTRANT
#   define _REENTRANT
#  endif /* !_REENTRANT */
# endif /* threads? */
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

# if defined(_MT) || \
     defined(__MT__)
#  define RECLS_MT
# endif /* threads? */
#endif /* platform */


/* /////////////////////////////////////////////////////////////////////////
 * multi-part patterns
 */

#if 1 && \
    (   !defined(RECLS_COMPILER_IS_MSVC) || \
        _MSC_VER >= 1200) && \
    !defined(RECLS_COMPILER_IS_WATCOM) && \
    1

# define RECLS_SUPPORTS_MULTIPATTERN_
#endif /* compiler */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_SRC_H_IMPL_ROOT */

/* ///////////////////////////// end of file //////////////////////////// */

