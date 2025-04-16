/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_1/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for files
 *  - search by recls::search_sequence
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry attribute method calls
 *
 * Created: 18th June 2006
 * Updated: 16th April 2025
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

int main(int argc, char* argv[])
{
    try
    {
        char const*             search_dir  =   argc > 1 ? argv[1] : ".";
        int                     flags       =   recls::RECLS_F_FILES | recls::RECLS_F_RECURSIVE;
        recls::search_sequence  files(search_dir, recls::wildcardsAll(), flags);

        { for (recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            std::cout << *i << std::endl;
        }}

        return EXIT_SUCCESS;
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Recls error: " << x.get_rc() << ", " << x.what() << std::endl;
    }
    catch (std::bad_alloc &)
    {
        std::cerr << "Out of memory" << std::endl;
    }
    catch (std::exception &x)
    {
        std::cerr << "Unhandled error: " << x.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unhandled unknown error" << std::endl;
    }

    return EXIT_FAILURE;
}


/* ///////////////////////////// end of file //////////////////////////// */

