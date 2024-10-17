/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFtpSearch_windows.cpp
 *
 * Purpose: Implementation of the ReclsFtpSearch class for Windows.
 *
 * Created: 16th August 2003
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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
#include "impl.types.ftp.hpp"
#include "impl.util.h"

#include "ReclsSearch.hpp"
#include "ReclsFtpSearch.hpp"
#include "ReclsFtpSearchDirectoryNode_windows.hpp"

#include "impl.trace.h"

#include <exception>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * utility functions
 */

/* /////////////////////////////////////////////////////////////////////////
 * ReclsFtpSearch
 */

inline void* ReclsFtpSearch::operator new(size_t cb, size_t cDirParts, size_t cbRootDir)
{
    function_scope_trace("ReclsFtpSearch::operator new");

    cbRootDir = recls_align_up_size_(cbRootDir);

    RECLS_ASSERT(cb > STLSOFT_RAW_OFFSETOF(ReclsFtpSearch, data));

    cb = STLSOFT_RAW_OFFSETOF(ReclsFtpSearch, data)
       + (cDirParts) * sizeof(recls_strptrs_t)
       + cbRootDir;

    void* const pv = malloc(cb);

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
    if (ss_nullptr_k == pv)
    {
        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        throw std::bad_alloc();
    }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

    return pv;
}

#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
void ReclsFtpSearch::operator delete(void* pv, size_t /* cDirParts */, size_t /* cbRootDir */)
{
    function_scope_trace("ReclsFtpSearch::operator delete");

    free(pv);
}
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */

void ReclsFtpSearch::operator delete(void* pv)
{
    function_scope_trace("ReclsFtpSearch::operator delete");

    free(pv);
}

/* static */ recls_rc_t
ReclsFtpSearch::FindAndCreate(
    recls_char_t const* host
,   recls_char_t const* username
,   recls_char_t const* password
,   recls_char_t const* rootDir
,   size_t              rootDirLen
,   recls_char_t const* pattern
,   size_t              patternLen
,   recls_uint32_t      flags
,   ReclsFtpSearch**    ppsi
)
{
    function_scope_trace("ReclsFtpSearch::FindAndCreate");

    recls_debug2_trace_printf_(RECLS_LITERAL("host:    %s"), host);
    recls_debug2_trace_printf_(RECLS_LITERAL("rootDir: %s"), rootDir);
    recls_debug2_trace_printf_(RECLS_LITERAL("pattern: %s"), pattern);

    // The first thing to do is to open the session and connection

    RECLS_ASSERT(ss_nullptr_k != host);
    RECLS_ASSERT(ss_nullptr_k != rootDir);
    RECLS_ASSERT(ss_nullptr_k != pattern);
    RECLS_ASSERT(ss_nullptr_k != ppsi);

    *ppsi = ss_nullptr_k;

    recls_rc_t          rc;
    types::session_type session(RECLS_LITERAL("recls-enumerator"), INTERNET_OPEN_TYPE_DIRECT, ss_nullptr_k, ss_nullptr_k, 0);

    // The session and connection are done in an exception-free manner just to
    // avoid CRT linking issues. It's not the best way to write software in
    // general.

    if (!session)
    {
        recls_debug2_trace_printf_(RECLS_LITERAL("Failed to create sessions: %lu"), ::GetLastError());

        rc = RECLS_RC_FTP_INIT_FAILED;
    }
    else
    {
        DWORD   dwFlags =   0;

        if (flags & RECLS_F_PASSIVE_FTP)
        {
            dwFlags |= INTERNET_FLAG_PASSIVE;
        }

        types::connection_type connection(session, host, INTERNET_DEFAULT_FTP_PORT, username, password, INTERNET_SERVICE_FTP, dwFlags);

        if (!connection)
        {
            DWORD   dwErr = connection.last_error();

            recls_debug1_trace_printf_(RECLS_LITERAL("Failed to open connection: %lu"), dwErr);

            rc = RECLS_RC_FTP_CONNECTION_FAILED;
        }
        else
        {
            ReclsFtpSearch*     si;
            size_t              cchFullPath = types::traits_type::get_full_path_name(connection, rootDir, 0, ss_nullptr_k);
            types::buffer_type  fullPath(1 + cchFullPath + 1); // +1 (nul) +1 (dir-end)

            if (0 == cchFullPath)
            {
                recls_debug2_trace_printf_(RECLS_LITERAL("Invalid directory"));

                rc = RECLS_RC_INVALID_NAME;
            }
            else
            {
                types::traits_type::get_full_path_name(connection, rootDir, fullPath.size(), &fullPath[0]);

                types::traits_type::ensure_dir_end(&fullPath[0]);

                size_t lenSearchRoot = types::traits_type::str_len(&fullPath[0]);

                RECLS_ASSERT(0 < lenSearchRoot);

                rootDir = &fullPath[0];

                // Count the directory parts. This is always done for the ReclsFtpSearch class, since it
                // uses them to recurse.
                recls_char_t const*         begin       =   rootDir;
                recls_char_t const* const   end         =   rootDir + lenSearchRoot;
                size_t                      cDirParts   =   types::count_dir_parts(begin, end);

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
                try
                {
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */
                    si = new(cDirParts, sizeof(recls_char_t) * (1 + lenSearchRoot)) ReclsFtpSearch(session, connection, cDirParts, rootDir, rootDirLen, pattern, patternLen, flags);
#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
                }
                catch (std::bad_alloc&)
                {
                    recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

                    si = ss_nullptr_k;
                }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

                if (ss_nullptr_k == si)
                {
                    rc = RECLS_RC_FAIL;
                }
                else
                {
                    connection.detach();
                    session.detach();

                    // This is a nasty hack. It's tantamount to ctor & create function, so
                    // should be made more elegant soon.
                    if (ss_nullptr_k == si->m_dnode)
                    {
                        delete si;

//                      si = ss_nullptr_k;

                        recls_debug2_trace_printf_(RECLS_LITERAL("No more data"));

                        rc = RECLS_RC_NO_MORE_DATA;
                    }
                    else
                    {
                        *ppsi = si;

                        rc = RECLS_RC_OK;
                    }
                }
            }
        }
    }

    return rc;
}

recls_char_t const*
ReclsFtpSearch::calc_rootDir_(
    size_t              cDirParts
,   recls_char_t const* rootDir
,   size_t              rootDirLen
)
{
    function_scope_trace("ReclsFtpSearch::calc_rootDir_");

    // Root dir is located after file parts, and before pattern
    recls_char_t* s = ::stlsoft::sap_cast<recls_char_t*>(&data[cDirParts * sizeof(recls_strptrs_t)]);

    types::traits_type::char_copy(s, rootDir, rootDirLen);
    s[rootDirLen] = '\0';

    return s;
}

ReclsFtpSearch::ReclsFtpSearch(
        HINTERNET           hSess
    ,   HINTERNET           hConn
    ,   size_t              cDirParts
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_char_t const* pattern
    ,   size_t              patternLen
    ,   recls_uint32_t      flags
)
    : m_session(hSess)
    , m_connection(hConn)
    , m_flags(flags)
    , m_rootDir(calc_rootDir_(cDirParts, rootDir, rootDirLen))
{
    function_scope_trace("ReclsFtpSearch::ReclsFtpSearch");

    RECLS_ASSERT(ss_nullptr_k != hSess);
    RECLS_ASSERT(ss_nullptr_k != hConn);
    RECLS_ASSERT(ss_nullptr_k != rootDir);
    RECLS_ASSERT(ss_nullptr_k != pattern);

    // Initialise the directory parts.

    RECLS_MESSAGE_ASSERT("FTP filesystems do not allow drive specifications", rootDir[1] != ':');

    m_dnode = ReclsFtpSearchDirectoryNode::FindAndCreate(
        m_connection
    ,   m_flags
    ,   rootDir
    ,   rootDirLen
    ,   pattern
    ,   patternLen
    );
}

ReclsFtpSearch::~ReclsFtpSearch()
{
    if (ss_nullptr_k != m_connection)
    {
        ::InternetCloseHandle(m_connection);
    }
    if (ss_nullptr_k != m_session)
    {
        ::InternetCloseHandle(m_session);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

