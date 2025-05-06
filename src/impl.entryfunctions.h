/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.entryfunctions.h
 *
 * Purpose: Utility functions for recls API.
 *
 * Created: 31st May 2004
 * Updated: 5th May 2025
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


#ifndef RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS
#define RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.h>
#include "impl.root.h"


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
 * functions
 */

/** Allocates an entry of the given size. */
RECLS_FNDECL(recls_entry_t)
Entry_Allocate(
    size_t cb
);

/** Releases an entry. */
RECLS_FNDECL(void)
Entry_Release(
    recls_entry_t fileInfo
);

/** Copies an entry. */
RECLS_API
Entry_Copy(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
);


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */


/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

