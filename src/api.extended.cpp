/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.extended.cpp
 *
 * Purpose: recls API extended functions.
 *
 * Created: 16th August 2003
 * Updated: 20th February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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

using ::recls::impl::recls_debug0_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#if defined(RECLS_PLATFORM_IS_UNIX)
# define RAPI_PATHNAMESEP                                   '/'
# define RAPI_PATHSEP                                       ':'
# define RAPI_WILDCARDSALL                                  '*'
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# define RAPI_PATHNAMESEP                                   '\\'
# define RAPI_PATHSEP                                       ';'
# define RAPI_WILDCARDSALL                                  '*', '.', '*'
#else /* unrecognised platform */
# error platform is not recognised
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

RECLS_LINKAGE_C recls_char_t const* Recls_GetPathNameSeparator()
{
    function_scope_trace("Recls_GetPathNameSeparator");

    static recls_char_t const   s_pathNameSeparator[] = { RAPI_PATHNAMESEP, '\0' };

    return s_pathNameSeparator;
}

RECLS_LINKAGE_C recls_char_t const* Recls_GetPathSeparator()
{
    function_scope_trace("Recls_GetPathSeparator");

    static recls_char_t const   s_pathSeparator[] = { RAPI_PATHSEP, '\0' };

    return s_pathSeparator;
}

RECLS_LINKAGE_C recls_char_t const* Recls_GetWildcardsAll()
{
    function_scope_trace("Recls_GetWildcardsAll");

    static recls_char_t const   s_wildcardsAll[] = { RAPI_WILDCARDSALL, '\0' };

    return s_wildcardsAll;
}

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

static
int
RECLS_CALLCONV_DEFAULT IsDirectoryEmpty_proc(
    recls_entry_t            /* info */
,   recls_process_fn_param_t /* param */
)
{
    return 0; // Cancel on any entry
}

RECLS_FNDECL(recls_bool_t)
Recls_IsDirectoryEmpty(recls_char_t const* dir)
{
    function_scope_trace("Recls_IsDirectoryEmpty");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_IsDirectoryEmpty(%s)"), stlsoft::c_str_ptr(dir));

    recls_rc_t rc = Recls_SearchProcess(dir, Recls_GetWildcardsAll(), RECLS_F_TYPEMASK, IsDirectoryEmpty_proc, 0);

    return RECLS_RC_SEARCH_CANCELLED != rc;
}

RECLS_FNDECL(recls_bool_t)
Recls_IsDirectoryEntryEmpty(recls_entry_t hEntry)
{
    function_scope_trace("Recls_IsDirectoryEntryEmpty");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_IsDirectoryEntryEmpty(%p)"), hEntry);

    RECLS_ASSERT(ss_nullptr_k != hEntry);
    RECLS_ASSERT(Recls_IsEntryDirectory(hEntry));

    return Recls_IsDirectoryEmpty(hEntry->path.begin);
}

static
int
RECLS_CALLCONV_DEFAULT CalcDirectorySize_proc(
    recls_entry_t               hEntry
,   recls_process_fn_param_t    param
)
{
    recls_filesize_t&   total   =   *static_cast<recls_filesize_t*>(param);
    recls_filesize_t    size    =   Recls_GetSizeProperty(hEntry);

    total = total + size;

    return 1; // Never cancel
}

RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectorySize(recls_char_t const* dir)
{
    function_scope_trace("Recls_CalcDirectorySize");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectorySize(%s)"), stlsoft::c_str_ptr(dir));

    static recls_filesize_t zero;
    recls_filesize_t        total = zero;

    Recls_SearchProcess(dir, Recls_GetWildcardsAll(), RECLS_F_FILES | RECLS_F_RECURSIVE, CalcDirectorySize_proc, static_cast<recls_process_fn_param_t>(&total));

    return total;
}

RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectoryEntrySize(recls_entry_t hEntry)
{
    function_scope_trace("Recls_CalcDirectoryEntrySize");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectoryEntrySize(%p)"), hEntry);

    RECLS_ASSERT(ss_nullptr_k != hEntry);
    RECLS_ASSERT(Recls_IsEntryDirectory(hEntry));

    return Recls_CalcDirectorySize(hEntry->path.begin);
}

RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectorySizeFeedback(
    recls_char_t const*         dir
,   recls_uint32_t              flags
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
)
{
    function_scope_trace("Recls_CalcDirectorySizeFeedback");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CalcDirectorySizeFeedback(%s, %08x, ..., %p)"), stlsoft::c_str_ptr(dir), flags, param);

    static recls_filesize_t zero;
    recls_filesize_t        total = zero;

    flags   &=  ~(RECLS_F_DIRECTORIES);
    flags   |=  RECLS_F_FILES;
    flags   |=  RECLS_F_RECURSIVE;

    Recls_SearchProcessFeedback(dir, Recls_GetWildcardsAll(), flags, CalcDirectorySize_proc, static_cast<recls_process_fn_param_t>(&total), pfn, param);

    return total;
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

