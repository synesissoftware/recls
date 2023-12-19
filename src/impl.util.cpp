/* /////////////////////////////////////////////////////////////////////////
 * File:        impl.util.cpp
 *
 * Purpose:     Platform-independent utility functions for the recls API.
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

#include "impl.trace.h"

#include <stlsoft/internal/safestr.h>
#include <stlsoft/shims/access/string.hpp>

#if 0
# undef RECLS_SUPPORTS_MULTIPATTERN_
#endif /* 1 */

//#define RECLS_MULTIPATTERN_SEARCH_MANUAL

#ifndef RECLS_MULTIPATTERN_SEARCH_MANUAL

# ifndef RECLS_NO_USE_STRING_VIEW_FOR_PATTERN_SEARCH
#  define RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_
# endif /* !RECLS_NO_USE_STRING_VIEW_FOR_PATTERN_SEARCH */

# ifdef RECLS_SUPPORTS_MULTIPATTERN_
#  ifdef RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_
#   include <stlsoft/string/string_view.hpp>
#  else /* ? RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_ */
#   include "recls_string.h"
#  endif /* RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_ */
#  include <stlsoft/string/string_tokeniser.hpp>
# endif /* RECLS_SUPPORTS_MULTIPATTERN_ */

#include <algorithm>    // for std::find

#endif /* !RECLS_MULTIPATTERN_SEARCH_MANUAL */

#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * compiler compatibility
 */

#if defined(RECLS_COMPILER_IS_MSVC)
# if _MSC_VER < 1300
#  pragma warning(disable : 4127)
# endif /* _MSC_VER < 1300 */
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace impl
{
#endif /* !RECLS_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(RECLS_CHAR_TYPE_IS_CHAR)
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
#  define recls_strncpy__(s1, s2, n)    strncpy_s(s1, _TRUNCATE, s2, n)
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
#  define recls_strncpy__               strncpy
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
# define recls_strlen__                 strlen
#elif defined(RECLS_CHAR_TYPE_IS_WCHAR)
# ifdef STLSOFT_USING_SAFE_STR_FUNCTIONS
#  define recls_strncpy__(s1, s2, n)    wcsncpy_s(s1, _TRUNCATE, s2, n)
# else /* ? STLSOFT_USING_SAFE_STR_FUNCTIONS */
#  define recls_strncpy__               wcsncpy
# endif /* STLSOFT_USING_SAFE_STR_FUNCTIONS */
# define recls_strlen__                 wcslen
#else /* ? RECLS_CHAR_TYPE_IS_???? */
# error Unrecognised char type
#endif /* RECLS_CHAR_TYPE_IS_???? */

/* ////////////////////////////////////////////////////////////////////// */

struct cmp_str_len
{
    template<   ss_typename_param_k S1
            ,   ss_typename_param_k S2
            >
    bool operator ()(S1 const &s1, S2 const &s2) const
    {
        RECLS_COVER_MARK_LINE();

        return stlsoft::c_str_len(s1) < stlsoft::c_str_len(s2);
    }
};

/* ////////////////////////////////////////////////////////////////////// */

size_t recls_strncpy_(
    recls_char_t*       dest
,   size_t              cchDest
,   recls_char_t const* src
,   size_t              cchSrc
)
{
    RECLS_COVER_MARK_LINE();

    size_t  cchWritten;

    if(cchDest < cchSrc)
    {
        RECLS_COVER_MARK_LINE();

        /* Just do straight strncpy. */
        recls_strncpy__(dest, src, cchDest);

        cchWritten = cchDest;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        recls_strncpy__(dest, src, cchSrc);

        if(cchSrc < cchDest)
        {
            RECLS_COVER_MARK_LINE();

            /* Fill the rest up with blanks. */
            memset(&dest[cchSrc], 0, sizeof(recls_char_t) * (cchDest - cchSrc));
        }

        cchWritten = cchSrc;
    }

    return cchWritten;
}

size_t recls_strlen_(
    recls_char_t const* s
)
{
    RECLS_COVER_MARK_LINE();

    return recls_strlen__(s);
}

RECLS_LINKAGE_C size_t recls_align_up_size_(
    size_t i
)
{
    RECLS_COVER_MARK_LINE();

#ifdef RECLS_COMPILER_IS_BORLAND
# define cbAlign            sizeof(void*)
#else /* ? compiler */
    const size_t cbAlign =  sizeof(void*);
#endif /* RECLS_COMPILER_IS_BORLAND */

    return static_cast<size_t>((i + (cbAlign - 1)) & ~(cbAlign - 1));
}

#if 0
RECLS_LINKAGE_C size_t count_char_instances(
    recls_char_t const* begin
,   recls_char_t const* end
,   recls_char_t const  ch
)
{
    RECLS_ASSERT(NULL != begin);
    RECLS_ASSERT(NULL != end);

    RECLS_COVER_MARK_LINE();

    size_t cDirParts = 0;

    for(; begin != end; ++begin)
    {
        RECLS_COVER_MARK_LINE();

        if(*begin == ch)
        {
            RECLS_COVER_MARK_LINE();

            ++cDirParts;
        }
    }

    return cDirParts;
}
#endif /* 0 */

/* ////////////////////////////////////////////////////////////////////// */

#if defined(RECLS_COMPILER_IS_DMC) || \
    defined(RECLS_COMPILER_IS_WATCOM)
RECLS_FNDECL(size_t) recls_get_string_property_(
    struct recls_strptrs_t const*       ptrs
,   recls_char_t *                      buffer
,   size_t                              cchBuffer
#else /* ? compiler */
RECLS_FNDECL(size_t) recls_get_string_property_(
    struct recls_strptrs_t const* const ptrs
,   recls_char_t *const                 buffer
,   size_t const                        cchBuffer
#endif /* compiler */
)
{
    RECLS_ASSERT(NULL != ptrs);

    RECLS_COVER_MARK_LINE();

    size_t  cch =   static_cast<size_t>(ptrs->end - ptrs->begin);

    if(NULL != buffer)
    {
        RECLS_COVER_MARK_LINE();

        cch = recls_strncpy_(buffer, cchBuffer, ptrs->begin, cch);
    }

    return cch;
}

/* ////////////////////////////////////////////////////////////////////// */

RECLS_LINKAGE_C recls_bool_t recls_file_exists_(
    recls_char_t const* f
)
{
    RECLS_COVER_MARK_LINE();

    return types::traits_type::file_exists(f);
}

/* ////////////////////////////////////////////////////////////////////// */

RECLS_API recls_is_valid_pattern_(
    recls_char_t const* pattern
,   recls_uint32_t      flags
,   size_t              maxPathCompLen
)
{
    STLSOFT_SUPPRESS_UNUSED(maxPathCompLen);

    RECLS_ASSERT(NULL != pattern);

    RECLS_COVER_MARK_LINE();

    if('\0' == *pattern)
    {
        RECLS_COVER_MARK_LINE();

        return RECLS_RC_NO_MORE_DATA;
    }
    else
    {
        STLSOFT_SUPPRESS_UNUSED(flags);

        RECLS_COVER_MARK_LINE();

#if !defined(RECLS_SUPPORTS_MULTIPATTERN_)

#else /* ? RECLS_SUPPORTS_MULTIPATTERN_ */
        // Ensure that if '.' was specified as a/the pattern, it is not
        // for recursive searches.

# ifdef RECLS_MULTIPATTERN_SEARCH_MANUAL

        const recls_char_t          sep =   *Recls_GetPathSeparator();
        const size_t                len =   recls_strlen_(pattern);
        recls_char_t const* const   end =   pattern + len;

        if(1 == len)
        {
            RECLS_COVER_MARK_LINE();

            if( 0 != (flags & RECLS_F_RECURSIVE) &&
                '.' == pattern[0])
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_DOT_RECURSIVE_SEARCH;
            }
        }
        else if(2 == len)
        {
            RECLS_COVER_MARK_LINE();

            if( '.' == pattern[0] &&
                '.' == pattern[1])
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_DOT_RECURSIVE_SEARCH;
            }
        }

        if(len > 0)
        {
            RECLS_COVER_MARK_LINE();

            recls_char_t    dotPattern[4]       =   "?.?";
            recls_char_t    dotdotPattern[5]    =   "?..?";

            dotPattern[0] = dotPattern[2] = dotdotPattern[0] = dotdotPattern[3] = sep;

            if( (   0 != (flags & RECLS_F_RECURSIVE) &&
                    0 == strncmp(pattern, &dotPattern[1], 2)) ||
                0 == strncmp(pattern, &dotdotPattern[1], 3))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_DOT_RECURSIVE_SEARCH;
            }

            if( (   0 != (flags & RECLS_F_RECURSIVE) &&
                    0 == strncmp(end - 2, dotPattern, 2)) ||
                0 == strncmp(end - 3, dotdotPattern, 3))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_DOT_RECURSIVE_SEARCH;
            }

            if( (   0 != (flags & RECLS_F_RECURSIVE) &&
                    NULL != strstr(pattern, dotPattern)) ||
                NULL != strstr(pattern, dotdotPattern))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_DOT_RECURSIVE_SEARCH;
            }

            RECLS_COVER_MARK_LINE();
        }
# else  /* ? RECLS_MULTIPATTERN_SEARCH_MANUAL */

        // "." can only be specified as a pattern in non-recursive searches
# ifdef RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_
        typedef ::stlsoft::basic_string_view<recls_char_t>  string_t;
# else /* ? RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_ */
        typedef RECLS_STRING_TEMPLATE_1(recls_char_t)       string_t;
# endif /* RECLS_USE_STRING_VIEW_FOR_PATTERN_SEARCH_ */

        // Some compilers can't handle the instantiation of STLSoft's string_tokeniser
        // with a string delimiter type (as opposed to character), so for those we
        // stick with the character delimiter type
# if defined(RECLS_COMPILER_IS_WATCOM) || \
    (   defined(RECLS_COMPILER_IS_MSVC) && \
        _MSC_VER < 1300 && \
        _STLSOFT_VER < 0x00010807)
        typedef ::stlsoft::string_tokeniser<string_t, char>         tokeniser_t;

        tokeniser_t     tokens(pattern, *Recls_GetPathSeparator());
# else /* ? compiler */
        typedef ::stlsoft::string_tokeniser<string_t, string_t>     tokeniser_t;

        tokeniser_t     tokens(pattern, Recls_GetPathSeparator());
# endif /* compiler */

        if( tokens.end() != std::find(tokens.begin(), tokens.end(), constants::parent_directory()) ||
            (   0 != (flags & RECLS_F_RECURSIVE) &&
                tokens.end() != std::find(tokens.begin(), tokens.end(), constants::local_directory())))
        {
            RECLS_COVER_MARK_LINE();

            return RECLS_RC_DOT_RECURSIVE_SEARCH;
        }

        RECLS_COVER_MARK_LINE();

        if(!tokens.empty())
        {
            RECLS_COVER_MARK_LINE();

            tokeniser_t::const_iterator it = std::max_element(tokens.begin(), tokens.end(), cmp_str_len());

            if(stlsoft::c_str_len(*it) > maxPathCompLen)
            {
                return RECLS_RC_PATH_LIMIT_EXCEEDED;
            }
        }

        RECLS_COVER_MARK_LINE();

# endif  /* ? RECLS_MULTIPATTERN_SEARCH_MANUAL */
#endif /* RECLS_SUPPORTS_MULTIPATTERN_ */

        return RECLS_RC_OK;
    }
}

RECLS_LINKAGE_C recls_bool_t recls_is_home_start_(
    recls_char_t const* path
)
{
    RECLS_ASSERT(NULL != path);

    RECLS_COVER_MARK_LINE();

    if( '~' == path[0] &&
        (   '\0' == path[1] ||
#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
            '\\' == path[1] ||
#endif /* platform */
            '/' == path[1]))
    {
        RECLS_COVER_MARK_LINE();

        return true;
    }

    RECLS_COVER_MARK_LINE();

    return false;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */
