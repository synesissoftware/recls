# recls Example - **example_c_1**

## Summary

Demonstrates recursive search with feedback for all files matching a multi-part pattern under a given directory including all appropriate failure handling.


## Source

```C
/* /////////////////////////////////////////////////////////////////////////
 * File:    examples/c/example_c_2/main.c
 *
 * Purpose: C example program for the recls core library. Demonstrates:
 *
 *  - search in current or named directory
 *  - search matching names with common programming language extensions according to multi-part pattern matching
 *  - search recursively for files
 *  - search by Recls_SearchFeedback() to show directory feedback if a tty; Recls_Search() otherwise
 *  - display of search-relative-path of each entry
 *  - detecting failure and reporting of failure reason
 *  - elicitation of entry properties via entry structure members
 *  - display of progress of each directory traversed, squeezed into the console width via Recls_SqueezePath()
 *
 * Created: 29th May 2006
 * Updated: 15th April 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>
#include <recls/internal/safestr.h>

/* STLSoft header files */
#include <stlsoft/memory/auto_buffer.h>
#include <platformstl/system/console_functions.h>

/* Standard C Library Files */
#include <stdio.h>
#include <stdlib.h>


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
    const recls_char_t  SEARCH_PATTERN[]    =   "*.c|*.cpp|*.cs|*.go|*.h|*.hpp|*.java|*.js|*.pl|*.py|*.rb|*.rs|*.ts";

    hrecls_t            hSrch;
    char const*         search_dir  =   argc > 1 ? argv[1] : ".";
    char const*         patterns    =   SEARCH_PATTERN;
    recls_uint32_t      flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
    recls_rc_t          rc;

    struct feedback_t   feedback    =   { 0 };

    if (platformstl_C_isatty_stm(stdout))
    {
        rc = Recls_SearchFeedback(search_dir, patterns, flags, example_c_2_progress_fn, &feedback, &hSrch);
    }
    else
    {
        rc = Recls_Search(search_dir, SEARCH_PATTERN, flags, &hSrch);
    }

    if (RECLS_RC_OK != rc)
    {
        recls_char_t    err[1001];
        size_t          n;

failed:

        n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, "Search in '%s' failed: %s\n", search_dir, err);

        return EXIT_FAILURE;
    }
    else
    {
        recls_info_t entry;

        Recls_GetDetails(hSrch, &entry);

        do
        {
            if (0 != feedback.lastLen)
            {
                write_blank_line(stdout, feedback.lastLen);
                feedback.lastLen = 0;
            }

            /* full path */
            printf("%.*s\n", (int)(entry->searchRelativePath.end - entry->searchRelativePath.begin), entry->searchRelativePath.begin);

            Recls_CloseDetails(entry);
        }
        while (RECLS_SUCCEEDED(rc = Recls_GetNextDetails(hSrch, &entry)));

        Recls_SearchClose(hSrch);

        if (0 != feedback.lastLen)
        {
            write_backs(stdout, feedback.lastLen);
            write_blanks(stdout, feedback.lastLen);
            write_backs(stdout, feedback.lastLen);
        }

        if (RECLS_RC_NO_MORE_DATA != rc && RECLS_FAILED(rc))
        {
            goto failed;
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

    fprintf(stm, "%.*s", (int)n, &backs[0]);
    fflush(stm);
}

static void write_blanks(FILE* stm, size_t n)
{
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&blanks[0], ' ', n);

    fprintf(stm, "%.*s", (int)n, &blanks[0]);
    fflush(stm);
}

static void write_blank_line(FILE* stm, size_t n)
{
    static recls_char_t backs[MAX_CONSOLE_WIDTH];
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&backs[0], '\b', n);
    write_chars(&blanks[0], ' ', n);

    fprintf(stm, "%.*s", (int)n, &backs[0]);
    fflush(stm);
    fprintf(stm, "%.*s", (int)n, &blanks[0]);
    fflush(stm);
    fprintf(stm, "%.*s", (int)n, &backs[0]);
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

            newLen = (size_t)fprintf(stdout, "%.*s", (int)cch, dir);

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

The main functionality of this program follows that of **example_c_1**, except that the search-relative-path of each entry is printed rather than its full path. The additional functionality is by dint of the use of feedback processing, via `Recls_SearchFeedback()` (but only in the case where the standard output stream is a tty).

The call to `Recls_SearchFeedback()` is passed the callback function `example_c_2_progress_fn()` which has two responsibilities:
* write the currently-being-searched directory - `dir` and `dirLen` - to the standard output stream, squeezed into the width of the console by `Recls_SqueezePath()`; and
* erasing the previously-written directory and returning the print-position ready for the next one or for the entry to be written (without subsequent erasure);


## Example results

When configured, built, and run specify the **test** directory

```
$ ./prepare_cmake.sh
$ ./build_cmake.sh
$ ./_build/examples/c/example_c_2/example_c_2 .
```

then it produces results such as:

```
test/unit/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c
test/unit/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp
test/unit/test.unit.c.retcodes/test.unit.c.retcodes.c
test/unit/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp
test/unit/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp
test/unit/test.unit.api.stat/test.unit.api.stat.c
test/unit/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp
test/unit/test.unit.api.combine_paths/test.unit.api.combine_paths.c
test/unit/test.unit.api.create_directory/test.unit.api.create_directory.c
test/component/test.component.util.cpp.is_socket/entry.cpp
test/component/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp
test/component/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp
test/scratch/test.scratch.with_pantheios/test.scratch.with_pantheios.cpp
test/scratch/test.scratch.cpp_api/test.scratch.cpp_api.cpp
test/scratch/test.scratch.search.1/test.scratch.search.1.c
test/scratch/test_c_1/test_c_1.c
test/scratch/test.scratch.links/test.scratch.links.cpp
include/recls/assert.h
include/recls/ftp.h
include/recls/implicit_link.h
include/recls/recls.h
include/recls/unix.h
include/recls/windows.h
include/recls/fwd.hpp
include/recls/recls.hpp
include/recls/internal/compiler.h
include/recls/internal/compiler_borland.h
include/recls/internal/compiler_ch.h
include/recls/internal/compiler_clang.h
include/recls/internal/compiler_como.h
include/recls/internal/compiler_dmc.h
include/recls/internal/compiler_gcc.h
include/recls/internal/compiler_intel.h
include/recls/internal/compiler_msvc.h
include/recls/internal/compiler_mwerks.h
include/recls/internal/compiler_vectorc.h
include/recls/internal/compiler_watcom.h
include/recls/internal/language.h
include/recls/internal/platform.h
include/recls/internal/platform_types.h
include/recls/internal/recls_filesize.h
include/recls/internal/recls_time.h
include/recls/internal/retcodes.h
include/recls/internal/safestr.h
include/recls/internal/warning/msvc.suppress.4530.h
include/recls/cpp/classfwd.hpp
include/recls/cpp/common.hpp
include/recls/cpp/directory_parts.hpp
include/recls/cpp/entry.hpp
include/recls/cpp/exceptions.hpp
include/recls/cpp/ftp_search_sequence.hpp
include/recls/cpp/root_sequence.hpp
include/recls/cpp/search_sequence.hpp
include/recls/cpp/traits.hpp
include/recls/cpp/unix.hpp
include/recls/cpp/util.hpp
include/recls/cpp/windows.hpp
include/recls/cpp/internal/sequence_helper.hpp
projects/core/pch.cpp
projects/core/pch.hpp
projects/core/_dev_pragmatics_/warnings.msvc.10+.h
examples/cpp/example_cpp_1/main.cpp
examples/cpp/example_cpp_3/main.cpp
examples/cpp/example_cpp_2/main.cpp
examples/c/example_c_3/main.c
examples/c/example_c_4/main.c
examples/c/example_c_5/main.c
examples/c/example_c_2/main.c
examples/c/example_c_7/main.c
examples/c/example_c_8/main.c
examples/c/example_c_1/main.c
examples/c/example_c_6/main.c
src/ReclsFileSearch.cpp
src/ReclsFileSearchDirectoryNode.cpp
src/ReclsFtpSearchDirectoryNode_windows.cpp
src/ReclsFtpSearch_windows.cpp
src/ReclsSearch.cpp
src/api.entryinfo.cpp
src/api.error.cpp
src/api.extended.cpp
src/api.ftp.windows.cpp
src/api.retcodes.windows.cpp
src/api.search.cpp
src/api.unix.cpp
src/api.util.combine_paths.cpp
src/api.util.create_directory.cpp
src/api.util.derive_relative_path.cpp
src/api.util.get_file_sizes.cpp
src/api.util.remove_directory.cpp
src/api.util.squeeze_path.cpp
src/api.util.stat.cpp
src/api.windows.cpp
src/impl.api.search.cpp
src/impl.entryinfo.cpp
src/impl.fileinfo.cpp
src/impl.fileinfo.unix.cpp
src/impl.fileinfo.windows.cpp
src/impl.snprintf.cpp
src/impl.trace.cpp
src/impl.util.cpp
src/impl.util.unix.cpp
src/impl.util.windows.cpp
src/impl.api.search.h
src/impl.assert.h
src/impl.atomic.h
src/impl.entryfunctions.h
src/impl.root.h
src/impl.trace.h
src/impl.util.h
src/incl.inetstl.h
src/incl.platformstl.h
src/incl.stlsoft.h
src/incl.unixstl.h
src/incl.winstl.h
src/ReclsFileSearch.hpp
src/ReclsFileSearchDirectoryNode.hpp
src/ReclsFtpSearch.hpp
src/ReclsFtpSearchDirectoryNode_windows.hpp
src/ReclsSearch.hpp
src/impl.constants.hpp
src/impl.entryinfo.hpp
src/impl.string.hpp
src/impl.types.ftp.hpp
src/impl.types.hpp
```


<!-- ########################### end of file ########################### -->

