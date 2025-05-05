/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.fileinfo.windows.cpp
 *
 * Purpose: Windows implementation for the file information blocks of
 *          recls API.
 *
 * Created: 16th August 2003
 * Updated: 5th May 2025
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
#include "impl.assert.h"
#include "impl.root.h"
#include "incl.winstl.h"
#include "impl.util.h"
#include "impl.atomic.hpp"

#include "impl.trace.h"

#if defined(RECLS_MT)
# include <winstl/synch/atomic_functions.h>
#endif /* RECLS_MT */


/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifdef RECLS_ATOMIC_USE_std_atomic_
# error This file cannot be built with C++14 or later
#endif // RECLS_ATOMIC_USE_std_atomic_


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
 * internal API
 */

void
RC_Increment(
    rc_atomic_ref_t p
)
{
#if defined(RECLS_MT)

    winstl::atomic_increment(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(&p)));
#else /* ? RECLS_MT */

    ++p;
#endif /* RECLS_MT */
}

rc_atomic_v_t
RC_PreDecrement(
    rc_atomic_ref_t p
)
{
#if defined(RECLS_MT)

    return winstl::atomic_predecrement(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(&p)));
#else /* ? RECLS_MT */

    return --p;
#endif /* RECLS_MT */
}

rc_atomic_v_t
RC_ReadValue(
    rc_atomic_ref_t p
)
{
#if defined(RECLS_MT)

    return winstl::atomic_read(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(&p)));
#else /* ? RECLS_MT */

    return p;
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

