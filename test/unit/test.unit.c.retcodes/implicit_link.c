/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.c.retcodes/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.c.retcodes project.
 *
 * Created:     13th December 2008
 * Updated:     19th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls header files */
#include <recls/implicit_link.h>

/* xTests header files */
#include <xtests/implicit_link.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* OS */

/* ///////////////////////////// end of file //////////////////////////// */

