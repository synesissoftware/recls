/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.stat.c
 *
 * Purpose: Test stat functionality of recls C API function `Recls_Stat()`.
 *
 * Created: 13th December 2008
 * Updated: 9th July 2024
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
#include <platformstl/filesystem/path_functions.h>
#include <platformstl/system/directory_functions.h>

/* Standard C header files */
#include <errno.h>
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

#if 0
#elif defined (PLATFORMSTL_OS_IS_UNIX)

# define this_getcwd                                        getcwd
#elif defined (PLATFORMSTL_OS_IS_WINDOWS)

# define this_getcwd                                        _tgetcwd
#else

# error platform not discriminated
#endif

#if 0
#elif defined(PLATFORMSTL_OS_IS_WINDOWS) || \
      ( defined(PLATFORMSTL_OS_IS_UNIX) && \
        defined(_WIN32))

# define THIS_MAX_PATH                                      _MAX_PATH
#elif defined(PLATFORMSTL_OS_IS_UNIX)

# ifdef PATH_MAX

#  define THIS_MAX_PATH                                     PATH_MAX
# else

#  define THIS_MAX_PATH                                     (1u + pathconf("/", _PC_PATH_MAX))
# endif /* PATH_MAX */
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
# define platformstl_C_get_home_directory                   platformstl_C_get_home_directory_w
#elif defined(RECLS_CHAR_TYPE_IS_CHAR)

# define XTESTS_TEST_RECLS_STRING_EQUAL                     XTESTS_TEST_MULTIBYTE_STRING_EQUAL
# define XTESTS_TEST_RECLS_STRING_EQUAL_APPROX              XTESTS_TEST_MULTIBYTE_STRING_EQUAL_APPROX
# define XTESTS_TEST_RECLS_STRING_EQUAL_N                   XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N
# define XTESTS_TEST_RECLS_STRING_EQUAL_N_APPROX            XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N_APPROX
# define platformstl_C_get_home_directory                   platformstl_C_get_home_directory_a
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
static void test_stat_dot(void);
static void test_stat_dot_slash(void);
static void test_stat_tilde(void);
static void test_stat_tilde_slash(void);
static void test_stat_tilde_MARK_DIRS(void);
static void test_stat_tilde_slash_MARK_DIRS(void);
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
size_t          s_cwdLen;
recls_char_t*   s_home;
size_t          s_cwdHome;
size_t          path_max;

static int main_(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.api.stat", verbosity))
    {
        XTESTS_RUN_CASE(test_1_0);
        XTESTS_RUN_CASE(test_stat_dot);
        XTESTS_RUN_CASE(test_stat_dot_slash);
        XTESTS_RUN_CASE(test_stat_tilde);
        XTESTS_RUN_CASE(test_stat_tilde_slash);
        XTESTS_RUN_CASE(test_stat_tilde_MARK_DIRS);
        XTESTS_RUN_CASE(test_stat_tilde_slash_MARK_DIRS);
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

    return retCode;
}

int main(int argc, char **argv)
{
    int r;

    char const* const program_name = platformstl_C_get_executable_name_from_path(argv[0]).ptr;

    path_max = THIS_MAX_PATH;

    s_cwd   =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));
    s_home  =   (recls_char_t*)malloc(sizeof(recls_char_t) * (1 + path_max));

    if (NULL == s_cwd ||
        NULL == s_home)
    {
        fprintf(stderr, "%s: cannot allocate enough memory to run tests\n", program_name);

        r = EXIT_FAILURE;
    }
    else
    {
        if (NULL == this_getcwd(s_cwd, (int)(1 + path_max)))
        {
            int const e = errno;

            fprintf(stderr, "%s: failed to obtain current directory: %d / %s\n", program_name, e, strerror(e));

            r = EXIT_FAILURE;
        }
        else
        {
            size_t const n = platformstl_C_get_home_directory(s_home, 1 + path_max);

            if (0 == n)
            {
                int const e = errno;

                fprintf(stderr, "%s: failed to obtain current directory: %d / %s\n", program_name, e, strerror(e));

                r = EXIT_FAILURE;
            }
            else
            {
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

                s_cwdHome = n;

                r = main_(argc, argv);
            }
        }
    }

    free(s_cwd);
    free(s_home);

    return r;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void test_1_0(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL(""), flags, &entry);

    XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
}

static void test_stat_dot(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("."), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the current directory */
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

static void test_stat_dot_slash(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("./"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the current directory */
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

static void test_stat_tilde(void)
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

static void test_stat_tilde_slash(void)
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

static void test_stat_tilde_MARK_DIRS(void)
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

static void test_stat_tilde_slash_MARK_DIRS(void)
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
    recls_info_t    entry;
    unsigned        flags   =   0;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_NO_MORE_DATA, rc));
}

static void test_1_12(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    if (RECLS_RC_OK == rc)
    {
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

static void test_1_13(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            |   RECLS_F_FILES
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_file, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_NO_MORE_DATA, rc));
}

static void test_1_14(void)
{
    recls_info_t    entry;
    unsigned        flags   =   0
                            |   RECLS_F_DETAILS_LATER
                            |   RECLS_F_FILES
                            ;
    recls_rc_t      rc      =   Recls_Stat(s_nonexistent_path, flags, &entry);

    XTESTS_REQUIRE(XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_DIRECTORY_NOT_FOUND, rc));
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


static void test_2_0(void)
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL(""), flags, &entry);

    XTESTS_TEST_INTEGER_EQUAL(RECLS_RC_INVALID_NAME, rc);
}

static void test_2_1(void)
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("."), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the current directory */
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

static void test_2_2(void)
{
    recls_info_t    entry;
    unsigned        flags   =   RECLS_F_DETAILS_LATER;
    recls_rc_t      rc      =   Recls_Stat(RECLS_LITERAL("./"), flags, &entry);

    if (RECLS_RC_OK == rc)
    {
        XTESTS_TEST_PASSED();

        /* Verify that it's the current directory */
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

static void test_2_3(void)
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

static void test_2_4(void)
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

static void test_2_5(void)
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

static void test_2_6(void)
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

static void test_2_7(void)
{
}

static void test_2_8(void)
{
}

static void test_2_9(void)
{
}


/* ///////////////////////////// end of file //////////////////////////// */

