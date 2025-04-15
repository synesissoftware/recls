/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_3/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names - implicitly, by specifying NULL for the patterns parameter
 *  - search non-recursively for files and directories
 *  - search by Recls_Search()
 *  - display of entry-name for each matched entry, squeezed into maximum 64-characters via Recls_SqueezePath()
 *  - display of file-size for each matched file; display of directory size (sum of all file-sizes in all subdirectories, via Recls_CalcDirectoryEntrySize()) for matched directory
 *  - detecting failure and reporting of failure reason
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
 * constants
 */

#define CCH_SQUEEZED_PATH                                   (36)


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    char const*     patterns    =   NULL;
    recls_uint32_t  flags       =   RECLS_F_FILES | RECLS_F_DIRECTORIES;
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
            recls_filesize_t    size;
            recls_filesize_t    unit_size;
            char const*         unit_label;
            char const*         type_label;
            recls_char_t        squeezedPath[CCH_SQUEEZED_PATH];
            size_t              cch;


            if (Recls_IsEntryDirectory(entry))
            {
                size = Recls_CalcDirectoryEntrySize(entry);
                type_label = "directory";
            }
            else
            {
                size = Recls_GetSizeProperty(entry);
                type_label = "file";
            }

            if (0 != (unit_size = Recls_GetFileSizeGigaBytes(size)))
            {
                unit_label = "GB";
            }
            else if (0 != (unit_size = Recls_GetFileSizeMegaBytes(size)))
            {
                unit_label = "MB";
            }
            else if (0 != (unit_size = Recls_GetFileSizeKiloBytes(size)))
            {
                unit_label = "KB";
            }
            else
            {
                unit_label = "byte(s)";
            }


            /* ... squeeze name+ext into CCH_SQUEEZED_PATH characters, ... */
            cch = Recls_SqueezePath(entry->fileName.begin, &squeezedPath[0], CCH_SQUEEZED_PATH - 1);

            ((void)&cch);

            printf( RECLS_LITERAL("%32s: %9s; %4lu %s\n")
            ,   squeezedPath
            ,   type_label
            ,   (unsigned long)unit_size
            ,   unit_label
            );


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

