# recls Example - **example_c_4**

## Summary

Demonstrates recursive search for all directories under the home or a named directory and displays the full path for any of them that has no files in it (or any of its subdirectories).


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_4/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in home or named directory
 *  - search matching all names - implicitly, by specifying NULL for the patterns parameter
 *  - search recursively for directories
 *  - search by Recls_Search()
 *  - display names of empty directories, (as determined via via Recls_IsDirectoryEntryEmpty())
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
 * main()
 */

int main(int argc, char* argv[])
{
    /* Declare a search handle, define the flags (for recursive file search)
     * and start a search.
     */
    hrecls_t        hSrch;
    recls_uint32_t  flags       =   RECLS_F_DIRECTORIES | RECLS_F_RECURSIVE;
    char const*     search_dir  =   argc > 1 ? argv[1] : "~";
    recls_rc_t      rc          =   Recls_Search(search_dir, "*", flags, &hSrch);

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
            /* ... test whether it's empty, ... */
            if (Recls_IsDirectoryEntryEmpty(entry))
            {
                /* ... display the search relative path, ... */
                printf("%s\n", entry->path.begin);
            }

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

T.B.C.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_4/example_c_4 ~/Documents
```

then it produces results such as:

```
/Users/user/Documents/temp/other
/Users/user/Documents/repositories/git/freelibs/xTests.git/objects/info
/Users/user/Documents/repositories/git/freelibs/xTests.git/refs/tags
/Users/user/Documents/repositories/git/freelibs/libCLImate.Go.git/objects/info
/Users/user/Documents/repositories/git/freelibs/libCLImate.Go.git/objects/pack
/Users/user/Documents/repositories/git/freelibs/libCLImate.Go.git/refs/heads
/Users/user/Documents/repositories/git/freelibs/libCLImate.Go.git/refs/tags
/Users/user/Documents/repositories/git/freelibs/collect-cxx.git/objects/info
/Users/user/Documents/repositories/git/freelibs/collect-cxx.git/refs/tags
/Users/user/Documents/repositories/git/freelibs/libpath.Go.git/objects/info
/Users/user/Documents/repositories/git/freelibs/libpath.Go.git/objects/pack
/Users/user/Documents/repositories/git/freelibs/libpath.Go.git/refs/tags
/Users/user/Documents/repositories/git/freelibs/Diagnosticism.git/objects/info
/Users/user/Documents/repositories/git/freelibs/Diagnosticism.git/objects/pack
/Users/user/Documents/repositories/git/freelibs/Diagnosticism.git/refs/tags
/Users/user/Documents/repositories/git/sis/async-1p.git/objects/info
/Users/user/Documents/repositories/git/sis/async-1p.git/refs/tags
/Users/user/Documents/repositories/git/STLSoft-1.11.git/objects/info
/Users/user/Documents/repositories/git/STLSoft-1.11.git/refs/tags
/Users/user/Documents/repositories/git/SynesisSoftware/.bin.git/objects/info
/Users/user/Documents/repositories/git/SynesisSoftware/.bin.git/refs/tags
/Users/user/Documents/Visual Studio 2022/Code Snippets/TypeScript/My Code Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/Visual Basic/My Code Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/Visual Web Developer/My CSS Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/Visual Web Developer/My HTML Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/XML/My Xml Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/Visual C++/My Code Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/JavaScript/My Code Snippets
/Users/user/Documents/Visual Studio 2022/Code Snippets/Visual C#/My Code Snippets
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/C#
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/Extensibility
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/JavaScript
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/TypeScript
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/Visual Basic
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/Visual C++
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/Visual C++ Project
/Users/user/Documents/Visual Studio 2022/Templates/ProjectTemplates/Visual Web Developer
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/C#
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/Extensibility
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/JavaScript
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/TypeScript
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/Visual Basic
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/Visual C++
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/Visual C++ Project
/Users/user/Documents/Visual Studio 2022/Templates/ItemTemplates/Visual Web Developer
```


<!-- ########################### end of file ########################### -->

