/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_1/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - searching for files
 *  - recursive operation
 *  - display of full path of each entry
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
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int /* argc */, char* /* argv */[])
{
    try
    {
        int                     flags   =   recls::RECLS_F_FILES | recls::RECLS_F_RECURSIVE;
        recls::search_sequence  files(".", recls::Recls_GetWildcardsAll(), flags);

        { for (recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry entry = *i;

            std::cout << entry.get_path() << std::endl;
        }}
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Recls error: " << x.get_rc() << ", " << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "Out of memory" << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::exception &x)
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

