/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.combine_paths.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     26th March 2021
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
#include "impl.root.h"
#include "impl.types.hpp"
#include "impl.util.h"

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::types;

using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
static
size_t
Recls_CombinePaths_X_(
    recls_char_t const* path1
,   recls_char_t const* path2
,   recls_char_t*       result
,   size_t              cchResult
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

RECLS_FNDECL(size_t)
Recls_CombinePaths(
    recls_char_t const* path1
,   recls_char_t const* path2
,   recls_char_t*       result
,   size_t              cchResult
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{
    try
    {
        return Recls_CombinePaths_X_(path1, path2, result, cchResult);
    }
    catch(std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_CombinePaths(): %s"), x.what());

        return 0u;
    }
    catch(...)
    {
        recls_error_trace_printf_(RECLS_LITERAL("unknown exception in Recls_CombinePaths()"));

        return 0u;
    }
}

static
size_t
Recls_CombinePaths_X_(
    recls_char_t const* path1
,   recls_char_t const* path2
,   recls_char_t*       result
,   size_t              cchResult
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_CombinePaths");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_CombinePaths(%s, %s, ..., %u)")
    ,   stlsoft::c_str_ptr(path1)
    ,   stlsoft::c_str_ptr(path2)
    ,   unsigned(cchResult)
    );

    RECLS_ASSERT(ss_nullptr_k != path1 || ss_nullptr_k != path2);

    platformstl::basic_path<recls_char_t>   path((ss_nullptr_k != path1) ? path1 : path2);

    if (ss_nullptr_k != path1 &&
        ss_nullptr_k != path2)
    {
        path /= path2;
    }

    size_t const n = path.copy(result, cchResult);

    recls_debug2_trace_printf_(
        RECLS_LITERAL("Recls_CombinePaths(): result: %u, %.*s")
    ,   unsigned(n)
    ,   int(path.size())
    ,   path.data()
    );

    return n;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

