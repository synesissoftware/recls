/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp
 *
 * Purpose: Unit-test of recls C++ API function `recls::combine_paths()`.
 *
 * Created: 7th June 2008
 * Updated: 3rd January 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * test component header file include(s)
 */

#include <recls/recls.hpp>

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
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_WIDE_STRING_EQUAL
#else
# define XTESTS_TEST_STRING_EQUAL                           XTESTS_TEST_MULTIBYTE_STRING_EQUAL
#endif

/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace
{

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

} // anonymous namespace

/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.cpp.combine_paths", verbosity))
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

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}

/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

namespace
{
    using recls::recls_char_t;


static void test_1_0(void)
{
#if defined(RECLS_PLATFORM_IS_UNIX)

    // 1. CombinePaths

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc"), "def/"));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc/"), "def/"));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def"), recls::combine_paths(RECLS_LITERAL("/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc"), "def/"));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/abc/def/"), recls::combine_paths(RECLS_LITERAL("/abc/"), "def/"));

#elif defined(RECLS_PLATFORM_IS_WINDOWS)

    // 1. CombinePaths

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc\\"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a\\b\\c\\def"), recls::combine_paths(RECLS_LITERAL("a\\b\\c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("\\def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def"), recls::combine_paths(RECLS_LITERAL("H:\\abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def"), recls::combine_paths(RECLS_LITERAL("H:\\abc\\"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def\\"), recls::combine_paths(RECLS_LITERAL("H:\\abc"), RECLS_LITERAL("def\\")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:\\abc\\def\\"), recls::combine_paths(RECLS_LITERAL("H:\\abc\\"), RECLS_LITERAL("def\\")));

    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc\\def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc/def"), recls::combine_paths(RECLS_LITERAL("abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("a/b/c/def"), recls::combine_paths(RECLS_LITERAL("a/b/c"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("abc"), recls::combine_paths(RECLS_LITERAL("abc"), static_cast<recls_char_t const*>(NULL)));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("def"), recls::combine_paths(static_cast<recls_char_t const*>(NULL), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("/def"), recls::combine_paths(RECLS_LITERAL("abc"), RECLS_LITERAL("/def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def"), recls::combine_paths(RECLS_LITERAL("H:/abc"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def"), recls::combine_paths(RECLS_LITERAL("H:/abc/"), RECLS_LITERAL("def")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def/"), recls::combine_paths(RECLS_LITERAL("H:/abc"), RECLS_LITERAL("def/")));
    XTESTS_TEST_STRING_EQUAL(RECLS_LITERAL("H:/abc/def/"), recls::combine_paths(RECLS_LITERAL("H:/abc/"), RECLS_LITERAL("def/")));

#else /* ? OS */
# error Platform not recognised
#endif /* __SYNSOFT_VAL_OS_WIN16 */

}

static void test_1_1(void)
{
}

static void test_1_2(void)
{
}

static void test_1_3(void)
{
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

static void test_1_20(void)
{
}

static void test_1_21(void)
{
}

static void test_1_22(void)
{
}

static void test_1_23(void)
{
}

static void test_1_24(void)
{
}

static void test_1_25(void)
{
}

static void test_1_26(void)
{
}

static void test_1_27(void)
{
}

static void test_1_28(void)
{
}

static void test_1_29(void)
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

