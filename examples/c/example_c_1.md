# recls Example - **example_c_1**

## Summary

Demonstrates recursive search for all files under a given directory including all appropriate failure handling.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_1/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for files
 *  - search by Recls_Search()
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry structure members
 *
 * Created: 29th May 2006
 * Updated: 14th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    /* Declare a search handle, define search directory as named or current,
     * pattern matching all names, flags for recursive search of files, and
     * start a search.
     */
    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    char const*     patterns    =   Recls_GetWildcardsAll();
    recls_uint32_t  flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
    recls_rc_t      rc          =   Recls_Search(search_dir, patterns, flags, &hSrch);

    if (RECLS_RC_NO_MORE_DATA == rc)
    {
        printf("  no matches found\n");

        return EXIT_SUCCESS;
    }
    else if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the failure reason. */
failed:

        fprintf(
            stderr
        ,   "Search in '%s' failed: %.*s\n"
        ,   search_dir
        ,   (int)Recls_GetSearchCodeStringLength(rc), Recls_GetSearchCodeString(rc)
        );

        return EXIT_FAILURE;
    }
    else
    {
        recls_info_t entry;

        /* Get the details for the first entry, ... */
        Recls_GetDetails(hSrch, &entry);

        do
        {
            /* ... display the full path, ... */
            printf("%.*s\n", (int)(entry->path.end - entry->path.begin), entry->path.begin);

            /* ... close the entry handle, ... */
            Recls_CloseDetails(entry);

        } /* ... and get the next entry. */
        while (RECLS_RC_OK == (rc = Recls_GetNextDetails(hSrch, &entry)));

        /* Close the search handle. */
        Recls_SearchClose(hSrch);

        if (RECLS_RC_NO_MORE_DATA != rc && RECLS_FAILED(rc))
        {
            goto failed;
        }

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The program determines the desired search directory from that given as a command-line value or defaults to the current directory, in `search_dir` variable. It defines the `patterns` variable from the special patterns value obtained from `Recls_GetWildcardsAll()`, which means _all_ names are matched. It defines the `flags` variable as a combination of `RECLS_F_FILES`, which means match entries that are files,  and `RECLS_F_RECURSIVE`, which means to search also in sub-directories.

These variables are passed as arguments to `Recls_Search()`, along with the address of the search handle variable `hSrch`.

If the special failure code `RECLS_RC_NO_MORE_DATA` is obtained, this means means that the search was created successfully but obtained no matches, and then the program exits with `EXIT_SUCCESS` indicating program success to the operating system.

If the search otherwise failed (as per the check `RECLS_FAILED()`) then a description of the reason for the failure is obtained (by `Recls_GetSearchCodeString()` and `Recls_GetSearchCodeStringLength()`) and written to `stderr`, and then the program exits with `EXIT_FAILURE` indicating failure to the operating system.

If the search succeeds and is non-empty, then the program obtains and displays the full path of the first entry found, closes the current entry (via `Recls_CloseDetails()`) to release its resources, and loops to obtain each subsequent matching entry by `Recls_GetNextDetails()`.

Once all successful matched searching is complete, the search handle is closed to release is resources.

If the search was terminated for a reason other than `RECLS_RC_NO_MORE_DATA`, then the failure handling is invoked; otherwise the program exits with `EXIT_SUCCESS` indicating program success to the operating system.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_1/example_c_1 test
```

then it produces results such as:

```
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/test.unit.c.retcodes.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/test.unit.api.stat.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/test.unit.api.combine_paths.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/test.unit.api.create_directory.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/test.scratch.with_pantheios.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/test.scratch.cpp_api.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/test.scratch.search.1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/test_c_1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/test.scratch.links.cpp
```


<!-- ########################### end of file ########################### -->

