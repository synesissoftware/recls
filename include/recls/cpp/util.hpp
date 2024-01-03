/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/util.hpp
 *
 * Purpose: recls C++ mapping - utility functions.
 *
 * Created: 18th August 2003
 * Updated: 30th December 2023
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
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


/** \file recls/cpp/util.hpp
 *
 * \brief [C++] Utility functions
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_UTIL
#define RECLS_INCL_RECLS_CPP_HPP_UTIL

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_UTIL_MAJOR     5
# define RECLS_VER_RECLS_CPP_HPP_UTIL_MINOR     1
# define RECLS_VER_RECLS_CPP_HPP_UTIL_REVISION  1
# define RECLS_VER_RECLS_CPP_HPP_UTIL_EDIT      46
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>
#include <recls/cpp/exceptions.hpp>

#include <stlsoft/shims/access/string.hpp>

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
 * implementation
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
struct util_impl
{
    static string_t combine_paths(recls_char_t const* path1, recls_char_t const* path2)
    {
        stlsoft::auto_buffer<recls_char_t>  result(Recls_CombinePaths(path1, path2, NULL, 0));

        Recls_CombinePaths(path1, path2, &result[0], result.size());

        return string_t(result.data(), result.size());
    }
    static string_t derive_relative_path(recls_char_t const* origin, recls_char_t const* target)
    {
        stlsoft::auto_buffer<recls_char_t>  result(Recls_DeriveRelativePath(origin, target, NULL, 0));

        Recls_DeriveRelativePath(origin, target, &result[0], result.size());

        return string_t(result.data(), result.size());
    }
    static string_t squeeze_path(recls_char_t const* path, size_t width)
    {
        stlsoft::auto_buffer<recls_char_t>  result(width);
        size_t                              cch =   Recls_SqueezePath(path, &result[0], result.size());

        STLSOFT_ASSERT(cch <= result.size());

        return string_t(result.data(), cch);
    }

    static recls_filesize_t calculate_directory_size(recls_char_t const* path)
    {
        return Recls_CalcDirectorySize(path);
    }

    static bool is_directory_empty(recls_char_t const* path)
    {
        return 0u != Recls_IsDirectoryEmpty(path);
    }

    static void create_directory(recls_char_t const* path, recls_directoryResults_t* results)
    {
        recls_rc_t rc = Recls_CreateDirectory(path, results);

        if (RECLS_FAILED(rc))
        {
            throw recls_exception(rc, "could not create directory", path, NULL, 0);
        }
    }

    static void remove_directory(recls_char_t const* path, int flags, recls_directoryResults_t* results)
    {
        recls_rc_t rc = Recls_RemoveDirectory(path, flags, results);

        if (RECLS_FAILED(rc))
        {
            if (RECLS_RC_NO_MORE_DATA == rc)
            {
                throw NO_MORE_DATA_exception(rc, "directory does not exist", path, NULL, flags);
            }

            throw recls_exception(rc, "could not remove directory", path, NULL, flags);
        }
    }
};
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * C++ API functions
 */

/** Combines two paths into one.
 *
 * \ingroup group__recls_cpp
 *
 * This function takes two path fragments and combines them to form a single path.
 *
 * \param path1 The left-most path.
 * \param path2 The right-most path.
 *
 * \return The resultant path.
 *
 * \remarks If \c path2 is an absolute path, \c path1 is ignored and
 *   \c result contains characters copied from \c path2.
 */
template<   typename S0
        ,   typename S1
        >
inline
string_t
combine_paths(
    S0 const&   path1
,   S1 const&   path2
)
{
    STLSOFT_NS_USING(c_str_ptr_null);

    return util_impl::combine_paths(c_str_ptr_null(path1), c_str_ptr_null(path2));
}

/** Determines the relative path between two paths
 *
 * \ingroup group__recls_cpp
 *
 * \param origin The path against which the relativity of \c target will be evaluated. If NULL or the empty string, then the resultant path is equivalent to target.
 * \param target The path whose relatively (against \c origin) will be evaluated.
 *
 * \remarks On operating systems that have drives, the result will be an
 *   absolute path (identical to \c target, in fact) if \c target and
 *   \c origin are located on different drives
 */
template<   typename S0
        ,   typename S1
        >
inline
string_t
derive_relative_path(
    S0 const&   origin
,   S1 const&   target
)
{
    STLSOFT_NS_USING(c_str_ptr);

    return util_impl::derive_relative_path(c_str_ptr(origin), c_str_ptr(target));
}

/** Prepares the path for display into a fixed maximum width field.
 *
 * \ingroup group__recls_cpp
 *
 * \param path The path to be squeezed.
 * \param width Number of character spaces into which \c path will be squeezed.
 *
 * \return The number of characters required, not including the NUL terminator
 */
template <typename S>
inline
string_t
squeeze_path(
    S const&    path
,   size_t      width
)
{
    STLSOFT_NS_USING(c_str_ptr);

    return util_impl::squeeze_path(c_str_ptr(path), width);
}

/** Returns the wildcard symbol used to represent the "all files" for the
 * current operating system.
 *
 * \ingroup group__recls_cpp
 *
 * \note On UNIX this is \c "*"; on Windows it is \c "*.*".
 */
inline
char_t const*
wildcardsAll()
{
    return Recls_GetWildcardsAll();
}

/** Calculates the number of bytes in files in the given directory
 *    and all its sub-directories.
 *
 * \ingroup group__recls_cpp
 *
 * \param dir The directory to assess
 */
template <typename S>
inline
recls_filesize_t
calculate_directory_size(
    S const& dir
)
{
    STLSOFT_NS_USING(c_str_ptr);

    return util_impl::calculate_directory_size(c_str_ptr(dir));
}

/** Determines whether the given directory is empty
 *
 * \ingroup group__recls_cpp
 *
 * \param dir The directory to assess
 */
template <typename S>
inline
bool
is_directory_empty(
    S const& dir
)
{
    STLSOFT_NS_USING(c_str_ptr);

    return util_impl::is_directory_empty(c_str_ptr(dir));
}

/** Creates a directory, including all intermediate directories
 *
 * \ingroup group__recls_cpp
 *
 *
 * \pre NULL != path
 */
template <typename S>
inline
void
create_directory(
    S const& path
)
{
    STLSOFT_NS_USING(c_str_ptr);

    util_impl::create_directory(c_str_ptr(path), NULL);
}

/** Creates a directory, including all intermediate directories
 *
 * \ingroup group__recls_cpp
 *
 * \param path The path to create. If not absolute, is assumed relative to
 *   the current directory
 * \param results Pointer to an instance of \c recls_directoryResults_t in
 *   which information regarding the changes effected by the operation will
 *   be recorded. May be \c NULL
 *
 * \note If the function fails, no attempt is made to undo the intermediate
 *   directories created. The caller may establish which intermediate
 *   elements were created by analysing the results
 *
 * \pre NULL != path
 */
template <typename S>
inline
void
create_directory(
    S const&                    path
,   recls_directoryResults_t*   results
)
{
    STLSOFT_NS_USING(c_str_ptr);

    util_impl::create_directory(c_str_ptr(path), results);
}

template <typename S>
inline
void
remove_directory(
    S const& path
)
{
    STLSOFT_NS_USING(c_str_ptr);

    util_impl::remove_directory(c_str_ptr(path), 0, NULL);
}

template <typename S>
inline
void
remove_directory(
    S const&                    path
,   int                         flags
,   recls_directoryResults_t*   results
)
{
    STLSOFT_NS_USING(c_str_ptr);

    util_impl::remove_directory(c_str_ptr(path), flags, results);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_UTIL */

/* ///////////////////////////// end of file //////////////////////////// */

