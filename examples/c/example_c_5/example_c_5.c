/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_c_5.c
 *
 * Purpose:     C example program for the recls core library. Demonstrates:
 *
 *                - stat() of home directory (via Recls_Stat())
 *                - en-bloc processing, via Recls_SearchProcess(), of all
 *                  files and directories under the home directory
 *                - recursive operation
 *                - display of path relative to home directory
 *                  (via Recls_DeriveRelativePath())
 *                - elicitation of entry properties via structure members
 *                - handling of errors and reporting of error information
 *
 * Created:     17th June 2006
 * Updated:     10th January 2017
 *
 * www:         http://www.recls.org/
 *
 * License:     Copyright (c) 2006-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////// */

/* recls Header Files */
#include <recls/recls.h>

/* Standard C Library Files */
#include <stdio.h>      /* for printf() / fprintf()         */
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define printf         wprintf
# define fprintf        fwprintf
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

/* ////////////////////////////////////////////////////////////////////// */

static int RECLS_CALLCONV_DEFAULT example_c_5_process_fn(   recls_info_t                entry
                                                        ,   recls_process_fn_param_t    param)
{
    recls_char_t        relativePath[1001];
    recls_char_t const  *homePath   =   (recls_char_t const*)param;
    size_t              cch         =   Recls_DeriveRelativePath(homePath, entry->path.begin, &relativePath[0], RECLS_NUM_ELEMENTS(relativePath));

    printf(RECLS_LITERAL("%.*s\n"), (int)cch, relativePath);

    return 1; /* Continue processing. */
}


int main()
{
    /* First, determine the home directory by stat()-ing ~ */
    recls_info_t    home;
    recls_rc_t      rc  =   Recls_Stat(RECLS_LITERAL("~"), RECLS_F_DIRECTORIES, &home);

    if(RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("stat of home directory failed: %s\n"), err);

        return EXIT_FAILURE;
    }
    else
    {
        recls_uint32_t  flags   =   RECLS_F_FILES | RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;

        /* Process all entries under the current directory, passing the home
         * entry's path pointer. This is valid since the path is always 
         * nul-terminated.
         */

        rc = Recls_SearchProcess(NULL, Recls_GetWildcardsAll(), flags, example_c_5_process_fn, (void*)home->path.begin);

        /* Close the home entry. */

        Recls_CloseDetails(home);

        if(RECLS_FAILED(rc))
        {
            /* The search failed. Display the error string. */
            recls_char_t    err[1001];
            size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

            err[n] = '\0';

            fprintf(stderr, RECLS_LITERAL("processing failed: %s\n"), err);

            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
