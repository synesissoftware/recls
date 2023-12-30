/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/language.h
 *
 * Purpose:     Platform discrimination for the recls API.
 *
 * Created:     15th August 2003
 * Updated:     30th December 2023
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


#ifndef RECLS_INCL_RECLS_INTERNAL_H_LANGUAGE
#define RECLS_INCL_RECLS_INTERNAL_H_LANGUAGE

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_MAJOR      3
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_MINOR      1
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_REVISION   1
# define RECLS_VER_RECLS_INTERNAL_H_LANGUAGE_EDIT       18
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
# define RECLS_LINKAGE_C                                    extern "C"
# define RECLS_LINKAGE_CPP                                  extern "C++"
#else
# define RECLS_LINKAGE_C                                    extern
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

