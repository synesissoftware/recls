/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.string.hpp
 *
 * Purpose:     Implementation header.
 *
 * Created:     12th March 2005
 * Updated:     30th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_HPP_IMPL_STRING
#define RECLS_INCL_SRC_HPP_IMPL_STRING

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>

#ifndef RECLS_NO_USE_SIMPLE_STRING

# include <stlsoft/string/simple_string.hpp>

# define    RECLS_STRING_TEMPLATE_1(T)  stlsoft::basic_simple_string<T>

# define    STLSOFT_STRING_ACCESS_NO_STD_STRING /* We don't care about std::string in recls */
#else /* ? RECLS_NO_USE_SIMPLE_STRING */

# include <string>

# define    RECLS_STRING_TEMPLATE_1(T)  std::basic_string<T>
#endif /* !RECLS_NO_USE_SIMPLE_STRING */

#include <stlsoft/shims/access/string.hpp>

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_STRING */

/* ///////////////////////////// end of file //////////////////////////// */

