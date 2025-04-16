/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_4/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in home or named directory
 *  - search matching all names - implicitly, by specifying NULL for the patterns parameter
 *  - search recursively for directories
 *  - search by Recls_Search()
 *  - display names of empty directories, (as determined via via Recls_IsDirectoryEntryEmpty())
 *
 * Created: 29th May 2006
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
    /* Declare a search handle, define the flags (for recursive file search)
     * and start a search.
     */
    hrecls_t        hSrch;
    recls_uint32_t  flags       =   RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;
    char const*     search_dir  =   argc > 1 ? argv[1] : "~";
    recls_rc_t      rc          =   Recls_Search(search_dir, "*", flags, &hSrch);

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
            /* ... test whether it's empty, ... */
            if (Recls_IsDirectoryEntryEmpty(entry))
            {
                /* ... display the search relative path, ... */
                printf("%s\n", entry->path.begin);
            }

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

