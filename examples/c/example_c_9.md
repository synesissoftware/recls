# recls Example - **example_c_1**

## Summary

Demonstrates recursive search for all sockets under a given directory including all appropriate failure handling.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_9/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching all names
 *  - search recursively for sockets
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
     * pattern matching all names, flags for recursive search of sockets,
     * and start a search.
     */
    hrecls_t        hSrch;
    char const*     search_dir  =   argc > 1 ? argv[1] : ".";
    char const*     patterns    =   Recls_GetWildcardsAll();
    recls_uint32_t  flags       =   RECLS_F_RECURSIVE | RECLS_F_SOCKETS;
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

        printf("  %lu socket(s) found\n", num_entries_found);

        return EXIT_SUCCESS;
    }
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The functionality follows a similar pattern to that demonstrated already in **example_c_1**. The key differences are that the flag `RECLS_F_SOCKETS` is specified absent any of the other type flags (`RECLS_F_DEVICES`, `RECLS_F_DIRECTORIES`, `RECLS_F_FILES`), hence only sockets in the searched directory are listed.

The other difference is the optional use of **Pantheios** to log out progress as the program executes. This is only enabled if **Pantheios** is discovered during the **CMake** configuration phase; if not detected, then the program only produces normative output and contingent reporting.


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_9/example_c_9 /tmp/
```

then it produces results such as (without Pantheios):

```
/tmp/mysocket.sock
/tmp/com.apple.launchd.JhZAEvfZIb/Listeners
  2 socket(s) found
```

and (with Pantheios)

```
[example_c_9.1, May 02 09:28:01.524; Debug]: Recls_Search(/tmp/, *, 00010010, ...)
[example_c_9.1, May 02 09:28:01.525; Debug]: Recls_SearchFeedback_(/tmp/, *, 0x10010, 0x0, 0x0, ...)
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, searchDir='/tmp/', patterns='*')
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/' (5), rootDirLen=5, patterns='*')
/tmp/mysocket.sock
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/powerlog' (13), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/perfcount' (14), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis' (8), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.525; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls' (14), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.526; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test' (19), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.526; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit' (24), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.526; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.squeeze_path' (51), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.526; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.squeeze_path/CMakeFiles' (62), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.526; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.squeeze_path/CMakeFiles/test.unit.api.squeeze_path.dir' (93), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/CMakeFiles' (35), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.retcodes' (47), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.retcodes/CMakeFiles' (58), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.retcodes/CMakeFiles/test.unit.cpp.retcodes.dir' (85), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.c.retcodes' (45), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.c.retcodes/CMakeFiles' (56), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.527; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.c.retcodes/CMakeFiles/test.unit.c.retcodes.dir' (81), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.528; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.squeeze_path' (51), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.528; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.squeeze_path/CMakeFiles' (62), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.528; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.squeeze_path/CMakeFiles/test.unit.cpp.squeeze_path.dir' (93), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.528; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.combine_paths' (52), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.528; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.combine_paths/CMakeFiles' (63), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.529; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.combine_paths/CMakeFiles/test.unit.cpp.combine_paths.dir' (95), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.530; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.util.file_sizes' (50), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.531; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.util.file_sizes/CMakeFiles' (61), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.531; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.util.file_sizes/CMakeFiles/test.unit.util.file_sizes.dir' (91), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.532; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.stat' (43), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.532; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.stat/CMakeFiles' (54), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.532; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.stat/CMakeFiles/test.unit.api.stat.dir' (77), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.532; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.derive_relative_path' (59), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.532; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.derive_relative_path/CMakeFiles' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.cpp.derive_relative_path/CMakeFiles/test.unit.cpp.derive_relative_path.dir' (109), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.combine_paths' (52), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.combine_paths/CMakeFiles' (63), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.combine_paths/CMakeFiles/test.unit.api.combine_paths.dir' (95), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.create_directory' (55), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.create_directory/CMakeFiles' (66), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.533; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/unit/test.unit.api.create_directory/CMakeFiles/test.unit.api.create_directory.dir' (101), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.534; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/CMakeFiles' (30), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.534; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component' (29), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.534; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/CMakeFiles' (40), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.534; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.is_socket' (63), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.is_socket/CMakeFiles' (74), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.is_socket/CMakeFiles/test.component.util.cpp.is_socket.dir' (112), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.create_directory' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.create_directory/CMakeFiles' (81), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.create_directory/CMakeFiles/test.component.util.cpp.create_directory.dir' (126), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.remove_directory' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.remove_directory/CMakeFiles' (81), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.535; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/component/test.component.util.cpp.remove_directory/CMakeFiles/test.component.util.cpp.remove_directory.dir' (126), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch' (27), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/CMakeFiles' (38), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.with_pantheios' (55), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.with_pantheios/CMakeFiles' (66), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.with_pantheios/CMakeFiles/test.scratch.with_pantheios.dir' (98), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.536; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.cpp_api' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.cpp_api/CMakeFiles' (59), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.cpp_api/CMakeFiles/test.scratch.cpp_api.dir' (84), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.ignore_inaccessible_nodes' (66), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.ignore_inaccessible_nodes/CMakeFiles' (77), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.ignore_inaccessible_nodes/CMakeFiles/test.scratch.ignore_inaccessible_nodes.dir' (120), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.537; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.entry_attributes' (57), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.entry_attributes/CMakeFiles' (68), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.entry_attributes/CMakeFiles/test.scratch.entry_attributes.dir' (102), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.search.1' (49), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.search.1/CMakeFiles' (60), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.search.1/CMakeFiles/test_scratch_search_1.dir' (86), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test_c_1' (36), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.538; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test_c_1/CMakeFiles' (47), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test_c_1/CMakeFiles/test_c_1.dir' (60), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.stop_on_access_failure' (63), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.stop_on_access_failure/CMakeFiles' (74), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.stop_on_access_failure/CMakeFiles/test.scratch.stop_on_access_failure.dir' (114), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.links' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.links/CMakeFiles' (57), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.539; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/test/scratch/test.scratch.links/CMakeFiles/test.scratch.links.dir' (80), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/cmake' (20), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles' (25), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyTest.dir' (41), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/3.31.6' (32), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/3.31.6/CompilerIdC' (44), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/3.31.6/CompilerIdC/tmp' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.540; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/3.31.6/CompilerIdCXX' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/3.31.6/CompilerIdCXX/tmp' (50), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalStart.dir' (47), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousStart.dir' (45), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalTest.dir' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousSubmit.dir' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalUpdate.dir' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyBuild.dir' (42), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyCoverage.dir' (45), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.541; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/Nightly.dir' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousCoverage.dir' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalMemCheck.dir' (50), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlySubmit.dir' (43), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/Continuous.dir' (40), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousConfigure.dir' (49), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyStart.dir' (42), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousTest.dir' (44), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.542; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalSubmit.dir' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyMemoryCheck.dir' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousUpdate.dir' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/pkgRedirects' (38), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/Export' (32), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/Export/d9fa4183e8bd26be97399c72bb131f10' (65), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousMemCheck.dir' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalCoverage.dir' (50), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyMemCheck.dir' (45), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.543; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ContinuousBuild.dir' (45), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/Experimental.dir' (42), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalBuild.dir' (47), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/ExperimentalConfigure.dir' (51), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyUpdate.dir' (43), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/CMakeFiles/NightlyConfigure.dir' (46), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/Testing' (22), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/Testing/Temporary' (32), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples' (23), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.544; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/CMakeFiles' (34), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.545; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp' (27), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.545; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_1' (41), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.545; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_1/CMakeFiles' (52), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.545; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_1/CMakeFiles/example_cpp_1.dir' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.545; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/CMakeFiles' (38), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_3' (41), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_3/CMakeFiles' (52), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_3/CMakeFiles/example_cpp_3.dir' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_2' (41), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_2/CMakeFiles' (52), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.546; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/cpp/example_cpp_2/CMakeFiles/example_cpp_2.dir' (70), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c' (25), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/CMakeFiles' (36), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_3' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_3/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_3/CMakeFiles/example_c_3.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_4' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_4/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.547; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_4/CMakeFiles/example_c_4.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_5' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_5/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_5/CMakeFiles/example_c_5.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_2' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_2/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.548; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_2/CMakeFiles/example_c_2.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_7' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_7/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_7/CMakeFiles/example_c_7.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_9' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_9/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.549; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_9/CMakeFiles/example_c_9.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_10' (38), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_10/CMakeFiles' (49), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_10/CMakeFiles/example_c_10.dir' (66), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_8' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_8/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_8/CMakeFiles/example_c_8.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_1' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.550; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_1/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_1/CMakeFiles/example_c_1.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_6' (37), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_6/CMakeFiles' (48), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/examples/c/example_c_6/CMakeFiles/example_c_6.dir' (64), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/src' (18), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/src/CMakeFiles' (29), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.551; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/sis/recls/src/CMakeFiles/core.dir' (38), rootDirLen=5, patterns='*')
[example_c_9.1, May 02 09:28:01.552; Debug]: FindAndCreate(flags=00010010, dc=0x600000b5c280, searchDir='/tmp/com.apple.launchd.JhZAEvfZIb' (33), rootDirLen=5, patterns='*')
/tmp/com.apple.launchd.JhZAEvfZIb/Listeners
[example_c_9.1, May 02 09:28:01.552; Debug]: Recls_SearchClose(0x600002c5c090)
  2 socket(s) found
```


<!-- ########################### end of file ########################### -->

