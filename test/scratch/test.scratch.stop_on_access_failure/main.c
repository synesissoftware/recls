/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.stop_on_access_failure.cpp
 *
 * Purpose: Scratch-test exercising the skipping of inaccessible nodes.
 *
 * Created: 1st May 2025
 * Updated: 2nd May 2025
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

/* Standard C header files */
#include <stdio.h>

#ifdef STLSOFT_COMPILER_IS_MSVC
# include <crtdbg.h>
#endif


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "test.scratch.stop_on_access_failure";


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

 int RECLS_CALLCONV_DEFAULT process_fn(
    /* [in] */ recls_entry_t            hEntry
,   /* [in] */ recls_process_fn_param_t param
)
{
    recls_uint64_t* num_found = param;

    ++*num_found;

    fprintf(stdout, "\t%s\n", hEntry->path.begin);

    return 1;
}

int main_(
    stlsoft_C_string_slice_m_t  program_name
,   int                         argc
,   char*                       argv[]
)
{
    char const*                 search_dir      =   argc > 1 ? argv[1] : ".";
    char const*                 patterns        =   "*|.*";
    recls_uint32_t const        flags           =   RECLS_F_RECURSIVE | RECLS_F_STOP_ON_ACCESS_FAILURE | RECLS_F_DEVICES | RECLS_F_FILES | RECLS_F_SOCKETS;
    recls_uint64_t              num_found       =   0;
    recls_rc_t                  rc              =   Recls_SearchProcess(search_dir, patterns, flags, process_fn, &num_found);

    if (RECLS_FAILED(rc) && RECLS_RC_NO_MORE_DATA != rc)
    {
        fprintf(stderr, "%.*s: %.*s\n", (int)program_name.len, program_name.ptr, (int)Recls_GetSearchCodeStringLength(rc), Recls_GetSearchCodeString(rc));

        return EXIT_FAILURE;
    }
    else
    {
        fprintf(stdout, "\t%llu item(s) found\n", (unsigned long long)num_found);

        return EXIT_SUCCESS;
    }
}

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
#ifdef HAS_Pantheios

        recls_log_severities_t severities = { .severities = {
            PANTHEIOS_SEV_ALERT,
            PANTHEIOS_SEV_ERROR,
            PANTHEIOS_SEV_WARNING,
            PANTHEIOS_SEV_INFORMATIONAL,
            PANTHEIOS_SEV_DEBUG,
            -1,
            -1,
            -1,
        }};
#endif /* HAS_Pantheios */

#if defined(_MSC_VER) && \
    defined(_DEBUG)

        _CrtMemState    memState;

        _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

#ifdef HAS_Pantheios

        Recls_SetApiLogFunction(recls_log_to_pantheios, 0, &severities);
#endif /* HAS_Pantheios */

        int const rm = main_(program_name, argc, argv);

#if defined(_MSC_VER) && \
    defined(_DEBUG)

        _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

        pantheios_uninit();

        return rm;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */

