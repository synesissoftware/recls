# recls - Example - **example_cpp_2**

## Summary

Demonstrates recursive search for all files under the home directory matching a multi-part pattern.


## Source

```C++
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_2/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - stat()-ing of home directory
 *  - searching for files and sockets, according to multi-part pattern
 *  - recursive operation
 *  - evaluation of relative path of each entry, with respect to home directory
 *  - handling exceptions and reporting of error information
 *  - elicitation of entry properties via method calls
 *
 * Created: 18th June 2006
 * Updated: 2nd May 2025
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
    const recls::char_t  SEARCH_PATTERN[]   =   "*.?pp|CMakeLists.*|";

    try
    {
        /* stat() the home directory */
        recls::entry            home    =   recls::stat("~");

        /* Enumerate all under the home directory, matching *.??? or makefile*.*. */
        int                     flags   =   recls::RECURSIVE | recls::FILES | recls::SOCKETS;

        recls::search_sequence  files(home, SEARCH_PATTERN, flags);
        recls::uint64_t         n_found =   0;

        /* and display each entry's search-relative path */
        { for (recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry        entry           =   *i;
            recls::string_t     relativePath    =   entry.get_search_relative_path();

            std::cout << relativePath << ' ' << entry.get_size() << std::endl;

            ++n_found;
        }}

        std::cout << '\t' << n_found << " item(s) found" << std::endl;

        return EXIT_SUCCESS;
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Could not elicit home directory by stat()-ing '~': " << x.get_rc() << ", " << x.what() << std::endl;
    }
    catch (std::bad_alloc&)
    {
        std::cerr << "Out of memory" << std::endl;
    }
    catch (std::exception& x)
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
```


## Discussion

The entry for the home directory is obtained via `recls::stat()`, which may then be passed to `recls::search_sequence()` along with the patterns and flags.

In the processing loop, as each matching entry is obtained its search-relative path and size are written to standard output stream.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/cpp/example_cpp_2/example_cpp_2
```

then it produces results such as:

```
temp/Catch2/CMakeLists.txt 7083
temp/Catch2/tools/misc/coverage-helper.cpp 3997
temp/Catch2/tools/misc/CMakeLists.txt 416
temp/Catch2/fuzzing/NullOStream.cpp 475
temp/Catch2/fuzzing/fuzz_TestSpecParser.cpp 593
temp/Catch2/fuzzing/fuzz_XmlWriter.cpp 547
temp/Catch2/fuzzing/fuzz_textflow.cpp 1347
temp/Catch2/fuzzing/CMakeLists.txt 753
temp/Catch2/tests/CMakeLists.txt 26260
temp/Catch2/tests/TestScripts/DiscoverTests/register-tests.cpp 678
temp/Catch2/tests/TestScripts/DiscoverTests/CMakeLists.txt 295
temp/Catch2/tests/SelfTest/TestRegistrations.cpp 6734
temp/Catch2/tests/SelfTest/IntrospectiveTests/Algorithms.tests.cpp 3552
temp/Catch2/tests/SelfTest/IntrospectiveTests/AssertionHandler.tests.cpp 539
temp/Catch2/tests/SelfTest/IntrospectiveTests/Clara.tests.cpp 2993
temp/Catch2/tests/SelfTest/IntrospectiveTests/CmdLine.tests.cpp 15944
temp/Catch2/tests/SelfTest/IntrospectiveTests/CmdLineHelpers.tests.cpp 4878
temp/Catch2/tests/SelfTest/IntrospectiveTests/ColourImpl.tests.cpp 1944
. . .
```


<!-- ########################### end of file ########################### -->

