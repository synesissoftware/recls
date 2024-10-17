/* /////////////////////////////////////////////////////////////////////////
 * File:    src/api.entryinfo.cpp
 *
 * Purpose: recls API functions pertaining to entry info.
 *
 * Created: 16th August 2003
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "incl.platformstl.h"
#include "impl.util.h"

#include "impl.trace.h"

#if defined(RECLS_PLATFORM_IS_UNIX)
# include <sys/stat.h>
#endif /* UNIX */

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{

using ::recls::impl::recls_get_string_property_;
using ::recls::impl::recls_file_exists_;
#endif /* !RECLS_NO_NAMESPACE */

namespace
{

#ifdef STLSOFT_ALWAYS_FALSE
# define always_false_()                                    STLSOFT_ALWAYS_FALSE()
#else
static
int
always_false_()
{
    return 0;
}
#endif

} /* anonymous namespace */

/* /////////////////////////////////////////////////////////////////////////
 * constants
 */

#if defined(RECLS_PLATFORM_IS_UNIX)
# define GetCreationTime_                                   modificationTime
# define GetLastStatusChangeTime_                           lastStatusChangeTime
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# define GetCreationTime_                                   creationTime
# define GetLastStatusChangeTime_                           modificationTime
#else /* unrecognised platform */
# error platform is not recognised
#endif /* platform */

/* /////////////////////////////////////////////////////////////////////////
 * file entry info structure
 */

RECLS_FNDECL(size_t) Recls_GetPathProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetPathProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->path, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetSearchRelativePathProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetSearchRelativePathProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->searchRelativePath, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetDirectoryProperty(
    recls_entry_t   fileInfo
,   recls_char_t*   buffer
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetDirectoryProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->directory, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetDirectoryPathProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetDirectoryPathProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    struct recls_strptrs_t directoryPath =
    {
            fileInfo->path.begin    /* Directory path is defined by start of path ... */
        ,   fileInfo->directory.end /* ... to end of directory. */
    };

    return recls_get_string_property_(&directoryPath, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetSearchDirectoryProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetSearchDirectoryProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->searchDirectory, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetUNCDriveProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetUNCDriveProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    struct recls_strptrs_t uncDrive =
    {
            fileInfo->path.begin        /* Directory path is defined by start of path ... */
        ,   fileInfo->directory.begin   /* ... to start of directory. */
    };

    if (!Recls_IsFileUNC(fileInfo))
    {
        uncDrive.end = uncDrive.begin;
    }

    return recls_get_string_property_(&uncDrive, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetFileProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetFileProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    struct recls_strptrs_t file =
    {
            fileInfo->fileName.begin /* File is defined by start of fileName ... */
        ,   fileInfo->fileExt.end    /* ... to end of fileExt. */
    };

    return recls_get_string_property_(&file, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetFileNameProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetFileNameProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->fileName, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetFileExtProperty(
    recls_entry_t   fileInfo
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetFileExtProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return recls_get_string_property_(&fileInfo->fileExt, buffer, cchBuffer);
}

RECLS_FNDECL(size_t) Recls_GetDirectoryPartProperty(
    recls_entry_t   fileInfo
,   int             part
,   recls_char_t    buffer[]
,   size_t          cchBuffer
)
{
    function_scope_trace("Recls_GetDirectoryPartProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    size_t  cParts = static_cast<size_t>(fileInfo->directoryParts.end - fileInfo->directoryParts.begin);

    if (part < 0)
    {
        return cParts;
    }
    else
    {
        RECLS_ASSERT(static_cast<size_t>(part) < cParts);

        return recls_get_string_property_(&fileInfo->directoryParts.begin[part], buffer, cchBuffer);
    }
}

RECLS_FNDECL(recls_bool_t) Recls_EntryExists(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_EntryExists");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    if (0 != fileInfo->size ||
        0 != fileInfo->attributes ||
#if defined(RECLS_PLATFORM_IS_WINDOWS)
        0 != fileInfo->GetCreationTime_.dwLowDateTime ||
        0 != fileInfo->GetCreationTime_.dwHighDateTime ||
        0 != fileInfo->GetLastStatusChangeTime_.dwLowDateTime ||
        0 != fileInfo->GetLastStatusChangeTime_.dwHighDateTime ||
        0 != fileInfo->modificationTime.dwLowDateTime ||
        0 != fileInfo->modificationTime.dwHighDateTime ||
#else
        0 != fileInfo->GetCreationTime_ ||
        0 != fileInfo->GetLastStatusChangeTime_ ||
        0 != fileInfo->modificationTime ||
#endif
        always_false_())
    {
        return true;
    }

    return false;
}

RECLS_FNDECL(recls_bool_t) Recls_IsFileReadOnly(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_IsFileReadOnly");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

#if defined(RECLS_PLATFORM_IS_UNIX)

    return (fileInfo->attributes & S_IWRITE) == 0;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    return (fileInfo->attributes & FILE_ATTRIBUTE_READONLY) == FILE_ATTRIBUTE_READONLY;
#else /* unrecognised platform */

# error platform is not recognised
#endif /* platform */
}

RECLS_FNDECL(recls_bool_t) Recls_IsFileDirectory(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_IsFileDirectory");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

#if defined(RECLS_PLATFORM_IS_UNIX)

    return (fileInfo->attributes & S_IFMT) == S_IFDIR;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    return (fileInfo->attributes & FILE_ATTRIBUTE_DIRECTORY) == FILE_ATTRIBUTE_DIRECTORY;
#else /* unrecognised platform */

# error platform is not recognised
#endif /* platform */
}

RECLS_FNDECL(recls_bool_t) Recls_IsFileLink(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_IsFileLink");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

#if defined(RECLS_PLATFORM_IS_UNIX) && \
    !defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)

    return (fileInfo->attributes & S_IFMT) == S_IFLNK;
#else /* unrecognised platform */

    STLSOFT_SUPPRESS_UNUSED(fileInfo);

    return false;
#endif /* platform */
}

RECLS_FNDECL(recls_bool_t) Recls_DoesEntryExist(recls_entry_t hEntry)
{
    function_scope_trace("Recls_DoesEntryExist");

    RECLS_ASSERT(ss_nullptr_k != hEntry);

    return recls_file_exists_(hEntry->path.begin);
}

RECLS_FNDECL(recls_bool_t) Recls_IsFileUNC(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_IsFileUNC");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

#if defined(RECLS_PLATFORM_IS_WINDOWS) || \
    defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)

    if ('\\' == fileInfo->path.begin[0] &&
        '\\' == fileInfo->path.begin[1])
    {
        return true;
    }
#else /* unrecognised platform */

    STLSOFT_SUPPRESS_UNUSED(fileInfo);
#endif /* platform */

    return false;
}

RECLS_FNDECL(recls_time_t) Recls_GetCreationTime(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_GetCreationTime");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return fileInfo->GetCreationTime_;
}

RECLS_FNDECL(recls_time_t) Recls_GetLastStatusChangeTime(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_GetLastStatusChangeTime");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return fileInfo->GetLastStatusChangeTime_;
}

RECLS_FNDECL(recls_filesize_t) Recls_GetSizeProperty(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_GetSizeProperty");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return fileInfo->size;
}

RECLS_FNDECL(recls_time_t) Recls_GetModificationTime(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_GetModificationTime");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return fileInfo->modificationTime;
}

RECLS_FNDECL(recls_time_t) Recls_GetLastAccessTime(recls_entry_t fileInfo)
{
    function_scope_trace("Recls_GetLastAccessTime");

    RECLS_ASSERT(ss_nullptr_k != fileInfo);

    return fileInfo->lastAccessTime;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

