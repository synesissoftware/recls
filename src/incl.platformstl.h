/* /////////////////////////////////////////////////////////////////////////
 * File:        src/incl.platformstl.h
 *
 * Purpose:     #includes the PlatformSTL root header and verifies the version.
 *
 * Created:     13th December 2008
 * Updated:     30th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */

#ifndef RECLS_INCL_SRC_H_INCL_PLATFORMSTL
#define RECLS_INCL_SRC_H_INCL_PLATFORMSTL

/* ////////////////////////////////////////////////////////////////////// */

#include "incl.stlsoft.h"

#ifdef PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL
# error Must not #include platformstl/platformstl.h before this file
#endif /* PLATFORMSTL_INCL_PLATFORMSTL_H_PLATFORMSTL */

#include <platformstl/platformstl.h>      /* If the compiler cannot find this, you are not using STLSoft 1.10.1 or later, as required. */
#if !defined(_PLATFORMSTL_VER) || \
    _PLATFORMSTL_VER < 0x01090183
# error Requires PlatformSTL 1.9.1 beta 3, or later. (www.stlsoft.org/downloads.html)
#endif /* PlatformSTL version */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef _PLATFORMSTL_NO_NAMESPACE
# error recls 1.10+ is not compatible with PlatformSTL namespace suppression
#endif /* _PLATFORMSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_PLATFORMSTL */

/* ///////////////////////////// end of file //////////////////////////// */

