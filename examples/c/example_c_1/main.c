/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_1/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for files and sockets
 *  - search by Recls_Search()
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry structure members
 *
 * Created: 29th May 2006
 * Updated: 21st April 2025
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
    recls_uint32_t  flags       =   RECLS_F_RECURSIVE | RECLS_F_FILES | RECLS_F_SOCKETS;
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

