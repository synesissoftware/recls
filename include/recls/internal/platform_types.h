/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/internal/platform_types.h
 *
 * Purpose: Platform discrimination for recls API.
 *
 * Created: 18th August 2003
 * Updated: 23rd February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted in accordance with the license and warranty
 * information described in recls.h (included in this distribution, or
 * available from https://github.com/synesissoftware/recls).
 *
 * ////////////////////////////////////////////////////////////////////// */


#ifndef RECLS_INCL_RECLS_INTERNAL_H_PLATFORM_TYPES
#define RECLS_INCL_RECLS_INTERNAL_H_PLATFORM_TYPES

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_TYPES_MAJOR    3
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_TYPES_MINOR    7
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_TYPES_REVISION 2
# define RECLS_VER_RECLS_INTERNAL_H_PLATFORM_TYPES_EDIT     40
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \file recls/internal/platform_types.h
 *
 * \brief [C, C++] Platform-dependent types for the
 *  \ref group__recls API.
 */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RECLS_INCL_RECLS_INTERNAL_H_PLATFORM
# error recls/internal/platform_types.h must not be included directly. You should include recls/recls.h
#endif /* !RECLS_INCL_RECLS_INTERNAL_H_PLATFORM */

#if defined(RECLS_PURE_API) || \
    defined(RECLS_PLATFORM_IS_UNIX)
# include <time.h>
# include <sys/types.h>
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# include <windows.h>
#elif defined(RECLS_OVERRIDE_PLATFORM)
 /* You're expected to ensure that the appropriate inclusions are made */
#else
# error Platform not (yet) recognised
#endif /* platform */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#if defined(_UNICODE) && \
    !defined(UNICODE)
# define UNICODE
#endif /* _UNICODE && !UNICODE */

#if defined(UNICODE) && \
    !defined(_UNICODE)
# define _UNICODE
#endif /* UNICODE && !_UNICODE */

#ifdef RECLS_CHAR_TYPE_IS_CHAR
# undef RECLS_CHAR_TYPE_IS_CHAR
#endif /* RECLS_CHAR_TYPE_IS_CHAR */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# undef RECLS_CHAR_TYPE_IS_WCHAR
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

/** The recls library ambient character type */
#if defined(UNICODE) && \
    !defined(RECLS_NO_UNICODE)
typedef recls_char_w_t              recls_char_t;
# define RECLS_CHAR_TYPE_IS_WCHAR
# define RECLS_LITERAL(x)           L ## x
#else /* ? UNICODE && !RECLS_NO_UNICODE */
typedef recls_char_a_t              recls_char_t;
# define RECLS_CHAR_TYPE_IS_CHAR
# define RECLS_LITERAL(x)           x
#endif /* UNICODE && !RECLS_NO_UNICODE */


/** An asymmetric range representing a sequence of characters (ie a string) */
struct recls_strptrs_t
{
    /** Points to the start of the sequence. */
    recls_char_t const* begin;
    /** Points to one-past-the-end of the sequence. */
    recls_char_t const* end;
};

/** An asymmetric range representing a sequence of recls_strptrs_t (ie a collection of strings) */
struct recls_strptrsptrs_t
{
    /** Points to the start of the sequence. */
    struct recls_strptrs_t const*   begin;
    /** Points to one-past-the-end of the sequence. */
    struct recls_strptrs_t const*   end;
};

/** A file-system entry info structure
 *
 * \note Several parts of this structure are platform-dependent.
 */
#if !defined(RECLS_PURE_API)
struct recls_entryinfo_t
{
/** \name attributes */
/** @{ */
    /** The entry's attributes */
    recls_uint32_t              attributes;
/** @} */
/** \name Path components  */
/** @{ */
    /** The full path of the entry.
     *
     * \note This is always nul-terminated.
     */
    struct recls_strptrs_t      path;
# if defined(RECLS_PLATFORM_IS_WINDOWS)
    /** The short (8.3) path of the entry
     *
     * \note This is always nul-terminated.
     * \note This member is only defined for the Windows platform.
     */
    struct recls_strptrs_t      shortFile;
    /** The letter of the drive */
    recls_char_t                drive;
# endif /* RECLS_PLATFORM_IS_WINDOWS */
    /** The directory component.
     *
     * \note This is <b>never</b> nul-terminated.
     */
    struct recls_strptrs_t      directory;
    /** The file name component (excluding extension).
     *
     * \note This is <b>never</b> nul-terminated.
     */
    struct recls_strptrs_t      fileName;
    /** The file extension component (excluding '.').
     *
     * \note You should <b>never</b> assume that this entry is nul-terminated.
     */
    struct recls_strptrs_t      fileExt;
    /** Pointers that delimit an array of string-pointer representing the
     * entry's directory parts, or an empty array if RECLS_F_DIRECTORY_PARTS
     * is not specified.
     *
     * \note The parts are <b>never</b> nul-terminated.
     */
    struct recls_strptrsptrs_t  directoryParts;
/** @} */
/** \name File times  */
/** @{ */
# if defined(RECLS_PLATFORM_IS_WINDOWS)
    /** The time the entry was created
     *
     * \note This member is only defined for the Windows platform.
     */
    recls_time_t                creationTime;
# endif /* RECLS_PLATFORM_IS_WINDOWS */
    /** The time the entry was last modified */
    recls_time_t                modificationTime;
    /** The time the entry was last accessed */
    recls_time_t                lastAccessTime;
# if defined(RECLS_PLATFORM_IS_UNIX)
    /** The time the entry status was last changed
     *
     * \note This member is only defined for the UNIX platform.
     */
    recls_time_t                lastStatusChangeTime;
# endif /* RECLS_PLATFORM_IS_UNIX */
/** @} */
/** \name Size  */
/** @{ */
    /** The size of the entry */
    recls_filesize_t            size;
/** @} */
/** \name Path components (2) */
/** @{ */
    /** The search directory specified in the search.
     *
     * \note This is <b>never</b> nul-terminated.
     */
    struct recls_strptrs_t      searchDirectory;
    /** The opaque data of the entry; it is not accessible to any
     * client code, and <b>must not be manipulated</b> in any way
     */
    struct recls_strptrs_t      searchRelativePath;
    /** The number of directory parts in the relative part of
     * the entry's path, or 0 if RECLS_F_DIRECTORY_PARTS is not specified
     * in the search.
     */
    size_t                      numRelativeDirectoryParts;
    /** The number of (hard) links on the file entry, or 0 if
     * RECLS_F_LINK_COUNT is not specified in the search, or 0 if the
     * link count could not be obtained (e.g. if the file cannot be
     * accessed).
     */
    size_t                      numLinks;
    /** The index of the file entry node
     */
    recls_uint64_t              nodeIndex;
    /** Identifier of the device on which the file resides
     *
     * \note On Windows this is the volume serial number.
     */
    size_t                      deviceId;

/** @} */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
/* data */
    /** Reserved for future use. */
    recls_uint64_t              checkSum;
    /** Reserved for future use. */
    recls_uint32_t              extendedFlags[2];
    /** The full path of the entry, relative to the directory
     * from which it was searched.
     *
     * \note This is always nul-terminated.
     */
    recls_byte_t                data[1];
    /*
     *
     * - full path
     * - directory parts
     *
     */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */
};
#endif /* !RECLS_PURE_API */


/* /////////////////////////////////////////////////////////////////////////
 * string access shims
 */

#ifdef __cplusplus

/* recls_entryinfo_t const& */

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline wchar_t const* c_str_data_w(recls_entryinfo_t const& entry)
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline char const* c_str_data_a(recls_entryinfo_t const& entry)
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
{
    return entry.path.begin;
}

inline recls_char_t const* c_str_data(recls_entryinfo_t const& entry)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_data_w(entry);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_data_a(entry);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline size_t c_str_len_w(recls_entryinfo_t const& entry)
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline size_t c_str_len_a(recls_entryinfo_t const& entry)
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
{
    return static_cast<size_t>(entry.path.end - entry.path.begin);
}

inline size_t c_str_len(recls_entryinfo_t const& entry)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_len_w(entry);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_len_a(entry);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

/* recls_entryinfo_t const* */

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline wchar_t const* c_str_data_w(recls_entryinfo_t const* entry)
{
    return (NULL == entry) ? L"" : entry->path.begin;
}
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline char const* c_str_data_a(recls_entryinfo_t const* entry)
{
    return (NULL == entry) ? "" : entry->path.begin;
}
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */

inline recls_char_t const* c_str_data(recls_entryinfo_t const* entry)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_data_w(entry);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_data_a(entry);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline size_t c_str_len_w(recls_entryinfo_t const* entry)
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline size_t c_str_len_a(recls_entryinfo_t const* entry)
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
{
    return (NULL == entry) ? 0u : static_cast<size_t>(entry->path.end - entry->path.begin);
}

inline size_t c_str_len(recls_entryinfo_t const* entry)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_len_w(entry);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_len_a(entry);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}



/* recls_strptrs_t const& */

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline wchar_t const* c_str_data_w(recls_strptrs_t const& ptrs)
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline char const* c_str_data_a(recls_strptrs_t const& ptrs)
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
{
    return ptrs.begin;
}

inline recls_char_t const* c_str_data(recls_strptrs_t const& ptrs)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_data_w(ptrs);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_data_a(ptrs);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
inline size_t c_str_len_w(recls_strptrs_t const& ptrs)
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
inline size_t c_str_len_a(recls_strptrs_t const& ptrs)
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
{
    return static_cast<size_t>(ptrs.end - ptrs.begin);
}

inline size_t c_str_len(recls_strptrs_t const& ptrs)
{
# if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    return c_str_len_w(ptrs);
# else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    return c_str_len_a(ptrs);
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */

#  ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#  endif /* !_STLSOFT_NO_NAMESPACE */

#  if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    using ::recls::c_str_data_w;
    using ::recls::c_str_len_w;
#  else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    using ::recls::c_str_data_a;
    using ::recls::c_str_len_a;
#  endif /* RECLS_CHAR_TYPE_IS_WCHAR */
    using ::recls::c_str_data;
    using ::recls::c_str_len;

#  ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#  endif /* !_STLSOFT_NO_NAMESPACE */

#else /* ? !RECLS_NO_NAMESPACE */

# ifdef __cplusplus

#  ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{

#  if defined(RECLS_CHAR_TYPE_IS_WCHAR)
    using ::c_str_data_w;
    using ::c_str_len_w;
#  else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
    using ::c_str_data_a;
    using ::c_str_len_a;
#  endif /* RECLS_CHAR_TYPE_IS_WCHAR */
    using ::c_str_data;
    using ::c_str_len;

} /* namespace stlsoft */
#  endif /* !_STLSOFT_NO_NAMESPACE */

# endif /* __cplusplus */
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion
 */

#ifdef RECLS_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* RECLS_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_RECLS_INTERNAL_H_PLATFORM_TYPES */

/* ///////////////////////////// end of file //////////////////////////// */

