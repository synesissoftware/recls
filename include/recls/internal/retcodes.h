/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/internal/retcodes.h
 *
 * Purpose: Return codes for the  recls API.
 *
 * Created: 15th August 2003
 * Updated: 23rd February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#if !defined(RECLS_INCL_RECLS_H_RECLS) && \
    !defined(RECLS_DOCUMENTATION_SKIP_SECTION)
# error recls/retcodes.h cannot be included directly. Include recls/recls.h
#else

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_RETCODES_MAJOR      3
# define RECLS_VER_RECLS_INTERNAL_H_RETCODES_MINOR      7
# define RECLS_VER_RECLS_INTERNAL_H_RETCODES_REVISION   1
# define RECLS_VER_RECLS_INTERNAL_H_RETCODES_EDIT       39
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/retcodes.h
 *
 * \brief [C, C++] Return codes for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * helper macros
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_CAST_OPERATOR_TRIGRAPH_SPLITTER  /* Just to make doubly sure that we can't get a <:: trigraph from a globally qualified type */
# ifdef __cplusplus
#  define RECLS_STATIC_CAST_(t, v)              (static_cast<RECLS_CAST_OPERATOR_TRIGRAPH_SPLITTER t>(v))
# else /* ? __cplusplus */
#  define RECLS_STATIC_CAST_(t, v)              ((t)(v))
# endif /* __cplusplus */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * error codes
 */

/** \name Error codes
 *
 * \ingroup group__recls
 */
/** @{ */

/** No search is currently active */
#define RECLS_RC_SEARCH_NO_CURRENT                          RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1001))
/** The directory was invalid, or does not exist */
#define RECLS_RC_PATH_IS_NOT_DIRECTORY                      RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1002))
/** No more data is available */
#define RECLS_RC_NO_MORE_DATA                               RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1003))
/** Memory exhaustion */
#define RECLS_RC_OUT_OF_MEMORY                              RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1004))
/** Function not implemented */
#define RECLS_RC_NOT_IMPLEMENTED                            RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1005))
/** Invalid search type */
#define RECLS_RC_INVALID_SEARCH_TYPE                        RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1006))
/** Invalid search protocol */
#define RECLS_RC_INVALID_SEARCH_PROTOCOL                    RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1007))
/** Unexpected internal condition */
#define RECLS_RC_UNEXPECTED                                 RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1008))
/** Cannot specify "." pattern in recursive search */
#define RECLS_RC_DOT_RECURSIVE_SEARCH                       RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1009))
/** Search was cancelled by callback. It did not otherwise fail. */
#define RECLS_RC_SEARCH_CANCELLED                           RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1010))
/** FTP infrastructure initialisation failed. */
#define RECLS_RC_FTP_INIT_FAILED                            RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1011))
/** FTP connection failed. */
#define RECLS_RC_FTP_CONNECTION_FAILED                      RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1012))
/** Cannot call stat() on root */
#define RECLS_RC_CANNOT_STAT_ROOT                           RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1014))
/** Directory or pattern component exceeds maximum length for host system */
#define RECLS_RC_PATH_LIMIT_EXCEEDED                        RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1015))
/** User cancelled the search (by a 0 return from the Recls_SearchFeedback() callback function) */
#define RECLS_RC_USER_CANCELLED_SEARCH                      RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1016))
/** The user's home directory cannot be determined */
#define RECLS_RC_NO_HOME                                    RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1017))
/** The given file/path name was invalid */
#define RECLS_RC_INVALID_NAME                               RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1018))
/** Insufficient permissions */
#define RECLS_RC_ACCESS_DENIED                              RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1019))
/** Directory does not exist */
#define RECLS_RC_DIRECTORY_NOT_FOUND                        RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1020))

/** Given path was a directory when one was not expected */
#define RECLS_RC_ENTRY_IS_DIRECTORY                         RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1021))
/** Given path was not a directory when one was expected */
#define RECLS_RC_ENTRY_IS_NOT_DIRECTORY                     RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1022))

#ifdef RECLS_PLATFORM_IS_WINDOWS
/** Short name not available */
# define RECLS_RC_SHORT_NAME_NOT_AVAILABLE                  RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1023))
#endif

/** Invalid-characters in search directory : the search-directory parameter cannot contain path separator or wildcard characters */
#define RECLS_RC_SEARCH_DIRECTORY_INVALID_CHARACTERS        RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1024))

/** A rooted pattern must not be specified with other patterns */
#define RECLS_RC_ROOTED_PATHS_IN_PATTERNS                   RECLS_STATIC_CAST_(RECLS_QUAL(recls_rc_t), RECLS_RC_VALUE(-1 - 1025))
/** @} */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef RECLS_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* RECLS_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_RECLS_H_RECLS */

/* ///////////////////////////// end of file //////////////////////////// */

