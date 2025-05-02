/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearch.hpp
 *
 * Purpose: Definition of the ReclsFileSearch class.
 *
 * Created: 31st May 2004
 * Updated: 1st May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
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

#include <recls/recls.h>
#include "ReclsSearch.hpp"

#include "impl.types.hpp"
#include "incl.stlsoft.h"


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
 * forward declarations
 */

class ReclsFileSearchDirectoryNode;
class ReclsSearchDirectoryControl;


/* /////////////////////////////////////////////////////////////////////////
 * interfaces
 */

// class ReclsSearchDirectoryControl
/// Interface for controlling how (and whether) directories are to be
/// traversed.
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsSearchDirectoryControl
{
public: // types
    typedef ReclsSearchDirectoryControl                     class_type;
    typedef recls_char_t                                    char_type;
    typedef types::traits_type::stat_data_type              stat_data_type;
private:

public: // construction
    /// Destructor
    ///
    /// ReclsSearchDirectoryControl instances are <b>not</b>
    /// reference-counted, but are deleted by their owner. They are
    /// non-shareable.
    virtual ~ReclsSearchDirectoryControl() = 0;

public: // operations
    virtual bool CanProcessDirectory(
        char_type const*        directoryPath
    ,   stat_data_type const*   psd
    ) = 0;
};

inline ReclsSearchDirectoryControl::~ReclsSearchDirectoryControl()
{}


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class ReclsFileSearch
/// Info structure for doing filesystem searches
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsFileSearch
    : public ReclsSearch
{
public: // types
    typedef ReclsFileSearch                                 class_type;
    typedef recls_char_t                                    char_type;
private:

private: // allocation
    void*
    operator new(
        size_t  cb
    ,   size_t  cDirParts
    ,   size_t  cbRootDir
    ,   size_t  cbPatterns
    );
#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
    void
    operator delete(
        void*   pv
    ,   size_t  cDirParts
    ,   size_t  cbRootDir
    ,   size_t  cbPatterns
    );
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */
public:
    void operator delete(void* pv);

protected: // construction
    ReclsFileSearch(
        size_t                      cDirParts
    ,   char_type const*            searchDir
    ,   size_t                      searchDirLen
    ,   char_type const*            patterns
    ,   size_t                      patternsLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_progress_fn_param_t   param
    ,   recls_uint32_t              flags
    ,   recls_rc_t*                 prc
    );
    ~ReclsFileSearch() STLSOFT_NOEXCEPT;
public:
    // TBC
    //
    // \param searchDir Search directory. May not be NULL
    // \param searchDirLen Number of elements in \c searchDir
    // \param patterns Search pattern(s). May not be NULL
    // \param patternsLen Number of elements in \c patterns
    // \param flags Flags to control the search
    // \param pfn Progress callback function
    // \param param Progress callback function parameter
    // \param ppsi Out-parameter to receive the instance obtained upon success
    //
    // \pre nullptr != searchDir
    // \pre len(searchDir) == searchDir
    // \pre types::traits_type::is_path_absolute(searchDir, searchDirLen)
    //
    // \pre nullptr != patterns
    // \pre len(patterns) == patternsLen
    static
    recls_rc_t
    FindAndCreate(
        char_type const*            searchDir
    ,   size_t                      searchDirLen
    ,   char_type const*            patterns
    ,   size_t                      patternsLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_progress_fn_param_t   param
    ,   class_type**                ppsi
    );
private:
    ReclsFileSearch(class_type const &);    // copy-construction proscribed
    void operator =(class_type const &);    // copy-assignment proscribed
public:

private: // implementation
    ReclsSearchDirectoryControl*
    create_dc_(
        recls_uint32_t      flags
    );
    char_type const*
    emplace_patterns_(
        size_t              cDirParts
    ,   size_t              searchDirLen
    ,   char_type const*    patterns
    ,   size_t              patternsLen
    );
    char_type const*
    emplace_rootDir_(
        size_t              cDirParts
    ,   char_type const*    searchDir
    ,   size_t              searchDirLen
    );

    static
    recls_rc_t
    FindAndCreate_(
        char_type const*            searchDir
    ,   size_t                      searchDirLen
    ,   char_type const*            patterns
    ,   size_t                      patternsLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_progress_fn_param_t   param
    ,   class_type**                ppsi
    );

private: // fields
    recls_uint32_t                      m_flags;
    ReclsSearchDirectoryControl* const  m_dc;
    char_type const* const              m_searchDir;
    size_t const                        m_searchDirLen;
    char_type const* const              m_patterns;
    size_t const                        m_patternsLen;
    hrecls_progress_fn_t const          m_pfn;
    recls_progress_fn_param_t const     m_param;

    /** The opaque data of the search */
    recls_byte_t                        data[1];
    /*
     * The data comprises:
     *
     *  - root dir;
     *  - directory parts;
     *  - patterns;
     *  - <padding>;
     *  - `ReclsFileSearch` instance data;
     */
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

