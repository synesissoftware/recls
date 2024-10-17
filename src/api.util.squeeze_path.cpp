/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.squeeze_path.cpp
 *
 * Purpose: recls API extended functions.
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
#include "impl.types.hpp"
#include "impl.util.h"

#include "impl.trace.h"

#include <platformstl/filesystem/path_functions.hpp>

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
Recls_SqueezePath_X_(
    recls_char_t const* path
,   recls_char_t        result[]
,   size_t              cchResult
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */


RECLS_FNDECL(size_t)
Recls_SqueezePath(
    recls_char_t const* path
,   recls_char_t        result[]
,   size_t              cchResult
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{
    try
    {
        return Recls_SqueezePath_X_(path, result, cchResult);
    }
    catch (std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_SqueezePath(%s, ..., ...): %s"), path, x.what());

        return 0;
    }
}

static
size_t
Recls_SqueezePath_X_(
    recls_char_t const* path
,   recls_char_t        result[]
,   size_t              cchResult
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_SqueezePath");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_SqueezePath(%s, ..., cchResult=%lu)")
    ,   stlsoft::c_str_ptr(path)
    ,   static_cast<unsigned long>(cchResult)
    );

    if (ss_nullptr_k == result)
    {
        size_t n = platformstl::path_squeeze(path, result, cchResult);

        if (0 != n)
        {
            --n;
        }

        return n;
    }
    else
    {
        stlsoft::auto_buffer<recls_char_t, 512> buffer(1 + cchResult);
        size_t                                  n = platformstl::path_squeeze(path, &buffer[0], buffer.size());

        if (0 != n)
        {
            RECLS_ASSERT(n <= cchResult + 1);

            types::traits_type::char_copy(result, buffer.data(), n);

            --n;
        }

        return n;
    }
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

