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
 * Updated: 22nd April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.hpp>

/* STLSoft C++ header files */
#include <platformstl/filesystem/path_functions.h>

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <string>

/* Standard C header files */
#include <stdlib.h>
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    stlsoft::string_slice_m_t program_name = platformstl::get_executable_name_from_path(argv[0]);

    for (int i = 1; i != argc; ++i)
    {
        if (0 == ::strcmp("--help", argv[i]))
        {
            std::cerr
                << "USAGE: "
                << program_name
                << " [ <path> [ <type-filter-number> ]]"
                << std::endl;

            return EXIT_SUCCESS;
        }
    }

    char const* path    =   argc > 1 ? argv[1] : ".";
    unsigned    flags   =   0;

    if (argc > 2)
    {
        char*   endptr;
        long    n = strtol(argv[2], &endptr, 0);

        if (0 == n)
        {
            if ('\0' != *endptr)
            {
                std::cerr
                    << program_name
                    << ": could not parse value "
                    << argv[2]
                    << " into recls flags; use --help for usage"
                    << std::endl;

                return EXIT_FAILURE;
            }
        }
        else
        {
            if (n < 0 || 0 != (n & ~recls::TYPEMASK))
            {
                std::cerr
                    << program_name
                    << ": invalid type selector value "
                    << n
                    << " into recls flags; use --help for usage"
                    << std::endl;

                return EXIT_FAILURE;
            }
            else
            {
                flags |= n;
            }
        }
    }

    flags |= recls::DIRECTORY_PARTS;

    try
    {
        std::cout << "  given path:       " << path << std::endl;

        std::cout << std::endl;

        // stat() the path
        recls::entry    entry    =   recls::stat(path, flags);

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
        std::cerr << program_name << ": could not elicit information by invoking `recls::stat()` on '" << path << "': " << x.what() << " (" << x.get_rc() << ")" << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::bad_alloc &)
    {
        std::cerr << program_name << ": out of memory" << std::endl;

        return EXIT_FAILURE;
    }
    catch (std::exception &x)
    {
        std::cerr << program_name << ": unhandled failure: " << x.what() << std::endl;

        return EXIT_FAILURE;
    }
    catch (...)
    {
        std::cerr << program_name << ": unhandled unknown error" << std::endl;

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

and when run with:

```
$ ./_build/examples/cpp/example_cpp_3/example_cpp_3 /tmp/mysql.sock
```

then it produces results such as:

```
  given path:       /tmp/mysql.sock

  full path:        /tmp/mysql.sock
  type:             <socket>
  directory path:   /tmp/
  directory:        /tmp/
  basename:              mysql.sock
  stem:                  mysql
  extension:                  .sock
  directory parts:
    part:           /
    part:            tmp/
  size:             0 byte(s)

  search directory: /tmp/
  search-rel path:  mysql.sock
```

and when run with:

```
$ ./_build/examples/cpp/example_cpp_3/example_cpp_3 /tmp/mysql.sock 16
```

then it produces results such as:

```
  given path:       /tmp/mysql.sock

  full path:        /tmp/mysql.sock
  type:             <socket>
  directory path:   /tmp/
  directory:        /tmp/
  basename:              mysql.sock
  stem:                  mysql
  extension:                  .sock
  directory parts:
    part:           /
    part:            tmp/
  size:             0 byte(s)

  search directory: /tmp/
  search-rel path:  mysql.sock
```

and when run with:

```
$ ./_build/examples/cpp/example_cpp_3/example_cpp_3 /tmp/mysql.sock 3
```

then it produces results such as:

```
  given path:       /tmp/mysql.sock

example_cpp_3: could not elicit information by invoking `recls::stat()` on '/tmp/mysql.sock': given path was a socket when one was not expected (0xfffffffffffffbfc)
```


<!-- ########################### end of file ########################### -->

