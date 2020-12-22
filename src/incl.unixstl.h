/* /////////////////////////////////////////////////////////////////////////
 * File:        incl.unixstl.h
 *
 * Purpose:     #includes the UNIXSTL root header and verifies the version.
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

#ifndef RECLS_INCL_SRC_H_INCL_UNIXSTL
#define RECLS_INCL_SRC_H_INCL_UNIXSTL

/* ////////////////////////////////////////////////////////////////////// */

#include "incl.stlsoft.h"

#ifdef UNIXSTL_INCL_UNIXSTL_H_UNIXSTL
# error Must not #include unixstl/unixstl.h before this file
#endif /* UNIXSTL_INCL_UNIXSTL_H_UNIXSTL */

#include <unixstl/unixstl.h>    /* If the compiler cannot find this, you are not using STLSoft 1.9.1 or later, as required. */
#if !defined(_UNIXSTL_VER) || \
    _UNIXSTL_VER < 0x010704ff
# error Requires UNIXSTL 1.7.4, or later. (www.stlsoft.org/downloads.html)
#endif /* UNIXSTL version */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef _UNIXSTL_NO_NAMESPACE
# error recls 1.9+ is not compatible with UNIXSTL namespace suppression
#endif /* _UNIXSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_UNIXSTL */

/* ///////////////////////////// end of file //////////////////////////// */
