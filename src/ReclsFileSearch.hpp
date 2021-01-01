/* /////////////////////////////////////////////////////////////////////////
 * File:        ReclsFileSearch.hpp
 *
 * Purpose:     Definition of the ReclsFileSearch class.
 *
 * Created:     31st May 2004
 * Updated:     1st January 2021
 *
 * Home:        http://recls.org/
 *
 * Copyright (c) 2019-2021, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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
 * - Neither the name(s) of Matthew Wilson and Synesis Information Systems
 *   nor the names of any contributors may be used to endorse or promote
 *   products derived from this software without specific prior written
 *   permission.
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


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#include <recls/recls.h>
#include "ReclsSearch.hpp"

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

/* /////////////////////////////////////////////////////////////////////////
 * classes
 */

// class ReclsFileSearch
/// Info structure for doing filesystem searches
///
/// \note It has an ugly name-prefix if need to compile with compiler that does not support namespaces
class ReclsFileSearch
    : public ReclsSearch
{
public:
    typedef ReclsFileSearch class_type;

// Allocation
private:
    void *operator new(size_t cb, size_t cDirParts, size_t cbRootDir);
#ifdef RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE
    void operator delete(void* pv, size_t cDirParts, size_t cbRootDir);
#endif /* RECLS_COMPILER_REQUIRES_MATCHING_PLACEMENT_DELETE */
public:
    void operator delete(void* pv);

// Construction
protected:
    ReclsFileSearch(
        size_t                      cDirParts
    ,   recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   recls_uint32_t              flags
    ,   recls_rc_t*                 prc
    );
    ~ReclsFileSearch() STLSOFT_NOEXCEPT;
public:
    //
    //
    // \pre nullptr != searchDir
    // \pre len(searchDir) == searchDir
    // \pre types::traits_type::is_path_absolute(searchDir, searchDirLen)
    //
    // \pre nullptr != pattern
    // \pre len(patternDir) == pattern
    static
    recls_rc_t
    FindAndCreate(
        recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );

    static
    recls_rc_t
    Stat(
        recls_char_t const* path
    ,   recls_uint32_t      flags
    ,   recls_entry_t*      phEntry
    );
private:
    ReclsFileSearch(class_type const &);    // copy-construction proscribed
    void operator =(class_type const &);    // copy-assignment proscribed

private: // implementation
    recls_char_t const*
    calc_rootDir_(
        size_t              cDirParts
    ,   recls_char_t const* searchDir
    ,   size_t              searchDirLen
    );

    static
    recls_rc_t
    FindAndCreate_(
        recls_char_t const*         searchDir
    ,   size_t                      searchDirLen
    ,   recls_char_t const*         pattern
    ,   size_t                      patternLen
    ,   recls_uint32_t              flags
    ,   hrecls_progress_fn_t        pfn
    ,   recls_process_fn_param_t    param
    ,   class_type**                ppsi
    );

private: // fields
    recls_uint32_t                  m_flags;
    recls_char_t const* const       m_searchDir;
    size_t const                    m_searchDirLen;
    hrecls_progress_fn_t const      m_pfn;
    recls_process_fn_param_t const  m_param;

    /** The opaque data of the search */
    recls_byte_t                    data[1];
    /*
     * The data comprises:
     *
     *  - root dir
     *
     */
};

/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace impl */
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

/* ///////////////////////////// end of file //////////////////////////// */

