/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.unit.util.file_sizes/entry.c
 *
 * Purpose: Unit-test of recls file-size utility functions.
 *
 * Created: 17th April 2025
 * Updated: 2nd May 2025
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
 * constants
 */

#define KibiByte                                            ((recls_filesize_t)RFS_(1024))
#define KiloByte                                            ((recls_filesize_t)RFS_(1000))

#define MebiByte                                            ((recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024))
#define MegaByte                                            ((recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000))

#define GibiByte                                            ((recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024))
#define GigaByte                                            ((recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000))

#define TebiByte                                            ((recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024) * (recls_filesize_t)RFS_(1024))
#define TeraByte                                            ((recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000) * (recls_filesize_t)RFS_(1000))


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void TEST_Recls_GetFileSizeKibiBytes(void);
static void TEST_Recls_GetFileSizeKiloBytes(void);
static void TEST_Recls_GetFileSizeMebiBytes(void);
static void TEST_Recls_GetFileSizeMegaBytes(void);
static void TEST_Recls_GetFileSizeGibiBytes(void);
static void TEST_Recls_GetFileSizeGigaBytes(void);
static void TEST_Recls_GetFileSizeTebiBytes(void);
static void TEST_Recls_GetFileSizeTeraBytes(void);


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
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeTebiBytes);
        XTESTS_RUN_CASE(TEST_Recls_GetFileSizeTeraBytes);

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
    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(0));

    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(KiloByte - 1));

    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(KiloByte));
    TEST_INT_EQ(0, Recls_GetFileSizeKibiBytes(KibiByte - 1));

    TEST_INT_EQ(1, Recls_GetFileSizeKibiBytes(KibiByte));

    TEST_INT_EQ(9, Recls_GetFileSizeKibiBytes(10 * KibiByte - 1));
    TEST_INT_EQ(10, Recls_GetFileSizeKibiBytes(10 * KibiByte));

    TEST_INT_EQ(999, Recls_GetFileSizeKibiBytes(KiloByte * 1024 - 1));
    TEST_INT_EQ(1023, Recls_GetFileSizeKibiBytes(MebiByte - 1));
    TEST_INT_EQ(1024, Recls_GetFileSizeKibiBytes(MebiByte));
}

static void TEST_Recls_GetFileSizeKiloBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeKiloBytes(0));

    TEST_INT_EQ(0, Recls_GetFileSizeKiloBytes(KiloByte - 1));

    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(KiloByte));
    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(KibiByte - 1));

    TEST_INT_EQ(1, Recls_GetFileSizeKiloBytes(KibiByte));

    TEST_INT_EQ(10, Recls_GetFileSizeKiloBytes(10 * KibiByte - 1));
    TEST_INT_EQ(10, Recls_GetFileSizeKiloBytes(10 * KibiByte));

    TEST_INT_EQ(1023, Recls_GetFileSizeKiloBytes(KiloByte * 1024 - 1));
    TEST_INT_EQ(1048, Recls_GetFileSizeKiloBytes(MebiByte - 1));
    TEST_INT_EQ(1048, Recls_GetFileSizeKiloBytes(MebiByte));
}

static void TEST_Recls_GetFileSizeMebiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(0));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(KiloByte - 1));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(KiloByte));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(KibiByte - 1));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(KibiByte));
    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(100 * KibiByte));

    TEST_INT_EQ(0, Recls_GetFileSizeMebiBytes(MebiByte - 1));
    TEST_INT_EQ(1, Recls_GetFileSizeMebiBytes(MebiByte));

    TEST_INT_EQ(9, Recls_GetFileSizeMebiBytes(10 * MegaByte));
    TEST_INT_EQ(10, Recls_GetFileSizeMebiBytes(10 * MebiByte));
}

static void TEST_Recls_GetFileSizeMegaBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(0));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(KiloByte - 1));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(KiloByte));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(KibiByte - 1));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(KibiByte));
    TEST_INT_EQ(0, Recls_GetFileSizeMegaBytes(100 * KibiByte));

    TEST_INT_EQ(1, Recls_GetFileSizeMegaBytes(MebiByte - 1));
    TEST_INT_EQ(1, Recls_GetFileSizeMegaBytes(MebiByte));

    TEST_INT_EQ(10, Recls_GetFileSizeMegaBytes(10 * MegaByte));
    TEST_INT_EQ(10, Recls_GetFileSizeMegaBytes(10 * MebiByte));
}

static void TEST_Recls_GetFileSizeGibiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeGibiBytes(1 * GigaByte));
    TEST_INT_EQ(1, Recls_GetFileSizeGibiBytes(1 * GibiByte));

    TEST_INT_EQ(3, Recls_GetFileSizeGibiBytes(4 * GigaByte));
    TEST_INT_EQ(4, Recls_GetFileSizeGibiBytes(4 * GibiByte));

    TEST_INT_EQ(9, Recls_GetFileSizeGibiBytes(10 * GigaByte - 1));
    TEST_INT_EQ(9, Recls_GetFileSizeGibiBytes(10 * GigaByte));
    TEST_INT_EQ(10, Recls_GetFileSizeGibiBytes(10 * GibiByte));
}

static void TEST_Recls_GetFileSizeGigaBytes(void)
{
    TEST_INT_EQ(1, Recls_GetFileSizeGigaBytes(1 * GigaByte));
    TEST_INT_EQ(1, Recls_GetFileSizeGigaBytes(1 * GibiByte));

    TEST_INT_EQ(4, Recls_GetFileSizeGigaBytes(4 * GigaByte));
    TEST_INT_EQ(4, Recls_GetFileSizeGigaBytes(4 * GibiByte));

    TEST_INT_EQ(9, Recls_GetFileSizeGigaBytes(10 * GigaByte - 1));
    TEST_INT_EQ(10, Recls_GetFileSizeGigaBytes(10 * GigaByte));
    TEST_INT_EQ(10, Recls_GetFileSizeGigaBytes(10 * GibiByte));
}

static void TEST_Recls_GetFileSizeTebiBytes(void)
{
    TEST_INT_EQ(0, Recls_GetFileSizeTebiBytes(1 * GigaByte));
    TEST_INT_EQ(0, Recls_GetFileSizeTebiBytes(1 * GibiByte));

    TEST_INT_EQ(0, Recls_GetFileSizeTebiBytes(1 * TeraByte));
    TEST_INT_EQ(1, Recls_GetFileSizeTebiBytes(1 * TebiByte));
}

static void TEST_Recls_GetFileSizeTeraBytes(void)
{
    TEST_INT_EQ(1, Recls_GetFileSizeTeraBytes(1 * TeraByte));
    TEST_INT_EQ(1, Recls_GetFileSizeTeraBytes(1 * TebiByte));

    TEST_INT_EQ(4, Recls_GetFileSizeTeraBytes(4 * TeraByte));
    TEST_INT_EQ(4, Recls_GetFileSizeTeraBytes(4 * TebiByte));

    TEST_INT_EQ(9, Recls_GetFileSizeTeraBytes(10 * TeraByte - 1));
    TEST_INT_EQ(10, Recls_GetFileSizeTeraBytes(10 * TeraByte));
    TEST_INT_EQ(10, Recls_GetFileSizeTeraBytes(10 * TebiByte));
}


/* ///////////////////////////// end of file //////////////////////////// */

