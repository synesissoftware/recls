/* /////////////////////////////////////////////////////////////////////////
 * File:        src/ReclsSearch.cpp
 *
 * Purpose:     Implementation of the ReclsFileSearch class for Windows.
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

#include "impl.trace.h"

#include "ReclsSearch.hpp"

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
 * ReclsSearch
 */

ReclsSearch::ReclsSearch()
    : m_dnode(ss_nullptr_k)
    , m_lastError(RECLS_RC_OK)
{}

ReclsSearch::~ReclsSearch()
{
    delete m_dnode;
}

/* static */ hrecls_t ReclsSearch::ToHandle(ReclsSearch* si)
{
    return hrecls_t(si);
}

/* static */ ReclsSearch* ReclsSearch::FromHandle(hrecls_t h)
{
    return static_cast<ReclsSearch*>(const_cast<void*>(static_cast<void const*>(h)));
}

// Operations

recls_rc_t ReclsSearch::GetNext()
{
    function_scope_trace("ReclsSearch::GetNext");

    RECLS_ASSERT(ss_nullptr_k != m_dnode);

    m_lastError = m_dnode->GetNext();

    if (RECLS_RC_NO_MORE_DATA == m_lastError)
    {
        delete m_dnode;

        m_dnode = ss_nullptr_k;
    }

    return m_lastError;
}

recls_rc_t ReclsSearch::GetDetails(recls_entry_t* pinfo)
{
    function_scope_trace("ReclsSearch::GetDetails");

    RECLS_ASSERT(ss_nullptr_k != m_dnode);

    return (m_lastError = m_dnode->GetDetails(pinfo));
}

recls_rc_t ReclsSearch::GetNextDetails(recls_entry_t* pinfo)
{
    function_scope_trace("ReclsSearch::GetNextDetails");

    RECLS_ASSERT(ss_nullptr_k != m_dnode);

    m_lastError = m_dnode->GetNextDetails(pinfo);

    if (RECLS_RC_NO_MORE_DATA == m_lastError)
    {
        delete m_dnode;

        m_dnode = ss_nullptr_k;
    }

    return m_lastError;
}

// Accessors

recls_rc_t ReclsSearch::GetLastError() const
{
    function_scope_trace("ReclsSearch::GetLastError");

    return m_lastError;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

