/* /////////////////////////////////////////////////////////////////////////
 * File:    src/impl.entryinfo.hpp
 *
 * Purpose: Definition of the create_entryinfo() function.
 *
 * Created: 31st May 2004
 * Updated: 30th December 2023
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_HPP_IMPL_ENTRYINFO
#define RECLS_INCL_SRC_HPP_IMPL_ENTRYINFO

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include "impl.types.hpp"

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
 * utility functions
 */

extern "C"
{

recls_entry_t
create_entryinfo(
    size_t                          rootDirLen
,   recls_char_t const*             searchDir
,   size_t                          searchDirLen
,   recls_char_t const*             entryPath
,   size_t                          entryPathLen
,   recls_char_t const*             entryFile
,   size_t                          entryFileLen
,   recls_uint32_t                  flags
,   types::stat_data_type const*    st
);

recls_entry_t
create_drive_entryinfo(
    recls_char_t const*             entryPath
,   size_t                          entryPathLen
,   recls_uint32_t                  flags
,   types::stat_data_type const*    st
);

} // extern "C"

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_ENTRYINFO */

/* ///////////////////////////// end of file //////////////////////////// */

