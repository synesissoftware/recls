/* /////////////////////////////////////////////////////////////////////////
 * File:    test.scratch.cpp_api.cpp
 *
 * Purpose: Scratch-test exercising various parts of recls C++ API.
 *
 * Created: 4th January 2010
 * Updated: 17th October 2024
 *
 * ////////////////////////////////////////////////////////////////////// */


/* recls header files */
#include <recls/recls.hpp>

/* STLSoft header files */
#include <platformstl/platformstl.hpp>
#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)

# include <platformstl/filesystem/current_directory_scope.hpp>
# include <platformstl/filesystem/path.hpp>
#endif
#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/conversion/char_conversions.hpp>
#else
# error platform not discriminated
#endif

/* Standard C++ header files */
#include <exception>
#include <iostream>
#include <iomanip>

/* Standard C header files */
#include <stdio.h>
#include <stdlib.h>

#if 0
#elif defined(PLATFORMSTL_OS_IS_UNIX)
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <tchar.h>
#else
# error platform not discriminated
#endif

#if defined(_MSC_VER) && \
    defined(_DEBUG)
# include <crtdbg.h>
#endif /* _MSC_VER) && _DEBUG */


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

static void display_entry(recls::entry const& fe);


/* /////////////////////////////////////////////////////////////////////////
 * forward declarations
 */

namespace {

    recls::char_t const s_CR[]      =   RECLS_LITERAL("\n");
    recls::char_t const s_false[]   =   RECLS_LITERAL("false");
    recls::char_t const s_true[]    =   RECLS_LITERAL("true");

    using recls::string_t;

#ifdef RECLS_CHAR_TYPE_IS_WCHAR

# define _tcerr                                             wcerr
# define _tcout                                             wcout
#else

# define _tcerr                                             cerr
# define _tcout                                             cout
#endif
} /* anonymous namespace */


/* /////////////////////////////////////////////////////////////////////////
 * main()
 */

static int main_(int /* argc */, char* argv[])
{
    using namespace recls;

    { // roots

        recls::cpp::root_sequence   roots;

        std::_tcout << s_CR << RECLS_LITERAL("Roots:") << std::endl;
        { for (root_sequence::const_iterator i = roots.begin(), e = roots.end(); i != e; ++i)
        {
            std::_tcout << s_CR << RECLS_LITERAL("    ") << *i << std::endl;
        }}
    }

    { // stat()

        std::_tcout << s_CR << RECLS_LITERAL("stat:") << std::endl;

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(\".\"):") << std::endl;

            recls::cpp::entry e = recls::cpp::stat(RECLS_LITERAL("."));

            display_entry(e);
        }

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(\"./\"):") << std::endl;

            recls::cpp::entry e = recls::cpp::stat(RECLS_LITERAL("./"));

            display_entry(e);
        }

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(argv[0]):") << std::endl;

#if defined(PLATFORMSTL_OS_IS_WINDOWS)

            recls::cpp::entry e = recls::cpp::stat(winstl::a2t(argv[0]), recls::DIRECTORY_PARTS);
#else

            recls::cpp::entry e = recls::cpp::stat(argv[0], recls::DIRECTORY_PARTS);
#endif

            display_entry(e);
        }

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(\"~\"):") << std::endl;

            recls::cpp::entry e = recls::cpp::stat(RECLS_LITERAL("~"));

            display_entry(e);
        }

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(\"~/\"):") << std::endl;

            recls::cpp::entry e = recls::cpp::stat(RECLS_LITERAL("~/"));

            display_entry(e);
        }

        {
            std::_tcout << s_CR << RECLS_LITERAL("  stat(\"/\"):") << std::endl;

            recls::cpp::entry e = recls::cpp::stat(RECLS_LITERAL("/"));

            display_entry(e);
        }
    }

    { // search_sequence

        std::_tcout << s_CR << RECLS_LITERAL("files under \"..\":") << std::endl;

        recls::cpp::search_sequence files(RECLS_LITERAL(".."), Recls_GetWildcardsAll(), recls::FILES | recls::RECURSIVE | recls::DIRECTORY_PARTS);

        { for (search_sequence::const_iterator i = files.begin(), e = files.end(); i != e; ++i)
        {
            display_entry(*i);
        }}
    }

    { // search_sequence

        string_t first_path;

        std::_tcout << s_CR << RECLS_LITERAL("custom searches, to illustrate flexibility in API:") << std::endl;

        std::_tcout << RECLS_LITERAL("  ") << RECLS_LITERAL("search (from '~' for all files and break after first file):") << std::endl;

        recls::cpp::search_sequence files0(RECLS_LITERAL("~/"), Recls_GetWildcardsAll(), recls::FILES | recls::RECURSIVE | recls::DIRECTORY_PARTS);

        { for (search_sequence::const_iterator i = files0.begin(), e = files0.end(); i != e; )
        {
            display_entry(*i);

            recls::entry first(*i);

            first_path.assign(first.get_path().c_str());

            break;
        }}

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
        {
            // since we're synthesising, and UNIX uses ':' as a patterns separator, and full Windows
            // paths that are drive rooted are of the form 'H:\...', we need to change to the root dir
            // and change the first_path

            platformstl::path   p(first_path);
            string_t            root(p.get_location().ptr, p.get_location().len);

            first_path.erase(first_path.begin(), first_path.begin() + p.get_location().len);

            platformstl::current_directory_scope    scoper(root);
#endif

        {
            std::_tcout << RECLS_LITERAL("  ") << RECLS_LITERAL("search using first path as patterns (and null as search-root):") << std::endl;

            recls::cpp::search_sequence files(NULL, first_path, recls::FILES | recls::RECURSIVE | recls::DIRECTORY_PARTS);

            { for (search_sequence::const_iterator i = files.begin(), e = files.end(); i != e; ++i)
            {
                display_entry(*i);
            }}
        }

        {
            std::_tcout << RECLS_LITERAL("  ") << RECLS_LITERAL("search using first path as patterns (and '~' as search-root):") << std::endl;

            recls::cpp::search_sequence files(RECLS_LITERAL("~"), first_path, recls::FILES | recls::RECURSIVE | recls::DIRECTORY_PARTS);

            { for (search_sequence::const_iterator i = files.begin(), e = files.end(); i != e; ++i)
            {
                display_entry(*i);
            }}
        }

#if defined(PLATFORMSTL_OS_IS_UNIX) && \
    defined(_WIN32)
        }
#endif
    }

#ifdef RECLS_API_FTP

    { // ftp_search_sequence

        recls::cpp::ftp_search_sequence files(RECLS_LITERAL("ftp.digitalmars.com"), RECLS_LITERAL(""), RECLS_LITERAL(""), RECLS_LITERAL("/"), Recls_GetWildcardsAll(), recls::FILES | recls::RECURSIVE | recls::DIRECTORY_PARTS);

        { for (ftp_search_sequence::const_iterator i = files.begin(), e = files.end(); i != e; ++i)
        {
            display_entry(*i);
        }}
    }
#endif /* RECLS_API_FTP */

    return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
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

#if 0
    { for (size_t i = 0; i < 0xffffffff; ++i){} }
#endif /* 0 */

    try
    {
#if defined(_DEBUG) || \
    defined(__SYNSOFT_DBS_DEBUG)

        puts("test.scratch.cpp_api: " __STLSOFT_COMPILER_LABEL_STRING);
#endif /* debug */

        res = main_(argc, argv);
    }
    catch (std::exception& x)
    {
        fprintf(stderr, "Unhandled error: %s\n", x.what());

        res = EXIT_FAILURE;
    }
    catch (...)
    {
        fprintf(stderr, "Unhandled unknown error\n");

        res = EXIT_FAILURE;
    }

#if defined(_MSC_VER) && \
    defined(_DEBUG)

    _CrtMemDumpAllObjectsSince(&memState);
#endif /* _MSC_VER) && _DEBUG */

    return res;
}


/* /////////////////////////////////////////////////////////////////////////
 * function implementations
 */

static void display_entry(recls::entry const& fe)
{
    using namespace recls;

    size_t width = 25;

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
    std::_tcout << std::setw(width) << RECLS_LITERAL("SearchRelativePath:") << RECLS_LITERAL("    ") << fe.SearchRelativePath << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("Path:") << RECLS_LITERAL("    ") << fe.Path << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("DirectoryPath:") << RECLS_LITERAL("    ") << fe.DirectoryPath << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("Drive:") << RECLS_LITERAL("    ") << fe.Drive << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("Directory:") << RECLS_LITERAL("    ") << std::setw(fe.get_drive().length()) << RECLS_LITERAL("") << fe.Directory << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("File:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length()) << RECLS_LITERAL("") << fe.File << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("FileName:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length()) << RECLS_LITERAL("") << fe.FileName << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("FileExtension:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length() + fe.get_file_name().length()) << RECLS_LITERAL("") << fe.FileExtension << std::endl;
#else /* ? RECLS_CPP_METHOD_PROPERTY_SUPPORT */
    std::_tcout << std::setw(width) << RECLS_LITERAL("search-relative path:") << RECLS_LITERAL("    ") << fe.get_search_relative_path() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("path:") << RECLS_LITERAL("    ") << fe.get_path() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("directory_path:") << RECLS_LITERAL("    ") << fe.get_directory_path() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("drive:") << RECLS_LITERAL("    ") << fe.get_drive() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("directory:") << RECLS_LITERAL("    ") << std::setw(fe.get_drive().length()) << RECLS_LITERAL("") << fe.get_directory() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("file:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length()) << RECLS_LITERAL("") << fe.get_file() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("file name:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length()) << RECLS_LITERAL("") << fe.get_file_name() << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("file extension:") << RECLS_LITERAL("    ") << std::setw(fe.get_directory_path().length() + fe.get_file_name().length()) << RECLS_LITERAL("") << fe.get_file_extension() << std::endl;
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

    std::_tcout << std::setw(width) << RECLS_LITERAL("directory parts:") << std::endl;
#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
    directory_parts parts = fe.DirectoryParts;
#else /* ? RECLS_CPP_METHOD_PROPERTY_SUPPORT */
    directory_parts parts = fe.get_directory_parts();
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */
    size_t partWidth = width + fe.get_drive().length();
    size_t numParts = parts.end() - parts.begin();
    STLSOFT_ASSERT(parts.size() == numParts);
#if 0
    std::_tcout << s_CR << RECLS_LITERAL("num parts:") << numParts << std::endl;
    std::_tcout << s_CR << RECLS_LITERAL("num parts:") << parts.size() << std::endl;

    std::_tcout << s_CR << RECLS_LITERAL("part begin:") << &*parts.begin() << std::endl;
    std::_tcout << s_CR << RECLS_LITERAL("part end:") << &*parts.end() << std::endl;
#endif /* 0 */

    if (numParts > 3)
    {
        (parts.begin() + 3) - 3;
        parts.begin()[3];
    }
    { for (directory_parts::const_iterator i = parts.begin(), e = parts.end(); i != e; ++i)
    {
        std::_tcout << std::setw(partWidth) << RECLS_LITERAL("") << RECLS_LITERAL("    ") << (*i) << std::endl;
        partWidth += (*i).length();
    }}

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
    std::_tcout
        << std::setw(width)
        << RECLS_LITERAL("Attributes:")
        << RECLS_LITERAL("    ")
        << RECLS_LITERAL("0x")
        << std::setw(8)
        << std::setfill(RECLS_LITERAL('0'))
        << std::setbase(16)
        << static_cast<unsigned>(fe.Attributes)
        << std::setfill(RECLS_LITERAL(' '))
        << std::endl
        ;

    std::_tcout << std::setw(width) << RECLS_LITERAL("Size:") << RECLS_LITERAL("    ") << static_cast<unsigned>(fe.Size) << std::endl;
#else /* ? RECLS_CPP_METHOD_PROPERTY_SUPPORT */
    std::_tcout << std::setw(width) << RECLS_LITERAL("attributes:") << RECLS_LITERAL("    ") << RECLS_LITERAL("0x") << std::setw(8) << std::setfill('0') << std::setbase(16) << static_cast<unsigned>(fe.get_attributes()) << std::setfill(' ') << std::endl;

    std::_tcout << std::setw(width) << RECLS_LITERAL("size:") << RECLS_LITERAL("    ") << static_cast<unsigned>(fe.get_size()) << std::endl;
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

//      std::_tcout << std::setw(width) << RECLS_LITERAL("creation time:") << RECLS_LITERAL("    ") << fe.get_creation_time() << std::endl;
//      std::_tcout << std::setw(width) << RECLS_LITERAL("last access time:") << RECLS_LITERAL("    ") << fe.get_creation_time() << std::endl;
//      std::_tcout << std::setw(width) << RECLS_LITERAL("last status change time:") << RECLS_LITERAL("    ") << fe.get_creation_time() << std::endl;
//      std::_tcout << std::setw(width) << RECLS_LITERAL("modification time:") << RECLS_LITERAL("    ") << fe.get_creation_time() << std::endl;

#ifdef RECLS_CPP_METHOD_PROPERTY_SUPPORT
    std::_tcout << std::setw(width) << RECLS_LITERAL("IsDirectory:") << RECLS_LITERAL("    ") << (fe.IsDirectory ? s_true : s_false) << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("IsReadOnly:") << RECLS_LITERAL("    ") << (fe.IsReadOnly ? s_true : s_false) << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("IsUnc:") << RECLS_LITERAL("    ") << (fe.IsUnc ? s_true : s_false) << std::endl;
#else /* ? RECLS_CPP_METHOD_PROPERTY_SUPPORT */
    std::_tcout << std::setw(width) << RECLS_LITERAL("is_directory:") << RECLS_LITERAL("    ") << (fe.is_directory() ? s_true : s_false) << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("is_readonly:") << RECLS_LITERAL("    ") << (fe.is_readonly() ? s_true : s_false) << std::endl;
    std::_tcout << std::setw(width) << RECLS_LITERAL("is_unc:") << RECLS_LITERAL("    ") << (fe.is_unc() ? s_true : s_false) << std::endl;
#endif /* RECLS_CPP_METHOD_PROPERTY_SUPPORT */

    std::_tcout << std::endl;
}


/* ///////////////////////////// end of file //////////////////////////// */

