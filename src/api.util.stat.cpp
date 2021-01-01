/* /////////////////////////////////////////////////////////////////////////
 * File:        api.util.stat.cpp
 *
 * Purpose:     recls API extended functions.
 *
 * Created:     16th August 2003
 * Updated:     1st January 2021
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

        return RECLS_RC_FAIL;
    }
    catch(...)
    {
        recls_log_printf_(RECLS_SEVIX_ERROR, RECLS_LITERAL("unknown exception in Recls_Stat()"));

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

    RECLS_ASSERT(ss_nullptr_k != path);
    RECLS_ASSERT(ss_nullptr_k != phEntry);

    *phEntry = static_cast<recls_entry_t>(0);

    types::file_path_buffer_type    home;
    size_t                          pathLen = types::traits_type::str_len(path);

    if (ss_nullptr_k != path &&
        recls_is_home_start_(path, pathLen))
    {
        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{2}: %s"), path);

        size_t n = recls_get_home_(&home[0], home.size());

        if (0 == n)
        {
            //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{3}: %s"), path);

            return RECLS_RC_NO_HOME;
        }
        else
        {
            RECLS_ASSERT(n == types::traits_type::str_len(home.data()));

            // recls_get_home_() always has a trailing path-name separator
            RECLS_ASSERT(types::traits_type::has_dir_end(&home[0]));

            //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{4}: %s"), path);

            if (pathLen + n > home.size())
            {
                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{5}: %s"), path);

                return RECLS_RC_PATH_LIMIT_EXCEEDED;
            }
            else
            {
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

                path = home.data();

                //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{8}: %s"), path);
            }
        }
    }

    RECLS_ASSERT(pathLen == types::traits_type::str_len(path));

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{9}: %s"), path);

    if (0 == pathLen)
    {
        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{10}: %s"), path);

        return RECLS_RC_INVALID_NAME;
    }

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{11}: %s"), path);

    if (pathLen > types::path_type::max_size())
    {
        recls_error_trace_printf_(RECLS_LITERAL("path too long: %s"), path);

        return RECLS_RC_INVALID_NAME;
    }

    types::path_type   path_(path, pathLen);

    //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{12}: [%s, %s]"), path, path_.c_str());

    if (!path_.exists() &&
        RECLS_F_DETAILS_LATER == (flags & RECLS_F_DETAILS_LATER) &&
        0 != (flags & RECLS_F_TYPEMASK)) // To allow non-existant things to be stat'd
    {
        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{13}: [%s, %s]"), path, path_.c_str());

        path_.make_absolute();  // Need this, or get RECLS_RC_DIRECTORY_NOT_FOUND on a non-existant relative path

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{14}: [%s, %s]"), path, path_.c_str());

        types::path_type::string_slice_type const   file    =   path_.get_file();
        types::path_type                            path2_(path_.c_str(), path_.size() - file.len);

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{15}: [%s, %s]"), path, path_.c_str());

        if (!path2_.exists())
        {
            return RECLS_RC_DIRECTORY_NOT_FOUND;
        }

        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{16}: [%s, %s]"), path, path_.c_str());

        return RECLS_RC_NO_MORE_DATA;
    }
    else
    {
        //recls_debug2_trace_printf_(RECLS_LITERAL("Recls_Stat{17}: [%s, %s]"), path, path_.c_str());

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
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

