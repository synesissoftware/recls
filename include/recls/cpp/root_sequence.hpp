/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/root_sequence.hpp
 *
 * Purpose: recls C++ mapping - root_sequence class.
 *
 * Created: 25th March 2004
 * Updated: 8th July 2024
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


/** \file recls/cpp/root_sequence.hpp
 *
 * \brief [C++] recls::root_sequence class
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_ROOT_SEQUENCE
#define RECLS_INCL_RECLS_CPP_HPP_ROOT_SEQUENCE

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_ROOT_SEQUENCE_MAJOR    4
# define RECLS_VER_RECLS_CPP_HPP_ROOT_SEQUENCE_MINOR    1
# define RECLS_VER_RECLS_CPP_HPP_ROOT_SEQUENCE_REVISION 7
# define RECLS_VER_RECLS_CPP_HPP_ROOT_SEQUENCE_EDIT     32
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/cpp/root_sequence.hpp
 *
 * \brief [C++] Definition of the
 *  \link recls::cpp::root_sequence root_sequence\endlink
 *  class, and supporting classes, representing the
 *  \ref group__recls__cpp "recls C++ mapping".
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>
#include <recls/cpp/traits.hpp>

#include <stlsoft/memory/new_allocator.hpp>
#include <stlsoft/iterators/transform_iterator.hpp>

#include <functional>

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
 * helpers
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION

namespace root_sequence_impl
{

    struct make_root_string
#if __cplusplus < 201402L
        : std::unary_function<recls_root_t, string_t>
#endif
    {
#if __cplusplus >= 201402L
        typedef recls_root_t                                argument_type;
        typedef string_t                                    result_type;
#endif

        string_t operator ()(recls_root_t const& root) const
        {
            return string_t(root.name);
        }
    };

} /* namespace root_sequence_impl */

#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class root_sequence
/** Presents an STL-like sequence interface over the roots on the
 *   file-system
 *
 * \ingroup group__recls__cpp
 *
\htmlonly
<pre>
  recls::root_sequence  roots;

  std::cout &lt;&lt; "Roots:" &lt;&lt; std::endl;
  { for (recls::root_sequence::const_iterator i = roots.begin(), e = roots.end(); i != e; ++i)
  {
    std::cout &lt;&lt; "    " &lt;&lt; *i &lt;&lt; std::endl;
  }}
</pre>
\endhtmlonly
 */
class root_sequence
{
/// \name Types
/// @{
public:
    /// The character type
    typedef char_t                                          char_type;
    /// The traits type
    typedef reclstl_traits<char_type>                       traits_type;
    /// The allocator type
    typedef stlsoft::new_allocator<char_type>               allocator_type;
    /// The current parameterisation of the type
    typedef root_sequence                                   class_type;
    /// The value type
    typedef char_type const*                                value_type;
private:
    typedef root_sequence_impl::make_root_string            transform_function_type_;
public:
    /// The non-mutating (const) iterator type supporting the Input Iterator concept
    typedef stlsoft::transform_iterator<
        recls_root_t*
    ,   transform_function_type_
    >                                                       const_iterator;
    /// The reference type
    typedef void                                            reference;
    /// The non-mutable (const) reference type
    typedef value_type                                      const_reference;
    /// The size type
    typedef size_t                                          size_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an instance containing all the roots on the
    ///  host system.
    root_sequence();
    /// Constructs an instance containing all the roots matching the
    ///  given recls::RECLS_ROOTS_FLAG flags.
    explicit
    root_sequence(
        unsigned flags
    );
    /// Destructor
    ~root_sequence() STLSOFT_NOEXCEPT;
private:
    root_sequence(class_type const&);   // Copy-construction proscribed
    void operator =(class_type const&); // Copy-assignment proscribed
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

/// \name Accessors
/// @{
public:
    /// Returns the number of items in the sequence
    size_type           size() const STLSOFT_NOEXCEPT;
    /// Indicates whether the sequence is empty
    recls_bool_t        empty() const STLSOFT_NOEXCEPT;
    /// Returns the maximum number of items in the sequence
    static size_type    max_size() STLSOFT_NOEXCEPT;

    /// TBC
    const_reference     operator [](size_type index) const;
/// @}

/// \name Members
/// @{
private:
    recls_root_t*   m_roots;
    size_type       m_cRoots;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

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
    root_sequence const& s
)
{
    return s.empty();
}

/* /////////////////////////////////////////////////////////////////////////
 * implementation
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION

// root_sequence

// Construction

inline
root_sequence::root_sequence()
#ifdef RECLS_COMPILER_IS_BORLAND
    : m_cRoots(26) // It fails to "see" Recls_GetRoots()
#else /* ? compiler */
    : m_cRoots(Recls_GetRoots(NULL, 0))
#endif /* compiler */
{
    m_roots = new recls_root_t[m_cRoots];

    m_cRoots = Recls_GetRoots(m_roots, m_cRoots);
}

inline
root_sequence::root_sequence(
    unsigned flags
)
#ifdef RECLS_COMPILER_IS_BORLAND
    : m_cRoots(26) // It fails to "see" Recls_GetRoots()
#else /* ? compiler */
    : m_cRoots(Recls_GetSelectedRoots(NULL, 0, flags))
#endif /* compiler */
{
    m_roots = new recls_root_t[m_cRoots];

    m_cRoots = Recls_GetSelectedRoots(m_roots, m_cRoots, flags);
}

inline
root_sequence::~root_sequence() STLSOFT_NOEXCEPT
{
    delete [] m_roots;
}

// Iteration

inline
root_sequence::const_iterator
root_sequence::begin() const
{
    return stlsoft::transformer(&m_roots[0], transform_function_type_());
}

inline
root_sequence::const_iterator
root_sequence::end() const
{
    return stlsoft::transformer(&m_roots[0] + m_cRoots, transform_function_type_());
}

// State

inline
root_sequence::size_type
root_sequence::size() const STLSOFT_NOEXCEPT
{
    return m_cRoots;
}

inline
recls_bool_t
root_sequence::empty() const STLSOFT_NOEXCEPT
{
    return 0 == m_cRoots;
}

inline /* static */
root_sequence::size_type
root_sequence::max_size() STLSOFT_NOEXCEPT
{
    return static_cast<size_type>(-1) / sizeof(value_type);
}

inline /* static */
root_sequence::const_reference
root_sequence::operator [](
    root_sequence::size_type index
) const
{
    STLSOFT_ASSERT(index < size());

    return m_roots[index].name;
}

#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* ////////////////////////////////////////////////////////////////////// */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* RECLS_INCL_RECLS_CPP_HPP_ROOT_SEQUENCE */

/* ///////////////////////////// end of file //////////////////////////// */

