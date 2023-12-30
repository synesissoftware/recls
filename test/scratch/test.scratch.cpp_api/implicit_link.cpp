/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.cpp_api project.
 *
 * Created:     4th January 2010
 * Updated:     19th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls Header Files */
#include <recls/implicit_link.h>

/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* xCover Header Files */
#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <xcover/implicit_link.h>
#endif

/* ///////////////////////////// end of file //////////////////////////// */

