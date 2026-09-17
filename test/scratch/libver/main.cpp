
#include <recls/recls.h>

#include <stlsoft/stlsoft.h>

#include <iomanip>
#include <iostream>

#include <stdlib.h>


#define PROGRAM_NAME                                        "libver"


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

    {
        unsigned const libver = _STLSOFT_VER;

        version(std::cout, "\t", "STLSoft", "_STLSOFT_VER", libver);
    }

    return EXIT_SUCCESS;
}

