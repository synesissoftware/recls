#! /bin/bash

ScriptPath=$0
Dir=$(cd $(dirname "$ScriptPath"); pwd)
Basename=$(basename "$ScriptPath")
CMakeDir=${SIS_CMAKE_BUILD_DIR:-$Dir/_build}
MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-make}}

Configuration=Release
ExamplesDisabled=0
MinGW=0
NO_b64=0
NO_Pantheios=0
NO_shwild=0
RunMake=0
STLSoftDirGiven=
TestingDisabled=0
USE_UNIXem=0
VerboseMakefile=0


# ##########################################################
# command-line handling

while [[ $# -gt 0 ]]; do

  case $1 in
    -v|--cmake-verbose-makefile)

      VerboseMakefile=1
      ;;
    -d|--debug-configuration)

      Configuration=Debug

      ;;
    -E|--disable-examples)
      ExamplesDisabled=1
      ;;
    -T|--disable-testing)

      TestingDisabled=1
      ;;
    --mingw)

      MinGW=1
      MakeCmd=${SIS_CMAKE_MAKE_COMMAND:-${SIS_CMAKE_COMMAND:-mingw32-make.exe}}
      ;;
    --no-b64)

      NO_b64=1
      ;;
    --no-pantheios|--no-pan)

      NO_Pantheios=1
      NO_b64=1
      ;;
    --no-shwild)

      NO_shwild=1
      ;;
    -m|--run-make)

      RunMake=1
      ;;
    -s|--stlsoft-root-dir)

      shift
      STLSoftDirGiven=$1
      ;;
    --use-unixem)

      USE_UNIXem=1
      ;;
    --help)

      cat << EOF
recls is a platform-independent recursive file-system search library
Copyright (c) 2019-2024, Matthew Wilson and Synesis Information Systems
Copyright (c) 2003-2019, Matthew Wilson and Synesis Software
Creates/reinitialises the CMake build script(s)

$ScriptPath [ ... flags/options ... ]

Flags/options:

    behaviour:

    -v
    --cmake-verbose-makefile
        configures CMake to run verbosely (by setting CMAKE_VERBOSE_MAKEFILE
        to be ON)

    -d
    --debug-configuration
        use Debug configuration (by setting CMAKE_BUILD_TYPE=Debug). Default
        is to use Release

    -E
    --disable-examples
        disables building of examples (by setting BUILD_EXAMPLES=OFF)

    -T
    --disable-testing
        disables building of tests (by setting BUILD_TESTING=OFF)

    --mingw
        uses explicitly the "MinGW Makefiles" generator, and defaults the
        make-command to "mingw32-make.exe"

    --no-b64
        suppresses discovery of b64 package

    --no-pan
    --no-pantheios
        suppresses discovery of Pantheios package (and of the b64 package
        also)

    --no-shwild
        suppresses discovery of shwild package

    -m
    --run-make
        executes make after a successful running of CMake

    -s <dir>
    --stlsoft-root-dir <dir>
        specifies the STLSoft root-directory, which will be passed to CMake
        as the variable STLSOFT, and which will override the environment
        variable STLSOFT (if present)

    --use-unixem
        when building on Windows, use the UNIXem library and define the
        preprocessor symbol _STLSOFT_FORCE_ANY_COMPILER so as to emulate and
        exercise UNIXSTL, not WinSTL (or COMSTL, etc.). Has no effect when
        not executing on Windows


    standard flags:

    --help
        displays this help and terminates

EOF

      exit 0
      ;;
    *)

      >&2 echo "$ScriptPath: unrecognised argument '$1'; use --help for usage"

      exit 1
      ;;
  esac

  shift
done


# ##########################################################
# main()

mkdir -p $CMakeDir || exit 1

cd $CMakeDir

echo "Executing CMake (in ${CMakeDir})"

if [ $ExamplesDisabled -eq 0 ]; then CMakeBuildExamplesFlag="ON" ; else CMakeBuildExamplesFlag="OFF" ; fi
if [ $NO_b64 -eq 0 ]; then CMakeNoB64="OFF" ; else CMakeNoB64="ON" ; fi
if [ $NO_Pantheios -eq 0 ]; then CMakeNoPantheios="OFF" ; else CMakeNoPantheios="ON" ; fi
if [ $NO_shwild -eq 0 ]; then CMakeNoShwild="OFF" ; else CMakeNoShwild="ON" ; fi
if [ -z $STLSoftDirGiven ]; then CMakeSTLSoftVariable="" ; else CMakeSTLSoftVariable="-DSTLSOFT=$STLSoftDirGiven/" ; fi
if [ $TestingDisabled -eq 0 ]; then CMakeBuildTestingFlag="ON" ; else CMakeBuildTestingFlag="OFF" ; fi
if [ $USE_UNIXem -ne 0 ]; then CMakeUSE_UNIXem="ON" ; else CMakeUSE_UNIXem="OFF" ; fi
if [ $VerboseMakefile -eq 0 ]; then CMakeVerboseMakefileFlag="OFF" ; else CMakeVerboseMakefileFlag="ON" ; fi

if [ $MinGW -ne 0 ]; then

  cmake \
    $CMakeSTLSoftVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DCMAKE_NO_B64:BOOL=$CMakeNoB64 \
    -DCMAKE_NO_PANTHEIOS:BOOL=$CMakeNoPantheios \
    -DCMAKE_NO_SHWILD:BOOL=$CMakeNoShwild \
    -DUSE_UNIXEM:BOOL=$CMakeUSE_UNIXem \
    -G "MinGW Makefiles" \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
else

  cmake \
    $CMakeSTLSoftVariable \
    -DBUILD_EXAMPLES:BOOL=$CMakeBuildExamplesFlag \
    -DBUILD_TESTING:BOOL=$CMakeBuildTestingFlag \
    -DCMAKE_BUILD_TYPE=$Configuration \
    -DCMAKE_NO_B64:BOOL=$CMakeNoB64 \
    -DCMAKE_NO_PANTHEIOS:BOOL=$CMakeNoPantheios \
    -DCMAKE_NO_SHWILD:BOOL=$CMakeNoShwild \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=$CMakeVerboseMakefileFlag \
    -DUSE_UNIXEM:BOOL=$CMakeUSE_UNIXem \
    -S $Dir \
    -B $CMakeDir \
    || (cd ->/dev/null ; exit 1)
fi

status=0

if [ $RunMake -ne 0 ]; then

  echo "Executing build (via command \`$MakeCmd\`)"

  $MakeCmd
  status=$?
fi

cd ->/dev/null

if [ $VerboseMakefile -ne 0 ]; then

  echo -e "contents of $CMakeDir:"
  ls -al $CMakeDir
fi

exit $status


# ############################## end of file ############################# #

