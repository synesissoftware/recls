/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_4.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - searching (via Recls_Search()) for directories
 *            - non-recursive operation
 *            - filtering of non-empty directories, (via
 *              Recls_IsDirectoryEntryEmpty())
 *            - display of search relative path
 *            - handling of errors and reporting of error information
 *            - elicitation of entry properties structure members
 *
 * Created: 29th May 2006
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
    /* Declare a search handle, define the flags (for recursive file search)
     * and start a search.
     */
    hrecls_t        hSrch;
    recls_uint32_t  flags   =   RECLS_F_DIRECTORIES;
    recls_rc_t      rc      =   Recls_Search(NULL, RECLS_LITERAL("*"), flags, &hSrch);

    ((void)&argc);
    ((void)&argv);

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
        recls_info_t    entry;

        /* Get the details for the first entry, ... */
        Recls_GetDetails(hSrch, &entry);

        do
        {
            /* ... test whether it's non-empty, ... */
            if (!Recls_IsDirectoryEntryEmpty(entry))
            {
                /* ... display the search relative path, ... */
                printf(RECLS_LITERAL("%.*s\n"), (int)(entry->searchRelativePath.end - entry->searchRelativePath.begin), entry->searchRelativePath.begin);
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

/* ///////////////////////////// end of file //////////////////////////// */

