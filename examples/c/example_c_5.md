# recls Example - **example_c_5**

## Summary

Demonstrates recursive search via process callback function, in which the entry's path is shown relative to the home or given directory.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_5/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - stat() of home directory (via Recls_Stat())
 *  - search matching all names
 *  - search recursively for files and directories
 *  - search as en-bloc processing, via Recls_SearchProcess()
 *  - display of each entry's path relative to home directory (via Recls_DeriveRelativePath())
 *  - handling of errors and reporting of error information
 *
 * Created: 17th June 2006
 * Updated: 15th April 2025
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

static int RECLS_CALLCONV_DEFAULT
example_c_5_process_fn(
    recls_info_t                entry
,   recls_process_fn_param_t    param
)
{
    recls_char_t                relativePath[1001];
    recls_char_t const* const   homePath    =   (recls_char_t const*)param;
    size_t                      cch         =   Recls_DeriveRelativePath(homePath, entry->path.begin, &relativePath[0], RECLS_NUM_ELEMENTS(relativePath));

    printf("%.*s\n", (int)cch, relativePath);

    return 1; /* Continue processing. */
}

int main(int argc, char* argv[])
{
    /* First, determine the home directory by stat()-ing ~ */
    recls_info_t    home;
    recls_rc_t      rc  =   Recls_Stat("~", RECLS_F_DIRECTORIES, &home);

    if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err));

        fprintf(stderr, "stat of home directory failed: %.*s\n", (int)n, err);

        return EXIT_FAILURE;
    }
    else
    {
        hrecls_t        hSrch;
        char const*     search_dir  =   argc > 1 ? argv[1] : ".";
        char const*     patterns    =   Recls_GetWildcardsAll();
        recls_uint32_t  flags       =   RECLS_F_FILES | RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;
        recls_rc_t      rc          =   Recls_Search(search_dir, patterns, flags, &hSrch);

        /* Process all entries under the current directory, passing the home
         * entry's path pointer. This is valid since the path is always
         * nul-terminated.
         */

        rc = Recls_SearchProcess(search_dir, Recls_GetWildcardsAll(), flags, example_c_5_process_fn, (void*)home->path.begin);

        /* Close the home entry. */

        Recls_CloseDetails(home);

        if (RECLS_FAILED(rc))
        {
            /* The search failed. Display the error string. */
            recls_char_t    err[1001];
            size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

            fprintf(stderr, "Search in '%s' failed: %.*s\n", search_dir, (int)n, err);

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

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_5/example_c_5 /Volumes/Non-TM\ backups/dir
```

then it produces results such as:

```
../../Volumes/Non-TM backups/dir/dir-1
../../Volumes/Non-TM backups/dir/dir-2
../../Volumes/Non-TM backups/dir/dir-2/file-2
../../Volumes/Non-TM backups/dir/dir-1/file-1
. . .
```


<!-- ########################### end of file ########################### -->

