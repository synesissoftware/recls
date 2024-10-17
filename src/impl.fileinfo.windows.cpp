/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.fileinfo.windows.cpp
 *
 * Purpose: Windows implementation for the file information blocks of
 *          recls API.
 *
 * Created: 16th August 2003
 * Updated: 16th October 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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
#include "incl.winstl.h"
#include "impl.atomic.h"

#include "impl.trace.h"

#if defined(RECLS_MT)
# include <winstl/synch/atomic_functions.h>
#endif /* RECLS_MT */


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

RECLS_FNDECL(void)
RC_Increment(
    rc_atomic_t volatile *p
)
{
#if defined(RECLS_MT)

    winstl::atomic_increment(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(p)));
#else /* ? RECLS_MT */

    ++*p;
#endif /* RECLS_MT */
}

RECLS_FNDECL(rc_atomic_t)
RC_PreDecrement(
    rc_atomic_t volatile *p
)
{
#if defined(RECLS_MT)

    return winstl::atomic_predecrement(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(p)));
#else /* ? RECLS_MT */

    return --*p;
#endif /* RECLS_MT */
}

RECLS_FNDECL(rc_atomic_t)
RC_ReadValue(
    rc_atomic_t volatile *p
)
{
#if defined(RECLS_MT)

    return winstl::atomic_read(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(p)));
#else /* ? RECLS_MT */

    return *p;
#endif /* RECLS_MT */
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

