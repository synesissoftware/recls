/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.cpp.squeeze_path project.
 *
 * Created:     7th June 2008
 * Updated:     19th December 2023
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * includes
 */

/* recls Header Files */
#include <recls/implicit_link.h>

/* xTests Header Files */
#include <xtests/implicit_link.h>

/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
# include <unixem/implicit_link.h>
#endif /* OS */

/* xCover Header Files */
#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <xcover/implicit_link.h>
#endif

/* ///////////////////////////// end of file //////////////////////////// */

