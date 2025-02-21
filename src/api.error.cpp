/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.error.cpp
 *
 * Purpose: Main (platform-independent) implementation file for recls API.
 *
 * Created: 16th August 2003
 * Updated: 20th February 2025
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "impl.util.h"

#include "ReclsSearch.hpp"

#include "impl.trace.h"

#include <errno.h>

/* /////////////////////////////////////////////////////////////////////////
 * errno
 *
 * Standard errno values:
 *
 * - EDOM
 * - EILSEQ
 * - ERANGE
 *
 * everything else must be translated if it doesn't exist
 */

#ifndef EZERO
# define EZERO                                              (0)
#endif

#ifndef EFAIL
# define EFAIL                                              (stlsoft_static_cast(int, stlsoft_static_cast(unsigned int, 0x01) << ((sizeof(int) * 8) - 1)))
#endif

#ifndef ENOSYS
# define ENOSYS                                             (EFAIL)
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

static
recls_char_t const*
lookup_error_string_(
    recls_rc_t  rc
,   int*        e
,   size_t*     len
)
{
    struct StringEntry
    {
        recls_rc_t          rc;
        int                 e;
        recls_char_t const* str;
        size_t              len;
    };

#define RC_STR_DECL(rc, e, desc)                                                    \
                                                                                    \
    static const recls_char_t   s_str##rc[] =   RECLS_LITERAL(desc);                \
    static const StringEntry    s_rct##rc = { rc, e, s_str##rc, NUM_ELEMENTS(desc) - 1 }


#define RC_STR_ENTRY(rc)        &s_rct##rc

#ifndef NUM_ELEMENTS
# define NUM_ELEMENTS(ar)       (sizeof(ar) / sizeof(ar[0]))
#endif /* !NUM_ELEMENTS */

    RC_STR_DECL(RECLS_RC_OK,                        EZERO,          "operation completed successfully");
    RC_STR_DECL(RECLS_RC_FAIL,                      EFAIL,          "unspecified failure");

    RC_STR_DECL(RECLS_RC_SEARCH_NO_CURRENT,         EINVAL,         "search has no current node");
    RC_STR_DECL(RECLS_RC_PATH_IS_NOT_DIRECTORY,     EINVAL,         "path is not a directory");
    RC_STR_DECL(RECLS_RC_NO_MORE_DATA,              ENOENT,         "no more data");
    RC_STR_DECL(RECLS_RC_OUT_OF_MEMORY,             ENOMEM,         "no more memory");
    RC_STR_DECL(RECLS_RC_NOT_IMPLEMENTED,           ENOSYS,         "not implemented");
    RC_STR_DECL(RECLS_RC_INVALID_SEARCH_TYPE,       EINVAL,         "the search type was invalid");
    RC_STR_DECL(RECLS_RC_INVALID_SEARCH_PROTOCOL,   EINVAL,         "the search protocol was invalid");
    RC_STR_DECL(RECLS_RC_UNEXPECTED,                EIO,            "an unexpected internal condition was encountered");
    RC_STR_DECL(RECLS_RC_DOT_RECURSIVE_SEARCH,      EINVAL,         "\"..\" specifed, or \".\" specified pattern in recursive search");
    RC_STR_DECL(RECLS_RC_SEARCH_CANCELLED,          EIO,            "the search was cancelled; it did not otherwise fail");
    RC_STR_DECL(RECLS_RC_FTP_INIT_FAILED,           EIO,            "FTP infrastructure initialisation failed");
    RC_STR_DECL(RECLS_RC_FTP_CONNECTION_FAILED,     EIO,            "FTP connection failed/rejected");
    RC_STR_DECL(RECLS_RC_CANNOT_STAT_ROOT,          EINVAL,         "cannot call stat() on root");
    RC_STR_DECL(RECLS_RC_PATH_LIMIT_EXCEEDED,       ENAMETOOLONG,   "directory or pattern component exceeds maximum length for host system");
    RC_STR_DECL(RECLS_RC_USER_CANCELLED_SEARCH,     0,              "user cancelled the search");
    RC_STR_DECL(RECLS_RC_NO_HOME,                   EINVAL,         "the user's home directory cannot be determined");
    RC_STR_DECL(RECLS_RC_INVALID_NAME,              EINVAL,         "the given file/path name was invalid");
    RC_STR_DECL(RECLS_RC_ACCESS_DENIED,             EACCES,         "insufficient permissions");
    RC_STR_DECL(RECLS_RC_DIRECTORY_NOT_FOUND,       EINVAL,         "directory not found");
    RC_STR_DECL(RECLS_RC_ENTRY_IS_DIRECTORY,        EISDIR,         "given path was a directory when one was not expected");
    RC_STR_DECL(RECLS_RC_ENTRY_IS_NOT_DIRECTORY,    ENOTDIR,        "given path was not a directory when one was expected");
#ifdef RECLS_PLATFORM_IS_WINDOWS
    RC_STR_DECL(RECLS_RC_SHORT_NAME_NOT_AVAILABLE,  EFAIL,          "could not obtain short name");
#endif
    RC_STR_DECL(RECLS_RC_SEARCH_DIRECTORY_INVALID_CHARACTERS,   EINVAL,         "the search-directory parameter cannot contain path separator or wildcard characters");
    RC_STR_DECL(RECLS_RC_ROOTED_PATHS_IN_PATTERNS,              EINVAL,         "a rooted pattern must not be specified with other patterns");


    static const StringEntry* entries[] =
    {
        RC_STR_ENTRY(RECLS_RC_OK),
        RC_STR_ENTRY(RECLS_RC_FAIL),

        RC_STR_ENTRY(RECLS_RC_SEARCH_NO_CURRENT),
        RC_STR_ENTRY(RECLS_RC_PATH_IS_NOT_DIRECTORY),
        RC_STR_ENTRY(RECLS_RC_NO_MORE_DATA),
        RC_STR_ENTRY(RECLS_RC_OUT_OF_MEMORY),
        RC_STR_ENTRY(RECLS_RC_NOT_IMPLEMENTED),
        RC_STR_ENTRY(RECLS_RC_INVALID_SEARCH_TYPE),
        RC_STR_ENTRY(RECLS_RC_INVALID_SEARCH_PROTOCOL),
        RC_STR_ENTRY(RECLS_RC_UNEXPECTED),
        RC_STR_ENTRY(RECLS_RC_DOT_RECURSIVE_SEARCH),
        RC_STR_ENTRY(RECLS_RC_SEARCH_CANCELLED),
        RC_STR_ENTRY(RECLS_RC_FTP_INIT_FAILED),
        RC_STR_ENTRY(RECLS_RC_FTP_CONNECTION_FAILED),
        RC_STR_ENTRY(RECLS_RC_CANNOT_STAT_ROOT),
        RC_STR_ENTRY(RECLS_RC_PATH_LIMIT_EXCEEDED),
        RC_STR_ENTRY(RECLS_RC_USER_CANCELLED_SEARCH),
        RC_STR_ENTRY(RECLS_RC_NO_HOME),
        RC_STR_ENTRY(RECLS_RC_INVALID_NAME),
        RC_STR_ENTRY(RECLS_RC_ACCESS_DENIED),
        RC_STR_ENTRY(RECLS_RC_DIRECTORY_NOT_FOUND),
        RC_STR_ENTRY(RECLS_RC_ENTRY_IS_DIRECTORY),
        RC_STR_ENTRY(RECLS_RC_ENTRY_IS_NOT_DIRECTORY),
#ifdef RECLS_PLATFORM_IS_WINDOWS
        RC_STR_ENTRY(RECLS_RC_SHORT_NAME_NOT_AVAILABLE),
#endif
        RC_STR_ENTRY(RECLS_RC_SEARCH_DIRECTORY_INVALID_CHARACTERS),
        RC_STR_ENTRY(RECLS_RC_ROOTED_PATHS_IN_PATTERNS),
    };
    int                         e_;     // Null object pattern
    size_t                      len_;   // Null object pattern

    if (ss_nullptr_k == e)
    {
        e = &e_;
    }

    if (ss_nullptr_k == len)
    {
        len = &len_;
    }

    for (size_t i = 0; i < stlsoft_num_elements_(entries); ++i)
    {
        if (entries[i]->rc == rc)
        {
            return (*len = entries[i]->len, *e = entries[i]->e, entries[i]->str);
        }
    }

    return (*len = 0, *e = EFAIL, RECLS_LITERAL(""));
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

using ::recls::impl::ReclsSearch;
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * error handling
 */

RECLS_API Recls_GetLastError(hrecls_t hSrch)
{
    function_scope_trace("Recls_GetLastError");

    ReclsSearch* const si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", ss_nullptr_k != si);

    return si->GetLastError();
}

RECLS_FNDECL(size_t)
Recls_GetErrorString(
    recls_rc_t      rc
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetErrorString");

    size_t              cchError;
    recls_char_t const* s = ::recls::impl::lookup_error_string_(rc, ss_nullptr_k, &cchError);

    if (ss_nullptr_k == buffer)
    {
        return cchError;
    }
    else
    {
        return ::recls::impl::recls_strncpy_(buffer, cchBuffer, s, cchError);
    }
}

RECLS_FNDECL(size_t)
Recls_GetLastErrorString(
    hrecls_t        hSrch
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetLastErrorString");

    return Recls_GetErrorString(Recls_GetLastError(hSrch), buffer, cchBuffer);
}

RECLS_FNDECL(recls_char_t const*)
Recls_GetSearchCodeString(recls_rc_t rc)
{
    function_scope_trace("Recls_GetLastErrorString");

    return impl::lookup_error_string_(rc, ss_nullptr_k, ss_nullptr_k);
}

RECLS_FNDECL(size_t)
Recls_GetSearchCodeStringLength(recls_rc_t rc)
{
    function_scope_trace("Recls_GetLastErrorString");

    size_t len;

    return (impl::lookup_error_string_(rc, ss_nullptr_k, &len), len);
}

RECLS_FNDECL(int)
Recls_GetErrno(recls_rc_t rc)
{
    function_scope_trace("Recls_GetErrno");

    int e = 0;

    return (impl::lookup_error_string_(rc, &e, ss_nullptr_k), e);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

