# recls - Example - **example_c_3**

## Summary

Demonstrates non-recursive search for all files and directories under a given directory and displays their size, that being the size of all contained files (including in sub-directories) in the case of directories.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_3/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names - implicitly, by specifying NULL for the patterns parameter
 *  - search non-recursively for non-hidden directories, files, and sockets
 *  - search by Recls_Search()
 *  - display of entry-name for each matched entry, squeezed into maximum 64-characters via Recls_SqueezePath()
 *  - display of file-size for each matched file; display of directory size (sum of all file-sizes in all subdirectories, via Recls_CalcDirectoryEntrySize()) for matched directory
 *  - detecting failure and reporting of failure reason
 *
 * Created: 29th May 2006
 * Updated: 3rd May 2025
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
    char const*     patterns    =   "*|.*";
    recls_uint32_t  flags       =   RECLS_F_IGNORE_HIDDEN_ENTRIES | RECLS_F_DIRECTORIES | RECLS_F_FILES | RECLS_F_SOCKETS;
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
            if (Recls_IsEntrySocket(entry))
            {
                size = 0;
                type_label = "socket";
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

            printf("%36s: %9s; %4lu %s\n"
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
```


## Discussion

The functionality follows a similar pattern to that demonstrated already in **example_c_1** and **example_c_2**. The key differences are that the flag `RECLS_F_RECURSIVE` is _not_ specified, hence only files in the searched directory are listed.

The other differences are the use of entry attribute functions:
 * `Recls_IsEntryDirectory()` - indicates whether the entry is a directory;
 * `Recls_GetSizeProperty()` - obtains the size of the entry in the case of a file; directories have 0 size;
 * `Recls_GetFileSizeGigaBytes()`, `Recls_GetFileSizeMegaBytes()`, `Recls_GetFileSizeKiloBytes()` - return the size in the given units;

and the use of utility functions:
 * `Recls_CalcDirectoryEntrySize()` - conducts a search in a directory represented by an entry (`recls_info_t`), obtaining the sum of the sizes of all the files in it, and in all its subdirectories;;
 * `Recls_SqueezePath()` - squeezes a path into a potentially smaller space, replacing a portion of the path with the substitution substring `"..."`  to as to fit adequately;


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_3/example_c_3 src
```

then it produces results such as:


```
                      CMakeLists.txt:      file;    3 KB
                 ReclsFileSearch.cpp:      file;   10 KB
                 ReclsFileSearch.hpp:      file;    5 KB
    ReclsFileSearchDirectoryNode.cpp:      file;   26 KB
    ReclsFileSearchDirectoryNode.hpp:      file;    7 KB
                  ReclsFtpSearch.hpp:      file;    3 KB
  ReclsFtpSearchD...Node_windows.cpp:      file;   22 KB
  ReclsFtpSearchD...Node_windows.hpp:      file;    5 KB
          ReclsFtpSearch_windows.cpp:      file;    9 KB
                     ReclsSearch.cpp:      file;    3 KB
                     ReclsSearch.hpp:      file;    3 KB
                   api.entryinfo.cpp:      file;   12 KB
                       api.error.cpp:      file;    9 KB
                    api.extended.cpp:      file;    6 KB
                 api.ftp.windows.cpp:      file;    3 KB
            api.retcodes.windows.cpp:      file;    4 KB
                      api.search.cpp:      file;    7 KB
                        api.unix.cpp:      file;    2 KB
          api.util.combine_paths.cpp:      file;    3 KB
       api.util.create_directory.cpp:      file;   10 KB
   api.util.derive_relative_path.cpp:      file;    6 KB
         api.util.get_file_sizes.cpp:      file;    2 KB
       api.util.remove_directory.cpp:      file;   14 KB
           api.util.squeeze_path.cpp:      file;    3 KB
                   api.util.stat.cpp:      file;    6 KB
                     api.windows.cpp:      file;    8 KB
                 impl.api.search.cpp:      file;   21 KB
                   impl.api.search.h:      file;    2 KB
                       impl.assert.h:      file;    1 KB
                       impl.atomic.h:      file;    2 KB
                  impl.constants.hpp:      file;    3 KB
               impl.entryfunctions.h:      file;    2 KB
                  impl.entryinfo.cpp:      file;   24 KB
                  impl.entryinfo.hpp:      file;    2 KB
                   impl.fileinfo.cpp:      file;    4 KB
              impl.fileinfo.unix.cpp:      file;    4 KB
           impl.fileinfo.windows.cpp:      file;    2 KB
                         impl.root.h:      file;    4 KB
                   impl.snprintf.cpp:      file;    4 KB
                     impl.string.hpp:      file;    1 KB
                      impl.trace.cpp:      file;   11 KB
                        impl.trace.h:      file;    4 KB
                  impl.types.ftp.hpp:      file;    5 KB
                      impl.types.hpp:      file;    4 KB
                       impl.util.cpp:      file;   10 KB
                         impl.util.h:      file;    3 KB
                  impl.util.unix.cpp:      file;    4 KB
               impl.util.windows.cpp:      file;    3 KB
                      incl.inetstl.h:      file;    1 KB
                  incl.platformstl.h:      file;    1 KB
                      incl.stlsoft.h:      file;    2 KB
                      incl.unixstl.h:      file;    1 KB
                       incl.winstl.h:      file;    1 KB
```

and when run with:

```
$ ./_build/examples/c/example_c_3/example_c_3 .
```

then it produces results such as:

```
                          AUTHORS.md:      file;    0 byte(s)
                         CHANGES.txt:      file;   81 KB
                      CMakeLists.txt:      file;    9 KB
                         EXAMPLES.md:      file;    4 KB
                              FAQ.md:      file;    6 KB
                          HISTORY.md:      file;    2 KB
                          INSTALL.md:      file;    5 KB
                             LICENSE:      file;    1 KB
                             NEWS.md:      file;    4 KB
                           README.md:      file;    2 KB
                             TODO.md:      file;    1 KB
                                 bin: directory;    0 byte(s)
                               build: directory;    8 MB
                      build_cmake.sh:      file;    2 KB
                      clean_cmake.sh:      file;    1 KB
                               cmake: directory;    4 KB
                            examples: directory;  184 KB
                             include: directory;  344 KB
                                 lib: directory;    0 byte(s)
                    prepare_cmake.sh:      file;    5 KB
                            projects: directory;   26 KB
           remove_cmake_artefacts.sh:      file;    2 KB
                 run_all_examples.sh:      file;    2 KB
            run_all_scratch_tests.sh:      file;    2 KB
               run_all_unit_tests.sh:      file;    2 KB
                             scratch: directory;    0 byte(s)
                                 src: directory;  378 KB
                                test: directory;  162 KB
```


<!-- ########################### end of file ########################### -->

