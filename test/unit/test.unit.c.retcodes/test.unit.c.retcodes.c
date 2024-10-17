/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.c.retcodes.c
 *
 * Purpose: Unit-test of recls status codes via C API.
 *
 * Created: 13th December 2008
 * Updated: 17th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#include <recls/recls.h>

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
 * forward declarations
 */

static void test_1_0(void);
static void test_1_1(void);
static void test_1_2(void);
static void test_1_3(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char* argv[])
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.c.retcodes", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_1_1);
        XTESTS_RUN_CASE(test_1_2);
        XTESTS_RUN_CASE(test_1_3);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

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



static void test_1_0(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(RECLS_SUCCEEDED(RECLS_RC_OK));
    XTESTS_TEST_BOOLEAN_FALSE(RECLS_FAILED(RECLS_RC_OK));
}

static void test_1_1(void)
{
    XTESTS_TEST_BOOLEAN_TRUE(RECLS_FAILED(RECLS_RC_FAIL));
    XTESTS_TEST_BOOLEAN_FALSE(RECLS_SUCCEEDED(RECLS_RC_FAIL));
}

static void test_1_2(void)
{
    { size_t i; for (i = 0; i != STLSOFT_NUM_ELEMENTS(s_FAILURE_CODES); ++i)
    {
        recls_rc_t const rc = s_FAILURE_CODES[i];

        XTESTS_TEST_BOOLEAN_TRUE(RECLS_FAILED(rc));
        XTESTS_TEST_BOOLEAN_FALSE(RECLS_SUCCEEDED(rc));
    }}
}

static void test_1_3(void)
{
    { size_t i; for (i = 0; i != 10000000; ++i)
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


/* ///////////////////////////// end of file //////////////////////////// */

