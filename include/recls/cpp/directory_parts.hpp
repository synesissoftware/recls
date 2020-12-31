/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/cpp/directory_parts.hpp
 *
 * Purpose:     recls C++ mapping - directory_parts class.
 *
 * Created:     18th August 2003
 * Updated:     23rd December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/** \file recls/cpp/directory_parts.hpp
 *
 * \brief [C++] recls::directory_parts class
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_DIRECTORY_PARTS
#define RECLS_INCL_RECLS_CPP_HPP_DIRECTORY_PARTS

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_MAJOR    4
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_MINOR    0
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_REVISION 4
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_EDIT     56
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes - 1
 */

#include <recls/cpp/common.hpp>

#include <stlsoft/view/transforming/random_access_transforming_view_base.hpp>

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

/** This class represents a read-only STL collection of all the elements of
 * the directory of an \link recls::cpp::entry entry\endlink.
 *
 * \ingroup group__recls__cpp
 */
class directory_parts
    : public stlsoft::random_access_transforming_view_base<directory_parts, string_t, recls_strptrs_t const*>
{
public: // Member Types
    /// The parent class type
    typedef stlsoft::random_access_transforming_view_base<
        directory_parts
    ,   string_t
    ,   recls_strptrs_t const*
    >                                                       parent_class_type;
    typedef parent_class_type::value_type                   value_type;
    typedef parent_class_type::const_iterator               const_iterator;
    /// This type
    typedef directory_parts                                 class_type;

public: // Construction
    /// Conversion constructor
    explicit
    directory_parts(recls_entry_t entry)
        : parent_class_type(entry->directoryParts.begin, entry->directoryParts.end)
        , m_parts(entry->directoryParts)
    {
        Recls_CopyDetails(entry, &m_entry);
    }
    /// Copy constructor
    directory_parts(class_type const& rhs)
        : parent_class_type(rhs.m_parts.begin, rhs.m_parts.end)
        , m_parts(rhs.m_parts)
    {
        Recls_CopyDetails(rhs.m_entry, &m_entry);
    }
    /// Destructor
    ~directory_parts() STLSOFT_NOEXCEPT
    {
        Recls_CloseDetails(m_entry);
    }
private:
    void operator =(class_type const&rhs); // copy-assignment proscribed

public:
    // Required by base class template
    static
    value_type
    create_value(
        recls_strptrs_t const& ptrs
    )
    {
        return value_type(ptrs.begin, ptrs.end);
    }

private: // Member Variables
    recls_entry_t               m_entry;
    recls_strptrsptrs_t const   m_parts;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_DIRECTORY_PARTS */

/* ///////////////////////////// end of file //////////////////////////// */

