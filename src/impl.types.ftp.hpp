/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.types.ftp.hpp
 *
 * Purpose:     Implementation header.
 *
 * Created:     13th December 2008
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_HPP_IMPL_TYPES_FTP
#define RECLS_INCL_SRC_HPP_IMPL_TYPES_FTP

# ifdef RECLS_INCL_SRC_HPP_IMPL_TYPES
#  error Cannot include impl.types.ftp.hpp and impl.types.hpp in same compilation unit
# endif

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#include "incl.inetstl.h"
#include "impl.string.hpp"
#include "impl.cover.h"

#include <stlsoft/memory/auto_buffer.hpp>

#include <inetstl/filesystem/filesystem_traits.hpp>
#include <inetstl/network/connection.hpp>
#include <inetstl/network/session.hpp>

#include <winstl/filesystem/file_path_buffer.hpp>
#include <winstl/filesystem/path.hpp>

#ifdef RECLS_STLSOFT_1_12_OR_LATER
# include <stlsoft/exception/policy/nothrow_exception_policy.hpp>
#endif /* RECLS_STLSOFT_1_12_OR_LATER */

#include <algorithm>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct ftp_types
{
public: /// Member Types
    typedef ::inetstl::filesystem_traits<recls_char_t>      traits_type;

    /// The character type
    typedef recls_char_t                                    char_type;

    /// The string type
    typedef RECLS_STRING_TEMPLATE_1(recls_char_t)           string_type;

    /// The buffer type
    typedef stlsoft::auto_buffer<recls_char_t>              buffer_type;

    /// The stat() data type
    typedef traits_type::stat_data_type                     stat_data_type;

    /// The find data type
    typedef traits_type::find_data_type                     find_data_type;

    /// The file-path buffer type
    typedef ::winstl::basic_file_path_buffer<recls_char_t>  file_path_buffer_type;

    /// The path type
    typedef ::winstl::basic_path<recls_char_t>              path_type;

    // The session type
    typedef inetstl::basic_session<
        recls_char_t
#ifdef RECLS_STLSOFT_1_12_OR_LATER
    ,   stlsoft::nothrow_exception_policy
#else /* ? RECLS_STLSOFT_1_12_OR_LATER */
    ,   stlsoft::null_exception_policy
#endif /* RECLS_STLSOFT_1_12_OR_LATER */
    >                                                       session_type;

    // The connection type
    typedef inetstl::basic_connection<
        recls_char_t
#ifdef RECLS_STLSOFT_1_12_OR_LATER
    ,   stlsoft::nothrow_exception_policy
#else /* ? RECLS_STLSOFT_1_12_OR_LATER */
    ,   stlsoft::null_exception_policy
#endif /* RECLS_STLSOFT_1_12_OR_LATER */
    >                                                       connection_type;

public: /// Operations

    // TODO: Factor out this with impl.types.hpp, via CRTP

    static size_t count_char_instances(
        recls_char_t const* begin
    ,   recls_char_t const* end
    ,   recls_char_t const  ch
    )
    {
        RECLS_ASSERT(NULL != begin);
        RECLS_ASSERT(NULL != end);

        RECLS_COVER_MARK_LINE();

        size_t cDirParts = 0;

        for(; begin != end; ++begin)
        {
            RECLS_COVER_MARK_LINE();

            if(*begin == ch)
            {
                RECLS_COVER_MARK_LINE();

                ++cDirParts;
            }
        }

        return cDirParts;
    }
    ///
    /// \note Assumes that the directory has a trailing path separator
    static size_t count_dir_parts(
        recls_char_t const* begin
    ,   recls_char_t const* end
    )
    {
        RECLS_COVER_MARK_LINE();

        // Need this seemingly superflous cast (to size_t) in order to
        // placate CodeWarrior
        return size_t(std::count_if(begin, end, traits_type::is_path_name_separator));
    }

private: /// Not to be implemented
    ftp_types();
    ftp_types(ftp_types const&);
    ftp_types& operator =(ftp_types const&);
};

typedef ftp_types   types; // This is required to avoid bad linker behaviour (which makes sense!)

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_TYPES_FTP */

/* ///////////////////////////// end of file //////////////////////////// */

