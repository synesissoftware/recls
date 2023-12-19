/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/recls_time.h (formerly in platform_types.h)
 *
 * Purpose:     Partially platform-independent time type for recls.
 *
 * Created:     18th August 2003
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
