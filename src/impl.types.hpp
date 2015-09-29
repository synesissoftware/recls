/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.types.hpp
 *
 * Purpose:     Implementation header.
 *
 * Created:     12th December 2008
 * Updated:     18th October 2010
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2008-2010, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_HPP_IMPL_TYPES
#define RECLS_INCL_SRC_HPP_IMPL_TYPES

# ifdef RECLS_INCL_SRC_HPP_IMPL_TYPES_FTP
#  error Cannot include impl.types.ftp.hpp and impl.types.hpp in same compilation unit
# endif

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <recls/recls.h>

#include "incl.platformstl.h"
#include "impl.cover.h"
#include "impl.string.hpp"

#include <stlsoft/memory/auto_buffer.hpp>

#include <platformstl/filesystem/file_path_buffer.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path.hpp>

#include <algorithm>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Types
 */

struct file_types
{
public: /// Member Types
    typedef ::platformstl::filesystem_traits<recls_char_t>      traits_type;

    /// The character type
    typedef recls_char_t                                        char_type;

    /// The string type
    typedef RECLS_STRING_TEMPLATE_1(recls_char_t)               string_type;

    /// The buffer type
    typedef stlsoft::auto_buffer<recls_char_t>                  buffer_type;

    /// The stat() data type
    typedef traits_type::stat_data_type                         stat_data_type;

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    /// The find data type
    typedef traits_type::find_data_type                         find_data_type;
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

    /// The file-path buffer type
    typedef ::platformstl::basic_file_path_buffer<recls_char_t> file_path_buffer_type;

    /// The path type
    typedef ::platformstl::basic_path<recls_char_t>             path_type;

public: /// Operations
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

        // static_cast required for CodeWarrior
        return static_cast<size_t>(std::count_if(begin, end, traits_type::is_path_name_separator));
    }

private: /// Not to be implemented
    file_types();
    file_types(file_types const&);
    file_types& operator =(file_types const&);
};

typedef file_types  types; // This is required to avoid bad linker behaviour (which makes sense!)

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_TYPES */

/* ///////////////////////////// end of file //////////////////////////// */
