/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.search.1.c
 *
 * Purpose: Demonstrates use of recls C API for searching.
 *
 * Created: 12th August 2009
 * Updated: 3rd January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ////////////////////////////////////////////////////////////////////// */

#ifdef _DEBUG
# ifndef RECLS_CHAR_TYPE_IS_WCHAR
void RECLS_CALLCONV_DEFAULT logfn(
    int                 severity
,   recls_char_t const* fmt
,   va_list             args
)
{
    ((void)severity);

    vfprintf(stderr, fmt, args);
    fputs("\n", stderr);
}
# endif /* !RECLS_CHAR_TYPE_IS_WCHAR */
#endif /* _DEBUG */

int main(int argc, char *argv[])
{
#ifdef RECLS_CHAR_TYPE_IS_WCHAR
    ((void)argc);
    ((void)argv);

    fwprintf(stderr, L"this test not implemented to do anything in wide encoding\n");

#else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
# ifdef _DEBUG
    Recls_SetApiLogFunction(logfn, 0, NULL);
# endif /* _DEBUG */

    { for (int i = 1; i < argc; ++i)
    {
        if (0 == strcmp("--help", argv[i]))
        {
            fprintf(stdout, "USAGE: %s { <search-directory> <search-pattern(s> | --help | )}\n", argv[0]);

            return EXIT_SUCCESS;
        }
    }}

    if (argc < 3)
    {
        char* args[] =
        {
            NULL,
            ".",
            "??????",
            NULL
        };

        args[0] = argv[0];
        args[2] = (recls_char_t*)Recls_GetWildcardsAll();

        fprintf(stdout, "executing as if two arguments specified: %s %s\n", args[1], args[2]);

        return main(3, args);
    }
    else
    {
        char const* const   directory   =   argv[1];
        char const* const   patterns    =   argv[2];
        recls_uint32_t      flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
        hrecls_t            hSrch;
        recls_rc_t          rc;

        fprintf(stdout, "searching for all files matching '%s' in directory '%s' (flags=0x%08x)\n", patterns, directory, flags);

        rc = Recls_Search(directory, patterns, flags, &hSrch);

        if (RECLS_RC_NO_MORE_DATA == rc)
        {
            fprintf(stdout, "\tno matches found\n");

            return EXIT_SUCCESS;
        }
        else
        if (RECLS_FAILED(rc))
        {
            fprintf(stderr, "search of '%s' directory, with '%s' pattern(s), failed: %s\n", directory, patterns, Recls_GetSearchCodeString(rc));

            return EXIT_FAILURE;
        }
        else
        {
            size_t num_found = 0;

            fprintf(stdout, "matching entries:\n");

            do
            {
                recls_entry_t entry;

                if (RECLS_SUCCEEDED(Recls_GetDetails(hSrch, &entry)))
                {
                    fprintf(stdout, "\t%s\n", entry->path.begin);

                    ++num_found;
                }

            } while (RECLS_SUCCEEDED(rc = Recls_GetNext(hSrch)));

            Recls_SearchClose(hSrch);

            fprintf(stdout, "search complete - %lu entries found\n", (unsigned long)num_found);

            return EXIT_SUCCESS;
        }
    }
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

/* ///////////////////////////// end of file //////////////////////////// */

