/* /////////////////////////////////////////////////////////////////////////
 * File:        incl.winstl.h
 *
 * Purpose:     #includes the WinSTL root header and verifies the version.
 *
 * Created:     8th November 2007
 * Updated:     21st December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */

#ifndef RECLS_INCL_SRC_H_INCL_WINSTL
#define RECLS_INCL_SRC_H_INCL_WINSTL

/* ////////////////////////////////////////////////////////////////////// */

#include "incl.stlsoft.h"

#ifdef WINSTL_INCL_WINSTL_H_WINSTL
# error Must not #include winstl/winstl.h before this file
#endif /* WINSTL_INCL_WINSTL_H_WINSTL */

#include <winstl/winstl.h>      /* If the compiler cannot find this, you are not using STLSoft 1.9.1 or later, as required. */
#if !defined(_WINSTL_VER) || \
    _WINSTL_VER < 0x010c0185
# error Requires WinSTL 1.12.1 beta 5, or later. (www.stlsoft.org/downloads.html)
#endif /* WINSTL version */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef _WINSTL_NO_NAMESPACE
# error recls 1.10+ is not compatible with WinSTL namespace suppression
#endif /* _WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_WINSTL */

/* ///////////////////////////// end of file //////////////////////////// */

