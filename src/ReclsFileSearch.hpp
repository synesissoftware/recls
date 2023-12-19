/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearch.hpp
 *
 * Purpose:     Definition of the ReclsFileSearch class.
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
public:
    typedef ReclsFileSearch class_type;

// Allocation
private:
    void *operator new(size_t cb, size_t cDirParts, size_t cbRootDir);
#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
    void operator delete(void* pv, size_t cDirParts, size_t cbRootDir);
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */
public:
    void operator delete(void* pv);

// Construction
protected:
    ReclsFileSearch(size_t                      cDirParts
                ,   recls_char_t const*         rootDir
                ,   size_t                      rootDirLen
                ,   recls_char_t const*         pattern
                ,   size_t                      patternLen
                ,   hrecls_progress_fn_t        pfn
                ,   recls_process_fn_param_t    param
                ,   recls_uint32_t              flags
                ,   recls_rc_t*                 prc
                );
    ~ReclsFileSearch();
public:
    static recls_rc_t FindAndCreate(
        recls_char_t const*         rootDir
    ,   size_t                      rootDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );

    static recls_rc_t Stat(
        recls_char_t const* path
    ,   recls_uint32_t      flags
    ,   recls_entry_t*      phEntry
    );

// Implementation
private:
    recls_char_t const* calc_rootDir_(
        size_t              cDirParts
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    );

    static recls_rc_t FindAndCreate_(
        recls_char_t const*         rootDir
    ,   size_t                      rootDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );


// Members
private:
    recls_uint32_t                  m_flags;
    recls_char_t const* const       m_rootDir;
    const size_t                    m_rootDirLen;
    const hrecls_progress_fn_t      m_pfn;
    const recls_process_fn_param_t  m_param;

    /** The opaque data of the search */
    recls_byte_t                    data[1];
    /*
     * The data comprises:
     *
     *  - root dir
     *
     */

// Not to be implemented
private:
    ReclsFileSearch(class_type const &);
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
