/* /////////////////////////////////////////////////////////////////////////
 * File:    src/incl.stlsoft.h
 *
 * Purpose: #includes the STLSoft root header and verifies the version.
 *
 * Created: 8th November 2007
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
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

#include <stlsoft/stlsoft.h>    /* If the compiler cannot find this, you are not using STLSoft 1.10.1 or later, as required. */
#if 0
#elif defined(STLSOFT_VER)

# if 0
# elif STLSOFT_VER >= 0x010c0000
#  define RECLS_STLSOFT_1_12_OR_LATER
# elif STLSOFT_VER >= 0x010b0000
#  define RECLS_STLSOFT_1_11_OR_LATER
# elif STLSOFT_VER >= 0x010a02ff
#  define RECLS_STLSOFT_1_10_1_OR_LATER
# else
#  error use of STLSoft 1.10 requires Version 1.10.2 or later
# endif

#elif defined(_STLSOFT_VER)

# if 0
# elif _STLSOFT_VER >= 0x010c0000
#  define RECLS_STLSOFT_1_12_OR_LATER
# elif _STLSOFT_VER >= 0x010b0000
#  define RECLS_STLSOFT_1_11_OR_LATER
# elif _STLSOFT_VER >= 0x010a02ff
#  define RECLS_STLSOFT_1_10_1_OR_LATER
# else
#  error use of STLSoft 1.10 requires Version 1.10.2 or later
# endif
#endif /* STLSoft version */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(__cplusplus) && \
    defined(_STLSOFT_NO_NAMESPACE)

# error recls 1.10+ is not compatible with STLSoft namespace suppression
#endif /* _STLSOFT_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_SRC_H_INCL_STLSOFT */

/* ///////////////////////////// end of file //////////////////////////// */

