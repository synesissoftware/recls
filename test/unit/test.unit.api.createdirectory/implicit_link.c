/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.api.createdirectory/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.api.createdirectory project.
 *
 * Created:     29th January 2009
 * Updated:     5th January 2010
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2009-2010, Synesis Software Pty Ltd.
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
