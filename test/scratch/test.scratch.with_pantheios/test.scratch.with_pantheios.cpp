/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.with_pantheios.cpp
 *
 * Purpose: Demonstrates using Pantheios for recls API logging.
 *
 * Created: 13th December 2008
 * Updated: 23rd February 2025
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

/* UNIXem header files */
#if defined(_WIN32) || \
    defined(_WIN64)
# include <unixem/unixem.h>
#endif /* Win32 || Win64 */

/* Standard C++ header files */
#include <exception>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <string>
#include <vector>
#endif /* 0 */

#if !defined(__WATCOMC__) && \
    (   !defined(_MSC_VER) || \
        _MSC_VER >= 1100)

#else /* ? __WATCOMC__ */
namespace std
{
    using ::exception;
}
#endif /* __WATCOMC__ */

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

extern "C" const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "test.scratch.with_pantheios";


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
    int             res;

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.with_pantheios: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch (std::exception& x)
    {
        pantheios::log_ALERT("Unexpected general error: ", x, ". Application terminating");

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        pantheios::puts(pantheios::emergency, "Unhandled unknown error");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* ///////////////////////////// end of file //////////////////////////// */

