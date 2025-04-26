/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.with_pantheios.cpp
 *
 * Purpose: Demonstrates using Pantheios for recls API logging.
 *
 * Created: 13th December 2008
 * Updated: 23rd April 2025
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

static int main_(int /* argc */, char** /*argv*/)
{
    using recls::RECLS_FAILED;
    using recls::RECLS_F_RECURSIVE;
    using recls::RECLS_SUCCEEDED;
    using recls::Recls_GetDetails;
    using recls::Recls_GetWildcardsAll;
    using recls::Recls_Search;
    using recls::Recls_SearchClose;
    using recls::Recls_SetApiLogFunction;
    using recls::hrecls_t;
    using recls::recls_info_t;
    using recls::recls_log_pfn_t;
    using recls::recls_rc_t;

    Recls_SetApiLogFunction(recls_log_to_pantheios, PANTHEIOS_SEV_DEBUG, 0);

    hrecls_t    hSrch;
    recls_rc_t  rc = Recls_Search(".", Recls_GetWildcardsAll(), RECLS_F_RECURSIVE, &hSrch);

    if (RECLS_RC_NO_MORE_DATA == rc)
    {
        puts("no matches");
    }
    else if (RECLS_FAILED(rc))
    {
    }
    else
    {
        recls_info_t    info;

        rc = Recls_GetDetails(hSrch, &info);

        if (RECLS_SUCCEEDED(rc))
        {
            ;
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

