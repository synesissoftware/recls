/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/cpp/classfwd.hpp
 *
 * Purpose:     Forward declarations of classes in the recls C++ mapping.
 *
 * Created:     23rd November 2011
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2011-2019, Matthew Wilson and Synesis Software
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
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
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


/** \file recls/cpp/classfwd.hpp
 *
 * \brief [C++] Forward declarations of classes
 *   in the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_CLASSFWD
#define RECLS_INCL_RECLS_CPP_HPP_CLASSFWD

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_CLASSFWD_MAJOR     1
# define RECLS_VER_RECLS_CPP_HPP_CLASSFWD_MINOR     1
# define RECLS_VER_RECLS_CPP_HPP_CLASSFWD_REVISION  2
# define RECLS_VER_RECLS_CPP_HPP_CLASSFWD_EDIT      4
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>

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
 * classes
 */

#ifdef RECLS_CPP_SUPPORT_DIRECTORY_PARTS
/* recls/cpp/directory_parts.hpp : */
class directory_parts;
#endif

/* recls/cpp/entry.hpp : */
class entry;

/* recls/cpp/exceptions.hpp : */
class recls_exception;
class NO_MORE_DATA_exception;

#ifdef RECLS_API_FTP
/* recls/cpp/ftp_search_sequence.hpp : */
class ftp_search_sequence;
#endif /* RECLS_API_FTP */

/* recls/cpp/root_sequence.hpp : */
class root_sequence;

/* recls/cpp/search_sequence.hpp : */
template<
	typename C
,   typename T
,   typename V
>
class basic_search_sequence_const_iterator;
class search_sequence;

/* recls/cpp/traits.hpp : */
template <typename C>
struct reclstl_traits;
template <>
struct reclstl_traits<recls_char_a_t>;
template <>
struct reclstl_traits<recls_char_w_t>;

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */

#ifdef RECLS_CPP_SUPPORT_DIRECTORY_PARTS
    using ::recls::cpp::directory_parts;
#endif
    using ::recls::cpp::entry;
#ifdef RECLS_API_FTP
    using ::recls::cpp::ftp_search_sequence;
#endif /* RECLS_API_FTP */
    using ::recls::cpp::search_sequence;
    using ::recls::cpp::root_sequence;
    using ::recls::cpp::recls_exception;
    using ::recls::cpp::NO_MORE_DATA_exception;

} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_CLASSFWD */

/* ///////////////////////////// end of file //////////////////////////// */

