/* /////////////////////////////////////////////////////////////////////////
 * File:        test.scratch.links.cpp
 *
 * Purpose:     Implementation file for the test.scratch.links project.
 *
 * Created:     23rd February 2011
 * Updated:     1st January 2021
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2011-2021, Synesis Software / Synesis Information Systems
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/recls.hpp>

/* STLSoft header files */
#include <platformstl/platformstl.h>

/* Standard C++ header files */
#include <exception>
#include <iostream>
#if 0
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#endif /* 0 */

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * globals
 */


/* /////////////////////////////////////////////////////////////////////////
 * typedefs
 */

#if 0
typedef char                        char_t;
typedef std::basic_string<char_t>   string_t;
#endif /* 0 */

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char** argv)
{
    recls::search_sequence files(NULL, NULL, recls::RECURSIVE | recls::LINK_COUNT);

    { for (recls::search_sequence::const_iterator it = files.begin(); files.end() != it; ++it)
    {
        std::cout
            << (*it).get_path()
            << ": "
            << unsigned((*it).get_file_size())
            << " bytes"
            << "; "
            << unsigned((*it).num_links())
            << " links"
            << std::endl;
    }}

    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)
        puts("test.scratch.links: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        return main_(argc, argv);
    }
    catch(std::bad_alloc&)
    {
        fputs("out of memory\n", stderr);
    }
    catch(std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());
    }
    catch(...)
    {
        fputs("Unhandled unknown error\n", stderr);
    }

    return EXIT_FAILURE;
}

/* ///////////////////////////// end of file //////////////////////////// */
