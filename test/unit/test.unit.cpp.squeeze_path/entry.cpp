/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.cpp.squeeze_path/entry.cpp
 *
 * Purpose: Test path-squeezing (via recls C++ API function
 *          `recls::squeeze_path()`).
 *
 * Created: 7th June 2008
 * Updated: 2nd May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <recls/recls.hpp>

/* /////////////////////////////////////
 * general includes
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

    if (XTESTS_START_RUNNER("test.unit.cpp.squeeze_path", verbosity))
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

static void test_1_0(void)
{
#if 0
#elif defined(RECLS_PLATFORM_IS_UNIX)

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(".../ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a.../ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ab.../ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc.../ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("abc/def/ghi"), 100));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/.../ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/a.../ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/ab.../ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc.../ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 14));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/ghi"), recls::squeeze_path(RECLS_LITERAL("/abc/def/ghi"), 100));

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("...\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a...\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ab...\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc...\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("abc\\def\\ghi"), 100));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\a...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\ab...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\abc...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 14));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\abc\\def\\ghi"), 100));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\...\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\a...\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\ab...\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc...\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 14));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 15));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 16));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("C:\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("C:\\abc\\def\\ghi"), 1100));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 0));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 1));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 2));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 3));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 4));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 5));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 6));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 7));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 8));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 9));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 10));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 11));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 12));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 13));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 14));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\a...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 15));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\ab...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 16));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\abc...\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 17));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 18));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 19));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 20));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), recls::squeeze_path(RECLS_LITERAL("\\\\host\\abc\\def\\ghi"), 1100));

//  recls::cpp::string_t    path    =   ;
#else /* ? OS */

# error Platform not recognised
#endif /* __SYNSOFT_VAL_OS_WIN16 */
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

