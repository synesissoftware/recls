# recls Example - **example_c_10**

## Summary

Demonstrates recursive search for all devices under a given directory including all appropriate failure handling.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_10/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for devices
 *  - search by Recls_Search()
 *  - display of full path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry structure members
 *
 * Created: 30th April 2025
 * Updated: 4th May 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>

/* Pantheios header files */
#ifdef HAS_Pantheios
# include <pantheios/pantheios.h>
#endif /* HAS_Pantheios */

/* STLSoft header files */
#include <platformstl/filesystem/path_functions.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>


/* /////////////////////////////////////////////////////////////////////////
 * globals
 */

#ifdef HAS_Pantheios

const char PANTHEIOS_FE_PROCESS_IDENTITY[]    =   "example_c_9";
#endif /* HAS_Pantheios */


/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifdef HAS_Pantheios

void RECLS_CALLCONV_DEFAULT recls_log_to_pantheios(
    int         severity
,   char const* fmt
,   va_list     args
)
{
    pantheios_logvprintf(severity, fmt, args);
}
#endif /* HAS_Pantheios */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

#ifdef HAS_Pantheios

static int main_(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    stlsoft_C_string_slice_m_t  program_name    =   platformstl_C_get_executable_name_from_path(argv[0]);
    int const                   ri              =   pantheios_init();

    if (0 != ri)
    {
        fprintf(stderr, "%.*s: %.*s\n", (int)program_name.len, program_name.ptr, (int)pantheios_getInitCodeStringLength(ri), pantheios_getInitCodeString(ri));

        return EXIT_FAILURE;
    }
    else
    {
        recls_log_severities_t severities = { .severities = {
            PANTHEIOS_SEV_ALERT,
            PANTHEIOS_SEV_ERROR,
            PANTHEIOS_SEV_WARNING,
            PANTHEIOS_SEV_INFORMATIONAL,
            PANTHEIOS_SEV_DEBUG,
            -1,
            -1,
            -1,
        }};

        Recls_SetApiLogFunction(recls_log_to_pantheios, 0, &severities);

        int const rm = main_(argc, argv);

        pantheios_uninit();

        return rm;
    }
}

static int main_(int argc, char* argv[])
#else

int main(int argc, char* argv[])
#endif /* HAS_Pantheios */
{
    /* Declare a search handle, define search directory as named or current,
     * pattern(s) matching all names, flags for recursive search of devices,
     * and start a search.
     */
    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    char const*     patterns    =   Recls_GetWildcardsAll();
    recls_uint32_t  flags       =   RECLS_F_RECURSIVE | RECLS_F_DEVICES;
    recls_rc_t      rc          =   Recls_Search(search_dir, patterns, flags, &hSrch);

    if (RECLS_RC_NO_MORE_DATA == rc)
    {
        printf("  no matches found\n");

        return EXIT_SUCCESS;
    }
    else if (RECLS_FAILED(rc))
    {
        /* The search failed. Display the failure reason. */
failed:

        fprintf(
            stderr
        ,   "Search in '%s' failed: %.*s\n"
        ,   search_dir
        ,   (int)Recls_GetSearchCodeStringLength(rc), Recls_GetSearchCodeString(rc)
        );

        return EXIT_FAILURE;
    }
    else
    {
        recls_info_t    entry;
        unsigned long   num_entries_found = 0;

        /* Get the details for the first entry, ... */
        Recls_GetDetails(hSrch, &entry);

        do
        {
            ++num_entries_found;

            /* ... display the full path, ... */
            printf("%.*s\n", (int)(entry->path.end - entry->path.begin), entry->path.begin);

            /* ... close the entry handle, ... */
            Recls_CloseDetails(entry);

        } /* ... and get the next entry. */
        while (RECLS_RC_OK == (rc = Recls_GetNextDetails(hSrch, &entry)));

        /* Close the search handle. */
        Recls_SearchClose(hSrch);

        if (RECLS_RC_NO_MORE_DATA != rc && RECLS_FAILED(rc))
        {
            goto failed;
        }

        printf("  %lu device(s) found\n", num_entries_found);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The functionality follows a similar pattern to that demonstrated already in **example_c_1**. The key differences are that the flag `RECLS_F_DEVICES` is specified absent any of the other type flags (`RECLS_F_DIRECTORIES`, `RECLS_F_FILES`, `RECLS_F_SOCKETS`), hence only devices in the searched directory are listed.

The other difference is the optional use of **Pantheios** to log out progress as the program executes. This is only enabled if **Pantheios** is discovered during the **CMake** configuration phase; if not detected, then the program only produces normative output and contingent reporting.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_10/example_c_10 /tmp/
```

then it produces results such as (without Pantheios):

```
/dev/oslog_stream
/dev/auditsessions
/dev/dtracehelper
/dev/autofs_nowait
/dev/autofs_notrigger
/dev/autofs_homedirmounter
/dev/autofs_control
/dev/cu.Bluetooth-Incoming-Port
/dev/tty
/dev/console
/dev/null
/dev/zero
/dev/klog
/dev/oslog
/dev/stdin
/dev/stdout
/dev/stderr
/dev/auditpipe
/dev/pf
/dev/pfm
/dev/ttyp0
/dev/ptyp0
/dev/ttyp1
/dev/ptyp1
/dev/ttyp2
/dev/ptyp2
/dev/ttyp3
/dev/ptyp3
/dev/ttyp4
/dev/ptyp4
/dev/ttyp5
/dev/ptyp5
/dev/ttyp6
/dev/ptyp6
/dev/ttyp7
/dev/ptyp7
/dev/ttyp8
/dev/ptyp8
/dev/ttyp9
/dev/ptyp9
/dev/ttypa
/dev/ptypa
/dev/ttypb
/dev/ptypb
/dev/ttypc
/dev/ptypc
/dev/ttypd
/dev/ptypd
/dev/ttype
/dev/ptype
/dev/ttypf
/dev/ptypf
/dev/ttyq0
/dev/ptyq0
/dev/ttyq1
/dev/ptyq1
/dev/ttyq2
/dev/ptyq2
/dev/ttyq3
/dev/ptyq3
/dev/ttyq4
/dev/ptyq4
/dev/ttyq5
/dev/ptyq5
/dev/ttyq6
/dev/ptyq6
/dev/ttyq7
/dev/ptyq7
/dev/ttyq8
/dev/ptyq8
/dev/ttyq9
/dev/ptyq9
/dev/ttyqa
/dev/ptyqa
/dev/ttyqb
/dev/ptyqb
/dev/ttyqc
/dev/ptyqc
/dev/ttyqd
/dev/ptyqd
/dev/ttyqe
/dev/ptyqe
/dev/ttyqf
/dev/ptyqf
/dev/ttyr0
/dev/ptyr0
/dev/ttyr1
/dev/ptyr1
/dev/ttyr2
/dev/ptyr2
/dev/ttyr3
/dev/ptyr3
/dev/ttyr4
/dev/ptyr4
/dev/ttyr5
/dev/ptyr5
/dev/ttyr6
/dev/ptyr6
/dev/ttyr7
/dev/ptyr7
/dev/ttyr8
/dev/ptyr8
/dev/ttyr9
/dev/ptyr9
/dev/ttyra
/dev/ptyra
/dev/ttyrb
/dev/ptyrb
/dev/ttyrc
/dev/ptyrc
/dev/ttyrd
/dev/ptyrd
/dev/ttyre
/dev/ptyre
/dev/ttyrf
/dev/ptyrf
/dev/ttys0
/dev/ptys0
/dev/ttys1
/dev/ptys1
/dev/ttys2
/dev/ptys2
/dev/ttys3
/dev/ptys3
/dev/ttys4
/dev/ptys4
/dev/ttys5
/dev/ptys5
/dev/ttys6
/dev/ptys6
/dev/ttys7
/dev/ptys7
/dev/ttys8
/dev/ptys8
/dev/ttys9
/dev/ptys9
/dev/ttysa
/dev/ptysa
/dev/ttysb
/dev/ptysb
/dev/ttysc
/dev/ptysc
/dev/ttysd
/dev/ptysd
/dev/ttyse
/dev/ptyse
/dev/ttysf
/dev/ptysf
/dev/ttyt0
/dev/ptyt0
/dev/ttyt1
/dev/ptyt1
/dev/ttyt2
/dev/ptyt2
/dev/ttyt3
/dev/ptyt3
/dev/ttyt4
/dev/ptyt4
/dev/ttyt5
/dev/ptyt5
/dev/ttyt6
/dev/ptyt6
/dev/ttyt7
/dev/ptyt7
/dev/ttyt8
/dev/ptyt8
/dev/ttyt9
/dev/ptyt9
/dev/ttyta
/dev/ptyta
/dev/ttytb
/dev/ptytb
/dev/ttytc
/dev/ptytc
/dev/ttytd
/dev/ptytd
/dev/ttyte
/dev/ptyte
/dev/ttytf
/dev/ptytf
/dev/ttyu0
/dev/ptyu0
/dev/ttyu1
/dev/ptyu1
/dev/ttyu2
/dev/ptyu2
/dev/ttyu3
/dev/ptyu3
/dev/ttyu4
/dev/ptyu4
/dev/ttyu5
/dev/ptyu5
/dev/ttyu6
/dev/ptyu6
/dev/ttyu7
/dev/ptyu7
/dev/ttyu8
/dev/ptyu8
/dev/ttyu9
/dev/ptyu9
/dev/ttyua
/dev/ptyua
/dev/ttyub
/dev/ptyub
/dev/ttyuc
/dev/ptyuc
/dev/ttyud
/dev/ptyud
/dev/ttyue
/dev/ptyue
/dev/ttyuf
/dev/ptyuf
/dev/ttyv0
/dev/ptyv0
/dev/ttyv1
/dev/ptyv1
/dev/ttyv2
/dev/ptyv2
/dev/ttyv3
/dev/ptyv3
/dev/ttyv4
/dev/ptyv4
/dev/ttyv5
/dev/ptyv5
/dev/ttyv6
/dev/ptyv6
/dev/ttyv7
/dev/ptyv7
/dev/ttyv8
/dev/ptyv8
/dev/ttyv9
/dev/ptyv9
/dev/ttyva
/dev/ptyva
/dev/ttyvb
/dev/ptyvb
/dev/ttyvc
/dev/ptyvc
/dev/ttyvd
/dev/ptyvd
/dev/ttyve
/dev/ptyve
/dev/ttyvf
/dev/ptyvf
/dev/ttyw0
/dev/ptyw0
/dev/ttyw1
/dev/ptyw1
/dev/ttyw2
/dev/ptyw2
/dev/ttyw3
/dev/ptyw3
/dev/ttyw4
/dev/ptyw4
/dev/ttyw5
/dev/ptyw5
/dev/ttyw6
/dev/ptyw6
/dev/ttyw7
/dev/ptyw7
/dev/ttyw8
/dev/ptyw8
/dev/ttyw9
/dev/ptyw9
/dev/ttywa
/dev/ptywa
/dev/ttywb
/dev/ptywb
/dev/ttywc
/dev/ptywc
/dev/ttywd
/dev/ptywd
/dev/ttywe
/dev/ptywe
/dev/ttywf
/dev/ptywf
/dev/ptmx
/dev/bpf0
/dev/bpf1
/dev/bpf2
/dev/bpf3
/dev/fsevents
/dev/random
/dev/urandom
/dev/dtrace
/dev/lockstat
/dev/sdt
/dev/systrace
/dev/machtrace
/dev/fbt
/dev/profile
/dev/afsc_type5
/dev/disk0
/dev/rdisk0
/dev/disk0s1
/dev/rdisk0s1
/dev/disk0s2
/dev/rdisk0s2
/dev/disk1
/dev/rdisk1
/dev/disk1s6
/dev/rdisk1s6
/dev/disk1s4
/dev/rdisk1s4
/dev/disk1s3
/dev/rdisk1s3
/dev/disk1s1
/dev/rdisk1s1
/dev/disk1s5
/dev/rdisk1s5
/dev/disk1s7
/dev/rdisk1s7
/dev/disk1s2
/dev/rdisk1s2
/dev/disk1s5s1
/dev/rdisk1s5s1
/dev/xcpm
/dev/disk2
/dev/rdisk2
/dev/disk2s1
/dev/rdisk2s1
/dev/disk2s2
/dev/rdisk2s2
/dev/disk2s3
/dev/rdisk2s3
/dev/disk2s4
/dev/rdisk2s4
/dev/disk3
/dev/rdisk3
/dev/disk3s1
/dev/rdisk3s1
/dev/disk4
/dev/rdisk4
/dev/disk4s1
/dev/rdisk4s1
/dev/disk4s2
/dev/rdisk4s2
/dev/disk4s3
/dev/rdisk4s3
/dev/disk5
/dev/rdisk5
/dev/disk5s1
/dev/rdisk5s1
/dev/disk5s3
/dev/rdisk5s3
/dev/disk5s4
/dev/rdisk5s4
/dev/nfsclnt
/dev/uart.BLTH
/dev/cu.BLTH
/dev/tty.BLTH
/dev/autofs
/dev/ttys000
/dev/ttys001
/dev/ttys002
/dev/ttys003
/dev/ttys004
/dev/ttys005
/dev/ttys006
/dev/ttys007
/dev/ttys008
/dev/ttys009
/dev/ttys010
/dev/ttys011
/dev/ttys012
/dev/ttys013
/dev/ttys014
/dev/ttys015
/dev/ttys016
/dev/ttys017
/dev/ttys018
/dev/ttys019
/dev/ttys020
/dev/ttys021
/dev/ttys022
/dev/ttys023
/dev/ttys024
/dev/ttys025
/dev/ttys026
/dev/ttys027
/dev/ttys028
/dev/ttys029
/dev/ttys030
/dev/ttys031
/dev/ttys032
/dev/ttys033
/dev/ttys034
/dev/ttys035
/dev/ttys036
/dev/disk7
/dev/rdisk7
/dev/disk7s1
/dev/rdisk7s1
/dev/nsmb0
/dev/disk6
/dev/rdisk6
/dev/disk6s1
/dev/rdisk6s1
/dev/disk6s2
/dev/rdisk6s2
/dev/ttys037
/dev/ttys038
/dev/tty.Bluetooth-Incoming-Port
/dev/fd/1
/dev/fd/0
/dev/fd/2
  406 device(s) found
```

and (with Pantheios)

```
[example_c_9.1, May 02 09:34:09.063; Debug]: Recls_Search(/dev/, *, 00010008, ...)
[example_c_9.1, May 02 09:34:09.064; Debug]: Recls_SearchFeedback_(/dev/, *, 0x10008, 0x0, 0x0, ...)
[example_c_9.1, May 02 09:34:09.064; Debug]: FindAndCreate(flags=00010008, searchDir='/dev/', patterns='*')
[example_c_9.1, May 02 09:34:09.064; Debug]: FindAndCreate(flags=00010008, dc=0x600002130280, searchDir='/dev/' (5), rootDirLen=5, patterns='*')
/dev/oslog_stream
/dev/auditsessions
/dev/dtracehelper
/dev/autofs_nowait
/dev/autofs_notrigger
/dev/autofs_homedirmounter
/dev/autofs_control
/dev/cu.Bluetooth-Incoming-Port
/dev/tty
/dev/console
/dev/null
/dev/zero
/dev/klog
/dev/oslog
/dev/stdin
/dev/stdout
/dev/stderr
/dev/auditpipe
/dev/pf
/dev/pfm
/dev/ttyp0
/dev/ptyp0
/dev/ttyp1
/dev/ptyp1
/dev/ttyp2
/dev/ptyp2
/dev/ttyp3
/dev/ptyp3
/dev/ttyp4
/dev/ptyp4
/dev/ttyp5
/dev/ptyp5
/dev/ttyp6
/dev/ptyp6
/dev/ttyp7
/dev/ptyp7
/dev/ttyp8
/dev/ptyp8
/dev/ttyp9
/dev/ptyp9
/dev/ttypa
/dev/ptypa
/dev/ttypb
/dev/ptypb
/dev/ttypc
/dev/ptypc
/dev/ttypd
/dev/ptypd
/dev/ttype
/dev/ptype
/dev/ttypf
/dev/ptypf
/dev/ttyq0
/dev/ptyq0
/dev/ttyq1
/dev/ptyq1
/dev/ttyq2
/dev/ptyq2
/dev/ttyq3
/dev/ptyq3
/dev/ttyq4
/dev/ptyq4
/dev/ttyq5
/dev/ptyq5
/dev/ttyq6
/dev/ptyq6
/dev/ttyq7
/dev/ptyq7
/dev/ttyq8
/dev/ptyq8
/dev/ttyq9
/dev/ptyq9
/dev/ttyqa
/dev/ptyqa
/dev/ttyqb
/dev/ptyqb
/dev/ttyqc
/dev/ptyqc
/dev/ttyqd
/dev/ptyqd
/dev/ttyqe
/dev/ptyqe
/dev/ttyqf
/dev/ptyqf
/dev/ttyr0
/dev/ptyr0
/dev/ttyr1
/dev/ptyr1
/dev/ttyr2
/dev/ptyr2
/dev/ttyr3
/dev/ptyr3
/dev/ttyr4
/dev/ptyr4
/dev/ttyr5
/dev/ptyr5
/dev/ttyr6
/dev/ptyr6
/dev/ttyr7
/dev/ptyr7
/dev/ttyr8
/dev/ptyr8
/dev/ttyr9
/dev/ptyr9
/dev/ttyra
/dev/ptyra
/dev/ttyrb
/dev/ptyrb
/dev/ttyrc
/dev/ptyrc
/dev/ttyrd
/dev/ptyrd
/dev/ttyre
/dev/ptyre
/dev/ttyrf
/dev/ptyrf
/dev/ttys0
/dev/ptys0
/dev/ttys1
/dev/ptys1
/dev/ttys2
/dev/ptys2
/dev/ttys3
/dev/ptys3
/dev/ttys4
/dev/ptys4
/dev/ttys5
/dev/ptys5
/dev/ttys6
/dev/ptys6
/dev/ttys7
/dev/ptys7
/dev/ttys8
/dev/ptys8
/dev/ttys9
/dev/ptys9
/dev/ttysa
/dev/ptysa
/dev/ttysb
/dev/ptysb
/dev/ttysc
/dev/ptysc
/dev/ttysd
/dev/ptysd
/dev/ttyse
/dev/ptyse
/dev/ttysf
/dev/ptysf
/dev/ttyt0
/dev/ptyt0
/dev/ttyt1
/dev/ptyt1
/dev/ttyt2
/dev/ptyt2
/dev/ttyt3
/dev/ptyt3
/dev/ttyt4
/dev/ptyt4
/dev/ttyt5
/dev/ptyt5
/dev/ttyt6
/dev/ptyt6
/dev/ttyt7
/dev/ptyt7
/dev/ttyt8
/dev/ptyt8
/dev/ttyt9
/dev/ptyt9
/dev/ttyta
/dev/ptyta
/dev/ttytb
/dev/ptytb
/dev/ttytc
/dev/ptytc
/dev/ttytd
/dev/ptytd
/dev/ttyte
/dev/ptyte
/dev/ttytf
/dev/ptytf
/dev/ttyu0
/dev/ptyu0
/dev/ttyu1
/dev/ptyu1
/dev/ttyu2
/dev/ptyu2
/dev/ttyu3
/dev/ptyu3
/dev/ttyu4
/dev/ptyu4
/dev/ttyu5
/dev/ptyu5
/dev/ttyu6
/dev/ptyu6
/dev/ttyu7
/dev/ptyu7
/dev/ttyu8
/dev/ptyu8
/dev/ttyu9
/dev/ptyu9
/dev/ttyua
/dev/ptyua
/dev/ttyub
/dev/ptyub
/dev/ttyuc
/dev/ptyuc
/dev/ttyud
/dev/ptyud
/dev/ttyue
/dev/ptyue
/dev/ttyuf
/dev/ptyuf
/dev/ttyv0
/dev/ptyv0
/dev/ttyv1
/dev/ptyv1
/dev/ttyv2
/dev/ptyv2
/dev/ttyv3
/dev/ptyv3
/dev/ttyv4
/dev/ptyv4
/dev/ttyv5
/dev/ptyv5
/dev/ttyv6
/dev/ptyv6
/dev/ttyv7
/dev/ptyv7
/dev/ttyv8
/dev/ptyv8
/dev/ttyv9
/dev/ptyv9
/dev/ttyva
/dev/ptyva
/dev/ttyvb
/dev/ptyvb
/dev/ttyvc
/dev/ptyvc
/dev/ttyvd
/dev/ptyvd
/dev/ttyve
/dev/ptyve
/dev/ttyvf
/dev/ptyvf
/dev/ttyw0
/dev/ptyw0
/dev/ttyw1
/dev/ptyw1
/dev/ttyw2
/dev/ptyw2
/dev/ttyw3
/dev/ptyw3
/dev/ttyw4
/dev/ptyw4
/dev/ttyw5
/dev/ptyw5
/dev/ttyw6
/dev/ptyw6
/dev/ttyw7
/dev/ptyw7
/dev/ttyw8
/dev/ptyw8
/dev/ttyw9
/dev/ptyw9
/dev/ttywa
/dev/ptywa
/dev/ttywb
/dev/ptywb
/dev/ttywc
/dev/ptywc
/dev/ttywd
/dev/ptywd
/dev/ttywe
/dev/ptywe
/dev/ttywf
/dev/ptywf
/dev/ptmx
/dev/bpf0
/dev/bpf1
/dev/bpf2
/dev/bpf3
/dev/fsevents
/dev/random
/dev/urandom
/dev/dtrace
/dev/lockstat
/dev/sdt
/dev/systrace
/dev/machtrace
/dev/fbt
/dev/profile
/dev/afsc_type5
/dev/disk0
/dev/rdisk0
/dev/disk0s1
/dev/rdisk0s1
/dev/disk0s2
/dev/rdisk0s2
/dev/disk1
/dev/rdisk1
/dev/disk1s6
/dev/rdisk1s6
/dev/disk1s4
/dev/rdisk1s4
/dev/disk1s3
/dev/rdisk1s3
/dev/disk1s1
/dev/rdisk1s1
/dev/disk1s5
/dev/rdisk1s5
/dev/disk1s7
/dev/rdisk1s7
/dev/disk1s2
/dev/rdisk1s2
/dev/disk1s5s1
/dev/rdisk1s5s1
/dev/xcpm
/dev/disk2
/dev/rdisk2
/dev/disk2s1
/dev/rdisk2s1
/dev/disk2s2
/dev/rdisk2s2
/dev/disk2s3
/dev/rdisk2s3
/dev/disk2s4
/dev/rdisk2s4
/dev/disk3
/dev/rdisk3
/dev/disk3s1
/dev/rdisk3s1
/dev/disk4
/dev/rdisk4
/dev/disk4s1
/dev/rdisk4s1
/dev/disk4s2
/dev/rdisk4s2
/dev/disk4s3
/dev/rdisk4s3
/dev/disk5
/dev/rdisk5
/dev/disk5s1
/dev/rdisk5s1
/dev/disk5s3
/dev/rdisk5s3
/dev/disk5s4
/dev/rdisk5s4
/dev/nfsclnt
/dev/uart.BLTH
/dev/cu.BLTH
/dev/tty.BLTH
/dev/autofs
/dev/ttys000
/dev/ttys001
/dev/ttys002
/dev/ttys003
/dev/ttys004
/dev/ttys005
/dev/ttys006
/dev/ttys007
/dev/ttys008
/dev/ttys009
/dev/ttys010
/dev/ttys011
/dev/ttys012
/dev/ttys013
/dev/ttys014
/dev/ttys015
/dev/ttys016
/dev/ttys017
/dev/ttys018
/dev/ttys019
/dev/ttys020
/dev/ttys021
/dev/ttys022
/dev/ttys023
/dev/ttys024
/dev/ttys025
/dev/ttys026
/dev/ttys027
/dev/ttys028
/dev/ttys029
/dev/ttys030
/dev/ttys031
/dev/ttys032
/dev/ttys033
/dev/ttys034
/dev/ttys035
/dev/ttys036
/dev/disk7
/dev/rdisk7
/dev/disk7s1
/dev/rdisk7s1
/dev/nsmb0
/dev/disk6
/dev/rdisk6
/dev/disk6s1
/dev/rdisk6s1
/dev/disk6s2
/dev/rdisk6s2
/dev/ttys037
/dev/ttys038
/dev/tty.Bluetooth-Incoming-Port
[example_c_9.1, May 02 09:34:09.068; Debug]: FindAndCreate(flags=00010008, dc=0x600002130280, searchDir='/dev/fd' (7), rootDirLen=5, patterns='*')
/dev/fd/1
/dev/fd/0
/dev/fd/2
[example_c_9.1, May 02 09:34:09.068; Debug]: FindAndCreate(flags=00010008, dc=0x600002130280, searchDir='/dev/fd/3' (9), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:34:09.069; Warning]: skipping directory '/dev/fd/3' because it has already been visited by another name: dev=-1131478966, ino=313
[example_c_9.1, May 02 09:34:09.069; Warning]: processing of directory '/dev/fd/3' prevented
[example_c_9.1, May 02 09:34:09.069; Debug]: FindAndCreate(flags=00010008, dc=0x600002130280, searchDir='/dev/fd/4' (9), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:34:09.069; Warning]: skipping directory '/dev/fd/4' because it has already been visited by another name: dev=-1131478966, ino=321
[example_c_9.1, May 02 09:34:09.069; Warning]: processing of directory '/dev/fd/4' prevented
[example_c_9.1, May 02 09:34:09.070; Debug]: Recls_SearchClose(0x600000630090)
  406 device(s) found
```


<!-- ########################### end of file ########################### -->

