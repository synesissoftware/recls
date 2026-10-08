# recls - Example - **example_c_7**

## Summary

Demonstrates combining of paths via `Recls_CombinePaths()`.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_7/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - stat() of current directory (via Recls_Stat())
 *  - combining paths (via Recls_CombinePaths())
 *  - handling of errors and reporting of error information
 *
 * Created: 17th June 2006
 * Updated: 16th April 2025
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
    /* stat() the current directory */
    recls_info_t    current;
    recls_rc_t      rc  =   Recls_Stat(".", RECLS_F_DIRECTORIES | RECLS_F_DIRECTORY_PARTS, &current);

    ((void)&argc);
    ((void)&argv);

    if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, "stat of current directory failed: %s\n", err);

        return EXIT_FAILURE;
    }
    else
    {
        const recls_char_t  path2[] =   "abc/def/";
        recls_char_t        combinedPath[1001];
        size_t              cch     =   Recls_CombinePaths(current->path.begin, path2, &combinedPath[0], RECLS_NUM_ELEMENTS(combinedPath));

        /* full path */
        printf("%s combined with %s yields %.*s\n", current->path.begin, path2, (int)cch, combinedPath);

        /* Close the current entry. */
        Recls_CloseDetails(current);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The call to `Recls_Stat()` is use here simply to obtain an actual path of the current directory with which to combine with the example relative path `"abc/def/"` via the utility function `Recls_CombinePaths()`.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_7/example_c_7
```

then it produces results such as:

```
/Users/user/dev/synesissoftware/freelibs/recls/recls combined with abc/def/ yields /Users/user/dev/synesissoftware/freelibs/recls/recls/abc/def/
```


<!-- ########################### end of file ########################### -->

