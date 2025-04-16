# recls Example - **example_c_8**

## Summary

Demonstrates elicitation of roots via `Recls_GetRoots()` and `Recls_GetSelectedRoots()`, and then obtaining size of files under one of the selected roots via `Recls_CalcDirectorySize()`.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_8/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - elicitation of all roots (via Recls_GetRoots()), and selected roots (via Recls_GetSelectedRoots()), on host system
 *  - determination of total size of all files per root (via Recls_CalcDirectorySize())
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

int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    /* Display all the roots on the host system. */
    {
        recls_root_t    roots[26];
        size_t          numRoots    =   Recls_GetRoots(&roots[0], RECLS_NUM_ELEMENTS(roots));
        size_t          i;

        printf("All roots on host system:\n");
        for (i = 0; i != numRoots; ++i)
        {
            printf("  %s\n", roots[i].name);
        }
        printf("\n");
    }

    /* Display the fixed, optical and ram-drive roots on the host system,
     * and calculate their size.
     */
    {
        unsigned        rootTypes   =   RECLS_ROOTS_F_FIXED_DRIVES | RECLS_ROOTS_F_CDROM_DRIVES | RECLS_ROOTS_F_RAM_DRIVES;
        size_t          numRoots    =   Recls_GetSelectedRoots(NULL, 0, rootTypes);
        recls_root_t*   roots       =   (recls_root_t*)malloc(sizeof(recls_root_t) * numRoots);
        size_t          i;

        numRoots = Recls_GetSelectedRoots(&roots[0], numRoots, rootTypes);

        printf("Measuring root directories of selected roots on host system. This could take several minutes ...\n");
        for (i = 0; i != numRoots; ++i)
        {
            recls_filesize_t size = Recls_CalcDirectorySize(roots[i].name);

            if (0 != Recls_GetFileSizeGigaBytes(size))
            {
                printf("  %s : %lu GB\n", roots[i].name, (unsigned long)Recls_GetFileSizeGigaBytes(size));
            }
            else if (0 != Recls_GetFileSizeMegaBytes(size))
            {
                printf("  %s : %lu MB\n", roots[i].name, (unsigned long)Recls_GetFileSizeMegaBytes(size));
            }
            else if (0 != Recls_GetFileSizeKiloBytes(size))
            {
                printf("  %s : %lu KB\n", roots[i].name, (unsigned long)Recls_GetFileSizeKiloBytes(size));
            }
            else
            {
                printf("  %s : %lu bytes\n", roots[i].name, (unsigned long)size);
            }
        }
        printf("\n");

        free(roots);
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The first part of the program uses the API function `Recls_GetRoots()` to obtain the list of roots. (On Unix, this will contain a single item `"/"`; on Windows, this might contain multiple roots of the form `"C:\"`, `"I:\"`, etc.).

The second part of the program uses the API function `Recls_GetSelectedRoots()` along with a set of flags indicating that only roots matching the given criteria are obtained. Then, for each of these, the directory size of the root is obtained via the utility function `Recls_CalcDirectorySize()` and displayed in the appropriate units.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_8/example_c_8
```

then it produces results such as:

```
All roots on host system:
  /

Measuring root directories of selected roots on host system. This could take several minutes ...
  / : 974 MB
```


<!-- ########################### end of file ########################### -->

