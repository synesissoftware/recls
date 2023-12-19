/* /////////////////////////////////////////////////////////////////////////
 * File:        api.error.cpp
 *
 * Purpose:     Main (platform-independent) implementation file for the recls API.
 *
 * Created:     16th August 2003
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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
#include "impl.cover.h"

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
# define EZERO              (0)
#endif

#ifndef EFAIL
# define EFAIL              (stlsoft_static_cast(int, stlsoft_static_cast(unsigned int, 0x01) << ((sizeof(int) * 8) - 1)))
#endif

#ifndef ENOSYS
# define ENOSYS             (EFAIL)
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

static recls_char_t const* lookup_error_string_(
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
    };
    int                         e_;     // Null object pattern
    size_t                      len_;   // Null object pattern

    if(NULL == e)
    {
        RECLS_COVER_MARK_LINE();

        e = &e_;
    }

    if(NULL == len)
    {
        RECLS_COVER_MARK_LINE();

        len = &len_;
    }

    for(size_t i = 0; i < stlsoft_num_elements_(entries); ++i)
    {
        RECLS_COVER_MARK_LINE();

        if(entries[i]->rc == rc)
        {
            RECLS_COVER_MARK_LINE();

            return (*len = entries[i]->len, *e = entries[i]->e, entries[i]->str);
        }
    }

    RECLS_COVER_MARK_LINE();

    return (*len = 0, *e = EFAIL, RECLS_LITERAL(""));
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.core.error")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * error handling
 */

RECLS_API Recls_GetLastError(hrecls_t hSrch)
{
    function_scope_trace("Recls_GetLastError");

    ::recls::impl::ReclsSearch* si = ::recls::impl::ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", NULL != si);

    RECLS_COVER_MARK_LINE();

    return si->GetLastError();
}

RECLS_FNDECL(size_t) Recls_GetErrorString(  recls_rc_t      rc
                                        ,   recls_char_t*   buffer
                                        ,   size_t          cchBuffer)
{
    function_scope_trace("Recls_GetErrorString");

    RECLS_COVER_MARK_LINE();

    size_t              cchError;
    recls_char_t const* s = ::recls::impl::lookup_error_string_(rc, NULL, &cchError);

    if(NULL == buffer)
    {
        RECLS_COVER_MARK_LINE();

        return cchError;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        return ::recls::impl::recls_strncpy_(buffer, cchBuffer, s, cchError);
    }
}

RECLS_FNDECL(size_t) Recls_GetLastErrorString(  hrecls_t        hSrch
                                            ,   recls_char_t*   buffer
                                            ,   size_t          cchBuffer)
{
    function_scope_trace("Recls_GetLastErrorString");

    RECLS_COVER_MARK_LINE();

    return Recls_GetErrorString(Recls_GetLastError(hSrch), buffer, cchBuffer);
}

RECLS_FNDECL(recls_char_t const*) Recls_GetSearchCodeString(recls_rc_t rc)
{
    function_scope_trace("Recls_GetLastErrorString");

    RECLS_COVER_MARK_LINE();

    return impl::lookup_error_string_(rc, NULL, NULL);
}

RECLS_FNDECL(size_t) Recls_GetSearchCodeStringLength(recls_rc_t rc)
{
    function_scope_trace("Recls_GetLastErrorString");

    RECLS_COVER_MARK_LINE();

    size_t len;

    return (impl::lookup_error_string_(rc, NULL, &len), len);
}

RECLS_FNDECL(int) Recls_GetErrno(
    /* [in] */ recls_rc_t rc
)
{
    function_scope_trace("Recls_GetErrno");

    RECLS_COVER_MARK_LINE();

    int e = 0;

    return (impl::lookup_error_string_(rc, &e, NULL), e);
}

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

