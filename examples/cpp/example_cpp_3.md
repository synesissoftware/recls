# recls Example - **example_cpp_3**

## Summary

Demonstrates use of `recls::stat()` on current directory or named path, showing various elements of the path in exploded form.


## Source

```C++
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_3/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - stat() of current directory (via recls::stat()) or named path
 *  - searching for files, according to multi-part pattern
 *  - recursive operation
 *  - evaluation of relative path of each entry, with respect to entry directory
 *  - handling exceptions and reporting of error information
 *  - elicitation of entry properties via method calls
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
#include <string>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    try
    {
        char const*     path    =   argc > 1 ? argv[1] : ".";

        std::cout << "  given path:       " << path << std::endl;

        std::cout << std::endl;

        // stat() the path
        recls::entry    entry    =   recls::stat(path, recls::DIRECTORY_PARTS);

        // Print out its characteristics:

        // full path
        std::cout << "  full path:        " << entry.get_path() << std::endl;

        // type
        std::cout << "  type:             ";
        if (entry.is_directory())
        {
            std::cout << "<directory>";
        }
        else
        if (entry.is_socket())
        {
            std::cout << "<socket>";
        }
        else
        {
            std::cout << "<file>";
        }
        if (entry.is_link())
        {
            std::cout << " <link>";
        }
        if (entry.is_readonly())
        {
            std::cout << " <read-only>";
        }
        std::cout << std::endl;

        // directory path
        std::cout << "  directory path:   " << entry.get_directory_path() << std::endl;

#ifdef RECLS_PLATFORM_API_WINDOWS

        // drive
        std::cout << "  drive:            " << entry.get_drive() << ':' << std::endl;

        // directory
        std::cout << "  directory:          " << entry.get_directory() << std::endl;
#else /* ? RECLS_PLATFORM_IS_WINDOWS */

        // directory
        std::cout << "  directory:        " << entry.get_directory() << std::endl;
#endif /* RECLS_PLATFORM_API_WINDOWS */

        // basename
        std::cout << "  basename:         " << std::string(entry.get_directory_path().size(), ' ') << entry.get_file() << std::endl;

        // stem
        std::cout << "  stem:             " << std::string(entry.get_directory_path().size(), ' ') << entry.get_file_name() << std::endl;

        // extension
        if (!entry.get_file_extension().empty())
        {
            std::cout << "  extension:        " << std::string(entry.get_directory_path().size() + entry.get_file_name().size(), ' ') << entry.get_file_extension() << std::endl;
        }

        // directory parts
        std::cout << "  directory parts:" << std::endl;
        unsigned n = 0;
        for (auto const& part : entry.get_directory_parts())
        {
            std::cout << "    part:           " << std::string(n, ' ') << part << std::endl;

            n += part.size();
        }

        // size
        //
        // We cast because some standard libraries cannot handle 64-bit
        // integers. If the file size exceeds that representable in 32-bits
        // then this will yield an invalid value; don't copy this into your
        // own code unless you are *totally* sure you'll never work with
        // files larger than 4GB in size.
        std::cout << "  size:             " << static_cast<unsigned long>(entry.get_size()) << " byte(s)" << std::endl;

        std::cout << std::endl;

        // search directory
        std::cout << "  search directory: " << entry.get_search_directory() << std::endl;

        // search-relative path
        std::cout << "  search-rel path:  " << entry.get_search_relative_path() << std::endl;
    }
    catch (recls::recls_exception& x)
    {
        std::cerr << "Could not elicit entry directory by stat()-ing '~': " << x.get_rc() << ", " << x.what() << std::endl;

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

This is effectively the same functionality as provided in **example_c_6**, but implemented in terms of the **recls/C++** API, which provides much more succinct syntax for the normative case (albeit the fully-exploded exception-handling as shown here can be quite verbose).


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/cpp/example_cpp_3/example_cpp_3 test
```

then it produces results such as:

```
  given path:       ./prepare_cmake.sh

  full path:        /Users/user/dev/synesissoftware/freelibs/recls/recls/prepare_cmake.sh
  type:             <file>
  directory path:   /Users/user/dev/synesissoftware/freelibs/recls/recls/
  directory:        /Users/user/dev/synesissoftware/freelibs/recls/recls/
  basename:                                                              prepare_cmake.sh
  stem:                                                                  prepare_cmake
  extension:                                                                          .sh
  directory parts:
    part:           /
    part:            Users/
    part:                  user/
    part:                       dev/
    part:                           synesissoftware/
    part:                                           freelibs/
    part:                                                    recls/
    part:                                                          recls/
  size:             3804 byte(s)

  search directory: /Users/user/dev/synesissoftware/freelibs/recls/recls/
  search-rel path:  prepare_cmake.sh
```


<!-- ########################### end of file ########################### -->

