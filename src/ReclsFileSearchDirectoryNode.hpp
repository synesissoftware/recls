/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearchDirectoryNode.hpp
 *
 * Purpose:     ReclsFileSearchDirectoryNode class.
 *
 * Created:     31st May 2004
 * Updated:     24th December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

// recls includes
#include <recls/recls.h>
#include "impl.root.h"
#include "impl.types.hpp"
#include "impl.util.h"

// Platform-specific includes
#include <platformstl/platformstl.h>

#if defined(RECLS_PLATFORM_IS_UNIX)

# include <unixstl/filesystem/glob_sequence.hpp>
# include <unixstl/filesystem/readdir_sequence.hpp>

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

# include <winstl/filesystem/findfile_sequence.hpp>

#else /* unrecognised platform */

# error The platform is not recognised. Only RECLS_PLATFORM_IS_UNIX or RECLS_PLATFORM_IS_WINDOWS currently supported

#endif /* platform */

// STLSoft includes
#ifdef RECLS_SUPPORTS_MULTIPATTERN_
# if !defined(RECLS_PLATFORM_IS_WINDOWS) || \
     !defined(WINSTL_VER_WINSTL_HPP_FINDFILE_SEQUENCE_MAJOR) || \
     WINSTL_VER_WINSTL_HPP_FINDFILE_SEQUENCE_MAJOR < 3
#  define RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_
#  include <stlsoft/filesystem/searchspec_sequence.hpp>
# endif /* stlsoft::findfile_sequence version */
#endif /* RECLS_SUPPORTS_MULTIPATTERN_ */

#include "ReclsSearch.hpp"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

class ReclsFileSearchDirectoryNode
    : public ReclsSearchDirectoryNode
{
public:
    typedef ReclsFileSearchDirectoryNode                    class_type;
    typedef types::path_buffer_type                         path_buffer_type;
    typedef types::string_type                              string_type;
private:

    /// The file entry search type
#if defined(RECLS_PLATFORM_IS_UNIX)
    typedef unixstl::glob_sequence                          file_find_sequence_type;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    typedef winstl::basic_findfile_sequence<
        recls_char_t
    ,   types::traits_type
    >                                                       file_find_sequence_type;
#endif /* platform */

    /// The directory search type
#if defined(RECLS_PLATFORM_IS_UNIX)
    typedef unixstl::readdir_sequence                       directory_sequence_type;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    typedef file_find_sequence_type                         directory_sequence_type;
#endif /* platform */

    /// The file entry search type
#ifdef RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_
    typedef stlsoft::searchspec_sequence<
        file_find_sequence_type
    >                                                       entry_sequence_type;
#else /* ? RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_ */
    typedef file_find_sequence_type                         entry_sequence_type;
#endif /* RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_ */

// Construction
protected: // Not private, or GCC whines
    ReclsFileSearchDirectoryNode(
        recls_uint32_t              flags
    ,   recls_char_t const*         rootDir
    ,   size_t                      rootDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    );
public:
    virtual ~ReclsFileSearchDirectoryNode();
private:
    ReclsFileSearchDirectoryNode(class_type const &);   // copy-construction proscribed
    void operator =(class_type const &);                // copy-assignment proscribed
public:

    static
    class_type*
    FindAndCreate(
        recls_uint32_t              flags
    ,   recls_char_t const*         rootDir
    ,   size_t                      rootDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   recls_rc_t*                 prc
    );

    //
    //
    // \pre nullptr != path
    // \pre strlen(path) == pathLen
    // \pre path has correct slashes
    // \pre path does not have a trailing slash
    static
    recls_rc_t
    Stat(
        recls_char_t const* path
    ,   size_t              pathLen
    ,   recls_uint32_t      flags
    ,   recls_entry_t*      phEntry
    );

// ReclsSearchDirectoryNode methods
private:
    /* virtual */ recls_rc_t GetNext();
    /* virtual */ recls_rc_t GetDetails(recls_entry_t* pinfo);
    /* virtual */ recls_rc_t GetNextDetails(recls_entry_t* pinfo);

// Implementation
private:
    recls_rc_t      Initialise();

#ifdef RECLS_ENFORCING_CONTRACTS
    recls_bool_t    is_valid() const;
#endif /* RECLS_ENFORCING_CONTRACTS */

    /// Translates the recls flags into the entry sequence flags
    static
    int
    essFlags_from_reclsFlags_(
        recls_uint32_t flags
    );
    /// Translates the recls flags into the directory sequence flags
    static
    int
    dssFlags_from_reclsFlags_(
        recls_uint32_t flags
    );
    /// Selects one or the other iterator, depending on the truth of b
    ///
    /// \note This is necessary because Borland seems not to like the tertiary
    /// operator in the member initialiser list (MIL)
    static
    directory_sequence_type::const_iterator
    select_iter_if_(
        unsigned long                           b
    ,   directory_sequence_type::const_iterator trueVal
    ,   directory_sequence_type::const_iterator falseVal
    );

    /// Creates a path-buffer from the given search directory, ensuring that
    /// it has a trailing path-name separator
    static
    path_buffer_type
    prepare_searchDir_(
        recls_char_t const*     searchDir
    );

    static
    recls_entry_t
    CreateEntryInfo(
        size_t                              rootDirLen
    ,   recls_char_t const*                 searchDir
    ,   size_t                              searchDirLen
    ,   recls_uint32_t                      flags
    ,   entry_sequence_type::const_iterator it
    );

// Members
private:
    recls_entry_t                           m_current;
    class_type*                             m_dnode;
    recls_uint32_t const                    m_flags;
    size_t const                            m_rootDirLen;
    path_buffer_type const                  m_searchDir;
    string_type const                       m_pattern;
    size_t const                            m_patternLen;
    directory_sequence_type                 m_directories;
    directory_sequence_type::const_iterator m_directoriesBegin;
    entry_sequence_type                     m_entries;
    entry_sequence_type::const_iterator     m_entriesBegin;
    hrecls_progress_fn_t const              m_pfn;
    recls_process_fn_param_t const          m_param;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

