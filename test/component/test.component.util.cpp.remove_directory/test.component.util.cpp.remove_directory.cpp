/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
 *
 * Purpose:     Implementation file for the test.component.util.cpp.remove_directory project.
 *
 * Created:     30th January 2010
 * Updated:     29th September 2015
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2010-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Test component header file include(s)
 */

#ifdef __GNUC__
# include <platformstl/filesystem/path.hpp>
#endif

#include <recls/recls.hpp>

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

/* xCover Header Files */
#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <xcover/xcover.h>
#endif

/* xTests Header Files */
#include <xtests/xtests.h>

/* STLSoft Header Files */
#include <stlsoft/stlsoft.h>
#include <platformstl/filesystem/directory_functions.hpp>
#include <platformstl/filesystem/file_path_buffer.hpp>
#include <platformstl/filesystem/path.hpp>

/* Standard C Header Files */
#include <stdlib.h>

/* /////////////////////////////////////////////////////////////////////////
 * Forward declarations
 */

namespace
{

    static void test_1_0(void);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
    static void test_1_1(void);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
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
    static void test_1_20(void);
    static void test_1_21(void);
    static void test_1_22(void);
    static void test_1_23(void);
    static void test_1_24(void);
    static void test_1_25(void);
    static void test_1_26(void);
    static void test_1_27(void);
    static void test_1_28(void);
    static void test_1_29(void);
    static void test_1_30(void);
    static void test_1_31(void);
    static void test_1_32(void);
    static void test_1_33(void);
    static void test_1_34(void);
    static void test_1_35(void);
    static void test_1_36(void);
    static void test_1_37(void);
    static void test_1_38(void);
    static void test_1_39(void);

    static int setup(void*);
    static int teardown(void*);

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Non-local static variables
 */

namespace
{

    platformstl::file_path_buffer   temp_dir;

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * Main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if(XTESTS_START_RUNNER_WITH_SETUP_FNS("test.component.util.cpp.remove_directory", verbosity, setup, teardown, NULL))
    {
        XTESTS_RUN_CASE(test_1_0);
#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
        XTESTS_RUN_CASE_THAT_THROWS(test_1_1, recls::recls_exception);
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */
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
        XTESTS_RUN_CASE(test_1_20);
        XTESTS_RUN_CASE(test_1_21);
        XTESTS_RUN_CASE(test_1_22);
        XTESTS_RUN_CASE(test_1_23);
        XTESTS_RUN_CASE(test_1_24);
        XTESTS_RUN_CASE(test_1_25);
        XTESTS_RUN_CASE(test_1_26);
        XTESTS_RUN_CASE(test_1_27);
        XTESTS_RUN_CASE(test_1_28);
        XTESTS_RUN_CASE(test_1_29);
        XTESTS_RUN_CASE(test_1_30);
        XTESTS_RUN_CASE(test_1_31);
        XTESTS_RUN_CASE(test_1_32);
        XTESTS_RUN_CASE(test_1_33);
        XTESTS_RUN_CASE(test_1_34);
        XTESTS_RUN_CASE(test_1_35);
        XTESTS_RUN_CASE(test_1_36);
        XTESTS_RUN_CASE(test_1_37);
        XTESTS_RUN_CASE(test_1_38);
        XTESTS_RUN_CASE(test_1_39);

#ifdef XCOVER_VER
        XCOVER_REPORT_GROUP_COVERAGE("recls.util.remove_directory", NULL);
#endif /* XCOVER_VER */

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * Test function implementations
 */

namespace
{
	using recls::recls_char_t;


static int setup(void*)
{
#if defined(PLATFORMSTL_OS_IS_UNIX)

    if(NULL == ::tmpnam(&temp_dir[0]))
    {
        fprintf(stderr, "tmpnam(): %d: %s\n", errno, strerror(errno));

        return int(errno);
    }

    if(!platformstl::create_directory_recurse(temp_dir.c_str()))
    {
        fprintf(stderr, "platformstl::create_directory_recurse(): %d: %s\n", errno, strerror(errno));

        return int(errno);
    }

# ifdef _WIN32
    size_t  n   =   ::strlen(temp_dir.c_str());
    char*   b   =   &temp_dir[0];
    char*   e   =   b + n;

    std::replace(b, e, '\\', '/');
# endif /* _WIN32 */

#elif defined(PLATFORMSTL_OS_IS_WINDOWS)

    TCHAR   tdir[_MAX_PATH + 1];
    DWORD   dw = ::GetTempPath(STLSOFT_NUM_ELEMENTS(tdir), &tdir[0]);

    if(0 == dw)
    {
        return int(::GetLastError());
    }

    UINT    n = ::GetTempFileName(tdir, RECLS_LITERAL("rcl"), 0, &temp_dir[0]);

    if(0 == n)
    {
        return int(::GetLastError());
    }

    if( !::DeleteFile(temp_dir.c_str()) ||
        !::CreateDirectory(temp_dir.c_str(), NULL))
    {
        return int(::GetLastError());
    }

#else
# error Platform not discriminated
#endif

    return 0;
}

static int teardown(void*)
{
    if(!platformstl::filesystem_traits<recls_char_t>::remove_directory(temp_dir.c_str()))
    {
        platformstl::remove_directory_recurse(temp_dir);
    }

    return 0;
}


static void test_1_0()
{
    //recls::create_directory(".");

    XTESTS_TEST_PASSED();
}

#ifdef STLSOFT_CF_EXCEPTION_SUPPORT
static void test_1_1()
{
    recls::remove_directory(RECLS_LITERAL("|"));

    XTESTS_TEST_FAIL("should not get here");
}
#endif /* STLSOFT_CF_EXCEPTION_SUPPORT */

static void test_1_2()
{
    platformstl::path path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    platformstl::path path2remove(path);

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 1u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 4u, results.resultingLength);
}

static void test_1_3()
{
    platformstl::path path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    platformstl::path path2remove(path);

    path.push(RECLS_LITERAL("def"));

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 2u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 8u, results.resultingLength);
}

static void test_1_4()
{
    platformstl::path path(temp_dir);

    path.push(RECLS_LITERAL("abc"));

    platformstl::path path2remove(path);

    path.push(RECLS_LITERAL("def"));
    path.push(RECLS_LITERAL("ghi"));
    path.push(RECLS_LITERAL("jkl"));

    platformstl::create_directory_recurse(path);

    recls::directoryResults_t   results;

    recls::remove_directory(path2remove, 0, &results);

    XTESTS_TEST_INTEGER_EQUAL(results.numExistingElements - 4u, results.numResultingElements);
    XTESTS_TEST_INTEGER_EQUAL(results.existingLength - 16u, results.resultingLength);
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

static void test_1_20()
{
}

static void test_1_21()
{
}

static void test_1_22()
{
}

static void test_1_23()
{
}

static void test_1_24()
{
}

static void test_1_25()
{
}

static void test_1_26()
{
}

static void test_1_27()
{
}

static void test_1_28()
{
}

static void test_1_29()
{
}

static void test_1_30()
{
}

static void test_1_31()
{
}

static void test_1_32()
{
}

static void test_1_33()
{
}

static void test_1_34()
{
}

static void test_1_35()
{
}

static void test_1_36()
{
}

static void test_1_37()
{
}

static void test_1_38()
{
}

static void test_1_39()
{
}


} // anonymous namespace

/* ///////////////////////////// end of file //////////////////////////// */
