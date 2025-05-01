/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearchDirectoryControlAlwaysAllow.cpp
 *
 * Purpose: Implementation of the ReclsFileSearchDirectoryControlAlwaysAllow.
 *
 * Created: 1st May 2025
 * Updated: 1st May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
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
// #include "impl.assert.h"
// #include "impl.root.h"
// #include "impl.util.h"
// #include "impl.string.hpp"

#include "ReclsFileSearch.hpp"
#include "ReclsFileSearchDirectoryControlAlwaysAllow.hpp"

#include "impl.trace.h"

#include <ctype.h>
#include <stdio.h>


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
 * utility functions
 */


/* /////////////////////////////////////////////////////////////////////////
 * ReclsFileSearchDirectoryControlAlwaysAllow
 */

ReclsFileSearchDirectoryControlAlwaysAllow::ReclsFileSearchDirectoryControlAlwaysAllow(
    recls_uint32_t  flags
)
    : m_flags(flags)
{
}

ReclsFileSearchDirectoryControlAlwaysAllow::~ReclsFileSearchDirectoryControlAlwaysAllow() STLSOFT_NOEXCEPT
{}

/* virtual */
bool
ReclsFileSearchDirectoryControlAlwaysAllow::CanProcessDirectory(
    char_type const*         /* directoryPath */
,   stat_data_type const*    /* psd */
)
{
    return true;
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

