# recls Example - **example_cpp_3**

## Summary

T.B.C.


## Source

```C++
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_3/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *            - stat()-ing of current directory
 *            - searching for files, according to multi-part pattern
 *            - recursive operation
 *            - evaluation of relative path of each entry, with respect
 *              to home directory
 *            - handling exceptions and reporting of error information
 *            - elicitation of entry properties via method calls
 *
 * Created: 18th June 2006
 * Updated: 9th April 2025
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
 * macros and definitions
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define cout                                               wcout
# define cerr                                               wcerr
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

/* ////////////////////////////////////////////////////////////////////// */

int main(int /* argc */, char* /* argv */[])
{
    try
    {
        // stat() the current directory
        recls::entry  home = recls::stat(".");

        // Print out its characteristics:

        // 1. Full path
        std::cout << "path: " << home.get_path() << std::endl;

        // 2. Search-relative path
        std::cout << "search-relative path: " << home.get_search_relative_path() << std::endl;

        // 3. Search directory
        std::cout << "search directory: " << home.get_search_directory() << std::endl;

#ifdef RECLS_PLATFORM_API_WINDOWS
        // 4. Drive property
        std::cout << "drive: " << home.get_drive() << std::endl;
#endif /* RECLS_PLATFORM_API_WINDOWS */

        // 5. Directory path property
        std::cout << "directory path: " << home.get_directory_path() << std::endl;

        // 6. Directory property
        std::cout << "directory: " << home.get_directory() << std::endl;

        // 7. File property
        std::cout << "file: " << home.get_file() << std::endl;

        // 8. File name property
        std::cout << "file name: " << home.get_file_name() << std::endl;

        // 9. File extension property
        std::cout << "file extension: " << home.get_file_extension() << std::endl;

        // 10. Type
        if (home.is_directory())
        {
            std::cout << " <directory>" << std::endl;
        }
        else
        {
            std::cout << " <file>" << std::endl;
        }
        if (home.is_link())
        {
            std::cout << " <link>" << std::endl;
        }
        if (home.is_readonly())
        {
            std::cout << " <read-only>" << std::endl;
        }

        // 11. Size
        //
        // We cast because some standard libraries cannot handle 64-bit
        // integers. If the file size exceeds that representable in 32-bits
        // then this will yield an invalid value; don't copy this into your
        // own code unless you are *totally* sure you'll never work with
        // files larger than 4GB in size.
        std::cout << static_cast<unsigned long>(home.get_size()) << " bytes" << std::endl;
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Could not elicit home directory by stat()-ing '~': " << x.get_rc() << ", " << x.what() << std::endl;

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
```


## Discussion

T.B.C.


## Example results

```
```


<!-- ########################### end of file ########################### -->

