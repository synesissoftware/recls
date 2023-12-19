/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.util.h
 *
 * Purpose:     Implementation header.
 *
 * Created:     17th August 2003
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_H_IMPL_UTIL
#define RECLS_INCL_SRC_H_IMPL_UTIL

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#include <stdarg.h>

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

/* impl.fileutil.h */
RECLS_FNDECL(recls_bool_t) recls_file_exists_(
    recls_char_t const* f
);

/* impl.numutil.h */
RECLS_FNDECL(size_t) recls_align_up_size_(
    size_t i
);

/* impl.strutil.h */
#if 0
RECLS_FNDECL(size_t) count_char_instances(
    recls_char_t const* begin
,   recls_char_t const* end
,   recls_char_t const  ch
);
#endif /* 0 */

RECLS_FNDECL(size_t) recls_strncpy_(
    recls_char_t*       dest
,   size_t              cchDest
,   recls_char_t const* src
,   size_t              cchSrc
);

RECLS_FNDECL(size_t) recls_strlen_(
    recls_char_t const* dest
);

RECLS_FNDECL(int) recls_vsnprintf_a(
    char*       dest
,   size_t      cchDest
,   char const* fmt
,   va_list     args
);
RECLS_FNDECL(int) recls_snprintf_a(
    char*       dest
,   size_t      cchDest
,   const char* fmt
,   ...
);
RECLS_FNDECL(int) recls_vsnprintf(
    recls_char_t*       dest
,   size_t              cchDest
,   recls_char_t const* fmt
,   va_list             args
);
RECLS_FNDECL(int) recls_snprintf(
    recls_char_t*       dest
,   size_t              cchDest
,   const recls_char_t* fmt
,   ...
);

/* impl.fileutil.h */
RECLS_FNDECL(recls_char_t const*) recls_find_directory_0_(
    recls_char_t const* path
);

/* impl.apiutil.h */
RECLS_FNDECL(size_t) recls_get_string_property_(
    struct recls_strptrs_t const*   ptrs
,   recls_char_t*                   buffer
,   size_t                          cchBuffer
);

/* impl.fileutil.h */
RECLS_API recls_is_valid_pattern_(
    recls_char_t const* pattern
,   recls_uint32_t      flags
,   size_t              maxPathCompLen
);

/* impl.envutil.h */

/** Indicates whether the path begins with a home indicator
 */
RECLS_FNDECL(recls_bool_t) recls_is_home_start_(
    recls_char_t const* path
);

/** Provides the home directory.
 *
 * \param buff Pointer to buffer to receive the result. If NULL, function
 *   returns required size (excluding NUL terminator).
 * \param cchBuff Number of characters available in buff to write to.
 *
 * \note Function will always attempt to include a trailing path name
 *   separator, unless the home directory is the root directory, or the
 *   function fails.
 *
 * \retval The number of characters written into buff
 */
RECLS_FNDECL(size_t) recls_get_home_(
    recls_char_t*   buff
,   size_t          cchBuff
);

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_IMPL_UTIL */

/* ///////////////////////////// end of file //////////////////////////// */
