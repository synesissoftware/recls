/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.fileinfo.windows.cpp
 *
 * Purpose:     Windows implementation for the file information blocks of
 *              the recls API.
 *
 * Created:     16th August 2003
 * Updated:     10th January 2017
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2003-2017, Matthew Wilson and Synesis Software
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "incl.winstl.h"
#include "impl.atomic.h"
#include "impl.cover.h"

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

RECLS_FNDECL(void) RC_Increment(rc_atomic_t volatile *p)
{
    RECLS_COVER_MARK_LINE();

#if defined(RECLS_MT)
    winstl::atomic_increment(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(p)));
#else /* ? RECLS_MT */
    ++*p;
#endif /* RECLS_MT */
}

RECLS_FNDECL(rc_atomic_t) RC_PreDecrement(rc_atomic_t volatile *p)
{
    RECLS_COVER_MARK_LINE();

#if defined(RECLS_MT)
    return winstl::atomic_predecrement(static_cast<winstl::atomic_int_t volatile*>(static_cast<void volatile*>(p)));
#else /* ? RECLS_MT */
    return --*p;
#endif /* RECLS_MT */
}

RECLS_FNDECL(rc_atomic_t) RC_ReadValue(rc_atomic_t volatile *p)
{
    RECLS_COVER_MARK_LINE();

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
