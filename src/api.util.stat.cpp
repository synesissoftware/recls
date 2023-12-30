/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.stat.cpp
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

#include "ReclsSearch.hpp"
#include "ReclsFileSearch.hpp"

#include "impl.trace.h"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::ReclsFileSearch;
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
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.util.stat")
RECLS_MARK_FILE_START()

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
    catch(std::exception &x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("exception in Recls_Stat(): %s"), x.what());

        RECLS_COVER_MARK_LINE();

        return RECLS_RC_FAIL;
    }
    catch(...)
    {
        recls_log_printf_(RECLS_SEVIX_ERROR, RECLS_LITERAL("unknown exception in Recls_Stat()"));

        RECLS_COVER_MARK_LINE();

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

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_Stat(%s, %08x, ...)"), path, flags);

    RECLS_ASSERT(NULL != path);
    RECLS_ASSERT(NULL != phEntry);

    RECLS_COVER_MARK_LINE();

    *phEntry = static_cast<recls_entry_t>(0);

    RECLS_COVER_MARK_LINE();

    types::file_path_buffer_type    home;
    size_t                          pathLen = types::traits_type::str_len(path);

    if (NULL != path &&
        recls_is_home_start_(path))
    {
        RECLS_COVER_MARK_LINE();

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{2}: %s"), path);

        size_t n = recls_get_home_(&home[0], home.size());

        if (0 == n)
        {
            RECLS_COVER_MARK_LINE();

            //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{3}: %s"), path);

            return RECLS_RC_NO_HOME;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            RECLS_ASSERT(n == types::traits_type::str_len(home.c_str()));

            // recls_get_home_() always has a trailing path-name separator
            RECLS_ASSERT(types::traits_type::has_dir_end(&home[0]));

            //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{4}: %s"), path);

            if (pathLen + n > home.size())
            {
                RECLS_COVER_MARK_LINE();

                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{5}: %s"), path);

                return RECLS_RC_PATH_LIMIT_EXCEEDED;
            }
            else
            {
                RECLS_COVER_MARK_LINE();

                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{6}: %s"), path);

                // append the path, skipping the tilde
                //
                // - &home[0] + (n - 1) drops the trailing separator on the home directory
                // - path + 1 skips the tilde
                // - pathLen includes the NUL terminator
                types::traits_type::char_copy(&home[0] + (n - 1), path + 1, pathLen);

                --n;        // The dropped path name separator
                --pathLen;  // The skipped tilde

                pathLen += n;

                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{7}: %s"), path);

                path = home.c_str();

                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{8}: %s"), path);
            }
        }
    }

    RECLS_ASSERT(pathLen == types::traits_type::str_len(path));

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{9}: %s"), path);

    if (0 == pathLen)
    {
        RECLS_COVER_MARK_LINE();

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{10}: %s"), path);

        return RECLS_RC_INVALID_NAME;
    }

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{11}: %s"), path);

    if (pathLen > types::path_type::max_size())
    {
        recls_error_trace_printf_(RECLS_LITERAL("path too long: %s"), path);

        return RECLS_RC_INVALID_NAME;
    }

    types::path_type   path_(path);

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{12}: [%s, %s]"), path, path_.c_str());

    if (!path_.exists() &&
        RECLS_F_DETAILS_LATER == (flags & RECLS_F_DETAILS_LATER) &&
        0 != (flags & RECLS_F_TYPEMASK)) // To allow non-existant things to be stat'd
    {
        RECLS_COVER_MARK_LINE();

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{13}: [%s, %s]"), path, path_.c_str());

        path_.make_absolute();  // Need this, or get RECLS_RC_DIRECTORY_NOT_FOUND on a non-existant relative path

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{14}: [%s, %s]"), path, path_.c_str());

#ifdef RECLS_STLSOFT_1_10_B01_OR_LATER
        recls_char_t const* file = path_.get_file().ptr;
#else /* ? RECLS_STLSOFT_1_10_B01_OR_LATER */
        recls_char_t const* file = path_.get_file();
#endif /* RECLS_STLSOFT_1_10_B01_OR_LATER */
        types::path_type    path2_(path_.c_str(), static_cast<size_t>(file - path_.c_str()));

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{15}: [%s, %s]"), path, path_.c_str());

        if (!path2_.exists())
        {
            RECLS_COVER_MARK_LINE();

            return RECLS_RC_DIRECTORY_NOT_FOUND;
        }

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{16}: [%s, %s]"), path, path_.c_str());

        return RECLS_RC_NO_MORE_DATA;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{17}: [%s, %s]"), path, path_.c_str());

        if (types::traits_type::is_directory(path_.c_str()))
        {
            RECLS_COVER_MARK_LINE();

            if (RECLS_F_FILES == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_ENTRY_IS_DIRECTORY;
            }
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            if (RECLS_F_DIRECTORIES == (flags & (RECLS_F_FILES | RECLS_F_DIRECTORIES)))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_ENTRY_IS_NOT_DIRECTORY;
            }
        }

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{18}: [%s, %s]"), path, path_.c_str());

        path_.make_absolute(false);

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{19}: [%s, %s]"), path, path_.c_str());

#ifdef RECLS_EXCEPTION_SUPPORT_
        path_.canonicalise(false);
#endif /* RECLS_EXCEPTION_SUPPORT_ */

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{20}: [%s, %s]"), path, path_.c_str());

        return ReclsFileSearch::Stat(path_.c_str(), flags, phEntry);
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

