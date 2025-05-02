/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.with_pantheios/main.cpp
 *
 * Purpose: Demonstrates using Pantheios for recls API logging.
 *
 * Created: 13th December 2008
 * Updated: 2nd May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


#define PANTHEIOS_NO_INCLUDE_OS_AND_3PTYLIB_STRING_ACCESS

/* recls header files */
#include <recls/recls.h>

/* Pantheios header files */
#include <pantheios/pantheios.hpp>
#include <pantheios/inserters/args.hpp>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C++ header files */
#include <exception>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

extern "C" const char PANTHEIOS_FE_PROCESS_IDENTITY[]   =   "test.scratch.with_pantheios";


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

void RECLS_CALLCONV_DEFAULT recls_log_to_pantheios(
    int                 severity
,   char const*         fmt
,   va_list             args
)
{
    pantheios::pantheios_logvprintf(severity, fmt, args);
}


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char* argv[])
{
    using recls::hrecls_t;
    using recls::RECLS_F_NO_BREAK_INFINITE_LOOPS;
    using recls::RECLS_F_RECURSIVE;
    using recls::RECLS_FAILED;
    using recls::Recls_GetDetails;
    using recls::Recls_GetWildcardsAll;
    using recls::recls_info_t;
    using recls::recls_log_pfn_t;
    using recls::RECLS_RC_OK;
    using recls::recls_rc_t;
    using recls::Recls_Search;
    using recls::Recls_SearchClose;
    using recls::Recls_SetApiLogFunction;
    using recls::RECLS_SUCCEEDED;
    using recls::recls_uint32_t;

    Recls_SetApiLogFunction(recls_log_to_pantheios, 0, NULL);

    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    recls_uint32_t  flags       =   RECLS_F_RECURSIVE | RECLS_F_NO_BREAK_INFINITE_LOOPS;
    char const*     patterns    =   Recls_GetWildcardsAll();
    recls_rc_t      rc          =   Recls_Search(search_dir, patterns, flags, &hSrch);

    if (RECLS_RC_NO_MORE_DATA == rc)
    {
        puts("no matches");
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

        Recls_GetDetails(hSrch, &entry);

        do
        {
            printf("%.*s\n", (int)(entry->path.end - entry->path.begin), entry->path.begin);

            Recls_CloseDetails(entry);

            ;
        } while (RECLS_RC_OK == (rc = Recls_GetNextDetails(hSrch, &entry)));

        Recls_SearchClose(hSrch);

        if (RECLS_RC_NO_MORE_DATA != rc && RECLS_FAILED(rc))
        {
            goto failed;
        }

        Recls_SearchClose(hSrch);
    }

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    try
    {
        return main_(argc, argv);
    }
    catch (std::exception& x)
    {
        pantheios::log_ALERT("Unexpected general error: ", x, ". Application terminating");
    }
    catch (...)
    {
        pantheios::logputs(pantheios::emergency, "Unhandled unknown error");
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

