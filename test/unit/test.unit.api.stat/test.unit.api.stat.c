/* /////////////////////////////////////////////////////////////////////////
 * File:        test.unit.api.stat.c
 *
 * Purpose:     Implementation file for the test.unit.api.stat project.
 *
 * Created:     13th December 2008
 * Updated:     22nd December 2020
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2020, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
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
#include <stdlib.h>
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
# define XTESTS_TEST_RECLS_STRING_EQUAL             XTESTS_TEST_WIDE_STRING_EQUAL
# define XTESTS_TEST_RECLS_STRING_EQUAL_APPROX      XTESTS_TEST_WIDE_STRING_EQUAL_APPROX
# define XTESTS_TEST_RECLS_STRING_EQUAL_N           XTESTS_TEST_WIDE_STRING_EQUAL_N
# define XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX    XTESTS_TEST_WIDE_STRING_EQUAL_N_APPROX
#elif defined(RECLS_CHAR_TYPE_IS_CHAR)
# define XTESTS_TEST_RECLS_STRING_EQUAL             XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_RECLS_STRING_EQUAL_APPROX      XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX
# define XTESTS_TEST_RECLS_STRING_EQUAL_N           XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX    XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX
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
recls_char_t*   s_home;
size_t          path_max;

static void finish_off_directory(recls_char_t* s)
{
    size_t n = strlen(s);

    if (n > 0)
    {
    }
}

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
#  define PATH_MAX  (1u + pathconf("/", _PC_PATH_MAX))
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


    if (XTESTS_START_RUNNER("test.unit.api.stat", verbosity))
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

static void test_1_0()
{
    recls_info_t    entry;
    recls_rc_t      rc = Recls_Stat("", 0, &entry);

    XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
}

static void test_1_1()
{
    recls_info_t    entry;
    recls_rc_t      rc = Recls_Stat(".", 0, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_APPROX(s_cwd, entry->path.begin);

#elif defined(PLATFORMSTL_OS_IS_UNIX)

        XTESTS_TEST_RECLS_STRING_EQUAL(s_cwd, entry->path.begin);
#else
# error platform not discriminated
#endif

        Recls_CloseDetails(entry);
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }
}

static void test_1_2()
{
    recls_info_t    entry;
    recls_rc_t      rc = Recls_Stat("~", 0, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_APPROX(s_home, entry->path.begin);

#elif defined(PLATFORMSTL_OS_IS_UNIX)

        XTESTS_TEST_RECLS_STRING_EQUAL(s_home, entry->path.begin);
#else
# error platform not discriminated
#endif

        Recls_CloseDetails(entry);
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }
}

static void test_1_3()
{
    recls_info_t    entry;
    recls_rc_t      rc = Recls_Stat("~", RECLS_F_MARK_DIRS, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX(s_home, entry->path.begin, strlen(s_home));

#elif defined(PLATFORMSTL_OS_IS_UNIX)

        XTESTS_TEST_RECLS_STRING_EQUAL_N(s_home, entry->path.begin, strlen(s_home));
#else
# error platform not discriminated
#endif

        Recls_CloseDetails(entry);
    }
    else
    {
        XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_OK, rc);
    }
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

