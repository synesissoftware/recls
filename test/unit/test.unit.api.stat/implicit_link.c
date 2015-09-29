/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.api.stat/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.api.stat project.
 *
 * Created:     13th December 2008
 * Updated:     5th January 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2010, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* /////////////////////////////////////////////////////////////////////////
 * Includes
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
#endif /* ? OS */

/* xCover Header Files */
#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <xcover/implicit_link.h>
#endif

/* ///////////////////////////// end of file //////////////////////////// */
