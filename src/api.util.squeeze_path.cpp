/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.squeeze_path.cpp
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

#include <platformstl/filesystem/path_functions.hpp>

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
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util.squeeze_path")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
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

    if (NULL == result)
    {
        RECLS_COVER_MARK_LINE();

        size_t n = platformstl::path_squeeze(path, result, cchResult);

        if (0 != n)
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

        if (0 != n)
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

