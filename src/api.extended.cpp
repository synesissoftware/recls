/* /////////////////////////////////////////////////////////////////////////
 * File:        api.extended.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     2nd April 2010
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2010, Matthew Wilson and Synesis Software
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
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * Constants
 */

#if defined(RECLS_PLATFORM_IS_UNIX)
# define RAPI_PATHNAMESEP           '/'
# define RAPI_PATHSEP               ':'
# define RAPI_WILDCARDSALL          '*'
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# define RAPI_PATHNAMESEP           '\\'
# define RAPI_PATHSEP               ';'
# define RAPI_WILDCARDSALL          '*', '.', '*'
#else /* unrecognised platform */
# error platform is not recognised
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * Extended API functions
 */

RECLS_LINKAGE_C recls_char_t const* Recls_GetPathNameSeparator()
{
    function_scope_trace("Recls_GetPathNameSeparator");

    RECLS_COVER_MARK_LINE();

    static recls_char_t const   s_pathNameSeparator[] = { RAPI_PATHNAMESEP, '\0' };

    return s_pathNameSeparator;
}

RECLS_LINKAGE_C recls_char_t const* Recls_GetPathSeparator()
{
    function_scope_trace("Recls_GetPathSeparator");

    RECLS_COVER_MARK_LINE();

    static recls_char_t const   s_pathSeparator[] = { RAPI_PATHSEP, '\0' };

    return s_pathSeparator;
}

RECLS_LINKAGE_C recls_char_t const* Recls_GetWildcardsAll()
{
    function_scope_trace("Recls_GetWildcardsAll");

    RECLS_COVER_MARK_LINE();

    static recls_char_t const   s_wildcardsAll[] = { RAPI_WILDCARDSALL, '\0' };

    return s_wildcardsAll;
}

/* /////////////////////////////////////////////////////////////////////////
 * Extended API functions
 */

static int RECLS_CALLCONV_DEFAULT IsDirectoryEmpty_proc(recls_entry_t /* info */, recls_process_fn_param_t /* param */)
{
    RECLS_COVER_MARK_LINE();

    return 0; // Cancel on any entry
}

RECLS_FNDECL(recls_bool_t) Recls_IsDirectoryEmpty(recls_char_t const* dir)
{
    function_scope_trace("Recls_IsDirectoryEmpty");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_IsDirectoryEmpty(%s)"), stlsoft::c_str_ptr(dir));

    RECLS_COVER_MARK_LINE();

    recls_rc_t rc = Recls_SearchProcess(dir, Recls_GetWildcardsAll(), RECLS_F_TYPEMASK, IsDirectoryEmpty_proc, 0);

    return RECLS_RC_SEARCH_CANCELLED != rc;
}

RECLS_FNDECL(recls_bool_t) Recls_IsDirectoryEntryEmpty(recls_entry_t hEntry)
{
    function_scope_trace("Recls_IsDirectoryEntryEmpty");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_IsDirectoryEntryEmpty(%p)"), hEntry);

    RECLS_ASSERT(NULL != hEntry);
    RECLS_ASSERT(Recls_IsFileDirectory(hEntry));

    RECLS_COVER_MARK_LINE();

    return Recls_IsDirectoryEmpty(hEntry->path.begin);
}

static int RECLS_CALLCONV_DEFAULT CalcDirectorySize_proc(recls_entry_t hEntry, recls_process_fn_param_t param)
{
    RECLS_COVER_MARK_LINE();

    recls_filesize_t&   total   =   *static_cast<recls_filesize_t*>(param);
    recls_filesize_t    size    =   Recls_GetSizeProperty(hEntry);

    total = total + size;

    return 1; // Never cancel
}

RECLS_FNDECL(recls_filesize_t) Recls_CalcDirectorySize(recls_char_t const* dir)
{
    function_scope_trace("Recls_CalcDirectorySize");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectorySize(%s)"), stlsoft::c_str_ptr(dir));

    RECLS_COVER_MARK_LINE();

    static recls_filesize_t zero;
    recls_filesize_t        total = zero;

    Recls_SearchProcess(dir, Recls_GetWildcardsAll(), RECLS_F_FILES | RECLS_F_RECURSIVE, CalcDirectorySize_proc, static_cast<recls_process_fn_param_t>(&total));

    return total;
}

RECLS_FNDECL(recls_filesize_t) Recls_CalcDirectoryEntrySize(recls_entry_t hEntry)
{
    function_scope_trace("Recls_CalcDirectoryEntrySize");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectoryEntrySize(%p)"), hEntry);

    RECLS_COVER_MARK_LINE();

    RECLS_ASSERT(NULL != hEntry);
    RECLS_ASSERT(Recls_IsFileDirectory(hEntry));

    return Recls_CalcDirectorySize(hEntry->path.begin);
}

RECLS_FNDECL(recls_filesize_t) Recls_CalcDirectorySizeFeedback(
    recls_char_t const*         dir
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
)
{
    function_scope_trace("Recls_CalcDirectorySizeFeedback");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectorySizeFeedback(%s, %08x, ..., %p)"), stlsoft::c_str_ptr(dir), flags, param);

    RECLS_COVER_MARK_LINE();

    static recls_filesize_t zero;
    recls_filesize_t        total = zero;

    flags   &=  ~(RECLS_F_DIRECTORIES);
    flags   |=  RECLS_F_FILES;
    flags   |=  RECLS_F_RECURSIVE;

    Recls_SearchProcessFeedback(dir, Recls_GetWildcardsAll(), flags, CalcDirectorySize_proc, static_cast<recls_process_fn_param_t>(&total), pfn, param);

    return total;
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
