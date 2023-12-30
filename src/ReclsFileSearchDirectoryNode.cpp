/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearchDirectoryNode.cpp
 *
 * Purpose:     Implementation of the ReclsFileSearchDirectoryNode class.
 *
 * Created:     31st May 2004
 * Updated:     30th December 2023
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
#include "impl.types.hpp"
#include "impl.string.hpp"
#include "impl.util.h"
#include "impl.entryfunctions.h"
#include "impl.entryinfo.hpp"
#include "impl.cover.h"

#include "ReclsFileSearchDirectoryNode.hpp"

#include "impl.trace.h"

#if defined(RECLS_CHAR_TYPE_IS_WCHAR)
# if defined(RECLS_PLATFORM_IS_WINDOWS)
#  include <winstl/conversion/char_conversions.hpp>
# endif /* RECLS_PLATFORM_IS_WINDOWS */
#endif /* RECLS_CHAR_TYPE_IS_???? */

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
# if defined(RECLS_PLATFORM_IS_WINDOWS)
#  ifdef RECLS_STLSOFT_1_10_B01_OR_LATER
#   include <winstl/exception/access_exception.hpp>
#  else /* ? STLSoft verosion */
#   include <winstl/error/exceptions.hpp>
#  endif /* STLSoft verosion */
# endif /* RECLS_PLATFORM_IS_WINDOWS */
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

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
 * ReclsFileSearchDirectoryNode
 */

/* static */ int ReclsFileSearchDirectoryNode::essFlags_from_reclsFlags_(
    recls_uint32_t flags
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::essFlags_from_reclsFlags_");

    RECLS_COVER_MARK_LINE();

#ifdef RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_
    // Because Digital Mars 8.40- has a problem, we must access the typedef separately from the enum value
    typedef entry_sequence_type::find_sequence_type sequence_t;
#else /* ? RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_ */
    typedef entry_sequence_type                     sequence_t;
#endif /* RECLS_USING_STLSOFT_SEARCHSPEC_SEQUENCE_ */

    int ssFlags = 0;

    if (0 != (flags & RECLS_F_FILES))
    {
        RECLS_COVER_MARK_LINE();

        ssFlags |= sequence_t::files;
    }
    if (0 != (flags & RECLS_F_DIRECTORIES))
    {
        RECLS_COVER_MARK_LINE();

        ssFlags |= sequence_t::directories;
    }

    if (0 != (flags & RECLS_F_STOP_ON_ACCESS_FAILURE))
    {
#if defined(_WINSTL_VER) && \
    _WINSTL_VER >= 0x010a05ff
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ssFlags |= sequence_t::throwOnAccessFailure;
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif
    }

    return ssFlags;
}

/* static */ int ReclsFileSearchDirectoryNode::dssFlags_from_reclsFlags_(
    recls_uint32_t flags
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::dssFlags_from_reclsFlags_");

    RECLS_COVER_MARK_LINE();

    typedef directory_sequence_type sequence_t;

    int ssFlags = 0;

    ssFlags |= sequence_t::directories;

#if defined(RECLS_PLATFORM_IS_UNIX)
# ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
#  pragma message(_sscomp_fileline_message("TODO: Make this for all, once findfile_sequence supports fullPath"))
# endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

    ssFlags |= sequence_t::fullPath;
#endif /* platform */

    if (0 == (flags & RECLS_F_ALLOW_REPARSE_DIRS))
    {
        RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        ssFlags |= sequence_t::skipReparseDirs;
#endif /* platform */
    }

    if (0 != (flags & RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS))
    {
        RECLS_COVER_MARK_LINE();

// TODO: Update this for UNIX when functionality available in UNIXSTL

#ifdef RECLS_PLATFORM_IS_WINDOWS
        ssFlags |= sequence_t::skipHiddenFiles;
        ssFlags |= sequence_t::skipHiddenDirs;
#endif /* RECLS_PLATFORM_IS_WINDOWS */
    }

    if (0 != (flags & RECLS_F_STOP_ON_ACCESS_FAILURE))
    {
#if defined(_WINSTL_VER) && \
    _WINSTL_VER >= 0x010a05ff
# ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        ssFlags |= sequence_t::throwOnAccessFailure;
# endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
#endif
    }

    return ssFlags;
}

/* static */ ReclsFileSearchDirectoryNode::directory_sequence_type::const_iterator ReclsFileSearchDirectoryNode::select_iter_if_(unsigned long b, directory_sequence_type::const_iterator trueVal, directory_sequence_type::const_iterator falseVal)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::select_iter_if_");

    RECLS_COVER_MARK_LINE();

    // I can't explain it, but Borland does not like the tertiary operator and the copy-ctors of the iterators
    if (b)
    {
        RECLS_COVER_MARK_LINE();

        return trueVal;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        return falseVal;
    }
}

/* static */ size_t ReclsFileSearchDirectoryNode::prepare_searchDir_(
    file_path_buffer_type&  buff
,   recls_char_t const*     searchDir
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::prepare_searchDir_");

    RECLS_COVER_MARK_LINE();

    size_t len = types::traits_type::str_len(searchDir);

    buff[len] = '\0';
    types::traits_type::char_copy(&buff[0], searchDir, len);

    RECLS_MESSAGE_ASSERT("I _think_ this should never happen. Please report if it does.", 0 != len);

    if (0 != len &&
        !types::traits_type::has_dir_end(&buff[0] + (len - 1)))
    {
        RECLS_COVER_MARK_LINE();

        types::traits_type::ensure_dir_end(&buff[0] + (len - 1));
        ++len;
    }

    return len;
}

/* static */ recls_entry_t ReclsFileSearchDirectoryNode::CreateEntryInfo(
    size_t                                                              rootDirLen
,   recls_char_t const*                                                 searchDir
,   size_t                                                              searchDirLen
,   recls_uint32_t                                                      flags
,   ReclsFileSearchDirectoryNode::entry_sequence_type::const_iterator   it
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::CreateEntryInfo");

    RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_UNIX)

    typedef int (*PfnStat)(char const*, struct stat*);

# if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    PfnStat             pfn =   ::stat;
# else /* ? RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */
    PfnStat             pfn =   (RECLS_F_LINKS == (flags & RECLS_F_LINKS)) ? ::lstat : ::stat;
# endif /* RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS */
    struct stat         st;
    recls_char_t const* entryPath = *it;

    if (0 != (*pfn)(entryPath, &st))
    {
        RECLS_COVER_MARK_LINE();

        // This will cause RECLS_F_OUT_OF_MEMORY.
        // TODO: Fix it!
        return NULL;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        size_t const        entryPathLen    =   types::traits_type::str_len(entryPath);
        recls_char_t const* entryFile       =   types::traits_type::str_rchr(&entryPath[0], types::traits_type::path_name_separator()) + 1;
        RECLS_ASSERT(NULL != (entryFile - 1));
        size_t const        entryFileLen    =   entryPathLen - (entryFile - entryPath);
        RECLS_ASSERT(entryFileLen == types::traits_type::str_len(entryFile));

        return create_entryinfo(rootDirLen, searchDir, searchDirLen, entryPath, entryPathLen, entryFile, entryFileLen, flags, &st);
    }
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    // In this case:
    //
    // - searchDir contains the directory that was searched
    // - it contains the iterator from which the full path and the stat data may be obtained.
    //    Note: the full path may contain additional subdirectories over and above that of searchDir
#if 0
    ReclsFileSearchDirectoryNode::entry_sequence_type::value_type const &value  =   *it;
#else /* ? 0 */
    ReclsFileSearchDirectoryNode::entry_sequence_type::const_reference  value   =   *it;
#endif /* 0 */

    recls_char_t const* entryPath       =   value.get_path();
    size_t const        entryPathLen    =   stlsoft::c_str_len(value);
    recls_char_t const* entryFile       =   types::traits_type::str_rchr(&entryPath[0], types::traits_type::path_name_separator()) + 1;
    RECLS_ASSERT(NULL != (entryFile - 1));
    size_t const        entryFileLen    =   entryPathLen - (entryFile - entryPath);
    RECLS_ASSERT(entryFileLen == types::traits_type::str_len(entryFile));

    return create_entryinfo(rootDirLen, searchDir, searchDirLen, entryPath, entryPathLen, entryFile, entryFileLen, flags, &value.get_find_data());
#else /* ? platform */
# error Platform not discriminated
#endif /* platform */
}

ReclsFileSearchDirectoryNode::ReclsFileSearchDirectoryNode(
    recls_uint32_t              flags
,   recls_char_t const*         searchDir
,   size_t                      rootDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
)
    : m_current(NULL)
    , m_dnode(NULL)
    , m_flags(flags)
    , m_rootDirLen(rootDirLen)
    , m_searchDir()
    , m_searchDirLen(prepare_searchDir_(m_searchDir, searchDir))
    , m_pattern(pattern)
    , m_patternLen(patternLen)
    , m_directories(searchDir
#if defined(RECLS_PLATFORM_IS_WINDOWS)    // Windows uses findfile_sequence, which takes wildcards
                ,   types::traits_type::pattern_all()
#endif /* platform */
                ,   dssFlags_from_reclsFlags_(flags))
    , m_directoriesBegin(select_iter_if_((flags & RECLS_F_RECURSIVE), m_directories.begin(), m_directories.end()))
    , m_entries(searchDir
            ,   pattern
#ifdef RECLS_SUPPORTS_MULTIPATTERN_
            ,   types::traits_type::path_separator()
#endif /* RECLS_SUPPORTS_MULTIPATTERN_ */
            ,   essFlags_from_reclsFlags_(flags))
    , m_entriesBegin(m_entries.begin())
    , m_pfn(pfn)
    , m_param(param)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::ReclsFileSearchDirectoryNode");

    RECLS_ASSERT(0 != m_searchDirLen);
    RECLS_ASSERT(types::traits_type::is_path_name_separator(m_searchDir[m_searchDirLen - 1]));

    RECLS_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_entries) < STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_entriesBegin));
    RECLS_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_directories) < STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_directoriesBegin));

#ifdef STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT
    STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_entries) < STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_entriesBegin));
    STLSOFT_STATIC_ASSERT(STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_directories) < STLSOFT_RAW_OFFSETOF(ReclsFileSearchDirectoryNode, m_directoriesBegin));
#endif /* STLSOFT_CF_USE_RAW_OFFSETOF_IN_STATIC_ASSERT */

    RECLS_COVER_MARK_LINE();
}

/* static */ ReclsFileSearchDirectoryNode* ReclsFileSearchDirectoryNode::FindAndCreate(
    recls_uint32_t              flags
,   recls_char_t const*         searchDir
,   size_t                      rootDirLen
,   recls_char_t const*         pattern
,   size_t                      patternLen
,   hrecls_progress_fn_t        pfn
,   recls_process_fn_param_t    param
,   recls_rc_t*                 prc
)
{
    ReclsFileSearchDirectoryNode* node;

    RECLS_ASSERT(rootDirLen <= types::traits_type::str_len(searchDir));
    RECLS_ASSERT(patternLen == types::traits_type::str_len(pattern));
    RECLS_ASSERT(NULL != prc);

    function_scope_trace("ReclsFileSearchDirectoryNode::FindAndCreate");

    RECLS_COVER_MARK_LINE();

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    try
    {
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        RECLS_COVER_MARK_LINE();

        node = new ReclsFileSearchDirectoryNode(flags, searchDir, rootDirLen, pattern, patternLen, pfn, param);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    }
# if _STLSOFT_VER >= 0x01097bff
#  if defined(PLATFORMSTL_OS_IS_UNIX)
    catch(unixstl::readdir_sequence_exception& x)
    {
        RECLS_COVER_MARK_LINE();

        recls_error_trace_printf_(RECLS_LITERAL("could not enumerate contents of directory '%s'"), x.Directory.c_str());

        *prc = RECLS_RC_ACCESS_DENIED;

        node = NULL;
    }
#  endif /* OS */
# endif /* _STLSOFT_VER */
    catch(std::bad_alloc&)
    {
        RECLS_COVER_MARK_LINE();

        recls_error_trace_printf_(RECLS_LITERAL("out of memory"));

        *prc = RECLS_RC_OUT_OF_MEMORY;

        node = NULL;
    }
# if defined(_WINSTL_VER) && \
     _WINSTL_VER >= 0x010a05ff
    catch(winstl_ns_qual(access_exception)& x)
    {
        RECLS_COVER_MARK_LINE();

#  if defined(RECLS_CHAR_TYPE_IS_WCHAR)
        recls_error_trace_printf_(winstl::a2t(x.what()).c_str());
#  else
        recls_error_trace_printf_(x.what());
#  endif

        *prc = RECLS_RC_ACCESS_DENIED;

        node = NULL;
    }
# endif
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

    if (NULL != node)
    {
        RECLS_COVER_MARK_LINE();

        // Ensure that it, or one of its sub-nodes, has matching entries.
        recls_rc_t rc = node->Initialise();

        if (RECLS_FAILED(rc))
        {
            RECLS_COVER_MARK_LINE();

            delete node;

            node = NULL;
        }

        *prc = rc;
    }

    RECLS_ASSERT(NULL == node || node->is_valid());

    return node;
}

/* static */ recls_rc_t ReclsFileSearchDirectoryNode::Stat(
    recls_char_t const* path
,   recls_uint32_t      flags
,   recls_entry_t*      phEntry
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::Stat");

    RECLS_COVER_MARK_LINE();

    // 1. Ensure that the path is valid
    //
    // 1.a Must not be NULL
    if (NULL == path ||
        '\0' == 0[path])
    {
        RECLS_COVER_MARK_LINE();

        return RECLS_RC_INVALID_NAME;
    }

    recls_debug1_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(path=%s, flags=0x%08x, ...)"), path, flags);

    RECLS_COVER_MARK_LINE();

    //
    // 1.b Must not be > max_path()
    const size_t pathLen = types::traits_type::str_len(path);

    if (pathLen > types::traits_type::path_max())
    {
        RECLS_COVER_MARK_LINE();

        recls_log_printf_(RECLS_SEVIX_WARN, RECLS_LITERAL("path limit exceeded: limit=%u; len=%u"), unsigned(types::traits_type::path_max()), unsigned(pathLen));

        return RECLS_RC_PATH_LIMIT_EXCEEDED;
    }

    recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 3"));

    RECLS_COVER_MARK_LINE();

    // 1. c Ensure that is has the correct slashes
    types::file_path_buffer_type path_;

    path = types::traits_type::char_copy(&path_[0], path, pathLen);
    path_[pathLen] = '\0';

    recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 4"));

    // stat() of root is now supported!
    if (types::traits_type::is_root_designator(path))
    {
        RECLS_COVER_MARK_LINE();

# if 1
        *phEntry = create_drive_entryinfo(path, pathLen, flags, NULL);
# else /* ? 0 */
        *phEntry = create_entryinfo(0, NULL, 0, path, pathLen, path + pathLen, 0, flags, NULL);
# endif /* 0 */

        return (NULL == *phEntry) ? RECLS_RC_OUT_OF_MEMORY : RECLS_RC_OK;
    }

    recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 6"));

    RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS)
    // emulated UNIX
    if (!types::traits_type::is_path_UNC(path))
    {
        RECLS_COVER_MARK_LINE();

        std::replace(&path_[0], &path_[0] + path_.size(), RECLS_LITERAL('\\'), RECLS_LITERAL('/'));
    }
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    std::replace(&path_[0], &path_[0] + path_.size(), RECLS_LITERAL('/'), RECLS_LITERAL('\\'));
# endif /* Windows && EMULATE_UNIX_ON_WINDOWS */

    recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 8"));

    // Now need to remove the directory end, if any
    types::traits_type::remove_dir_end(&path_[0]);

    types::traits_type::stat_data_type  st;
    types::traits_type::stat_data_type* pst = &st;

    if (!types::traits_type::stat(path, &st))
    {
        RECLS_COVER_MARK_LINE();

        recls_log_printf_(
          (flags & RECLS_F_DETAILS_LATER) ? RECLS_SEVIX_INFO : RECLS_SEVIX_WARN
        , RECLS_LITERAL("stat() failed on %s")
        , path
        );

        pst = NULL;
    }

    recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 10"));

    if (NULL == pst &&
        RECLS_F_DETAILS_LATER != (flags & (RECLS_F_DETAILS_LATER | RECLS_F_TYPEMASK))) // To allow non-existant things to be stat'd
    {
        RECLS_COVER_MARK_LINE();

        recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 11"));

        return RECLS_RC_NO_MORE_DATA;
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 12"));

        size_t const        pathLen2        =   types::traits_type::str_len(path);
        recls_char_t const* entryFile       =   types::traits_type::str_rchr(path, types::traits_type::path_name_separator()) + 1;
        RECLS_ASSERT(NULL != (entryFile - 1));
        size_t const        entryDirLen     =   static_cast<size_t>(entryFile - path);
        size_t const        entryFileLen    =   pathLen2 - entryDirLen;
        RECLS_ASSERT(entryFileLen == types::traits_type::str_len(entryFile));

        recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 13"));

        recls_debug2_trace_printf_(RECLS_LITERAL("path=%s"), path);

        recls_debug2_trace_printf_(RECLS_LITERAL("%d %d %d %d %d %d"),
            int(entryDirLen), int(entryDirLen)
        ,   int(pathLen2), int(pathLen2)
        ,   int(entryFileLen), int(entryFileLen)
        );

        recls_debug2_trace_printf_(
            RECLS_LITERAL("[create_entryinfo(%.*s [%d], %.*s [%d], %.*s [%d], 0x%08x]")
        ,   int(entryDirLen), path, int(entryDirLen)
        ,   int(pathLen2), path, int(pathLen2)
        ,   int(entryFileLen), entryFile, int(entryFileLen)
        ,   static_cast<unsigned int>(flags)
        );

        recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 14"));

        *phEntry = create_entryinfo(pathLen2, path, entryDirLen, path, pathLen2, entryFile, entryFileLen, flags, pst);

        recls_debug2_trace_printf_(RECLS_LITERAL("ReclsFileSearchDirectoryNode::Stat(): 15"));

        return (NULL == *phEntry) ? RECLS_RC_OUT_OF_MEMORY : RECLS_RC_OK;
    }

#if defined(STLSOFT_COMPILER_IS_GCC)
    RECLS_COVER_MARK_LINE();

    RECLS_MESSAGE_ASSERT("Should never reach here", 0);

    return RECLS_RC_OK;
#endif /* GCC */
}

ReclsFileSearchDirectoryNode::~ReclsFileSearchDirectoryNode()
{
    function_scope_trace("ReclsFileSearchDirectoryNode::~ReclsFileSearchDirectoryNode");

    RECLS_COVER_MARK_LINE();

    Entry_Release(m_current);

    delete m_dnode;
}

recls_rc_t ReclsFileSearchDirectoryNode::Initialise()
{
    function_scope_trace("ReclsFileSearchDirectoryNode::Initialise");

    recls_rc_t rc = RECLS_RC_OK;

    RECLS_ASSERT(NULL == m_current);
    RECLS_ASSERT(NULL == m_dnode);

    RECLS_COVER_MARK_LINE();

    if (NULL != m_pfn)
    {
        RECLS_COVER_MARK_LINE();

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        if (m_flags & RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS)
        {
            RECLS_COVER_MARK_LINE();

            typedef int (RECLS_CALLCONV_STDDECL *stdcall_progress_fn_t)(recls_char_t const*
                                                                    ,   size_t
                                                                    ,   recls_process_fn_param_t
                                                                    ,   void*
                                                                    ,   recls_uint32_t);

            stdcall_progress_fn_t   pfn_stdcall =   (stdcall_progress_fn_t)m_pfn;

            (*pfn_stdcall)(m_searchDir.c_str(), m_searchDirLen, m_param, NULL, 0);
        }
        else
#endif /* RECLS_PLATFORM_IS_WINDOWS */
        {
            RECLS_COVER_MARK_LINE();

            if (0 == (*m_pfn)(m_searchDir.c_str(), m_searchDirLen, m_param, NULL, 0))
            {
                RECLS_COVER_MARK_LINE();

                return RECLS_RC_USER_CANCELLED_SEARCH;
            }
        }
    }

    RECLS_COVER_MARK_LINE();

    if (m_entriesBegin != m_entries.end())
    {
        RECLS_COVER_MARK_LINE();

        recls_debug2_trace_printf_(RECLS_LITERAL("Next entry in %s"), static_cast<recls_char_t const*>(stlsoft::c_str_ptr(m_searchDir)));

        // (i) Try getting a file first,
        m_current = CreateEntryInfo(m_rootDirLen, stlsoft::c_str_ptr(m_searchDir), m_searchDirLen, m_flags, m_entriesBegin);

        if (NULL == m_current)
        {
            RECLS_COVER_MARK_LINE();

            rc = RECLS_RC_OUT_OF_MEMORY;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            rc = RECLS_RC_OK;
        }
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        if (m_directoriesBegin == m_directories.end())
        {
            RECLS_COVER_MARK_LINE();

            rc = RECLS_RC_NO_MORE_DATA;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

//          recls_debug2_trace_printf_("Next directory in %s", static_cast<char const*>(stlsoft::c_str_ptr(m_searchDir)));
//          recls_debug2_trace_printf_("*m_directoriesBegin: %s", static_cast<char const*>(stlsoft::c_str_ptr(*m_directoriesBegin)));

            do
            {
                RECLS_COVER_MARK_LINE();

#ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
# pragma message(_sscomp_fileline_message("TODO: Merge these once we've got findfile_sequence supporting fullPath"))
#endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */

//              RECLS_ASSERT('\0' != (*m_directoriesBegin).get_path()[0]);

                m_dnode = ReclsFileSearchDirectoryNode::FindAndCreate(  m_flags
#if defined(RECLS_PLATFORM_IS_UNIX)
                // The way glob_sequence works
                                                                    ,   *m_directoriesBegin
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
                // The way basic_findfile_sequence<> works
                                                                    ,   (*m_directoriesBegin).get_path()
#endif /* RECLS_PLATFORM_IS_??? */
                                                                    ,   m_rootDirLen
                                                                    ,   stlsoft::c_str_ptr(m_pattern)
                                                                    ,   m_patternLen
                                                                    ,   m_pfn
                                                                    ,   m_param
                                                                    ,   &rc
                                                                    );

            } while (NULL == m_dnode && ++m_directoriesBegin != m_directories.end());

            if (RECLS_SUCCEEDED(rc))
            {
                rc = (NULL == m_dnode) ? RECLS_RC_NO_MORE_DATA : RECLS_RC_OK;
            }
        }
    }

    if (RECLS_SUCCEEDED(rc))
    {
        RECLS_COVER_MARK_LINE();

        RECLS_ASSERT(is_valid());
    }

    RECLS_COVER_MARK_LINE();

    return rc;
}

#ifdef RECLS_ENFORCING_CONTRACTS
recls_bool_t ReclsFileSearchDirectoryNode::is_valid() const
{
    function_scope_trace("ReclsFileSearchDirectoryNode::is_valid");

    RECLS_COVER_MARK_LINE();

    recls_rc_t rc = RECLS_RC_OK;

#if defined(RECLS_PRAGMA_MESSAGE_SUPPORT) && \
    !defined(RECLS_PRAGMA_MESSAGE_IS_INTRUSIVE)
# pragma message("Flesh these out")
    if (RECLS_SUCCEEDED(rc))
    {
        RECLS_COVER_MARK_LINE();

    }
#endif /* compiler */

    // (i) Either we are enumerating files (m_current != NULL) or directories (m_dnode != NULL), but not both
    RECLS_ASSERT(NULL == m_current || NULL == m_dnode);
    // (ii) Either we are enumerating files (m_current != NULL) or there are no more files to enumerate
    RECLS_ASSERT(NULL != m_current || m_entriesBegin == m_entries.end());

    return RECLS_SUCCEEDED(rc);
}
#endif /* RECLS_ENFORCING_CONTRACTS */

recls_rc_t ReclsFileSearchDirectoryNode::GetNext()
{
    function_scope_trace("ReclsFileSearchDirectoryNode::GetNext");

    RECLS_ASSERT(is_valid());

    RECLS_COVER_MARK_LINE();

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
    RECLS_ASSERT(NULL == m_current || NULL == m_dnode);
    // (ii) Either we are enumerating files (m_current != NULL) or there are no more files to enumerate
    RECLS_ASSERT(NULL != m_current || m_entriesBegin == m_entries.end());

    recls_rc_t rc = RECLS_RC_NO_MORE_DATA;

    if (NULL != m_current)
    {
        // Currently enumerating through the files
        RECLS_ASSERT(m_entriesBegin != m_entries.end());
        RECLS_ASSERT(NULL == m_dnode);

        RECLS_COVER_MARK_LINE();

        // Advance, and check for end of sequence
        ++m_entriesBegin;

        Entry_Release(m_current);
        if (m_entriesBegin != m_entries.end())
        {
            RECLS_COVER_MARK_LINE();

            // Still enumerating, so just update m_current
            m_current = CreateEntryInfo(m_rootDirLen, stlsoft::c_str_ptr(m_searchDir), m_searchDirLen, m_flags, m_entriesBegin);

            rc = RECLS_RC_OK;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            // No more left in the files sequence, so delete m_current
            m_current = NULL;

            rc = RECLS_RC_NO_MORE_DATA;
        }
    }

    if (NULL == m_current)
    {
        RECLS_COVER_MARK_LINE();

        // Now we are either enumerating the directories, or we've already done so
        if (NULL != m_dnode)
        {
            RECLS_COVER_MARK_LINE();

            // Currently enumerating the directories
            rc = m_dnode->GetNext();

            if (RECLS_RC_NO_MORE_DATA == rc)
            {
                RECLS_COVER_MARK_LINE();

                ++m_directoriesBegin;

                delete m_dnode;

                m_dnode = NULL;
            }
        }

        if (m_directoriesBegin == m_directories.end())
        {
            RECLS_COVER_MARK_LINE();

            // Enumeration is complete.
            rc = RECLS_RC_NO_MORE_DATA;
        }
        else
        {
            RECLS_COVER_MARK_LINE();

            if (NULL == m_dnode)
            {
                RECLS_COVER_MARK_LINE();

                do
                {
                    RECLS_COVER_MARK_LINE();

                    // Creation of the node will cause it to enter the first enumeration
                    // state. However, if there are no matching, then NULL will be returned
                    RECLS_ASSERT(m_directoriesBegin != m_directories.end());

                    m_dnode = ReclsFileSearchDirectoryNode::FindAndCreate(  m_flags
#if defined(RECLS_PLATFORM_IS_UNIX)
                                                                        ,   *m_directoriesBegin
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
                                                                        ,   (*m_directoriesBegin).get_path()
#endif /* RECLS_PLATFORM_IS_??? */
                                                                        ,   m_rootDirLen
                                                                        ,   stlsoft::c_str_ptr(m_pattern)
                                                                        ,   m_patternLen
                                                                        ,   m_pfn
                                                                        ,   m_param
                                                                        ,   &rc
                                                                        );

                    if (NULL != m_dnode)
                    {
                        RECLS_COVER_MARK_LINE();

                        rc = RECLS_RC_OK;
                    }
                    else
                    {
                        RECLS_COVER_MARK_LINE();

                        ++m_directoriesBegin;
                    }

                } while (NULL == m_dnode && m_directoriesBegin != m_directories.end());
            }
        }
    }

    RECLS_ASSERT(is_valid());

    RECLS_COVER_MARK_LINE();

    return rc;
}

recls_rc_t ReclsFileSearchDirectoryNode::GetDetails(
    recls_entry_t* pinfo
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::GetDetails");

    RECLS_ASSERT(is_valid());

    RECLS_COVER_MARK_LINE();

    recls_rc_t  rc;

    RECLS_ASSERT(NULL != pinfo);
    RECLS_ASSERT(NULL == m_current || NULL == m_dnode);

    if (NULL != m_current)
    {
        // Currently searching for files from the current directory

        RECLS_ASSERT(NULL == m_dnode);

        RECLS_COVER_MARK_LINE();

        rc = Entry_Copy(m_current, pinfo);

#if RECLS_TRACE_LEVEL >= 2
        {
            RECLS_COVER_MARK_LINE();

            file_path_buffer_type   buffer;

            Recls_GetPathProperty(m_current, &buffer[0], buffer.size());

# if defined(RECLS_CHAR_TYPE_IS_CHAR)
            recls_debug2_trace_printf_("    [%s]", static_cast<char const*>(stlsoft::c_str_ptr(buffer)));
# elif defined(RECLS_CHAR_TYPE_IS_WCHAR)
            recls_debug2_trace_printf_("    [%s]", static_cast<char const*>(winstl::w2a(buffer)));
# endif /* RECLS_CHAR_TYPE_IS_???? */
        }
#endif /* RECLS_TRACE_LEVEL >= 2 */
    }
    else if (NULL != m_dnode)
    {
        RECLS_ASSERT(NULL == m_current);

        RECLS_COVER_MARK_LINE();

        // Sub-directory searching is active, so get from there.
        rc = m_dnode->GetDetails(pinfo);
    }
    else
    {
        RECLS_COVER_MARK_LINE();

        // Enumeration has completed
        rc = RECLS_RC_NO_MORE_DATA;
    }

    RECLS_ASSERT(is_valid());

    return rc;
}

recls_rc_t ReclsFileSearchDirectoryNode::GetNextDetails(
    recls_entry_t* pinfo
)
{
    function_scope_trace("ReclsFileSearchDirectoryNode::GetNextDetails");

    RECLS_ASSERT(is_valid());
    RECLS_ASSERT(NULL != pinfo);

    RECLS_COVER_MARK_LINE();

    recls_rc_t  rc  =   GetNext();

    if (RECLS_SUCCEEDED(rc))
    {
        RECLS_COVER_MARK_LINE();

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

