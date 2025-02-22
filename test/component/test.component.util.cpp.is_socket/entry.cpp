/* /////////////////////////////////////////////////////////////////////////
 * File:    test/unit/test.component.util.cpp.is_socket/entry.cpp
 *
 * Purpose: Tests `recls::entry#is_socket()`.
 *
 * Created: 20th February 2025
 * Updated: 23rd February 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* /////////////////////////////////////
 * test component header file include(s)
 */

#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <recls/recls.h>
#endif

#include <xtests/test/util/compiler_warnings_suppression.first_include.h>

#ifdef __GNUC__
# include <platformstl/filesystem/path.hpp>
#endif

#include <recls/recls.hpp>

/* /////////////////////////////////////
* general includes
*/

/* xTests header files */
#include <xtests/terse-api.h>
#include <xtests/util/temp_directory.hpp>

/* STLSoft header files */
#include <platformstl/filesystem/path.hpp>
#include <stlsoft/smartptr/scoped_handle.hpp>

/* Standard C header files */
#include <errno.h>
#include <stdlib.h>

/* UNIX header files */
#include <sys/socket.h>
#include <sys/un.h>

#include <xtests/test/util/compiler_warnings_suppression.last_include.h>


/* /////////////////////////////////////////////////////////////////////////
* forward declarations
*/

namespace
{

    static void TEST_is_socket();
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
* types
*/

namespace
{

    typedef platformstl::path                               path_t;
    using xtests::cpp::util::temp_directory;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
* Non-local static variables
*/

namespace
{

    int verbosity = 2;
} // anonymous namespace


/* /////////////////////////////////////////////////////////////////////////
* main()
*/

int main(int argc, char **argv)
{
    int retCode = EXIT_SUCCESS;
    XTESTS_COMMANDLINE_PARSEVERBOSITY(argc, argv, &verbosity);

    if (XTESTS_START_RUNNER("test.component.util.cpp.is_socket", verbosity))
    {
        XTESTS_RUN_CASE(TEST_is_socket);

        XTESTS_PRINT_RESULTS();

        XTESTS_END_RUNNER_UPDATE_EXITCODE(&retCode);
    }

    return retCode;
}


/* /////////////////////////////////////////////////////////////////////////
* test function implementations
*/

#include <iostream>

#include <platformstl/filesystem/readdir_sequence.hpp>

namespace
{

static void TEST_is_socket(void)
{

    path_t  td_path;

    {
        temp_directory  td(temp_directory::EmptyOnOpen | temp_directory::EmptyOnClose | temp_directory::RemoveOnClose);

        path_t          path(td.c_str());
        path_t          sk_path = path / "tmp.sock";

        td_path = td.c_str();

        if (verbosity >= 4)
        {
            std::cerr
                << '\t'
                << "path="
                << path
                << std::endl
                << '\t'
                << "sk_path="
                << sk_path
                << std::endl
                ;
        }

        int sk = socket(AF_UNIX, SOCK_STREAM, 0);

        if (-1 == sk)
        {
            int const e = errno;

            TEST_FAIL_WITH_QUALIFIER("failed to create socket", strerror(e));
        }
        else
        {
            stlsoft::scoped_handle scoper(sk, close);

            struct sockaddr_un sa;

            if (sk_path.length() >= STLSOFT_NUM_ELEMENTS(sa.sun_path))
            {
                TEST_FAIL_WITH_QUALIFIER("socket_path is too long to test", sk_path);
            }
            else
            {
                sa.sun_len = sizeof(sa);
                sa.sun_family = AF_UNIX;
                strcpy(sa.sun_path, sk_path.c_str());

                int const r = bind(sk, (struct sockaddr*)&sa, sizeof(sa));

                if (0 != r)
                {
                    int const e = errno;

                    TEST_FAIL_WITH_QUALIFIER("failed to bind socket", strerror(e));
                }
                else
                {
                    recls::entry re = recls::stat(sk_path);

                    TEST_BOOLEAN_FALSE(re.is_directory());
                    TEST_BOOLEAN_TRUE(re.is_socket());
                }
            }
        }
    }
}
} // anonymous namespace


/* ///////////////////////////// end of file //////////////////////////// */

