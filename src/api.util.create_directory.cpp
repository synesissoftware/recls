/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.create_directory.cpp
 *
 * Purpose: more recls API extended functions.
 *
 * Created: 30th January 2009
 * Updated: 9th July 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2009-2019, Matthew Wilson and Synesis Software
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
#include "impl.string.hpp"
#include "impl.types.hpp"
#include "impl.util.h"

#include "impl.trace.h"

#include <platformstl/exception/platformstl_exception.hpp>
#include <platformstl/filesystem/directory_functions.hpp>

#include <vector>

#if defined(RECLS_PLATFORM_IS_UNIX)
# include <sys/stat.h>
# include <sys/types.h>
#endif /* RECLS_PLATFORM_IS_UNIX */

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1310
# pragma warning(disable : 4702)
#endif /* compiler */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::types;

using ::recls::impl::recls_debug0_trace_printf_;
using ::recls::impl::recls_debug1_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_is_home_start_;

#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */

namespace
{

inline
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)
int
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
DWORD
#endif /* platform */
get_exception_status_code(
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

# if _STLSOFT_VER >= 0x010a0200

    unixstl::unixstl_exception& x
# else /* ? 1.10.2+ */

    unixstl::unix_exception&    x
# endif /* 1.10.2+ */
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

# if _STLSOFT_VER >= 0x010a0200

    winstl::winstl_exception&   x
# else /* ? 1.10.2+ */

    winstl::windows_exception&  x
# endif /* 1.10.2+ */
#endif /* platform */
)
{
    return x.status_code();
}

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * implementation functions
 */

namespace
{

    /* Algorithm:
     *
     * - make path absolute
     * - split into parts
     * - stat each part
     *    - if exists, verify that it is a directory '[-d part]'
     *    - if not exist, attempt to create it
     */

    RECLS_API Recls_CreateDirectory3_(
        recls_char_t const*         path
    ,   size_t                      pathLen
    ,   recls_directoryResults_t*   results
    )
    {
        RECLS_ASSERT(ss_nullptr_k != path);
        RECLS_ASSERT(0 != pathLen);
        RECLS_ASSERT('\0' != 0[path]);
        RECLS_ASSERT(types::traits_type::str_len(path) == pathLen);
        RECLS_ASSERT(types::traits_type::is_path_absolute(path, pathLen));

        RECLS_ASSERT(ss_nullptr_k != results);

        recls_debug1_trace_printf_(
            RECLS_LITERAL("Recls_CreateDirectory3_(%.*s, ...)")
        ,   int(pathLen)
        ,   stlsoft::c_str_ptr(path)
        );

        types::traits_type::stat_data_type stat_data;

        if (types::traits_type::stat(path, &stat_data)) // Not lstat!
        {
            if (types::traits_type::is_directory(&stat_data))
            {
                results->existingLength     =   pathLen;
                results->resultingLength    =   pathLen;

                return RECLS_RC_OK;
            }
            else
            {
                return RECLS_RC_ENTRY_IS_NOT_DIRECTORY;
            }
        }
        else
        {
            // Need to work back to root

            types::path_type    path_0(path, pathLen);

            path_0.pop();

            if (0 == path_0.size())
            {
                if (types::traits_type::is_path_UNC(path))
                {
                    return RECLS_RC_INVALID_NAME;
                }
                else
                {
                    return RECLS_RC_UNEXPECTED;
                }
            }
            else if (path_0.size() != pathLen)
            {
                recls_rc_t rc = Recls_CreateDirectory3_(path_0.data(), path_0.size(), results);

                if (RECLS_FAILED(rc))
                {
                    return rc;
                }
            }

            // Now try and create the directory
            if (!platformstl::create_directory_recurse(path))
            {
                recls_error_trace_printf_(
                    RECLS_LITERAL("platformstl::create_directory_recurse(%.*s) failed: %ld")
                ,   int(pathLen)
                ,   stlsoft::c_str_ptr(path)
                ,   types::traits_type::get_last_error()
                );

                return RECLS_RC_FAIL;
            }
            else
            {
                results->resultingLength = pathLen;
                ++results->numResultingElements;

                return RECLS_RC_OK;
            }
        }
    }

    RECLS_API Recls_CreateDirectory_(
        recls_char_t const*         path
    ,   size_t                      pathLen
    ,   recls_directoryResults_t*   results
    )
    {
        RECLS_ASSERT(ss_nullptr_k != path);
        RECLS_ASSERT(0 != pathLen);
        RECLS_ASSERT('\0' != 0[path]);
        RECLS_ASSERT(types::traits_type::str_len(path) == pathLen);

        RECLS_ASSERT(ss_nullptr_k != results);


        recls_debug1_trace_printf_(RECLS_LITERAL("Recls_CreateDirectory_(%s, ...)"), path);

        // 1. Make path absolute

        if (recls_is_home_start_(path, pathLen))
        {
            types::buffer_type  home(1);

            size_t const homeLen = types::traits_type::get_home_directory(home);

            if (0 == homeLen)
            {
#ifdef RECLS_STLSOFT_1_12_OR_LATER
                types::traits_type::error_type const e = types::traits_type::get_last_error();

                if (types::traits_type::is_memory_error_code(e))
                {
                    return RECLS_RC_OUT_OF_MEMORY;
                }
                else
#endif
                {
                    return RECLS_RC_NO_HOME;
                }
            }
            else
            {
                size_t const lenRequired = homeLen + (pathLen - 1);

                if (!home.resize(lenRequired + 1))
                {
                    return RECLS_RC_OUT_OF_MEMORY;
                }
                else
                {
                    types::traits_type::char_copy(home.data() + homeLen, path + 1, (pathLen - 1) + 1);

                    path    =   home.data();
                    pathLen =   lenRequired;

                    return Recls_CreateDirectory_(path, pathLen, results);
                }
            }
        }

        if (!types::traits_type::is_path_absolute(path))
        {
            types::path_type fullPath(path);

            fullPath.make_absolute();

            fullPath.canonicalise();

            return Recls_CreateDirectory_(fullPath.c_str(), fullPath.size(), results);
        }
        else
        {
            results->numExistingElements    =   static_cast<unsigned>(types::count_dir_parts(path, path + pathLen) + (types::traits_type::has_dir_end(path) ? 0u : 1u));
            results->numResultingElements   =   results->numExistingElements;
            /* results->existingLength; */
            /* results->resultingLength; */
            /* results->numExistingFiles; */
            /* results->numDeletedFiles; */

            return Recls_CreateDirectory3_(path, pathLen, results);
        }
    }


} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
static
recls_rc_t
Recls_CreateDirectory_X_(
    recls_char_t const*         path
,   recls_directoryResults_t*   results
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */


RECLS_API
Recls_CreateDirectory(
    recls_char_t const*         path
,   recls_directoryResults_t*   results /* = NULL */
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{

    try
    {
        return Recls_CreateDirectory_X_(path, results);
    }
    catch (std::bad_alloc&)
    {
        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        return RECLS_RC_OUT_OF_MEMORY;
    }
    catch (platformstl::platform_exception& x)
    {
        recls_fatal_trace_printf_(RECLS_LITERAL("Exception in Recls_CreateDirectory(): %s"), x.what());

        // TODO: write a system_error_code_2_recls_rc() translator
# if defined(PLATFORMSTL_OS_IS_UNIX)
        if (ENOENT == get_exception_status_code(x))
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
        if (ERROR_INVALID_NAME == get_exception_status_code(x))
# else /* ? OS */
#  error Platform not discriminated
# endif /* OS */
        {
            return RECLS_RC_INVALID_NAME;
        }

        return RECLS_RC_UNEXPECTED;
    }
    catch (std::exception& x)
    {
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_CreateDirectory(): %s"), x.what());

        return RECLS_RC_UNEXPECTED;
    }
}

static
recls_rc_t
Recls_CreateDirectory_X_(
    recls_char_t const*         path
,   recls_directoryResults_t*   results
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_CreateDirectory");

    recls_debug0_trace_printf_(RECLS_LITERAL("Recls_CreateDirectory(%s, ...)"), stlsoft::c_str_ptr(path));

    RECLS_ASSERT(ss_nullptr_k != path);

    // Initial parameter validation

    recls_directoryResults_t results_;

    if (ss_nullptr_k == results)
    {
        results = &results_;
    }

    results->numExistingElements    =   0;
    results->numResultingElements   =   0;
    results->existingLength         =   0;
    results->resultingLength        =   0;
    results->numExistingFiles       =   0;
    results->numDeletedFiles        =   0;

    if ('\0' == *path)
    {
        return RECLS_RC_INVALID_NAME;
    }
    else
    {
        return Recls_CreateDirectory_(path, types::traits_type::str_len(path), results);
    }
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace impl
{
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

