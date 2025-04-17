/* /////////////////////////////////////////////////////////////////////////
 * File:    test.unit.util.file_sizes.cpp
 *
 * Purpose: Unit-test of recls file-size utility functions.
 *
 * Created: 17th April 2025
 * Updated: 17th April 2025
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
#include <xtests/terse-api.h>

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#define RFS_(v)                                             STLSOFT_GEN_SINT64_SUFFIX(v)


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_Recls_GetFileSizeKibiBytes(void);
static void TEST_Recls_GetFileSizeKiloBytes(void);
static void TEST_Recls_GetFileSizeMebiBytes(void);
static void TEST_Recls_GetFileSizeMegaBytes(void);
static void TEST_Recls_GetFileSizeGibiBytes(void);
static void TEST_Recls_GetFileSizeGigaBytes(void);


/* /////////////////////////////////////////////////////////////////////////
 * main
 */

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    int verbosity = 2;

    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.unit.util.file_sizes", verbosity))
    {
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeKibiBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeKiloBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeMebiBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeMegaBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeGibiBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeGigaBytes);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
 * test function implementations
 */

static void TEST_Recls_GetFileSizeKibiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(RFS_(0)));

    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(RFS_(999)));

    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(RFS_(1000)));
    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(RFS_(1023)));

    TEST_INT_EQ(1, Recls_GetFileSizeKibiBytes(RFS_(1024)));

    TEST_INT_EQ(9, Recls_GetFileSizeKibiBytes(RFS_(10239)));
    TEST_INT_EQ(10, Recls_GetFileSizeKibiBytes(RFS_(10240)));

    TEST_INT_EQ(999, Recls_GetFileSizeKibiBytes(RFS_(1000) * 1024 - 1));
    TEST_INT_EQ(1023, Recls_GetFileSizeKibiBytes(RFS_(1024) * 1024 - 1));
    TEST_INT_EQ(1024, Recls_GetFileSizeKibiBytes(RFS_(1024) * 1024));
}

static void TEST_Recls_GetFileSizeKiloBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeKiloBytes(RFS_(0)));

    TEST_INT_EQ(0, Recls_GetFileSizeKiloBytes(RFS_(999)));

    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(RFS_(1000)));
    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(RFS_(1023)));

    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(RFS_(1024)));

    TEST_INT_EQ(10, Recls_GetFileSizeKiloBytes(RFS_(10239)));
    TEST_INT_EQ(10, Recls_GetFileSizeKiloBytes(RFS_(10240)));

    TEST_INT_EQ(1023, Recls_GetFileSizeKiloBytes(RFS_(1000) * 1024 - 1));
    TEST_INT_EQ(1048, Recls_GetFileSizeKiloBytes(RFS_(1024) * 1024 - 1));
    TEST_INT_EQ(1048, Recls_GetFileSizeKiloBytes(RFS_(1024) * 1024));
}

static void TEST_Recls_GetFileSizeMebiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(0)));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(999)));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(1000)));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(1023)));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(1024)));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(100) * 1024));

    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(RFS_(1024) * 1024 - 1));
    TEST_INT_EQ(1, Recls_GetFileSizeMebiBytes(RFS_(1024) * 1024));

    TEST_INT_EQ(9, Recls_GetFileSizeMebiBytes(RFS_(10) * 1000 * 1000));
    TEST_INT_EQ(10, Recls_GetFileSizeMebiBytes(RFS_(10) * 1024 * 1024));
}

static void TEST_Recls_GetFileSizeMegaBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(0)));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(999)));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(1000)));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(1023)));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(1024)));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(RFS_(100) * 1024));

    TEST_INT_EQ(1, Recls_GetFileSizeMegaBytes(RFS_(1024) * 1024 - 1));
    TEST_INT_EQ(1, Recls_GetFileSizeMegaBytes(RFS_(1024) * 1024));

    TEST_INT_EQ(10, Recls_GetFileSizeMegaBytes(RFS_(10) * 1000 * 1000));
    TEST_INT_EQ(10, Recls_GetFileSizeMegaBytes(RFS_(10) * 1024 * 1024));
}

static void TEST_Recls_GetFileSizeGibiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeGibiBytes(RFS_(1) * 1000 * 1000 * 1000));
    TEST_INT_EQ(1, Recls_GetFileSizeGibiBytes(RFS_(1) * 1024 * 1024 * 1024));

    TEST_INT_EQ(3, Recls_GetFileSizeGibiBytes(RFS_(4) * 1000 * 1000 * 1000));
    TEST_INT_EQ(4, Recls_GetFileSizeGibiBytes(RFS_(4) * 1024 * 1024 * 1024));

    TEST_INT_EQ(9, Recls_GetFileSizeGibiBytes(RFS_(10) * 1000 * 1000 * 1000 - 1));
    TEST_INT_EQ(9, Recls_GetFileSizeGibiBytes(RFS_(10) * 1000 * 1000 * 1000));
    TEST_INT_EQ(10, Recls_GetFileSizeGibiBytes(RFS_(10) * 1024 * 1024 * 1024));
}

static void TEST_Recls_GetFileSizeGigaBytes(void)
{
    TEST_INT_EQ(1, Recls_GetFileSizeGigaBytes(RFS_(1) * 1000 * 1000 * 1000));
    TEST_INT_EQ(1, Recls_GetFileSizeGigaBytes(RFS_(1) * 1024 * 1024 * 1024));

    TEST_INT_EQ(4, Recls_GetFileSizeGigaBytes(RFS_(4) * 1000 * 1000 * 1000));
    TEST_INT_EQ(4, Recls_GetFileSizeGigaBytes(RFS_(4) * 1024 * 1024 * 1024));

    TEST_INT_EQ(9, Recls_GetFileSizeGigaBytes(RFS_(10) * 1000 * 1000 * 1000 - 1));
    TEST_INT_EQ(10, Recls_GetFileSizeGigaBytes(RFS_(10) * 1000 * 1000 * 1000));
    TEST_INT_EQ(10, Recls_GetFileSizeGigaBytes(RFS_(10) * 1024 * 1024 * 1024));
}


/* ///////////////////////////// end of file //////////////////////////// */

