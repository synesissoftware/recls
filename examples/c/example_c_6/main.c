/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_6/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 * - stat() of current directory (via Recls_Stat()) or named path
 * - display of full path, drive (Win32 only), directory, directory path, file, file name, file extension, and directory parts of each entry
 * - elicitation of entry properties via structure members
 * - handling of errors and reporting of error information
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
    /* stat() the current directory */
    recls_info_t    current;
    char const*     path    =   argc > 1 ? argv[1] : ".";
    recls_rc_t      rc      =   Recls_Stat(path, RECLS_F_DIRECTORY_PARTS, &current);

    if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the error string. */
        recls_char_t    err[100];
        size_t          n   =   Recls_GetErrorString(rc, &err[0], sizeof(err));

        fprintf(stderr, "stat of '%s' failed: %.*s\n", path, (int)n, err);

        return EXIT_FAILURE;
    }
    else
    {
        /* full path */
        printf("  given path:       %s\n", path);

        printf("\n");

        /* full path */
        printf("  full path:        %s\n", current->path.begin);

        /* directory path */
        printf("  directory path:   %.*s\n", (int)(current->directory.end - current->path.begin), current->path.begin);

#if defined(RECLS_PLATFORM_IS_WINDOWS)

        /* drive (Windows-only) */
        printf("  drive:            %c:\n", current->drive);

        /* directory */
        printf("  directory:          %.*s\n", (int)(current->directory.end - current->directory.begin), current->directory.begin);
#else

        /* directory */
        printf("  directory:        %.*s\n", (int)(current->directory.end - current->directory.begin), current->directory.begin);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* file */
        printf("  basename:         %*s%.*s\n", (int)(current->directory.end - current->path.begin), "", (int)(current->fileExt.end - current->fileName.begin), current->fileName.begin);

        /* file name */
        printf("  stem:             %*s%.*s\n", (int)(current->directory.end - current->path.begin), "", (int)(current->fileName.end - current->fileName.begin), current->fileName.begin);

        /* file extension */
        if (current->fileExt.end != current->fileExt.begin)
        {
            printf("  extension:        %*s%*s%.*s\n", (int)(current->directory.end - current->path.begin), "", 1 + (int)(current->fileName.end - current->fileName.begin), "", (int)(current->fileExt.end - current->fileExt.begin), current->fileExt.begin);
        }

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        /* drive (Windows-only) */
        printf("  short file:       %.*s\n", (int)(current->shortFile.end - current->shortFile.begin), current->shortFile.begin);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* directory parts */
        printf("  directory parts:\n");
        {
            struct recls_strptrs_t const*   part_ptr;
            int                             offset = 0;

            for (part_ptr = current->directoryParts.begin; part_ptr != current->directoryParts.end; ++part_ptr)
            {
                printf("    part:           %*s%.*s\n", offset, "", (int)(part_ptr->end - part_ptr->begin), part_ptr->begin);

                offset += (int)(part_ptr->end - part_ptr->begin);
            }
        }

        printf("\n");

        printf("  search directory: %.*s\n", (int)(current->searchDirectory.end - current->searchDirectory.begin), current->searchDirectory.begin);
        printf("  search-rel path:  %.*s\n", (int)(current->searchRelativePath.end - current->searchRelativePath.begin), current->searchRelativePath.begin);

        /* Close the current entry. */
        Recls_CloseDetails(current);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

