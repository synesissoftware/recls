/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/internal/safestr.h
 *
 * Purpose:     Handles detection of safe string library.
 *
 * Created:     8th June 2008
 * Updated:     30th December 2023
 *
 * Author:      Matthew Wilson
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright:   Matthew Wilson and Synesis Software Pty Ltd, 2008.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file recls/internal/safestr.h
 *
 * \brief [C, C++] Handles detection of safe string library.
 */

#ifndef RECLS_INCL_RECLS_INTERNAL_H_SAFESTR
#define RECLS_INCL_RECLS_INTERNAL_H_SAFESTR

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RECLS_INCL_RECLS_H_RECLS
# include <recls/recls.h>
#endif /* !RECLS_INCL_RECLS_H_RECLS */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifdef __STDC_SECURE_LIB__
# if defined(__STDC_WANT_SECURE_LIB__) && \
     __STDC_WANT_SECURE_LIB__ == 1
#  define RECLS_USING_SAFE_STR_FUNCTIONS
# endif /* __STDC_WANT_SECURE_LIB__ */
#endif /* __STDC_SECURE_LIB__ */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* RECLS_INCL_RECLS_INTERNAL_H_SAFESTR */

/* ///////////////////////////// end of file //////////////////////////// */

