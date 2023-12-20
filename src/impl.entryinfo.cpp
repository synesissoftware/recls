/* /////////////////////////////////////////////////////////////////////////
 * File:        src/impl.entryinfo.cpp
 *
 * Purpose:     Implementation of the create_entryinfo() function.
 *
 * Created:     31st May 2004
 * Updated:     19th December 2023
 *
 * Home:        https://github.com/synesissoftware/recls
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include <recls/assert.h>
#include "impl.root.h"
#include "incl.stlsoft.h"
#ifdef RECLS_STLSOFT_1_12_OR_LATER
# include <stlsoft/synch/util/concepts.hpp>
#else /* ? STLSoft 1.12+ */
# include <stlsoft/synch/concepts.hpp> // Required to workaround VC++ 6 ICE
#endif /* STLSoft 1.12+ */
#include "impl.types.hpp"
#include "impl.util.h"
#include "impl.entryinfo.hpp"
#include "impl.entryfunctions.h"

#include "impl.trace.h"

#if defined(RECLS_CHAR_TYPE_IS_WCHAR)
# if defined(RECLS_PLATFORM_IS_WINDOWS)
#  include <winstl/conversion/char_conversions.hpp>
# endif /* RECLS_PLATFORM_IS_WINDOWS */
#endif /* RECLS_CHAR_TYPE_IS_???? */

#include <stlsoft/shims/conversion/to_uint64.hpp>
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)
# include <unixstl/shims/conversion/to_uint64/stat.hpp>
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# include <winstl/shims/conversion/to_uint64/WIN32_FIND_DATA.hpp>
#endif /* OS */

#if 0
#elif defined(RECLS_PLATFORM_IS_WINDOWS) || \
      defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
# define RECLS_USE_WINSTL_LINK_FUNCTIONS_
# include <winstl/filesystem/link_functions.h>
#endif /* OS */

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
)
{
    function_scope_trace("create_entryinfo");

    recls_debug2_trace_printf_(
        RECLS_LITERAL("create_entryinfo(%lu, %.*s, %.*s, %.*s, 0x%08x, ...)")
    ,   static_cast<unsigned long>(rootDirLen)
    ,   int(searchDirLen), stlsoft::c_str_ptr(searchDir)
    ,   int(entryPathLen), stlsoft::c_str_ptr(entryPath)
    ,   int(entryFileLen), stlsoft::c_str_ptr(entryFile)
    ,   flags
    );

    bool const bSearchDirOverlap = 0 == types::traits_type::str_n_compare(searchDir, entryPath, searchDirLen);

    STLSOFT_SUPPRESS_UNUSED(searchDir);
    STLSOFT_SUPPRESS_UNUSED(entryFile);

    RECLS_MESSAGE_ASSERT("Directory length cannot be 0", 0 != searchDirLen);
    RECLS_MESSAGE_ASSERT("Path length cannot be 0", 0 != entryPathLen);
    RECLS_MESSAGE_ASSERT("File length cannot be 0", 0 != entryFileLen);

    RECLS_MESSAGE_ASSERT("Invalid directory length", searchDirLen <= types::traits_type::str_len(searchDir));
    RECLS_MESSAGE_ASSERT("Invalid path length", entryPathLen == types::traits_type::str_len(entryPath));
    RECLS_MESSAGE_ASSERT("Invalid file length", entryFileLen == types::traits_type::str_len(entryFile));

    RECLS_ASSERT(!bSearchDirOverlap || searchDirLen < entryPathLen);
    RECLS_ASSERT(!bSearchDirOverlap || searchDirLen + entryFileLen <= entryPathLen);

    RECLS_ASSERT(!bSearchDirOverlap || 0 == types::traits_type::str_n_compare(searchDir, entryPath, searchDirLen));
    RECLS_ASSERT(0 == types::traits_type::str_n_compare(entryFile, entryPath + (entryPathLen - entryFileLen), entryFileLen));

    RECLS_ASSERT(searchDir[searchDirLen - 1] == types::traits_type::path_name_separator());

    RECLS_ASSERT(types::traits_type::str_rchr(entryPath, types::traits_type::path_name_separator()) + 1 == entryPath + (entryPathLen - entryFileLen));

    // size of structure is:
    //
    //    offsetof(struct recls_entryinfo_t, data)
    //  + directory parts
    //  + full path (+ null)
    //  + short name (+ null)
    //  + 1 in case we need to MARK_DIRS
    //  [+ 1 + searchDirLen if searchDir and entryPath do not overlap]

    recls_char_t const* const   dir0    =   recls_find_directory_0_(entryPath);
    recls_char_t const* const   end     =   entryPath + (entryPathLen - entryFileLen);

    size_t const    cchFileName =   entryFileLen;
    size_t const    cDirParts   =   (RECLS_F_DIRECTORY_PARTS == (flags & RECLS_F_DIRECTORY_PARTS)) ? types::count_dir_parts(dir0, end) : 0;
    size_t const    cbPath      =   recls_align_up_size_(sizeof(recls_char_t) * (1 + entryPathLen));
#if defined(RECLS_PLATFORM_IS_UNIX)
    size_t const    cbAlt       =   0;  // UNIX doesn't have alt paths
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    size_t const    cbAlt       =   recls_align_up_size_(sizeof(recls_char_t) * (1 + RECLS_NUM_ELEMENTS(st->cAlternateFileName)));
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
    size_t const    cb          =   offsetof(struct recls_entryinfo_t, data)
                                +   cDirParts * sizeof(recls_strptrs_t)
                                +   cbPath
                                +   cbAlt
                                +   1 // In case we need to expand for MARK_DIRS
                                +   (bSearchDirOverlap ? 0 : (sizeof(recls_char_t) * (1 + searchDirLen + 1)))
                                ;

    struct recls_entryinfo_t* info = const_cast<struct recls_entryinfo_t*>(Entry_Allocate(cb));

    if (ss_nullptr_k != info)
    {
        recls_byte_t* const     pData       =   &info->data[0];
        recls_byte_t* const     pParts      =   pData + 0;
        recls_byte_t* const     pPath       =   pParts + (cDirParts * sizeof(recls_strptrs_t));
#if defined(RECLS_PLATFORM_IS_WINDOWS)
        recls_byte_t* const     pAltName    =   pPath + cbPath;
#endif /* platform */
        recls_byte_t* const     pSearchCopy =   pPath + cbPath + cbAlt;

        recls_char_t*           fullPath    =   ::stlsoft::sap_cast<recls_char_t*>(pPath);
#if defined(RECLS_PLATFORM_IS_WINDOWS)
        recls_char_t*           altName     =   ::stlsoft::sap_cast<recls_char_t*>(pAltName);
#endif /* platform */

        RECLS_ASSERT(::stlsoft::sap_cast<recls_char_t*>(pData + (cDirParts * sizeof(recls_strptrs_t))) == fullPath);
#if defined(RECLS_PLATFORM_IS_WINDOWS)
        RECLS_ASSERT(::stlsoft::sap_cast<recls_char_t*>(pData + (cDirParts * sizeof(recls_strptrs_t) + cbPath)) == altName);
#endif /* platform */

        info->checkSum                      =   0;
        info->extendedFlags[0]              =   0;
        info->extendedFlags[1]              =   0;

        // full path
        types::traits_type::char_copy(&fullPath[0], entryPath, entryPathLen + 1);
        info->path.begin                    =   fullPath;
        info->path.end                      =   fullPath + entryPathLen;

        // search-relative path
        if (bSearchDirOverlap)
        {
            info->searchRelativePath.begin  =   info->path.begin + rootDirLen;
            info->searchRelativePath.end    =   info->path.end;
        }
        else
        {
            info->searchRelativePath.begin  =   info->path.begin;
            info->searchRelativePath.end    =   info->path.end;
        }

        // Number of relative directory parts
        info->numRelativeDirectoryParts     =   (RECLS_F_DIRECTORY_PARTS == (flags & RECLS_F_DIRECTORY_PARTS)) ? types::count_dir_parts(info->searchRelativePath.begin, info->searchRelativePath.end) : 0;

        // Number of (hard) links; node index & device Id
        if (0 != ((RECLS_F_LINK_COUNT|RECLS_F_NODE_INDEX) & flags) &&
            ss_nullptr_k != st)
        {
            recls_debug3_trace_printf_(
                RECLS_LITERAL("looking up additional attributes for entry %.*s")
            ,   int(entryPathLen), stlsoft::c_str_ptr(entryPath)
            );

            info->numLinks                  =   0;
            info->nodeIndex                 =   0;
            info->deviceId                  =   0;

#ifdef RECLS_USE_WINSTL_LINK_FUNCTIONS_

            DWORD   fileIndexHigh;
            DWORD   fileIndexLow;
            DWORD   deviceId;
            DWORD   numLinks;

            if (winstl::hard_link_get_link_information(
                    entryPath
                ,   &fileIndexHigh
                ,   &fileIndexLow
                ,   &deviceId
                ,   &numLinks
                ))
            {
                if (RECLS_F_LINK_COUNT & flags)
                {
                    info->numLinks          =   numLinks;
                }
                if (RECLS_F_NODE_INDEX & flags)
                {
                    info->nodeIndex         =   recls_uint64_t(fileIndexHigh) << 32 | fileIndexLow;
                    info->deviceId          =   deviceId;
                }
            }
#else /* ? RECLS_USE_WINSTL_LINK_FUNCTIONS_ */

            if (RECLS_F_LINK_COUNT & flags)
            {
                RECLS_ASSERT(ss_nullptr_k != st);

                info->numLinks              =   st->st_nlink;
            }
            if (RECLS_F_NODE_INDEX & flags)
            {
                RECLS_ASSERT(ss_nullptr_k != st);

                info->nodeIndex             =   st->st_ino;
                info->deviceId              =   st->st_dev;
            }
#endif /* RECLS_USE_WINSTL_LINK_FUNCTIONS_ */
        }
        else
        {
            info->numLinks                  =   0;
            info->nodeIndex                 =   0;
            info->deviceId                  =   0;
        }

        // drive, directory, file (name + ext)
#if defined(RECLS_PLATFORM_IS_UNIX)
        info->directory.begin               =   &fullPath[dir0 - entryPath];
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
        info->drive                         =   ('\\' == fullPath[0]) ? '\0' : fullPath[0];
        info->directory.begin               =   &fullPath[dir0 - entryPath];
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
        info->directory.end                 =   fullPath + (entryPathLen - entryFileLen);
        info->fileName.begin                =   info->directory.end;
        info->fileName.end                  =   types::traits_type::str_rchr(info->directory.end, RECLS_LITERAL('.'));
        if (ss_nullptr_k != info->fileName.end)
        {
            info->fileExt.begin             =   info->fileName.end + 1;
            info->fileExt.end               =   info->directory.end +  cchFileName;
        }
        else
        {
            info->fileName.end              =   info->directory.end +  cchFileName;
            info->fileExt.begin             =   info->directory.end +  cchFileName;
            info->fileExt.end               =   info->directory.end +  cchFileName;
        }

        // determine the directory parts
        recls_char_t const*     p           =   info->directory.begin;
        recls_char_t const*     l           =   info->directory.end;
        struct recls_strptrs_t* begin       =   ::stlsoft::sap_cast<struct recls_strptrs_t*>(&info->data[0]);

        info->directoryParts.begin          =   begin;
        info->directoryParts.end            =   begin + cDirParts;

        if (bSearchDirOverlap)
        {
            info->searchDirectory.begin     =   info->path.begin;
            info->searchDirectory.end       =   info->searchDirectory.begin + rootDirLen;
        }
        else
        {
            recls_char_t*   searchCopy      =   ::stlsoft::sap_cast<recls_char_t*>(pSearchCopy);
            info->searchDirectory.begin     =   searchCopy;
            info->searchDirectory.end       =   info->searchDirectory.begin + searchDirLen;
            types::traits_type::char_copy(searchCopy, searchDir, searchDirLen);
            searchCopy[searchDirLen] = '\0';
        }

        if (info->directoryParts.begin != info->directoryParts.end)
        {
            RECLS_ASSERT((flags & RECLS_F_DIRECTORY_PARTS) == RECLS_F_DIRECTORY_PARTS);

            begin->begin = p;

            for (; p != l; ++p)
            {
                if (*p == types::traits_type::path_name_separator())
                {
                    begin->end = p + 1;

                    if (++begin != info->directoryParts.end)
                    {
                        begin->begin = p + 1;
                    }
                }
            }
        }

        if (ss_nullptr_k == st)
        {
            recls_time_t        no_time;
            recls_filesize_t    no_size;

            memset(&no_time, 0, sizeof(no_time));
            memset(&no_size, 0, sizeof(no_size));

            // alt name
#if defined(RECLS_PLATFORM_IS_WINDOWS)
            altName[0] = '\0';
            info->shortFile.begin   =   altName;
            info->shortFile.end     =   altName;
#endif /* platform */

            // attributes
            info->attributes            =   0;

            // time, size
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->lastStatusChangeTime  =   no_time;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->creationTime          =   no_time;
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
            info->modificationTime      =   no_time;
            info->lastAccessTime        =   no_time;
            info->size                  =   no_size;
        }
        else
        {
            RECLS_ASSERT(ss_nullptr_k != st);

            // alt name
#if defined(RECLS_PLATFORM_IS_WINDOWS)
            size_t altLen = types::traits_type::str_len(st->cAlternateFileName);
            types::traits_type::char_copy(altName, st->cAlternateFileName, altLen);
            altName[altLen] = '\0';
            info->shortFile.begin   =   altName;
            info->shortFile.end     =   altName + altLen;
#endif /* platform */

            // attributes
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->attributes            =   st->st_mode;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->attributes            =   st->dwFileAttributes;
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */

            // time, size
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->lastStatusChangeTime  =   st->st_ctime;
            info->modificationTime      =   st->st_mtime;
            info->lastAccessTime        =   st->st_atime;
            info->size                  =   stlsoft::to_uint64(*st);
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->creationTime          =   st->ftCreationTime;
            info->modificationTime      =   st->ftLastWriteTime;
            info->lastAccessTime        =   st->ftLastAccessTime;
            info->size                  =   stlsoft::to_uint64(*st);
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */

            // Handle MARK_DIRS
            if (RECLS_F_MARK_DIRS == (flags & RECLS_F_MARK_DIRS) &&
                types::traits_type::is_directory(st))
            {
                *const_cast<recls_char_t*>(info->path.end)  =   types::traits_type::path_name_separator();
                ++info->path.end;
                *const_cast<recls_char_t*>(info->path.end)  =   '\0';

                ++info->searchRelativePath.end;
            }
        }

        // Checks
        RECLS_ASSERT(info->path.begin < info->path.end);
        RECLS_ASSERT(info->directory.begin < info->directory.end);
        RECLS_ASSERT(info->path.begin <= info->directory.begin);
        RECLS_ASSERT(info->directory.end <= info->path.end);
        RECLS_ASSERT(info->fileName.begin <= info->fileName.end);
        RECLS_ASSERT(info->fileExt.begin <= info->fileExt.end);
        RECLS_ASSERT(info->fileName.begin < info->fileExt.end);
        RECLS_ASSERT(info->fileName.end <= info->fileExt.begin);
    }

    recls_debug1_trace_printf_(
        RECLS_LITERAL("created entry info (%p) for '%.*s'")
    ,   info
    ,   int(entryPathLen), stlsoft::c_str_ptr(entryPath)
    );

    return info;
}

recls_entry_t
create_drive_entryinfo(
    recls_char_t const*             entryPath
,   size_t                          entryPathLen
,   recls_uint32_t                  flags
,   types::stat_data_type const*    st
)
{
    function_scope_trace("create_drive_entryinfo");

    recls_debug2_trace_printf_(
        RECLS_LITERAL("create_drive_entryinfo(%.*s, 0x%08x, ...)")
    ,   int(entryPathLen), stlsoft::c_str_ptr(entryPath)
    ,   flags
    );

    /* const */ size_t    cDirParts   =   0; // This is declared non-const to placate Borland C/C++
    size_t const    cbPath      =   recls_align_up_size_(sizeof(recls_char_t) * (1 + entryPathLen));
    size_t const    cb          =   offsetof(struct recls_entryinfo_t, data)
                                +   cbPath
                                +   1 // In case we need to expand for MARK_DIRS
                                ;

    struct recls_entryinfo_t* info = const_cast<struct recls_entryinfo_t*>(Entry_Allocate(cb));

    if (ss_nullptr_k != info)
    {
        recls_byte_t* const pData       =   &info->data[0];
        recls_byte_t* const pParts      =   pData + 0;
        recls_byte_t* const pPath       =   pParts + (cDirParts * sizeof(recls_strptrs_t));
        recls_char_t*       fullPath    =   ::stlsoft::sap_cast<recls_char_t*>(pPath);

        RECLS_ASSERT(::stlsoft::sap_cast<recls_char_t*>(pData + (cDirParts * sizeof(recls_strptrs_t))) == fullPath);

        info->checkSum                      =   0;
        info->extendedFlags[0]              =   0;
        info->extendedFlags[1]              =   0;

        // full path
        types::traits_type::char_copy(&fullPath[0], entryPath, entryPathLen);
        fullPath[entryPathLen] = '\0';
        info->path.begin                    =   fullPath;
        info->path.end                      =   fullPath + entryPathLen;

        // search-relative path
        info->searchRelativePath.begin      =   info->path.begin;
        info->searchRelativePath.end        =   info->path.end;

        // Number of relative directory parts
        info->numRelativeDirectoryParts     =   0;

        // Number of (hard) links
#if defined(RECLS_PLATFORM_IS_UNIX)
        if (0 != (RECLS_F_LINK_COUNT & flags) &&
            ss_nullptr_k != st)
        {
            RECLS_ASSERT(ss_nullptr_k != st);

            info->numLinks                  =   st->st_nlink;
        }
        else
#else /* ? OS */
        {
            info->numLinks                  =   0;
        }
#endif /* OS */
        // node index and device Id
#if defined(RECLS_PLATFORM_IS_UNIX)
        if (0 != (RECLS_F_NODE_INDEX & flags) &&
            ss_nullptr_k != st)
        {
            RECLS_ASSERT(ss_nullptr_k != st);

            info->nodeIndex                 =   st->st_ino;
            info->deviceId                  =   st->st_dev;
        }
        else
#else /* ? OS */
        {
            info->nodeIndex                 =   0;
            info->deviceId                  =   0;
        }
#endif /* OS */

        // drive, directory, file (name + ext)
        info->directory.begin               =   info->path.end;
#if defined(RECLS_PLATFORM_IS_WINDOWS)
        info->drive                         =   ('\\' == fullPath[0]) ? '\0' : fullPath[0];
#elif defined(RECLS_PLATFORM_IS_UNIX)
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
        info->directory.begin               =   info->path.end;
        info->directory.end                 =   info->path.end;
        info->fileName.begin                =   info->path.end;
        info->fileName.end                  =   info->path.end;
        info->fileExt.begin                 =   info->path.end;
        info->fileExt.end                   =   info->path.end;

        // determine the directory parts
        info->directoryParts.begin          =   ss_nullptr_k;
        info->directoryParts.end            =   ss_nullptr_k;

        info->searchDirectory.begin         =   info->path.end;
        info->searchDirectory.end           =   info->path.end;

        if (ss_nullptr_k == st)
        {
            recls_time_t        no_time;
            recls_filesize_t    no_size;

            memset(&no_time, 0, sizeof(no_time));
            memset(&no_size, 0, sizeof(no_size));

            // alt name
#if defined(RECLS_PLATFORM_IS_WINDOWS)
            info->shortFile.begin           =   info->path.end;
            info->shortFile.end             =   info->path.end;
#endif /* platform */

            // attributes
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->attributes            =   S_IFDIR;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->attributes            =   FILE_ATTRIBUTE_DIRECTORY;
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */

            // time, size
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->lastStatusChangeTime  =   no_time;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->creationTime          =   no_time;
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
            info->modificationTime      =   no_time;
            info->lastAccessTime        =   no_time;
            info->size                  =   no_size;
        }
        else
        {
            // alt name
#if defined(RECLS_PLATFORM_IS_WINDOWS)
            info->shortFile.begin           =   info->path.begin;
            info->shortFile.end             =   info->path.end;
#endif /* platform */

            // attributes
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->attributes            =   st->st_mode;
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->attributes            =   st->dwFileAttributes;
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */

            // time, size
#if defined(RECLS_PLATFORM_IS_UNIX)
            info->lastStatusChangeTime  =   st->st_ctime;
            info->modificationTime      =   st->st_mtime;
            info->lastAccessTime        =   st->st_atime;
            info->size                  =   stlsoft::to_uint64(*st);
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
            info->creationTime          =   st->ftCreationTime;
            info->modificationTime      =   st->ftLastWriteTime;
            info->lastAccessTime        =   st->ftLastAccessTime;
            info->size                  =   stlsoft::to_uint64(*st);
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */

            // Handle MARK_DIRS
            if (RECLS_F_MARK_DIRS == (flags & RECLS_F_MARK_DIRS) &&
                types::traits_type::is_directory(st))
            {
                *const_cast<recls_char_t*>(info->path.end)  =   types::traits_type::path_name_separator();
                ++info->path.end;
                *const_cast<recls_char_t*>(info->path.end)  =   '\0';
            }
        }

        // Checks
        RECLS_ASSERT(info->path.begin < info->path.end);
        RECLS_ASSERT(info->directory.begin == info->directory.end);
        RECLS_ASSERT(info->path.begin < info->directory.begin);
        RECLS_ASSERT(info->directory.end == info->path.end);
        RECLS_ASSERT(info->fileName.begin == info->fileName.end);
        RECLS_ASSERT(info->fileExt.begin == info->fileExt.end);
        RECLS_ASSERT(info->fileName.begin == info->fileExt.end);
        RECLS_ASSERT(info->fileName.end == info->fileExt.begin);
    }

    recls_debug1_trace_printf_(
        RECLS_LITERAL("created drive info (%p) for '%.*s'")
    ,   info
    ,   int(entryPathLen), stlsoft::c_str_ptr(entryPath)
    );

    return info;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

