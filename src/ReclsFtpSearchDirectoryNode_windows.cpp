/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFtpSearchDirectoryNode_windows.cpp
 *
 * Purpose: Implementation of the ReclsFtpSearchDirectoryNode class for
 *          Windows.
 *
 * Created: 1st June 2004
 * Updated: 17th October 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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
#include "impl.types.ftp.hpp"
#include "impl.util.h"
#include "impl.entryfunctions.h"
#include "impl.constants.hpp"

#include "ReclsSearch.hpp"
#include "ReclsFtpSearchDirectoryNode_windows.hpp"

#include "impl.trace.h"

#if defined(RECLS_CHAR_TYPE_IS_WCHAR)
# include <winstl/conversion/char_conversions.hpp>
#endif /* RECLS_CHAR_TYPE_IS_???? */

#if defined(RECLS_PLATFORM_IS_WINDOWS)
# include <winstl/shims/conversion/to_uint64/WIN32_FIND_DATA.hpp>
#endif /* RECLS_PLATFORM_IS_WINDOWS */

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

/// Creates an entry from the platform-specific record

static recls_entry_t
create_entryinfo_from_psrecord(
    recls_char_t const*             rootDir
,   recls_uint32_t                  flags
,   types::find_data_type const&    findData
)
{
    function_scope_trace("create_entryinfo_from_psrecord");

    // size of structure is:
    //
    //    offsetof(struct recls_entryinfo_t, data)
    //  + directory parts
    //  + full path (+ null)
    //  + short name (+ null)

    // Bizarrely, the findData.cFileName can come in either as the file name or as the full path,
    // which means that we're in for some effort to handle that.

    int     isRooted    =   findData.cFileName[0] == '/';
    size_t  cchRootDir  =   types::traits_type::str_len(rootDir);
    size_t  cchEntry    =   types::traits_type::str_len(findData.cFileName);
    size_t  cchFile     =   isRooted ? (cchEntry - ((types::traits_type::str_rchr(findData.cFileName, '/') + 1) - &findData.cFileName[0])) : cchEntry;
    size_t  cchFullPath =   isRooted ? cchEntry : (cchRootDir + cchFile);

    RECLS_ASSERT(cchRootDir > 0);
    RECLS_ASSERT(rootDir[cchRootDir - 1] == types::traits_type::path_name_separator());

    size_t  cDirParts   =   ((flags & RECLS_F_DIRECTORY_PARTS) == RECLS_F_DIRECTORY_PARTS) ? types::count_dir_parts(rootDir, rootDir + cchRootDir) : 0;
    size_t  cbPath      =   recls_align_up_size_(sizeof(recls_char_t) * (1 + cchFullPath));
    size_t  cbAlt       =   recls_align_up_size_(sizeof(recls_char_t) * (1 + RECLS_NUM_ELEMENTS(findData.cAlternateFileName)));
    size_t  cb          =   offsetof(struct recls_entryinfo_t, data)
                        +   cDirParts * sizeof(recls_strptrs_t)
                        +   cbPath
                        +   cbAlt;

    struct recls_entryinfo_t *info   =   const_cast<struct recls_entryinfo_t*>(Entry_Allocate(cb));

    if (ss_nullptr_k != info)
    {
        recls_char_t*           fullPath    =   ::stlsoft::sap_cast<recls_char_t*>(&info->data[cDirParts * sizeof(recls_strptrs_t)]);
        recls_char_t*           altName     =   ::stlsoft::sap_cast<recls_char_t*>(&info->data[cDirParts * sizeof(recls_strptrs_t) + cbPath]);

        // full path
        if (isRooted)
        {
            types::traits_type::char_copy(fullPath, findData.cFileName, cchEntry);
            fullPath[cchEntry] = '\0';
        }
        else
        {
            types::traits_type::char_copy(fullPath, rootDir, cchRootDir);
            types::traits_type::char_copy(fullPath + cchRootDir, findData.cFileName, cchEntry);
            fullPath[cchRootDir + cchEntry] = '\0';
        }

        info->path.begin                    =   fullPath;
        info->path.end                      =   fullPath + cchFullPath;

        recls_debug2_trace_printf_(RECLS_LITERAL("entry: %s"), fullPath);

        // drive, directory, file (name + ext)
        info->drive                         =   '\0';
        info->directory.begin               =   fullPath;
        info->directory.end                 =   fullPath + cchRootDir;
        info->fileName.begin                =   info->directory.end;
#if defined(RECLS_CHAR_TYPE_IS_CHAR)
        info->fileName.end                  =   strrchr(info->directory.end, '.');
#elif defined(RECLS_CHAR_TYPE_IS_WCHAR)
        info->fileName.end                  =   wcsrchr(info->directory.end, L'.');
#else
# error
#endif /* RECLS_CHAR_TYPE_IS_???? */

        if (ss_nullptr_k != info->fileName.end)
        {
            info->fileExt.begin             =   info->fileName.end + 1;
            info->fileExt.end               =   info->directory.end +  cchFile;
        }
        else
        {
            info->fileName.end              =   info->directory.end +  cchFile;
            info->fileExt.begin             =   info->directory.end +  cchFile;
            info->fileExt.end               =   info->directory.end +  cchFile;
        }

        // determine the directory parts
        recls_char_t const*     p           =   info->directory.begin;
        recls_char_t const*     l           =   info->directory.end;
        struct recls_strptrs_t* begin       =   ::stlsoft::sap_cast<struct recls_strptrs_t*>(&info->data[0]);

        info->directoryParts.begin          =   begin;
        info->directoryParts.end            =   begin + cDirParts;

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

        // alt name
        size_t altLen = types::traits_type::str_len(findData.cAlternateFileName);
        types::traits_type::char_copy(altName, findData.cAlternateFileName, altLen);
        altName[altLen] = '\0';
        info->shortFile.begin   =   altName;
        info->shortFile.end     =   altName + altLen;

        // attributes
        info->attributes        =   findData.dwFileAttributes;

        // time, size
        info->creationTime      =   findData.ftCreationTime;
        info->modificationTime  =   findData.ftLastWriteTime;
        info->lastAccessTime    =   findData.ftLastAccessTime;
        info->size              =   stlsoft::to_uint64(findData);

        // Checks
        RECLS_ASSERT(info->path.begin < info->path.end);
        RECLS_ASSERT(info->directory.begin < info->directory.end);
        RECLS_ASSERT(info->path.begin <= info->directory.begin);
        RECLS_ASSERT(info->directory.end <= info->path.end);
        RECLS_ASSERT(info->fileName.begin <= info->fileName.end);
        RECLS_ASSERT(info->fileExt.begin <= info->fileExt.end);
        RECLS_ASSERT(types::traits_type::str_len(info->fileExt.begin) == static_cast<size_t>(info->fileExt.end - info->fileExt.begin));
        RECLS_ASSERT(info->fileName.begin < info->fileExt.end);
        RECLS_ASSERT(info->fileName.end <= info->fileExt.begin);
        RECLS_ASSERT(info->directory.end == info->fileName.begin);
    }

    return info;
}

/* /////////////////////////////////////////////////////////////////////////
 * ReclsFtpSearchDirectoryNode
 */

/* static */ ReclsFtpSearchDirectoryNode::directory_sequence_type::const_iterator
ReclsFtpSearchDirectoryNode::select_iter_if_(
    unsigned long                           b
,   directory_sequence_type::const_iterator trueVal
,   directory_sequence_type::const_iterator falseVal
)
{
    // I can't explain it, but Borland does not like the tertiary operator and the copy-ctors of the iterators
    if (b)
    {
        return trueVal;
    }
    else
    {
        return falseVal;
    }
}

/* static */ int
ReclsFtpSearchDirectoryNode::essFlags_from_reclsFlags_(
    recls_uint32_t flags
)
{
#if defined(RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_)
    // Because Digital Mars 8.40- has a problem, we must access the typedef separately from the enum value
    typedef entry_sequence_type::find_sequence_type sequence_t;
#else /* ? RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_ */
    typedef entry_sequence_type                     sequence_t;
#endif /* RECLS_USING_INETSTL_SEARCHSPEC_SEQUENCE_ */

    int ssFlags = 0;

    if (0 != (flags & RECLS_F_FILES))
    {
        ssFlags |= sequence_t::files;
    }
    if (0 != (flags & RECLS_F_DIRECTORIES))
    {
        ssFlags |= sequence_t::directories;
    }

    return ssFlags;
}

inline
/* static */ ReclsFtpSearchDirectoryNode::directory_sequence_type
ReclsFtpSearchDirectoryNode::init_directories_(
    HINTERNET               connection
,   recls_char_t const*     rootDir
,   size_t               /* rootDirLen */
,   recls_uint32_t          flags
)
{
    RECLS_ASSERT(ss_nullptr_k != connection);

    directory_sequence_type     dirs;

    if (flags & RECLS_F_RECURSIVE)
    {
        file_find_sequence_type     directories(connection, rootDir, types::traits_type::pattern_all(), file_find_sequence_type::directories);

        file_find_sequence_type::const_iterator begin   =   directories.begin();
        file_find_sequence_type::const_iterator end     =   directories.end();

        for (; begin != end; ++begin)
        {
            dirs.push_back((*begin).get_path());
        }
    }

    return dirs;
}

ReclsFtpSearchDirectoryNode::ReclsFtpSearchDirectoryNode(
    HINTERNET           connection
,   recls_uint32_t      flags
,   recls_char_t const* rootDir
,   size_t              rootDirLen
,   recls_char_t const* pattern
,   size_t              patternLen
)
    : m_connection(connection)
    , m_current(ss_nullptr_k)
    , m_dnode(ss_nullptr_k)
    , m_flags(flags)
    , m_rootDir()
    , m_pattern()
    , m_directories(init_directories_(connection, rootDir, rootDirLen, flags))
    , m_directoriesBegin(m_directories.begin())
    , m_entries(
            connection
        ,   rootDir
        ,   pattern
#if defined(RECLS_USE_NEW_INETSTL_FFS) || \
    defined(RECLS_SUPPORTS_MULTIPATTERN_)
        ,   types::traits_type::path_separator()
#else /* ? RECLS_USE_NEW_INETSTL_FFS || RECLS_SUPPORTS_MULTIPATTERN_ */
#endif /* RECLS_USE_NEW_INETSTL_FFS || RECLS_SUPPORTS_MULTIPATTERN_ */
        ,   essFlags_from_reclsFlags_(flags)
        )
    , m_entriesBegin(m_entries.begin())
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::ReclsFtpSearchDirectoryNode");

    RECLS_ASSERT(ss_nullptr_k != m_connection);

    if (0 == types::traits_type::str_n_compare(constants::local_directory().data(), pattern, patternLen))
    {
        // This special case handles "." as a search pattern.
        string_type temp(rootDir, rootDirLen);

        if (!temp.empty() &&
            temp[temp.length() - 1] == '/')
        {
            temp = string_type(&temp[0], &temp[temp.length() - 1]);
        }

        size_t          cch = types::traits_type::get_full_path_name(m_connection, stlsoft::c_str_ptr(temp), 0, ss_nullptr_k);
        string_type     temp2(cch, ' ');
        recls_char_t*   file = ss_nullptr_k; // GCC requires this be initialised

        types::traits_type::get_full_path_name(m_connection, stlsoft::c_str_ptr(temp), 1 + temp2.length(), &temp2[0], &file);

        m_rootDir.assign(&temp2[0], file);
        m_pattern.assign(file);
    }
    else
    {
        m_rootDir = rootDir;
        if (!m_rootDir.empty() &&
            m_rootDir[m_rootDir.length() - 1] != '/')
        {
            m_rootDir += '/';
        }
        m_pattern.assign(pattern, patternLen);
    }

    RECLS_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_entries) < STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_entriesBegin));
    RECLS_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_directories) < STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_directoriesBegin));

#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT
    STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_entries) < STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_entriesBegin));
    STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_directories) < STLSOFT_RAW_OFFSETOF(ReclsFtpSearchDirectoryNode, m_directoriesBegin));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */
}

/* static */ ReclsFtpSearchDirectoryNode*
ReclsFtpSearchDirectoryNode::FindAndCreate(
    HINTERNET           connection
,   recls_uint32_t      flags
,   recls_char_t const* rootDir
,   size_t              rootDirLen
,   recls_char_t const* pattern
,   size_t              patternLen
)
{
    ReclsFtpSearchDirectoryNode* node;

    function_scope_trace("ReclsFtpSearchDirectoryNode::FindAndCreate");

#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
    try
    {
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */
        node = new ReclsFtpSearchDirectoryNode(connection, flags, rootDir, rootDirLen, pattern, patternLen);
#ifdef RECLS_COMPILER_THROWS_ON_NEW_FAIL
    }
    catch (std::bad_alloc&)
    {
        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        node = ss_nullptr_k;
    }
#endif /* RECLS_COMPILER_THROWS_ON_NEW_FAIL */

    if (ss_nullptr_k != node)
    {
        // Ensure that it, or one of its sub-nodes, has matching entries.
        recls_rc_t  rc = node->Initialise();

        if (RECLS_FAILED(rc))
        {
            delete node;

            node = ss_nullptr_k;
        }
    }

    RECLS_ASSERT(ss_nullptr_k == node || node->is_valid());

    return node;
}

ReclsFtpSearchDirectoryNode::~ReclsFtpSearchDirectoryNode()
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::~ReclsFtpSearchDirectoryNode");

    Entry_Release(m_current);

    delete m_dnode;
}

recls_rc_t
ReclsFtpSearchDirectoryNode::Initialise()
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::Initialise");

    recls_rc_t  rc;

    RECLS_ASSERT(ss_nullptr_k == m_current);
    RECLS_ASSERT(ss_nullptr_k == m_dnode);

    if (m_entriesBegin != m_entries.end())
    {
        // (i) Try getting a file first,
        m_current = create_entryinfo_from_psrecord(stlsoft::c_str_ptr(m_rootDir), m_flags, (*m_entriesBegin).get_find_data());

        if (ss_nullptr_k == m_current)
        {
            rc = RECLS_RC_OUT_OF_MEMORY;
        }
        else
        {
            rc = RECLS_RC_OK;
        }
    }
    else
    {
        if (m_directoriesBegin == m_directories.end())
        {
            rc = RECLS_RC_NO_MORE_DATA;
        }
        else
        {
            do
            {
                m_dnode = ReclsFtpSearchDirectoryNode::FindAndCreate(
                    m_connection
                ,   m_flags
                ,   stlsoft::c_str_ptr(*m_directoriesBegin)
                ,   stlsoft::c_str_len(*m_directoriesBegin)
                ,   m_pattern.data()
                ,   m_pattern.size()
                );

            } while (ss_nullptr_k == m_dnode && ++m_directoriesBegin != m_directories.end());

            rc = (ss_nullptr_k == m_dnode) ? RECLS_RC_NO_MORE_DATA : RECLS_RC_OK;
        }
    }

    if (RECLS_SUCCEEDED(rc))
    {
        RECLS_ASSERT(is_valid());
    }

    return rc;
}

#ifdef RECLS_ENFORCING_CONTRACTS
recls_bool_t
ReclsFtpSearchDirectoryNode::is_valid() const
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::is_valid");

    recls_rc_t  rc  =   RECLS_RC_OK;

#if defined(RECLS_PRAGMA_MESSAGE_SUPPORT) && \
    !defined(RECLS_PRAGMA_MESSAGE_IS_INTRUSIVE)
# pragma message("Flesh these out")
    if (RECLS_SUCCEEDED(rc))
    {
    }
#endif /* compiler */

    // (i) Either we are enumerating files (m_current != NULL) or directories (m_dnode != NULL), but not both
    RECLS_ASSERT(ss_nullptr_k == m_current || ss_nullptr_k == m_dnode);
    // (ii) Either we are enumerating files (m_current != NULL) or there are no more files to enumerate
    RECLS_ASSERT(ss_nullptr_k != m_current || m_entriesBegin == m_entries.end());

    return RECLS_SUCCEEDED(rc);
}
#endif /* RECLS_ENFORCING_CONTRACTS */

recls_rc_t
ReclsFtpSearchDirectoryNode::GetNext()
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::GetNext");

    RECLS_ASSERT(is_valid());

    /* Searching operates as follows:
     *
     * 1. Return all the contents of the files
     * 2. Return the contents of the directories.
     *
     * Hence, if m_dnode is non-NULL, we've already searched
     */

    /* States:
     *
     * - Iterating files: m_entriesBegin != m_entries.end(), m_dnode is NULL, m_directoriesBegin != m_directories.end()
     * - Iterating directories: m_directoriesBegin != m_directories.end(), m_dnode is non-NULL, m_current is NULL
     *
     */

    // Invariants

    // (i) Either we are enumerating files (m_current != NULL) or directories (m_dnode != NULL), but not both
    RECLS_ASSERT(ss_nullptr_k == m_current || ss_nullptr_k == m_dnode);
    // (ii) Either we are enumerating files (m_current != NULL) or there are no more files to enumerate
    RECLS_ASSERT(ss_nullptr_k != m_current || m_entriesBegin == m_entries.end());

    recls_rc_t  rc = RECLS_RC_NO_MORE_DATA;

    if (ss_nullptr_k != m_current)
    {
        // Currently enumerating through the files

        RECLS_ASSERT(m_entriesBegin != m_entries.end());
        RECLS_ASSERT(ss_nullptr_k == m_dnode);

        // Advance, and check for end of sequence
        ++m_entriesBegin;

        Entry_Release(m_current);
        if (m_entriesBegin != m_entries.end())
        {
            // Still enumerating, so just update m_current
            m_current = create_entryinfo_from_psrecord(stlsoft::c_str_ptr(m_rootDir), m_flags, (*m_entriesBegin).get_find_data());

            rc = RECLS_RC_OK;
        }
        else
        {
            // No more left in the files sequence, so delete m_current
            m_current = ss_nullptr_k;

            rc = RECLS_RC_NO_MORE_DATA;
        }
    }

    if (ss_nullptr_k == m_current)
    {
        // Now we are either enumerating the directories, or we've already done so

        if (ss_nullptr_k != m_dnode)
        {
            // Currently enumerating the directories
            rc = m_dnode->GetNext();

            if (RECLS_RC_NO_MORE_DATA == rc)
            {
                ++m_directoriesBegin;

                delete m_dnode;

                m_dnode = ss_nullptr_k;
            }
        }

        if (m_directoriesBegin == m_directories.end())
        {
            // Enumeration is complete.
            rc = RECLS_RC_NO_MORE_DATA;
        }
        else
        {
            if (ss_nullptr_k == m_dnode)
            {
                do
                {
                    // Creation of the node will cause it to enter the first enumeration
                    // state. However, if there are no matching

                    RECLS_ASSERT(m_directoriesBegin != m_directories.end());

                    m_dnode = ReclsFtpSearchDirectoryNode::FindAndCreate(
                        m_connection
                    ,   m_flags
                    ,   stlsoft::c_str_ptr(*m_directoriesBegin)
                    ,   stlsoft::c_str_len(*m_directoriesBegin)
                    ,   m_pattern.data()
                    ,   m_pattern.size()
                    );

                    if (ss_nullptr_k != m_dnode)
                    {
                        rc = RECLS_RC_OK;
                    }
                    else
                    {
                        ++m_directoriesBegin;
                    }

                } while (ss_nullptr_k == m_dnode && m_directoriesBegin != m_directories.end());
            }
        }
    }

    RECLS_ASSERT(is_valid());

    return rc;
}

recls_rc_t
ReclsFtpSearchDirectoryNode::GetDetails(
    recls_entry_t* pinfo
)
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::GetDetails");

    RECLS_ASSERT(is_valid());

    recls_rc_t  rc;

    RECLS_ASSERT(ss_nullptr_k != pinfo);
    RECLS_ASSERT(ss_nullptr_k == m_current || ss_nullptr_k == m_dnode);

    if (ss_nullptr_k != m_current)
    {
        // Currently searching for files from the current directory

        RECLS_ASSERT(ss_nullptr_k == m_dnode);

        rc = Entry_Copy(m_current, pinfo);

#if RECLS_TRACE_LEVEL >= 2
        {
            size_t      cch =   Recls_GetPathProperty(m_current, ss_nullptr_k, 0);
            string_type buffer(cch, ' ');

            Recls_GetPathProperty(m_current, &buffer[0], 1 + buffer.length());

# if defined(RECLS_CHAR_TYPE_IS_CHAR)
            recls_debug2_trace_printf_("    [%s]", stlsoft::c_str_ptr(buffer));
# elif defined(RECLS_CHAR_TYPE_IS_WCHAR)
            recls_debug2_trace_printf_("    [%s]", static_cast<char const*>(winstl::w2a(buffer)));
# endif /* RECLS_CHAR_TYPE_IS_???? */
        }
#endif /* RECLS_TRACE_LEVEL >= 2 */
    }
    else if (ss_nullptr_k != m_dnode)
    {
        RECLS_ASSERT(ss_nullptr_k == m_current);

        // Sub-directory searching is active, so get from there.

        rc = m_dnode->GetDetails(pinfo);
    }
    else
    {
        // Enumeration has completed
        rc = RECLS_RC_NO_MORE_DATA;
    }

    RECLS_ASSERT(is_valid());

    return rc;
}

recls_rc_t
ReclsFtpSearchDirectoryNode::GetNextDetails(
    recls_entry_t* pinfo
)
{
    function_scope_trace("ReclsFtpSearchDirectoryNode::GetNextDetails");

    RECLS_ASSERT(is_valid());
    RECLS_ASSERT(ss_nullptr_k != pinfo);

    recls_rc_t rc = GetNext();

    if (RECLS_SUCCEEDED(rc))
    {
        rc = GetDetails(pinfo);
    }

    RECLS_ASSERT(is_valid());

    return rc;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

