/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.api.createdirectory.c
 *
 * Purpose: Test creation of directories (via recls C API function
 *          `Recls_CreateDirectory()`).
 *
 * Created: 29th January 2009
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
#include <platformstl/filesystem/path_functions.h>
#include <platformstl/system/directory_functions.h>

/* Standard C header files */
#include <errno.h>
#include <stdlib.h>
#if 0
#elif 1 &&\
      defined(_WIN32) &&\
      ( 0 ||\
        defined(STLSOFT_COMPILER_IS_GCC) ||\
        defined(STLSOFT_COMPILER_IS_MSVC) ||\
        0) &&\
      1

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

static void test_create_directory_invalid_name(void);
static void test_create_directory_pwd(void);
static void test_create_directory_under_home(void);
static void test_create_subdirectory_under_home(void);


/* /////////////////////////////////////////////////////////////////////////
 * main()
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

    if (XTESTS_START_RUNNER("test.unit.api.createdirectory", verbosity))
    {
        XTESTS_RUN_CASE(test_create_directory_invalid_name);
        XTESTS_RUN_CASE(test_create_directory_pwd);
        XTESTS_RUN_CASE(test_create_directory_under_home);
        XTESTS_RUN_CASE(test_create_subdirectory_under_home);

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

#define RECLS_TEST_DIR_ROOT                                 RECLS_LITERAL("~/recls_test_dir_root_D01441CA_A1CD_4916_B095_B2D65B15E517")
#define RECLS_TEST_DIR_ROOT_LEN                             ((STLSOFT_NUM_ELEMENTS(RECLS_TEST_DIR_ROOT) - 1))


static void test_create_directory_invalid_name(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_LITERAL(""), &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_LITERAL(""), NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_INVALID_NAME, rc);
    }
}

static void test_create_directory_pwd(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_LITERAL("."), &results);

        // because it's the current directory, it will succeed, and the
        // path length and number of elements will remain unchanged

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
        XTESTS_TEST_INTEGER_EQUAL(s_cwdLen, results.resultingLength);
        XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements, results.numResultingElements);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_LITERAL("."), NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }
}

static void test_create_directory_under_home(void)
{
    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT, &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);

        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(results.existingLength, results.resultingLength);


        XTESTS_TEST_INTEGER_EQUAL(s_cwdHome + (RECLS_TEST_DIR_ROOT_LEN - 1), results.resultingLength);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT, NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(RECLS_TEST_DIR_ROOT, RECLS_REMDIR_F_REMOVE_FILES, NULL);
}

static void test_create_subdirectory_under_home(void)
{
#define TEST_1_3_SUBDIR                                     RECLS_LITERAL("abc/def/ghi/jkl/mno")
#define TEST_1_3_SUBDIR_LEN                                 (STLSOFT_NUM_ELEMENTS(TEST_1_3_SUBDIR) - 1)

    {
        recls_directoryResults_t    results;
        recls_rc_t                  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT TEST_1_3_SUBDIR, &results);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);

        XTESTS_TEST_INTEGER_GREATER_OR_EQUAL(results.existingLength, results.resultingLength);


        XTESTS_TEST_INTEGER_EQUAL(s_cwdHome + (RECLS_TEST_DIR_ROOT_LEN - 1) + TEST_1_3_SUBDIR_LEN, results.resultingLength);
    }

    {
        recls_rc_t  rc = Recls_CreateDirectory(RECLS_TEST_DIR_ROOT TEST_1_3_SUBDIR, NULL);

        XTESTS_TEST_POINTER_EQUAL(RECLS_RC_OK, rc);
    }

    Recls_RemoveDirectory(RECLS_TEST_DIR_ROOT, RECLS_REMDIR_F_REMOVE_FILES | RECLS_REMDIR_F_REMOVE_READONLY, NULL);
}


/* ///////////////////////////// end of file //////////////////////////// */

