/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.constants.hpp
 *
 * Purpose:     Common constants.
 *
 * Created:     28th February 2007
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2007-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_SRC_HPP_IMPL_CONSTANTS
#define RECLS_INCL_SRC_HPP_IMPL_CONSTANTS

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include "impl.cover.h"
#include <stlsoft/string/string_view.hpp>

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
 * coverage
 */

RECLS_ASSOCIATE_FILE_WITH_CORE_GROUP()
RECLS_MARK_FILE_START()

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#define RECLS_S_DEFAULT_SEARCH_ROOT_                        RECLS_LITERAL(".")
#define RECLS_S_HOME_                                       RECLS_LITERAL("~")
#define RECLS_S_LOCAL_DIR_                                  RECLS_LITERAL(".")
#define RECLS_S_PARENT_DIR_                                 RECLS_LITERAL("..")

struct constants
{
public: /// Member Types
    typedef ::stlsoft::basic_string_view<recls_char_t>  string_type;

public: /// Constants
    static string_type  default_search_root()
    {
        RECLS_COVER_MARK_LINE();

        return string_type(RECLS_S_DEFAULT_SEARCH_ROOT_, STLSOFT_NUM_ELEMENTS(RECLS_S_DEFAULT_SEARCH_ROOT_) - 1);
    }
    static string_type  home()
    {
        RECLS_COVER_MARK_LINE();

        return string_type(RECLS_S_HOME_, STLSOFT_NUM_ELEMENTS(RECLS_S_HOME_) - 1);
    }
    static string_type  local_directory()
    {
        RECLS_COVER_MARK_LINE();

        return string_type(RECLS_S_LOCAL_DIR_, STLSOFT_NUM_ELEMENTS(RECLS_S_LOCAL_DIR_) - 1);
    }
    static string_type  parent_directory()
    {
        RECLS_COVER_MARK_LINE();

        return string_type(RECLS_S_PARENT_DIR_, STLSOFT_NUM_ELEMENTS(RECLS_S_PARENT_DIR_) - 1);
    }

private: /// Not to be implemented
    constants();
    constants(constants const&);
    constants& operator =(constants const&);
};

/* /////////////////////////////////////////////////////////////////////////
 * coverage
 */

RECLS_MARK_FILE_END()

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_SRC_HPP_IMPL_CONSTANTS */

/* ///////////////////////////// end of file //////////////////////////// */

