/* /////////////////////////////////////////////////////////////////////////
 * File:    test/scratch/versions/main.cpp
 *
 * Purpose: Scratch version reporter for recls and optional efferents.
 *
 * Created: 30th June 2025
 * Updated: 13th October 2026
 *
 * ////////////////////////////////////////////////////////////////////// */


#include <recls/recls.h>

#ifdef HAS_2be
# include <2be/2be.h>
#endif /* HAS_2be */
#ifdef HAS_b64
# include <b64/b64.h>
#endif /* HAS_b64 */
#ifdef HAS_Diagnosticism
# include <diagnosticism/version_string.h>
#endif /* HAS_Diagnosticism */
#ifdef HAS_Pantheios
# include <pantheios/pantheios.h>
#endif /* HAS_Pantheios */
#ifdef HAS_shwild
# include <shwild/shwild.h>
#endif /* HAS_shwild */
#include <stlsoft/stlsoft.h>
#ifdef RECLS_HAS_UNIXEM
# include <unixem/unixem.h>
#endif /* RECLS_HAS_UNIXEM */

#include <iomanip>
#include <iostream>

#include <stdlib.h>


#define PROGRAM_NAME                                        "test.scratch.versions"


template<
    typename T_stream
,   typename T_integer
>
int
version(
    T_stream&   stm
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
)
{
#ifdef HAS_Diagnosticism

    char        buffer[101];
    size_t      n;
    int const   r = diagnosticism_calc_version_string(
        buffer
    ,   sizeof(buffer) / sizeof(buffer[0])
    ,   (int)((libver >> 24) & 0xff)
    ,   (int)((libver >> 16) & 0xff)
    ,   (int)((libver >> 8) & 0xff)
    ,   (int)((libver >> 0) & 0xff)
    ,   &n
    );

    if (0 != r)
    {
        std::cerr
            << PROGRAM_NAME
            << ": failed to format version string for "
            << libname
            << std::endl
            ;

        return EXIT_FAILURE;
    }

    buffer[n] = '\0';

    stm
        << prefix
        << libname
        << ": "
        << buffer
        << " ("
        << macroname
        << " = 0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << ")"
        << std::endl
        ;
#else /* ? HAS_Diagnosticism */

    stm
        << prefix
        << libname
        << ": v"
        << ((libver >> 24) & 0xff)
        << '.'
        << ((libver >> 16) & 0xff)
        << '.'
        << ((libver >> 8) & 0xff)
        << '.'
        << ((libver >> 0) & 0xff)
        << " ("
        << macroname
        << " = 0x"
        << std::hex << std::setfill('0') << std::setw(8)
        << static_cast<unsigned>(libver)
        << std::dec
        << ")"
        << std::endl
        ;
#endif /* HAS_Diagnosticism */

    return EXIT_SUCCESS;
}


int main(int /* argc */, char* /* argv */[])
{
    {
        unsigned const libver = RECLS_VER;

        if (EXIT_SUCCESS != version(std::cout, "", "recls", "RECLS_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }

    /* STLSoft is always an include of this TU; optional siblings follow. */
    std::cout << "\n" << "efferent dependencies:" << std::endl;

#ifdef HAS_2be

    {
        unsigned const libver = TWOB_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "2be", "TWOB_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* HAS_2be */

#ifdef HAS_b64

    {
        unsigned const libver = B64_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "b64", "B64_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* HAS_b64 */

#ifdef HAS_Diagnosticism

    {
        unsigned const libver = DIAGNOSTICISM_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "Diagnosticism", "DIAGNOSTICISM_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* HAS_Diagnosticism */

#ifdef HAS_Pantheios

    {
        unsigned const libver = PANTHEIOS_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "Pantheios", "PANTHEIOS_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* HAS_Pantheios */

#ifdef HAS_shwild

    {
        unsigned const libver = SHWILD_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "shwild", "SHWILD_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* HAS_shwild */

    {
        unsigned const libver = _STLSOFT_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "STLSoft", "_STLSOFT_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }

#ifdef RECLS_HAS_UNIXEM

    {
        unsigned const libver = UNIXEM_VER;

        if (EXIT_SUCCESS != version(std::cout, "\t", "UNIXem", "UNIXEM_VER", libver))
        {
            return EXIT_FAILURE;
        }
    }
#endif /* RECLS_HAS_UNIXEM */

    return EXIT_SUCCESS;
}


/* ///////////////////////////// end of file //////////////////////////// */

