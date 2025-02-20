/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/cpp/entry.hpp
 *
 * Purpose: recls C++ mapping - entry class.
 *
 * Created: 18th August 2003
 * Updated: 20th February 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2025, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file recls/cpp/entry.hpp
 *
 * \brief [C++] recls::entry class
 *   for the \ref group__recls__cpp "recls C++ mapping".
 */

#ifndef RECLS_INCL_RECLS_CPP_HPP_ENTRY
#define RECLS_INCL_RECLS_CPP_HPP_ENTRY

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_CPP_HPP_ENTRY_MAJOR    4
# define RECLS_VER_RECLS_CPP_HPP_ENTRY_MINOR    12
# define RECLS_VER_RECLS_CPP_HPP_ENTRY_REVISION 1
# define RECLS_VER_RECLS_CPP_HPP_ENTRY_EDIT     118
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/cpp/common.hpp>
#include <recls/cpp/directory_parts.hpp>
#include <recls/cpp/exceptions.hpp>
#include <recls/cpp/traits.hpp>

#include <stlsoft/memory/auto_buffer.hpp>
#include <stlsoft/shims/access/string.hpp>
#include <platformstl/filesystem/filesystem_traits.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
namespace cpp
{
#endif /* !RECLS_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

/** Class used to represent file system entries, which provides access to
 * fields representing path, directory, file (name and/or extension), size,
 * timestamps, attributes, and more.
 *
 * Instances may be obtained as the value types of search sequences (such as
 * \link recls::cpp::search_sequence recls::search_sequence\endlink, as
 * \link recls::cpp::ftp_search_sequence recls::ftp_search_sequence\endlink),
 * and also from the recls::stat() function.
 *
 * \ingroup group__recls__cpp
 *
\htmlonly
<pre>
  recls::entry      home = recls::stat(RECLS_LITERAL("~"));
</pre>
\endhtmlonly
 */
class entry
{
public: // Member Types
    /// This type
    typedef entry                       class_type;
    /// The character type
    typedef char_t                      char_type;
    /// The traits type
    typedef reclstl_traits<char_type>   traits_type;
    /// The size type
    typedef size_t                      size_type;
    /// The string type
    typedef string_t                    string_type;
    /// The directory parts type
    typedef directory_parts             directory_parts_type;
private:
    typedef platformstl::filesystem_traits<
        char_type
    >                                   traits_type_;
public:

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
    struct stat_impl;
public:
    friend struct stat_impl;
    struct stat_impl
    {
    public:
        template <typename S>
        static
        entry
        create(
            S const&    path
        ,   int         flags
        )
        {
            STLSOFT_NS_USING(c_str_ptr);

            return create_(c_str_ptr(path), flags);
        }
    private:
        static
        entry
        create_(
            recls_char_t const* path
        ,   int                 flags
        )
        {
            recls_entry_t   e;
            recls_rc_t      rc = Recls_Stat(path, flags, &e);

            if (RECLS_FAILED(rc))
            {
                if (RECLS_RC_NO_MORE_DATA == rc)
                {
                    throw NO_MORE_DATA_exception(rc, "path does not exist", path, NULL, flags);
                }

                throw recls_exception(rc, "failed to stat path", path, NULL, flags);
            }

            return entry(&e);
        }
    };
/* private: */
    explicit
    entry(recls_entry_t* e) STLSOFT_NOEXCEPT
        : m_entry(*e)
    {}
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

public: // Construction
    entry(class_type const& rhs) STLSOFT_NOEXCEPT
        : m_entry(copy_entry_(rhs.m_entry))
    {}
    ~entry() STLSOFT_NOEXCEPT
    {
        delete_entry_(m_entry);
    }
    class_type& operator =(class_type const& rhs) STLSOFT_NOEXCEPT
    {
        recls_entry_t e = copy_entry_(rhs.m_entry);

        delete_entry_(m_entry);

        m_entry = e;

        return *this;
    }


public: // Ordering
    int
    compare(class_type const& rhs) const STLSOFT_NOEXCEPT
    {
        return traits_type_::path_str_compare(c_str(), rhs.c_str());
    }


public: // Attribute Methods
    /// Returns the full path of the entry
    char_type const* c_str() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->path.begin;
    }
    /// Returns the length of the full path of the entry
    size_type length() const STLSOFT_NOEXCEPT
    {
        return size_();
    }
#ifdef RECLS_OBSOLETE
    /// [DEPRECATED] Returns the length of the full path of the entry
    ///
    /// \deprecated This method is deprecated, and will be removed in a
    ///   future release of the library.
    size_type size() const STLSOFT_NOEXCEPT
    {
        return size_();
    }
#endif /* RECLS_OBSOLETE */
private:
    size_type size_() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->path.end - m_entry->path.begin;
    }
public:

    /// The (operating system-specific) attributes of the entry
    recls_uint32_t get_attributes() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->attributes;
    }

    /// The (operating system-specific) creation time of the entry
    recls_time_t get_creation_time() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return Recls_GetCreationTime(m_entry);
    }
    /// The (operating system-specific) last access time of the entry
    recls_time_t get_last_access_time() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return Recls_GetLastAccessTime(m_entry);
    }
    /// The (operating system-specific) last status change time of the entry
    recls_time_t get_last_status_change_time() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return Recls_GetLastStatusChangeTime(m_entry);
    }
    /// The (operating system-specific) modification time of the entry
    recls_time_t get_modification_time() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return Recls_GetModificationTime(m_entry);
    }

    /// The directory of the item
    string_type get_directory() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->directory.begin, m_entry->directory.end);
    }

    /// The directory parts of the item
    directory_parts get_directory_parts() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return directory_parts(m_entry);
    }

    /// The directory path of the item
    string_type get_directory_path() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->path.begin, m_entry->directory.end);
    }

    /// The drive of the item
    string_type get_drive() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->path.begin, m_entry->directory.begin);
    }

    /// The file of the item
    string_type get_file() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->fileName.begin, m_entry->fileExt.end);
    }
    /// [DEPRECATED] The file name of the item
    ///
    /// \deprecated This member is deprecated in favour
    ///   of get_file_basename(), and will be replaced in a future
    ///   version.
    string_type get_file_name() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->fileName.begin, m_entry->fileName.end);
    }

    /// The file basename of the item
    string_type get_file_basename() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->fileName.begin, m_entry->fileName.end);
    }

    /// The file extension of the item, including the period ('.')
    ///
    /// If the extension is non-empty, the returned string will include the
    /// period. If not, the string will be empty
    ///
    /// \note This is unlike the raw API (via Recls_GetFileExtProperty())
    /// and also unlike mappings from versions prior to 1.9
    string_type get_file_extension() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        if (m_entry->fileExt.begin == m_entry->fileExt.end)
        {
            return string_type();
        }
        else
        {
            return string_type(m_entry->fileExt.begin - 1u, m_entry->fileExt.end);
        }
    }

    /// Indicates whether the represented file-system entity existed (at
    /// the time that the instance was elicited)
    bool exists() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_EntryExists(m_entry);
    }

    /// Indicates if the entry is a directory.
    bool is_directory() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_IsEntryDirectory(m_entry);
    }
    /// Indicates if the entry is a link.
    bool is_link() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_IsEntryLink(m_entry);
    }
    /// Indicates if the entry is read-only.
    bool is_readonly() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_IsEntryReadOnly(m_entry);
    }
    /// Indicates if the entry is a socket.
    bool is_socket() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_IsEntrySocket(m_entry);
    }
    /// Indicates if the entry is on a UNC drive.
    bool is_unc() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return 0 != Recls_IsEntryUNC(m_entry);
    }

    /// The full path of the entry
    string_type get_path() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->path.begin, m_entry->path.end);
    }
#ifdef RECLS_PLATFORM_IS_WINDOWS
    string_type get_short_path() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        DWORD const dw = ::GetShortPathName(m_entry->path.begin, NULL, 0);

        if (0 == dw)
        {
            throw recls_exception(RECLS_RC_SHORT_NAME_NOT_AVAILABLE);
        }
        else
        {
            stlsoft::auto_buffer<char_type> buffer(dw);

            DWORD const dw2 = ::GetShortPathName(m_entry->path.begin, &buffer[0], static_cast<DWORD>(buffer.size()));

            return string_type(buffer.data(), dw2);
        }
    }
#endif

    /// The search directory of the item
    string_type get_search_directory() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->searchDirectory.begin, m_entry->searchDirectory.end);
    }
    /// The search relative path of the item
    string_type get_search_relative_path() const
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return string_type(m_entry->searchRelativePath.begin, m_entry->searchRelativePath.end);
    }

    /// The number of directory parts in the relative part of the entry's
    /// path, or 0 if RECLS_F_DIRECTORY_PARTS is not specified in the
    /// search.
    size_type num_relative_directory_parts() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->numRelativeDirectoryParts;
    }

    size_type num_links() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->numLinks;
    }

    recls_uint64_t node_index() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->nodeIndex;
    }

    size_type device_id() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return m_entry->deviceId;
    }



    /// The size of the item
    ///
    /// \note If the item is a directory, this will always be zero. Instead,
    ///   use recls::cpp::calculate_directory_size().
    recls_uint64_t get_size() const STLSOFT_NOEXCEPT
    {
        return get_file_size();
    }
    /// The size of the item, if it's a file
    ///
    /// \note If the item is a directory, this will always be zero. Instead,
    ///   use recls::cpp::calculate_directory_size().
    recls_uint64_t get_file_size() const STLSOFT_NOEXCEPT
    {
        STLSOFT_ASSERT(NULL != m_entry);

        return Recls_GetSizeProperty(m_entry);
    }


    /// Access to the underlying recls API handle
    ///
    /// \warn The caller must NOT invoke Recls_CloseDetails() on the
    ///   returned value
    recls_entry_t
    get() const STLSOFT_NOEXCEPT
    {
        return m_entry;
    }

public: // Attribute Properties
#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, Path);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, SearchDirectory);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, SearchRelativePath);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, NumRelativeDirectoryParts);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, NumLinks);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, NodeIndex);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, DeviceId);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, Drive);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, Directory);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, DirectoryPath);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, DirectoryParts);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, File);
    /* RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, ShortFile); */
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, FileName);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, FileExtension);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, CreationTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, ModificationTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, LastAccessTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, LastStatusChangeTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, Size);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, FileSize);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, Attributes);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, IsDirectory);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, IsReadOnly);
    RECLS_CPP_OPT_METHOD_PROPERTY_DEFINE_OFFSET(class_type, IsUnc);
    union
    {
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_path, Path);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_search_directory, SearchDirectory);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_search_relative_path, SearchRelativePath);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(size_type,       class_type, num_relative_directory_parts, NumRelativeDirectoryParts);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(size_type,       class_type, num_links, NumLinks);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_uint64_t,  class_type, node_index, NodeIndex);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(size_type,       class_type, device_id, DeviceId);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_drive, Drive);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_directory, Directory);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_directory_path, DirectoryPath);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(directory_parts, class_type, get_directory_parts, DirectoryParts);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_file, File);
    /* RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,  class_type, get_shortFile, ShortFile); */
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_file_name, FileName);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(string_type,     class_type, get_file_extension, FileExtension);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_time_t,    class_type, get_creation_time, CreationTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_time_t,    class_type, get_modification_time, ModificationTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_time_t,    class_type, get_last_access_time, LastAccessTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_time_t,    class_type, get_last_status_change_time, LastStatusChangeTime);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_uint64_t,  class_type, get_size, Size);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_uint64_t,  class_type, get_file_size, FileSize);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(recls_uint32_t,  class_type, get_attributes, Attributes);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(bool,            class_type, is_directory, IsDirectory);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(bool,            class_type, is_readonly, IsReadOnly);
    RECLS_CPP_OPT_METHOD_PROPERTY_GET_PROP(bool,            class_type, is_unc, IsUnc);
    };
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

private: // Implementation
    static recls_entry_t copy_entry_(recls_entry_t e) STLSOFT_NOEXCEPT
    {
        recls_entry_t copy;

        Recls_CopyDetails(e, &copy);

        return copy;
    }
    static void delete_entry_(recls_entry_t e) STLSOFT_NOEXCEPT
    {
        Recls_CloseDetails(e);
    }

private: // Member Variables
    recls_entry_t m_entry;
};

/// Retrieves an entry corresponding to the given path.
///
/// \param path A string containing the path whose information is to be
///   elicited.
/// \param flags A combination of flags from the \c RECLS_FLAG enumeration.
///
/// \return An instance representing the "stat'd" path
///
/// \exception recls::NO_MORE_DATA_exception Thrown if no entry is found
/// \exception recls::recls_exception if the information cannot otherwise be
///   retrieved.
template <typename S>
inline
entry
stat(
    S const&    path
,   int         flags = 0
)
{
    return entry::stat_impl::create(path, flags);
}

/* /////////////////////////////////////////////////////////////////////////
 * comparison
 */

inline
bool
operator <(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) < 0;
}

inline
bool
operator <=(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) <= 0;
}

inline
bool
operator >(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) > 0;
}

inline
bool
operator >=(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) >= 0;
}

inline
bool
operator ==(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) == 0;
}

inline
bool
operator !=(
    entry const& lhs
,   entry const& rhs
) STLSOFT_NOEXCEPT
{
    return lhs.compare(rhs) != 0;
}

/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#ifndef RECLS_PURE_API

/// String access shim
///
/// \ingroup group__recls__cpp
///
/// This returns a non-null null-terminated C-string of the given entry's full path.
/// \param fe The entry instance whose path is to be returned
///
/// \note This fits the <a href = "http://stlsoft.org/help/main.html">STLSoft</a> shims
/// concept, described in <a href = "http://synesis.com.au/resources/articles/cpp/shims.pdf">this</a>
/// Synesis Software White Paper, and featured in the article "<a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">Generalised String Manipulation: Access Shims and Type-tunnelling</a>",
/// in the August 2003 issue of <a href = "http://www.cuj.com">C/C++ User's Journal</a>.
inline
entry::char_type const*
c_str_ptr(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return fe.c_str();
}

inline
entry::char_type const*
c_str_ptr_null(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return (0u != fe.length()) ? fe.c_str() : NULL;
}

inline
entry::char_type const*
c_str_data(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return fe.c_str();
}

inline
size_t
c_str_len(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return fe.length();
}

# ifdef RECLS_CHAR_TYPE_IS_CHAR

inline
recls_char_t const*
c_str_ptr_a(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_ptr(fe);
}

inline
recls_char_t const*
c_str_ptr_null_a(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_ptr_null(fe);
}

inline
recls_char_t const*
c_str_data_a(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_data(fe);
}

inline
size_t
c_str_len_a(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_len(fe);
}
# endif /* RECLS_CHAR_TYPE_IS_CHAR */

# ifdef RECLS_CHAR_TYPE_IS_WCHAR

inline
recls_char_t const*
c_str_ptr_w(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_ptr(fe);
}

inline
recls_char_t const*
c_str_ptr_null_w(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_ptr_null(fe);
}

inline
recls_char_t const*
c_str_data_w(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_data(fe);
}

inline
size_t
c_str_len_w(
    entry const&    fe
) STLSOFT_NOEXCEPT
{
    return c_str_len(fe);
}
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */
#endif /* !RECLS_PURE_API */

////////////////////////////////////////////////////////////////////////////
// IOStream compatibility

template <typename S>
inline
S&
operator <<(
    S&                          s
,   ::recls::cpp::entry const&  v
)
{
    s << v.c_str();

    return s;
}

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)

} /* namespace cpp */
} /* namespace recls */

# if (  defined(STLSOFT_COMPILER_IS_MSVC) || \
        defined(STLSOFT_COMPILER_IS_UNKNOWN)) && \
     defined(_MSC_VER) && \
     _MSC_VER < 1310

template <typename C>
inline
std::basic_ostream<C>&
operator <<(
    std::basic_ostream<C>&      s
,   ::recls::cpp::entry const&  v
)
{
    s << v.c_str();

    return s;
}
# endif /* compiler */


#ifdef RECLS_DOCUMENTATION_SKIP_SECTION

/** The recls project inserts c_str_ptr, c_str_data and c_str_len
 * <a href = "http://www.cuj.com/documents/s=8681/cuj0308wilson/">string access shims</a>
 * into the STLSoft namespace, for generalised manipulation of its
 * \link recls::cpp::entry entry\endlink type.
 */
#endif /* RECLS_DOCUMENTATION_SKIP_SECTION */
namespace stlsoft
{
//    using ::recls::cpp::c_str_ptr_null_a;
//    using ::recls::cpp::c_str_ptr_null;

# ifdef RECLS_CHAR_TYPE_IS_CHAR

    using ::recls::cpp::c_str_data_a;
    using ::recls::cpp::c_str_len_a;
    using ::recls::cpp::c_str_ptr_a;
    using ::recls::cpp::c_str_ptr_null_a;
# endif /* RECLS_CHAR_TYPE_IS_CHAR */
# ifdef RECLS_CHAR_TYPE_IS_WCHAR

    using ::recls::cpp::c_str_data_w;
    using ::recls::cpp::c_str_len_w;
    using ::recls::cpp::c_str_ptr_w;
    using ::recls::cpp::c_str_ptr_null_w;
# endif /* RECLS_CHAR_TYPE_IS_WCHAR */

    using ::recls::cpp::c_str_ptr;
    using ::recls::cpp::c_str_ptr_null;
    using ::recls::cpp::c_str_data;
    using ::recls::cpp::c_str_len;
}
#endif /* !RECLS_NO_NAMESPACE */
#endif /* !RECLS_INCL_RECLS_CPP_HPP_ENTRY */

/* ///////////////////////////// end of file //////////////////////////// */

