/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.fileinfo.cpp
 *
 * Purpose:     Main (platform-independent) implementation file for the recls API.
 *
 * Created:     16th August 2003
 * Updated:     22nd December 2020
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.atomic.h"
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
    volatile rc_atomic_t        rc;
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

volatile rc_atomic_t s_createdInfoBlocks =   rc_atomic_init(0);
volatile rc_atomic_t s_sharedInfoBlocks  =   rc_atomic_init(0);

#if !defined(RECLS_NO_NAMESPACE)
} // anonymous namespace
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

inline struct counted_recls_info_t* counted_info_from_info(recls_entry_t i)
{
    RECLS_ASSERT(i != NULL);

    struct recls_entryinfo_t*   i2  =   const_cast<struct recls_entryinfo_t*>(i);
    recls_byte_t*               i3  =   reinterpret_cast<recls_byte_t*>(i2);

    // can't be bothered with all the C++ casts here!
    return reinterpret_cast<struct counted_recls_info_t*>(i3 - offsetof(counted_recls_info_t, info));
}

inline recls_entry_t info_from_counted_info(struct counted_recls_info_t* ci)
{
    RECLS_ASSERT(ci != NULL);

    return &ci->info;
}

/* /////////////////////////////////////////////////////////////////////////
 * file info functions
 */

RECLS_FNDECL(recls_entry_t) Entry_Allocate(size_t cb)
{
    // Simply allocate a lock-count prior to the main memory (but do it on an 8-byte block)
    counted_recls_info_t*   ci  =   static_cast<counted_recls_info_t*>(malloc(cb - sizeof(struct recls_entryinfo_t) + sizeof(struct counted_recls_info_t)));
    recls_entry_t           info;

    if (NULL == ci)
    {
        info = NULL;
    }
    else
    {
        rc_atomic_t initial = rc_atomic_init(1);

        ci->rc  =   initial; // One initial reference
        info    =   info_from_counted_info(ci);

        RC_Increment(&s_createdInfoBlocks);
    }

    return info;
}

RECLS_FNDECL(void) Entry_Release(recls_entry_t fileInfo)
{
    if (NULL != fileInfo)
    {
        counted_recls_info_t* pci = counted_info_from_info(fileInfo);

        if (0 == RC_PreDecrement(&pci->rc))
        {
            free(pci);

            RC_PreDecrement(&s_createdInfoBlocks);
        }
        else
        {
            RC_PreDecrement(&s_sharedInfoBlocks);
        }
    }
}

RECLS_API Entry_Copy(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
)
{
    RECLS_ASSERT(NULL != pinfo);

    if (NULL != fileInfo)
    {
        counted_recls_info_t* pci = counted_info_from_info(fileInfo);

#if 0
        recls_trace_printf_(RECLS_LITERAL("Entry_Copy(%p): %s"), fileInfo, fileInfo->path.begin);
#endif /* 0 */

        RC_Increment(&pci->rc);
        RC_Increment(&s_sharedInfoBlocks);
    }

    *pinfo = fileInfo;

    return RECLS_RC_OK;
}

RECLS_FNDECL(void) Entry_BlockCount(
    rc_atomic_t* pcCreated
,   rc_atomic_t* pcShared
)
{
    RECLS_ASSERT(NULL != pcCreated);
    RECLS_ASSERT(NULL != pcShared);

    *pcCreated  =   RC_ReadValue(&s_createdInfoBlocks);
    *pcShared   =   RC_ReadValue(&s_sharedInfoBlocks);
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

