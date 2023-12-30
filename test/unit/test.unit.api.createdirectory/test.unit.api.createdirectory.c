/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.createdirectory.c
 *
 * Purpose:     Implementation file for the test.unit.api.createdirectory project.
 *
 * Created:     29th January 2009
 * Updated:     30th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#include <recls/recls.h>

/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* xTests header files */
#include <xtests/xtests.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>
#include <platformstl/platformstl.h>

/* Standard C header files */
#include <stdlib.h>
#if 0
#elif defined(STLSOFT_COMPILER_IS_MSVC) && \
      defined(_WIN32)
# include <direct.h>
# include <tchar.h>
#endif
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
# include <unistd.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <windows.h>
#else
# error platform not discriminated
#endif

/* /////////////////////////////////////////////////////////////////////////
 * compatibility
 */

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1200

# pragma warning(disable : 4996)
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
size_t          path_max;

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
    s_cwd   =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));
    s_home  =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));

    if (NULL == s_cwd ||
        NULL == s_home)
    {
        fprintf(stderr, "Cannot allocate enough memory to run tests!\n");

        return EXIT_FAILURE;
    }

    _tgetcwd(s_cwd, (int)(1 + path_max));
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))
    _tcscpy(s_home, _tgetenv(RECLS_LITERAL("HOMEDRIVE")));
    _tcscat(s_home, _tgetenv(RECLS_LITERAL("HOMEPATH")));
#elif defined(PLATFORMSTL_OS_IS_UNIX)
    strcpy(s_home, getenv("HOME"));
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
#else
# error platform not discriminated
#endif

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
    { char* s; for (s = s_cwd; *s; ++s)
    {
        if ('\\' == *s)
        {
            *s = '/';
        }
    }}
    { char* s; for (s = s_home; *s; ++s)
    {
        if ('\\' == *s)
        {
            *s = '/';
        }
    }}
#endif

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

    s_cwdLen = _tcslen(s_cwd);
#else

    s_cwdLen = strlen(s_cwd);
#endif

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

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

#define RECLS_TEST_DIR_ROOT                                 RECLS_LITERAL("/recls_test_dir_root_D01441CA_A1CD_4916_B095_B2D65B15E517")
#define RECLS_TEST_DIR_ROOT_LEN_                            ((STLSOFT_NUM_ELEMENTS(RECLS_TEST_DIR_ROOT) - 1))
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# define RECLS_TEST_DIR_ROOT_LEN                            (2u + RECLS_TEST_DIR_ROOT_LEN_)
#else
# define RECLS_TEST_DIR_ROOT_LEN                            RECLS_TEST_DIR_ROOT_LEN_
#endif


static void test_1_0()
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_LITERAL(""), &results);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_LITERAL(""), NULL);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }
}

static void test_1_1()
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_LITERAL("."), &results);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
        XTESTS_TEST_INTEGER_EQUAL(s_cwdLen, results.resultingLength);
        XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements, results.numResultingElements);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_LITERAL("."), NULL);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }
}

static void test_1_2()
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT, &results);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)

        XTESTS_TEST_INTEGER_EQUAL(RECLS_TEST_DIR_ROOT_LEN + 2, results.resultingLength);
#else

        XTESTS_TEST_INTEGER_EQUAL(RECLS_TEST_DIR_ROOT_LEN, results.resultingLength);
#endif
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT, NULL);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(RECLS_TEST_DIR_ROOT, RECLS_REMDIR_F_REMOVE_FILES, NULL);
}

static void test_1_3()
{
#define TEST_1_3_SUBDIR                                     RECLS_LITERAL("/abc/def/ghi/jkl/mno")
#define TEST_1_3_SUBDIR_LEN                                 (STLSOFT_NUM_ELEMENTS(TEST_1_3_SUBDIR) - 1)

    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT TEST_1_3_SUBDIR, &results);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)

        XTESTS_TEST_INTEGER_EQUAL(RECLS_TEST_DIR_ROOT_LEN + TEST_1_3_SUBDIR_LEN + 2, results.resultingLength);
#else

        XTESTS_TEST_INTEGER_EQUAL(RECLS_TEST_DIR_ROOT_LEN + TEST_1_3_SUBDIR_LEN, results.resultingLength);
#endif
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT TEST_1_3_SUBDIR, NULL);

        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(RECLS_TEST_DIR_ROOT, RECLS_REMDIR_F_REMOVE_FILES | RECLS_REMDIR_F_REMOVE_READONLY, NULL);
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

