/* /////////////////////////////////////////////////////////////////////////
 * File:    test_c_1.c
 *
 * Purpose: Demonstrates use of recls C API functions for accessing entry
 *          attributes, searching for files under the home directory.
 *
 * Created: 28th February 2007
 * Updated: 20th February 2025
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.h>
#ifdef RECLS_PLATFORM_IS_WINDOWS
# include <recls/ftp.h>
#endif /* platform */

/* STLSoft header files */
#include <stlsoft/stlsoft.h>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void process_search(hrecls_t hSrch);


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int argc, char* argv[])
{
    hrecls_t    hSrch;
    recls_rc_t  rc;

    printf("searching for '*.txt|*.cpp' under ~\n");

#if 0
    {
        recls_info_t    hEntry;

        Recls_Stat("~/abc", RECLS_F_DETAILS_LATER, &hEntry);

        Recls_Stat("/", 0, &hEntry);
    }
#endif /* 0 */

#if 0
    rc = Recls_Search(".", NULL, RECLS_F_RECURSIVE, &hSrch);
#else /* ? 0 */
# if 0
    rc = Recls_Search(NULL, "H:/dev/bin/*.dll", RECLS_F_RECURSIVE, &hSrch);
# else /* ? 0 */
#  if 1
    rc = Recls_Search("~/", "*.txt;*.cpp", RECLS_F_RECURSIVE, &hSrch);
#  else /* ? 0 */
#   if 0
    rc = Recls_Search(NULL, "H:/dev/bin/VssChangeLister.exe", RECLS_F_RECURSIVE, &hSrch);
#   else /* ? 0 */
    rc = Recls_Search("H:/dev/include", "H:/dev/bin/VssChangeLister.exe", RECLS_F_RECURSIVE, &hSrch);
#   endif /* 0 */
#  endif /* 0 */
# endif /* 0 */
#endif /* 0 */

    if (RECLS_SUCCEEDED(rc))
    {
        if (RECLS_RC_NO_MORE_DATA != rc)
        {
            process_search(hSrch);
        }

        Recls_SearchClose(hSrch);
    }

    printf("\n");


    printf("FTP system:\n");

#ifdef RECLS_PLATFORM_IS_WINDOWS
    rc = Recls_SearchFtp("ftp.digitalmars.com", "anonymous", "anon@mouse.com", "/", "*.zip", RECLS_F_RECURSIVE, &hSrch);

    if (RECLS_SUCCEEDED(rc))
    {
        if (RECLS_RC_NO_MORE_DATA != rc)
        {
            process_search(hSrch);
        }

        Recls_SearchClose(hSrch);
    }
#endif /* platform */

    printf("\n");

    ((void)argc);
    ((void)argv);

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[])
{
    int             res;
#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemState    memState;
#endif /* _MSC_VER && _MSC_VER */

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemCheckpoint(&memState);
#endif /* _MSC_VER && _MSC_VER */

    res = main_(argc, argv);

#if defined(_MSC_VER) && \
    defined(_DEBUG)
    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

static void process_search(hrecls_t hSrch)
{
    size_t (RECLS_CALLCONV_DEFAULT *fns[])(recls_info_t, recls_char_t*, size_t) =
    {
            Recls_GetPathProperty
        ,   Recls_GetSearchRelativePathProperty
        ,   Recls_GetDirectoryProperty
        ,   Recls_GetDirectoryPathProperty
        ,   Recls_GetSearchDirectoryProperty
        ,   Recls_GetUNCDriveProperty
        ,   Recls_GetFileProperty
#ifdef RECLS_PLATFORMS_IS_WINDOWS
        ,   Recls_GetShortFileProperty
#endif /* platform */
        ,   Recls_GetFileNameProperty
        ,   Recls_GetFileExtProperty
        ,
    };

    recls_rc_t  rc;

    for (;;)
    {
        recls_char_t        buff[256];
        recls_info_t        info;
        recls_filesize_t    size;

        rc = Recls_GetDetails(hSrch, &info);

        if (RECLS_SUCCEEDED(rc))
        {
            printf("\t%.*s\n", (int)(info->path.end - info->path.begin), info->path.begin);

            { size_t i; for (i = 0; i < STLSOFT_NUM_ELEMENTS(fns); ++i)
            {
                fns[i](info, &buff[0], STLSOFT_NUM_ELEMENTS(buff));
            }}

            { size_t i; for (i = 0; i < Recls_GetDirectoryPartProperty(info, -1, NULL, 0); ++i)
            {
                Recls_GetDirectoryPartProperty(info, (int)i, &buff[0], STLSOFT_NUM_ELEMENTS(buff));
            }}

            Recls_IsEntryReadOnly(info);
            Recls_IsEntryDirectory(info);
            Recls_IsEntryLink(info);

            Recls_DoesEntryExist(info);
            Recls_IsEntryUNC(info);
            size = Recls_GetSizeProperty(info);
            ((void)&size);
            Recls_GetCreationTime(info);
            Recls_GetModificationTime(info);
            Recls_GetLastAccessTime(info);
            Recls_GetLastStatusChangeTime(info);


            Recls_CloseDetails(info);
        }

        rc = Recls_GetNext(hSrch);

        if (RECLS_FAILED(rc))
        {
            break;
        }
    }
}

/* ///////////////////////////// end of file //////////////////////////// */

