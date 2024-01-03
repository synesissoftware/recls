/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.stat.c
 *
 * Purpose: Implementation file for the test.unit.api.stat project.
 *
 * Created: 13th December 2008
 * Updated: 30th December 2023
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

static recls_char_t const s_nonexistent_file[] = RECLS_LITERAL("20101D98-B455-4e9d-AD7D-2C23FD2D63B1-60B3B24B-2AB6-4b44-B34D-A9FFDEBED982");
static recls_char_t const s_nonexistent_path[] = RECLS_LITERAL("9B810A5F-F664-4f93-BC7D-893304CD2F84-8584D8E5-1565-4aad-88F7-235FDD1E6330/20101D98-B455-4e9d-AD7D-2C23FD2D63B1-60B3B24B-2AB6-4b44-B34D-A9FFDEBED982");

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

static void test_2_0(void);
static void test_2_1(void);
static void test_2_2(void);
static void test_2_3(void);
static void test_2_4(void);
static void test_2_5(void);
static void test_2_6(void);
static void test_2_7(void);
static void test_2_8(void);
static void test_2_9(void);

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

recls_char_t*   s_cwd;
recls_char_t*   s_home;
size_t          path_max;

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1500
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

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

    _tgetcwd(s_cwd, ((int)(1 + path_max)));
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

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1500
# pragma warning(pop)
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

        XTESTS_RUN_CASE(test_2_0);
        XTESTS_RUN_CASE(test_2_1);
        XTESTS_RUN_CASE(test_2_2);
        XTESTS_RUN_CASE(test_2_3);
        XTESTS_RUN_CASE(test_2_4);
        XTESTS_RUN_CASE(test_2_5);
        XTESTS_RUN_CASE(test_2_6);
        XTESTS_RUN_CASE(test_2_7);
        XTESTS_RUN_CASE(test_2_8);
        XTESTS_RUN_CASE(test_2_9);

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
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL(""), flags, &entry);

    XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
}

static void test_1_1()
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("."), flags, &entry);

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
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("./"), flags, &entry);

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

static void test_1_3()
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~"), flags, &entry);

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

static void test_1_4()
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~/"), flags, &entry);

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

static void test_1_5()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_MARK_DIRS;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX(s_home, entry->path.begin, (int)_tcslen(s_home));

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

static void test_1_6()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_MARK_DIRS;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~/"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX(s_home, entry->path.begin, (int)_tcslen(s_home));

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
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_NO_MORE_DATA, rc));
}

static void test_1_12()
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        recls_char_t    expected[1001];

        _tcscpy(expected, s_cwd);
# if 0
# elif defined(PLATFORMSTL_OS_IS_UNIX)

        strcat(expected, "/");
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)

        _tcscat(expected, RECLS_LITERAL("\\"));
# else
#  error
# endif
        _tcscat(expected, s_nonexistent_file);

        XTESTS_TEST_RECLS_STRING_EQUAL_APPROX(expected, entry->path.begin);

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

static void test_1_13()
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            |   RECLS_F_FILES
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_NO_MORE_DATA, rc));
}

static void test_1_14()
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            |   RECLS_F_FILES
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_path, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_DIRECTORY_NOT_FOUND, rc));
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


static void test_2_0()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL(""), flags, &entry);

    XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
}

static void test_2_1()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("."), flags, &entry);

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

static void test_2_2()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("./"), flags, &entry);

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

static void test_2_3()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~"), flags, &entry);

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

static void test_2_4()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~/"), flags, &entry);

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

static void test_2_5()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER | RECLS_F_MARK_DIRS;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX(s_home, entry->path.begin, (int)_tcslen(s_home));

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

static void test_2_6()
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER | RECLS_F_MARK_DIRS;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("~/"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the home directory */
#if defined(PLATFORMSTL_OS_IS_WINDOWS) || \
    (   defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

        XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX(s_home, entry->path.begin, (int)_tcslen(s_home));

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

static void test_2_7()
{
}

static void test_2_8()
{
}

static void test_2_9()
{
}


/* ///////////////////////////// end of file //////////////////////////// */

