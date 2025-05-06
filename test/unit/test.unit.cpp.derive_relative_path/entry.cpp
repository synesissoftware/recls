/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.cpp.derive_relative_path/entry.cpp
 *
 * Purpose: Unit-test of recls C++ API function `recls::derive_relative_path()`.
 *
 * Created: 7th June 2008
 * Updated: 2nd May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <recls/recls.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_0(void);
    static void test_1_1(void);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.cpp.derive_relative_path", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

#if 0
static void run_unittests()
{
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

    // 1. combine_paths

    // 2. squeeze_path

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL(".../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("a.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("ab.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("abc.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 100));

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("/.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("/a.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("/ab.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("/abc.../ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("/abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("/abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("/abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 14));
    RECLS_ASSERT(RECLS_LITERAL("/abc/def/ghi") == recls::stl::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 100));

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    // 1. combine_paths

    RECLS_ASSERT(RECLS_LITERAL("abc\\def") == recls::stl::combine_paths("abc"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("abc\\def") == recls::stl::combine_paths("abc\\"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("a\\b\\c\\def") == recls::stl::combine_paths("a\\b\\c"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("abc") == recls::stl::combine_paths("abc", RECLS_LITERAL("")));
    RECLS_ASSERT(RECLS_LITERAL("def") == recls::stl::combine_paths(RECLS_LITERAL(""), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("\\def") == recls::stl::combine_paths("abc"), RECLS_LITERAL("\\def")));
    RECLS_ASSERT(RECLS_LITERAL("H:\\abc\\def") == recls::stl::combine_paths("H:\\abc"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("H:\\abc\\def") == recls::stl::combine_paths("H:\\abc\\"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("H:\\abc\\def\\") == recls::stl::combine_paths("H:\\abc"), RECLS_LITERAL("def\\")));
    RECLS_ASSERT(RECLS_LITERAL("H:\\abc\\def\\") == recls::stl::combine_paths("H:\\abc\\"), RECLS_LITERAL("def\\")));

    RECLS_ASSERT(RECLS_LITERAL("abc\\def") == recls::stl::combine_paths("abc"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("abc/def") == recls::stl::combine_paths("abc/"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("a/b/c/def") == recls::stl::combine_paths("a/b/c"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("abc") == recls::stl::combine_paths("abc", RECLS_LITERAL("")));
    RECLS_ASSERT(RECLS_LITERAL("def") == recls::stl::combine_paths(RECLS_LITERAL(""), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("/def") == recls::stl::combine_paths("abc"), RECLS_LITERAL("/def")));
    RECLS_ASSERT(RECLS_LITERAL("H:/abc/def") == recls::stl::combine_paths("H:/abc"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("H:/abc/def") == recls::stl::combine_paths("H:/abc/"), RECLS_LITERAL("def")));
    RECLS_ASSERT(RECLS_LITERAL("H:/abc/def/") == recls::stl::combine_paths("H:/abc"), RECLS_LITERAL("def/")));
    RECLS_ASSERT(RECLS_LITERAL("H:/abc/def/") == recls::stl::combine_paths("H:/abc/"), RECLS_LITERAL("def/")));

    // 2. squeeze_path

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL("...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("a...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("ab...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("abc...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 100));

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("\\...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("\\a...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("\\ab...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("\\abc...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 14));
    RECLS_ASSERT(RECLS_LITERAL("\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 100));

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("C:\\...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("C:\\a...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("C:\\ab...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("C:\\abc...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("C:\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 14));
    RECLS_ASSERT(RECLS_LITERAL("C:\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 15));
    RECLS_ASSERT(RECLS_LITERAL("C:\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 16));
    RECLS_ASSERT(RECLS_LITERAL("C:\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 1100));

    RECLS_ASSERT(RECLS_LITERAL("") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 0));
    RECLS_ASSERT(RECLS_LITERAL("g") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 1));
    RECLS_ASSERT(RECLS_LITERAL("gh") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 2));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 3));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 4));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 5));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 6));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 7));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 8));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 9));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 10));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 11));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 12));
    RECLS_ASSERT(RECLS_LITERAL("ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 13));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 14));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\a...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 15));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\ab...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 16));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\abc...\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 17));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 18));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 19));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 20));
    RECLS_ASSERT(RECLS_LITERAL("\\\\host\\abc\\def\\ghi") == recls::stl::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 1100));

    // 3. Relative path
    RECLS_ASSERT(RECLS_LITERAL("..\\ghi") == recls::stl::derive_relative_path(RECLS_LITERAL("/abc/def"), RECLS_LITERAL("/abc/ghi")));
    RECLS_ASSERT(RECLS_LITERAL("..\\defghi") == recls::stl::derive_relative_path(RECLS_LITERAL("h:\\abc\\def"), RECLS_LITERAL("H:\\abc\\defghi")));

    RECLS_ASSERT(RECLS_LITERAL("C:\\abc\\defghi") == recls::stl::derive_relative_path(RECLS_LITERAL("h:\\abc\\def"), RECLS_LITERAL("C:\\abc\\defghi")));

    ::SetCurrentDirectoryA("C:\\");
    RECLS_ASSERT(RECLS_LITERAL("..\\defghi") == recls::stl::derive_relative_path(RECLS_LITERAL("abc\\def"), RECLS_LITERAL("C:\\abc\\defghi")));
    RECLS_ASSERT(RECLS_LITERAL("H:\\abc\\defghi") == recls::stl::derive_relative_path(RECLS_LITERAL(""), RECLS_LITERAL("H:\\abc\\defghi")));
    RECLS_ASSERT(RECLS_LITERAL("abc\\defghi") == recls::stl::derive_relative_path(RECLS_LITERAL(""), RECLS_LITERAL("C:\\abc\\defghi")));


//  RECLS_ASSERT(RECLS_LITERAL("def"
    RECLS_ASSERT(RECLS_LITERAL("def") == recls::stl::derive_relative_path(RECLS_LITERAL("."), RECLS_LITERAL("def")));

    RECLS_ASSERT(RECLS_LITERAL("..\\..\\lib\\recls") == recls::stl::derive_relative_path(RECLS_LITERAL("/usr/include/recls"), RECLS_LITERAL("/usr/lib/recls")));

    RECLS_ASSERT(RECLS_LITERAL("..\\def") == recls::stl::derive_relative_path(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));


//  recls::cpp::string_t    path    =   ;
#else /* ? OS */

# error Platform not recognised
#endif /* OS */
}
#endif /* 0 */


namespace
{

static void test_1_0(void)
{
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\ghi"), recls::derive_relative_path(RECLS_LITERAL("/abc/def"), RECLS_LITERAL("/abc/ghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\defghi"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def"), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\defghi\\"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def"), RECLS_LITERAL("H:\\abc\\defghi\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\defghi"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\"), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\defghi\\"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\"), RECLS_LITERAL("H:\\abc\\defghi\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\..\\defghi"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\ghi"), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\..\\defghi\\"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\ghi"), RECLS_LITERAL("H:\\abc\\defghi\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\..\\defghi"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\ghi\\"), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\..\\defghi\\"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def\\ghi\\"), RECLS_LITERAL("H:\\abc\\defghi\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("defghi"), recls::derive_relative_path(RECLS_LITERAL("C:\\abc\\"), RECLS_LITERAL("C:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("defghi\\"), recls::derive_relative_path(RECLS_LITERAL("C:\\abc\\"), RECLS_LITERAL("C:\\abc\\defghi\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("defghi"), recls::derive_relative_path(RECLS_LITERAL("C:\\abc"), RECLS_LITERAL("C:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("defghi\\"), recls::derive_relative_path(RECLS_LITERAL("C:\\abc"), RECLS_LITERAL("C:\\abc\\defghi\\")));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\defghi"), recls::derive_relative_path(RECLS_LITERAL("h:\\abc\\def"), RECLS_LITERAL("C:\\abc\\defghi")));

    ::SetCurrentDirectoryA("C:\\");
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\defghi"), recls::derive_relative_path(RECLS_LITERAL("abc\\def"), RECLS_LITERAL("C:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\defghi"), recls::derive_relative_path(RECLS_LITERAL(""), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\defghi"), recls::derive_relative_path(RECLS_LITERAL(""), RECLS_LITERAL("C:\\abc\\defghi")));


//  XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::derive_relative_path(RECLS_LITERAL("."), RECLS_LITERAL("def")));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\..\\lib\\recls"), recls::derive_relative_path(RECLS_LITERAL("/usr/include/recls"), RECLS_LITERAL("/usr/lib/recls")));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("..\\def"), recls::derive_relative_path(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));


//  recls::cpp::string_t    path    =   ;
#else /* ? OS */

# error Platform not recognised
#endif /* OS */
}

static void test_1_1(void)
{
#ifdef RECLS_PLATFORM_IS_WINDOWS

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\defghi"), recls::derive_relative_path(RECLS_LITERAL("C:\\"), RECLS_LITERAL("H:\\abc\\defghi")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\defghi"), recls::derive_relative_path(RECLS_LITERAL("C:\\"), RECLS_LITERAL("C:\\abc\\defghi")));
#endif /* OS */
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

