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

