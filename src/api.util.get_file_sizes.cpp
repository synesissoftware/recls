/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.get_file_sizes.cpp
 *
 * Purpose: recls API utility functions.
 *
 * Created: 10th February 2010
 * Updated: 20th February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2010-2019, Matthew Wilson and Synesis Software
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
#include "impl.types.hpp"
#include "impl.util.h"

#include "impl.trace.h"


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeGigaBytes(recls_filesize_t size)
{
    return size / (1024 * 1024 * 1024);
}

RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeMegaBytes(recls_filesize_t size)
{
    return size / (1024 * 1024);
}

RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeKiloBytes(recls_filesize_t size)
{
    return size / (1024);
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

