/* /////////////////////////////////////////////////////////////////////////
 * File:        recls/implicit_link.h
 *
 * Purpose:     Implicit linking for the recls API
 *
 * Created:     20th September 2005
 * Updated:     22nd December 2020
 *
 * Home:        http://fastformat.org/
 *
 * Copyright (c) 2019-2020, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file recls/implicit_link.h
 *
 * \brief [C, C++] Implicit linking for the recls API.
 */

#ifndef RECLS_INCL_RECLS_H_IMPLICIT_LINK
#define RECLS_INCL_RECLS_H_IMPLICIT_LINK

/* /////////////////////////////////////////////////////////////////////////
 * version information
 */

#ifndef RECLS_DOCUMENTATION_SKIP_SECTION
# define RECLS_VER_RECLS_H_IMPLICIT_LINK_MAJOR      1
# define RECLS_VER_RECLS_H_IMPLICIT_LINK_MINOR      5
# define RECLS_VER_RECLS_H_IMPLICIT_LINK_REVISION   1
# define RECLS_VER_RECLS_H_IMPLICIT_LINK_EDIT       16
#endif /* !RECLS_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

#ifndef RECLS_INCL_RECLS_H_RECLS
# include <recls/recls.h>
#endif /* !RECLS_INCL_RECLS_H_RECLS */

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#define RECLS_STRINGIZE_(x) #x
#define RECLS_STRINGIZE(x)  RECLS_STRINGIZE_(x)

/* /////////////////////////////////////////////////////////////////////////
 * implicit linking
 */

#if defined(_WIN32) || \
    defined(_WIN64)

# if defined(__BORLANDC__) || \
     /* defined(__DMC__) || */ \
     defined(__INTEL_COMPILER) || \
     defined(__MWERKS__) || \
     defined(_MSC_VER)
#  if !defined(__COMO__)
#   define RECLS_IMPLICIT_LINK_SUPPORT
#  endif /* compiler */
# endif /* compiler */

# if defined(RECLS_IMPLICIT_LINK_SUPPORT) && \
     defined(RECLS_NO_IMPLICIT_LINK)
#  undef RECLS_IMPLICIT_LINK_SUPPORT
# endif /* RECLS_IMPLICIT_LINK_SUPPORT && RECLS_NO_IMPLICIT_LINK */

# if defined(RECLS_IMPLICIT_LINK_SUPPORT)

  /* prefix */

#  define RECLS_IMPL_LINK_PREFIX

  /* library basename */

#  define RECLS_IMPL_LINK_LIBRARY_BASENAME          "recls"

  /* major version */

#  define RECLS_IMPL_LINK_MAJOR_VERSION             "." RECLS_STRINGIZE(RECLS_VER_MAJOR)

  /* module name */

#  define RECLS_IMPL_LINK_MODULE_NAME               ""

  /* compiler tag */

#  if defined(__BORLANDC__)
#   if 0
#   elif __BORLANDC__ == 0x0550
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc55"
#   elif (__BORLANDC__ == 0x0551)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc551"
#   elif (__BORLANDC__ == 0x0560)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc56"
#   elif (__BORLANDC__ == 0x0564)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc564"
#   elif (__BORLANDC__ == 0x0582)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc582"
#   elif (0x0590 == (__BORLANDC__ & 0xfff0))
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc59x"
#   elif (0x0610 == (__BORLANDC__ & 0xfff0))
#    define RECLS_IMPL_LINK_COMPILER_NAME           "bc61x"
#   else /* ? __BORLANDC__ */
#    error Unrecognised value of __BORLANDC__
#   endif /* __BORLANDC__ */

/*
#  elif defined(__DMC__)
#   define RECLS_IMPL_LINK_COMPILER_NAME            "dm"
 */

#  elif defined(__INTEL_COMPILER)
#   if 0
#   elif __INTEL_COMPILER == 600
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl6"
#   elif __INTEL_COMPILER == 700
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl7"
#   elif __INTEL_COMPILER == 800
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl8"
#   elif __INTEL_COMPILER == 900
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl9"
#   elif __INTEL_COMPILER == 1000
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl10"
#   elif __INTEL_COMPILER == 1100
#    define   RECLS_IMPL_LINK_COMPILER_NAME         "icl11"
#   else /* ? __INTEL_COMPILER */
#    error Intel C/C++ version not supported
#   endif /* __INTEL_COMPILER */

#  elif defined(__MWERKS__)
#   if 0
#   elif ((__MWERKS__ & 0xFF00) == 0x2400)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "cw7"
#   elif ((__MWERKS__ & 0xFF00) == 0x3000)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "cw8"
#   elif ((__MWERKS__ & 0xFF00) == 0x3200)
#    define RECLS_IMPL_LINK_COMPILER_NAME           "cw9"
#   else /* ? __MWERKS__ */
#    error CodeWarrior version not supported
#   endif /* __MWERKS__ */

#  elif defined(_MSC_VER)
#   if 0
#   elif _MSC_VER < 1500
#    error recls 1.10 is not supported for Visual C++ compilers prior to version 9 (Visual Studio 2008)
#   elif _MSC_VER == 1500
#    define RECLS_IMPL_LINK_COMPILER_NAME           "vc9"
#   elif _MSC_VER == 1600
#    define RECLS_IMPL_LINK_COMPILER_NAME           "vc10"
#   elif _MSC_VER == 1700
#    define RECLS_IMPL_LINK_COMPILER_NAME           "vc11"
#   elif _MSC_VER == 1800
#    define RECLS_IMPL_LINK_COMPILER_NAME           "vc12"
#   elif _MSC_VER == 1900
#    define RECLS_IMPL_LINK_COMPILER_NAME           "vc14"
#   else /* ? _MSC_VER */
#    error Visual C++ version not supported
#   endif /* _MSC_VER */

#  else /* ? compiler */
#   error Unrecognised compiler
#  endif /* compiler */


  /* operating system tag */

#  if defined(_STLSOFT_FORCE_ANY_COMPILER) && \
      defined(RECLS_PLATFORM_IS_UNIX) && \
      defined(_WIN32)
#   define RECLS_IMPL_LINK_OS_TAG                   ".unix"
#  endif /* pseudo UNIX */

#  if !defined(RECLS_IMPL_LINK_OS_TAG)
#   define RECLS_IMPL_LINK_OS_TAG                   ""
#  endif /* !RECLS_IMPL_LINK_OS_TAG */


  /* architecture tag */

#  if defined(RECLS_ARCH_IS_X86)
#   define RECLS_IMPL_LINK_ARCH_TAG                 ""
#  elif defined(RECLS_ARCH_IS_X64)
#   define RECLS_IMPL_LINK_ARCH_TAG                 ".x64"
#  elif defined(RECLS_ARCH_IS_IA64)
#   define RECLS_IMPL_LINK_ARCH_TAG                 ".ia64"
#  endif /* arch */

#  if !defined(RECLS_IMPL_LINK_ARCH_TAG)
#   define RECLS_IMPL_LINK_ARCH_TAG                 ""
#  endif /* !RECLS_IMPL_LINK_ARCH_TAG */


  /* encoding tag */

#  if defined(RECLS_CHAR_TYPE_IS_WCHAR)
#   define RECLS_IMPL_LINK_ENCODING_TAG             ".widestring"
#  else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
#   define RECLS_IMPL_LINK_ENCODING_TAG             ""
#  endif /* RECLS_CHAR_TYPE_IS_WCHAR */


  /* threading tag */

#  if defined(__MT__) || \
      defined(_REENTRANT) || \
      defined(_MT)
#   if 0
#   elif defined(_DLL) || \
       defined(__DLL)
#    define RECLS_IMPL_LINK_THREADING_TAG           ".dll"
#   else /* ? dll */
#    define RECLS_IMPL_LINK_THREADING_TAG           ".mt"
#   endif /* dll */
#  else /* ? mt */
#    define RECLS_IMPL_LINK_THREADING_TAG           ""
#  endif /* mt */


  /* debug tag */

#  if !defined(NDEBUG) && \
      defined(_DEBUG)
#   define RECLS_IMPL_LINK_DEBUG_TAG                ".debug"
#  else /* ? debug */
#   define RECLS_IMPL_LINK_DEBUG_TAG                ""
#  endif /* debug */


  /* suffix */

#  define RECLS_IMPL_LINK_SUFFIX                    ".lib"


   /* Library name is:
    *
    * [lib]<library-basename>.<major-version>.<module-name>.<compiler-name>[.<os-arch-tag>][.<char-encoding-tag>][.<threading-tag>][.<nox-tag>][.<debug-tag>].{a|lib}
    */

#  define RECLS_IMPL_LINK_LIBRARY_NAME              RECLS_IMPL_LINK_PREFIX \
                                                        RECLS_IMPL_LINK_LIBRARY_BASENAME \
                                                        RECLS_IMPL_LINK_MAJOR_VERSION \
                                                        RECLS_IMPL_LINK_MODULE_NAME \
                                                        "." RECLS_IMPL_LINK_COMPILER_NAME \
                                                        RECLS_IMPL_LINK_OS_TAG \
                                                        RECLS_IMPL_LINK_ARCH_TAG \
                                                        RECLS_IMPL_LINK_ENCODING_TAG \
                                                        RECLS_IMPL_LINK_THREADING_TAG \
                                                        RECLS_IMPL_LINK_DEBUG_TAG \
                                                        RECLS_IMPL_LINK_SUFFIX


#  pragma message("lib: " RECLS_IMPL_LINK_LIBRARY_NAME)

#  pragma comment(lib, RECLS_IMPL_LINK_LIBRARY_NAME)

# endif /* RECLS_IMPLICIT_LINK_SUPPORT */

#endif /* Win-32 || Win-64 */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !RECLS_INCL_RECLS_H_IMPLICIT_LINK */

/* ///////////////////////////// end of file //////////////////////////// */

