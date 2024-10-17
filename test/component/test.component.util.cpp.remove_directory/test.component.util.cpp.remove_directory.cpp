/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
 *
 * Purpose: Test removal of directories (via recls C++ API function
 *          `recls::remove_directory()`).
 *
 * Created: 30th January 2010
 * Updated: 17th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <recls/recls.h>
#endif

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

#ifdef __GNUC__
# include <platformstl/filesystem/path.hpp>
#endif

#include <recls/recls.hpp>

/* /////////////////////////////////////
 * general includes
 */

/* xTests header files */
#include <xtests/xtests.h>
#if _XTESTS_VER < 0x001204ff
# error Requires xTests 0.18.4 or later
#endif
#include <xtests/util/temp_directory.hpp>

/* STLSoft header files */
#include <platformstl/filesystem/directory_functions.hpp>
#include <platformstl/filesystem/path.hpp>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/conversion/char_conversions.hpp>
# define CONVERTER_m2t(s)   winstl::m2t(s)
#else
# define CONVERTER_m2t(s)   (s)
#endif

/* Standard C header files */
#include <stdlib.h>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

    static void test_1_0(void);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    static void test_1_1(void);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
    static void test_1_2(void);
    static void test_1_3(void);
    static void test_1_4(void);
    static void test_1_5(void);

    static int setup(void*);
    static int teardown(void*);
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

namespace
{

    using recls::recls_char_t;
    typedef platformstl::basic_path<recls_char_t>   path_t;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * Non-local static variables
 */

namespace
{

    path_t   temp_dir;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.util.cpp.remove_directory", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_1_0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        XTESTS_RUN_CASE_THAT_THROWS(test_1_1, recls::recls_exception);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);

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


static int setup(void*)
{
    using ::xtests::cpp::util::temp_directory;

    temp_directory td(temp_directory::EmptyOnOpen);

    temp_dir = path_t(CONVERTER_m2t(td.c_str()));

    return 0;
}

static int teardown(void*)
{
    if (!platformstl::filesystem_traits<recls_char_t>::remove_directory(temp_dir.c_str()))
    {
        platformstl::remove_directory_recurse(temp_dir);
    }

    return 0;
}


static void test_1_0(void)
{
    //recls::create_directory(".");

    XTESTS_TEST_PASSED();
}

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
static void test_1_1(void)
{
    recls::remove_directory(RECLS_LITERAL("|"));

    XTESTS_TEST_FAIL("should not get here");
}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

static void test_1_2(void)
{
    path_t path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    path_t path2remove(path);

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 1u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 4u, results.resultingLength);
}

static void test_1_3(void)
{
    path_t path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    path_t path2remove(path);

    path.push(RECLS_LITERAL("def"));

    if (!platformstl::create_directory_recurse(path))
    {
        XTESTS_TEST_FAIL_WITH_QUALIFIER("failed to create directory", path);
    }

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 2u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 8u, results.resultingLength);
}

static void test_1_4(void)
{
    path_t path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    path_t path2remove(path);

    path.push(RECLS_LITERAL("def"));
    path.push(RECLS_LITERAL("ghi"));
    path.push(RECLS_LITERAL("jkl"));

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 4u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 16u, results.resultingLength);
}

static void test_1_5(void)
{
    path_t path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    path_t path2remove(path);

    path.push(RECLS_LITERAL("def"));
    path.push(RECLS_LITERAL("ghi"));
    path.push(RECLS_LITERAL("jkl"));
    path.push(RECLS_LITERAL("mno"));
    path.push(RECLS_LITERAL("pqr"));

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 6u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 24u, results.resultingLength);
}

} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

