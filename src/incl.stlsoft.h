/* /////////////////////////////////////////////////////////////////////////
 * File:        incl.stlsoft.h
 *
 * Purpose:     #includes the STLSoft root header and verifies the version.
 *
 * Created:     8th November 2007
 * Updated:     17th November 2013
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2013, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */

#ifndef RECLS_INCL_SRC_H_INCL_STLSOFT
#define RECLS_INCL_SRC_H_INCL_STLSOFT

/* ////////////////////////////////////////////////////////////////////// */

#ifdef STLSOFT_INCL_STLSOFT_H_STLSOFT
# error Must not #include stlsoft/stlsoft.h before this file
#endif /* STLSOFT_INCL_STLSOFT_H_STLSOFT */

#ifdef RECLS_STLSOFT_1_12_OR_LATER
# undef RECLS_STLSOFT_1_12_OR_LATER
#endif /* RECLS_STLSOFT_1_12_OR_LATER */

#include <stlsoft/stlsoft.h>    /* If the compiler cannot find this, you are not using STLSoft 1.9.1 or later, as required. */
#if defined(STLSOFT_VER) && \
    STLSOFT_VER >= 0x010c0000
# define RECLS_STLSOFT_1_12_OR_LATER
#elif !defined(_STLSOFT_VER) || \
   _STLSOFT_VER < 0x010975ff
# error Requires STLSoft 1.9.117, or later. (www.stlsoft.org)
#endif /* STLSoft version */

/* /////////////////////////////////////////////////////////////////////////
 * Compatibility
 */

#ifdef _STLSOFT_NO_NAMESPACE
# error recls 1.9+ is not compatible with STLSoft namespace suppression
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_INCL_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */
