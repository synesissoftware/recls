/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.search.1.c
 *
 * Purpose:     Implementation file for the test.scratch.search.1 project.
 *
 * Created:     12th August 2009
 * Updated:     1st January 2021
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2021, Synesis Software / Synesis Information Systems
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

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

#else /* ? RECLS_CHAR_TYPE_IS_WCHAR */
# ifdef _DEBUG
    Recls_SetApiLogFunction(logfn, 0, NULL);
# endif /* _DEBUG */

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

        printf("executing as if two arguments specified: %s %s\n", args[1], args[2]);

        return main(3, args);
    }
    else
    {
        char const* const   directory   =   argv[1];
        char const* const   patterns    =   argv[2];
        recls_uint32_t      flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
        hrecls_t            hSrch;
        recls_rc_t          rc;

        printf("searching for all files matching '%s' in directory '%s'\n", patterns, directory);

        rc = Recls_Search(directory, patterns, flags, &hSrch);

        if (RECLS_FAILED(rc))
        {
            fprintf(stderr, "search of '%s' directory, with '%s' pattern(s), failed: %s\n", directory, patterns, Recls_GetSearchCodeString(rc));

            return EXIT_FAILURE;
        }
        else
        {
            do
            {
                recls_entry_t entry;

                if (RECLS_SUCCEEDED(Recls_GetDetails(hSrch, &entry)))
                {
                    fprintf(stderr, "%s\n", entry->path.begin);
                }

            } while (RECLS_SUCCEEDED(rc = Recls_GetNext(hSrch)));

            Recls_SearchClose(hSrch);

            return EXIT_SUCCESS;
        }
    }
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */
}

/* ///////////////////////////// end of file //////////////////////////// */
