/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.squeeze_path.c
 *
 * Purpose:     Implementation file for the test.unit.api.squeeze_path project.
 *
 * Created:     13th December 2008
 * Updated:     30th December 2023
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
# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_WIDE_STRING_EQUAL
#else
# define XTESTS_TEST_STRING_EQUAL       XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void test_1_0(void);
static void test_1_1(void);
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

    if (XTESTS_START_RUNNER("test.unit.api.squeeze_path", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
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

static void test_1_0()
{
    recls_char_t    result[1];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL(""), NULL, 0);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), result);
}

static void test_1_1()
{
    recls_char_t    result[1];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL(""), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), result);
}

static void test_1_2()
{
    recls_char_t    result[11];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL(""), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(0u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(""), result);
}

static void test_1_3()
{
    recls_char_t    result[12];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(11u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def/ghi"), result);
}

static void test_1_4()
{
    recls_char_t    result[11];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(10u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc.../ghi"), result);
}

static void test_1_5()
{
    recls_char_t    result[10];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(9u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ab.../ghi"), result);
}

static void test_1_6()
{
    recls_char_t    result[9];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(8u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a.../ghi"), result);
}

static void test_1_7()
{
    recls_char_t    result[8];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(7u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL(".../ghi"), result);
}

static void test_1_8()
{
    recls_char_t    result[7];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), result);
}

static void test_1_9()
{
    recls_char_t    result[6];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), result);
}

static void test_1_10()
{
    recls_char_t    result[5];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), result);
}

static void test_1_11()
{
    recls_char_t    result[4];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(3u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("ghi"), result);
}

static void test_1_12()
{
    recls_char_t    result[3];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(2u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("gh"), result);
}

static void test_1_13()
{
    recls_char_t    result[2];
    size_t  cch = Recls_SqueezePath(RECLS_LITERAL("abc/def/ghi"), &result[0], STLSOFT_NUM_ELEMENTS(result) - 1);

    result[cch] = '\0';

    XTESTS_TEST_INTEGER_EQUAL(1u, cch);
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("g"), result);
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

