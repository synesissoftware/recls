/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_6/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - stat() of current directory (via Recls_Stat()) or named path
 *  - display of full path, drive (Win32 only), directory, directory path, file, file name, file extension, and directory parts of each entry
 *  - elicitation of entry properties via structure members
 *  - handling of errors and reporting of error information
 *
 * Created: 17th June 2006
 * Updated: 30th April 2025
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
    /* stat() the path */
    recls_info_t    entry;
    char const*     path    =   argc > 1 ? argv[1] : ".";
    recls_rc_t      rc      =   Recls_Stat(path, RECLS_F_DIRECTORY_PARTS, &entry);

    if (RECLS_FAILED(rc))
    {
        /* search failed : display the error string */
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
        printf("  full path:        %s\n", entry->path.begin);

        /* type */
        printf("  type:             ");
        if (Recls_IsEntryDirectory(entry))
        {
            printf("<directory>");
        }
        else
        if (Recls_IsEntryDevice(entry))
        {
            printf("<device>");
        }
        if (Recls_IsEntrySocket(entry))
        {
            printf("<socket>");
        }
        else
        {
            printf("<file>");
        }
        if (Recls_IsEntryLink(entry))
        {
            printf(" <link>");
        }
        if (Recls_IsEntryReadOnly(entry))
        {
            printf(" <read-only>");
        }
        printf("\n");


        /* directory path */
        printf("  directory path:   %.*s\n", (int)(entry->directory.end - entry->path.begin), entry->path.begin);

#if defined(RECLS_PLATFORM_IS_WINDOWS)

        /* drive (Windows-only) */
        printf("  drive:            %c:\n", entry->drive);

        /* directory */
        printf("  directory:          %.*s\n", (int)(entry->directory.end - entry->directory.begin), entry->directory.begin);
#else /* ? RECLS_PLATFORM_IS_WINDOWS */

        /* directory */
        printf("  directory:        %.*s\n", (int)(entry->directory.end - entry->directory.begin), entry->directory.begin);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* basename */
        printf("  basename:         %*s%.*s\n", (int)(entry->directory.end - entry->path.begin), "", (int)(entry->fileExt.end - entry->fileName.begin), entry->fileName.begin);

        /* stem */
        printf("  stem:             %*s%.*s\n", (int)(entry->directory.end - entry->path.begin), "", (int)(entry->fileName.end - entry->fileName.begin), entry->fileName.begin);

        /* extension */
        if (entry->fileExt.end != entry->fileExt.begin)
        {
            printf("  extension:        %*s%*s%.*s\n", (int)(entry->directory.end - entry->path.begin), "", 1 + (int)(entry->fileName.end - entry->fileName.begin), "", (int)(entry->fileExt.end - entry->fileExt.begin), entry->fileExt.begin);
        }

#if defined(RECLS_PLATFORM_IS_WINDOWS)
        /* drive (Windows-only) */
        printf("  short file:       %.*s\n", (int)(entry->shortFile.end - entry->shortFile.begin), entry->shortFile.begin);
#endif /* RECLS_PLATFORM_IS_WINDOWS */

        /* directory parts */
        printf("  directory parts:\n");
        {
            struct recls_strptrs_t const*   part_ptr;
            int                             offset = 0;

            for (part_ptr = entry->directoryParts.begin; part_ptr != entry->directoryParts.end; ++part_ptr)
            {
                printf("    part:           %*s%.*s\n", offset, "", (int)(part_ptr->end - part_ptr->begin), part_ptr->begin);

                offset += (int)(part_ptr->end - part_ptr->begin);
            }
        }

        /* size */
        printf("  size:             %lu byte(s)\n", (unsigned long)(entry->size));

        printf("\n");

        /* search directory */
        printf("  search directory: %.*s\n", (int)(entry->searchDirectory.end - entry->searchDirectory.begin), entry->searchDirectory.begin);

        /* search-relative path */
        printf("  search-rel path:  %.*s\n", (int)(entry->searchRelativePath.end - entry->searchRelativePath.begin), entry->searchRelativePath.begin);

        /* close the entry. */
        Recls_CloseDetails(entry);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

