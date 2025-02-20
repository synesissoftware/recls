/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.trace.cpp
 *
 * Purpose: Tracing.
 *
 * Created: 30th September 2003
 * Updated: 20th February 2025
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

/* recls header files */
#include <recls/recls.h>
#include <recls/assert.h>
#include "incl.platformstl.h"
#include "impl.trace.h"
#include "impl.util.h"

/* STLSoft / platform-specific header files */
#include <stlsoft/internal/safestr.h>
#if defined(RECLS_PLATFORM_IS_UNIX)
# include <stlsoft/error/errno_scope.hpp>
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# ifdef RECLS_STLSOFT_1_12_OR_LATER
#  include <winstl/diagnostics/last_error_scope.hpp>
# else /* ? RECLS_STLSOFT_1_12_OR_LATER */
#  include <winstl/error/last_error_scope.hpp>
# endif /* RECLS_STLSOFT_1_12_OR_LATER */
#else /* ? platform */
# error Unrecognised platform
#endif /* platform */

/* Standard C header files */
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * Statics & globals
 */

namespace
{
#if !defined(RECLS_NO_NAMESPACE)
    using recls::recls_char_t;
    using recls::recls_log_pfn_t;
    using recls::impl::recls_snprintf;
    using recls::impl::recls_vsnprintf;
#endif /* !RECLS_NO_NAMESPACE */

    int const fatalSeverity_DEFAULT         = 1;
    int const errorSeverity_DEFAULT         = 4;
    int const warningSeverity_DEFAULT       = 5;
    int const informationalSeverity_DEFAULT = 7;
    int const debug0Severity_DEFAULT        = 8;
    int const debug1Severity_DEFAULT        = 9;
    int const debug2Severity_DEFAULT        = -1;
    int const debug3Severity_DEFAULT        = -1;


#if defined(RECLS_DEBUG) && \
    (   defined(RECLS_PLATFORM_IS_WINDOWS) || \
        (   defined(RECLS_PLATFORM_IS_UNIX) && \
            defined(_WIN32)))

    void RECLS_CALLCONV_DEFAULT default_debug_log_fn_(
        int                 severity
    ,   recls_char_t const* fmt
    ,   va_list             args
    )
    {
        recls_char_t    message[1001];
        int             n1;
        int             n2;
        int             n;

        if (0 == (severity & 0x0f))
        {
            // treat it as a number

            n1 = recls_snprintf(&message[0]
                        ,   STLSOFT_NUM_ELEMENTS(message) - 2
                        ,   RECLS_LITERAL("%-2d: "), severity);
        }
        else
        {
            // treat it as a set of flags

            n1 = recls_snprintf(&message[0]
                        ,   STLSOFT_NUM_ELEMENTS(message) - 2
                        ,   RECLS_LITERAL("0x%-16x: "), severity);
        }

        n2 = recls_vsnprintf(&message[0] + n1
                        ,   STLSOFT_NUM_ELEMENTS(message) - 2 - n1
                        ,   fmt, args);

        if (n2 < 0)
        {
            n2 = static_cast<int>(STLSOFT_NUM_ELEMENTS(message)) - 2 - n1;
        }

        n = n1 + n2;

        RECLS_ASSERT(n <= int(STLSOFT_NUM_ELEMENTS(message)) - 2);

        message[n + 0] = '\n';
        message[n + 1] = '\0';

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
        OutputDebugStringW(message);
#else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
        OutputDebugStringA(message);
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */
    }

    static recls_log_pfn_t  s_loggingFunction   =   default_debug_log_fn_;
#else /* ? OS */
    static recls_log_pfn_t  s_loggingFunction   =   ss_nullptr_k;
#endif /* OS */
    static int              s_severities[12]     =
    {
        -12345678
    ,   fatalSeverity_DEFAULT
    ,   -12345678
    ,   -12345678
    ,   errorSeverity_DEFAULT
    ,   warningSeverity_DEFAULT
    ,   -12345678
    ,   informationalSeverity_DEFAULT
    ,   debug0Severity_DEFAULT
    ,   debug1Severity_DEFAULT
    ,   debug2Severity_DEFAULT
    ,   debug3Severity_DEFAULT
    };
    static int              s_flags             =   0;

#if 0
#elif defined(__cplusplus) && \
      (   __cplusplus >= 201103L || \
          defined(STLSOFT_CF_static_assert_SUPPORT))

    static_assert(RECLS_SEVIX_UNKNOWN >= 0, "cannot be negative");
    static_assert(RECLS_SEVIX_DBG3 < STLSOFT_NUM_ELEMENTS(s_severities), "constant too large for severities array");
#endif /* __cplusplus */

} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * API
 */

RECLS_FNDECL(void)
Recls_LogSeverities_Init(
    recls_log_severities_t*         severities
,   int                             fatalSeverity
,   int                             errorSeverity
,   int                             warningSeverity
,   int                             informationalSeverity
,   int                             debug0Severity
,   int                             debug1Severity
,   int                             debug2Severity
,   int                             debug3Severity
)
{
    RECLS_ASSERT(ss_nullptr_k != severities);

    severities->severities[0]   =   fatalSeverity;
    severities->severities[1]   =   errorSeverity;
    severities->severities[2]   =   warningSeverity;
    severities->severities[3]   =   informationalSeverity;
    severities->severities[4]   =   debug0Severity;
    severities->severities[5]   =   debug1Severity;
    severities->severities[6]   =   debug2Severity;
    severities->severities[7]   =   debug3Severity;
}

RECLS_FNDECL(void)
Recls_SetApiLogFunction(
    recls_log_pfn_t               pfn
,   int                           flags
,   recls_log_severities_t const* severities
)
{
    RECLS_ASSERT((ss_nullptr_k == severities) || (ss_nullptr_k != pfn));

    s_loggingFunction   =   pfn;
    s_flags             =   flags;
    if (ss_nullptr_k == severities)
    {
        s_severities[RECLS_SEVIX_FATAL]   =   fatalSeverity_DEFAULT;
        s_severities[RECLS_SEVIX_ERROR]   =   errorSeverity_DEFAULT;
        s_severities[RECLS_SEVIX_WARN]    =   warningSeverity_DEFAULT;
        s_severities[RECLS_SEVIX_INFO]    =   informationalSeverity_DEFAULT;
        s_severities[RECLS_SEVIX_DBG0]    =   debug0Severity_DEFAULT;
        s_severities[RECLS_SEVIX_DBG1]    =   debug1Severity_DEFAULT;
        s_severities[RECLS_SEVIX_DBG2]    =   debug2Severity_DEFAULT;
        s_severities[RECLS_SEVIX_DBG3]    =   debug3Severity_DEFAULT;
    }
    else
    {
        s_severities[RECLS_SEVIX_FATAL]   =   severities->severities[0];
        s_severities[RECLS_SEVIX_ERROR]   =   severities->severities[1];
        s_severities[RECLS_SEVIX_WARN]    =   severities->severities[2];
        s_severities[RECLS_SEVIX_INFO]    =   severities->severities[3];
        s_severities[RECLS_SEVIX_DBG0]    =   severities->severities[4];
        s_severities[RECLS_SEVIX_DBG1]    =   severities->severities[5];
        s_severities[RECLS_SEVIX_DBG2]    =   severities->severities[6];
        s_severities[RECLS_SEVIX_DBG3]    =   severities->severities[7];
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

#if defined(RECLS_PLATFORM_IS_UNIX)

typedef stlsoft::errno_scope                error_scope_t;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

typedef winstl::last_error_scope            error_scope_t;
#else /* ? platform */

# error Unrecognised platform
#endif /* platform */


/* /////////////////////////////////////////////////////////////////////////
 * recls_????_printf_
 */

static
void
recls_log_vprintf_(
    int                 sevIndex
,   recls_char_t const* fmt
,   va_list             args
)
{
    RECLS_ASSERT(ss_nullptr_k != fmt);

    RECLS_ASSERT(sevIndex >= 0 && sevIndex < int(STLSOFT_NUM_ELEMENTS(s_severities)));

    recls_log_pfn_t const   loggingFunction =   s_loggingFunction;
    int const               severity        =   s_severities[sevIndex % STLSOFT_NUM_ELEMENTS(s_severities)];

    if (severity >= 0 &&
        ss_nullptr_k != loggingFunction)
    {
        (*loggingFunction)(severity, fmt, args);
    }
}

void recls_log_printf_(
    int                 sevIndex
,   recls_char_t const* fmt
,   ...
)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(sevIndex, fmt, args);

    va_end(args);
}

void recls_fatal_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_FATAL, fmt, args);

    va_end(args);
}

void recls_error_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_ERROR, fmt, args);

    va_end(args);
}

void recls_warning_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_WARN, fmt, args);

    va_end(args);
}

void recls_info_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_INFO, fmt, args);

    va_end(args);
}

void recls_debug0_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_DBG0, fmt, args);

    va_end(args);
}

void recls_debug1_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_DBG1, fmt, args);

    va_end(args);
}

void recls_debug2_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_DBG2, fmt, args);

    va_end(args);
}

void recls_debug3_trace_printf_(recls_char_t const* fmt, ...)
{
    va_list args;

    va_start(args, fmt);

    recls_log_vprintf_(RECLS_SEVIX_DBG3, fmt, args);

    va_end(args);
}


/* /////////////////////////////////////////////////////////////////////////
 * function_scope
 */

function_scope::function_scope(
    recls_char_t const* fn
)
    : m_fn(fn)
{
    error_scope_t    error_scope;

    recls_debug2_trace_printf_(RECLS_LITERAL(">> %s()"), m_fn);
}

function_scope::~function_scope() STLSOFT_NOEXCEPT
{
    error_scope_t    error_scope;

    recls_debug2_trace_printf_(RECLS_LITERAL("<< %s()"), m_fn);
}


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

