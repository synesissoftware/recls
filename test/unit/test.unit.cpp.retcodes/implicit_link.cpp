/* /////////////////////////////////////////////////////////////////////////
 * File:        test/unit/test.unit.cpp.retcodes/implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.unit.cpp.retcodes project.
 *
 * Created:     13th December 2008
 * Updated:     22nd December 2020
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2020, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
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

/* ///////////////////////////// end of file //////////////////////////// */

