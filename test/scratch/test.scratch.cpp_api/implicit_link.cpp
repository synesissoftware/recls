/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.cpp_api project.
 *
 * Created:     4th January 2010
 * Updated:     30th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/implicit_link.h>

/* UNIXem header files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* ///////////////////////////// end of file //////////////////////////// */

