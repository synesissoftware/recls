/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.combine_paths.cpp
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
    catch (std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_CombinePaths(): %s"), x.what());

        return 0u;
    }
    catch (...)
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

