/* /////////////////////////////////////////////////////////////////////////
 * File:        api.search.cpp
 *
 * Purpose:     Main (platform-independent) implementation file for the recls API.
 *
 * Created:     16th August 2003
 * Updated:     2nd January 2021
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.api.search.h"
#include "impl.constants.hpp"
#include "impl.entryfunctions.h"
#include "impl.string.hpp"
#include "impl.types.hpp"
#include "impl.util.h"

#include "ReclsSearch.hpp"

#include "impl.trace.h"

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
 * typedefs
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */

using ::recls::impl::Recls_SearchFeedback_;
using ::recls::impl::Recls_SearchProcessFeedback_;

using ::recls::impl::ReclsSearch;
using ::recls::impl::constants;
using ::recls::impl::types;

using ::recls::impl::Entry_BlockCount;
using ::recls::impl::Entry_Copy;
using ::recls::impl::Entry_Release;

using ::recls::impl::recls_debug0_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * API functions
 */

RECLS_API Recls_Search(
    recls_char_t const* searchRoot
,   recls_char_t const* pattern
,   recls_uint32_t      flags
,   hrecls_t*           phSrch
)
{
    function_scope_trace("Recls_Search");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_Search(%s, %s, %08x, ...)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(pattern)
    ,   flags
    );

    return Recls_SearchFeedback_(
        "Recls_Search"
    ,   searchRoot
    ,   pattern
    ,   flags
    ,   ss_nullptr_k
    ,   ss_nullptr_k
    ,   phSrch
    );
}

RECLS_API Recls_SearchFeedback(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   hrecls_t*                   phSrch
)
{
    function_scope_trace("Recls_SearchFeedback");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SearchFeedback(%s, %s, 0x%04x, ..., %p, ...)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(pattern)
    ,   flags
    ,   param
    );

    return Recls_SearchFeedback_(
        "Recls_SearchFeedback"
    ,   searchRoot
    ,   pattern
    ,   flags
    ,   pfn
    ,   param
    ,   phSrch
    );
}

/** Closes the given search */
RECLS_FNDECL(void) Recls_SearchClose(hrecls_t hSrch)
{
    function_scope_trace("Recls_SearchClose");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SearchClose(%p)"), hSrch);

    ReclsSearch* const si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", ss_nullptr_k != si);

    delete si;
}

/* /////////////////////////////////////////////////////////////////////////
 * search enumeration
 */

RECLS_API Recls_SearchProcessFeedback(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_process_fn_t         pfn
,   recls_process_fn_param_t    param
,   hrecls_progress_fn_t        pfnProgress
,   recls_process_fn_param_t    paramProgress
)
{
    function_scope_trace("Recls_SearchProcessFeedback");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SearchProcessFeedback(%s, %s, 0x%04x, ..., %p, ..., %p)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(pattern)
    ,   flags
    ,   param
    ,   paramProgress
    );

    return Recls_SearchProcessFeedback_(
        "Recls_SearchProcessFeedback"
    ,   searchRoot
    ,   pattern
    ,   flags
    ,   pfn
    ,   param
    ,   pfnProgress
    ,   paramProgress
    );
}

RECLS_API Recls_SearchProcess(
    recls_char_t const*         searchRoot
,   recls_char_t const*         pattern
,   recls_uint32_t              flags
,   hrecls_process_fn_t         pfn
,   recls_process_fn_param_t    param
)
{
    function_scope_trace("Recls_SearchProcess");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SearchProcess(%s, %s, 0x%04x, ..., %p)")
    ,   stlsoft::c_str_ptr(searchRoot)
    ,   stlsoft::c_str_ptr(pattern)
    ,   flags
    ,   param
    );

    return Recls_SearchProcessFeedback_(
        "Recls_SearchProcess"
    ,   searchRoot
    ,   pattern
    ,   flags
    ,   pfn
    ,   param
    ,   ss_nullptr_k
    ,   ss_nullptr_k
    );
}

RECLS_API Recls_GetNext(hrecls_t hSrch)
{
    function_scope_trace("Recls_GetNext");

    ReclsSearch* const si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", ss_nullptr_k != si);

    return si->GetNext();
}

RECLS_API Recls_GetDetails(
    hrecls_t        hSrch
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_GetDetails");

    ReclsSearch* const si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", ss_nullptr_k != si);
    RECLS_ASSERT(ss_nullptr_k != pinfo);

    return si->GetDetails(pinfo);
}

RECLS_API Recls_GetNextDetails(
    hrecls_t        hSrch
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_GetNextDetails");

    ReclsSearch* const si = ReclsSearch::FromHandle(hSrch);

    RECLS_MESSAGE_ASSERT("Search handle is null!", ss_nullptr_k != si);

    return si->GetNextDetails(pinfo);
}

/***************************************
 * File entry info structure
 */

RECLS_FNDECL(void) Recls_CloseDetails(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_CloseDetails");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    Entry_Release(fileInfo);
}

RECLS_API Recls_CopyDetails(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
)
{
    function_scope_trace("Recls_CopyDetails");

    RECLS_ASSERT(ss_nullptr_k != pinfo);

    return Entry_Copy(fileInfo, pinfo);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

