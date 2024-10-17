/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.stat.cpp
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

#include "ReclsFileSearchDirectoryNode.hpp"

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::ReclsFileSearchDirectoryNode;
using ::recls::impl::types;

using ::recls::impl::recls_is_home_start_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_debug2_trace_printf_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
recls_rc_t Recls_Stat_X_(
    recls_char_t const* path
,   recls_uint32_t      flags
,   recls_entry_t*      phEntry
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

RECLS_API Recls_Stat(
    recls_char_t const* path
,   recls_uint32_t      flags
,   recls_entry_t*      phEntry
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{
    try
    {
        return Recls_Stat_X_(path, flags, phEntry);
    }
    catch (std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("exception in Recls_Stat(): %s"), x.what());

        return RECLS_RC_FAIL;
    }
    catch (...)
    {
        recls_error_trace_printf_(RECLS_LITERAL("unknown exception in Recls_Stat()"));

        return RECLS_RC_UNEXPECTED;
    }
}

recls_rc_t Recls_Stat_X_(
    recls_char_t const* path
,   recls_uint32_t      flags
,   recls_entry_t*      phEntry
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_Stat");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_Stat(%s, %08x, ...)")
    ,   stlsoft::c_str_ptr(path)
    ,   int(flags)
    );

    RECLS_ASSERT(ss_nullptr_k != path);
    RECLS_ASSERT(ss_nullptr_k != phEntry);

    *phEntry = static_cast<recls_entry_t>(0);

    types::buffer_type  home(1);
    size_t              pathLen = types::traits_type::str_len(path);

    if (recls_is_home_start_(path, pathLen))
    {
        size_t const homeLen = types::traits_type::get_home_directory(home);

        if (0 == homeLen)
        {
#ifdef RECLS_STLSOFT_1_12_OR_LATER
            types::traits_type::error_type const e = types::traits_type::get_last_error();

            if (types::traits_type::is_memory_error_code(e))
            {
                return RECLS_RC_OUT_OF_MEMORY;
            }
            else
#endif
            {
                return RECLS_RC_NO_HOME;
            }
        }
        else
        {
            size_t const lenRequired = homeLen + (pathLen - 1);

            if (!home.resize(lenRequired + 1))
            {
                return RECLS_RC_OUT_OF_MEMORY;
            }
            else
            {
                types::traits_type::char_copy(home.data() + homeLen, path + 1, (pathLen - 1) + 1);

                path    =   home.data();
                pathLen =   lenRequired;
            }
        }
    }

    RECLS_ASSERT(pathLen == types::traits_type::str_len(path));

    if (0 == pathLen)
    {
        return RECLS_RC_INVALID_NAME;
    }

    types::path_type   path_(path, pathLen);

    if (!path_.exists() &&
        RECLS_F_DETAILS_LATER == (flags & RECLS_F_DETAILS_LATER) &&
        0 != (flags & RECLS_F_TYPEMASK)) // To allow non-existant things to be stat'd
    {
        path_.make_absolute();  // Need this, or get RECLS_RC_DIRECTORY_NOT_FOUND on a non-existant relative path

        types::path_type::string_slice_type const   file    =   path_.get_file();
        types::path_type                            path2_(path_.c_str(), path_.size() - file.len);

        if (!path2_.exists())
        {
            return RECLS_RC_DIRECTORY_NOT_FOUND;
        }

        return RECLS_RC_NO_MORE_DATA;
    }
    else
    {
        if (types::traits_type::is_directory(path_.c_str()))
        {
            if (RECLS_F_FILES == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
            {
                return RECLS_RC_ENTRY_IS_DIRECTORY;
            }
        }
        else
        {
            if (RECLS_F_DIRECTORIES == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
            {
                return RECLS_RC_ENTRY_IS_NOT_DIRECTORY;
            }
        }

        path_.make_absolute(false);

#ifdef RECLS_EXCEPTION_SUPPORT_
        path_.canonicalise(false);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

        return ReclsFileSearchDirectoryNode::Stat(
            path_.c_str(), path_.size()
        ,   flags
        ,   phEntry
        );
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

