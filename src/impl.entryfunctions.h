/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.entryfunctions.h
 *
 * Purpose:     Utility functions for the recls API.
 *
 * Created:     31st May 2004
 * Updated:     30th January 2010
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2004-2010, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
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


#ifndef RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS
#define RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* recls Header Files */
#include <recls/recls.h>
#include "impl.root.h"
#include "impl.atomic.h"

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Functions
 */

/** Allocates an entry of the given size. */
RECLS_FNDECL(recls_entry_t) Entry_Allocate(
    size_t cb
);

/** Releases an entry. */
RECLS_FNDECL(void) Entry_Release(
    recls_entry_t fileInfo
);

/** Copies an entry. */
RECLS_API Entry_Copy(
    recls_entry_t   fileInfo
,   recls_entry_t*  pinfo
);

/** Returns the block count of an entry. */
RECLS_FNDECL(void) Entry_BlockCount(
    rc_atomic_t*    pcCreated
,   rc_atomic_t*    pcShared
);

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_IMPL_ENTRYFUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */
