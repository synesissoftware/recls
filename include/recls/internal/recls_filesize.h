/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/recls_filesize.h (formerly in platform_types.h)
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_RECLS_FILESIZE
#define RECLS_INCL_RECLS_INTERNAL_H_RECLS_FILESIZE

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_FILESIZE_MAJOR    1
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_FILESIZE_MINOR    0
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_FILESIZE_REVISION 4
# define RECLS_VER_RECLS_INTERNAL_H_RECLS_FILESIZE_EDIT     5
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/recls_filesize.h
 *
 * \brief [C, C++] Partially platform-independent time type for .
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RECLS_INCL_RECLS_INTERNAL_H_PLATFORM
# error recls/internal/recls_filesize.h must not be included directly. You should include recls/recls.h
#endif /* !RECLS_INCL_RECLS_INTERNAL_H_PLATFORM */

#include <time.h>

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

/** The file-size type for the recls API.
 */
typedef recls_uint64_t              recls_filesize_t;

#ifdef __cplusplus
typedef recls_filesize_t            filesize_t;
#endif /* !__cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_RECLS_FILESIZE */

/* ///////////////////////////// end of file //////////////////////////// */
