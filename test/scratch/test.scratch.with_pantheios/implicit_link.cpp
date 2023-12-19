/* /////////////////////////////////////////////////////////////////////////
 * File:        implicit_link.cpp
 *
 * Purpose:     Implicit link file for the test.scratch.with_pantheios project.
 *
 * Created:     13th December 2008
 * Updated:     19th December 2023
 *
 * Status:      Wizard-generated
 *
 * License:     (Licensed under the Synesis Software Open License)
 *
 *              Copyright (c) 2008-2015, Synesis Software Pty Ltd.
 *              All rights reserved.
 *
 *              www:        http://www.synesis.com.au/software
 *
 * ////////////////////////////////////////////////////////////////////// */


/* Pantheios Header Files */
#include <platformstl/platformstl.h>
#include <pantheios/implicit_link/core.h>
#include <pantheios/implicit_link/fe.simple.h>
#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <pantheios/implicit_link/be.syslog.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <pantheios/implicit_link/be.N.h>
# include <pantheios/implicit_link/bec.WindowsDebugger.h>
# include <pantheios/implicit_link/bec.WindowsSysLog.h>
#endif /* operating system */

/* UNIXem Header Files */
#include <platformstl/platformstl.h>
#if defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <unixem/implicit_link.h>
#endif /* operating system */

/* xCover Header Files */
#if defined(__FUNCTION__) && \
    defined(__COUNTER__)
# include <xcover/implicit_link.h>
#endif

/* ////////////////////////////////////////////////////////////////////// */

/* Pantheios Header Files */
#if defined(PLATFORMSTL_OS_IS_WINDOWS)

# include <pantheios/backends/be.N.h>
# include <pantheios/backends/bec.WindowsDebugger.h>
# include <pantheios/backends/bec.WindowsSyslog.h>

pan_be_N_t  PAN_BE_N_BACKEND_LIST[] =
{
    PANTHEIOS_BE_N_STDFORM_ENTRY(1, pantheios_be_WindowsDebugger, 0)
  , PANTHEIOS_BE_N_STDFORM_ENTRY(2, pantheios_be_WindowsSyslog, PANTHEIOS_BE_N_F_IGNORE_INIT_FAILURE)
  , PANTHEIOS_BE_N_TERMINATOR_ENTRY
};

#endif /* operating system */

/* ///////////////////////////// end of file //////////////////////////// */

