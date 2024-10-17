/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearch.hpp
 *
 * Purpose: Definition of the ReclsFileSearch class.
 *
 * Created: 31st May 2004
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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

// Allocation
private:
    void* operator new(size_t cb, size_t cDirParts, size_t cbRootDir);
#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
    void operator delete(void* pv, size_t cDirParts, size_t cbRootDir);
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */
public:
    void operator delete(void* pv);

// Construction
protected:
    ReclsFileSearch(
        size_t                      cDirParts
    ,   recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   recls_uint32_t              flags
    ,   recls_rc_t*                 prc
    );
    ~ReclsFileSearch() STLSOFT_NOEXCEPT;
public:
    // TBC
    //
    // \param searchDir Search directory
    // \param searchDirLen Number of elements in \c searchDir
    // \param pattern Search pattern
    // \param patternLen Number of elements in \c pattern
    // \param flags Flags to control the search
    // \param pfn Progress callback function
    // \param param Progress callback function parameter
    // \param ppsi Out-parameter to receive the instance obtained upon success
    //
    // \pre nullptr != searchDir
    // \pre len(searchDir) == searchDir
    // \pre types::traits_type::is_path_absolute(searchDir, searchDirLen)
    //
    // \pre nullptr != pattern
    // \pre len(patternDir) == pattern
    static
    recls_rc_t
    FindAndCreate(
        recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );
private:
    ReclsFileSearch(class_type const &);    // copy-construction proscribed
    void operator =(class_type const &);    // copy-assignment proscribed
public:

private: // implementation
    recls_char_t const*
    calc_rootDir_(
        size_t              cDirParts
    ,   recls_char_t const* searchDir
    ,   size_t              searchDirLen
    );

    static
    recls_rc_t
    FindAndCreate_(
        recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );

private: // fields
    recls_uint32_t                  m_flags;
    recls_char_t const* const       m_searchDir;
    size_t const                    m_searchDirLen;
    hrecls_progress_fn_t const      m_pfn;
    recls_process_fn_param_t const  m_param;

    /** The opaque data of the search */
    recls_byte_t                    data[1];
    /*
     * The data comprises:
     *
     *  - root dir
     *
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

