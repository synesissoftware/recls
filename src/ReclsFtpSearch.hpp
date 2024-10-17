/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFtpSearch.hpp
 *
 * Purpose: Definition of the ReclsFtpSearch class.
 *
 * Created: 31st May 2004
 * Updated: 30th December 2023
 *
 * Home:    https://github.com/synesissoftware/recls
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

#include <inetstl/inetstl.h>

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

class ReclsFtpSearchDirectoryNode;

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class ReclsFtpSearch
/// Info structure for doing filesystem searches
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsFtpSearch
    : public ReclsSearch
{
public:
    typedef ReclsFtpSearch  class_type;

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
    ReclsFtpSearch(
        HINTERNET           hSess
    ,   HINTERNET           hConn
    ,   size_t              cDirParts
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_char_t const* pattern
    ,   size_t              patternLen
    ,   recls_uint32_t      flags
    );
    ~ReclsFtpSearch();
public:
    static
    recls_rc_t
    FindAndCreate(
        recls_char_t const* host
    ,   recls_char_t const* username
    ,   recls_char_t const* password
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    ,   recls_char_t const* pattern
    ,   size_t              patternLen
    ,   recls_uint32_t      flags
    ,   class_type**        ppsi
    );
private:
    ReclsFtpSearch(class_type const &);     // copy-construction proscribed
    void operator =(class_type const &);    // copy-assignment proscribed

// Implementation
private:
    recls_char_t const*
    calc_rootDir_(
        size_t              cDirParts
    ,   recls_char_t const* rootDir
    ,   size_t              rootDirLen
    );

// Members
private:
    HINTERNET const             m_session;
    HINTERNET const             m_connection;
    recls_uint32_t              m_flags;
    recls_char_t const* const   m_rootDir;

    /** The opaque data of the search */
    recls_byte_t                data[1];
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

