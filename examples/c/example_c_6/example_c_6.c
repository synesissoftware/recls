/* /////////////////////////////////////////////////////////////////////////////
 * File:        example_c_6.c
 *
 * Purpose:     C example program for the recls core library. Demonstrates:
 *
 *                - stat() of current directory (via Recls_Stat())
 *                - display of full path, drive (Win32 only), directory,
 *                  directory path, file, file name, file extension, and
 *                  directory parts of each entry
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

int main()
{
    /* stat() the current directory */
    recls_info_t    current;
    recls_rc_t      rc  =   Recls_Stat(RECLS_LITERAL("."), RECLS_F_DIRECTORIES | RECLS_F_DIRECTORY_PARTS, &current);

    if(RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[1001];
        size_t  n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("stat of current directory failed: %s\n"), err);

        return EXIT_FAILURE;
    }
    else
    {
        struct recls_strptrs_t const    *part_ptr;

        /* full path */
        printf(RECLS_LITERAL("%s\n"), current->path.begin);

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        /* drive (Windows-only) */
        printf(RECLS_LITERAL("  drive:          %c:\n"), current->drive);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* directory path */
        printf(RECLS_LITERAL("  directory path: %.*s\n"), (int)(current->directory.end - current->path.begin), current->path.begin);

        /* directory */
        printf(RECLS_LITERAL("  directory:      %.*s\n"), (int)(current->directory.end - current->directory.begin), current->directory.begin);

        /* file */
        printf(RECLS_LITERAL("  file:           %.*s\n"), (int)(current->fileExt.end - current->fileName.begin), current->fileName.begin);

        /* file name */
        printf(RECLS_LITERAL("  file name:      %.*s\n"), (int)(current->fileName.end - current->fileName.begin), current->fileName.begin);

        /* file extension */
        printf(RECLS_LITERAL("  file ext:       %.*s\n"), (int)(current->fileExt.end - current->fileExt.begin), current->fileExt.begin);

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        /* drive (Windows-only) */
        printf(RECLS_LITERAL("  short file:     %.*s\n"), (int)(current->shortFile.end - current->shortFile.begin), current->shortFile.begin);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* directory parts */
        printf(RECLS_LITERAL("  directory parts:\n"));
        for(part_ptr = current->directoryParts.begin; part_ptr != current->directoryParts.end; ++part_ptr)
        {
            printf(RECLS_LITERAL("    part:     %.*s\n"), (int)(part_ptr->end - part_ptr->begin), part_ptr->begin);
        }

        /* Close the current entry. */
        Recls_CloseDetails(current);

        return EXIT_SUCCESS;
    }
}

/* ///////////////////////////// end of file //////////////////////////// */
