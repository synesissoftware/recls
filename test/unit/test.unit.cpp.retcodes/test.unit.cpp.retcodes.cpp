/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.cpp.retcodes.cpp
 *
 * Purpose:     Implementation file for the test.unit.cpp.retcodes project.
 *
 * Created:     13th December 2008
 * Updated:     19th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <recls/recls.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#ifndef PANTHEIOS_DOCUMENTATION_SKIP_SECTION
# if defined(STLSOFT_COMPILER_IS_MSVC)
#  pragma warning(disable : 4702)
# endif /* compiler */
#endif /* !PANTHEIOS_DOCUMENTATION_SKIP_SECTION */

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

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER("test.unit.cpp.retcodes", verbosity))
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

#if 0
using recls::recls_rc_t;
using recls::RECLS_SUCCEEDED;
using recls::RECLS_FAILED;
#else /* ? 0 */
using namespace recls;
#endif /* 0 */

static recls_rc_t const s_FAILURE_CODES[] =
{
        RECLS_RC_FAIL

    ,   RECLS_RC_SEARCH_NO_CURRENT
    ,   RECLS_RC_PATH_IS_NOT_DIRECTORY
    ,   RECLS_RC_NO_MORE_DATA
    ,   RECLS_RC_OUT_OF_MEMORY
    ,   RECLS_RC_NOT_IMPLEMENTED
    ,   RECLS_RC_INVALID_SEARCH_TYPE
    ,   RECLS_RC_INVALID_SEARCH_PROTOCOL
    ,   RECLS_RC_UNEXPECTED
    ,   RECLS_RC_DOT_RECURSIVE_SEARCH
    ,   RECLS_RC_SEARCH_CANCELLED
    ,   RECLS_RC_FTP_INIT_FAILED
    ,   RECLS_RC_FTP_CONNECTION_FAILED
    ,   RECLS_RC_CANNOT_STAT_ROOT
    ,   RECLS_RC_PATH_LIMIT_EXCEEDED
    ,   RECLS_RC_USER_CANCELLED_SEARCH
    ,   RECLS_RC_NO_HOME
    ,   RECLS_RC_INVALID_NAME
    ,   RECLS_RC_ACCESS_DENIED
    ,   RECLS_RC_DIRECTORY_NOT_FOUND
    ,   RECLS_RC_ENTRY_IS_DIRECTORY
    ,   RECLS_RC_ENTRY_IS_NOT_DIRECTORY
};



static void test_1_0()
{
    XTESTS_TEST_BOOLEAN_TRUE(RECLS_SUCCEEDED(RECLS_RC_OK));
    XTESTS_TEST_BOOLEAN_FALSE(RECLS_FAILED(RECLS_RC_OK));
}

static void test_1_1()
{
    XTESTS_TEST_BOOLEAN_TRUE(RECLS_FAILED(RECLS_RC_FAIL));
    XTESTS_TEST_BOOLEAN_FALSE(RECLS_SUCCEEDED(RECLS_RC_FAIL));
}

static void test_1_2()
{
    { size_t i; for(i = 0; i != STLSOFT_NUM_ELEMENTS(s_FAILURE_CODES); ++i)
    {
        recls_rc_t const rc = s_FAILURE_CODES[i];

        XTESTS_TEST_BOOLEAN_TRUE(RECLS_FAILED(rc));
        XTESTS_TEST_BOOLEAN_FALSE(RECLS_SUCCEEDED(rc));
    }}
}

static void test_1_3()
{
    { size_t i; for(i = 0; i != 10000000; ++i)
    {
        union
        {
            recls_rc_t  rc;
            int         ints[4];
        } u;

        u.ints[0] = rand();
        u.ints[1] = rand();
        u.ints[2] = rand();
        u.ints[3] = rand();

        XTESTS_TEST_BOOLEAN_TRUE(RECLS_SUCCEEDED(u.rc));
        XTESTS_TEST_BOOLEAN_FALSE(RECLS_FAILED(u.rc));
    }}
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

