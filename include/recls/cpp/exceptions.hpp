/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/cpp/exceptions.hpp
 *
 * Purpose:     recls C++ mapping - exception classes.
 *
 * Created:     10th September 2003
 * Updated:     14th June 2012
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2012, Matthew Wilson and Synesis Software
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


/** \file recls/cpp/exceptions.hpp
 *
 * \brief [C++] Exception classes
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_EXCEPTIONS
#define RECLS_INCL_RECLS_CPP_HPP_EXCEPTIONS

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_EXCEPTIONS_MAJOR       4
# define RECLS_VER_RECLS_CPP_HPP_EXCEPTIONS_MINOR       1
# define RECLS_VER_RECLS_CPP_HPP_EXCEPTIONS_REVISION    2
# define RECLS_VER_RECLS_CPP_HPP_EXCEPTIONS_EDIT        40
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#include <recls/cpp/common.hpp>
#include <recls/internal/safestr.h>

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string.hpp>

#include <stdexcept>

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

/// The exception type thrown by the recls - STL mapping
class recls_exception
    : public std::runtime_error
{
/// \name Types
/// @{
public:
    typedef std::runtime_error  parent_class_type;
    typedef recls_exception     class_type;
private:
    typedef string_t            string_type;
    typedef string_a_t          message_string_type;
/// @}

/// \name Construction
/// @{
public:
    /// Constructs an exception from the given error code
    explicit recls_exception(recls_rc_t rc)
        : parent_class_type(create_message_(rc))
        , m_rc(rc)
        , m_context()
        , m_path()
        , m_patterns()
        , m_flags(0)
    {}
    /// Constructs an exception from the given error code, message,
    /// path and flags
    ///
    /// \param rc The result code to be associated with the exception.
    /// \param context The context (message) to be associated with the exception.
    /// \param path The path to be associated with the exception.
    /// \param patterns The patterns to be associated with the exception.
    /// \param flags The flags to be associated with the exception.
    recls_exception(recls_rc_t rc, char const* context, recls_char_t const* path, recls_char_t const* patterns, int flags)
        : parent_class_type(create_message_(rc, context, path, flags))
        , m_rc(rc)
        , m_context(stlsoft::c_str_ptr(context))
        , m_path(stlsoft::c_str_ptr(path))
        , m_patterns(stlsoft::c_str_ptr(patterns))
        , m_flags(0)
    {}
#ifdef STLSOFT_COMPILER_IS_GCC
    virtual ~recls_exception() throw()
    {}
#endif /* STLSOFT_COMPILER_IS_GCC */
private:
    class_type& operator =(class_type const& );
/// @}

/// \name Accessors
/// @{
public:
    /// The recls return code associated with the exception
    recls_rc_t get_rc() const
    {
        return m_rc;
    }
    /// The user-supplied context associated with the exception
    message_string_type get_context() const
    {
        return m_context;
    }
    /// The user-supplied path associated with the exception
    string_type get_path() const
    {
        return m_path;
    }
    /// The user-supplied patterns associated with the exception
    string_type get_patterns() const
    {
        return m_patterns;
    }
    /// The user-supplied flags associated with the exception
    int get_flags() const
    {
        return m_flags;
    }
/// @}

/// \name Implementation
/// @{
private:
    static message_string_type create_message_(recls_rc_t rc)
    {
        return create_message_(rc, NULL, NULL, 0);
    }
    static message_string_type create_message_(
        recls_rc_t          rc
    ,   char const*         /* context */
    ,   recls_char_t const* /* path */
    ,   int                 /* flags */
    )
    {
        recls_char_t const* const   codeString          =   Recls_GetSearchCodeString(rc);
        size_t const                codeStringLength    =   Recls_GetSearchCodeStringLength(rc);

#if defined(RECLS_CHAR_TYPE_IS_CHAR)

        return message_string_type(codeString, codeStringLength);

#elif defined(RECLS_CHAR_TYPE_IS_WCHAR)

        stlsoft::auto_buffer<char>  buffer(1u + codeStringLength);

        size_t  numConverted;
# ifdef RECLS_USING_SAFE_STR_FUNCTIONS
        int     err = ::wcstombs_s(&numConverted, &buffer[0], buffer.size(), codeString, codeStringLength);

        if(0 != err)
# else /* ? RECLS_USING_SAFE_STR_FUNCTIONS */

        numConverted = ::wcstombs(buffer.data(), codeString, buffer.size());

        if(~size_t(0) == numConverted)
# endif /* RECLS_USING_SAFE_STR_FUNCTIONS */
        {
            numConverted = 0;
        }

        return message_string_type(buffer.data(), numConverted);

#else /* ? RECLS_CHAR_TYPE_IS_??? */
# error RECLS_CHAR_TYPE_IS_CHAR or RECLS_CHAR_TYPE_IS_WCHAR must be defined.
#endif /* RECLS_CHAR_TYPE_IS_??? */
    }
/// @}

/// \name Members
/// @{
private:
    recls_rc_t const          m_rc;
    message_string_type const m_context;
    string_type const         m_path;
    string_type const         m_patterns;
    int const                 m_flags;
/// @}
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace cpp */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_CPP_HPP_EXCEPTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
