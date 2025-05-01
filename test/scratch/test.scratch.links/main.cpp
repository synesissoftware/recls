/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/test.scratch.links/main.cpp
 *
 * Purpose: Finds and lists multiply-linked files.
 *
 * Created: 23rd February 2011
 * Updated: 2nd May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.hpp>

/* STLSoft header files */
#include <platformstl/platformstl.h>
#include <platformstl/filesystem/path_functions.h>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/conversion/char_conversions.hpp>
# include <winstl/conversion/int_to_string.hpp>
# include <winstl/diagnostics/output_debug_line.hpp>
#endif

/* Standard C++ header files */
#include <exception>
#include <iostream>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace {

    typedef stlsoft::string_slice_m_t                       sslice_t;
#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    typedef std::basic_string<
        char
    >                                                       string_r_t;
#endif
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * helpers
 */



/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(
    sslice_t const  program_name
,   int             argc
,   char*           argv[]
)
{
    char const* searchRoot = NULL;

    switch (argc)
    {
    case 1:

        break;
    case 2:

        if (0 == ::strcmp("--help", argv[1]))
        {
            std::cout
                << "USAGE: "
                << program_name
                << " [ { --help | <search-root-dir> | } ]"
                << std::endl;

            return EXIT_SUCCESS;
        }
        else
        {
            searchRoot = argv[1];
        }
        break;
    default:

        std::cerr
            << program_name
            << ": too many arguments; use --help for usage"
            << std::endl;

        return EXIT_FAILURE;
    }

    std::cout
        << "listing all files under the directory '"
        << stlsoft::c_str_ptr(NULL != searchRoot ? searchRoot : ".")
        << "' that have a link count > 1:"
        << std::endl;

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    string_r_t longest_dir;

    struct callback
    {
        static int function(
            /* [in] */ recls::char_t const*         dir
        ,   /* [in] */ size_t                       dirLen
        ,   /* [in] */ recls::progress_fn_param_t   param
        ,   /* [in] */ void*                     /* reserved0 */
        ,   /* [in] */ recls::uint32_t           /* reserved1 */
        )
        {
            WINSTL_ASSERT(ss_nullptr_k != param);

            winstl::diagnostics::output_debug_line("searching '", winstl::t2a(dir), "'");

            string_r_t& ldir = *static_cast<string_r_t*>(param);

            if (dirLen > ldir.size())
            {
                ldir.assign(winstl::t2a(dir), dirLen);
            }

            return 1;
        }
    };
#endif


#if defined(PLATFORMSTL_OS_IS_WINDOWS)
    recls::search_sequence files(
        winstl::a2t(searchRoot)
    ,   NULL
    ,   recls::RECURSIVE | recls::LINK_COUNT
    ,   &callback::function
    ,   &longest_dir
    );
#endif

#if !defined(PLATFORMSTL_OS_IS_WINDOWS)
    recls::search_sequence files(
        searchRoot
    ,   NULL
    ,   recls::RECURSIVE | recls::LINK_COUNT
    );
#endif

    { for (recls::search_sequence::const_iterator it = files.begin(); files.end() != it; ++it)
    {
        recls::entry const      e       =   *it;
        recls::uint32_t const   nlinks  =   static_cast<recls::uint32_t>(e.num_links());
        recls::uint64_t const   fsize   =   e.get_file_size();

        if (nlinks > 1)
        {
            std::cout
                << '\t'
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
                << winstl::t2a(e.get_path())
#else
                << e.get_path()
#endif
                << ": "
                << fsize
                << " bytes"
                << "; "
                << nlinks
                << " links"
                << std::endl
                ;
        }
    }}

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    winstl::diagnostics::output_debug_line("longest directory searched: '", longest_dir.c_str(), "' (", winstl::int_to_string<char>(longest_dir.size()), ")");
#endif

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
    sslice_t const program_name = platformstl::get_executable_name_from_path(argv[0]);

    try
    {
        return main_(program_name, argc, argv);
    }
    catch (std::bad_alloc&)
    {
        fprintf(stderr, "%.*s: out of memory\n", int(program_name.len), program_name.ptr);
    }
    catch (recls::recls_exception& x)
    {
        fprintf(stderr, "%.*s: %s\n", int(program_name.len), program_name.ptr, x.what());
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "%.*s: Unhandled exception (%s): %s\n", int(program_name.len), program_name.ptr, typeid(x).name(), x.what());
    }
    catch (...)
    {
        fputs("Unhandled unknown error\n", stderr);
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

