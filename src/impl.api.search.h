/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.api.search.h
 *
 * Purpose:     Implementation header.
 *
 * Created:     1st January 2021
 * Updated:     1st January 2021
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2021, Matthew Wilson and Synesis Information Systems
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_H_IMPL_API_SEARCH
#define RECLS_INCL_SRC_H_IMPL_API_SEARCH

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

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

recls_rc_t
Recls_SearchFeedback_(
    /* [in] */ char const*                  function
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          patterns
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_progress_fn_t         pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [out] */ hrecls_t*                   phSrch
);

recls_rc_t
Recls_SearchProcessFeedback_(
    /* [in] */ char const*                  function
,   /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          patterns
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_process_fn_t          pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [in] */ hrecls_progress_fn_t         pfnProgress
,   /* [out] */ recls_process_fn_param_t    paramProgress
);

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_IMPL_API_SEARCH */

/* ///////////////////////////// end of file //////////////////////////// */
