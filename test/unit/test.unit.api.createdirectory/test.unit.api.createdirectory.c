/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.createdirectory.c
 *
 * Purpose:     Implementation file for the test.unit.api.createdirectory project.
 *
 * Created:     29th January 2009
 * Updated:     3rd August 2026
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
#include <platformstl/platformstl.h>

/* Standard C Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unistd.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <direct.h>
# include <windows.h>
#else
# error platform not discriminated
#endif

/* /////////////////////////////////////////////////////////////////////////
 * character encoding
 */

#if defined(RECLS_CHAR_TYPE_IS_WCHAR)
# define XTESTS_TEST_RECLS_STRING_EQUAL                     XTESTS_TEST_WIDE_STRING_EQUAL
# define XTESTS_TEST_RECLS_STRING_EQUAL_APPROX              XTESTS_TEST_WIDE_STRING_EQUAL_APPROX
# define XTESTS_TEST_RECLS_STRING_EQUAL_N                   XTESTS_TEST_WIDE_STRING_EQUAL_N
# define XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX            XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX
#elif defined(RECLS_CHAR_TYPE_IS_CHAR)
# define XTESTS_TEST_RECLS_STRING_EQUAL                     XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_RECLS_STRING_EQUAL_APPROX              XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX
# define XTESTS_TEST_RECLS_STRING_EQUAL_N                   XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX
#else
# error recls not discriminating correctly
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

recls_char_t*   s_cwd;
size_t          s_cwdLen;
recls_char_t*   s_home;
recls_char_t*   s_testRoot;
size_t          s_testRootLen;
size_t          path_max;

#define RECLS_TEST_DIR_LEAF                                 "recls_test_dir_root_D01441CA_A1CD_4916_B095_B2D65B15E517"

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))
    path_max = _MAX_PATH;
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# ifndef PATH_MAX
#  define PATH_MAX                                          (1u + pathconf("/", _PC_PATH_MAX))
# endif /* PATH_MAX */
    path_max = PATH_MAX;
#else
# error platform not discriminated
#endif
    s_cwd       =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));
    s_home      =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));
    s_testRoot  =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));

    if (NULL == s_cwd ||
        NULL == s_home ||
        NULL == s_testRoot)
    {
        fprintf(stderr, "Cannot allocate enough memory to run tests!\n");

        free(s_cwd);
        free(s_home);
        free(s_testRoot);

        return EXIT_FAILURE;
    }

    getcwd(s_cwd, 1 + path_max);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))
    strcpy(s_home, getenv("HOMEDRIVE"));
    strcat(s_home, getenv("HOMEPATH"));
#elif defined(PLATFORMSTL_OS_IS_UNIX)
    strcpy(s_home, getenv("HOME"));
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
#else
# error platform not discriminated
#endif

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
    { char* s; for(s = s_cwd; *s; ++s)
    {
        if ('\\' == *s)
        {
            *s = '/';
        }
    }}
    { char* s; for(s = s_home; *s; ++s)
    {
        if ('\\' == *s)
        {
            *s = '/';
        }
    }}
#endif

    s_cwdLen = strlen(s_cwd);

    /* Place under $HOME (1.10 uses "~/..."; 1.9 has no tilde expansion). */
    strcpy(s_testRoot, s_home);
#if defined(PLATFORMSTL_OS_IS_WINDOWS) && \
    !defined(PLATFORMSTL_OS_IS_UNIX)
    strcat(s_testRoot, "\\" RECLS_TEST_DIR_LEAF);
#else
    strcat(s_testRoot, "/" RECLS_TEST_DIR_LEAF);
#endif
    s_testRootLen = strlen(s_testRoot);

    if (XTESTS_START_RUNNER("test.unit.api.createdirectory", verbosity))
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

    free(s_cwd);
    free(s_home);
    free(s_testRoot);

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_1_0(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory("", &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory("", NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }
}

static void test_1_1(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(".", &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
        XTESTS_TEST_INTEGER_EQUAL(s_cwdLen, results.resultingLength);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(".", NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }
}

static void test_1_2(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(s_testRoot, &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
        XTESTS_TEST_INTEGER_EQUAL(s_testRootLen, results.resultingLength);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(s_testRoot, NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(s_testRoot, RECLS_REMDIR_F_REMOVE_FILES, NULL);
}

static void test_1_3(void)
{
#define TEST_1_3_SUBDIR                                     "/abc/def/ghi/jkl/mno"
#define TEST_1_3_SUBDIR_LEN                                 (STLSOFT_NUM_ELEMENTS(TEST_1_3_SUBDIR) - 1)

    recls_char_t* const path = (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + s_testRootLen + TEST_1_3_SUBDIR_LEN));
    size_t const        pathLen = s_testRootLen + TEST_1_3_SUBDIR_LEN;

    if (NULL == path)
    {
        XTESTS_TEST_FAIL("could not allocate path buffer");

        return;
    }

    strcpy(path, s_testRoot);
    strcat(path, TEST_1_3_SUBDIR);

    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(path, &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
        XTESTS_TEST_INTEGER_EQUAL(pathLen, results.resultingLength);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(path, NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(s_testRoot, RECLS_REMDIR_F_REMOVE_FILES | RECLS_REMDIR_F_REMOVE_READONLY, NULL);

    free(path);
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

