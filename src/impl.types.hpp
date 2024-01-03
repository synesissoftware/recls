/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.types.hpp
 *
 * Purpose: Implementation header.
 *
 * Created: 12th December 2008
 * Updated: 30th December 2023
 *
 * Home:    https://github.com/synesissoftware/recls
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


#ifndef RECLS_INCL_SRC_HPP_IMPL_TYPES
#define RECLS_INCL_SRC_HPP_IMPL_TYPES

# ifdef RECLS_INCL_SRC_HPP_IMPL_TYPES_FTP
#  error Cannot include impl.types.ftp.hpp and impl.types.hpp in same compilation unit
# endif

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#include "incl.platformstl.h"
#include "impl.string.hpp"

#include <stlsoft/memory/auto_buffer.hpp>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <platformstl/filesystem/path.hpp>
#include <platformstl/filesystem/path_buffer.hpp>
#include <platformstl/system/system_traits.hpp>

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

template<
    typename T_character
>
struct file_types_base;

template<>
struct file_types_base<recls_char_a_t>
{
    typedef platformstl::path_buffer_a                      path_buffer_type;
};

template<>
struct file_types_base<recls_char_w_t>
{
    typedef platformstl::path_buffer_w                      path_buffer_type;
};

struct file_types
{
public: /// Member Types
    typedef ::platformstl::filesystem_traits<
        recls_char_t
    >                                                       traits_type;

    typedef ::platformstl::system_traits<
        recls_char_t
    >                                                       system_traits_type;

    /// The character type
    typedef recls_char_t                                    char_type;

    /// The string type
    typedef RECLS_STRING_TEMPLATE_1(recls_char_t)           string_type;

    /// The buffer type
    typedef stlsoft::auto_buffer<recls_char_t>              buffer_type;

    /// The stat() data type
    typedef traits_type::stat_data_type                     stat_data_type;

#ifdef PLATFORMSTL_OS_IS_WINDOWS
    /// The find data type
    typedef traits_type::find_data_type                     find_data_type;
#endif /* PLATFORMSTL_OS_IS_WINDOWS */

    /// The path buffer type
    typedef file_types_base<
        recls_char_t
    >::path_buffer_type                                     path_buffer_type;

    /// The path type
    typedef ::platformstl::basic_path<recls_char_t>         path_type;


private: // construction
    file_types();                       // default-construction proscribed
    file_types(file_types const&);      // copy-construction proscribed
    void operator =(file_types const&); // copy-assignment proscribed

public: // operations
    ///
    /// \note Assumes that the directory has a trailing path separator
    static
    size_t
    count_dir_parts(
        recls_char_t const* begin
    ,   recls_char_t const* end
    )
    {
        // static_cast required for CodeWarrior
        return static_cast<size_t>(std::count_if(begin, end, traits_type::is_path_name_separator));
    }
};

typedef file_types  types; // This is required to avoid bad linker behaviour (which makes sense!)

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_TYPES */

/* ///////////////////////////// end of file //////////////////////////// */

