/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearchDirectoryControlPreventInfiniteLoops.cpp
 *
 * Purpose: Implementation of the ReclsFileSearchDirectoryControlPreventInfiniteLoops.
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
#include "impl.types.hpp"

#include "ReclsFileSearch.hpp"
#include "ReclsFileSearchDirectoryControlPreventInfiniteLoops.hpp"

#include "impl.trace.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>


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
 * ReclsFileSearchDirectoryControlPreventInfiniteLoops
 */

ReclsFileSearchDirectoryControlPreventInfiniteLoops::ReclsFileSearchDirectoryControlPreventInfiniteLoops(
    recls_uint32_t  flags
)
    : m_flags(flags)
    , m_counts()
{
}

ReclsFileSearchDirectoryControlPreventInfiniteLoops::~ReclsFileSearchDirectoryControlPreventInfiniteLoops() STLSOFT_NOEXCEPT
{}

/* virtual */
bool
ReclsFileSearchDirectoryControlPreventInfiniteLoops::CanProcessDirectory(
    char_type const*        directoryPath
,   stat_data_type const*   psd
)
{
    if (NULL == psd)
    {
        types::traits_type::stat_data_type stat_data;

        if (!types::traits_type::stat(directoryPath, &stat_data))
        {
            recls_warning_trace_printf_(RECLS_LITERAL("skipping directory '%s' because could not invoke `stat()` on it"), directoryPath);

            return false;
        }
        else
        {
            return this->CanProcessDirectory(directoryPath, &stat_data);
        }
    }
    else
    {
        key_type            k   =   { recls_sint64_t(psd->st_dev), recls_sint64_t(psd->st_ino) };
        map_type_::iterator i   =   m_counts.find(k);

        if (m_counts.end() == i)
        {
            m_counts.insert(std::make_pair(k, 1));

            return true;
        }
        else
        {
            ++(*i).second;

            recls_warning_trace_printf_(RECLS_LITERAL("skipping directory '%s' because it has already been visited by another name: dev=%lld, ino=%lld")
            ,   directoryPath
            ,   static_cast<signed long long>(psd->st_dev)
            ,   static_cast<signed long long>(psd->st_ino)
            );

            return false;
        }
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

