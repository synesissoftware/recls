/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_3.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - stat() of current directory (via Recls_Stat())
 *            - searching (via Recls_Search()) for files and directories
 *            - recursive operation
 *            - display of full path of each entry, squeezed to constant
 *              width (via Recls_SqueezePath())
 *            - display of file size for file entries
 *            - display of directory contents size for directory
 *              entries, (determined via Recls_CalcDirectoryEntrySize())
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
        hrecls_t        hSrch;
        recls_uint32_t  flags   =   RECLS_F_FILES | RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;

        rc = Recls_Search(current->path.begin, NULL, flags, &hSrch);

        /* ... close the entry handle, ... */
        Recls_CloseDetails(current);

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
                /* ... get the full path, ... */
                recls_filesize_t    size;
                recls_bool_t        isDirectory;
                recls_char_t        path[1001];
                recls_char_t        squeezedPath[48];
                size_t              cch = Recls_GetPathProperty(entry, &path[0], RECLS_NUM_ELEMENTS(path) - 1);;

                path[cch] = '\0';

                /* ... squeeze it into 48 characters, ... */
                cch = Recls_SqueezePath(path, &squeezedPath[0], RECLS_NUM_ELEMENTS(squeezedPath));

                /* ... determine type, ... */
                isDirectory = Recls_IsFileDirectory(entry);

                if (isDirectory)
                {
                    /* ... calculate size, or ... */
                    size = Recls_CalcDirectoryEntrySize(entry);
                }
                else
                {
                    /* ... elicit size, ... */

                    size = Recls_GetSizeProperty(entry);
                }

                if (0 != Recls_GetFileSizeGigaBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu MB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeMegaBytes(size)
                        );
                }
                else if (0 != Recls_GetFileSizeMegaBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu MB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeMegaBytes(size)
                        );
                }
                else if (0 != Recls_GetFileSizeKiloBytes(size))
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu KB\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)Recls_GetFileSizeKiloBytes(size)
                        );
                }
                else
                {
                    printf( RECLS_LITERAL("%.*s: %s; %lu bytes\n")
                        ,   (int)cch
                        ,   squeezedPath
                        ,   isDirectory ? RECLS_LITERAL("directory") : RECLS_LITERAL("file")
                        ,   (unsigned long)size
                        );
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
}

/* ///////////////////////////// end of file //////////////////////////// */

