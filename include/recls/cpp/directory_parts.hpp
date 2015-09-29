/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/cpp/directory_parts.hpp
 *
 * Purpose:     recls C++ mapping - directory_parts class.
 *
 * Created:     18th August 2003
 * Updated:     19th May 2010
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2010, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_REVISION 1
# define RECLS_VER_RECLS_CPP_HPP_DIRECTORY_PARTS_EDIT     50
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <recls/cpp/common.hpp>

/* If this header cannot be found, you may not be using STLSoft 1.10 (or later),
 * or STLSoft 1.9 with STLSoft 1.10 alpha 13 (or later)
 *
 * Note: At the time of release of recls 1.9, STLSoft 1.10 has not been
 *  released, and exists only in alpha form. You must download both
 *  STLSoft 1.9 (which is a complete distribution) and STLSoft 1.10 alpha
 *  (which is a delta distribution). Then, it is recommended that you create
 *  two environment variables, STLSOFT and STLSOFT_1_10 respectively, and
 *  specify them both on your include paths, in *reverse* order, in order
 *  that the components defined in STLSoft 1.10 take precendence. For
 *  example, if you're compiling from the shell on UNIX, you would specify
 *  your include paths along the following lines:
 *
 *     . . . -I $(RECLS_ROOT)/include -I $(STLSOFT_1_10)/include -I $(STLSOFT)/include . . .
 */
#include <stlsoft/view/transforming/random_access_transforming_view_base.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace cpp
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
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
    typedef stlsoft::random_access_transforming_view_base<
                directory_parts
            ,   string_t
            ,   recls_strptrs_t const*
            >                                   parent_class_type;
    typedef parent_class_type::value_type       value_type;
    typedef parent_class_type::const_iterator   const_iterator;
    typedef directory_parts                     class_type;

public: // Construction
    /// Conversion constructor
    explicit directory_parts(recls_entry_t entry)
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
    ~directory_parts() stlsoft_throw_0()
    {
        Recls_CloseDetails(m_entry);
    }
private:
    class_type& operator =(class_type const&rhs);

public:
    // Required by base class template
    static value_type create_value(recls_strptrs_t const& ptrs)
    {
        return value_type(ptrs.begin, ptrs.end);
    }

private: // Member Variables
    recls_entry_t               m_entry;
    recls_strptrsptrs_t const   m_parts;
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_DIRECTORY_PARTS */

/* ///////////////////////////// end of file //////////////////////////// */
