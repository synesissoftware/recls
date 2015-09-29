/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFtpSearchDirectoryNode_windows.hpp
 *
 * Purpose:     ReclsFtpSearchDirectoryNode class, for Windows.
 *
 * Created:     31st May 2004
 * Updated:     16th January 2010
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2004-2010, Matthew Wilson and Synesis Software
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


/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

// recls includes
#include <recls/recls.h>
#include "impl.util.h"
#include "impl.string.hpp"

// STLSoft includes
#include "incl.stlsoft.h"

// Platform-specific includes
#include <inetstl/inetstl.h>
#include <inetstl/filesystem/filesystem_traits.hpp>
#include <inetstl/filesystem/findfile_sequence.hpp>

// The Dinkumware list implementation causes Visual C++ 7.1 to give C4702 warning, so we don't use it
#if defined(RECLS_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# include <vector>
#else /* ? compiler */
# include <list>
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

class ReclsFtpSearchDirectoryNode
    : public ReclsSearchDirectoryNode
{
public:
    typedef ReclsFtpSearchDirectoryNode                                     class_type;
    typedef inetstl::filesystem_traits<recls_char_t>                        traits_type;
private:
    typedef RECLS_STRING_TEMPLATE_1(recls_char_t)                           string_type;
    typedef inetstl::basic_findfile_sequence<recls_char_t, traits_type>     file_find_sequence_type;
#if defined(RECLS_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
    typedef std::vector<string_type>                                        directory_sequence_type;
#else /* ? compiler */
    typedef std::list<string_type>                                          directory_sequence_type;
#endif /* compiler */
#ifdef RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_
    typedef inetstl::searchspec_sequence<file_find_sequence_type>           entry_sequence_type;
#else /* ? RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_ */
    typedef file_find_sequence_type                                         entry_sequence_type;
#endif /* RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_ */

// Construction
protected: // Not private, or GCC whines
    ReclsFtpSearchDirectoryNode(
        HINTERNET           connection
    ,   recls_uint32_t      flags
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_char_t const* pattern
    ,   size_t              patternLen
    );
public:
    virtual ~ReclsFtpSearchDirectoryNode();

    static class_type *FindAndCreate(
        HINTERNET           connection
    ,   recls_uint32_t      flags
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_char_t const* pattern
    ,   size_t              patternLen
    );

// ReclsSearchDirectoryNode methods
public:
    /* virtual */ recls_rc_t GetNext();
    /* virtual */ recls_rc_t GetDetails(recls_entry_t* pinfo);
    /* virtual */ recls_rc_t GetNextDetails(recls_entry_t* pinfo);

// Implementation
private:
    recls_rc_t      Initialise();

#ifdef RECLS_ENFORCING_CONTRACTS
    recls_bool_t    is_valid() const;
#endif /* RECLS_ENFORCING_CONTRACTS */

    static directory_sequence_type::const_iterator select_iter_if_(
        unsigned long                           b
    ,   directory_sequence_type::const_iterator trueVal
    ,   directory_sequence_type::const_iterator falseVal
    );
    static int essFlags_from_reclsFlags_(recls_uint32_t flags);

// Implementation
private:
    static directory_sequence_type init_directories_(
        HINTERNET           connection
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_uint32_t      flags
    );

// Members
private:
    HINTERNET                               m_connection;
    recls_entry_t                           m_current;
    class_type*                             m_dnode;
    recls_uint32_t const                    m_flags;
    string_type                             m_rootDir;
    string_type                             m_pattern;
    directory_sequence_type                 m_directories;
    directory_sequence_type::const_iterator m_directoriesBegin;
    entry_sequence_type                     m_entries;
    entry_sequence_type::const_iterator     m_entriesBegin;

// Not to be implemented
private:
    ReclsFtpSearchDirectoryNode(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
