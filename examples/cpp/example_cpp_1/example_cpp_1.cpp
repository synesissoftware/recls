/* /////////////////////////////////////////////////////////////////////////
 * File:        example_cpp_1.cpp
 *
 * Purpose:     C++ example program for recls/C++. Demonstrates:
 *
 *                - searching for files
 *                - recursive operation
 *                - display of full path of each entry
 *                - handling exceptions and reporting of error information
 *                - elicitation of entry properties via method calls
 *
 * Created:     18th June 2006
 * Updated:     10th January 2017
 *
 * www:         http://www.recls.org/
 *
 * License:     Copyright (c) 2006-2017, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              (Licensed under the Synesis Software Open License)
 *
 *              This source code is placed into the public domain 2006
 *              by Synesis Software Pty Ltd. There are no restrictions
 *              whatsoever to your use of the software.
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls Header Files */
#include <recls/recls.hpp>

/* Standard C++ Header Files */
#include <exception>
#include <iostream>

/* Standard C Header Files */
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define cout           wcout
# define cerr           wcerr
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

/* ////////////////////////////////////////////////////////////////////////// */

int main()
{
    try
    {
        int                     flags   =   recls::RECLS_F_FILES | recls::RECLS_F_RECURSIVE;
        recls::search_sequence  files(RECLS_LITERAL("."), recls::Recls_GetWildcardsAll(), flags);

        { for(recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry entry = *i;

            std::cout << entry.get_path() << std::endl;
        }}
    }
    catch(recls::recls_exception& x)
    {
        std::cerr << RECLS_LITERAL("Recls error: ") << x.get_rc() << RECLS_LITERAL(", ") << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch(std::bad_alloc &)
    {
        std::cerr << RECLS_LITERAL("Out of memory") << std::endl;

        return EXIT_FAILURE;
    }
    catch(std::exception &x)
    {
        std::cerr << RECLS_LITERAL("Unhandled error: ") << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch(...)
    {
        std::cerr << RECLS_LITERAL("Unhandled unknown error") << std::endl;

        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

/* ///////////////////////////// end of file //////////////////////////// */
