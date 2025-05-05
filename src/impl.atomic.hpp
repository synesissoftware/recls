/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.atomic.hpp
 *
 * Purpose: Implementation header.
 *
 * Created: 11th March 2005
 * Updated: 5th May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_H_IMPL_ATOMIC
#define RECLS_INCL_SRC_H_IMPL_ATOMIC

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.h>
#include "impl.root.h"
#include "incl.platformstl.h"

#include <platformstl/synch/util/features.h>
#ifdef PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS
# include <platformstl/synch/atomic_functions.h>
#endif /* PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS */


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
 * typedefs
 */

#if 1 &&\
    defined(RECLS_PLATFORM_IS_UNIX) &&\
    defined(RECLS_MT) && \
    defined(RECLS_UNIX_USE_ATOMIC_OPERATIONS) &&\
    1

typedef atomic_t                                            rc_atomic_t;
# define rc_atomic_init(x)                                  ATOMIC_INIT(x)
#elif defined(PLATFORMSTL_HAS_ATOMIC_INTEGER_OPERATIONS)

typedef platformstl_ns_qual(atomic_int_t)                   rc_atomic_t;
# define rc_atomic_init(x)                                  x
#else /* ? RECLS_MT && RECLS_UNIX_USE_ATOMIC_OPERATIONS */

typedef int                                                 rc_atomic_t;
# define rc_atomic_init(x)                                  x
#endif /* RECLS_MT && RECLS_UNIX_USE_ATOMIC_OPERATIONS */

typedef rc_atomic_t volatile&                               rc_atomic_ref_t;


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

void
RC_Increment(
    rc_atomic_ref_t p
);

rc_atomic_t
RC_PreDecrement(
    rc_atomic_ref_t p
);

rc_atomic_t
RC_ReadValue(
    rc_atomic_ref_t p
);

/** Returns the block count of an entry. */
void
Entry_BlockCount(
    rc_atomic_ref_t cCreated
,   rc_atomic_ref_t cShared
);


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#endif /* !RECLS_INCL_SRC_H_IMPL_ATOMIC */

/* ///////////////////////////// end of file //////////////////////////// */

