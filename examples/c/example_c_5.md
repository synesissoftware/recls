# recls Example - **example_c_5**

## Summary

T.B.C.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_5/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - stat() of home directory (via Recls_Stat())
 *            - en-bloc processing, via Recls_SearchProcess(), of all
 *              files and directories under the home directory
 *            - recursive operation
 *            - display of path relative to home directory
 *              (via Recls_DeriveRelativePath())
 *            - elicitation of entry properties via structure members
 *            - handling of errors and reporting of error information
 *
 * Created: 17th June 2006
 * Updated: 10th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Standard C Library Files */
#include <stdio.h>      /* for printf() / fprintf()         */
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define printf                                             wprintf
# define fprintf                                            fwprintf
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int RECLS_CALLCONV_DEFAULT example_c_5_process_fn(   recls_info_t                entry
                                                        ,   recls_process_fn_param_t    param)
{
    recls_char_t        relativePath[1001];
    recls_char_t const  *homePath   =   (recls_char_t const*)param;
    size_t              cch         =   Recls_DeriveRelativePath(homePath, entry->path.begin, &relativePath[0], RECLS_NUM_ELEMENTS(relativePath));

    printf(RECLS_LITERAL("%.*s\n"), (int)cch, relativePath);

    return 1; /* Continue processing. */
}

int main(int argc, char* argv[])
{
    /* First, determine the home directory by stat()-ing ~ */
    recls_info_t    home;
    recls_rc_t      rc  =   Recls_Stat(RECLS_LITERAL("~"), RECLS_F_DIRECTORIES, &home);

    ((void)&argc);
    ((void)&argv);

    if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("stat of home directory failed: %s\n"), err);

        return EXIT_FAILURE;
    }
    else
    {
        recls_uint32_t  flags   =   RECLS_F_FILES | RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;

        /* Process all entries under the current directory, passing the home
         * entry's path pointer. This is valid since the path is always
         * nul-terminated.
         */

        rc = Recls_SearchProcess(NULL, Recls_GetWildcardsAll(), flags, example_c_5_process_fn, (void*)home->path.begin);

        /* Close the home entry. */

        Recls_CloseDetails(home);

        if (RECLS_FAILED(rc))
        {
            /* The search failed. Display the error string. */
            recls_char_t    err[1001];
            size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

            err[n] = '\0';

            fprintf(stderr, RECLS_LITERAL("processing failed: %s\n"), err);

            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

T.B.C.


## Example results

```
dev/synesissoftware/freelibs/recls/recls/AUTHORS.md
dev/synesissoftware/freelibs/recls/recls/CHANGES.txt
dev/synesissoftware/freelibs/recls/recls/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/EXAMPLES.md
dev/synesissoftware/freelibs/recls/recls/FAQ.md
dev/synesissoftware/freelibs/recls/recls/HISTORY.md
dev/synesissoftware/freelibs/recls/recls/INSTALL.md
dev/synesissoftware/freelibs/recls/recls/LICENSE
dev/synesissoftware/freelibs/recls/recls/NEWS.md
dev/synesissoftware/freelibs/recls/recls/README.md
dev/synesissoftware/freelibs/recls/recls/TODO.md
dev/synesissoftware/freelibs/recls/recls/bin
dev/synesissoftware/freelibs/recls/recls/build
dev/synesissoftware/freelibs/recls/recls/build_cmake.sh
dev/synesissoftware/freelibs/recls/recls/clean_cmake.sh
dev/synesissoftware/freelibs/recls/recls/cmake
dev/synesissoftware/freelibs/recls/recls/examples
dev/synesissoftware/freelibs/recls/recls/include
dev/synesissoftware/freelibs/recls/recls/lib
dev/synesissoftware/freelibs/recls/recls/prepare_cmake.sh
dev/synesissoftware/freelibs/recls/recls/projects
dev/synesissoftware/freelibs/recls/recls/recls.vc10.sln
dev/synesissoftware/freelibs/recls/recls/remove_cmake_artefacts.sh
dev/synesissoftware/freelibs/recls/recls/run_all_examples.sh
dev/synesissoftware/freelibs/recls/recls/run_all_scratch_tests.sh
dev/synesissoftware/freelibs/recls/recls/run_all_unit_tests.sh
dev/synesissoftware/freelibs/recls/recls/src
dev/synesissoftware/freelibs/recls/recls/test
dev/synesissoftware/freelibs/recls/recls/test/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/component
dev/synesissoftware/freelibs/recls/recls/test/scratch
dev/synesissoftware/freelibs/recls/recls/test/unit
dev/synesissoftware/freelibs/recls/recls/test/unit/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/implicit_link.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/vc10/test.unit.api.squeeze_path.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/vc10/test.unit.api.squeeze_path.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/vc10/test.unit.cpp.retcodes.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/vc10/test.unit.cpp.retcodes.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/implicit_link.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/test.unit.c.retcodes.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/vc10/test.unit.c.retcodes.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/vc10/test.unit.c.retcodes.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/vc10/test.unit.cpp.squeeze_path.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/vc10/test.unit.cpp.squeeze_path.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/vc10/test.unit.cpp.combine_paths.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/vc10/test.unit.cpp.combine_paths.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/implicit_link.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/test.unit.api.stat.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/vc10/test.unit.api.stat.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/vc10/test.unit.api.stat.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/vc10/test.unit.cpp.derive_relative_path.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/vc10/test.unit.cpp.derive_relative_path.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/implicit_link.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/test.unit.api.combine_paths.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/vc10/test.unit.api.combine_paths.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/vc10/test.unit.api.combine_paths.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/implicit_link.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/test.unit.api.create_directory.c
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/vc10
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/vc10/test.unit.api.createdirectory.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/vc10/test.unit.api.createdirectory.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/component/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/entry.cpp
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/vc10
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/vc10/test.component.util.cpp.create_directory.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/vc10/test.component.util.cpp.create_directory.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/vc10
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/vc10/test.component.util.cpp.remove_directory.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/vc10/test.component.util.cpp.remove_directory.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/scratch/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios
dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/test.scratch.with_pantheios.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/test.scratch.cpp_api.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/vc10
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/vc10/test.scratch.cpp_api.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/vc10/test.scratch.cpp_api.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/test.scratch.search.1.c
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/vc10
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/vc10/test.scratch.search.1.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/vc10/test.scratch.search.1.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/test_c_1.c
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/implicit_link.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/test.scratch.links.cpp
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/vc10
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/vc10/test.scratch.links.vcxproj
dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/vc10/test.scratch.links.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/cmake/BuildType.cmake
dev/synesissoftware/freelibs/recls/recls/cmake/LanguageFullVersion.cmake
dev/synesissoftware/freelibs/recls/recls/cmake/TargetMacros.cmake
dev/synesissoftware/freelibs/recls/recls/cmake/recls-config.cmake.in
dev/synesissoftware/freelibs/recls/recls/.vscode-2/settings.json
dev/synesissoftware/freelibs/recls/recls/include/recls
dev/synesissoftware/freelibs/recls/recls/include/recls/assert.h
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp
dev/synesissoftware/freelibs/recls/recls/include/recls/ftp.h
dev/synesissoftware/freelibs/recls/recls/include/recls/fwd.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/implicit_link.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal
dev/synesissoftware/freelibs/recls/recls/include/recls/recls.h
dev/synesissoftware/freelibs/recls/recls/include/recls/recls.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/unix.h
dev/synesissoftware/freelibs/recls/recls/include/recls/windows.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_borland.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_ch.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_clang.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_como.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_dmc.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_gcc.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_intel.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_msvc.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_mwerks.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_vectorc.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_watcom.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/language.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/platform.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/platform_types.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/recls_filesize.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/recls_time.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/retcodes.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/safestr.h
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/warning
dev/synesissoftware/freelibs/recls/recls/include/recls/internal/warning/msvc.suppress.4530.h
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/classfwd.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/common.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/directory_parts.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/entry.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/exceptions.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/ftp_search_sequence.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/internal
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/root_sequence.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/search_sequence.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/traits.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/unix.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/util.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/windows.hpp
dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/internal/sequence_helper.hpp
dev/synesissoftware/freelibs/recls/recls/projects/core
dev/synesissoftware/freelibs/recls/recls/projects/vcprops
dev/synesissoftware/freelibs/recls/recls/projects/core/_dev_pragmatics_
dev/synesissoftware/freelibs/recls/recls/projects/core/pch.cpp
dev/synesissoftware/freelibs/recls/recls/projects/core/pch.hpp
dev/synesissoftware/freelibs/recls/recls/projects/core/vc10
dev/synesissoftware/freelibs/recls/recls/projects/core/vc10/recls.core.vcxproj
dev/synesissoftware/freelibs/recls/recls/projects/core/vc10/recls.core.vcxproj.filters
dev/synesissoftware/freelibs/recls/recls/projects/core/_dev_pragmatics_/warnings.msvc.10+.h
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.common.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.example.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.no-PCH.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.Catch.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.common.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.component.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.scratch.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.unit.props
dev/synesissoftware/freelibs/recls/recls/projects/vcprops/recls.test.xTests.props
dev/synesissoftware/freelibs/recls/recls/examples/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c
dev/synesissoftware/freelibs/recls/recls/examples/cpp
dev/synesissoftware/freelibs/recls/recls/examples/cpp/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_1
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_1.md
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_2
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_2.md
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_3
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_3.md
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_1/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_1/main.cpp
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_3/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_3/main.cpp
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_2/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_2/main.cpp
dev/synesissoftware/freelibs/recls/recls/examples/c/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_1
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_1.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_2
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_2.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_3
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_3.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_4
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_4.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_5
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_5.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_6
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_6.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_7
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_7.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_8
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_8.md
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_3/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_3/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_4/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_4/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_5/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_5/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_2/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_2/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_7/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_7/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_8/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_8/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_1/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_1/main.c
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_6/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_6/main.c
dev/synesissoftware/freelibs/recls/recls/build/clang130.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc34.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc34.win32
dev/synesissoftware/freelibs/recls/recls/build/gcc40.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc41.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc42.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc43.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc44.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc45.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc46.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc47.mingw
dev/synesissoftware/freelibs/recls/recls/build/gcc47.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc47.win32
dev/synesissoftware/freelibs/recls/recls/build/gcc81.mingw
dev/synesissoftware/freelibs/recls/recls/build/gcc81.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc81.win32
dev/synesissoftware/freelibs/recls/recls/build/gcc92.mingw
dev/synesissoftware/freelibs/recls/recls/build/gcc92.unix
dev/synesissoftware/freelibs/recls/recls/build/gcc92.win32
dev/synesissoftware/freelibs/recls/recls/build/gcc93.unix
dev/synesissoftware/freelibs/recls/recls/build/vc10
dev/synesissoftware/freelibs/recls/recls/build/vc10.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc10.x64
dev/synesissoftware/freelibs/recls/recls/build/vc11
dev/synesissoftware/freelibs/recls/recls/build/vc11.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc11.x64
dev/synesissoftware/freelibs/recls/recls/build/vc12
dev/synesissoftware/freelibs/recls/recls/build/vc12.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc12.x64
dev/synesissoftware/freelibs/recls/recls/build/vc14
dev/synesissoftware/freelibs/recls/recls/build/vc14.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc14.x64
dev/synesissoftware/freelibs/recls/recls/build/vc15
dev/synesissoftware/freelibs/recls/recls/build/vc15.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc15.x64
dev/synesissoftware/freelibs/recls/recls/build/vc16
dev/synesissoftware/freelibs/recls/recls/build/vc16.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc16.x64
dev/synesissoftware/freelibs/recls/recls/build/vc9.unixem
dev/synesissoftware/freelibs/recls/recls/build/vc9.x64
dev/synesissoftware/freelibs/recls/recls/build/gcc45.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc14/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc47.mingw/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc12/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc14.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc15/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc16.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc81.mingw/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc44.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc12.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc34.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc47.win32/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc43.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc81.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc42.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc81.win32/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc10.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc9.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc10/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc11.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc15.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc10.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc12.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc16/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc11/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc41.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc40.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/clang130.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc16.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc14.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc15.x64/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc9.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc92.win32/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc92.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc34.win32/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc47.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc92.mingw/makefile
dev/synesissoftware/freelibs/recls/recls/build/vc11.unixem/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc46.unix/makefile
dev/synesissoftware/freelibs/recls/recls/build/gcc93.unix/makefile
dev/synesissoftware/freelibs/recls/recls/.vscode/settings.json
dev/synesissoftware/freelibs/recls/recls/src/CMakeLists.txt
dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearch.cpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearch.hpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearchDirectoryNode.cpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearchDirectoryNode.hpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearch.hpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearchDirectoryNode_windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearchDirectoryNode_windows.hpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearch_windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsSearch.cpp
dev/synesissoftware/freelibs/recls/recls/src/ReclsSearch.hpp
dev/synesissoftware/freelibs/recls/recls/src/api.entryinfo.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.error.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.extended.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.ftp.windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.retcodes.windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.search.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.unix.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.combine_paths.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.create_directory.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.derive_relative_path.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.get_file_sizes.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.remove_directory.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.squeeze_path.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.util.stat.cpp
dev/synesissoftware/freelibs/recls/recls/src/api.windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.api.search.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.api.search.h
dev/synesissoftware/freelibs/recls/recls/src/impl.atomic.h
dev/synesissoftware/freelibs/recls/recls/src/impl.constants.hpp
dev/synesissoftware/freelibs/recls/recls/src/impl.entryfunctions.h
dev/synesissoftware/freelibs/recls/recls/src/impl.entryinfo.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.entryinfo.hpp
dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.unix.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.root.h
dev/synesissoftware/freelibs/recls/recls/src/impl.snprintf.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.string.hpp
dev/synesissoftware/freelibs/recls/recls/src/impl.trace.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.trace.h
dev/synesissoftware/freelibs/recls/recls/src/impl.types.ftp.hpp
dev/synesissoftware/freelibs/recls/recls/src/impl.types.hpp
dev/synesissoftware/freelibs/recls/recls/src/impl.util.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.util.h
dev/synesissoftware/freelibs/recls/recls/src/impl.util.unix.cpp
dev/synesissoftware/freelibs/recls/recls/src/impl.util.windows.cpp
dev/synesissoftware/freelibs/recls/recls/src/incl.inetstl.h
dev/synesissoftware/freelibs/recls/recls/src/incl.platformstl.h
dev/synesissoftware/freelibs/recls/recls/src/incl.stlsoft.h
dev/synesissoftware/freelibs/recls/recls/src/incl.unixstl.h
dev/synesissoftware/freelibs/recls/recls/src/incl.winstl.h
```


<!-- ########################### end of file ########################### -->

