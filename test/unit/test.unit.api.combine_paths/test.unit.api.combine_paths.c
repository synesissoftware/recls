/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.combine_paths.c
 *
 * Purpose: Unit-test of recls C API function `Recls_CombinePaths()`.
 *
 * Created: 13th December 2008
 * Updated: 8th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <recls/recls.h>

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

static void test_measure_0(void);
static void test_measure_1(void);
static void test_1_2(void);
static void test_1_3(void);
static void test_1_4(void);
static void test_1_5(void);
static void test_1_6(void);
static void test_1_7(void);
static void test_1_8(void);
static void test_1_9(void);
static void test_1_10(void);
static void test_1_11(void);
static void test_1_12(void);
static void test_1_13(void);
static void test_1_14(void);
static void test_1_15(void);
static void test_1_16(void);
static void test_1_17(void);
static void test_1_18(void);
static void test_1_19(void);

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char** argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.api.combine_paths", verbosity))
    {
        XTESTS_RUN_CASE(test_measure_0);
        XTESTS_RUN_CASE(test_measure_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);
        XTESTS_RUN_CASE(test_1_4);
        XTESTS_RUN_CASE(test_1_5);
        XTESTS_RUN_CASE(test_1_6);
        XTESTS_RUN_CASE(test_1_7);
        XTESTS_RUN_CASE(test_1_8);
        XTESTS_RUN_CASE(test_1_9);
        XTESTS_RUN_CASE(test_1_10);
        XTESTS_RUN_CASE(test_1_11);
        XTESTS_RUN_CASE(test_1_12);
        XTESTS_RUN_CASE(test_1_13);
        XTESTS_RUN_CASE(test_1_14);
        XTESTS_RUN_CASE(test_1_15);
        XTESTS_RUN_CASE(test_1_16);
        XTESTS_RUN_CASE(test_1_17);
        XTESTS_RUN_CASE(test_1_18);
        XTESTS_RUN_CASE(test_1_19);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_measure_0(void)
{
    {
        size_t  cch = Recls_CombinePaths(RECLS_LITERAL(""), NULL, NULL, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        size_t  cch = Recls_CombinePaths(NULL, RECLS_LITERAL(""), NULL, 0);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        size_t  cch = Recls_CombinePaths(RECLS_LITERAL(""), NULL, NULL, 100);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }

    {
        size_t  cch = Recls_CombinePaths(NULL, RECLS_LITERAL(""), NULL, 100);

        XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    }
}

static void test_measure_1(void)
{
    recls_char_t    result[101];
    size_t          cch = Recls_CombinePaths(NULL, RECLS_LITERAL(""), &result[0], STLSOFT_NUM_ELEMENTS(result));

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(0u, cch);
}

static void test_1_2(void)
{
    {
        recls_char_t    result[101];
        size_t          cch = Recls_CombinePaths(NULL, RECLS_LITERAL("abc"), &result[0], STLSOFT_NUM_ELEMENTS(result));

        result[cch] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(3u, cch);
        XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), result);
    }

    {
        recls_char_t    result[101];
        size_t          cch = Recls_CombinePaths(RECLS_LITERAL("abc"), NULL, &result[0], STLSOFT_NUM_ELEMENTS(result));

        result[cch] = '\0';

        XTESTS_TEST_INTEGER_EQUAL(3u, cch);
        XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), result);
    }
}

static void test_1_3(void)
{
    recls_char_t    result[101];
    size_t          cch = Recls_CombinePaths(RECLS_LITERAL("abc"), RECLS_LITERAL("def"), &result[0], STLSOFT_NUM_ELEMENTS(result));

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(7u, cch);
#if defined(RECLS_PLATFORM_IS_UNIX)
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), result);
#elif defined(RECLS_PLATFORM_IS_WINDOWS)
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), result);
#endif
}

static void test_1_4(void)
{
}

static void test_1_5(void)
{
}

static void test_1_6(void)
{
}

static void test_1_7(void)
{
}

static void test_1_8(void)
{
}

static void test_1_9(void)
{
}

static void test_1_10(void)
{
}

static void test_1_11(void)
{
}

static void test_1_12(void)
{
}

static void test_1_13(void)
{
}

static void test_1_14(void)
{
}

static void test_1_15(void)
{
}

static void test_1_16(void)
{
}

static void test_1_17(void)
{
}

static void test_1_18(void)
{
}

static void test_1_19(void)
{
}

/* ///////////////////////////// end of file //////////////////////////// */

