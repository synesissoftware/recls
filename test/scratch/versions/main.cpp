
#include <recls/recls.h>

#ifdef HAS_2be
# include <2be/2be.h>
#endif /* HAS_2be */
#ifdef HAS_b64
# include <b64/b64.h>
#endif /* HAS_b64 */
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
#ifdef HAS_xTests
# include <xtests/xtests.h>
#endif /* HAS_xTests */

#include <iomanip>
#include <iostream>

#include <stdlib.h>


#define PROGRAM_NAME                                        "versions"


template<
    typename T_stream
,   typename T_integer
>
void
version(
    T_stream&   stm
,   char const* prefix
,   char const* libname
,   char const* macroname
,   T_integer   libver
)
{
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
}


int main(int /* argc */, char* /* argv */[])
{
    {
        unsigned const libver = RECLS_VER;

        version(std::cout, "", "recls", "RECLS_VER", libver);
    }

    std::cout << "\n" << "efferent dependencies:" << std::endl;

#ifdef HAS_2be

    {
        unsigned const libver = TWOB_VER;

        version(std::cout, "\t", "2be", "TWOB_VER", libver);
    }
#endif /* HAS_2be */

#ifdef HAS_b64

    {
        unsigned const libver = B64_VER;

        version(std::cout, "\t", "b64", "B64_VER", libver);
    }
#endif /* HAS_b64 */

#ifdef HAS_Pantheios

    {
        unsigned const libver = PANTHEIOS_VER;

        version(std::cout, "\t", "Pantheios", "PANTHEIOS_VER", libver);
    }
#endif /* HAS_Pantheios */

#ifdef HAS_shwild

    {
        unsigned const libver = SHWILD_VER;

        version(std::cout, "\t", "shwild", "SHWILD_VER", libver);
    }
#endif /* HAS_shwild */

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

#ifdef RECLS_HAS_UNIXEM

    {
        unsigned const libver = UNIXEM_VER;

        version(std::cout, "\t", "UNIXem", "UNIXEM_VER", libver);
    }
#endif /* RECLS_HAS_UNIXEM */

#ifdef HAS_xTests

    {
        unsigned const libver = _XTESTS_VER;

        version(std::cout, "\t", "xTests", "_XTESTS_VER", libver);
    }
#endif /* HAS_xTests */

    return EXIT_SUCCESS;
}

