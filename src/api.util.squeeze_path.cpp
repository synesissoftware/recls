/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.squeeze_path.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     7th October 2015
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2015, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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
 * Includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.cover.h"

#include "impl.trace.h"

#include <platformstl/filesystem/path_functions.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::types;

using ::recls::impl::recls_is_home_start_;
using ::recls::impl::recls_get_home_;
using ::recls::impl::recls_log_printf_;
using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_warning_trace_printf_;
using ::recls::impl::recls_info_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util")
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util.squeeze_path")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * Extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
static size_t Recls_SqueezePath_X_(
    recls_char_t const* path
,   recls_char_t*       result
,   size_t              cchResult
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */


RECLS_FNDECL(size_t) Recls_SqueezePath(
    recls_char_t const* path
,   recls_char_t*       result
,   size_t              cchResult
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{
    try
    {
        return Recls_SqueezePath_X_(path, result, cchResult);
    }
    catch(std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_SqueezePath(%s, ..., ...): %s"), path, x.what());

        RECLS_COVER_MARK_LINE();

        return 0;
    }
}

static size_t Recls_SqueezePath_X_(
    recls_char_t const* path
,   recls_char_t*       result
,   size_t              cchResult
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_SqueezePath");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_SqueezePath(%s, ..., %u)"), stlsoft::c_str_ptr(path), unsigned(cchResult));

    RECLS_COVER_MARK_LINE();

    if(NULL == result)
    {
        RECLS_COVER_MARK_LINE();

        size_t n = platformstl::path_squeeze(path, result, cchResult);

        if(0 != n)
        {
            RECLS_COVER_MARK_LINE();

            --n;
        }

        return n;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        stlsoft::auto_buffer<recls_char_t, 512> buffer(1 + cchResult);
        size_t                                  n = platformstl::path_squeeze(path, &buffer[0], buffer.size());

        if(0 != n)
        {
            RECLS_ASSERT(n <= cchResult + 1);

            RECLS_COVER_MARK_LINE();

            types::traits_type::char_copy(result, buffer.data(), n);

            --n;
        }

        return n;
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * Coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
