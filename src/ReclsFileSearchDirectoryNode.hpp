/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearchDirectoryNode.hpp
 *
 * Purpose:     ReclsFileSearchDirectoryNode class.
 *
 * Created:     31st May 2004
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
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
    typedef ReclsFileSearchDirectoryNode                                        class_type;
    typedef types::file_path_buffer_type                                        file_path_buffer_type;
    typedef types::string_type                                                  string_type;
private:

    /// The file entry search type
#if defined(RECLS_PLATFORM_IS_UNIX)
    typedef unixstl::glob_sequence                                              file_find_sequence_type;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    typedef winstl::basic_findfile_sequence<recls_char_t, types::traits_type>   file_find_sequence_type;
#endif /* platform */

    /// The directory search type
#if defined(RECLS_PLATFORM_IS_UNIX)
    typedef unixstl::readdir_sequence                                           directory_sequence_type;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    typedef file_find_sequence_type                                             directory_sequence_type;
#endif /* platform */

    /// The file entry search type
#ifdef RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_
    typedef stlsoft::searchspec_sequence<file_find_sequence_type>               entry_sequence_type;
#else /* ? RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_ */
    typedef file_find_sequence_type                                             entry_sequence_type;
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

    static class_type* FindAndCreate(
        recls_uint32_t              flags
    ,   recls_char_t const*         rootDir
    ,   size_t                      rootDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   recls_rc_t*                 prc
    );

    static recls_rc_t Stat(
        recls_char_t const* path
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
    static int essFlags_from_reclsFlags_(recls_uint32_t flags);
    /// Translates the recls flags into the directory sequence flags
    static int dssFlags_from_reclsFlags_(recls_uint32_t flags);
    /// Selects one or the other iterator, depending on the truth of b
    ///
    /// \note This is necessary because Borland seems not to like the tertiary
    /// operator in the member initialiser list (MIL)
    static directory_sequence_type::const_iterator select_iter_if_( unsigned long                           b
                                                                ,   directory_sequence_type::const_iterator trueVal
                                                                ,   directory_sequence_type::const_iterator falseVal);

    /// Copies searchDir to buff, ensuring it has a trailing path name
    /// separator, and returns the precise length of the resultant string
    static size_t prepare_searchDir_(file_path_buffer_type &buff, recls_char_t const* searchDir);

    static recls_entry_t    CreateEntryInfo(size_t                              rootDirLen
                                        ,   recls_char_t const                  *searchDir
                                        ,   size_t                              searchDirLen
                                        ,   recls_uint32_t                      flags
                                        ,   entry_sequence_type::const_iterator it);

// Members
private:
    recls_entry_t                           m_current;
    class_type*                             m_dnode;
    const recls_uint32_t                    m_flags;
    const size_t                            m_rootDirLen;
    file_path_buffer_type                   m_searchDir;
    const size_t                            m_searchDirLen;
    const string_type                       m_pattern;
    const size_t                            m_patternLen;
    directory_sequence_type                 m_directories;
    directory_sequence_type::const_iterator m_directoriesBegin;
    entry_sequence_type                     m_entries;
    entry_sequence_type::const_iterator     m_entriesBegin;
    const hrecls_progress_fn_t              m_pfn;
    const recls_process_fn_param_t          m_param;

// Not to be implemented
private:
    ReclsFileSearchDirectoryNode(class_type const &);
    class_type &operator =(class_type const &);
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

