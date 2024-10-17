/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_1/example_c_1.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - searching (via Recls_Search()) for files
 *            - recursive operation
 *            - display of full path of each entry
 *            - handling of errors and reporting of error information
 *            - elicitation of entry properties via API function calls
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
    recls_uint32_t  flags   =   RECLS_F_FILES | RECLS_F_RECURSIVE;
    recls_rc_t      rc      =   Recls_Search(RECLS_LITERAL("."), Recls_GetWildcardsAll(), flags, &hSrch);

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
        /* Get the details for the first entry, ... */

        recls_info_t    entry;

        Recls_GetDetails(hSrch, &entry);

        do
        {
            /* ... display the full path, ... */

            recls_char_t    path[1001];
            size_t          cch;

            cch = Recls_GetPathProperty(entry, &path[0], RECLS_NUM_ELEMENTS(path));
            printf(RECLS_LITERAL("%.*s\n"), (int)cch, &path[0]);

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

