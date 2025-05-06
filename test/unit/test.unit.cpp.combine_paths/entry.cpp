/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.cpp.combine_paths/entry.cpp
 *
 * Purpose: Unit-test of recls C++ API function `recls::combine_paths()`.
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
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.cpp.combine_paths", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    using recls::recls_char_t;


static void test_1_0(void)
{
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

    // 1. CombinePaths

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc"), "def/"));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc/"), "def/"));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc"), "def/"));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc/"), "def/"));

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    // 1. CombinePaths

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc\\"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a\\b\\c\\def"), recls::combine_paths(RECLS_LITERAL("a\\b\\c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("\\def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def"), recls::combine_paths(RECLS_LITERAL("H:\\abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def"), recls::combine_paths(RECLS_LITERAL("H:\\abc\\"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def\\"), recls::combine_paths(RECLS_LITERAL("H:\\abc"), RECLS_LITERAL("def\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def\\"), recls::combine_paths(RECLS_LITERAL("H:\\abc\\"), RECLS_LITERAL("def\\")));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def"), recls::combine_paths(RECLS_LITERAL("H:/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def"), recls::combine_paths(RECLS_LITERAL("H:/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def/"), recls::combine_paths(RECLS_LITERAL("H:/abc"), RECLS_LITERAL("def/")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def/"), recls::combine_paths(RECLS_LITERAL("H:/abc/"), RECLS_LITERAL("def/")));

#else /* ? OS */

# error Platform not recognised
#endif /* __SYNSOFT_VAL_OS_WIN16 */
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

