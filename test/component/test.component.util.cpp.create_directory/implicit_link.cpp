/* /////////////////////////////////////////////////////////////////////////
 * File:        test/component/test.component.util.cpp.create_directory/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.component.util.cpp.create_directory project.
 *
 * Created:     30th January 2010
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

