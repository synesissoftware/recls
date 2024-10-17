/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_8.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - elicitation of all roots (via Recls_GetRoots()), and
 *              selected roots (via Recls_GetSelectedRoots()), on host
 *              system
 *            - determination of total size of all files per root (via
 *              Recls_CalcDirectorySize())
 *
 * Created: 17th June 2006
 * Updated: 8th July 2024
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

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    ((void)&argc);
    ((void)&argv);

    /* Display all the roots on the host system. */
    {
        recls_root_t    roots[26];
        size_t          numRoots    =   Recls_GetRoots(&roots[0], RECLS_NUM_ELEMENTS(roots));
        size_t          i;

        printf(RECLS_LITERAL("All roots on host system:\n"));
        for (i = 0; i != numRoots; ++i)
        {
            printf(RECLS_LITERAL("  %s\n"), roots[i].name);
        }
        printf(RECLS_LITERAL("\n"));
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

        printf(RECLS_LITERAL("Measuring root directories of selected roots on host system. This could take several minutes ...\n"));
        for (i = 0; i != numRoots; ++i)
        {
            recls_filesize_t size = Recls_CalcDirectorySize(roots[i].name);

            if (0 != Recls_GetFileSizeGigaBytes(size))
            {
                printf(RECLS_LITERAL("  %s : %lu GB\n"), roots[i].name, (unsigned long)Recls_GetFileSizeGigaBytes(size));
            }
            else if (0 != Recls_GetFileSizeMegaBytes(size))
            {
                printf(RECLS_LITERAL("  %s : %lu MB\n"), roots[i].name, (unsigned long)Recls_GetFileSizeMegaBytes(size));
            }
            else if (0 != Recls_GetFileSizeKiloBytes(size))
            {
                printf(RECLS_LITERAL("  %s : %lu KB\n"), roots[i].name, (unsigned long)Recls_GetFileSizeKiloBytes(size));
            }
            else
            {
                printf(RECLS_LITERAL("  %s : %lu bytes\n"), roots[i].name, (unsigned long)size);
            }
        }
        printf(RECLS_LITERAL("\n"));

        free(roots);
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */

