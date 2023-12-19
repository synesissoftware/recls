/* /////////////////////////////////////////////////////////////////////////
 * File:        api.unix.cpp
 *
 * Purpose:     Windows implementation file for the recls API.
 *
 * Created:     16th August 2003
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "incl.unixstl.h"
#include "impl.string.hpp"
#include "impl.util.h"
#include "impl.cover.h"

#include "impl.trace.h"

#include <sys/types.h>
#include <sys/stat.h>

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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_ASSOCIATE_FILE_WITH_GROUP("recls.core.search")
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * roots
 */

RECLS_LINKAGE_C size_t Recls_GetRoots(  recls_root_t*   roots
                                    ,   size_t          cRoots)
{
    RECLS_COVER_MARK_LINE();

    if(0 < cRoots)
    {
        RECLS_ASSERT(NULL != roots);

        RECLS_COVER_MARK_LINE();

        roots[0].name[0] = '/';
        roots[0].name[1] = '\0';
    }

    return 1;
}

RECLS_LINKAGE_C size_t Recls_GetSelectedRoots(  recls_root_t*   roots
                                            ,   size_t          cRoots
                                            ,   recls_uint32_t  /* flags */)
{
    RECLS_COVER_MARK_LINE();

    return recls::Recls_GetRoots(roots, cRoots);
}

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
