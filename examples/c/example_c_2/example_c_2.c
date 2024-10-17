/* /////////////////////////////////////////////////////////////////////////
 * File:    example_c_2.c
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
 * Updated: 8th July 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>
#include <recls/internal/safestr.h>

/* STLSoft header files */
#ifdef RECLS_PLATFORM_API_WINDOWS
# include <winstl/system/console_functions.h>
#endif /* RECLS_PLATFORM_API_WINDOWS */

/* Standard C Library Files */
#include <stdio.h>      /* for printf() / fprintf()         */
#include <stdlib.h>     /* for EXIT_SUCCESS / EXIT_FAILURE  */
#include <string.h>

/* /////////////////////////////////////////////////////////////////////////
 * macros and definitions
 */

#ifdef RECLS_CHAR_TYPE_IS_WCHAR
# define printf                                             wprintf
# define fprintf                                            fwprintf
#endif /* RECLS_CHAR_TYPE_IS_WCHAR */

#define MAX_CONSOLE_WIDTH                                   (76)

/* ////////////////////////////////////////////////////////////////////// */

static void write_backs(FILE* stm, size_t n);
static void write_blanks(FILE* stm, size_t n);
static void write_blank_line(FILE* stm, size_t n);
static size_t get_console_width(void);
static int RECLS_CALLCONV_DEFAULT example_c_2_progress_fn(  recls_char_t const*         dir
                                                        ,   size_t                      dirLen
                                                        ,   recls_process_fn_param_t    param
                                                        ,   void*                       reserved0
                                                        ,   recls_uint32_t              reserved1);

/* ////////////////////////////////////////////////////////////////////// */

struct feedback_t
{
    size_t  lastLen;
};

/* ////////////////////////////////////////////////////////////////////// */

int main(int argc, char* argv[])
{
    const recls_char_t  SEARCH_PATTERN[]    =   RECLS_LITERAL("*.h|*.hpp|*.c|*.cpp|*.cs|*.d|*.java|*.pl|*.py|*.rb");

    struct feedback_t   feedback    =   { 0 };
    hrecls_t            hSrch;
    recls_uint32_t      flags       =   RECLS_F_FILES | RECLS_F_RECURSIVE;
    recls_rc_t          rc          =   Recls_SearchFeedback(NULL, SEARCH_PATTERN, flags, example_c_2_progress_fn, &feedback, &hSrch);

    ((void)&argc);
    ((void)&argv);

    if (RECLS_RC_OK != rc)
    {
        recls_char_t    err[1001];
        size_t  n   =   Recls_GetErrorString(rc, &err[0], sizeof(err) - 1);

        err[n] = '\0';

        fprintf(stderr, RECLS_LITERAL("Search failed: %s\n"), err);

        return EXIT_FAILURE;
    }
    else
    {
        recls_info_t    entry;

        Recls_GetDetails(hSrch, &entry);

        do
        {
            size_t n = (size_t)(entry->path.end - entry->path.begin);

            if (n > MAX_CONSOLE_WIDTH - 1)
            {
                n = MAX_CONSOLE_WIDTH - 1;
            }

            write_blank_line(stdout, feedback.lastLen);

            /* full path */
            printf(RECLS_LITERAL("%.*s\n"), (int)n, entry->path.begin);

            Recls_CloseDetails(entry);
        }
        while (RECLS_SUCCEEDED(Recls_GetNextDetails(hSrch, &entry)));

        return EXIT_SUCCESS;
    }
}

/* ////////////////////////////////////////////////////////////////////// */

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
}

static void write_blanks(FILE* stm, size_t n)
{
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&blanks[0], ' ', n);

    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &blanks[0]);
}

static void write_blank_line(FILE* stm, size_t n)
{
    static recls_char_t backs[MAX_CONSOLE_WIDTH];
    static recls_char_t blanks[MAX_CONSOLE_WIDTH];

    write_chars(&backs[0], '\b', n);
    write_chars(&blanks[0], ' ', n);

    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &backs[0]);
    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &blanks[0]);
    fprintf(stm, RECLS_LITERAL("%.*s"), (int)n, &backs[0]);
}

static size_t get_console_width_(void)
{
    /* In reality, this should evaluate as appropriate to the operating
     * system.
     */

#ifdef RECLS_PLATFORM_API_WINDOWS
    return winstl_C_get_console_width();
#else /* ? RECLS_PLATFORM_API_??? */
    return 48;
#endif /* RECLS_PLATFORM_API_??? */
}

static size_t get_console_width(void)
{
    size_t w = get_console_width_();

    if (w > MAX_CONSOLE_WIDTH)
    {
        w = MAX_CONSOLE_WIDTH;
    }

    return w;
}

static int RECLS_CALLCONV_DEFAULT example_c_2_progress_fn(  recls_char_t const*         dir
                                                        ,   size_t                      dirLen
                                                        ,   recls_process_fn_param_t    param
                                                        ,   void*                       reserved0
                                                        ,   recls_uint32_t              reserved1)
{
    struct feedback_t*  feedback        =   (struct feedback_t*)param;
    size_t              newLen;
    size_t              cch;
    size_t              consoleWidth    =   get_console_width() - 1;

    if (consoleWidth < dirLen)
    {
        recls_char_t squeezedForm[MAX_CONSOLE_WIDTH];

        memcpy(squeezedForm, dir, sizeof(squeezedForm[0]) * dirLen);

        squeezedForm[dirLen - 1] = '\0';

        cch = Recls_SqueezePath(squeezedForm, squeezedForm, consoleWidth - 1);

        dir = squeezedForm;
    }
    else
    {
        cch = dirLen;
    }

    write_backs(stdout, feedback->lastLen);

    newLen = (size_t)fprintf(stdout, RECLS_LITERAL("%.*s"), (int)cch, dir);

    if (newLen < feedback->lastLen)
    {
        size_t  spare   =   feedback->lastLen - newLen;

        write_blanks(stdout, spare);
        write_backs(stdout, spare);
    }

    feedback->lastLen = newLen;

    ((void)reserved0);
    ((void)reserved1);

    return 1; /* Continue processing. */
}

/* ///////////////////////////// end of file //////////////////////////// */

