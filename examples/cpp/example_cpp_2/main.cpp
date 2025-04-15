/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_2/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - stat()-ing of home directory
 *  - searching for files, according to multi-part pattern
 *  - recursive operation
 *  - evaluation of relative path of each entry, with respect to home directory
 *  - handling exceptions and reporting of error information
 *  - elicitation of entry properties via method calls
 *
 * Created: 18th June 2006
 * Updated: 15th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.hpp>

/* Standard C++ header files */
#include <exception>
#include <iostream>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    try
    {
        /* stat() the home directory */
        recls::entry            home    =   recls::stat("~");

        /* Enumerate all under the home directory, matching *.??? or makefile*.*. */
        int                     flags   =   recls::RECLS_F_FILES | recls::RECLS_F_RECURSIVE;

        recls::search_sequence  files(home, "*.?????|makefile|makefile.*|", flags);

        /* and display each entry's search-relative path */
        { for (recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry        entry           =   *i;
            recls::string_t     relativePath    =   entry.get_search_relative_path();

            std::cout << relativePath << std::endl;
        }}
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Could not elicit home directory by stat()-ing '~': " << x.get_rc() << ", " << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::bad_alloc&)
    {
        std::cerr << "Out of memory" << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::exception& x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

