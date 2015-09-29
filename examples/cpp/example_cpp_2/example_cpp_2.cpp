/* /////////////////////////////////////////////////////////////////////////
 * File:        example_cpp_2.cpp
 *
 * Purpose:     C++ example program for recls/C++. Demonstrates:
 *
 *                - stat()-ing of home directory
 *                - searching for files, according to multi-part pattern
 *                - recursive operation
 *                - evaluation of relative path of each entry, with respect
 *                  to home directory
 *                - handling exceptions and reporting of error information
 *                - elicitation of entry properties via method calls
 *
 * Created:     18th June 2006
 * Updated:     30th November 2011
 *
 * www:         http://www.recls.org/
 *
 * License:     Copyright (c) 2006-2011, Synesis Software Pty Ltd.
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
 * Macros and definitions
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
        /* stat() the home directory */
        recls::entry            home    =   recls::stat(RECLS_LITERAL("~"));

        /* Enumerate all under the current directory, matching *.??? or makefile*.*. */
        int                     flags   =   recls::RECLS_F_FILES | recls::RECLS_F_RECURSIVE;

#if defined(STLSOFT_COMPILER_IS_GCC) && \
    __GNUC__ < 4

        /* This is only for old GCC, and ... */
        recls::search_sequence  files(RECLS_LITERAL(""), RECLS_LITERAL("*.???|makefile|makefile.*|"), flags);

#else

        /* ... this is the way you can (and should) do it in everything else. */
        recls::search_sequence  files(NULL, RECLS_LITERAL("*.???|makefile|makefile.*|"), flags);

#endif

        { for(recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry        entry                   = *i;
            recls::string_t relativePath  = recls::derive_relative_path(home.get_path(), entry.get_path());

            std::cout << relativePath << std::endl;
        }}
    }
    catch(recls::recls_exception& x)
    {
        std::cerr << RECLS_LITERAL("Could not elicit home directory by stat()-ing '~': ") << x.get_rc() << ", " << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch(std::bad_alloc&)
    {
        std::cerr << RECLS_LITERAL("Out of memory") << std::endl;

        return EXIT_FAILURE;
    }
    catch(std::exception& x)
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
