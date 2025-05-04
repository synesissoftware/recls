/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_4/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - use of Recls_RemoveDirectory() to (attempt to) remove the given
 *    directory;
 *
 * Created: 4th May 2025
 * Updated: 4th May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.hpp>

/* Pantheios header files */
#ifdef HAS_Pantheios
# include <pantheios/pantheios.hpp>
#endif /* HAS_Pantheios */

/* STLSoft header files */
#include <platformstl/filesystem/path_functions.h>
#include <stlsoft/system/cmdargs.hpp>

/* Standard C++ Library Files */
#include <iostream>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#ifdef HAS_Pantheios

const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "example_cpp_4";
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

static
int main_(stlsoft::string_slice_m_t program_name, int argc, char* argv[])
{
#ifdef HAS_Pantheios

    {
        recls::log_severities_t severities(
            PANTHEIOS_SEV_ALERT
        ,   PANTHEIOS_SEV_ERROR
        ,   PANTHEIOS_SEV_WARNING
        ,   PANTHEIOS_SEV_INFORMATIONAL
        ,   PANTHEIOS_SEV_DEBUG
        );

        Recls_SetApiLogFunction(recls_log_to_pantheios, 0, &severities);
    }
#endif /* HAS_Pantheios */

    char const*         dir_to_remove   =   NULL;
    recls::uint32_t     flags           =   0;

    stlsoft::cmdargs    args(argc, argv);

    for (auto const& opt : args.options())
    {
        if ("help" == opt.name)
        {
            std::cout << "USAGE: " << program_name << " <directory-to-remove> [ { --delete-files | -f }] [ { --delete-sockets | -s }]" << std::endl;

            return EXIT_SUCCESS;
        }
        else
        if ("delete-files" == opt.name ||
            "f" == opt.name)
        {
            flags |= recls::RECLS_REMDIR_F_REMOVE_FILES;
        }
        else
        if ("delete-sockets" == opt.name ||
            "s" == opt.name)
        {
            flags |= recls::RECLS_REMDIR_F_REMOVE_SOCKETS;
        }
        else
        {
            std::cerr << program_name << ": " << "invalid flag/option '" << opt << "'; use --help for usage" << std::endl;

            return EXIT_FAILURE;
        }
    }

    switch (args.values().size())
    {
    case 0:

        std::cerr << program_name << ": " << "must specify directory to remove; use --help for usage" << std::endl;

        return EXIT_FAILURE;
    case 1:

        dir_to_remove = args.values()[0].name.data();
        break;
    default:

        std::cerr << program_name << ": " << "too many arguments; use --help for usage" << std::endl;

        return EXIT_FAILURE;
    }


    // program logic
    {
        using recls::Recls_RemoveDirectory;
        using recls::directoryResults_t;
        using recls::recls_rc_t;

        directoryResults_t  dr;
        recls_rc_t          rc = Recls_RemoveDirectory(dir_to_remove, flags, &dr);

        if (RECLS_FAILED(rc))
        {
            /* The operation failed. Display the failure reason. */

            std::cerr << program_name << ": " << "could not remove directory '" << dir_to_remove << "': " << rc << std::endl;

            return EXIT_FAILURE;
        }
        else
        {
            std::cout
                << "removed directory '" << dir_to_remove << "': "
                << dr.numExistingElements << " existing element(s)"
                << "; "
                << dr.numResultingElements << " resulting element(s)"
                << "; "
                << dr.numExistingFiles << " existing entries(s)"
                << "; "
                << dr.numDeletedFiles << " deleted entries(s)"
                << "; "
                << dr.existingLength << " existing length"
                << "; "
                << dr.resultingLength << " resulting length"
                << std::endl
                ;

            return EXIT_SUCCESS;
        }
    }
}

int main(int argc, char* argv[])
{
    auto program_name = platformstl::get_executable_name_from_path(argv[0]);

    try
    {
        return main_(program_name, argc, argv);
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "%.*s: out of memory\n", int(program_name.len), program_name.ptr);
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "%.*s: %s\n", int(program_name.len), program_name.ptr, x.what());
    }
    catch (...)
    {
        fprintf(stderr, "%.*s: unexpected condition\n", int(program_name.len), program_name.ptr);
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

