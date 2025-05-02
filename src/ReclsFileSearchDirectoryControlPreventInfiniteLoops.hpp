/* /////////////////////////////////////////////////////////////////////////
 * File:    src/ReclsFileSearchDirectoryControlPreventInfiniteLoops.hpp
 *
 * Purpose: Definition of the ReclsFileSearchDirectoryControlPreventInfiniteLoops class.
 *
 * Created: 1st May 2025
 * Updated: 1st May 2025
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2025, Matthew Wilson and Synesis Information Systems
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
#include "impl.types.hpp"
#include "incl.stlsoft.h"

#if __cplusplus >= 201103L
# include <functional>
# include <unordered_map>
#else
# include <map>
#endif


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
 * forward declarations
 */

class ReclsFileSearchDirectoryNode;
class ReclsSearchDirectoryControl;


/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class ReclsFileSearchDirectoryControlPreventInfiniteLoops
/// Info structure for doing filesystem searches
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsFileSearchDirectoryControlPreventInfiniteLoops
    : public ReclsSearchDirectoryControl
{
public: // types
    typedef ReclsFileSearchDirectoryControlPreventInfiniteLoops
                                                            class_type;
    typedef recls_char_t                                    char_type;
    typedef types::traits_type::stat_data_type              stat_data_type;
private:
    struct                                                  key_type
    {
        recls_sint64_t  dev;
        recls_sint64_t  ino;
#if __cplusplus >= 201103L

        bool operator ==(key_type const& rhs) const STLSOFT_NOEXCEPT
        {
            key_type const& lhs = *this;

            if (lhs.dev != rhs.dev)
            {
                return false;
            }

            if (lhs.ino != rhs.ino)
            {
                return false;
            }

            return true;
        }
#else

        bool operator <(key_type const& rhs) const STLSOFT_NOEXCEPT
        {
            key_type const& lhs = *this;

            if (lhs.dev < rhs.dev)
            {
                return true;
            }
            if (lhs.dev > rhs.dev)
            {
                return false;
            }

            if (lhs.ino < rhs.ino)
            {
                return true;
            }

            return false;
        }
#endif
    };
#if __cplusplus >= 201103L

    struct                                                  key_hasher_type
    {
        std::size_t
        operator()(key_type const& k) const STLSOFT_NOEXCEPT
        {
            return std::hash<recls_sint64_t>()(k.ino);
        }
    };
#endif
#if __cplusplus >= 201103L

    typedef std::unordered_map<
        key_type
    ,   size_t
    ,   key_hasher_type
    >                                                       map_type_;
#else

    typedef std::map<
        key_type
    ,   size_t
    >                                                       map_type_;
#endif


public: // construction
    ReclsFileSearchDirectoryControlPreventInfiniteLoops(
        recls_uint32_t              flags
    );
    ~ReclsFileSearchDirectoryControlPreventInfiniteLoops() STLSOFT_NOEXCEPT;
private:
    ReclsFileSearchDirectoryControlPreventInfiniteLoops(class_type const &); // copy-construction proscribed
    void operator =(class_type const &);                            // copy-assignment proscribed


public:
    virtual bool CanProcessDirectory(
        char_type const*        directoryPath
    ,   stat_data_type const*   psd
    );


private: // fields
    recls_uint32_t const    m_flags;
    map_type_               m_counts;
};


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

