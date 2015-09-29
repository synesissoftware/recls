/* /////////////////////////////////////////////////////////////////////////
 * File:        incl.platformstl.h
 *
 * Purpose:     #includes the PlatformSTL root header and verifies the version.
 *
 * Created:     13th December 2008
 * Updated:     29th November 2011
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2008-2011, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */

#ifndef RECLS_INCL_SRC_H_INCL_PLATFORMSTL
#define RECLS_INCL_SRC_H_INCL_PLATFORMSTL

/* ////////////////////////////////////////////////////////////////////// */

#include "incl.stlsoft.h"

#ifdef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# error Must not #include platformstl/platformstl.h before this file
#endif /* PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */

#include <platformstl/platformstl.h>      /* If the compiler cannot find this, you are not using STLSoft 1.9.1 or later, as required. */
#if !defined(_PLATFORMSTL_VER) || \
    _PLATFORMSTL_VER < 0x010803ff
# error Requires PlatformSTL 1.8.3, or later. (www.stlsoft.org/downloads.html)
#endif /* PlatformSTL version */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifdef _PLATFORMSTL_NO_NAMESPACE
# error recls 1.9+ is not compatible with PlatformSTL namespace suppression
#endif /* _PLATFORMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_PLATFORMSTL */

/* ///////////////////////////// end of file //////////////////////////// */
