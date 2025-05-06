/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearchDirectoryControlAlwaysAllow.hpp
 *
 * Purpose: Definition of the ReclsFileSearchDirectoryControlAlwaysAllow class.
 *
 * Created: 1st May 2025
 * Updated: 1st May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2025, Matthew Wilson and Synesis Information Systems
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
 * classes
 */

// class ReclsFileSearchDirectoryControlAlwaysAllow
/// Info structure for doing filesystem searches
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsFileSearchDirectoryControlAlwaysAllow
    : public ReclsSearchDirectoryControl
{
public: // types
    typedef ReclsFileSearchDirectoryControlAlwaysAllow      class_type;
    typedef recls_char_t                                    char_type;
private:

public: // construction
    ReclsFileSearchDirectoryControlAlwaysAllow(
        recls_uint32_t              flags
    );
    ~ReclsFileSearchDirectoryControlAlwaysAllow() STLSOFT_NOEXCEPT;
private:
    ReclsFileSearchDirectoryControlAlwaysAllow(class_type const &); // copy-construction proscribed
    void operator =(class_type const &);                            // copy-assignment proscribed

public:
    virtual bool CanProcessDirectory(
        char_type const*        directoryPath
    ,   stat_data_type const*   psd
    );

private: // fields
    recls_uint32_t const            m_flags;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

