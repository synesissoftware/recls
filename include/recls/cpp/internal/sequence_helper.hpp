/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/internal/sequence_helper.hpp
 *
 * Purpose: recls::internal::sequence_helper struct.
 *
 * Created: 10th September 2003
 * Updated: 13th January 2024
 *
 * Home:    http://recls.org/
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file recls/cpp/internal/sequence_helper.hpp
 *
 * \brief [C++] recls::internal::sequence_helper struct
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER
#define RECLS_INCL_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER_MAJOR     5
# define RECLS_VER_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER_MINOR     0
# define RECLS_VER_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER_REVISION  6
# define RECLS_VER_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER_EDIT      104
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/cpp/search_sequence.hpp
 *
 * \brief [C++] Definition of the
 *  \link recls::cpp::search_sequence search_sequence\endlink
 *  class, and supporting classes.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/traits.hpp>

#include <platformstl/filesystem/filesystem_traits.hpp>
#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/meta/is_integral_type.hpp>
#include <stlsoft/meta/yesno.hpp>

#ifndef STLSOFT_CF_nullptr_KEYWORD_SUPPORT

# ifndef STLSOFT_INCL_H_CSTDDEF
#  define STLSOFT_INCL_H_CSTDDEF
#  include <cstddef>
# endif /* !STLSOFT_INCL_H_CSTDDEF */
#endif

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace cpp
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * utility classes
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION

struct sequence_helper
{
public: // types
    /// The character type
    typedef char_t                                          char_type;
    /// The traits type
    typedef reclstl_traits<char_type>                       traits_type;

    typedef stlsoft::auto_buffer<
        recls_char_t
    ,   200
    >                                                       directory_buffer_type;

    typedef stlsoft::auto_buffer<
        recls_char_t
    ,   100
    >                                                       pattern_buffer_type;


public: // operations
    // These two copy_or_null() implementations provide the following:
    //
    // - generic behaviour, via String Access Shims
    // - ability to supply NULL/nullptr, and have it passed through (rather
    //   than translated into "" by the shims)

private:

    template<
        typename T_src
    ,   typename T_buffer
    >
    static
    char_type const*
    copy_or_null_(
        T_buffer&            /* dest */
    ,   T_src const&            src
    ,   stlsoft::yes_type
    ) STLSOFT_NOEXCEPT
    {
        STLSOFT_MESSAGE_ASSERT("you cannot pass an integer to the directory or patterns parameters", 0 == src);
        STLSOFT_SUPPRESS_UNUSED(src);

        return ss_nullptr_k;
    }

    template<
        typename T_src
    ,   typename T_buffer
    >
    static
    char_type const*
    copy_or_null_(
        T_buffer&               dest
    ,   T_src const&            src
    ,   stlsoft::no_type
    )
    {
        return copy_or_null_len_(dest, STLSOFT_NS_QUAL(c_str_data)(src), STLSOFT_NS_QUAL(c_str_len)(src));
    }

    template<
        typename T_buffer
    >
    static
    char_type const*
    copy_or_null_len_(
        T_buffer&               dest
    ,   char_type const*        src
    ,   size_t                  n
    )
    {
        if (0 == n)
        {
            return ss_nullptr_k;
        }
        else
        {
            dest.resize(n + 1);

            RECLS_ASSERT(n < dest.size());

            char_type* const s = traits_type::char_copy(&dest[0], src, n);

            s[n] = '\0';

            return s;
        }
    }
public:

    template<
        typename T_src
    ,   typename T_buffer
    >
    static
    char_type const*
    copy_or_null(
        T_buffer&               dest
    ,   T_src const&            src
    )
    {
        enum { SrcIsIntegralType = stlsoft::is_integral_type<T_src>::value };

        typedef ss_typename_type_k stlsoft::value_to_yesno_type<SrcIsIntegralType>::type  is_integral_type_t;

        return copy_or_null_(dest, src, is_integral_type_t());
    }

    // This one is implemented in-class as it allows sequence to be used by VC++ 5
    template<
        typename T_buffer
    >
    static
    char_type const*
    copy_or_null(
        T_buffer&               dest
    ,   char_type const*        src
    )
    {
        size_t const n = (ss_nullptr_k == src) ? 0 : traits_type::str_len(src);

        return copy_or_null_len_(dest, src, n);
    }

    // This one is implemented to work with STLSoft's strong NULL
#ifdef STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL

    template<
        typename T_buffer
    >
    static
    char_type const*
    copy_or_null(
        T_buffer&               dest
    ,   stlsoft::NULL_v const&
    ) STLSOFT_NOEXCEPT
    {
        return ss_nullptr_k;
    }
#endif /* !STLSOFT_INCL_STLSOFT_UTIL_HPP_NULL */

    // This one is implemented to work with C++ 11's nullptr
#ifndef STLSOFT_CF_nullptr_KEYWORD_SUPPORT

    template<
        typename T_buffer
    >
    static
    char_type const*
    copy_or_null(
        T_buffer&               dest
    ,   std::nullptr_t const&
    ) STLSOFT_NOEXCEPT
    {
        return ss_nullptr_k;
    }
#endif
};
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* RECLS_INCL_RECLS_CPP_INTERNAL_HPP_SEQUENCE_HELPER */

/* ///////////////////////////// end of file //////////////////////////// */

