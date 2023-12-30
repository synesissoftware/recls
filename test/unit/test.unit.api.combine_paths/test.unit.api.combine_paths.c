/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.combine_paths.c
 *
 * Purpose:     Implementation file for the test.unit.api.combine_paths project.
 *
 * Created:     13th December 2008
 * Updated:     30th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <recls/recls.h>
#include <../src/impl.cover.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xCover Header Files */
#ifdef RECLS_QUALITY_USE_XCOVER
# include <xcover/xcover.h>
#endif /* RECLS_QUALITY_USE_XCOVER */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
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

#ifdef XCOVER_VER
static int main_xc(int argc, char** argv);
#endif /* XCOVER_VER */

int main(int argc, char** argv)
{
#ifdef XCOVER_VER
    xcover_rc_t const xcrc = xcover_init();

    if (xcrc < 0)
    {
        fprintf(stderr, "failed to initialise xCover : %s (%d)\n", xcover_getApiCodeString(xcrc), xcrc);

        return EXIT_FAILURE;
    }
    else
    {
        int r = main_xc(argc, argv);

        xcover_uninit();

        return r;
    }
}

static int main_xc(int argc, char** argv)
{
#endif /* XCOVER_VER */

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

#ifdef XCOVER_VER
        XCOVER_REPORT_GROUP_COVERAGE("recls.util.combine_paths", NULL);
#endif /* XCOVER_VER */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_measure_0()
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

static void test_measure_1()
{
    recls_char_t    result[101];
    size_t          cch = Recls_CombinePaths(NULL, RECLS_LITERAL(""), &result[0], STLSOFT_NUM_ELEMENTS(result));

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(0u, cch);
}

static void test_1_2()
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

static void test_1_3()
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

static void test_1_4()
{
}

static void test_1_5()
{
}

static void test_1_6()
{
}

static void test_1_7()
{
}

static void test_1_8()
{
}

static void test_1_9()
{
}

static void test_1_10()
{
}

static void test_1_11()
{
}

static void test_1_12()
{
}

static void test_1_13()
{
}

static void test_1_14()
{
}

static void test_1_15()
{
}

static void test_1_16()
{
}

static void test_1_17()
{
}

static void test_1_18()
{
}

static void test_1_19()
{
}


/* ///////////////////////////// end of file //////////////////////////// */

