/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_7.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - stat() of current directory (via Recls_Stat())
 *            - combining paths (via Recls_CombinePaths())
 *            - elicitation of entry properties via structure members
 *            - handling of errors and reporting of error information
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
        const recls_char_t  path2[] =   RECLS_LITERAL("abc/def/");
        recls_char_t        combinedPath[1001];
        size_t              cch     =   Recls_CombinePaths(current->path.begin, path2, &combinedPath[0], RECLS_NUM_ELEMENTS(combinedPath));

        /* full path */
        printf(RECLS_LITERAL("%s combined with %s yields %.*s\n"), current->path.begin, path2, (int)cch, combinedPath);

        /* Close the current entry. */
        Recls_CloseDetails(current);

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

