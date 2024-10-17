/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.util.remove_directory.cpp
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
using ::recls::impl::recls_fatal_trace_printf_;
using ::recls::impl::recls_error_trace_printf_;
using ::recls::impl::recls_debug0_trace_printf_;

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

    struct file_removal_info_t_
    {
        int const   flags;
        recls_rc_t  rc;
        unsigned    numDeleted;

    public:
        explicit
        file_removal_info_t_(int flags)
            : flags(flags)
            , rc(RECLS_RC_OK)
            , numDeleted(0)
        {}

    private:
        void operator =(file_removal_info_t_ const&);
    };

    int RECLS_CALLCONV_DEFAULT file_removal_fn_(
        recls_entry_t               hEntry
    ,   recls_process_fn_param_t    param
    )
    {
        types::traits_type::stat_data_type  stat_data;
        file_removal_info_t_&               info    =   *static_cast<file_removal_info_t_*>(param);
        recls_char_t const* const           path    =   hEntry->path.begin;

        if (RECLS_REMDIR_F_REMOVE_READONLY & info.flags)
        {
            if (types::traits_type::stat(path, &stat_data))
            {
                if (types::traits_type::is_readonly(&stat_data))
                {
#if defined(PLATFORMSTL_OS_IS_UNIX)
# ifdef RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS
                    ::_chmod(path, stat_data.st_mode | _S_IWRITE);
# else /* ? RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */
                    ::chmod(path, stat_data.st_mode | S_IWUSR);
# endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
                    ::SetFileAttributes(path, stat_data.dwFileAttributes & ~(FILE_ATTRIBUTE_READONLY));
#else /* ? OS */
# error Platform not discriminated
#endif /* OS */
                }
            }
        }

        if (!types::traits_type::delete_file(path))
        {
            info.rc = RECLS_RC_ACCESS_DENIED;

            return 0;
        }

        ++info.numDeleted;

        return 1;
    }

    typedef RECLS_STRING_TEMPLATE_1(recls_char_t)   directory_t;
    typedef std::vector<directory_t>                directories_t;

    struct directory_removal_info_t_
    {
        int const       flags;
        unsigned        maxParts;
        recls_rc_t      rc;
        directories_t&  directories;

    public:
        directory_removal_info_t_(
            int             flags
        ,   directories_t&  directories
        )
            : flags(flags)
            , maxParts(0u)
            , rc(RECLS_RC_OK)
            , directories(directories)
        {}

    private:
        void operator =(directory_removal_info_t_ const&);
    };

    int RECLS_CALLCONV_DEFAULT subdirectory_search_fn_(
        recls_entry_t               hEntry
    ,   recls_process_fn_param_t    param
    )
    {
        directory_removal_info_t_&  info        =   *static_cast<directory_removal_info_t_*>(param);
        recls_char_t const* const   path        =   hEntry->path.begin;
        unsigned                    numParts    =   1u + static_cast<unsigned>(hEntry->directoryParts.end - hEntry->directoryParts.begin);

        info.directories.push_back(path);

        if (info.maxParts < numParts)
        {
            info.maxParts = numParts;
        }

        return 1;
    }

    struct order_by_length
    {
        bool operator ()(directory_t const& lhs, directory_t const& rhs) const
        {
            return lhs.size() < rhs.size();
        }
    };

    RECLS_API Recls_RemoveDirectory4_(
        recls_char_t const*             path
    ,   size_t                       /* pathLen */
    ,   int                             flags
    ,   recls_directoryResults_t*       results
    )
    {
        RECLS_ASSERT(types::traits_type::is_path_absolute(path));
        RECLS_ASSERT('\0' != 0[path]);
        RECLS_ASSERT(ss_nullptr_k != results);

        types::traits_type::stat_data_type stat_data;

        if (!types::traits_type::stat(path, &stat_data)) // Not lstat!
        {
            return RECLS_RC_DIRECTORY_NOT_FOUND;
        }
        else if (!types::traits_type::is_directory(&stat_data))
        {
            return RECLS_RC_PATH_IS_NOT_DIRECTORY;
        }
        else
        {
            if (RECLS_REMDIR_F_REMOVE_FILES & flags)
            {
                // Remove all files

                file_removal_info_t_    info(flags);
                recls_rc_t              rc;

                rc = Recls_SearchProcess(   path
                                        ,   ss_nullptr_k
                                        ,   RECLS_F_FILES | RECLS_F_RECURSIVE | RECLS_F_DETAILS_LATER
                                        ,   file_removal_fn_
                                        ,   &info
                                        );

                if (RECLS_FAILED(rc))
                {
                    return info.rc;
                }

                results->numDeletedFiles    =   info.numDeleted;
            }

            if (0 == (RECLS_REMDIR_F_NO_REMOVE_SUBDIRS & flags))
            {
                // Remove all sub-directories

                directories_t               directories;
                directory_removal_info_t_   info(flags, directories);
                recls_rc_t                  rc;

                rc = Recls_SearchProcess(   path
                                        ,   ss_nullptr_k
                                        ,   RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE | RECLS_F_DIRECTORY_PARTS
                                        ,   subdirectory_search_fn_
                                        ,   &info
                                        );

                if (RECLS_FAILED(rc))
                {
                    return info.rc;
                }

                std::sort(directories.begin(), directories.end(), order_by_length());

                { for (directories_t::reverse_iterator b = directories.rbegin(); b != directories.rend(); ++b)
                {
                    directory_t directory = *b;

                    if (!types::traits_type::remove_directory(directory.c_str()))
                    {
                        return RECLS_RC_ACCESS_DENIED;
                    }
                    else
                    {
                        if (results->existingLength < directory.size())
                        {
                            results->existingLength = directory.size();
                        }
                    }
                }}

                results->numExistingElements = info.maxParts;
            }

            if (!types::traits_type::remove_directory(path))
            {
                return RECLS_RC_ACCESS_DENIED;
            }
            else
            {
                types::path_type resultingPath(path);

                if (0 == results->existingLength)
                {
                    results->existingLength = resultingPath.size();
                }

                resultingPath.pop(false);
                results->numResultingElements = static_cast<unsigned>(types::count_dir_parts(resultingPath.data(), resultingPath.data() + resultingPath.size()));

                resultingPath.pop_sep();
                results->resultingLength = resultingPath.size();

                if (0 == results->numExistingElements)
                {
                    results->numExistingElements = 1u + results->numResultingElements;
                }
            }

            return RECLS_RC_OK;
        }
    }

    RECLS_API Recls_RemoveDirectory_(
        recls_char_t const*         path
    ,   size_t                      pathLen
    ,   int                         flags
    ,   recls_directoryResults_t*   results
    )
    {
        RECLS_ASSERT(ss_nullptr_k != path);
        RECLS_ASSERT('\0' != 0[path]);
        RECLS_ASSERT(ss_nullptr_k != results);

        // ensure path is absolute

        if (!types::traits_type::is_path_absolute(path))
        {
            types::path_type    fullPath;

            fullPath = path;

            fullPath.make_absolute();
            fullPath.canonicalise();

            return Recls_RemoveDirectory_(fullPath.data(), fullPath.size(), flags, results);
        }
        else
        {
            /* results->numExistingElements */;
            /* results->numResultingElements */;
            /* results->existingLength; */
            /* results->resultingLength; */
            /* results->numExistingFiles; */
            /* results->numDeletedFiles; */

            return Recls_RemoveDirectory4_(path, pathLen, flags, results);
        }
    }

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * extended API functions
 */

#ifdef RECLS_EXCEPTION_SUPPORT_
static
recls_rc_t
Recls_RemoveDirectory_X_(
    recls_char_t const*         path
,   int                         flags
,   recls_directoryResults_t*   results
);
#endif /* RECLS_EXCEPTION_SUPPORT_ */


RECLS_API
Recls_RemoveDirectory(
    recls_char_t const*         path
,   int                         flags   /* = 0 */
,   recls_directoryResults_t*   results /* = NULL */
)
#ifdef RECLS_EXCEPTION_SUPPORT_
{
    try
    {
        return Recls_RemoveDirectory_X_(path, flags, results);
    }
    catch (std::bad_alloc&)
    {
        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        return RECLS_RC_OUT_OF_MEMORY;
    }
    catch (platformstl::platform_exception& x)
    {
        recls_fatal_trace_printf_(RECLS_LITERAL("Exception in Recls_RemoveDirectory(): %s"), x.what());

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
        recls_error_trace_printf_(RECLS_LITERAL("Exception in Recls_RemoveDirectory(): %s"), x.what());

        return RECLS_RC_UNEXPECTED;
    }
}

static
recls_rc_t
Recls_RemoveDirectory_X_(
    recls_char_t const*         path
,   int                         flags
,   recls_directoryResults_t*   results
)
#endif /* RECLS_EXCEPTION_SUPPORT_ */
{
    function_scope_trace("Recls_RemoveDirectory");

    recls_debug0_trace_printf_(
        RECLS_LITERAL("Recls_RemoveDirectory(%s, flags=0x%08x, ...)")
    ,   stlsoft::c_str_ptr(path)
    ,   flags
    );

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
        return Recls_RemoveDirectory_(path, types::traits_type::str_len(path), flags, results);
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

