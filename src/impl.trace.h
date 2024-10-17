/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.trace.h
 *
 * Purpose: Tracing.
 *
 * Created: 30th September 2003
 * Updated: 9th July 2024
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


#ifndef RECLS_INCL_SRC_H_IMPL_TRACE
#define RECLS_INCL_SRC_H_IMPL_TRACE


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.h>
#include "impl.root.h"


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
 * recls_trace_printf_
 */

enum recls_sev_index_t_
{
        RECLS_SEVIX_UNKNOWN     =   0
    ,   RECLS_SEVIX_FATAL       =   1
    ,   RECLS_SEVIX_ERROR       =   4
    ,   RECLS_SEVIX_WARN        =   5
    ,   RECLS_SEVIX_INFO        =   7
    ,   RECLS_SEVIX_DBG0        =   8
    ,   RECLS_SEVIX_DBG1        =   9
    ,   RECLS_SEVIX_DBG2        =   10
    ,   RECLS_SEVIX_DBG3        =   11
};
#if !defined(RECLS_NO_NAMESPACE)
# define RECLS_SEVIX_UNKNOWN                                ::recls::impl::RECLS_SEVIX_UNKNOWN
# define RECLS_SEVIX_FATAL                                  ::recls::impl::RECLS_SEVIX_FATAL
# define RECLS_SEVIX_ERROR                                  ::recls::impl::RECLS_SEVIX_ERROR
# define RECLS_SEVIX_WARN                                   ::recls::impl::RECLS_SEVIX_WARN
# define RECLS_SEVIX_INFO                                   ::recls::impl::RECLS_SEVIX_INFO
# define RECLS_SEVIX_DBG0                                   ::recls::impl::RECLS_SEVIX_DBG0
# define RECLS_SEVIX_DBG1                                   ::recls::impl::RECLS_SEVIX_DBG1
# define RECLS_SEVIX_DBG2                                   ::recls::impl::RECLS_SEVIX_DBG2
# define RECLS_SEVIX_DBG3                                   ::recls::impl::RECLS_SEVIX_DBG3
#endif /* !RECLS_NO_NAMESPACE */

#ifndef __cplusplus
typedef enum recls_sev_index_t_   recls_sev_index_t_;
#endif /* __cplusplus */

void recls_log_printf_(int sevIndex, recls_char_t const* fmt, ...);

void recls_fatal_trace_printf_(recls_char_t const* fmt, ...);
void recls_error_trace_printf_(recls_char_t const* fmt, ...);
void recls_warning_trace_printf_(recls_char_t const* fmt, ...);
void recls_info_trace_printf_(recls_char_t const* fmt, ...);
void recls_debug0_trace_printf_(recls_char_t const* fmt, ...);
void recls_debug1_trace_printf_(recls_char_t const* fmt, ...);
void recls_debug2_trace_printf_(recls_char_t const* fmt, ...);
void recls_debug3_trace_printf_(recls_char_t const* fmt, ...);


#ifdef __cplusplus
class function_scope
{
public:
    typedef function_scope  class_type;

public: /// Construction
    explicit
    function_scope(recls_char_t const* fn);
    ~function_scope() STLSOFT_NOEXCEPT;
private:
    function_scope(class_type const &);     // copy-construction proscribed
    void operator =(class_type const &);    // copy-assignment proscribed

private: /// Member Variables
    recls_char_t const* m_fn;
};

# define function_scope_trace(f)        recls::impl::function_scope  recls_function_scope_ ## __LINE__(RECLS_LITERAL(f))
#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef STLSOFT_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* STLSOFT_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_SRC_H_IMPL_TRACE */

/* ///////////////////////////// end of file //////////////////////////// */

