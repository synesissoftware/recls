/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/cpp/ftp_search_sequence.hpp
 *
 * Purpose:     recls C++ mapping - ftp_search_sequence class.
 *
 * Created:     10th September 2003
 * Updated:     30th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
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


/** \file recls/cpp/ftp_search_sequence.hpp
 *
 * \brief [C++] recls::ftp_search_sequence class
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE
#define RECLS_INCL_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE_MAJOR      4
# define RECLS_VER_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE_MINOR      0
# define RECLS_VER_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE_REVISION   7
# define RECLS_VER_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE_EDIT       94
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/cpp/ftp_search_sequence.hpp
 *
 * \brief [C++] Definition of the
 *  \link recls::cpp::ftp_search_sequence ftp_search_sequence\endlink
 *  class, and supporting classes.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/search_sequence.hpp>

#include <recls/cpp/common.hpp>
#include <recls/cpp/entry.hpp>
#include <recls/cpp/traits.hpp>

#ifndef RECLS_API_FTP
# error Can only use recls::ftp_search_sequence in environments that support RECLS_API_FTP
#endif /* RECLS_API_FTP */

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

// class ftp_search_sequence
/** Presents an STL-like sequence interface over the entries on the
 *   file-system
 *
 * \ingroup group__recls__cpp
 *
\htmlonly
<pre>
  recls::ftp_search_sequence files(".", "*.*", recls::FILES | recls::RECURSIVE);

  std::cout &lt;&lt; "Files:" &lt;&lt; std::endl;
  { for (recls::ftp_search_sequence::const_iterator i = files.begin(), e = files.end(); i != e; ++i)
  {
    std::cout &lt;&lt; "    " &lt;&lt; *i &lt;&lt; std::endl;
  }}
</pre>
\endhtmlonly
 */
class ftp_search_sequence
    : protected sequence_helper
{
/// \name Types
/// @{
public:
    /// The character type
    typedef char_t                                          char_type;
    /// The traits type
    typedef reclstl_traits<char_type>                       traits_type;
    /// The current parameterisation of the type
    typedef ftp_search_sequence                             class_type;
    /// The value type
    typedef entry                                           value_type;
    /// The non-mutating (const) iterator type supporting the Input Iterator concept
    typedef basic_search_sequence_const_iterator<
        char_type
    ,   traits_type
    ,   value_type
    >                                                       const_iterator;
    /// The reference type
    typedef value_type&                                     reference;
    /// The non-mutable (const) reference type
    typedef value_type const&                               const_reference;
    /// The find-data type
    typedef traits_type::entry_type                         entry_type;
    /// The size type
    typedef size_t                                          size_type;
    /// The difference type
    typedef ptrdiff_t                                       difference_type;
    /// The string type
    typedef string_t                                        string_type;
/// @}

/// \name Construction
/// @{
public:
    /// Commence an FTP search on the given site, according to the given search pattern and flags
    ftp_search_sequence(
        char_type const*    host
    ,   char_type const*    username
    ,   char_type const*    password
    ,   char_type const*    directory
    ,   char_type const*    pattern
    ,   recls_uint32_t      flags
    );
#if defined(STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT)
    template<
        typename S0
    ,   typename S1
    ,   typename S2
    ,   typename S3
    ,   typename S4
    >
    ftp_search_sequence(S0 const& host, S1 const& username, S2 const& password, S3 const& directory, S4 const& pattern, recls_uint32_t flags)
        : m_host(stlsoft::c_str_data(host), stlsoft::c_str_len(host))
        , m_username(stlsoft::c_str_data(username), stlsoft::c_str_len(username))
        , m_password(stlsoft::c_str_data(password), stlsoft::c_str_len(password))
        , m_directory_(1)
        , m_pattern_(1)
        , m_directory(copy_or_null(m_directory_, directory))
        , m_pattern(copy_or_null(m_pattern_, pattern))
        , m_flags(flags)
    {}
#endif /* STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT */
    /// Destructor
    ~ftp_search_sequence() STLSOFT_NOEXCEPT
    {
#if !defined(RECLS_COMPILER_IS_COMO) && \
    !defined(RECLS_COMPILER_IS_GCC) && \
    !defined(RECLS_COMPILER_IS_INTEL)
        STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_directory_) < STLSOFT_RAW_OFFSETOF(class_type, m_directory));
        STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(class_type, m_pattern_) < STLSOFT_RAW_OFFSETOF(class_type, m_pattern));
#endif /* compiler */
    }
private:
    ftp_search_sequence(class_type const&); // copy-construction proscribed
    void operator =(class_type const&);     // copy-assignment proscribed
/// @}

/// \name Iteration
/// @{
public:
    /// Begins the iteration
    ///
    /// \return An iterator representing the start of the sequence
    const_iterator  begin() const;
    /// Ends the iteration
    ///
    /// \return An iterator representing the end of the sequence
    const_iterator  end() const;
/// @}

/// \name State
/// @{
public:
    /// Indicates whether the sequence is empty
    recls_bool_t        empty() const;
    /// Returns the maximum number of items in the sequence
    static size_type    max_size() STLSOFT_NOEXCEPT;
/// @}

/// \name Members
/// @{
private:
    friend class basic_search_sequence_const_iterator<char_type, traits_type, value_type>;

    string_type const       m_host;
    string_type const       m_username;
    string_type const       m_password;
    directory_buffer_type   m_directory_;
    pattern_buffer_type     m_pattern_;
    char_type const* const  m_directory;
    char_type const* const  m_pattern;
    recls_uint32_t          m_flags;
/// @}
};

////////////////////////////////////////////////////////////////////////////
// Shims

/// is_empty shim
/// \ingroup group__recls__cpp
///
/// This returns a non-zero value if the given sequence is empty.
/// \param s The sequence whose state is to be tested
///
/// \note This fits the <a href = "http://stlsoft.org/help/main.html">STLSoft</a> shims
/// concept, described in <a href = "http://synesis.com.au/resources/articles/cpp/shims.pdf">this</a>
/// Synesis Software White Paper, and featured in the article "<a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">Generalised String Manipulation: Access Shims and Type-tunnelling</a>",
/// in the August 2003 issue of <a href = "http://www.cuj.com">C/C++ User's Journal</a>.
inline
recls_bool_t
is_empty(
    ftp_search_sequence const& s
)
{
    return s.empty();
}

////////////////////////////////////////////////////////////////////////////
// Implementation

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION

// ftp_search_sequence

// Construction
inline
ftp_search_sequence::ftp_search_sequence(
    char_type const*    host
,   char_type const*    username
,   char_type const*    password
,   char_type const*    directory
,   char_type const*    pattern
,   recls_uint32_t      flags
)
    : m_host(host)
    , m_username(username)
    , m_password(password)
    , m_directory_(1)
    , m_pattern_(1)
    , m_directory(copy_or_null(m_directory_, directory))
    , m_pattern(copy_or_null(m_pattern_, pattern))
    , m_flags(flags)
{
    RECLS_MESSAGE_ASSERT("Must specify a hostname if using FTP", (NULL == username && NULL == password) || NULL != host);
}

// Iteration
inline
ftp_search_sequence::const_iterator
ftp_search_sequence::begin() const
{
    hrecls_t    hSrch;
    recls_rc_t  rc = traits_type::SearchFtp(m_host.c_str(), m_username.c_str(), m_password.c_str(), m_directory, m_pattern, m_flags, &hSrch);

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT

    if (RECLS_FAILED(rc) &&
        RECLS_RC_NO_MORE_DATA != rc)
    {
        throw recls_exception(rc, "failed to search FTP directory", m_directory, m_pattern, m_flags);
    }
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    return const_iterator(hSrch);
}

inline
ftp_search_sequence::const_iterator
ftp_search_sequence::end() const
{
    return const_iterator();
}

// State
inline
recls_bool_t
ftp_search_sequence::empty() const
{
    return begin() == end();
}

inline /* static */
ftp_search_sequence::size_type
ftp_search_sequence::max_size() STLSOFT_NOEXCEPT
{
    return static_cast<size_type>(-1);
}

#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* RECLS_INCL_RECLS_CPP_HPP_FTP_SEARCH_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

