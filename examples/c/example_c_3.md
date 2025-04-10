# recls Example - **example_c_3**

## Summary

T.B.C.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_3/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - stat() of current directory (via Recls_Stat())
 *            - searching (via Recls_Search()) for files and directories
 *            - recursive operation
 *            - display of full path of each entry, squeezed to constant
 *              width (via Recls_SqueezePath())
 *            - display of file size for file entries
 *            - display of directory contents size for directory
 *              entries, (determined via Recls_CalcDirectoryEntrySize())
 *            - handling of errors and reporting of error information
 *            - elicitation of entry properties via API function calls
 *
 * Created: 29th May 2006
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
 * constants
 */

#define CCH_SQUEEZED_PATH                                   (64)


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    /* stat() the current directory */
    recls_info_t    current;
    recls_rc_t      rc  =   Recls_Stat(RECLS_LITERAL("."), RECLS_F_DIRECTORIES | RECLS_F_DIRECTORY_PARTS, &current);

    ((void)&argc);
    ((void)&argv);

    if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("stat of current directory failed: %s\n"), err);

        return EXIT_FAILURE;
    }
    else
    {
        hrecls_t        hSrch;
        recls_uint32_t  flags   =   RECLS_F_FILES | RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;

        rc = Recls_Search(current->path.begin, NULL, flags, &hSrch);

        /* ... close the entry handle, ... */
        Recls_CloseDetails(current);

        if (RECLS_RC_NO_MORE_DATA == rc)
        {
            printf(RECLS_LITERAL("  no matches found\n"));

            return EXIT_SUCCESS;
        }
        else if (RECLS_FAILED(rc))
        {
            /* The search failed. Display the error string. */
            recls_char_t    err[1001];
            size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

            err[n] = '\0';

            fprintf(stderr, RECLS_LITERAL("Search failed: %s\n"), err);

            return EXIT_FAILURE;
        }
        else
        {
            /* Get the details for the first entry, ... */

            recls_info_t    entry;

            Recls_GetDetails(hSrch, &entry);

            do
            {
                /* ... get the full path, ... */
                recls_filesize_t    size;
                recls_bool_t        isDirectory;
                recls_char_t        path[1001];
                recls_char_t        squeezedPath[CCH_SQUEEZED_PATH];
                size_t              cch = Recls_GetPathProperty(entry, &path[0], RECLS_NUM_ELEMENTS(path) - 1);;

                path[cch] = '\0';

                /* ... squeeze it into CCH_SQUEEZED_PATH characters, ... */
                cch = Recls_SqueezePath(path, &squeezedPath[0], RECLS_NUM_ELEMENTS(squeezedPath));

                /* ... determine type, ... */
                isDirectory = Recls_IsEntryDirectory(entry);

                if (isDirectory)
                {
                    /* ... calculate size, or ... */
                    size = Recls_CalcDirectoryEntrySize(entry);
                }
                else
                {
                    /* ... elicit size, ... */

                    size = Recls_GetSizeProperty(entry);
                }

                if (0 != Recls_GetFileSizeGigaBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu MB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeMegaBytes(size)
                        );
                }
                else if (0 != Recls_GetFileSizeMegaBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu MB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeMegaBytes(size)
                        );
                }
                else if (0 != Recls_GetFileSizeKiloBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu KB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeKiloBytes(size)
                        );
                }
                else
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu bytes\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)size
                        );
                }

                /* ... close the entry handle, ... */
                Recls_CloseDetails(entry);

            } /* ... and get the next entry. */
            while (RECLS_SUCCEEDED(Recls_GetNextDetails(hSrch, &entry)));

            /* Close the search handle. */
            Recls_SearchClose(hSrch);

            return EXIT_SUCCESS;
        }
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

T.B.C.


## Example results

```
/Users/user/dev/synesissoftware/freelibs/recls/recls/AUTHORS.md: file; 319 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/CHANGES.txt: file; 77 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 8 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/EXAMPLES.md: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/FAQ.md: file; 6 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/HISTORY.md: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/INSTALL.md: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/LICENSE: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/NEWS.md: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/README.md: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/TODO.md: file; 124 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/bin: directory; 0 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/build: directory; 7 MB
/Users/user/dev/synesissoftware/freelibs/recls.../build_cmake.sh: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../clean_cmake.sh: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/cmake: directory; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples: directory; 226 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/include: directory; 326 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/lib: directory; 0 bytes
/Users/user/dev/synesissoftware/freelibs/rec.../prepare_cmake.sh: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/projects: directory; 54 KB
/Users/user/dev/synesissoftware/freelibs/recls.../recls.vc10.sln: file; 65 KB
/Users/user/dev/synesissoftware/fre.../remove_cmake_artefacts.sh: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/.../run_all_examples.sh: file; 2 KB
/Users/user/dev/synesissoftware/free.../run_all_scratch_tests.sh: file; 2 KB
/Users/user/dev/synesissoftware/freelib.../run_all_unit_tests.sh: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/src: directory; 333 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/test: directory; 287 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 646 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recl.../component: directory; 34 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../scratch: directory; 69 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit: directory; 183 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 403 bytes
/Users/user/dev/synesissoftware/f.../test.unit.api.combine_paths: directory; 13 KB
/Users/user/dev/synesissoftwar.../test.unit.api.create_directory: directory; 18 KB
/Users/user/dev/synesissoftware/fr.../test.unit.api.squeeze_path: directory; 15 KB
/Users/user/dev/synesissoftware/freelibs/r.../test.unit.api.stat: directory; 28 KB
/Users/user/dev/synesissoftware/freelibs.../test.unit.c.retcodes: directory; 12 KB
/Users/user/dev/synesissoftware/f.../test.unit.cpp.combine_paths: directory; 20 KB
/Users/user/dev/synesissof.../test.unit.cpp.derive_relative_path: directory; 33 KB
/Users/user/dev/synesissoftware/freeli.../test.unit.cpp.retcodes: directory; 13 KB
/Users/user/dev/synesissoftware/fr.../test.unit.cpp.squeeze_path: directory; 26 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 182 bytes
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.c: file; 375 bytes
/Users/user/dev/synesissoftware/.../test.unit.api.squeeze_path.c: file; 6 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesissof.../test.unit.api.squeeze_path.vcxproj: file; 6 KB
/Users/user/dev/sy.../test.unit.api.squeeze_path.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 176 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 375 bytes
/Users/user/dev/synesissoftware/fr.../test.unit.cpp.retcodes.cpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesissoftwar.../test.unit.cpp.retcodes.vcxproj: file; 6 KB
/Users/user/dev/synesi.../test.unit.cpp.retcodes.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 170 bytes
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.c: file; 375 bytes
/Users/user/dev/synesissoftware/freeli.../test.unit.c.retcodes.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesissoftware/.../test.unit.c.retcodes.vcxproj: file; 6 KB
/Users/user/dev/synesiss.../test.unit.c.retcodes.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 184 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 375 bytes
/Users/user/dev/synesissoftwar.../test.unit.cpp.squeeze_path.cpp: file; 17 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesissof.../test.unit.cpp.squeeze_path.vcxproj: file; 6 KB
/Users/user/dev/sy.../test.unit.cpp.squeeze_path.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 186 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 377 bytes
/Users/user/dev/synesissoftwa.../test.unit.cpp.combine_paths.cpp: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesisso.../test.unit.cpp.combine_paths.vcxproj: file; 6 KB
/Users/user/dev/s.../test.unit.cpp.combine_paths.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 166 bytes
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.c: file; 377 bytes
/Users/user/dev/synesissoftware/freelibs.../test.unit.api.stat.c: file; 19 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesissoftware/fr.../test.unit.api.stat.vcxproj: file; 6 KB
/Users/user/dev/synesissof.../test.unit.api.stat.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 200 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 375 bytes
/Users/user/dev/synesi.../test.unit.cpp.derive_relative_path.cpp: file; 24 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/sy.../test.unit.cpp.derive_relative_path.vcxproj: file; 7 KB
/Users/use.../test.unit.cpp.derive_relative_path.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 184 bytes
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.c: file; 375 bytes
/Users/user/dev/synesissoftware.../test.unit.api.combine_paths.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesisso.../test.unit.api.combine_paths.vcxproj: file; 6 KB
/Users/user/dev/s.../test.unit.api.combine_paths.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 190 bytes
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.c: file; 377 bytes
/Users/user/dev/synesissoftw.../test.unit.api.create_directory.c: file; 9 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/dev/synesis.../test.unit.api.createdirectory.vcxproj: file; 6 KB
/Users/user/dev.../test.unit.api.createdirectory.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 296 bytes
/Users/user/dev/syne.../test.component.util.cpp.create_directory: directory; 14 KB
/Users/user/dev/synesissoft.../test.component.util.cpp.is_socket: directory; 4 KB
/Users/user/dev/syne.../test.component.util.cpp.remove_directory: directory; 15 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 169 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recl.../entry.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 211 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 375 bytes
/Users/user/dev/.../test.component.util.cpp.create_directory.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/.../test.component.util.cpp.create_directory.vcxproj: file; 7 KB
/Use.../test.component.util.cpp.create_directory.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 211 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 375 bytes
/Users/user/dev/.../test.component.util.cpp.remove_directory.cpp: file; 6 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 8 KB
/Users/user/.../test.component.util.cpp.remove_directory.vcxproj: file; 7 KB
/Use.../test.component.util.cpp.remove_directory.vcxproj.filters: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 236 bytes
/Users/user/dev/synesissoftware/freelibs.../test.scratch.cpp_api: directory; 27 KB
/Users/user/dev/synesissoftware/freelibs/r.../test.scratch.links: directory; 17 KB
/Users/user/dev/synesissoftware/freelib.../test.scratch.search.1: directory; 13 KB
/Users/user/dev/synesissoftware/f.../test.scratch.with_pantheios: directory; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../test_c_1: directory; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 302 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 1 KB
/Users/user/dev/synesissoftwa.../test.scratch.with_pantheios.cpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 165 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 328 bytes
/Users/user/dev/synesissoftware/free.../test.scratch.cpp_api.cpp: file; 14 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 12 KB
/Users/user/dev/synesissoftware/.../test.scratch.cpp_api.vcxproj: file; 8 KB
/Users/user/dev/synesiss.../test.scratch.cpp_api.vcxproj.filters: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 70 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 314 bytes
/Users/user/dev/synesissoftware/freel.../test.scratch.search.1.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 9 KB
/Users/user/dev/synesissoftware.../test.scratch.search.1.vcxproj: file; 7 KB
/Users/user/dev/synesis.../test.scratch.search.1.vcxproj.filters: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 139 bytes
/Users/user/dev/synesissoftware/freelibs/recls/rec.../test_c_1.c: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 161 bytes
/Users/user/dev/synesissoftware/freelibs/re.../implicit_link.cpp: file; 328 bytes
/Users/user/dev/synesissoftware/freeli.../test.scratch.links.cpp: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/tes.../vc10: directory; 12 KB
/Users/user/dev/synesissoftware/fr.../test.scratch.links.vcxproj: file; 8 KB
/Users/user/dev/synesissof.../test.scratch.links.vcxproj.filters: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recl.../BuildType.cmake: file; 1 KB
/Users/user/dev/synesissoftware/fre.../LanguageFullVersion.cmake: file; 867 bytes
/Users/user/dev/synesissoftware/freelibs/r.../TargetMacros.cmake: file; 1 KB
/Users/user/dev/synesissoftware/freelib.../recls-config.cmake.in: file; 81 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/in.../recls: directory; 326 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../assert.h: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/incl.../cpp: directory; 127 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/in.../ftp.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../fwd.hpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recl.../implicit_link.h: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../internal: directory; 90 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../recls.h: file; 74 KB
/Users/user/dev/synesissoftware/freelibs/recls/recl.../recls.hpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/i.../unix.h: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recl.../windows.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../compiler.h: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/r.../compiler_borland.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../compiler_ch.h: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/rec.../compiler_clang.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recl.../compiler_como.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../compiler_dmc.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../compiler_gcc.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/rec.../compiler_intel.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recl.../compiler_msvc.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/re.../compiler_mwerks.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/r.../compiler_vectorc.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/re.../compiler_watcom.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../language.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../platform.h: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/rec.../platform_types.h: file; 12 KB
/Users/user/dev/synesissoftware/freelibs/rec.../recls_filesize.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/r.../recls_time.h: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../retcodes.h: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/recls/recl.../safestr.h: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../warning: directory; 171 bytes
/Users/user/dev/synesissoftware/freelibs.../msvc.suppress.4530.h: file; 171 bytes
/Users/user/dev/synesissoftware/freelibs/recls/r.../classfwd.hpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../common.hpp: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/.../directory_parts.hpp: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recls/recl.../entry.hpp: file; 24 KB
/Users/user/dev/synesissoftware/freelibs/recls.../exceptions.hpp: file; 8 KB
/Users/user/dev/synesissoftware/freel.../ftp_search_sequence.hpp: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../internal: directory; 7 KB
/Users/user/dev/synesissoftware/freelibs/re.../root_sequence.hpp: file; 9 KB
/Users/user/dev/synesissoftware/freelibs/.../search_sequence.hpp: file; 18 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../traits.hpp: file; 12 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../unix.hpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../util.hpp: file; 9 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../windows.hpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/.../sequence_helper.hpp: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/pro.../core: directory; 31 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../vcprops: directory; 23 KB
/Users/user/dev/synesissoftware/freelibs/rec.../_dev_pragmatics_: directory; 56 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../pch.cpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../pch.hpp: file; 304 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/pro.../vc10: directory; 28 KB
/Users/user/dev/synesissoftware/freelibs/r.../recls.core.vcxproj: file; 18 KB
/Users/user/dev/synesissoftware/fr.../recls.core.vcxproj.filters: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/.../warnings.msvc.10+.h: file; 56 bytes
/Users/user/dev/synesissoftware/freelibs/r.../recls.common.props: file; 13 KB
/Users/user/dev/synesissoftware/freelibs/.../recls.example.props: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/r.../recls.no-PCH.props: file; 364 bytes
/Users/user/dev/synesissoftware/freeli.../recls.test.Catch.props: file; 1 KB
/Users/user/dev/synesissoftware/freel.../recls.test.common.props: file; 1 KB
/Users/user/dev/synesissoftware/fr.../recls.test.component.props: file; 539 bytes
/Users/user/dev/synesissoftware/free.../recls.test.scratch.props: file; 771 bytes
/Users/user/dev/synesissoftware/freelib.../recls.test.unit.props: file; 539 bytes
/Users/user/dev/synesissoftware/freel.../recls.test.xTests.props: file; 615 bytes
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 611 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c: directory; 215 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/exam.../cpp: directory; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 99 bytes
/Users/user/dev/synesissoftware/freelibs/recls/.../example_cpp_1: directory; 2 KB
/Users/user/dev/synesissoftware/freelibs/rec.../example_cpp_1.md: file; 214 bytes
/Users/user/dev/synesissoftware/freelibs/recls/.../example_cpp_2: directory; 2 KB
/Users/user/dev/synesissoftware/freelibs/rec.../example_cpp_2.md: file; 214 bytes
/Users/user/dev/synesissoftware/freelibs/recls/.../example_cpp_3: directory; 4 KB
/Users/user/dev/synesissoftware/freelibs/rec.../example_cpp_3.md: file; 214 bytes
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 142 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls.../main.cpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 142 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls.../main.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 142 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls.../main.cpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 243 bytes
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_1: directory; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_1.md: file; 21 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_2: directory; 8 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_2.md: file; 21 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_3: directory; 6 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_3.md: file; 135 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_4: directory; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_4.md: file; 210 bytes
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_5: directory; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_5.md: file; 210 bytes
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_6: directory; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_6.md: file; 210 bytes
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_7: directory; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_7.md: file; 210 bytes
/Users/user/dev/synesissoftware/freelibs/recls/re.../example_c_8: directory; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../example_c_8.md: file; 210 bytes
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 6 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 347 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 8 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 138 bytes
/Users/user/dev/synesissoftware/freelibs/recls/recls/e.../main.c: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../clang130.unix: directory; 139 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc34.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc34.win32: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc40.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc41.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc42.unix: directory; 139 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc43.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc44.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc45.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc46.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc47.mingw: directory; 157 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc47.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc47.win32: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc81.mingw: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc81.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc81.win32: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc92.mingw: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc92.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../gcc92.win32: directory; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../gcc93.unix: directory; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc10: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc10.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc10.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc11: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc11.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc11.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc12: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc12.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc12.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc14: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc14.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc14.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc15: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc15.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc15.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/build/vc16: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../vc16.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../vc16.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/rec.../vc9.unixem: directory; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls/.../vc9.x64: directory; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 157 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 139 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 139 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 335 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 156 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 84 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/recls.../makefile: file; 138 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../settings.json: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../CMakeLists.txt: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/.../ReclsFileSearch.cpp: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/.../ReclsFileSearch.hpp: file; 4 KB
/Users/user/dev/synesissoftw.../ReclsFileSearchDirectoryNode.cpp: file; 25 KB
/Users/user/dev/synesissoftw.../ReclsFileSearchDirectoryNode.hpp: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/r.../ReclsFtpSearch.hpp: file; 3 KB
/Users/user/dev/synes.../ReclsFtpSearchDirectoryNode_windows.cpp: file; 22 KB
/Users/user/dev/synes.../ReclsFtpSearchDirectoryNode_windows.hpp: file; 5 KB
/Users/user/dev/synesissoftware/fr.../ReclsFtpSearch_windows.cpp: file; 9 KB
/Users/user/dev/synesissoftware/freelibs/recl.../ReclsSearch.cpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recl.../ReclsSearch.hpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/re.../api.entryinfo.cpp: file; 11 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../api.error.cpp: file; 9 KB
/Users/user/dev/synesissoftware/freelibs/rec.../api.extended.cpp: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/.../api.ftp.windows.cpp: file; 3 KB
/Users/user/dev/synesissoftware/free.../api.retcodes.windows.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../api.search.cpp: file; 7 KB
/Users/user/dev/synesissoftware/freelibs/recls/r.../api.unix.cpp: file; 2 KB
/Users/user/dev/synesissoftware/fr.../api.util.combine_paths.cpp: file; 3 KB
/Users/user/dev/synesissoftware.../api.util.create_directory.cpp: file; 10 KB
/Users/user/dev/synesissoft.../api.util.derive_relative_path.cpp: file; 6 KB
/Users/user/dev/synesissoftware/f.../api.util.get_file_sizes.cpp: file; 1 KB
/Users/user/dev/synesissoftware.../api.util.remove_directory.cpp: file; 13 KB
/Users/user/dev/synesissoftware/fre.../api.util.squeeze_path.cpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/re.../api.util.stat.cpp: file; 5 KB
/Users/user/dev/synesissoftware/freelibs/recl.../api.windows.cpp: file; 8 KB
/Users/user/dev/synesissoftware/freelibs/.../impl.api.search.cpp: file; 20 KB
/Users/user/dev/synesissoftware/freelibs/re.../impl.api.search.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../impl.atomic.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/r.../impl.constants.hpp: file; 2 KB
/Users/user/dev/synesissoftware/freelib.../impl.entryfunctions.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/r.../impl.entryinfo.cpp: file; 24 KB
/Users/user/dev/synesissoftware/freelibs/r.../impl.entryinfo.hpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/re.../impl.fileinfo.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freeli.../impl.fileinfo.unix.cpp: file; 3 KB
/Users/user/dev/synesissoftware/fre.../impl.fileinfo.windows.cpp: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../impl.root.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/re.../impl.snprintf.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recl.../impl.string.hpp: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../impl.trace.cpp: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls/r.../impl.trace.h: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/r.../impl.types.ftp.hpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls.../impl.types.hpp: file; 4 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../impl.util.cpp: file; 10 KB
/Users/user/dev/synesissoftware/freelibs/recls/re.../impl.util.h: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/r.../impl.util.unix.cpp: file; 4 KB
/Users/user/dev/synesissoftware/freelib.../impl.util.windows.cpp: file; 3 KB
/Users/user/dev/synesissoftware/freelibs/recls.../incl.inetstl.h: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/r.../incl.platformstl.h: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls.../incl.stlsoft.h: file; 2 KB
/Users/user/dev/synesissoftware/freelibs/recls.../incl.unixstl.h: file; 1 KB
/Users/user/dev/synesissoftware/freelibs/recls/.../incl.winstl.h: file; 1 KB
```


<!-- ########################### end of file ########################### -->

