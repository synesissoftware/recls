/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.entryfunctions.h
 *
 * Purpose: Utility functions for recls API.
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


#ifndef RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS
#define RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.h>
#include "impl.root.h"
#include "impl.atomic.h"

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

/** Returns the block count of an entry. */
RECLS_FNDECL(void)
Entry_BlockCount(
    rc_atomic_t*    pcCreated
,   rc_atomic_t*    pcShared
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

