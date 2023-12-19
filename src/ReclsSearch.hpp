/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsSearch.hpp
 *
 * Purpose:     Definition of the ReclsSearch and ReclsSearchDirectoryNode classes.
 *
 * Created:     15th August 2003
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_HPP_RECLS_SEARCH
#define RECLS_INCL_HPP_RECLS_SEARCH

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef __cplusplus
# error This file can only be included in C++ compilation units
#endif /* __cplusplus */

#include <recls/recls.h>

/* /////////////////////////////////////////////////////////////////////////
 * Compiler / language features
 *
 * Note: these should be moved out to the compiler-specific files later
 */

#if defined(RECLS_COMPILER_IS_COMO) || \
    defined(RECLS_COMPILER_IS_GCC) || \
    defined(RECLS_COMPILER_IS_INTEL) || \
    (   defined(RECLS_COMPILER_IS_MSVC) && \
        _MSC_VER > 1100) || \
    defined(RECLS_COMPILER_IS_MWERKS)
# define RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
#endif /* compiler */

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
 * interfaces
 */

// class ReclsSearchDirectoryNode
/// Interface for directory nodes
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
struct ReclsSearchDirectoryNode
{
// Construction
public:
    /// Destructor
    ///
    /// ReclsSearchDirectoryNode instances are <b>not</b> reference-counted, but are
    /// deleted by their owner. They are non-shareable.
    virtual ~ReclsSearchDirectoryNode() = 0;

// Operations
public:
    virtual recls_rc_t GetNext() = 0;

    virtual recls_rc_t GetDetails(recls_entry_t* pinfo) = 0;

    virtual recls_rc_t GetNextDetails(recls_entry_t* pinfo) = 0;
};

inline ReclsSearchDirectoryNode::~ReclsSearchDirectoryNode()
{}

// class ReclsSearch
struct ReclsSearch
{
// Construction
protected:
    ReclsSearch();
public:
    /// Destructor
    ///
    /// ReclsSearch instances are <b>not</b> reference-counted, but are
    /// deleted by their owner. They are non-shareable.
    virtual ~ReclsSearch() = 0;

// Operations
public:
    virtual recls_rc_t GetNext();
    virtual recls_rc_t GetDetails(recls_entry_t* pinfo);
    virtual recls_rc_t GetNextDetails(recls_entry_t* pinfo);

// Accessors
public:
    virtual recls_rc_t  GetLastError() const;

// Handle interconversion
public:
    static hrecls_t     ToHandle(ReclsSearch* si);
    static ReclsSearch* FromHandle(hrecls_t h);

// Members
protected:
    // protected data harmful but necessary, since it enables a drop in code size
    ReclsSearchDirectoryNode*   m_dnode;
    recls_rc_t                  m_lastError;
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_HPP_RECLS_SEARCH */

/* ///////////////////////////// end of file //////////////////////////// */
