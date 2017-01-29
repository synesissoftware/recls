/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.cover.h
 *
 * Purpose:     Code Coverage.
 *
 * Created:     8th February 2009
 * Updated:     19th January 2017
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2009-2017, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from http://recls.org/)
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_H_IMPL_COVER
#define RECLS_INCL_SRC_H_IMPL_COVER

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

/* recls Header Files */
#include <recls/recls.h>
#include "impl.root.h"
#include "incl.stlsoft.h"

/* ////////////////////////////////
 * Compatibility - 1
 *
 * recls uses xCover if
 *
 * - !RECLS_QUALITY_NO_USE_XCOVER, &&
 * -   RECLS_VARIANT_TEST && STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT && STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT, ||
 * -   RECLS_QUALITY_USE_XCOVER
 */

#ifndef RECLS_QUALITY_NO_USE_XCOVER
# ifdef RECLS_QUALITY_USE_XCOVER
#  if 0 ||\
      !defined(RECLS_VARIANT_TEST) ||\
      !defined(STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT) ||\
      !defined(STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT) ||\
      0
#   undef RECLS_QUALITY_USE_XCOVER
#  endif
# endif
#endif

/* Temporarily suppress support with GCC (4.3+), until xCover fully 
 * compatible
 */

#if defined(STLSOFT_COMPILER_IS_GCC)
# if defined(RECLS_QUALITY_USE_XCOVER)
#  undef RECLS_QUALITY_USE_XCOVER
# endif /* RECLS_QUALITY_USE_XCOVER */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

#ifdef RECLS_QUALITY_USE_XCOVER
# include <xcover/xcover.h>
#endif /* RECLS_QUALITY_USE_XCOVER */

/* ////////////////////////////////
 * Compatibility - 2
 */

#ifdef RECLS_QUALITY_USE_XCOVER

# define RECLS_MARK_FILE_START()                    XCOVER_DEFINE_FILE_STARTER()
# define RECLS_MARK_FILE_END()                      XCOVER_DEFINE_FILE_ENDER()

# define RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()     XCOVER_FILE_GROUP_ASSOCIATOR("recls.core")
# define RECLS_ASSOCIATE_FILE_WITH_GROUP(groupName) XCOVER_FILE_GROUP_ASSOCIATOR(groupName)

# define RECLS_COVER_MARK_LINE()                    XCOVER_MARK_LINE()

#else /* ? RECLS_QUALITY_USE_XCOVER */

# define RECLS_MARK_FILE_START()
# define RECLS_MARK_FILE_END()

# define RECLS_COVER_MARK_LINE()                    stlsoft_static_cast(void, 0)

# define RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
# define RECLS_ASSOCIATE_FILE_WITH_GROUP(groupName)

#endif /* RECLS_QUALITY_USE_XCOVER */

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
 * classes
 */

#ifdef RECLS_QUALITY_USE_XCOVER

#endif /* RECLS_QUALITY_USE_XCOVER */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_H_IMPL_COVER */

/* ///////////////////////////// end of file //////////////////////////// */
