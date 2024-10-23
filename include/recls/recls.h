/* /////////////////////////////////////////////////////////////////////////
 * File:    recls/recls.h
 *
 * Purpose: Main header file for recls API.
 *
 * Created: 15th August 2003
 * Updated: 23rd October 2024
 *
 * Home:    https://github.com/synesissoftware/recls
 *
 * Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
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


/** \file recls/recls.h
 *
 * \brief [C, C++] The root header for the \ref group__recls API
 */

#ifndef RECLS_INCL_RECLS_H_RECLS
#define RECLS_INCL_RECLS_H_RECLS

/* File version */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_H_RECLS_MAJOR      3
# define RECLS_VER_RECLS_H_RECLS_MINOR      21
# define RECLS_VER_RECLS_H_RECLS_REVISION   17
# define RECLS_VER_RECLS_H_RECLS_EDIT       138
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** \name recls API Version
 * \ingroup group__recls
 */
/** @{ */
/** \def RECLS_VER_MAJOR
 * The major version number of RECLS.
 */

/** \def RECLS_VER_MINOR
 * The minor version number of RECLS.
 */

/** \def RECLS_VER_REVISION
 * The revision version number of RECLS.
 */

/** \def RECLS_VER
 * The current composite version number of RECLS.
 */
/** @} */

/* recls version */
#define RECLS_VER_1_0_1                                     0x01000100
#define RECLS_VER_1_1_1                                     0x01010100
#define RECLS_VER_1_2_1                                     0x01020100
#define RECLS_VER_1_3_1                                     0x01030100
#define RECLS_VER_1_4_1                                     0x01040100
#define RECLS_VER_1_4_2                                     0x01040200
#define RECLS_VER_1_5_1                                     0x01050100
#define RECLS_VER_1_5_2                                     0x01050200
#define RECLS_VER_1_5_3                                     0x01050300
#define RECLS_VER_1_6_1                                     0x01060100
#define RECLS_VER_1_6_2                                     0x01060200
#define RECLS_VER_1_6_3                                     0x01060300
#define RECLS_VER_1_6_4                                     0x01060400
#define RECLS_VER_1_6_5                                     0x01060500
#define RECLS_VER_1_7_1                                     0x01070100
#define RECLS_VER_1_7_2                                     0x01070200
#define RECLS_VER_1_8_1                                     0x01080100
#define RECLS_VER_1_8_2                                     0x01080200
#define RECLS_VER_1_8_3                                     0x01080300
#define RECLS_VER_1_8_4                                     0x01080400
#define RECLS_VER_1_8_5                                     0x01080500
#define RECLS_VER_1_8_6                                     0x01080600
#define RECLS_VER_1_8_7                                     0x01080700
#define RECLS_VER_1_8_8                                     0x01080800
#define RECLS_VER_1_8_9                                     0x01080900
#define RECLS_VER_1_8_10                                    0x01080a00
#define RECLS_VER_1_8_11                                    0x01080b00
#define RECLS_VER_1_8_12                                    0x01080cff
#define RECLS_VER_1_8_13                                    0x01080dff
#define RECLS_VER_1_9_1_ALPHA_1                             0x01090101
#define RECLS_VER_1_9_1_ALPHA_2                             0x01090102
#define RECLS_VER_1_9_1_ALPHA_3                             0x01090103
#define RECLS_VER_1_9_1_ALPHA_4                             0x01090104
#define RECLS_VER_1_9_1_ALPHA_5                             0x01090105
#define RECLS_VER_1_9_1_ALPHA_6                             0x01090106
#define RECLS_VER_1_9_1_ALPHA_7                             0x01090107
#define RECLS_VER_1_9_1_ALPHA_8                             0x01090108
#define RECLS_VER_1_9_1_ALPHA_9                             0x01090109
#define RECLS_VER_1_9_1_ALPHA_10                            0x0109010a
#define RECLS_VER_1_9_1                                     0x010901ff
#define RECLS_VER_1_9_2                                     0x010902ff
#define RECLS_VER_1_9_3                                     0x010903ff
#define RECLS_VER_1_9_4                                     0x010904ff
#define RECLS_VER_1_9_5                                     0x010905ff
#define RECLS_VER_1_9_6                                     0x010906ff
#define RECLS_VER_1_9_7                                     0x010907ff
#define RECLS_VER_1_9_8                                     0x010908ff
#define RECLS_VER_1_10_0_ALPHA_1                            0x010a0001
#define RECLS_VER_1_10_0_ALPHA_2                            0x010a0002
#define RECLS_VER_1_10_0_ALPHA_3                            0x010a0003
#define RECLS_VER_1_10_0_ALPHA_4                            0x010a0004
#define RECLS_VER_1_10_0_ALPHA_5                            0x010a0005
#define RECLS_VER_1_10_0_ALPHA_6                            0x010a0006
#define RECLS_VER_1_10_0_ALPHA_7                            0x010a0007
#define RECLS_VER_1_10_0_ALPHA_8                            0x010a0008
#define RECLS_VER_1_10_0_ALPHA_9                            0x010a0009

#define RECLS_VER_MAJOR         1
#define RECLS_VER_MINOR         10
#define RECLS_VER_REVISION      0
#define RECLS_VER               RECLS_VER_1_10_0_ALPHA_9


/* /////////////////////////////////////////////////////////////////////////
 * strictness
 */

#ifndef RECLS_NO_STRICT
# define RECLS_STRICT
#endif /* !RECLS_NO_STRICT */


/* /////////////////////////////////////////////////////////////////////////
 * Includes - 1
 */

/* Detects C & C++ things, such as namespace support */
#include <recls/internal/language.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#if !defined(RECLS_NO_NAMESPACE)
# define RECLS_QUAL(x)                                      ::recls::x
#else
# define RECLS_QUAL(x)                                      x
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * Includes - 2
 */

/* Includes platform-specific headers */
#include <recls/internal/platform.h>
/* Includes stddef.h / cstddef, and defines the recls types: recls_s/uint8/16/32/64_t */
#include <recls/internal/compiler.h>
/* Defines recls_time_t */
#include <recls/internal/recls_time.h>
/* Defines recls_filesize_t */
#include <recls/internal/recls_filesize.h>
/* Defines recls_strptrs_t, recls_strptrsptrs_t, recls_entryinfo_t */
#include <recls/internal/platform_types.h>

#include <stdarg.h> /* for logging function pointer */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
/** The recls namespace, within which the core API symbols are defined (in
 * C++ compilation units only), and into which the C++ mappings symbols are
 * introduced (from <code>recls::cpp</code>) by the inclusion of
 * recls/recls.hpp
 */
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#if defined(STLSOFT_NUM_ELEMENTS)
# define RECLS_NUM_ELEMENTS(x)                              STLSOFT_NUM_ELEMENTS(x)
#else /* ? STLSOFT_NUM_ELEMENTS */
# define RECLS_NUM_ELEMENTS(x)                              (sizeof(x) / sizeof((x)[0]))
#endif /* STLSOFT_NUM_ELEMENTS */


/* /////////////////////////////////////////////////////////////////////////
 * constants and definitions
 */

/** \def RECLS_ROOT_NAME_LEN
 *
 * Defines the number of characters in a system root.
 *
 * \ingroup group__recls
 */
#if defined(RECLS_DOCUMENTATION_SKIP_SECTION)
# define RECLS_ROOT_NAME_LEN                                (1) or (3)
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
# define RECLS_ROOT_NAME_LEN                                (3)
#elif defined(RECLS_PLATFORM_IS_UNIX)
# define RECLS_ROOT_NAME_LEN                                (1)
#elif defined(RECLS_OVERRIDE_PLATFORM)
  /* Assume that the appropriate inclusions are made */
#else
# error Platform not recognised
#endif /* platform */


/* /////////////////////////////////////////////////////////////////////////
 * function specifications
 */

/** Defines the recls linkage and calling convention.
 *
 * \ingroup group__recls
 */
#define RECLS_FNDECL(rt)                                    RECLS_LINKAGE_C rt RECLS_CALLCONV_DEFAULT

/** Defines the recls linkage, calling convention with the standard return
 * type of \c recls_rc_t.
 *
 * \ingroup group__recls
 */
#define RECLS_API                                           RECLS_FNDECL(recls_rc_t)


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/* recls_rc_t */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
struct recls_rc_t_
{ char recls_rc_t_dummy; };
# define RECLS_RC_VALUE(x)                                  ((RECLS_QUAL(recls_rc_t))(void*)(RECLS_QUAL(recls_uintptr_t))(x))
# define RECLS_RC_OK_                                       RECLS_RC_VALUE(0)
# define RECLS_RC_FAIL_                                     RECLS_RC_VALUE(-1)
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** The type of return codes issued by the API functions.
 *
 * \ingroup group__recls
 */
typedef struct recls_rc_t_ const*                           recls_rc_t;

#ifdef __cplusplus

/** General success code.
 *
 * \ingroup group__recls
 */
const recls_rc_t RECLS_RC_OK = RECLS_RC_OK_;
/** General failure code.
 *
 * \ingroup group__recls
 */
const recls_rc_t RECLS_RC_FAIL = RECLS_RC_FAIL_;

/** Returns non-zero if the given return code indicates failure.
 *
 * \ingroup group__recls
 */
inline bool RECLS_FAILED(recls_rc_t const &rc)
{
    recls_uintptr_t rcs = ((recls_uintptr_t)(void*)(recls_rc_t)(rc));

#ifndef __BORLANDC__
    static
#endif /* Borland */
           recls_uintptr_t const highBit = recls_uintptr_t(0x01) << (sizeof(recls_uintptr_t) * 8 - 1);

    return 0 != (highBit & rcs);
}

/** Returns non-zero if the given return code indicates success.
 *
 * \ingroup group__recls
 */
inline bool RECLS_SUCCEEDED(recls_rc_t const &rc)
{
    return !RECLS_FAILED(rc);
}

#else /* ? __cplusplus */

/** General success code.
 *
 * \ingroup group__recls
 */
# define RECLS_RC_OK                                        RECLS_RC_OK_
/** General failure code.
 *
 * \ingroup group__recls
 */
# define RECLS_RC_FAIL                                      RECLS_RC_FAIL_

/** Evaluates to non-zero if the given return code indicates failure.
 *
 * \ingroup group__recls
 */
# define RECLS_FAILED(rc)                                   (0 != (((recls_uintptr_t)(0x01) << (sizeof(recls_uintptr_t) * 8 - 1)) & ((recls_uintptr_t)(void*)(recls_rc_t)(rc))))

/** Evaluates to non-zero if the given return code indicates success.
 *
 * \ingroup group__recls
 */
# define RECLS_SUCCEEDED(rc)                                (!RECLS_FAILED(rc))

#endif /* __cplusplus */

/* hrecls_t */
#if !defined(RECLS_DOCUMENTATION_SKIP_SECTION) && \
    defined(RECLS_COMPILER_IS_BORLAND) && \
    __BORLANDC__ < 0x0560
struct hrecls_t_
{
    int dummy;
};
#else /* ? compiler */
struct hrecls_t_;
#endif /* compiler */

/** The handle to a recursive search operation.
 *
 * \ingroup group__recls
 */
typedef struct hrecls_t_ const*                             hrecls_t;


/* /////////////////////////////////////////////////////////////////////////
 * trying to get Borland to get over itself
 */

#if defined(__cplusplus) && \
    defined(__BORLANDC__)
# pragma warn -8026

namespace borland_compatibility
{

    struct compatibility_initialiser
    {
        ~compatibility_initialiser() throw()
        {
            /* Required for Borland */
            ((void)RECLS_RC_OK);
            ((void)RECLS_RC_FAIL);
        }
    };
    static compatibility_initialiser s_init;

} /* namespace borland_compatibility */

# pragma warn .8026
#endif /* C++ & Borland */


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* Defines result codes */
#include <recls/internal/retcodes.h>


/* /////////////////////////////////////////////////////////////////////////
 * namespace
 */

#if !defined(RECLS_NO_NAMESPACE)
namespace recls
{
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * enumerations
 */

/** Search flags
 *
 * \ingroup group__recls
 *
 * These flags moderate the search behaviour of the
 * Recls_Search(), Recls_SearchFeedback(), and Recls_SearchProcess() functions.
 */
enum RECLS_FLAG
{
        RECLS_F_FILES                               =   0x00000001  /*!< Include files in search. Included by default if none specified */
    ,   RECLS_F_DIRECTORIES                         =   0x00000002  /*!< Include directories in search */
    ,   RECLS_F_LINKS                               =   0x00000004  /*!< Include links in search. Ignored in Windows */
    ,   RECLS_F_DEVICES                             =   0x00000008  /*!< Include devices in search. Not currently supported */
    ,   RECLS_F_TYPEMASK                            =   0x00000FFF
    ,   RECLS_F_DIR_PROGRESS                        =   0x00001000  /*!< Reports each traversed directory to the callback function supplied to Recls_SearchFeedback() */
    ,   RECLS_F_STOP_ON_ACCESS_FAILURE              =   0x00002000  /*!< Stops if a directory cannot be accessed. Supported on Windows from version 1.9 onwards. */
    ,   RECLS_F_LINK_COUNT                          =   0x00004000  /*!< Records the number of links to the entry */
    ,   RECLS_F_NODE_INDEX                          =   0x00008000  /*!< Records the node index of the entry */
    ,   RECLS_F_RECURSIVE                           =   0x00010000  /*!< Searches given directory and all sub-directories */
    ,   RECLS_F_NO_FOLLOW_LINKS                     =   0x00020000  /*!< Does not expand links */
    ,   RECLS_F_DIRECTORY_PARTS                     =   0x00040000  /*!< Fills out the directory parts. Supported from version 1.1.1 onwards */
    ,   RECLS_F_DETAILS_LATER                       =   0x00080000  /*!< Does not fill out anything other than the path. When specified to Recls_Stat(), and no types (RECLS_F_TYPEMASK) are specified, this will allow some details for a non-existant path to be elicited. */
    ,   RECLS_F_PASSIVE_FTP                         =   0x00100000  /*!< Passive mode in FTP. Supported from version 1.5.1 onwards */
    ,   RECLS_F_MARK_DIRS                           =   0x00200000  /*!< Marks the directories with a trailing slash. */
    ,   RECLS_F_ALLOW_REPARSE_DIRS                  =   0x00400000  /*!< Allow Windows reparse point directories to be examined (which can cause infinite loops). */
#if 0
    ,   RECLS_F_CALC_CHECKSUM                       =   0x00800000
#endif /* 0 */
    ,   RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS        =   0x01000000  /*!< Treats the callbacks as <b>stdcall</b> calling convention on Windows. Default is <b>cdecl</b>. This is useful for interfacing as delegates with .NET */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
    ,   RECLS_F_CALLBACKS_STDCALL_ON_WIN32          =   RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */
    ,   RECLS_F_USE_TILDE_ON_NO_SEARCHROOT          =   0x04000000  /*!< Interprets a NULL or empty searchRoot as the home directory, rather than the current directory. Supported from version 1.8.1 onwards. */
#if 0
    ,   RECLS_F_DIR_SIZE_IS_NUM_FILES               =   0x02000000  /*!< This causes the size of the directory to be the number of files contained within it, rather than being 0. */
#endif /* 0 */
    ,   RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS    =   0x08000000  /*!< This causes hidden files to be ignored. Currently supported on Windows only. */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
    ,   RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WIN32      =   RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

#if !defined(FILES)
    ,   FILES = RECLS_F_FILES /*!< RECLS_F_FILES. */
#endif /* !FILES */

#if !defined(DIRECTORIES)
    ,   DIRECTORIES = RECLS_F_DIRECTORIES /*!< RECLS_F_DIRECTORIES. */
#endif /* !DIRECTORIES */

#if !defined(LINKS)
    ,   LINKS = RECLS_F_LINKS /*!< RECLS_F_LINKS. */
#endif /* !LINKS */

#if !defined(DEVICES)
    ,   DEVICES = RECLS_F_DEVICES /*!< RECLS_F_DEVICES. */
#endif /* !DEVICES */

#if !defined(TYPEMASK)
    ,   TYPEMASK = RECLS_F_TYPEMASK /*!< RECLS_F_TYPEMASK. */
#endif /* !TYPEMASK */

#if !defined(DIR_PROGRESS)
    ,   DIR_PROGRESS = RECLS_F_DIR_PROGRESS /*!< RECLS_F_DIR_PROGRESS. */
#endif /* !DIR_PROGRESS */

#if !defined(STOP_ON_ACCESS_FAILURE)
    ,   STOP_ON_ACCESS_FAILURE = RECLS_F_STOP_ON_ACCESS_FAILURE /*!< RECLS_F_STOP_ON_ACCESS_FAILURE. */
#endif /* !STOP_ON_ACCESS_FAILURE */

#if !defined(LINK_COUNT)
    ,   LINK_COUNT = RECLS_F_LINK_COUNT /*!< RECLS_F_LINK_COUNT. */
#endif /* !LINK_COUNT */

#if !defined(NODE_INDEX)
    ,   NODE_INDEX = RECLS_F_NODE_INDEX /*!< RECLS_F_NODE_INDEX. */
#endif /* !LINK_COUNT */

#if !defined(RECURSIVE)
    ,   RECURSIVE = RECLS_F_RECURSIVE /*!< RECLS_F_RECURSIVE. */
#endif /* !RECURSIVE */

#if !defined(NO_FOLLOW_LINKS)
    ,   NO_FOLLOW_LINKS = RECLS_F_NO_FOLLOW_LINKS /*!< RECLS_F_NO_FOLLOW_LINKS. */
#endif /* !NO_FOLLOW_LINKS */

#if !defined(DIRECTORY_PARTS)
    ,   DIRECTORY_PARTS = RECLS_F_DIRECTORY_PARTS /*!< RECLS_F_DIRECTORY_PARTS. */
#endif /* !DIRECTORY_PARTS */

#if !defined(DETAILS_LATER)
    ,   DETAILS_LATER = RECLS_F_DETAILS_LATER /*!< RECLS_F_DETAILS_LATER. */
#endif /* !DETAILS_LATER */

#if !defined(PASSIVE_FTP)
    ,   PASSIVE_FTP = RECLS_F_PASSIVE_FTP /*!< RECLS_F_PASSIVE_FTP. */
#endif /* !PASSIVE_FTP */

#if !defined(MARK_DIRS)
    ,   MARK_DIRS = RECLS_F_MARK_DIRS /*!< RECLS_F_MARK_DIRS. */
#endif /* !MARK_DIRS */

#if !defined(ALLOW_REPARSE_DIRS)
    ,   ALLOW_REPARSE_DIRS = RECLS_F_ALLOW_REPARSE_DIRS /*!< RECLS_F_ALLOW_REPARSE_DIRS. */
#endif /* !ALLOW_REPARSE_DIRS */

#if 0
# if !defined(CALC_CHECKSUM)
    ,   CALC_CHECKSUM = RECLS_F_CALC_CHECKSUM /*!< RECLS_F_CALC_CHECKSUM. */
# endif /* !CALC_CHECKSUM */
#endif /* 0 */

#if !defined(CALLBACKS_STDCALL_ON_WINDOWS)
    ,   CALLBACKS_STDCALL_ON_WINDOWS = RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS /*!< RECLS_F_CALLBACKS_STDCALL_ON_WINDOWS. */
#endif /* !CALLBACKS_STDCALL_ON_WINDOWS */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# if !defined(CALLBACKS_STDCALL_ON_WIN32)
    ,   CALLBACKS_STDCALL_ON_WIN32 = RECLS_F_CALLBACKS_STDCALL_ON_WIN32
# endif /* !CALLBACKS_STDCALL_ON_WIN32 */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/*  ,   DIR_SIZE_IS_NUM_CHILDREN    =   RECLS_F_DIR_SIZE_IS_NUM_CHILDREN    */

#if !defined(F_USE_TILDE_ON_NO_SEARCHROOT)
    ,   USE_TILDE_ON_NO_SEARCHROOT = RECLS_F_USE_TILDE_ON_NO_SEARCHROOT /*!< RECLS_F_USE_TILDE_ON_NO_SEARCHROOT. */
#endif /* !RECLS_F_USE_TILDE_ON_NO_SEARCHROOT */

#if !defined(IGNORE_HIDDEN_ENTRIES_ON_WINDOWS)
    ,   IGNORE_HIDDEN_ENTRIES_ON_WINDOWS = RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS /*!< RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS. */
#endif /* !IGNORE_HIDDEN_ENTRIES_ON_WINDOWS */
#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# if !defined(IGNORE_HIDDEN_ENTRIES_ON_WIN32)
    ,   IGNORE_HIDDEN_ENTRIES_ON_WIN32 = RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WIN32
# endif /* !IGNORE_HIDDEN_ENTRIES_ON_WIN32 */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

#if 0
#if !defined(RECLS_F_DIR_SIZE_IS_NUM_FILES)
    ,   DIR_SIZE_IS_NUM_FILES = RECLS_F_DIR_SIZE_IS_NUM_FILES /*!< RECLS_F_DIR_SIZE_IS_NUM_FILES. */
#endif /* !RECLS_F_DIR_SIZE_IS_NUM_FILES */
#endif /* 0 */
};

/** Flags that moderate the search behaviour of the Recls_GetSelectedRoots() function.
 *
 * \ingroup group__recls
 *
 * \note The flags are ignored on UNIX, since the only root is '/'
 */
enum RECLS_ROOTS_FLAG
{
        RECLS_ROOTS_F_FIXED_DRIVES      =   0x0001  /*!< Include local fixed drives. */
    ,   RECLS_ROOTS_F_NETWORK_DRIVES    =   0x0002  /*!< Include network drives. */
    ,   RECLS_ROOTS_F_CDROM_DRIVES      =   0x0004  /*!< Include CD-ROM / DVD-ROM drives. */
    ,   RECLS_ROOTS_F_REMOVABLE_DRIVES  =   0x0008  /*!< Include removable drives. */
    ,   RECLS_ROOTS_F_RAM_DRIVES        =   0x0010  /*!< Include RAM drives. */

#ifndef RECLS_NO_NAMESPACE
    ,   FixedDrives                     =   RECLS_ROOTS_F_FIXED_DRIVES      /*!< Include local fixed drives. RECLS_ROOTS_F_FIXED_DRIVES. */
    ,   NetworkDrives                   =   RECLS_ROOTS_F_NETWORK_DRIVES    /*!< Include network drives. RECLS_ROOTS_F_NETWORK_DRIVES. */
    ,   CDRomDrives                     =   RECLS_ROOTS_F_CDROM_DRIVES      /*!< Include CD-ROM / DVD-ROM drives. RECLS_ROOTS_F_CDROM_DRIVES. */
    ,   RemovableDrives                 =   RECLS_ROOTS_F_REMOVABLE_DRIVES  /*!< Include removable drives. RECLS_ROOTS_F_REMOVABLE_DRIVES. */
    ,   RamDrives                       =   RECLS_ROOTS_F_RAM_DRIVES        /*!< Include RAM drives. RECLS_ROOTS_F_RAM_DRIVES. */
#endif /* !RECLS_NO_NAMESPACE */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
    ,   RECLS_F_FIXED_DRIVES            =   RECLS_ROOTS_F_FIXED_DRIVES
    ,   RECLS_F_NETWORK_DRIVES          =   RECLS_ROOTS_F_NETWORK_DRIVES
    ,   RECLS_F_CDROM_DRIVES            =   RECLS_ROOTS_F_CDROM_DRIVES
    ,   RECLS_F_REMOVABLE_DRIVES        =   RECLS_ROOTS_F_REMOVABLE_DRIVES
    ,   RECLS_F_RAM_DRIVES              =   RECLS_ROOTS_F_RAM_DRIVES
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */
};

/** Flags that moderate the behaviour of Recls_RemoveDirectory()
 *
 * \ingroup group__recls
 */
enum RECLS_REMDIR_FLAG
{
        RECLS_REMDIR_F_NO_REMOVE_SUBDIRS    =   0x0001  /*!< By default, empty sub-directories are removed, unless this flag is specified */
    ,   RECLS_REMDIR_F_REMOVE_FILES         =   0x0002  /*!< By default, files are not removed, unless this flag is specified */
    ,   RECLS_REMDIR_F_REMOVE_READONLY      =   0x0004  /*!< By default, read-only files are not removed, unless this flag is specified */
};

#if !defined(__cplusplus) && \
    !defined(RECLS_DOCUMENTATION_SKIP_SECTION)
typedef enum RECLS_FLAG         RECLS_FLAG;
typedef enum RECLS_ROOTS_FLAG   RECLS_ROOTS_FLAG;
#endif /* !__cplusplus && !RECLS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

/* #if defined(RECLS_PLATFORM_IS_WINDOWS)
# define RECLS_ROOT_NAME_LEN                                (3)
#elif defined(RECLS_PLATFORM_IS_UNIX)
 */
#ifndef RECLS_COMPILER_IS_CH
/** Structure containing information about a file-system root.
 *
 * \ingroup group__recls
 */
struct recls_root_t
{
    /** The name of the root.
     *
     * \remarks For UNIX compilation, this is a two character nul-terminated
     *   array that always contains the string <code>"/"</code>. On Windows,
     *   this is a four character nul-terminated array that contains a drive
     *   specification, e.g. <code>"H:\\"</code>.
     */
    recls_char_t    name[1 + RECLS_ROOT_NAME_LEN];
};

# ifndef RECLS_NO_NAMESPACE
typedef recls_root_t                                        root_t;
# elif !defined(__cplusplus)
typedef struct recls_root_t                                 recls_root_t;
# endif /* __cplusplus */

/** Structure used to return statistics about the modifications performed by
 * the Recls_CreateDirectory() and Recls_RemoveDirectory() functions.
 *
 */
struct recls_directoryResults_t
{
    unsigned    numExistingElements;    /*!< (Maximum) number of parts in any (sub-)directory before the operation commences. */
    unsigned    numResultingElements;   /*!< (Maximum) number of parts in the resulting directory after the operation returns. */
    size_t      existingLength;         /*!< For create operation, the length of the directory before the operation; for remove operation, the length of the longest sub-directory removed. */
    size_t      resultingLength;        /*!< Length of the directory after the operation */
    unsigned    numExistingFiles;       /*!< Number of files existing before a remove operation */
    unsigned    numDeletedFiles;        /*!< Number of files existing after a remove operation */
};

# ifndef RECLS_NO_NAMESPACE
typedef recls_directoryResults_t                            directoryResults_t;
# elif !defined(__cplusplus)
typedef struct recls_directoryResults_t                     recls_directoryResults_t;
# endif /* __cplusplus */

#endif /* !RECLS_COMPILER_IS_CH */

#ifndef RECLS_COMPILER_IS_CH
struct recls_entryinfo_t;
#endif /* !RECLS_COMPILER_IS_CH */

/** Opaque type representing a file-system entry information.
 *
 * \ingroup group__recls
 */
typedef struct recls_entryinfo_t const*                     recls_entry_t;
#if !defined(RECLS_NO_NAMESPACE)
typedef recls_entry_t                                       entry_t;
#endif /* !RECLS_NO_NAMESPACE */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
typedef recls_entry_t                                       recls_info_t;
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** Opaque type representing a user-defined parameter to the process function.
 *
 * \ingroup group__recls
 */
typedef void*                                               recls_process_fn_param_t;

/** User-supplied process function, used by Recls_SearchProcess()
 *
 * \ingroup group__recls
 *
 * \param hEntry entry info structure
 * \param param the parameter passed to Recls_SearchProcess()
 *
 * \return A status to indicate whether to continue or cancel the processing
 * \retval 0 cancel the processing
 * \retval non-0 continue the processing
 */
typedef int (RECLS_CALLCONV_DEFAULT *hrecls_process_fn_t)(
    /* [in] */ recls_entry_t            hEntry
,   /* [in] */ recls_process_fn_param_t param
);

/** User-supplied process function, used by Recls_SearchFeedback(), which receives the
 * sub-directories traversed
 *
 * \ingroup group__recls
 *
 * \param dir The nul-terminated C-style string containing the sub-directory's full path
 * \param dirLen The number of characters in the \c dir param, not including the nul-terminator
 * \param param the parameter passed to Recls_SearchFeedback()
 *
 * \return A status to indicate whether to continue or cancel the processing
 * \retval 0 cancel the processing
 * \retval non-0 continue the processing
 */
typedef int (RECLS_CALLCONV_DEFAULT *hrecls_progress_fn_t)(
    /* [in] */ recls_char_t const*      dir
,   /* [in] */ size_t                   dirLen
,   /* [in] */ recls_process_fn_param_t param
,   /* [in] */ void*                    reserved0
,   /* [in] */ recls_uint32_t           reserved1
);


/* /////////////////////////////////////////////////////////////////////////
 * namespace typedefs
 */

#if !defined(RECLS_NO_NAMESPACE)
typedef recls_entry_t                                       info_t;
typedef recls_process_fn_param_t                            process_fn_param_t;
#endif /* !RECLS_NO_NAMESPACE */


/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

/***************************************
 * File system
 */

/** \name File system functions
 *
 * \ingroup group__recls
 */
/** @{ */

#ifndef RECLS_COMPILER_IS_CH
/** Retrieves the file-system roots for the current operating system.
 *
 * \ingroup group__recls
 *
 * It is used as follows:
 *
\htmlonly
<pre>
  recls_root_t  roots[26];
  size_t        cRoots  = Recls_GetRoots(&roots[0], 26);
  size_t        i;

  for (i = 0; i < cRoots; ++i)
  {
    puts(roots[i].name);
  }
</pre>
\endhtmlonly
 *
 * \param roots A pointer to an array of size \c cRoots. If NULL, the function returns the number of available roots.
 * \param cRoots The maximum number of roots to retrive in \c roots.
 *
 * \return The number of roots actually retrieved. If \c roots is NULL, then this is the current number of roots on
 * the current operating system. If \c roots is not NULL, then this is the number of roots written into \c roots, and
 * is not more than \c cRoots.
 */
RECLS_FNDECL(size_t)
Recls_GetRoots(
    /* [in] */ recls_root_t*    roots
,   /* [in] */ size_t           cRoots
);

/** Like Recls_GetRoots(), but only returns roots of selected disk types
 *
 * \ingroup group__recls
 *
 * \param roots A pointer to an array of size \c cRoots. If NULL, the function returns the number of available roots.
 * \param cRoots The maximum number of roots to retrive in \c roots.
 * \param flags Combination of the recls::RECLS_ROOTS_FLAG enumeration. If 0, implies all available root types.
 *
 * \return The number of roots actually retrieved. If \c roots is NULL, then this is the current number of roots on
 * the current operating system. If \c roots is not NULL, then this is the number of roots written into \c roots, and
 * is not more than \c cRoots.
 */
RECLS_FNDECL(size_t)
Recls_GetSelectedRoots(
    /* [in] */ recls_root_t*    roots
,   /* [in] */ size_t           cRoots
,   /* [in] */ recls_uint32_t   flags
);

#endif /* !RECLS_COMPILER_IS_CH */

#if 0
/* New Recls1 API. */
RECLS_FNDECL(size_t)
Recls1_FileSystem_GetRoots(
    /* [in] */ recls_root_t*    roots
,   /* [in] */ size_t           cRoots
,   /* [in] */ recls_uint32_t   flags
);
#endif /* 0 */


/** Returns the symbol used to separate distinct path names in path name lists.
 *
 * \ingroup group__recls
 *
 * \note On UNIX this is \c "/"; on Windows it is \c "\".
 *
 * It is used as follows:
 *
\htmlonly
<pre>
  puts(Recls_GetPathNameSeparator());
</pre>
\endhtmlonly
 */
RECLS_FNDECL(recls_char_t const*)
Recls_GetPathNameSeparator(void);

#if 0
/* New Recls1 API. */
RECLS_FNDECL(recls_char_t const*)
Recls1_FileSystem_GetPathNameSeparator(void);
#endif /* 0 */

/** Returns the symbol used to separate the directory parts within paths.
 *
 * \ingroup group__recls
 *
 * \note On UNIX this is \c ":"; on Windows it is \c ";".
 *
 * It is used as follows:
 *
\htmlonly
<pre>
  puts(Recls_GetPathSeparator());
</pre>
\endhtmlonly
 */
RECLS_FNDECL(recls_char_t const*)
Recls_GetPathSeparator(void);

#if 0
/* New Recls1 API. */
RECLS_FNDECL(recls_char_t const*)
Recls1_FileSystem_GetPathSeparator(void);
#endif /* 0 */

/** Returns the wildcard symbol used to represent the "all files" for the current operating system.
 *
 * \ingroup group__recls
 *
 * \note On UNIX this is \c "*"; on Windows it is \c "*.*".
 *
 * It is used as follows:
 *
\htmlonly
<pre>
  puts(Recls_GetWildcardsAll());
</pre>
\endhtmlonly
 */
RECLS_FNDECL(recls_char_t const*)
Recls_GetWildcardsAll(void);

#if 0
/* New Recls1 API. */
RECLS_FNDECL(recls_char_t const*)
Recls1_FileSystem_GetWildcardsAll(void);
#endif /* 0 */

/** @} */

/***************************************
 * Search control
 */

/** \name Search control functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Searches a given directory for matching files of the given pattern
 *
 * \ingroup group__recls
 *
 * \param searchRoot The directory representing the root of the search. NULL
 *   or "" means the current directory is assumed, unless
 *   RECLS_F_USE_TILDE_ON_NO_SEARCHROOT
 *   is specified, in which case the calling identity's home directory is
 *   assumed.
 * \param pattern The search pattern, e.g. "*.c". NULL means "all files". ""
 *   means no files.
 * \param flags A combination of 0 or more
 *   RECLS_FLAG values.
 * \param phSrch Address of the search handle. This is set to NULL on
 *   failure.
 *
 * \return A status code indicating success/failure.
 * \retval RECLS_RC_NO_MORE_DATA No items matched the given search criteria.
 */
RECLS_API Recls_Search(
    /* [in] */ recls_char_t const*  searchRoot
,   /* [in] */ recls_char_t const*  pattern
,   /* [in] */ recls_uint32_t       flags
,   /* [out] */ hrecls_t*           phSrch
);

/** Searches a given directory for matching files of the given pattern, calling back
 * on the given progress function pointer to inform the caller as each (sub-)directory
 * is traversed.
 *
 * \ingroup group__recls
 *
 * \param searchRoot The directory representing the root of the search
 * \param pattern The search pattern, e.g. "*.c"
 * \param flags A combination of 0 or more
 *   RECLS_FLAG values.
 * \param pfn The function that will be invoked for each directory traversed
 * \param param The caller-defined parameter that is passed to the callback function
 * \param phSrch Address of the search handle. This is set to NULL on failure
 *
 * \return A status code indicating success/failure
 */
RECLS_API Recls_SearchFeedback(
    /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          pattern
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_progress_fn_t         pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [out] */ hrecls_t*                   phSrch
);

RECLS_API Recls_SearchProcessFeedback(
    /* [in] */ recls_char_t const*          searchRoot
,   /* [in] */ recls_char_t const*          pattern
,   /* [in] */ recls_uint32_t               flags
,   /* [in] */ hrecls_process_fn_t          pfn
,   /* [in] */ recls_process_fn_param_t     param
,   /* [in] */ hrecls_progress_fn_t         pfnProgress
,   /* [out] */ recls_process_fn_param_t    paramProgress
);

/** Searches a given directory for matching files of the given pattern, and processes them according to the given process function
 *
 * \ingroup group__recls
 *
 * \param searchRoot The directory representing the root of the search
 * \param pattern The search pattern, e.g. "*.c"
 * \param flags A combination of 0 or more
 *   RECLS_FLAG values.
 * \param pfn The processing function
 * \param param A caller-supplied parameter that is passed through to \c pfn on each invocation. The function can cancel the enumeration by returning 0
 *
 * \return A status code indicating success/failure
 *
 * \note Available from version 1.1 of the <b>recls</b> API
 */
RECLS_API Recls_SearchProcess(
    /* [in] */ recls_char_t const*      searchRoot
,   /* [in] */ recls_char_t const*      pattern
,   /* [in] */ recls_uint32_t           flags
,   /* [in] */ hrecls_process_fn_t      pfn
,   /* [in] */ recls_process_fn_param_t param
);

/** Closes the given search
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 */
RECLS_FNDECL(void)
Recls_SearchClose(
    /* [in] */ hrecls_t hSrch
);

#if 0
/* New Recls1 API. */
RECLS_API Recls1_FileSystem_CloseSearch(
    /* [in] */ hrecls_t hSrch
);
#endif /* 0 */


/** Retrieves the information for the given path
 *
 * \ingroup group__recls
 *
 * \param path Absolute or relative path of the file system entry whose information is to be retrieved. May not be NULL
 * \param flags Flags to moderate the search. Only the type flags (flags & RECLS_F_TYPEMASK) and RECLS_F_DIRECTORY_PARTS are recognised
 * \param phEntry Pointer to receive entry info structure. May not be NULL.
 *
 * \return Status code
 * \retval RECLS_RC_OK Position was advanced; search handle can be queried for details
 * \retval RECLS_RC_NO_MORE_DATA There was no file system entry that matched the \c path and \c flags criteria
 * \retval Any other status code indicates an error
 *
 * \pre (NULL != path)
 * \pre (NULL != phEntry)
 */
RECLS_API Recls_Stat(
    /* [in] */ recls_char_t const*  path
,   /* [in] */ recls_uint32_t       flags
,   /* [out] */ recls_entry_t*      phEntry
);

#if 0
/* New Recls1 API. */
RECLS_API Recls1_FileSystem_Stat(
    /* [in] */ Recls1_char_t const* path
,   /* [in] */ Recls1_uint32_t      flags
,   /* [out] */ Recls1_entry_t*     pentry
);
#endif /* 0 */


/** @} */

/***************************************
 * Search enumeration
 */

/** \name Search enumeration functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Advances the search one position
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 *
 * \return Status code
 * \retval RECLS_RC_OK Position was advanced; search handle can be queried for details
 * \retval RECLS_RC_NO_MORE_DATA There are no more items in the search
 * \retval Any other status code indicates an error
 */
RECLS_API Recls_GetNext(
    /* [in] */ hrecls_t hSrch
);

#if 0
/* New Recls1 API. */
RECLS_API Recls1_Search_Next(
    /* [in] */ hrecls_t hSrch
);
#endif /* 0 */


/** Retrieves the information for the current search position
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 * \param phEntry Pointer to receive entry info structure.
 *
 * \return Status code
 * \retval RECLS_RC_OK Position was advanced; search handle can be queried for details
 * \retval RECLS_RC_NO_MORE_DATA There are no more items in the search
 * \retval Any other status code indicates an error
 */
RECLS_API Recls_GetDetails(
    /* [in] */ hrecls_t         hSrch
,   /* [out] */ recls_entry_t*  phEntry
);

#if 0
/* New Recls1 API. */
#endif /* 0 */

/** Advances the search one position, and retrieves the information for the new position
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 * \param phEntry Pointer to receive entry info structure.
 *
 * \return Status code
 * \retval RECLS_RC_OK Position was advanced; search handle can be queried for details
 * \retval Any other status code indicates an error
 */
RECLS_API Recls_GetNextDetails(
    /* [in] */ hrecls_t         hSrch
,   /* [out] */ recls_entry_t*  phEntry
);

/** @} */

/***************************************
 * File entry information
 */

/** \name File entry information functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Releases the resources associated with an entry info structure.
 *
 * \ingroup group__recls
 *
 * \param hEntry The info entry structure handle. Must not be NULL.
 */
RECLS_FNDECL(void)
Recls_CloseDetails(
    /* [in] */ recls_entry_t hEntry
);

/** Copies an entry info structure.
 *
 * \ingroup group__recls
 *
 * \param hEntry The info entry structure.
 * \param phEntry Address to receive a copy of the info entry structure. May not be NULL.
 *
 * \return Status code
 * \retval RECLS_RC_OK Entry was generated.
 * \retval Any other status code indicates an error
 */
RECLS_API Recls_CopyDetails(
    /* [in] */ recls_entry_t    hEntry
,   /* [out] */ recls_entry_t*  phEntry
);

/** @} */

/***************************************
 * Error handling
 */

/** \name Error handling functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Returns the last error code associated with the given search handle
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 *
 * \return The last error code for the search handle
 */
RECLS_API Recls_GetLastError(
    /* [in] */ hrecls_t hSrch
);

/** Gets the error string representing the given error
 *
 * \ingroup group__recls
 *
 * \param rc The error code
 * \param buffer Pointer to character buffer in which to write the error. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for the error.
 */
RECLS_FNDECL(size_t)
Recls_GetErrorString(
    /* [in] */ recls_rc_t       rc
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Gets the error string representing the current error associated with the given search handle
 *
 * \ingroup group__recls
 *
 * \param hSrch Handle of the search to close. May not be NULL.
 * \param buffer Pointer to character buffer in which to write the error. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the error.
 */
RECLS_FNDECL(size_t)
Recls_GetLastErrorString(
    /* [in] */ hrecls_t         hSrch
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);


/** Returns a pointer to a C-style string representing the given search code
 *
 * \ingroup group__recls
 *
 * \param rc The error code
 */
RECLS_FNDECL(recls_char_t const*)
Recls_GetSearchCodeString(/* [in] */ recls_rc_t rc);

/** Returns the length of the C-style string returned by
 *   Recls_GetSearchCodeString() representing the given search code
 *
 * \ingroup group__recls
 *
 * \param rc The error code
 */
RECLS_FNDECL(size_t)
Recls_GetSearchCodeStringLength(/* [in] */ recls_rc_t rc);

/** Translates the recls status code, into an errno
 *
 * \ingroup group__recls
 *
 * \param rc The error code
 *
 * \return The errno equivalent.
 */
RECLS_FNDECL(int)
Recls_GetErrno(
    /* [in] */ recls_rc_t rc
);

/** @} */

/***************************************
 * Property elicitation
 */

/** \name Property elicitation functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Retrieves the full path of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the path. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the path.
 */
RECLS_FNDECL(size_t)
Recls_GetPathProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the path of the given entry recls_entryinfo_t, relative to the search directory
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the path. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the path.
 */
RECLS_FNDECL(size_t)
Recls_GetSearchRelativePathProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the directory of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the directory. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the directory.
 */
RECLS_FNDECL(size_t)
Recls_GetDirectoryProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the directory (and drive) of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the directory. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the directory.
 *
 * \note On systems that do not have a drive, this function behaves identically to Recls_GetDirectoryProperty()
 */
RECLS_FNDECL(size_t)
Recls_GetDirectoryPathProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the directory (and drive) of the given entry recls_entryinfo_t that was used in the search resulting in the given entry
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the directory. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the directory.
 */
RECLS_FNDECL(size_t)
Recls_GetSearchDirectoryProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the UNC drive property of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the directory. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the directory.
 *
 * \note On operating systems that do not support UNC, this function always returns 0, and writes the empty string into buffer (when non-NULL)
 */
RECLS_FNDECL(size_t)
Recls_GetUNCDriveProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the file (filename + extension) of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the file. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the file.
 */
RECLS_FNDECL(size_t)
Recls_GetFileProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the short version of the file of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the file. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the file.
 *
 * \note On systems where there is no concept of a short name, this function behaves exactly as Recls_GetFileProperty()
 */
RECLS_FNDECL(size_t)
Recls_GetShortFileProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the filename (not including extension, if any) of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the filename. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the filename.
 */
RECLS_FNDECL(size_t)
Recls_GetFileNameProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves the file extension of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param buffer Pointer to character buffer in which to write the extension. If NULL, the function returns the number of characters required.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the extension.
 */
RECLS_FNDECL(size_t)
Recls_GetFileExtProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);

/** Retrieves a directory part of the given entry recls_entryinfo_t
 *
 * \ingroup group__recls
 *
 * \param hEntry The entry recls_entryinfo_t. Cannot be NULL
 * \param part The part requested. If -1, then the function returns the number of parts
 * \param buffer Pointer to character buffer in which to write the extension. If NULL, the function returns the number of characters required. Ignored if part is -1.
 * \param cchBuffer Number of character spaces in \c buffer. Ignored if \c buffer is NULL or part is -1.
 *
 * \return If \c part is -1, returns the number of parts. Otherwise, The number of characters written to the buffer, or required for, the extension.
 *
 * \note The behaviour is undefined if part is outside the range of parts.
 */
RECLS_FNDECL(size_t)
Recls_GetDirectoryPartProperty(
    /* [in] */ recls_entry_t    hEntry
,   /* [in] */ int              part
,   /* [in] */ recls_char_t     buffer[]
,   /* [in] */ size_t           cchBuffer
);


/** Indicates whether the represented file-system entity existed (at the time that the instance was elicited)
 */
RECLS_FNDECL(recls_bool_t)
Recls_EntryExists(
    /* [in] */ recls_entry_t hEntry
);

/** Returns non-zero if the file entry is read-only.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 * \retval true file entry is read-only
 * \retval false file entry is not read-only
 *
 * \note There is no error return
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsFileReadOnly(
    /* [in] */ recls_entry_t hEntry
);

/** Returns non-zero if the file entry represents a directory.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 * \retval true file entry is a directory
 * \retval false file entry is not directory
 *
 * \note There is no error return
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsFileDirectory(
    /* [in] */ recls_entry_t hEntry
);

/** Returns non-zero if the file entry represents a link.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 * \retval true file entry is a link
 * \retval false file entry is not link
 *
 * \note There is no error return
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsFileLink(
    /* [in] */ recls_entry_t hEntry
);

/** Returns non-zero if the file entry exists "now".
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 * \retval true file entry exists in the file-system at the time of call.
 * \retval false file entry does not exist in the file-system at the time of call
 *
 * \note There is no error return.
 */
RECLS_FNDECL(recls_bool_t)
Recls_DoesEntryExist(
    /* [in] */ recls_entry_t hEntry
);

/** Returns non-zero if the file entry's path is UNC.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 * \retval true file entry's path is UNC
 * \retval false file entry's path is UNC
 *
 * \note There is no error return
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsFileUNC(
    /* [in] */ recls_entry_t hEntry
);

/** Returns the size of the file entry.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 *
 * \note There is no error return. File system entries that do not have a meaningful size will be given a notional size of 0.
 */
RECLS_FNDECL(recls_filesize_t)
Recls_GetSizeProperty(
    /* [in] */ recls_entry_t hEntry
);

/** Returns the time the file was created.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 */
RECLS_FNDECL(recls_time_t)
Recls_GetCreationTime(
    /* [in] */ recls_entry_t hEntry
);

/** Returns the time the file was last modified.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 */
RECLS_FNDECL(recls_time_t)
Recls_GetModificationTime(
    /* [in] */ recls_entry_t hEntry
);

/** Returns the time the file was last accessed.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 */
RECLS_FNDECL(recls_time_t)
Recls_GetLastAccessTime(
    /* [in] */ recls_entry_t hEntry
);

/** Returns the time the file status was last changed.
 *
 * \ingroup group__recls
 *
 * \param hEntry The file entry info structure to test. May not be NULL
 */
RECLS_FNDECL(recls_time_t)
Recls_GetLastStatusChangeTime(
    /* [in] */ recls_entry_t hEntry
);

#if 0
/** Returns the checksum value of the file.
 *
 * \ingroup group__recls
 *
 * \note This will return 0 if the entry is not a file, or its contents could
 * not be read, or RECLS_F_CALC_CHECKSUM was not specified.
 */
RECLS_FNDECL(recls_uint32_t)
Recls_GetChecksum(
    /* [in] */ recls_entry_t hEntry
);
#endif /* 0 */

/** @} */

/***************************************
 * Logging
 */

/** \name Logging functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** logging function pointer
 *
 * \param severity The severity parameter, which is one of the values
 *   specified in the <code>recls_log_severities_t::severities</code>
 *   array, and is not interpreted by the <strong>recls</strong>
 *   library
 * \param fmt A sprintf()-like format
 * \param args An arguments vector matching the \c fmt
 */

typedef void (RECLS_CALLCONV_DEFAULT* recls_log_pfn_t)(
    int                 severity
,   recls_char_t const* fmt
,   va_list             args
);

#ifndef RECLS_NO_NAMESPACE
typedef recls_log_pfn_t                 log_pfn_t;
#endif /* !RECLS_NO_NAMESPACE */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
struct recls_log_severities_t;

# ifndef RECLS_NO_NAMESPACE
typedef recls_log_severities_t          log_severities_t;
# elif !defined(__cplusplus)
typedef struct recls_log_severities_t   recls_log_severities_t;
# endif /* __cplusplus */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** Initialises an instance of recls_log_severities_t
 *
 * \param severities The recls_log_severities_t instance to be initialised.
 * \param fatalSeverity The severity for fatal conditions. Specify -1 to suppress.
 * \param errorSeverity The severity for error conditions. Specify -1 to suppress.
 * \param warningSeverity The severity for warning conditions. Specify -1 to suppress.
 * \param informationalSeverity The severity for informational conditions. Specify -1 to suppress.
 * \param debug0Severity The severity for debug (level 0) conditions. Specify -1 to suppress.
 * \param debug1Severity The severity for debug (level 1) conditions. Specify -1 to suppress.
 * \param debug2Severity The severity for debug (level 2) conditions. Specify -1 to suppress.
 * \param debug3Severity The severity for debug (level 3) conditions. Specify -1 to suppress.
 *
 * \pre (NULL != severities)
 */
RECLS_FNDECL(void)
Recls_LogSeverities_Init(
    recls_log_severities_t*         severities
,   int                             fatalSeverity
,   int                             errorSeverity
,   int                             warningSeverity
,   int                             informationalSeverity
,   int                             debug0Severity
,   int                             debug1Severity
,   int                             debug2Severity
,   int                             debug3Severity
);

/** \def Recls_LogSeverities_Init8(s, f, e, w, i, d0, d1, d2, d3)
 *
 * Initialises an instance of recls_log_severities_t with seven severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init8(s, f, e, w, i, d0, d1, d2, d3)    Recls_LogSeverities_Init((s), (f), (e), (w), (i), (d0), (d1), (d2), (d3))

/** \def Recls_LogSeverities_Init7(s, f, e, w, i, d0, d1, d2)
 *
 * Initialises an instance of recls_log_severities_t with seven severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init7(s, f, e, w, i, d0, d1, d2)        Recls_LogSeverities_Init7((s), (f), (e), (w), (i), (d0), (d1), (d2), -1)

/** \def Recls_LogSeverities_Init6(s, f, e, w, i, d0, d1)
 *
 * Initialises an instance of recls_log_severities_t with six severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init6(s, f, e, w, i, d0, d1)    Recls_LogSeverities_Init6((s), (f), (e), (w), (i), (d0), (d1), -1)

/** \def Recls_LogSeverities_Init5(s, f, e, w, i, d0)
 *
 * Initialises an instance of recls_log_severities_t with five severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init5(s, f, e, w, i, d0)        Recls_LogSeverities_Init5((s), (f), (e), (w), (i), (d0), -1)

/** \def Recls_LogSeverities_Init4(s, f, e, w, i)
 *
 * Initialises an instance of recls_log_severities_t with four severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init4(s, f, e, w, i)            Recls_LogSeverities_Init4((s), (f), (e), (w), (i), -1)

/** \def Recls_LogSeverities_Init3(s, f, e, w)
 *
 * Initialises an instance of recls_log_severities_t with three severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init3(s, f, e, w)               Recls_LogSeverities_Init4((s), (f), (e), (w), -11)

/** \def Recls_LogSeverities_Init2(s, f, e)
 *
 * Initialises an instance of recls_log_severities_t with two severity levels.
 *
 * \see Recls_LogSeverities_Init
 */
#define Recls_LogSeverities_Init2(s, f, e)                  Recls_LogSeverities_Init3((s), (f), (e), -1)



#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# if defined(__BORLANDC__)
#  pragma warn -8026
# endif /* compiler */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/** Structure containing a mapping of severities
 */
struct recls_log_severities_t
{
    /** An array of severities, ranked as follows:
     *
     * - [0] - Fatal condition
     * - [1] - Error condition
     * - [2] - Warning condition
     * - [3] - Informational condition
     * - [4] - Debug0 condition
     * - [5] - Debug1 condition
     * - [6] - Debug2 condition
     * - [7] - Debug3 condition
     *
     * Specifying an element with a value <0 disables logging for that
     * severity.
     */
    int   severities[8];

#ifdef __cplusplus
public:
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity, int informationalSeverity, int debug0Severity, int debug1Severity, int debug2Severity, int debug3Severity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, informationalSeverity, debug0Severity, debug1Severity, debug2Severity, debug3Severity);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity, int informationalSeverity, int debug0Severity, int debug1Severity, int debug2Severity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, informationalSeverity, debug0Severity, debug1Severity, debug2Severity, -1);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity, int informationalSeverity, int debug0Severity, int debug1Severity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, informationalSeverity, debug0Severity, debug1Severity, -1, -1);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity, int informationalSeverity, int debug0Severity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, informationalSeverity, debug0Severity, -1, -1, -1);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity, int informationalSeverity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, informationalSeverity, -1, -1, -1, -1);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity, int warningSeverity)
    {
        init_(fatalSeverity, errorSeverity, warningSeverity, -1, -1, -1, -1, -1);
    }
    recls_log_severities_t(int fatalSeverity, int errorSeverity)
    {
        init_(fatalSeverity, errorSeverity, -1, -1, -1, -1, -1, -1);
    }
private:
    void
    init_(
        int fatalSeverity
    ,   int errorSeverity
    ,   int warningSeverity
    ,   int informationalSeverity
    ,   int debug0Severity
    ,   int debug1Severity
    ,   int debug2Severity
    ,   int debug3Severity
    )
    {
        severities[0] = fatalSeverity;
        severities[1] = errorSeverity;
        severities[2] = warningSeverity;
        severities[3] = informationalSeverity;
        severities[4] = debug0Severity;
        severities[5] = debug1Severity;
        severities[6] = debug2Severity;
        severities[7] = debug3Severity;
    }
#endif /* __cplusplus */
};

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# if defined(STLSOFT_COMPILER_IS_BORLAND)
#  pragma warn .8026
# endif /* compiler */
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */



/** Registers a logging function
 *
 * \ingroup group__recls
 *
 * \param pfn Pointer to the function to use for logging. Specify NULL to
 *   remove previously registered function and suppress logging.
 * \param flags Currently unused.
 * \param severities Structure specifying severity mappings.
 *
 * \pre (NULL == severities) || (NULL != pfn)
 */
RECLS_FNDECL(void)
Recls_SetApiLogFunction(
    recls_log_pfn_t                 pfn
,   int                             flags
,   recls_log_severities_t const*   severities
);

/** @} */

/***************************************
 * Extended API functions
 */

/** \name Extended API functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Determines whether the given directory is empty
 *
 * \ingroup group__recls
 *
 * \param dir The directory to assess
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsDirectoryEmpty(
    /* [in] */ recls_char_t const* dir
);

/** Determines whether the given directory entry is empty
 *
 * \ingroup group__recls
 *
 * \param hEntry The directory entry to assess
 */
RECLS_FNDECL(recls_bool_t)
Recls_IsDirectoryEntryEmpty(
    /* [in] */ recls_entry_t hEntry
);

/** Calculates the number of bytes in files in the given directory
 *    and all its sub-directories.
 *
 * \ingroup group__recls
 *
 * \param dir The directory to assess
 */
RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectorySize(
    /* [in] */ recls_char_t const* dir
);

/** Calculates the number of bytes in files in the given directory
 *    entry and all its sub-directories.
 *
 * \ingroup group__recls
 *
 * \param hEntry The directory entry to assess
 */
RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectoryEntrySize(
    /* [in] */ recls_entry_t hEntry
);

/** Calculates the number of bytes in files in the given directory
 *   and all its sub-directories, calling back on the given progress
 *   function pointer to inform the caller as each (sub-)directory is
 *   traversed.
 *
 * \param dir The directory whose size will be calculated.
 * \param flags Ignores RECLS_F_DIRECTORIES, and always adds RECLS_F_FILES. Listens to selected others.
 * \param pfn The function that will be invoked for each directory traversed
 * \param param The caller-defined parameter that is passed to the callback function
 *
 * \return A status code indicating success/failure
 *
 */
RECLS_FNDECL(recls_filesize_t)
Recls_CalcDirectorySizeFeedback(
    /* [in] */ recls_char_t const*      dir
,   /* [in] */ recls_uint32_t           flags
,   /* [in] */ hrecls_progress_fn_t     pfn
,   /* [in] */ recls_process_fn_param_t param
);

/** @} */

/***************************************
 * Size functions
 */

/** \name Size functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Calculates the whole number of gigabytes in the file size.
 *
 * \ingroup group__recls
 */
RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeGigaBytes(recls_filesize_t size);

/** Calculates the whole number of megabytes in the file size.
 *
 * \ingroup group__recls
 */
RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeMegaBytes(recls_filesize_t size);

/** Calculates the whole number of kilobytes in the file size.
 *
 * \ingroup group__recls
 */
RECLS_FNDECL(recls_filesize_t)
Recls_GetFileSizeKiloBytes(recls_filesize_t size);

/** @} */

/***************************************
 * Path functions
 */

/** \name Path functions
 *
 * \ingroup group__recls
 */
/** @{ */

/** Combines two paths into one.
 *
 * \ingroup group__recls
 *
 * This function takes two path fragments and combines them to form a single path.
 *
 * \param path1 The left-most path.
 * \param path2 The right-most path.
 * \param result Pointer to character buffer in which to write the resultant path. If NULL, the function returns the number of characters required.
 * \param cchResult Number of character spaces in \c result. Ignored if \c result is NULL.
 *
 * \return The number of characters written to the buffer, or required for, the path.
 *
 * \remarks If \c path2 is an absolute path, \c path1 is ignored and
 *   \c result contains characters copied from \c path2.
 */
RECLS_FNDECL(size_t)
Recls_CombinePaths(
    /* [in] */ recls_char_t const*  path1
,   /* [in] */ recls_char_t const*  path2
,   /* [in] */ recls_char_t         result[]
,   /* [in] */ size_t               cchResult
);

/** Determines the relative path between two paths
 *
 * \ingroup group__recls
 *
 * \param origin The path against which the relativity of \c target will be evaluated. If NULL or the empty string, then the resultant path is equivalent to target.
 * \param target The path whose relatively (against \c origin) will be evaluated.
 * \param result Pointer to character buffer in which to write the resultant path. If NULL, the function returns the number of characters required.
 * \param cchResult Number of character spaces in \c result. Ignored if \c result is NULL.
 *
 * \remarks On operating systems that have drives, the result will be an
 *   absolute path (identical to \c target, in fact) if \c target and
 *   \c origin are located on different drives
 */
RECLS_FNDECL(size_t)
Recls_DeriveRelativePath(
    /* [in] */ recls_char_t const*  origin
,   /* [in] */ recls_char_t const*  target
,   /* [in] */ recls_char_t         result[]
,   /* [in] */ size_t               cchResult
);

/** Prepares the path for display into a fixed maximum width field.
 *
 * \ingroup group__recls
 *
 * \param path The path to be squeezed.
 * \param result Pointer to character buffer in which to write the resultant path. If NULL, the function returns the number of characters required.
 * \param cchResult Number of character spaces in \c result. Ignored if \c result is NULL.
 *
 * \return The number of characters required, not including the NUL terminator
 *
 * \pre NULL != path
 */
RECLS_FNDECL(size_t)
Recls_SqueezePath(
    /* [in] */ recls_char_t const*  path
,   /* [in] */ recls_char_t         result[]
,   /* [in] */ size_t               cchResult
);

/** Creates a directory, including all intermediate directories
 *
 * \ingroup group__recls
 *
 * \param path The path to create. If not absolute, is assumed relative to
 *   the current directory
 * \param results Pointer to an instance of \c recls_directoryResults_t in
 *   which information regarding the changes effected by the operation will
 *   be recorded. May be \c NULL
 *
 * \note If the function fails, no attempt is made to undo the intermediate
 *   directories created. The caller may establish which intermediate
 *   elements were created by analysing the results
 *
 * \pre NULL != path
 */
RECLS_API Recls_CreateDirectory(
    /* [in] */ recls_char_t const*          path
,   /* [out] */ recls_directoryResults_t*   results /* = NULL */
);

/** Removes a directory, including any sub-directories
 *
 * \ingroup group__recls
 *
 * \param path The path to remove. If not absolute, is assumed relative to
 *   the current directory
 * \param flags A combination of zero or more flags from
 *   the \c recls::RECLS_REMDIR_FLAG enumeration
 * \param results Pointer to an instance of \c recls_directoryResults_t in
 *   which information regarding the changes effected by the operation will
 *   be recorded. May be \c NULL
 *
 * \pre NULL != path
 */
RECLS_API Recls_RemoveDirectory(
    /* [in] */ recls_char_t const*          path
,   /* [in] */ int                          flags   /* = 0 */
,   /* [out] */ recls_directoryResults_t*   results /* = NULL */
);

/** @} */


/* /////////////////////////////////////////////////////////////////////////
 * shims
 */

#if !defined(RECLS_NO_NAMESPACE)
} /* namespace recls */
#endif /* !RECLS_NO_NAMESPACE */

#ifdef __cplusplus

# ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
# endif /* !_STLSOFT_NO_NAMESPACE */

 /* recls_root_t */

inline RECLS_QUAL(recls_char_t) const* c_str_ptr(RECLS_QUAL(recls_root_t) const &root)
{
    return root.name;
}

#ifdef RECLS_CHAR_TYPE_IS_CHAR
inline RECLS_QUAL(recls_char_t) const* c_str_ptr_a(RECLS_QUAL(recls_root_t) const &root)
{
    return c_str_ptr(root);
}
#endif /* RECLS_CHAR_TYPE_IS_CHAR */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
inline RECLS_QUAL(recls_char_t) const* c_str_ptr_w(RECLS_QUAL(recls_root_t) const &root)
{
    return c_str_ptr(root);
}
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */



 /* recls_rc_t */

inline RECLS_QUAL(recls_char_t) const* c_str_ptr(RECLS_QUAL(recls_rc_t) rc)
{
    return RECLS_QUAL(Recls_GetSearchCodeString)(rc);
}
#ifdef RECLS_CHAR_TYPE_IS_CHAR
inline RECLS_QUAL(recls_char_t) const* c_str_ptr_a(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_ptr(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_CHAR */
#ifdef RECLS_CHAR_TYPE_IS_WCHAR
inline RECLS_QUAL(recls_char_t) const* c_str_ptr_w(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_ptr(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

# if defined(RECLS_NO_NAMESPACE)
inline recls_char_t const* c_str_data(recls_rc_t rc)
# else /* ? RECLS_NO_NAMESPACE */
inline RECLS_QUAL(recls_char_t) const* c_str_data(RECLS_QUAL(recls_rc_t) rc)
# endif /* RECLS_NO_NAMESPACE */
{
    return RECLS_QUAL(Recls_GetSearchCodeString)(rc);
}
#ifdef RECLS_CHAR_TYPE_IS_CHAR
inline RECLS_QUAL(recls_char_t) const* c_str_data_a(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_data(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_CHAR */
#ifdef RECLS_CHAR_TYPE_IS_WCHAR
inline RECLS_QUAL(recls_char_t) const* c_str_data_w(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_data(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

inline size_t c_str_len(RECLS_QUAL(recls_rc_t) rc)
{
    return RECLS_QUAL(Recls_GetSearchCodeStringLength)(rc);
}
#ifdef RECLS_CHAR_TYPE_IS_CHAR
inline size_t c_str_len_a(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_len(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_CHAR */
#ifdef RECLS_CHAR_TYPE_IS_WCHAR
inline size_t c_str_len_w(RECLS_QUAL(recls_rc_t) rc)
{
    return c_str_len(rc);
}
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */


# ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
# endif /* !_STLSOFT_NO_NAMESPACE */

#endif /* __cplusplus */


/* /////////////////////////////////////////////////////////////////////////
 * Platform-specific includes
 */

/** \def RECLS_PLATFORM_API_WIN32
 *
 * Defined if Windows platform-specific extensions are in use.
 */

/** \def RECLS_PLATFORM_API_WIN64
 *
 * Defined if Win64 platform-specific extensions are in use.
 */

/** \def RECLS_PLATFORM_API_WINDOWS
 *
 * Defined if Windows platform-specific extensions are in use.
 */

/** \def RECLS_PLATFORM_API_UNIX
 *
 * Defined if UNIX platform-specific extensions are in use.
 */

#ifdef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_PLATFORM_API_WIN32
# define RECLS_PLATFORM_API_WIN64
# define RECLS_PLATFORM_API_WINDOWS
# define RECLS_PLATFORM_API_UNIX
#endif /* RECLS_DOCUMENTATION_SKIP_SECTION */


#ifdef RECLS_PLATFORM_API_WIN32
# undef RECLS_PLATFORM_API_WIN32
#endif /* RECLS_PLATFORM_API_WIN32 */

#ifdef RECLS_PLATFORM_API_UNIX
# undef RECLS_PLATFORM_API_UNIX
#endif /* RECLS_PLATFORM_API_UNIX */

#if !defined(RECLS_PURE_API)
# if defined(RECLS_PLATFORM_IS_WINDOWS)
#  include <recls/windows.h>
#  define RECLS_PLATFORM_API_WINDOWS
#  ifdef RECLS_PLATFORM_IS_WIN32
#   define RECLS_PLATFORM_API_WIN32
#  endif /* RECLS_PLATFORM_IS_WIN32 */
#  ifdef RECLS_PLATFORM_IS_WIN64
#   define RECLS_PLATFORM_API_WIN64
#  endif /* RECLS_PLATFORM_IS_WIN64 */
# elif defined(RECLS_PLATFORM_IS_UNIX)
#  include <recls/unix.h>
#  define RECLS_PLATFORM_API_UNIX
# else
#  error Platform not recognised
# endif /* platform */
#endif /* !RECLS_PURE_API */


/* /////////////////////////////////////////////////////////////////////////
 * documentation
 */

#ifdef RECLS_DOCUMENTATION_SKIP_SECTION
# include <recls/internal/doc/includes.h>
#endif /* RECLS_DOCUMENTATION_SKIP_SECTION */


/* /////////////////////////////////////////////////////////////////////////
 * inclusion control
 */

#ifdef RECLS_CF_PRAGMA_ONCE_SUPPORT
# pragma once
#endif /* RECLS_CF_PRAGMA_ONCE_SUPPORT */

#endif /* !RECLS_INCL_RECLS_H_RECLS */

/* ///////////////////////////// end of file //////////////////////////// */

