# recls Example - **example_c_1**

## Summary

Demonstrates recursive search, via `Recls_Search()`, and display of each full path.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_2/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *            - searching (via Recls_SearchFeedback()) for files
 *            - use of multi-part pattern matching
 *            - recursive operation
 *            - display of full path of each entry
 *            - handling of errors and reporting of error information
 *            - elicitation of entry properties via entry structure
 *              members
 *            - display of progress (of each directory traversed)
 *
 * Created: 29th May 2006
 * Updated: 12th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>
#include <recls/internal/safestr.h>

/* STLSoft header files */
#include <stlsoft/memory/auto_buffer.h>
#include <platformstl/system/console_functions.h>

/* Standard C Library Files */
#include <stdio.h>      /* for printf() / fprintf()         */
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */
#include <string.h>


/* /////////////////////////////////////////////////////////////////////////
 * macros
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define printf                                             wprintf
# define fprintf                                            fwprintf
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */


/* /////////////////////////////////////////////////////////////////////////
 * constants and definitions
 */

#define DEFAULT_CONSOLE_WIDTH                               (256)
#define MIN_CONSOLE_WIDTH                                   (40)
#define MAX_CONSOLE_WIDTH                                   (2048)


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void write_backs(FILE* stm, size_t n);
static void write_blanks(FILE* stm, size_t n);
static void write_blank_line(FILE* stm, size_t n);
static size_t get_console_width(void);
static int RECLS_CALLCONV_DEFAULT
example_c_2_progress_fn(
    recls_char_t const*         dir
,   size_t                      dirLen
,   recls_process_fn_param_t    param
,   void*                       reserved0
,   recls_uint32_t              reserved1
);


/* /////////////////////////////////////////////////////////////////////////
 * types
 */

struct feedback_t
{
    size_t lastLen;
};


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

int main(int argc, char* argv[])
{
    const recls_char_t  SEARCH_PATTERN[]    =   RECLS_LITERAL("*.c|*.cpp|*.cs|*.go|*.h|*.hpp|*.java|*.js|*.pl|*.py|*.rb|*.rs|*.ts");

    struct feedback_t   feedback    =   { 0 };
    hrecls_t            hSrch;
    recls_uint32_t      flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
    char const* const   search_dir  =   argc > 1 ? argv[1] : RECLS_LITERAL(".");
    recls_rc_t          rc;

    if (platformstl_C_isatty_stm(stdout))
    {
        rc = Recls_SearchFeedback(search_dir, SEARCH_PATTERN, flags, example_c_2_progress_fn, &feedback, &hSrch);
    }
    else
    {
        rc = Recls_Search(search_dir, SEARCH_PATTERN, flags, &hSrch);
    }

    if (RECLS_RC_OK != rc)
    {
        recls_char_t    err[1001];
        size_t  n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("Search in '%s' failed: %s\n"), search_dir, err);

        return EXIT_FAILURE;
    }
    else
    {
        recls_info_t    entry;

        Recls_GetDetails(hSrch, &entry);

        do
        {
            if (0 != feedback.lastLen)
            {
                write_blank_line(stdout, feedback.lastLen);
                feedback.lastLen = 0;
            }


            /* full path */
            printf(RECLS_LITERAL("%.*s\n"), (int)(entry->path.end - entry->path.begin), entry->path.begin);

            Recls_CloseDetails(entry);
        }
        while (RECLS_SUCCEEDED(Recls_GetNextDetails(hSrch, &entry)));

        Recls_SearchClose(hSrch);

        if (0 != feedback.lastLen)
        {
            write_backs(stdout, feedback.lastLen);
            write_blanks(stdout, feedback.lastLen);
            write_backs(stdout, feedback.lastLen);
        }

        return EXIT_SUCCESS;
    }
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementions
 */

static void write_chars(
    recls_char_t*   buff
,   recls_char_t    ch
,   size_t          n
)
{
    size_t i;

    for (i = 0; i != n; ++i)
    {
        buff[i] = ch;
    }
}

static void write_backs(FILE* stm, size_t n)
{
    static recls_char_t backs[MAX_CONSOLE_WIDTH];

    write_chars(&backs[0], '\b', n);

    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &backs[0]);
    fflush(stm);
}

static void write_blanks(FILE* stm, size_t n)
{
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&blanks[0], ' ', n);

    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &blanks[0]);
    fflush(stm);
}

static void write_blank_line(FILE* stm, size_t n)
{
    static recls_char_t backs[MAX_CONSOLE_WIDTH];
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&backs[0], '\b', n);
    write_chars(&blanks[0], ' ', n);

    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &backs[0]);
    fflush(stm);
    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &blanks[0]);
    fflush(stm);
    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &backs[0]);
    fflush(stm);
}

static size_t get_console_width(void)
{
    size_t w = platformstl_C_get_console_width();

    if (w > MAX_CONSOLE_WIDTH)
    {
        w = MAX_CONSOLE_WIDTH;
    }

    return w;
}

static int RECLS_CALLCONV_DEFAULT
example_c_2_progress_fn(
    recls_char_t const*         dir
,   size_t                      dirLen
,   recls_process_fn_param_t    param
,   void*                       reserved0
,   recls_uint32_t              reserved1
)
{
    size_t const consoleWidth = get_console_width() - 1;

    STLSOFT_ASSERT(NULL != param);

    ((void)reserved0);
    ((void)reserved1);

    if (consoleWidth >= MIN_CONSOLE_WIDTH)
    {
        STLSOFT_C_AUTO_BUFFER_DECLARE(char, DEFAULT_CONSOLE_WIDTH, squeezedForm);

        if (0 != STLSOFT_C_AUTO_BUFFER_INITIALISE(squeezedForm, consoleWidth + 1))
        {
            fprintf(stderr, "failed to allocate memory\n");

            abort();
        }
        else
        {
            struct feedback_t* const    feedback        =   (struct feedback_t*)param;
            size_t                      newLen;
            size_t                      cch;

            if (consoleWidth < dirLen)
            {
                cch = Recls_SqueezePath(dir, squeezedForm.ptr, squeezedForm.size);

                dir = squeezedForm.ptr;
            }
            else
            {
                cch = dirLen;
            }

            write_backs(stdout, feedback->lastLen);

            newLen = (size_t)fprintf(stdout, RECLS_LITERAL("%.*s"), (int)cch, dir);

            if (newLen < feedback->lastLen)
            {
                size_t const spare = feedback->lastLen - newLen;

                write_blanks(stdout, spare);
                write_backs(stdout, spare);
            }

            feedback->lastLen = newLen;

            STLSOFT_C_AUTO_BUFFER_FREE(squeezedForm);
        }
    }

    return 1; /* Continue processing. */
}


/* ///////////////////////////// end of file //////////////////////////// */
```


## Discussion

The program creates a recursive (`RECLS_F_RECURSIVE`) search from the current directory (`"."`) for files (`RECLS_F_FILES`) obtaining a search handle (`hSrch`). The return code (`rc`) is checked against `RECLS_RC_NO_MORE_DATA`, which means that the search was created successfully but obtained no matches. If the search otherwise failed (as per the check `RECLS_FAILED()`) then a description of the reason for the failure is obtained (by `Recls_GetErrorString()`) and written to `stderr`.

If the search succeeds (and is non-empty), then the details of the first match are obtained by `Recls_GetDetails()` and then displayed in a loop, the terminating condition of which is determined by repeated calls to `Recls_GetNextDetails()`.

Finally, the search handle is closed (and all its associated resources) by `Recls_SearchClose()`.


## Example results

```
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.c.retcodes/test.unit.c.retcodes.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.stat/test.unit.api.stat.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.combine_paths/test.unit.api.combine_paths.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/implicit_link.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/unit/test.unit.api.create_directory/test.unit.api.create_directory.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.is_socket/entry.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/component/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.with_pantheios/test.scratch.with_pantheios.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.cpp_api/test.scratch.cpp_api.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/test.scratch.search.1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.search.1/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test_c_1/test_c_1.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/implicit_link.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/test/scratch/test.scratch.links/test.scratch.links.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/assert.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/ftp.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/implicit_link.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/recls.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/unix.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/windows.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/fwd.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/recls.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_borland.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_ch.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_clang.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_como.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_dmc.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_gcc.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_intel.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_msvc.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_mwerks.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_vectorc.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/compiler_watcom.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/language.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/platform.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/platform_types.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/recls_filesize.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/recls_time.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/retcodes.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/safestr.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/internal/warning/msvc.suppress.4530.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/classfwd.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/common.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/directory_parts.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/entry.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/exceptions.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/ftp_search_sequence.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/root_sequence.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/search_sequence.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/traits.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/unix.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/util.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/windows.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/include/recls/cpp/internal/sequence_helper.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/projects/core/pch.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/projects/core/pch.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/projects/core/_dev_pragmatics_/warnings.msvc.10+.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_1/main.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_3/main.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/cpp/example_cpp_2/main.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_3/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_4/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_5/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_2/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_7/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_8/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_1/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/examples/c/example_c_6/main.c
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearch.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearchDirectoryNode.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearchDirectoryNode_windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearch_windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsSearch.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.entryinfo.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.error.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.extended.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.ftp.windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.retcodes.windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.search.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.unix.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.combine_paths.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.create_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.derive_relative_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.get_file_sizes.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.remove_directory.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.squeeze_path.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.util.stat.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/api.windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.api.search.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.entryinfo.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.unix.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.fileinfo.windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.snprintf.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.trace.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.util.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.util.unix.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.util.windows.cpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.api.search.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.assert.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.atomic.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.entryfunctions.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.root.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.trace.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.util.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/incl.inetstl.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/incl.platformstl.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/incl.stlsoft.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/incl.unixstl.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/incl.winstl.h
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearch.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFileSearchDirectoryNode.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearch.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsFtpSearchDirectoryNode_windows.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/ReclsSearch.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.constants.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.entryinfo.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.string.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.types.ftp.hpp
/Users/user/dev/synesissoftware/freelibs/recls/recls/src/impl.types.hpp
```


<!-- ########################### end of file ########################### -->

