/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/traits.hpp
 *
 * Purpose: Traits for recls C++ mapping.
 *
 * Created: 25th March 2004
 * Updated: 13th January 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file recls/cpp/traits.hpp
 *
 * \brief [C++] Traits
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_TRAITS
#define RECLS_INCL_RECLS_CPP_HPP_TRAITS

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_TRAITS_MAJOR       5
# define RECLS_VER_RECLS_CPP_HPP_TRAITS_MINOR       1
# define RECLS_VER_RECLS_CPP_HPP_TRAITS_REVISION    4
# define RECLS_VER_RECLS_CPP_HPP_TRAITS_EDIT        29
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/cpp/traits.hpp
 *
 * \brief [C++] Definition of the
 *  \link recls::cpp::reclstl_traits reclstl_traits\endlink
 *  traits class, representing the
 *  \ref group__recls__cpp "recls C++ mapping".
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>
#include <recls/cpp/directory_parts.hpp>

#if defined(RECLS_API_FTP)
# include <recls/ftp.h>
#endif /* RECLS_API_FTP */

#ifndef RECLS_INCL_H_RECLS_ASSERT
# include <recls/assert.h>
#endif /* !RECLS_INCL_H_RECLS_ASSERT */

#include <stlsoft/internal/safestr.h>

#include <string.h>

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

/// A traits class to provide character-encoding specific mappings from the \ref group__recls "recls C API" to the \ref group__recls__cpp "recls C++ mapping"
/// \ingroup group__recls__cpp
///
template <typename C>
struct reclstl_traits
{
public:
    /// The <code>char</code> type
    ///
    /// \note In this template, <code>void</code> is a placeholder. <code>recls_char_a_t</code> and <code>recls_char_w_t</code> specialisations
    /// will use their respective character types
    typedef void                                            char_type;
    /// The entry type
    ///
    /// \note In this template, <code>void*</code> is a placeholder. <code>recls_char_a_t</code> and <code>recls_char_w_t</code> specialisations
    /// will use their respective \c recls_fileinfo_t types
    typedef void*                                           entry_type;

public:
#if defined(RECLS_API_FTP)
    /// traits-form of Recls_SearchFtp()
    static recls_rc_t       SearchFtp(char_type const* host, char_type const* username, char_type const* password, char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch);
#endif /* RECLS_API_FTP */

    /// traits-form of Recls_Search()
    static recls_rc_t       Search(char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch);

    /// traits-form of Recls_GetDetails()
    static recls_rc_t       GetDetails(hrecls_t hSrch, entry_type *pinfo);
    /// traits-form of Recls_GetNextDetails()
    static recls_rc_t       GetNextDetails(hrecls_t hSrch, entry_type *pinfo);

    /// traits-form of Recls_CloseDetails()
    static void             CloseDetails(entry_type fileInfo);
    /// traits-form of Recls_CopyDetails()
    static entry_type       CopyDetails(entry_type fileInfo);

    /// Copies a specific number of characters from the source to the destination
    static char_type*       char_copy(char_type* dest, char_type const* src, size_t n);
#if !defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) || \
    defined(_CRT_SECURE_NO_DEPRECATE)
    /// traits-form of <code>strcpy</code>
    static char_type*       str_copy(char_type* , char_type const* );

    /// traits-form of <code>strcpy</code>
    static char_type*       str_n_copy(char_type* , char_type const* , size_t);
#endif /* !STLSOFT_USING_SAFE_STR_FUNCTIONS || _CRT_SECURE_NO_DEPRECATE */
    /// Evaluates the length of <code>src</code>
    static size_t           str_len(char_type const* src);
};

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION

# ifdef RECLS_CHAR_TYPE_IS_CHAR

template <>
struct reclstl_traits<recls_char_a_t>
{
public:
    typedef reclstl_traits<recls_char_a_t>                  traits_type;
    typedef recls_char_a_t                                  char_type;
    typedef recls_info_t                                    entry_type;
    typedef recls_strptrs_t                                 strptrs_type;
    typedef recls_strptrsptrs_t                             strptrsptrs_type;

    /// The directory parts sequence type
    typedef directory_parts                                 directory_parts_type;

    /// Constructs a value of type \c string_t from an instance of the pointers structure.
    ///
    /// \note This is required by the STLSoft proxy_sequence template.
    static string_t make_value(strptrs_type const& ptrs)
    {
        return string_t(ptrs.begin, ptrs.end);
    }

public:
#if defined(RECLS_API_FTP)
    static recls_rc_t SearchFtp(char_type const* host, char_type const* username, char_type const* password, char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch)
    {
        return Recls_SearchFtp(host, username, password, searchRoot, pattern, flags, phSrch);
    }
#endif /* RECLS_API_FTP */

    static recls_rc_t Search(char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch)
    {
        return Recls_Search(searchRoot, pattern, flags, phSrch);
    }

    static recls_rc_t SearchFeedback(char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_progress_fn_t pfn, recls_process_fn_param_t param, hrecls_t* phSrch)
    {
        return Recls_SearchFeedback(searchRoot, pattern, flags, pfn, param, phSrch);
    }

    static recls_rc_t GetDetails(hrecls_t hSrch, entry_type *pinfo)
    {
        return Recls_GetDetails(hSrch, pinfo);
    }

    static recls_rc_t GetNextDetails(hrecls_t hSrch, entry_type *pinfo)
    {
        return Recls_GetNextDetails(hSrch, pinfo);
    }

    static void CloseDetails(entry_type fileInfo)
    {
        Recls_CloseDetails(fileInfo);
    }
    static entry_type CopyDetails(entry_type fileInfo)
    {
        entry_type  infoCopy;

        return RECLS_SUCCEEDED(Recls_CopyDetails(fileInfo, &infoCopy)) ? infoCopy : static_cast<entry_type>(NULL);
    }

    static char_type* char_copy(char_type* dest, char_type const* src, size_t n)
    {
        RECLS_ASSERT(NULL != dest);
        RECLS_ASSERT(0 == n || NULL != src);

        return static_cast<char_type*>(::memcpy(dest, src, sizeof(char_type) * n));
    }
#if !defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) || \
    defined(_CRT_SECURE_NO_DEPRECATE)
    static char_type* str_copy(char_type* dest, char_type const* src)
    {
        return ::strcpy(dest, src);
    }

    static char_type* str_n_copy(char_type* dest, char_type const* src, size_t n)
    {
        return ::strncpy(dest, src, n);
    }
#endif /* !STLSOFT_USING_SAFE_STR_FUNCTIONS || _CRT_SECURE_NO_DEPRECATE */
    static size_t str_len(char_type const* src)
    {
        RECLS_ASSERT(NULL != src);

        return ::strlen(src);
    }
};

# elif defined(RECLS_CHAR_TYPE_IS_WCHAR)

template <>
struct reclstl_traits<recls_char_w_t>
{
public:
    typedef reclstl_traits<recls_char_w_t>                  traits_type;
    typedef recls_char_w_t                                  char_type;
    typedef recls_info_t                                    entry_type;
    typedef recls_strptrs_t                                 strptrs_type;
    typedef recls_strptrsptrs_t                             strptrsptrs_type;

#ifdef RECLS_CPP_SUPPORT_DIRECTORY_PARTS
    /// The directory parts sequence type
    typedef directory_parts                                 directory_parts_type;

#endif
    /// Constructs a value of type \c string_t from an instance of the pointers structure.
    ///
    /// \note This is required by the STLSoft proxy_sequence template.
    static string_t make_value(strptrs_type const& ptrs)
    {
        return string_t(ptrs.begin, ptrs.end);
    }

public:
#if defined(RECLS_API_FTP)
    static recls_rc_t SearchFtp(char_type const* host, char_type const* username, char_type const* password, char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch)
    {
        return Recls_SearchFtp(host, username, password, searchRoot, pattern, flags, phSrch);
    }
#endif /* RECLS_API_FTP */

    static recls_rc_t Search(char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_t* phSrch)
    {
        return Recls_Search(searchRoot, pattern, flags, phSrch);
    }

    static recls_rc_t SearchFeedback(char_type const* searchRoot, char_type const* pattern, recls_uint32_t flags, hrecls_progress_fn_t pfn, recls_process_fn_param_t param, hrecls_t* phSrch)
    {
        return Recls_SearchFeedback(searchRoot, pattern, flags, pfn, param, phSrch);
    }

    static recls_rc_t GetDetails(hrecls_t hSrch, entry_type *pinfo)
    {
        return Recls_GetDetails(hSrch, pinfo);
    }

    static recls_rc_t GetNextDetails(hrecls_t hSrch, entry_type *pinfo)
    {
        return Recls_GetNextDetails(hSrch, pinfo);
    }

    static void CloseDetails(entry_type fileInfo)
    {
        Recls_CloseDetails(fileInfo);
    }
    static entry_type CopyDetails(entry_type fileInfo)
    {
        entry_type  infoCopy;

        return RECLS_SUCCEEDED(Recls_CopyDetails(fileInfo, &infoCopy)) ? infoCopy : static_cast<entry_type>(NULL);
    }

    static char_type* char_copy(char_type* dest, char_type const* src, size_t n)
    {
        RECLS_ASSERT(NULL != dest);
        RECLS_ASSERT(0 == n || NULL != src);

        return static_cast<char_type*>(::memcpy(dest, src, sizeof(char_type) * n));
    }
#if !defined(STLSOFT_USING_SAFE_STR_FUNCTIONS) || \
    defined(_CRT_SECURE_NO_DEPRECATE)
    static char_type* str_copy(char_type* dest, char_type const* src)
    {
        return ::wcscpy(dest, src);
    }

    static char_type* str_n_copy(char_type* dest, char_type const* src, size_t n)
    {
        return ::wcsncpy(dest, src, n);
    }
#endif /* !STLSOFT_USING_SAFE_STR_FUNCTIONS || _CRT_SECURE_NO_DEPRECATE */
    static size_t str_len(char_type const* src)
    {
        RECLS_ASSERT(NULL != src);

        return ::wcslen(src);
    }
};
# else /* character type */

#  error Neither RECLS_CHAR_TYPE_IS_WCHAR nor RECLS_CHAR_TYPE_IS_CHAR are defined
# endif /* character type */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* RECLS_INCL_RECLS_CPP_HPP_TRAITS */

/* ///////////////////////////// end of file //////////////////////////// */

