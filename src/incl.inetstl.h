/* /////////////////////////////////////////////////////////////////////////
 * File:        incl.inetstl.h
 *
 * Purpose:     #includes the InetSTL root header and verifies the version.
 *
 * Created:     8th November 2007
 * Updated:     10th January 2017
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2017, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */

#ifndef RECLS_INCL_SRC_H_INCL_INETSTL
#define RECLS_INCL_SRC_H_INCL_INETSTL

/* ////////////////////////////////////////////////////////////////////// */

#include "incl.stlsoft.h"

#ifdef INETSTL_INCL_INETSTL_H_INETSTL
# error Must not #include inetstl/inetstl.h before this file
#endif /* INETSTL_INCL_INETSTL_H_INETSTL */

#include <inetstl/inetstl.h>    /* If the compiler cannot find this, you are not using STLSoft 1.9.1 or later, as required. */
#if !defined(_INETSTL_VER) || \
    _INETSTL_VER < 0x010305ff
# error Requires InetSTL 1.3.5, or later. (www.stlsoft.org/downloads.html)
#endif /* INETSTL version */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef _INETSTL_NO_NAMESPACE
# error recls 1.9+ is not compatible with InetSTL namespace suppression
#endif /* _INETSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_INETSTL */

/* ///////////////////////////// end of file //////////////////////////// */
