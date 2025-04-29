/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_9/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for sockets
 *  - search by Recls_Search()
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry structure members
 *
 * Created: 30th April 2025
 * Updated: 30th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Pantheios header files */
#ifdef HAS_Pantheios
# include <pantheios/pantheios.h>
#endif /* HAS_Pantheios */

/* STLSoft header files */
#include <platformstl/filesystem/path_functions.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#ifdef HAS_Pantheios

const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "example_c_9";
#endif /* HAS_Pantheios */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifdef HAS_Pantheios

void RECLS_CALLCONV_DEFAULT recls_log_to_pantheios(
    int         severity
,   char const* fmt
,   va_list     args
)
{
    pantheios_logvprintf(severity, fmt, args);
}
#endif /* HAS_Pantheios */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */


/* Pantheios header files */
#ifdef HAS_Pantheios
static int main_(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    stlsoft_C_string_slice_m_t  program_name    =   platformstl_C_get_executable_name_from_path(argv[0]);
    int const                   ri              =   pantheios_init();

    if (0 != ri)
    {
        fprintf(stderr, "%.*s: %.*s\n", (int)program_name.len, program_name.ptr, (int)pantheios_getInitCodeStringLength(ri), pantheios_getInitCodeString(ri));

        return EXIT_FAILURE;
    }
    else
    {
        recls_log_severities_t severities = {
            PANTHEIOS_SEV_ALERT,
            PANTHEIOS_SEV_ERROR,
            PANTHEIOS_SEV_WARNING,
            PANTHEIOS_SEV_INFORMATIONAL,
            PANTHEIOS_SEV_DEBUG,
            -1,
            -1,
            -1,
        };

        Recls_SetApiLogFunction(recls_log_to_pantheios, 0, &severities);

        int const rm = main_(argc, argv);

        pantheios_uninit();

        return rm;
    }
}

static int main_(int argc, char* argv[])
#else

int main(int argc, char* argv[])
#endif /* HAS_Pantheios */
{
    /* Declare a search handle, define search directory as named or current,
     * pattern matching all names, flags for recursive search of sockets,
     * and start a search.
     */
    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    char const*     patterns    =   Recls_GetWildcardsAll();
    recls_uint32_t  flags       =   RECLS_F_RECURSIVE | RECLS_F_SOCKETS;
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
        recls_info_t    entry;
        unsigned long   num_entries_found = 0;

        /* Get the details for the first entry, ... */
        Recls_GetDetails(hSrch, &entry);

        do
        {
            ++num_entries_found;

            /* ... display the full path, ... */
            printf("%.*s\n", (int)(entry->path.end - entry->path.begin), entry->path.begin);

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

        printf("  %lu socket(s) found\n", num_entries_found);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

