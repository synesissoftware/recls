/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.snprintf.cpp (was $PANTHEIOS_ROOT/src/util/snprintf.c)
 *
 * Purpose:     Implementation file for snprintf() utility functions for
 *              the recls API. (Was borrowed from Pantheios.)
 *
 * Created:     21st June 2005
 * Updated:     10th January 2017
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2005-2017, Matthew Wilson and Synesis Software
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
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.constants.hpp"
#include "impl.cover.h"

/* STLSoft header files */

#include <stlsoft/stlsoft.h>
#include <stlsoft/internal/safestr.h>

/* Standard C header files */

#include <stdarg.h>
#include <stdio.h>

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
 * Compiler / feature discrimination
 *
 * recls_vsnprintf_a_(d, n, f, a)
 * recls_vsnprintf_w_(d, n, f, a)
 *
 * recls_vsnprintf_(d, n, f, a)
 */

#if defined(STLSOFT_COMPILER_IS_DMC) || \
    (   (   defined(WIN32) || \
            defined(WIN64)) && \
        (   defined(STLSOFT_COMPILER_IS_INTEL) || \
            (   defined(STLSOFT_COMPILER_IS_COMO) && \
                defined(_MSC_VER)))) || \
    defined(STLSOFT_COMPILER_IS_MSVC)
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
#  define recls_vsnprintf_a_(d, n, f, a)    _vsnprintf_s((d), (n), _TRUNCATE, (f), (a))
#  define recls_vsnprintf_w_(d, n, f, a)    _vsnwprintf_s((d), (n), _TRUNCATE, (f), (a))
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
#  define recls_vsnprintf_a_(d, n, f, a)    _vsnprintf((d), (n), (f), (a))
#  define recls_vsnprintf_w_(d, n, f, a)    _vsnwprintf((d), (n), (f), (a))
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
#else /* ? compiler */
#  define recls_vsnprintf_a_(d, n, f, a)    vsnprintf((d), (n), (f), (a))
#  define recls_vsnprintf_w_(d, n, f, a)    vsnwprintf((d), (n), (f), (a))
#endif /* compiler */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define recls_vsnprintf_(d, n, f, a)       recls_vsnprintf_w_(d, n, f, a)
#else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
# define recls_vsnprintf_(d, n, f, a)       recls_vsnprintf_a_(d, n, f, a)
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

/* /////////////////////////////////////////////////////////////////////////
 * private API
 */

RECLS_FNDECL(int) recls_vsnprintf_a(
    char*       dest
,   size_t      cchDest
,   char const* fmt
,   va_list     args
)
{
    RECLS_COVER_MARK_LINE();

    return recls_vsnprintf_a_(dest, cchDest, fmt, args);
}

RECLS_FNDECL(int) recls_snprintf_a(
    char*       dest
,   size_t      cchDest
,   const char* fmt
,   ...
)
{
    va_list args;
    int     ret;

    RECLS_COVER_MARK_LINE();

    va_start(args, fmt);

    ret = recls_vsnprintf_a(dest, cchDest, fmt, args);

    va_end(args);

    RECLS_COVER_MARK_LINE();

    return ret;
}

/* /////////////////////////////////////////////////////////////////////////
 * API
 */

RECLS_FNDECL(int) recls_vsnprintf(
    recls_char_t*       dest
,   size_t              cchDest
,   recls_char_t const* fmt
,   va_list             args
)
{
    RECLS_COVER_MARK_LINE();

    return recls_vsnprintf_(dest, cchDest, fmt, args);
}

RECLS_FNDECL(int) recls_snprintf(
    recls_char_t*       dest
,   size_t              cchDest
,   const recls_char_t* fmt
,   ...
)
{
    va_list args;
    int     ret;

    RECLS_COVER_MARK_LINE();

    va_start(args, fmt);

    ret = recls_vsnprintf(dest, cchDest, fmt, args);

    va_end(args);

    RECLS_COVER_MARK_LINE();

    return ret;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
