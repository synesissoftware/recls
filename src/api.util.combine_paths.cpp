/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.combine_paths.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     30th December 2023
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
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.cover.h"

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util")
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util.combine_paths")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
static size_t Recls_CombinePaths_X_(
    recls_char_t const* path1
,   recls_char_t const* path2
,   recls_char_t*       result
,   size_t              cchResult
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

RECLS_FNDECL(size_t) Recls_CombinePaths(
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

        RECLS_COVER_MARK_LINE();

        return 0u;
    }
    catch(...)
    {
        recls_log_printf_(RECLS_SEVIX_ERROR, RECLS_LITERAL("unknown exception in Recls_CombinePaths()"));

        RECLS_COVER_MARK_LINE();

        return 0u;
    }
}

static size_t Recls_CombinePaths_X_(
    recls_char_t const* path1
,   recls_char_t const* path2
,   recls_char_t*       result
,   size_t              cchResult
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_CombinePaths");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CombinePaths(%s, %s, ..., %u)"), stlsoft::c_str_ptr(path1), stlsoft::c_str_ptr(path2), unsigned(cchResult));

    RECLS_ASSERT(NULL != path1 || NULL != path2);

    RECLS_COVER_MARK_LINE();

    platformstl::basic_path<recls_char_t>   path((NULL != path1) ? path1 : path2);

    if (NULL != path1 &&
        NULL != path2)
    {
        RECLS_COVER_MARK_LINE();

        path /= path2;
    }

    size_t  n = path.copy(result, cchResult);

    recls_debug2_trace_printf_(RECLS_LITERAL("Recls_CombinePaths(): result: %u, %.*s")
                    ,   unsigned(n)
                    ,   int(path.size())
                    ,   path.c_str());

    RECLS_COVER_MARK_LINE();

    return n;
}

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

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

