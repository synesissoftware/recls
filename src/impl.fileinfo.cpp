/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.fileinfo.cpp
 *
 * Purpose: Main (platform-independent) implementation file for recls API.
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
#include "impl.util.h"
#include "impl.atomic.hpp"
#include "impl.entryfunctions.h"

#include "impl.trace.h"


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

struct counted_recls_info_t
{
#ifdef RECLS_ATOMIC_USE_std_atomic_
    rc_atomic_t                 rc;
#else // ? RECLS_ATOMIC_USE_std_atomic_
    volatile rc_atomic_t        rc;
#endif // RECLS_ATOMIC_USE_std_atomic_
    recls_uint32_t              _;
    struct recls_entryinfo_t    info;
};


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace
{
#endif /* !RECLS_NO_NAMESPACE */

#ifdef RECLS_ATOMIC_USE_std_atomic_

rc_atomic_t s_createdInfoBlocks;
rc_atomic_t s_sharedInfoBlocks;
#else // ? RECLS_ATOMIC_USE_std_atomic_

volatile rc_atomic_t s_createdInfoBlocks =   rc_atomic_init(0);
volatile rc_atomic_t s_sharedInfoBlocks  =   rc_atomic_init(0);
#endif // RECLS_ATOMIC_USE_std_atomic_

#if !defined(RECLS_NO_NAMESPACE)
} // anonymous namespace
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

inline
struct counted_recls_info_t*
counted_info_from_info(recls_entry_t i)
{
    RECLS_ASSERT(i != ss_nullptr_k);

    struct recls_entryinfo_t*   i2  =   const_cast<struct recls_entryinfo_t*>(i);
    recls_byte_t*               i3  =   reinterpret_cast<recls_byte_t*>(i2);

    // can't be bothered with all the C++ casts here!
    return reinterpret_cast<struct counted_recls_info_t*>(i3 - offsetof(counted_recls_info_t, info));
}

inline
recls_entry_t
info_from_counted_info(struct counted_recls_info_t* ci)
{
    RECLS_ASSERT(ci != ss_nullptr_k);

    return &ci->info;
}


/* /////////////////////////////////////////////////////////////////////////
 * file info functions
 */

RECLS_FNDECL(recls_entry_t)
Entry_Allocate(size_t cb)
{
    // Simply allocate a lock-count prior to the main memory (but do it on an 8-byte block)
    counted_recls_info_t*   ci  =   static_cast<counted_recls_info_t*>(malloc(cb - sizeof(struct recls_entryinfo_t) + sizeof(struct counted_recls_info_t)));
    recls_entry_t           info;

    if (ss_nullptr_k == ci)
    {
        info = ss_nullptr_k;
    }
    else
    {
#ifdef RECLS_ATOMIC_USE_std_atomic_

        ci->rc  =   1;
#else // ? RECLS_ATOMIC_USE_std_atomic_

        rc_atomic_t initial = rc_atomic_init(1);

        ci->rc  =   initial; // One initial reference
#endif // RECLS_ATOMIC_USE_std_atomic_
        info    =   info_from_counted_info(ci);

        RC_Increment(s_createdInfoBlocks);
    }

    return info;
}

RECLS_FNDECL(void)
Entry_Release(recls_entry_t fileInfo)
{
    if (ss_nullptr_k != fileInfo)
    {
        counted_recls_info_t* pci = counted_info_from_info(fileInfo);

        if (0 == RC_PreDecrement(pci->rc))
        {
            free(pci);

            RC_PreDecrement(s_createdInfoBlocks);
        }
        else
        {
            RC_PreDecrement(s_sharedInfoBlocks);
        }
    }
}

RECLS_API Entry_Copy(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
)
{
    RECLS_ASSERT(ss_nullptr_k != pinfo);

    if (ss_nullptr_k != fileInfo)
    {
        counted_recls_info_t* pci = counted_info_from_info(fileInfo);

#if 0
        recls_trace_printf_(RECLS_LITERAL("Entry_Copy(%p): %s"), fileInfo, fileInfo->path.begin);
#endif /* 0 */

        RC_Increment(pci->rc);
        RC_Increment(s_sharedInfoBlocks);
    }

    *pinfo = fileInfo;

    return RECLS_RC_OK;
}

void
Entry_BlockCount(
    rc_atomic_ref_t cCreated
,   rc_atomic_ref_t cShared
)
{
    RECLS_ASSERT(ss_nullptr_k != &cCreated);
    RECLS_ASSERT(ss_nullptr_k != &cShared);

#ifdef RECLS_ATOMIC_USE_std_atomic_

    cCreated.store(RC_ReadValue(s_createdInfoBlocks));
    cShared.store(RC_ReadValue(s_sharedInfoBlocks));
#else // ? RECLS_ATOMIC_USE_std_atomic_

    cCreated    =   RC_ReadValue(s_createdInfoBlocks);
    cShared     =   RC_ReadValue(s_sharedInfoBlocks);
#endif // RECLS_ATOMIC_USE_std_atomic_
}


/* /////////////////////////////////////////////////////////////////////////
 * internal API
 */

#ifdef RECLS_ATOMIC_USE_std_atomic_

void
RC_Increment(
    rc_atomic_ref_t p
)
{
    ++p;
}

rc_atomic_v_t
RC_PreDecrement(
    rc_atomic_ref_t p
)
{
    return --p;
}

rc_atomic_v_t
RC_ReadValue(
    rc_atomic_ref_t p
)
{
    return p.load();
}
#endif // RECLS_ATOMIC_USE_std_atomic_


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

