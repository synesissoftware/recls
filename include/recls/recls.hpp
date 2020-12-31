/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/recls.hpp
 *
 * Purpose:     recls C++ mapping.
 *
 * Created:     5th January 2010
 * Updated:     31st December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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


#ifndef RECLS_INCL_RECLS_HPP_RECLS
#define RECLS_INCL_RECLS_HPP_RECLS

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_HPP_RECLS_MAJOR    1
# define RECLS_VER_RECLS_HPP_RECLS_MINOR    2
# define RECLS_VER_RECLS_HPP_RECLS_REVISION 4
# define RECLS_VER_RECLS_HPP_RECLS_EDIT     8
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>

#include <recls/cpp/exceptions.hpp>

#include <recls/cpp/entry.hpp>

#include <recls/cpp/root_sequence.hpp>

#include <recls/cpp/search_sequence.hpp>

#ifdef RECLS_API_FTP
# include <recls/cpp/ftp_search_sequence.hpp>
#endif /* RECLS_API_FTP */

#include <recls/cpp/util.hpp>

#if !defined(RECLS_PURE_API)
# if 0
# elif defined(RECLS_PLATFORM_IS_WINDOWS)
#  include <recls/cpp/windows.hpp>
# elif defined(RECLS_PLATFORM_IS_UNIX)
#  include <recls/cpp/unix.hpp>
# else /* ? platform */
#  error Platform not recognised
# endif /* platform */
#endif /* !RECLS_PURE_API */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */

    using ::recls::cpp::char_t;
    using ::recls::cpp::string_t;

    using ::recls::cpp::directory_parts;
    using ::recls::cpp::entry;
#ifdef RECLS_API_FTP
    using ::recls::cpp::ftp_search_sequence;
#endif /* RECLS_API_FTP */
    using ::recls::cpp::search_sequence;
    using ::recls::cpp::root_sequence;
    using ::recls::cpp::recls_exception;
    using ::recls::cpp::NO_MORE_DATA_exception;

    using ::recls::cpp::calculate_directory_size;
    using ::recls::cpp::create_directory;
    using ::recls::cpp::combine_paths;
    using ::recls::cpp::derive_relative_path;
    using ::recls::cpp::is_directory_empty;
    using ::recls::cpp::remove_directory;
    using ::recls::cpp::squeeze_path;
    using ::recls::cpp::stat;

    using ::recls::cpp::wildcardsAll;

#if !defined(RECLS_PURE_API)
# if defined(RECLS_PLATFORM_IS_WINDOWS)
        using ::recls::cpp::result_code_to_windows_error_code;
# elif defined(RECLS_PLATFORM_IS_UNIX)
# else /* ? platform */
#  error Platform not recognised
# endif /* platform */
#endif /* !RECLS_PURE_API */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_HPP_RECLS */

/* ///////////////////////////// end of file //////////////////////////// */
