# recls Example - **example_cpp_1**

## Summary

Demonstrates recursive search for all files under a given directory including all appropriate failure handling.


## Source

```C++
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/cpp/example_cpp_1/main.cpp
 *
 * Purpose: C++ example program for recls/C++. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for files and sockets
 *  - search by recls::search_sequence
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry attribute method calls
 *
 * Created: 18th June 2006
 * Updated: 1st May 2025
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
        int                     flags       =   recls::RECURSIVE | recls::FILES | recls::SOCKETS;
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
```


## Discussion

This is effectively the same functionality as provided in **example_c_1**, but implemented in terms of the **recls/C++** API, which provides much more succinct syntax for the normative case (albeit the fully-exploded exception-handling as shown here can be quite verbose).

Note that the expression `*i` is of type `recls::entry`, which is directly insertable into the stream statement in the form of the full path. It could be equivalently expressed as:

```C++
        { for (recls::search_sequence::const_iterator i = files.begin(); i != files.end(); ++i)
        {
            recls::entry const entry = *i;

            std::cout << entry.get_path() << std::endl;
        }}
```


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/cpp/example_cpp_1/example_cpp_1 test
```

then it produces results such as:

```
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.util.file_sizes/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.util.file_sizes/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/entry.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/test.scratch.with_pantheios.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/test.scratch.cpp_api.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/test.scratch.search.1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/test_c_1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/CMakeLists.txt
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/test.scratch.links.cpp
```


<!-- ########################### end of file ########################### -->

