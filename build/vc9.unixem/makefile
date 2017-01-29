############################################################################
# File:     makefile
#
# Purpose:  Makefile for the recls project, for the Visual C++ 9.0 (x86 UNIXem)
#           compiler, on UNIX
#
# Created:  23rd September 2003
# Updated:  29th January 2017
#
############################################################################


############################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

!ifndef PTHREADS_WIN32
!error PTHREADS_WIN32 must be defined
!endif # !PTHREADS_WIN32

!ifndef UNIXEM
!error UNIXEM must be defined
!endif # !UNIXEM

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   vc9
ARCH_TAG            =   
OS_TAG				=   .unix
PROJ_TAG            =   recls
PROJ_VER_MAJOR      =   1
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR	=	1
UNIXEM_TAG_VER      =   unixem.$(UNIXEM_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# Testing verbosity

!ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
!endif # !TEST_VERBOSITY

########################################
# Directories

PROJ_BASE_DIR           =   ..\..
PROJ_BIN_DIR            =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR        =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR            =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR            =   .
PROJ_SRC_DIR            =   $(PROJ_BASE_DIR)\src
PROJ_EXAMPLES_DIR       =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)\samples
PROJ_TEST_ROOT_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_TEST_COMPONENT_DIR =   $(PROJ_TEST_ROOT_DIR)\component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)\performance
PROJ_TEST_SCRATCH_DIR   =   $(PROJ_TEST_ROOT_DIR)\scratch
PROJ_TEST_UNIT_DIR      =   $(PROJ_TEST_ROOT_DIR)\unit

SHWILD_PROJ_INCLUDE		=	
!ifdef RECLS_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR		=   $(RECLS_SHWILD_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(RECLS_SHWILD_BASE_DIR)\src
SHWILD_PROJ_INCLUDE		=	-I$(SHWILD_INCLUDE_DIR)
!else
SHWILD_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
SHWILD_SRC_DIR			=   $(PROJ_SRC_DIR)\shwild
!endif # !RECLS_SHWILD_BASE_DIR

XCONTRACT_PROJ_INCLUDE	=	

XTESTS_PROJ_INCLUDE		=	
!ifdef RECLS_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR		=   $(RECLS_XTESTS_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(RECLS_XTESTS_BASE_DIR)\src
XTESTS_PROJ_INCLUDE		=	-I$(XTESTS_INCLUDE_DIR)
!else
XTESTS_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
XTESTS_SRC_DIR			=   $(PROJ_SRC_DIR)\xtests
!endif # !RECLS_XTESTS_BASE_DIR

!ifdef STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=	-I$(STLSOFT_1_10)\include
!else # ? STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=
!endif # !STLSOFT_1_10


STLSOFT_PROJ_INCLUDE	=	-I$(STLSOFT)\include

########################################
# tools

CC                      =   cl
CPPC                    =   cl
AR                      =   lib
LD                      =   link
RM                      =   del /f
CP                      =   copy
RC                      =   rc

# Includes

INCLUDES_LEADER         =   

PROJ_INCLUDE            =   -I$(PROJ_INCLUDE_DIR)

ENV_INCLUDES            =

COMMON_INCLUDES         =   





# Lib

LIBS_LEADER             =   

# lib paths

ENV_LIBPATHS        =
COMMON_LIBPATHS         =   


LIBPATHS=\
$(LIBS_LEADER)\
-libpath:"$(PTHREADS_WIN32)\lib"\
-libpath:"$(UNIXEM)\lib"\
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_UX=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib pthreadVC.lib \
 \

TARGET_LIB_MT_UX_DEBUG=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib ws2_32.lib pthreadVC.lib \
 \


# #defines

OS_DEFS				=	-DUNIX

COMMON_DEFS 		=

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)



# CC flags

CC_F_NOLOGO           =   -nologo
CC_F_COMPILE_ONLY     =   -c
CC_F_WARNING_MAX      =   -W4
CC_F_WARNING_ERR      =   -WX
CC_F_MINIMUM_SIZE     =   -O1
CC_F_MAXIMUM_SPEED    =   -O2

CC_FLAGS_BASE=\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_UX=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_UX_DEBUG=\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -W4
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON    =   -EHsc
CPPC_F_EXCEPTIONS_OFF   =   -GX- -FIrecls/internal/warning/msvc.suppress.4530.h
CPPC_F_EXCEPTIONS		=	
CPPC_F_RTTI_ON          =   -GR
CPPC_F_RTTI_OFF         =   -GR-
CPPC_F_RTTI             =   
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED	=	-O2

CPPC_FLAGS_BASE=\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_UX=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_UX_DEBUG=\
 $(CPPC_FLAGS_BASE)\
 \



# CC defines

CC_DEFS_BASE=\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CC_CUSTOM_DEFS)\
 -DEMULATE_UNIX_ON_WIN32\
 \

CC_DEFS_MT_UX=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_UX_DEBUG=\
 $(CC_DEFS_BASE)\
 \


# CPPC defines

CPPC_DEFS_BASE=\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CPPC_CUSTOM_DEFS)\
 -DEMULATE_UNIX_ON_WIN32\
 \

CPPC_DEFS_MT_UX=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_MT_UX_DEBUG=\
 $(CPPC_DEFS_BASE)\
 \




# CC includes

CC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
-I"$(PTHREADS_WIN32)\include"\
-I"$(UNIXEM)\include"\
 $(ENV_INCLUDES)\
 \

CC_INCLUDES_MT_UX=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_UX_DEBUG=\
 $(CC_INCLUDES_BASE)\
 \



CC_SHWILD_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_UX=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_UX_DEBUG=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_UX=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_UX_DEBUG=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \



# CPPC includes

CPPC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
-I"$(PTHREADS_WIN32)\include"\
-I"$(UNIXEM)\include"\
 $(ENV_INCLUDES)\
 \

CPPC_INCLUDES_MT_UX=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_MT_UX_DEBUG=\
 $(CPPC_INCLUDES_BASE)\
 \



CPPC_SHWILD_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_UX_DEBUG=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_UX_DEBUG=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_UX=\
 $(CC_FLAGS_MT_UX)\
 $(CC_DEFS_MT_UX)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 -MT -Zi -Fd$*.pdb -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DNDEBUG $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_RELEASE)\
 $(CC_INCLUDES_MT_UX)
CC_ARGS_MT_UX_DEBUG=\
 $(CC_FLAGS_MT_UX_DEBUG)\
 $(CC_DEFS_MT_UX_DEBUG)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 -MTd -Zi -Fd$*.pdb -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -D_DEBUG $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_DEBUG)\
 $(CC_INCLUDES_MT_UX_DEBUG)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_UX=\
 $(CPPC_FLAGS_MT_UX)\
 $(CPPC_DEFS_MT_UX)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 -MT -Zi -Fd$*.pdb -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -DNDEBUG $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_RELEASE)\
 $(CPPC_INCLUDES_MT_UX)
CPPC_ARGS_MT_UX_DEBUG=\
 $(CPPC_FLAGS_MT_UX_DEBUG)\
 $(CPPC_DEFS_MT_UX_DEBUG)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 -MTd -Zi -Fd$*.pdb -D_STLSOFT_FORCE_ANY_COMPILER -D_REENTRANT -D_DEBUG $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_DEBUG)\
 $(CPPC_INCLUDES_MT_UX_DEBUG)



# AR Args

AR_ARGS             =   -nologo


# LD flags

LD_F_NOLOGO				=   -nologo

LD_FLAGS_BASE=\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_UX=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_UX_DEBUG=\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE=\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_UX=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_UX_DEBUG=\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_UX= $(LD_FLAGS_MT_UX) unixem.core.1.$(COMP_TAG).mt.lib -release $(LD_INCLUDES_MT_UX)
LD_ARGS_MT_UX_DEBUG= $(LD_FLAGS_MT_UX_DEBUG) unixem.core.1.$(COMP_TAG).mt.debug.lib -debug $(LD_INCLUDES_MT_UX_DEBUG)



# 3rd party libraries

3PTY_LIBS_BASE=\
 \


3PTY_LIBS_MT_UX	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_MT_UX_DEBUG	=\
 $(3PTY_LIBS_BASE)\
 \


############################################################################
# Headers

CORE_HEADERS=\
 $(PROJ_INCLUDE_DIR)\recls\assert.h\
 $(PROJ_INCLUDE_DIR)\recls\ftp.h\
 $(PROJ_INCLUDE_DIR)\recls\implicit_link.h\
 $(PROJ_INCLUDE_DIR)\recls\recls.h\
 $(PROJ_INCLUDE_DIR)\recls\unix.h\
 $(PROJ_INCLUDE_DIR)\recls\windows.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_borland.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_ch.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_como.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_dmc.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_gcc.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_intel.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_msvc.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_mwerks.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_vectorc.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\compiler_watcom.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\language.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\platform.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\platform_types.h\
 $(PROJ_INCLUDE_DIR)\recls\internal\retcodes.h\
 \

CPP_API_HEADERS=\
 $(PROJ_INCLUDE_DIR)\recls\recls.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\common.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\directory_parts.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\entry.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\exceptions.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\ftp_search_sequence.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\root_sequence.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\search_sequence.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\traits.hpp\
 $(PROJ_INCLUDE_DIR)\recls\cpp\util.hpp\
 \


SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.h\
 $(SHWILD_INCLUDE_DIR)\shwild\shwild.hpp\
 \

XTESTS_HEADERS=\
 $(XTESTS_INCLUDE_DIR)\xtests\xtests.h\
 $(XTESTS_INCLUDE_DIR)\xtests\internal\safestr.h\
 \

############################################################################
# Targets

########################################
# Libraries

# recls
LIB_CORE_MT_UX           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_MT_UX_DEBUG           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.lib

# shwild
LIB_SHWILD_MT_UX         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_MT_UX_DEBUG         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib

# xtests
LIB_XTESTS_MT_UX         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_MT_UX_DEBUG         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib

########################################
# Examples

TARG_EX_ex_c_1_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_2_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_3_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_4_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_5_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_6_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_7_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_8_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_1_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_2_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_3_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_4_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_5_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_6_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_7_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_8_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.debug.exe

TARG_EX_ex_cpp_1_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_2_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_3_MT_UX	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_1_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_2_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_3_MT_UX_DEBUG	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.debug.exe

########################################
# Tests

##############################
# Component Tests

TARG_TEST_COMP_api_crdir_MT_UX	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_rmdir_MT_UX	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_crdir_MT_UX_DEBUG	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_api_rmdir_MT_UX_DEBUG	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe

##############################
# Scratch Tests

TARG_TEST_SCRT_srch1_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch2_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch1_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_srch2_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.debug.exe

##############################
# Unit Tests

TARG_TEST_UNIT_api_cmbpaths_MT_UX  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_drvrel_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_sqzpath_MT_UX   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_UX  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_drvrel_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_UX   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_retcodes_MT_UX  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_c_retcodes_MT_UX    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_drvrel_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_sqzpath_MT_UX_DEBUG   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_c_retcodes_MT_UX_DEBUG    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe


############################################################################
# Objects

########################################
# Libraries

# recls

OBJ_CR_api_entryinfo_MT_UX		= $(PROJ_OBJ_DIR)\api.entryinfo.mt.obj
OBJ_CR_api_error_MT_UX			= $(PROJ_OBJ_DIR)\api.error.mt.obj
OBJ_CR_api_extended_MT_UX		= $(PROJ_OBJ_DIR)\api.extended.mt.obj
OBJ_CR_api_combpath_MT_UX		= $(PROJ_OBJ_DIR)\api.combpath.mt.obj
OBJ_CR_api_derrpath_MT_UX		= $(PROJ_OBJ_DIR)\api.derrpath.mt.obj
OBJ_CR_api_getflsizs_MT_UX		= $(PROJ_OBJ_DIR)\api.getflsizs.mt.obj
OBJ_CR_api_sqzpath_MT_UX		= $(PROJ_OBJ_DIR)\api.sqzpath.mt.obj
OBJ_CR_api_stat_MT_UX			= $(PROJ_OBJ_DIR)\api.stat.mt.obj
OBJ_CR_api_crdir_MT_UX			= $(PROJ_OBJ_DIR)\api.crdir.mt.obj
OBJ_CR_api_rmdir_MT_UX			= $(PROJ_OBJ_DIR)\api.rmdir.mt.obj
OBJ_CR_api_search_MT_UX		= $(PROJ_OBJ_DIR)\api.search.mt.obj
OBJ_CR_impl_debug_MT_UX		= $(PROJ_OBJ_DIR)\impl.trace.mt.obj
OBJ_CR_impl_entryinfo_MT_UX	= $(PROJ_OBJ_DIR)\impl.entryinfo.mt.obj
OBJ_CR_impl_fileinfo_MT_UX		= $(PROJ_OBJ_DIR)\impl.fileinfo.mt.obj
OBJ_CR_impl_snprintf_MT_UX		= $(PROJ_OBJ_DIR)\impl.snprintf.mt.obj
OBJ_CR_impl_util_MT_UX			= $(PROJ_OBJ_DIR)\impl.util.mt.obj
OBJ_CR_Srch_MT_UX				= $(PROJ_OBJ_DIR)\ReclsSearch.mt.obj
OBJ_CR_FlSrch_MT_UX			= $(PROJ_OBJ_DIR)\ReclsFileSearch.mt.obj
OBJ_CR_FlSchDirNode_MT_UX		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.mt.obj
OBJ_CR_api_unix_MT_UX				= $(PROJ_OBJ_DIR)\api.unix.mt.obj
OBJ_CR_impl_fileinfo_unix_MT_UX	= $(PROJ_OBJ_DIR)\impl.fileinfo.unix.mt.obj
OBJ_CR_impl_util_unix_MT_UX		= $(PROJ_OBJ_DIR)\impl.util.unix.mt.obj



OBJ_CORE_MT_UX=\
 $(OBJ_CR_api_entryinfo_MT_UX)\
 $(OBJ_CR_api_error_MT_UX)\
 $(OBJ_CR_api_extended_MT_UX)\
 $(OBJ_CR_api_combpath_MT_UX)\
 $(OBJ_CR_api_derrpath_MT_UX)\
 $(OBJ_CR_api_getflsizs_MT_UX)\
 $(OBJ_CR_api_sqzpath_MT_UX)\
 $(OBJ_CR_api_stat_MT_UX)\
 $(OBJ_CR_api_crdir_MT_UX)\
 $(OBJ_CR_api_rmdir_MT_UX)\
 $(OBJ_CR_api_search_MT_UX)\
 $(OBJ_CR_impl_debug_MT_UX)\
 $(OBJ_CR_impl_entryinfo_MT_UX)\
 $(OBJ_CR_impl_fileinfo_MT_UX)\
 $(OBJ_CR_impl_snprintf_MT_UX)\
 $(OBJ_CR_impl_util_MT_UX)\
 $(OBJ_CR_Srch_MT_UX)\
 $(OBJ_CR_FlSrch_MT_UX)\
 $(OBJ_CR_FlSchDirNode_MT_UX)\
 $(OBJ_CR_api_unix_MT_UX)\
 $(OBJ_CR_impl_fileinfo_unix_MT_UX)\
 $(OBJ_CR_impl_util_unix_MT_UX)\
 \

OBJ_CR_api_entryinfo_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.entryinfo.mt.debug.obj
OBJ_CR_api_error_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\api.error.mt.debug.obj
OBJ_CR_api_extended_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.extended.mt.debug.obj
OBJ_CR_api_combpath_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.combpath.mt.debug.obj
OBJ_CR_api_derrpath_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.derrpath.mt.debug.obj
OBJ_CR_api_getflsizs_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.getflsizs.mt.debug.obj
OBJ_CR_api_sqzpath_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.sqzpath.mt.debug.obj
OBJ_CR_api_stat_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\api.stat.mt.debug.obj
OBJ_CR_api_crdir_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\api.crdir.mt.debug.obj
OBJ_CR_api_rmdir_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\api.rmdir.mt.debug.obj
OBJ_CR_api_search_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\api.search.mt.debug.obj
OBJ_CR_impl_debug_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\impl.trace.mt.debug.obj
OBJ_CR_impl_entryinfo_MT_UX_DEBUG	= $(PROJ_OBJ_DIR)\impl.entryinfo.mt.debug.obj
OBJ_CR_impl_fileinfo_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\impl.fileinfo.mt.debug.obj
OBJ_CR_impl_snprintf_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\impl.snprintf.mt.debug.obj
OBJ_CR_impl_util_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\impl.util.mt.debug.obj
OBJ_CR_Srch_MT_UX_DEBUG				= $(PROJ_OBJ_DIR)\ReclsSearch.mt.debug.obj
OBJ_CR_FlSrch_MT_UX_DEBUG			= $(PROJ_OBJ_DIR)\ReclsFileSearch.mt.debug.obj
OBJ_CR_FlSchDirNode_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.mt.debug.obj
OBJ_CR_api_unix_MT_UX_DEBUG				= $(PROJ_OBJ_DIR)\api.unix.mt.debug.obj
OBJ_CR_impl_fileinfo_unix_MT_UX_DEBUG	= $(PROJ_OBJ_DIR)\impl.fileinfo.unix.mt.debug.obj
OBJ_CR_impl_util_unix_MT_UX_DEBUG		= $(PROJ_OBJ_DIR)\impl.util.unix.mt.debug.obj



OBJ_CORE_MT_UX_DEBUG=\
 $(OBJ_CR_api_entryinfo_MT_UX_DEBUG)\
 $(OBJ_CR_api_error_MT_UX_DEBUG)\
 $(OBJ_CR_api_extended_MT_UX_DEBUG)\
 $(OBJ_CR_api_combpath_MT_UX_DEBUG)\
 $(OBJ_CR_api_derrpath_MT_UX_DEBUG)\
 $(OBJ_CR_api_getflsizs_MT_UX_DEBUG)\
 $(OBJ_CR_api_sqzpath_MT_UX_DEBUG)\
 $(OBJ_CR_api_stat_MT_UX_DEBUG)\
 $(OBJ_CR_api_crdir_MT_UX_DEBUG)\
 $(OBJ_CR_api_rmdir_MT_UX_DEBUG)\
 $(OBJ_CR_api_search_MT_UX_DEBUG)\
 $(OBJ_CR_impl_debug_MT_UX_DEBUG)\
 $(OBJ_CR_impl_entryinfo_MT_UX_DEBUG)\
 $(OBJ_CR_impl_fileinfo_MT_UX_DEBUG)\
 $(OBJ_CR_impl_snprintf_MT_UX_DEBUG)\
 $(OBJ_CR_impl_util_MT_UX_DEBUG)\
 $(OBJ_CR_Srch_MT_UX_DEBUG)\
 $(OBJ_CR_FlSrch_MT_UX_DEBUG)\
 $(OBJ_CR_FlSchDirNode_MT_UX_DEBUG)\
 $(OBJ_CR_api_unix_MT_UX_DEBUG)\
 $(OBJ_CR_impl_fileinfo_unix_MT_UX_DEBUG)\
 $(OBJ_CR_impl_util_unix_MT_UX_DEBUG)\
 \


# shwild

OBJ_shw_api_MT_UX            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.obj
OBJ_shw_matches_MT_UX        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.obj
OBJ_shw_pattern_MT_UX        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.obj

OBJ_SHWILD_MT_UX=\
 $(OBJ_shw_api_MT_UX)\
 $(OBJ_shw_matches_MT_UX)\
 $(OBJ_shw_pattern_MT_UX)\
 \

OBJ_shw_api_MT_UX_DEBUG            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.debug.obj
OBJ_shw_matches_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.debug.obj
OBJ_shw_pattern_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.debug.obj
PDB_shw_api_MT_UX_DEBUG            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.debug.pdb
PDB_shw_matches_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.debug.pdb
PDB_shw_pattern_MT_UX_DEBUG        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.debug.pdb

OBJ_SHWILD_MT_UX_DEBUG=\
 $(OBJ_shw_api_MT_UX_DEBUG)\
 $(OBJ_shw_matches_MT_UX_DEBUG)\
 $(OBJ_shw_pattern_MT_UX_DEBUG)\
 \

PDB_SHWILD_MT_UX_DEBUG=\
 $(PDB_shw_api_MT_UX_DEBUG)\
 $(PDB_shw_matches_MT_UX_DEBUG)\
 $(PDB_shw_pattern_MT_UX_DEBUG)\
 \


# xtests

OBJ_xts_core_MT_UX           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.obj

OBJ_XTESTS_MT_UX=\
 $(OBJ_xts_core_MT_UX)\
 \

OBJ_xts_core_MT_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.debug.obj
PDB_xts_core_MT_UX_DEBUG           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.debug.pdb

OBJ_XTESTS_MT_UX_DEBUG=\
 $(OBJ_xts_core_MT_UX_DEBUG)\
 \

PDB_CORE_MT_UX_DEBUG=\
 $(PDB_xts_core_MT_UX_DEBUG)\
 \


########################################
# Examples

OBJ_EX_ex_c_1_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.mt.obj
OBJ_EX_ex_c_2_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.mt.obj
OBJ_EX_ex_c_3_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.mt.obj
OBJ_EX_ex_c_4_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.mt.obj
OBJ_EX_ex_c_5_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.mt.obj
OBJ_EX_ex_c_6_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.mt.obj
OBJ_EX_ex_c_7_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.mt.obj
OBJ_EX_ex_c_8_MT_UX =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.mt.obj
OBJ_EX_ex_c_1_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.mt.debug.obj
OBJ_EX_ex_c_2_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.mt.debug.obj
OBJ_EX_ex_c_3_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.mt.debug.obj
OBJ_EX_ex_c_4_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.mt.debug.obj
OBJ_EX_ex_c_5_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.mt.debug.obj
OBJ_EX_ex_c_6_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.mt.debug.obj
OBJ_EX_ex_c_7_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.mt.debug.obj
OBJ_EX_ex_c_8_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.mt.debug.obj

OBJ_EX_ex_cpp_1_MT_UX =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.mt.obj
OBJ_EX_ex_cpp_2_MT_UX =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.mt.obj
OBJ_EX_ex_cpp_3_MT_UX =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.mt.obj
OBJ_EX_ex_cpp_1_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.mt.debug.obj
OBJ_EX_ex_cpp_2_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.mt.debug.obj
OBJ_EX_ex_cpp_3_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.mt.debug.obj

########################################
# Tests

##############################
# Component Tests

OBJ_TEST_COMP_api_crdir_MT_UX =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.mt.obj
OBJ_TEST_COMP_api_rmdir_MT_UX =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.mt.obj
OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.mt.debug.obj
OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.mt.debug.obj

##############################
# Scratch Tests

OBJ_TEST_SCRT_srch1_MT_UX   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.mt.obj
OBJ_TEST_SCRT_srch2_MT_UX   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.mt.obj
OBJ_TEST_SCRT_srch1_MT_UX_DEBUG   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.mt.debug.obj
OBJ_TEST_SCRT_srch2_MT_UX_DEBUG   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.mt.debug.obj

##############################
# Unit Tests

OBJ_TEST_UNIT_api_cmbpaths_MT_UX	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.mt.obj
OBJ_TEST_UNIT_api_drvrel_MT_UX		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.mt.obj
OBJ_TEST_UNIT_api_sqzpath_MT_UX	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.mt.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_UX		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.mt.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_UX	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_UX	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.mt.obj
OBJ_TEST_UNIT_c_retcodes_MT_UX		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.mt.obj
OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_api_drvrel_MT_UX_DEBUG		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.mt.debug.obj
OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.mt.debug.obj

##################################################
# Target groups

########################################
# Objects

# recls
OBJS_CORE=\
 $(OBJ_CORE_MT_UX)\
 $(OBJ_CORE_MT_UX_DEBUG)\
 \

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_MT_UX)\
 $(OBJ_SHWILD_MT_UX_DEBUG)\
 \

# xtests
OBJS_XTESTS=\
 $(OBJ_XTESTS_MT_UX)\
 $(OBJ_XTESTS_MT_UX_DEBUG)\
 \

# Examples 
OBJS_EXAMPLE=\
 $(OBJ_EX_ex_c_1_MT_UX)\
 $(OBJ_EX_ex_c_2_MT_UX)\
 $(OBJ_EX_ex_c_3_MT_UX)\
 $(OBJ_EX_ex_c_4_MT_UX)\
 $(OBJ_EX_ex_c_5_MT_UX)\
 $(OBJ_EX_ex_c_6_MT_UX)\
 $(OBJ_EX_ex_c_7_MT_UX)\
 $(OBJ_EX_ex_c_8_MT_UX)\
 $(OBJ_EX_ex_cpp_1_MT_UX)\
 $(OBJ_EX_ex_cpp_2_MT_UX)\
 $(OBJ_EX_ex_cpp_3_MT_UX)\
 $(OBJ_EX_ex_c_1_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_2_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_3_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_4_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_5_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_6_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_7_MT_UX_DEBUG)\
 $(OBJ_EX_ex_c_8_MT_UX_DEBUG)\
 $(OBJ_EX_ex_cpp_1_MT_UX_DEBUG)\
 $(OBJ_EX_ex_cpp_2_MT_UX_DEBUG)\
 $(OBJ_EX_ex_cpp_3_MT_UX_DEBUG)\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_api_crdir_MT_UX)\
 $(OBJ_TEST_COMP_api_rmdir_MT_UX)\
 $(OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG)\
 $(OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_srch1_MT_UX)\
 $(OBJ_TEST_SCRT_srch1_MT_UX_DEBUG)\
 \

# TODO: Add this project
# $(OBJ_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) \


# Unit Tests
OBJS_TEST_UNIT=\
 $(OBJ_TEST_UNIT_api_cmbpaths_MT_UX)\
 $(OBJ_TEST_UNIT_api_sqzpath_MT_UX)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX)\
 $(OBJ_TEST_UNIT_cpp_drvrel_MT_UX)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX)\
 $(OBJ_TEST_UNIT_cpp_retcodes_MT_UX)\
 $(OBJ_TEST_UNIT_c_retcodes_MT_UX)\
 $(OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)\
 $(OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG)\
 \

# TODO: Add this project
# $(OBJ_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ] ) \

########################################
# Libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_UX)\
 $(LIB_CORE_MT_UX_DEBUG)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_UX)\
 $(LIB_SHWILD_MT_UX_DEBUG)\
 \

TARGETS_LIB_XTESTS=\
 $(LIB_XTESTS_MT_UX)\
 $(LIB_XTESTS_MT_UX_DEBUG)\
 \

########################################
# Programs

TARGETS_EXAMPLE_C=\
 $(TARG_EX_ex_c_1_MT_UX)\
 $(TARG_EX_ex_c_2_MT_UX)\
 $(TARG_EX_ex_c_3_MT_UX)\
 $(TARG_EX_ex_c_4_MT_UX)\
 $(TARG_EX_ex_c_5_MT_UX)\
 $(TARG_EX_ex_c_6_MT_UX)\
 $(TARG_EX_ex_c_7_MT_UX)\
 $(TARG_EX_ex_c_8_MT_UX)\
 $(TARG_EX_ex_c_1_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_2_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_3_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_4_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_5_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_6_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_7_MT_UX_DEBUG)\
 $(TARG_EX_ex_c_8_MT_UX_DEBUG)\
 \

TARGETS_EXAMPLE_CPP=\
 $(TARG_EX_ex_cpp_1_MT_UX)\
 $(TARG_EX_ex_cpp_2_MT_UX)\
 $(TARG_EX_ex_cpp_3_MT_UX)\
 $(TARG_EX_ex_cpp_1_MT_UX_DEBUG)\
 $(TARG_EX_ex_cpp_2_MT_UX_DEBUG)\
 $(TARG_EX_ex_cpp_3_MT_UX_DEBUG)\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \

TARGETS_SAMPLE=\
 \

TARGETS_TEST_COMPONENT=\
 $(TARG_TEST_COMP_api_crdir_MT_UX)\
 $(TARG_TEST_COMP_api_rmdir_MT_UX)\
 $(TARG_TEST_COMP_api_crdir_MT_UX_DEBUG)\
 $(TARG_TEST_COMP_api_rmdir_MT_UX_DEBUG)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_srch1_MT_UX)\
 $(TARG_TEST_SCRT_srch1_MT_UX_DEBUG)\
 \

# TODO: Add this project
# $(TARG_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) \


TARGETS_TEST_UNIT=\
 $(TARG_TEST_UNIT_api_cmbpaths_MT_UX)\
 $(TARG_TEST_UNIT_api_sqzpath_MT_UX)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX)\
 $(TARG_TEST_UNIT_cpp_drvrel_MT_UX)\
 $(TARG_TEST_UNIT_cpp_sqzpath_MT_UX)\
 $(TARG_TEST_UNIT_cpp_retcodes_MT_UX)\
 $(TARG_TEST_UNIT_c_retcodes_MT_UX)\
 $(TARG_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)\
 $(TARG_TEST_UNIT_c_retcodes_MT_UX_DEBUG)\
 \

# TODO: Add this project
# $(TARG_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ])\

############################################################################
# External Targets (invokable by make)

# primary

_default:                   build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure

check.lib.dir:              $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:              $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:          $(PROJ_MAKEFILE_NAME)   $(OBJS_CORE)

compile.libs.shwild:        $(PROJ_MAKEFILE_NAME)   $(OBJS_SHWILD)

compile.libs.xcover:        $(PROJ_MAKEFILE_NAME)   $(OBJS_XCOVER)

compile.libs.xtests:        $(PROJ_MAKEFILE_NAME)   $(OBJS_XTESTS)

compile.libs:                                       compile.libs.core compile.libs.shwild compile.libs.xcover compile.libs.xtests

compile.examples:           $(PROJ_MAKEFILE_NAME)   $(OBJS_EXAMPLE)

compile.samples:            $(PROJ_MAKEFILE_NAME)   $(OBJS_SAMPLE)

compile.test.component:     $(PROJ_MAKEFILE_NAME)   $(OBJS_TEST_COMPONENT)

compile.test.performance:   $(PROJ_MAKEFILE_NAME)   $(OBJS_TEST_PERFORMANCE)

compile.test.scratch:       $(PROJ_MAKEFILE_NAME)   $(OBJS_TEST_SCRATCH)

compile.test.unit:          $(PROJ_MAKEFILE_NAME)   $(OBJS_TEST_UNIT)

compile.test:                                       compile.test.unit compile.test.component compile.test.scratch compile.test.performance

compile:                                            compile.libs compile.test compile.examples compile.samples

compile.all:                                        compile



# build targets

build.libs.core:            check.lib.dir           $(TARGETS_LIB_CORE)

build.libs.shwild:          check.lib.dir           $(TARGETS_LIB_SHWILD)

build.libs.xcover:          check.lib.dir           $(TARGETS_LIB_XCOVER)

build.libs.xtests:          check.lib.dir           $(TARGETS_LIB_XTESTS)

build.libs:                                         build.libs.core build.libs.shwild build.libs.xcover build.libs.xtests

build.examples:             check.bin.dir           $(TARGETS_EXAMPLE)

build.ex.c:					check.bin.dir           $(TARGETS_EXAMPLE_C)

build.ex.c++:				check.bin.dir           $(TARGETS_EXAMPLE_CPP)

build.samples:              check.bin.dir           $(TARGETS_SAMPLE)

build.test.component:       check.bin.dir           $(TARGETS_TEST_COMPONENT)

build.test.performance:     check.bin.dir           $(TARGETS_TEST_PERFORMANCE)

build.test.scratch:         check.bin.dir           $(TARGETS_TEST_SCRATCH)

build.test.unit:            check.bin.dir           $(TARGETS_TEST_UNIT)

build.test:                                         build.test.unit build.test.component build.test.scratch build.test.performance

build:                                              build.libs build.examples build.samples build.test

build.all:                                          build



# test targets

test.component_:
	@echo Running Test:Component programs ...
	$(TARG_TEST_COMP_api_crdir_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_srch1_MT_UX)
	$(TARG_TEST_SCRT_srch1_MT_UX_DEBUG)


# TODO: Add this project
#	$(TARG_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) 

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_api_cmbpaths_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_MT_UX) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_MT_UX_DEBUG) --verbosity=$(TEST_VERBOSITY)

# TODO: Add this project
#	$(TARG_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ] ) --verbosity=$(TEST_VERBOSITY)


test.ex.c_:
	@echo C Example programs ...
	-$(TARG_EX_ex_c_1_MT_UX)
	-$(TARG_EX_ex_c_2_MT_UX)
	-$(TARG_EX_ex_c_3_MT_UX)
	-$(TARG_EX_ex_c_4_MT_UX)
	-$(TARG_EX_ex_c_5_MT_UX)
	-$(TARG_EX_ex_c_6_MT_UX)
	-$(TARG_EX_ex_c_7_MT_UX)
	-$(TARG_EX_ex_c_8_MT_UX)
	-$(TARG_EX_ex_c_1_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_2_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_3_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_4_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_5_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_6_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_7_MT_UX_DEBUG)
	-$(TARG_EX_ex_c_8_MT_UX_DEBUG)

test.ex.cpp_:
	@echo C++ Example programs ...


test.component:             build.test.component test.component_

test.scratch:               build.test.scratch test.scratch_

test.unit:                  build.test.unit test.unit_

test.ex.c:					build.ex.c test.ex.c_

test.ex.cpp:				build.ex.cpp test.ex.cpp_

test.examples:              test.ex.c test.ex.cpp

test:                       test.unit test.component

test.all:                   test test.scratch
test-all:                   test.all



# clean targets

clean.libs.core:
	@echo Cleaning Core libraries ...
	@-$(RM) $(LIB_CORE_MT_UX)
	@-$(RM) $(LIB_CORE_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_entryinfo_MT_UX)
	@-$(RM) $(OBJ_CR_api_error_MT_UX)
	@-$(RM) $(OBJ_CR_api_extended_MT_UX)
	@-$(RM) $(OBJ_CR_api_combpath_MT_UX)
	@-$(RM) $(OBJ_CR_api_derrpath_MT_UX)
	@-$(RM) $(OBJ_CR_api_getflsizs_MT_UX)
	@-$(RM) $(OBJ_CR_api_sqzpath_MT_UX)
	@-$(RM) $(OBJ_CR_api_stat_MT_UX)
	@-$(RM) $(OBJ_CR_api_crdir_MT_UX)
	@-$(RM) $(OBJ_CR_api_rmdir_MT_UX)
	@-$(RM) $(OBJ_CR_api_search_MT_UX)
	@-$(RM) $(OBJ_CR_impl_debug_MT_UX)
	@-$(RM) $(OBJ_CR_impl_entryinfo_MT_UX)
	@-$(RM) $(OBJ_CR_impl_fileinfo_MT_UX)
	@-$(RM) $(OBJ_CR_impl_snprintf_MT_UX)
	@-$(RM) $(OBJ_CR_impl_util_MT_UX)
	@-$(RM) $(OBJ_CR_Srch_MT_UX)
	@-$(RM) $(OBJ_CR_FlSrch_MT_UX)
	@-$(RM) $(OBJ_CR_FlSchDirNode_MT_UX)
	@-$(RM) $(OBJ_CR_api_unix_MT_UX)
	@-$(RM) $(OBJ_CR_impl_fileinfo_unix_MT_UX)
	@-$(RM) $(OBJ_CR_impl_util_unix_MT_UX)
	@-$(RM) $(OBJ_CR_api_entryinfo_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_error_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_extended_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_combpath_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_derrpath_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_getflsizs_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_sqzpath_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_stat_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_crdir_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_rmdir_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_search_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_debug_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_entryinfo_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_fileinfo_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_snprintf_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_util_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_Srch_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_FlSrch_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_FlSchDirNode_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_api_unix_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_fileinfo_unix_MT_UX_DEBUG)
	@-$(RM) $(OBJ_CR_impl_util_unix_MT_UX_DEBUG)

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-$(RM) $(LIB_SHWILD_MT_UX)
	@-$(RM) $(LIB_SHWILD_MT_UX_DEBUG)
	@-$(RM) $(OBJ_SHWILD_MT_UX)
	@-$(RM) $(OBJ_SHWILD_MT_UX_DEBUG)
	@-$(RM) $(PDB_SHWILD_MT_UX_DEBUG)

clean.libs.xcover:
	@echo Cleaning xCover libraries ...

clean.libs.xtests:
	@echo Cleaning xTests libraries ...
	@-$(RM) $(LIB_XTESTS_MT_UX)
	@-$(RM) $(LIB_XTESTS_MT_UX_DEBUG)
	@-$(RM) $(OBJ_XTESTS_MT_UX)
	@-$(RM) $(OBJ_XTESTS_MT_UX_DEBUG)
	@-$(RM) $(PDB_XTESTS_MT_UX_DEBUG)

clean.libs:                                         clean.libs.core clean.libs.shwild clean.libs.xcover clean.libs.xtests

clean.examples:
	@echo cleaning Example programs ...
	@-$(RM) $(TARG_EX_ex_c_1_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_1_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_2_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_2_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_3_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_3_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_4_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_4_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_5_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_5_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_6_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_6_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_7_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_7_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_8_MT_UX)
	@-$(RM) $(OBJ_EX_ex_c_8_MT_UX)
	@-$(RM) $(TARG_EX_ex_cpp_1_MT_UX)
	@-$(RM) $(OBJ_EX_ex_cpp_1_MT_UX)
	@-$(RM) $(TARG_EX_ex_cpp_2_MT_UX)
	@-$(RM) $(OBJ_EX_ex_cpp_2_MT_UX)
	@-$(RM) $(TARG_EX_ex_cpp_3_MT_UX)
	@-$(RM) $(OBJ_EX_ex_cpp_3_MT_UX)
	@-$(RM) $(TARG_EX_ex_c_1_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_1_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_2_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_2_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_3_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_3_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_4_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_4_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_5_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_5_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_6_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_6_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_7_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_7_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_c_8_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_c_8_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_cpp_1_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_cpp_1_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_cpp_2_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_cpp_2_MT_UX_DEBUG)
	@-$(RM) $(TARG_EX_ex_cpp_3_MT_UX_DEBUG)
	@-$(RM) $(OBJ_EX_ex_cpp_3_MT_UX_DEBUG)

clean.samples:
	@echo cleaning Sample programs ...

clean.test.component:
	@echo Cleaning Test::Component files ...
	@-$(RM) $(TARG_TEST_COMP_api_crdir_MT_UX)
	@-$(RM) $(TARG_TEST_COMP_api_rmdir_MT_UX)
	@-$(RM) $(OBJ_TEST_COMP_api_crdir_MT_UX)
	@-$(RM) $(OBJ_TEST_COMP_api_rmdir_MT_UX)
	@-$(RM) $(TARG_TEST_COMP_api_crdir_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_COMP_api_rmdir_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG)

clean.test.scratch:
	@-$(RM) $(TARG_TEST_SCRT_srch1_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_srch1_MT_UX)
	@-$(RM) $(TARG_TEST_SCRT_srch2_MT_UX)
	@-$(RM) $(OBJ_TEST_SCRT_srch2_MT_UX)
	@-$(RM) $(TARG_TEST_SCRT_srch1_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_srch1_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_SCRT_srch2_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_SCRT_srch2_MT_UX_DEBUG)

clean.test.unit:
	@-$(RM) $(TARG_TEST_UNIT_api_cmbpaths_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_api_cmbpaths_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_api_drvrel_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_api_drvrel_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_api_sqzpath_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_api_sqzpath_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_cpp_drvrel_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_drvrel_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_cpp_sqzpath_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_cpp_retcodes_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_retcodes_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_c_retcodes_MT_UX)
	@-$(RM) $(OBJ_TEST_UNIT_c_retcodes_MT_UX)
	@-$(RM) $(TARG_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_api_drvrel_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_api_drvrel_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)
	@-$(RM) $(TARG_TEST_UNIT_c_retcodes_MT_UX_DEBUG)
	@-$(RM) $(OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG)

clean.test:                                         clean.test.unit clean.test.component clean.test.scratch

clean:                                              clean.libs clean.test clean.examples clean.samples

clean.all:                                          clean


############################################################################
# build targets

##################################################
# Libraries

########################################
# Main library - 'recls.X.core.a'

$(LIB_CORE_MT_UX): $(OBJ_CORE_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_UX)

$(OBJ_CR_api_entryinfo_MT_UX): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_MT_UX): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_MT_UX): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_MT_UX): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_UX): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_UX): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_UX): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_UX): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_UX): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_UX): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_search_MT_UX): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_MT_UX): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_UX): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_UX): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_UX): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_UX): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_MT_UX): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_UX): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_UX): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_unix_MT_UX): $(PROJ_SRC_DIR)\api.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\api.unix.cpp
$(OBJ_CR_impl_fileinfo_unix_MT_UX): $(PROJ_SRC_DIR)\impl.fileinfo.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.unix.cpp
$(OBJ_CR_impl_util_unix_MT_UX): $(PROJ_SRC_DIR)\impl.util.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_SRC_DIR)\impl.util.unix.cpp


$(LIB_CORE_MT_UX_DEBUG): $(OBJ_CORE_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_UX_DEBUG)

$(OBJ_CR_api_entryinfo_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_search_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_MT_UX_DEBUG): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_UX_DEBUG): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_UX_DEBUG): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_unix_MT_UX_DEBUG): $(PROJ_SRC_DIR)\api.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\api.unix.cpp
$(OBJ_CR_impl_fileinfo_unix_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.fileinfo.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.unix.cpp
$(OBJ_CR_impl_util_unix_MT_UX_DEBUG): $(PROJ_SRC_DIR)\impl.util.unix.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\impl.util.unix.cpp



########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_MT_UX): $(OBJ_SHWILD_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_UX)

$(OBJ_shw_api_MT_UX): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_UX): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_UX): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_SHWILD_INCLUDES_MT_UX) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_UX_DEBUG): $(OBJ_SHWILD_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_UX_DEBUG)

$(OBJ_shw_api_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_UX_DEBUG): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_SHWILD_INCLUDES_MT_UX_DEBUG) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp


########################################
# xTests library - 'xtests.X.recls.core.a'

$(LIB_XTESTS_MT_UX): $(OBJ_XTESTS_MT_UX) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_UX)

$(OBJ_xts_core_MT_UX): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) $(CPPC_XTESTS_INCLUDES_MT_UX) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_UX_DEBUG): $(OBJ_XTESTS_MT_UX_DEBUG) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_UX_DEBUG)

$(OBJ_xts_core_MT_UX_DEBUG): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) $(CPPC_XTESTS_INCLUDES_MT_UX_DEBUG) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp


##################################################
# Examples

$(TARG_EX_ex_c_1_MT_UX):    \
		$(OBJ_EX_ex_c_1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_1_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_1_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_2_MT_UX):    \
		$(OBJ_EX_ex_c_2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_2_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_2_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_3_MT_UX):    \
		$(OBJ_EX_ex_c_3_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_3_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_3_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_3_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_3_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_3_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_4_MT_UX):    \
		$(OBJ_EX_ex_c_4_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_4_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_4_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_4_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_4_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_4_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_5_MT_UX):    \
		$(OBJ_EX_ex_c_5_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_5_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_5_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_5_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_5_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_5_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_6_MT_UX):    \
		$(OBJ_EX_ex_c_6_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_6_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_6_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_6_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_6_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_6_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_7_MT_UX):    \
		$(OBJ_EX_ex_c_7_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_7_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_7_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_7_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_7_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_7_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_8_MT_UX):    \
		$(OBJ_EX_ex_c_8_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_c_8_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_c_8_MT_UX): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_c_8_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_c_8_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_c_8_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c


$(TARG_EX_ex_cpp_1_MT_UX):    \
		$(OBJ_EX_ex_cpp_1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_cpp_1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_cpp_1_MT_UX): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_cpp_1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_cpp_1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_cpp_1_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_2_MT_UX):    \
		$(OBJ_EX_ex_cpp_2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_cpp_2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_cpp_2_MT_UX): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_cpp_2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_cpp_2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_cpp_2_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_3_MT_UX):    \
		$(OBJ_EX_ex_cpp_3_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_EX_ex_cpp_3_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_EX_ex_cpp_3_MT_UX): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_MT_UX_DEBUG):    \
		$(OBJ_EX_ex_cpp_3_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_EX_ex_cpp_3_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_EX_ex_cpp_3_MT_UX_DEBUG): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp


##################################################
# Tests




##############################
# Component Tests

$(TARG_TEST_COMP_api_crdir_MT_UX):    \
		$(OBJ_TEST_COMP_api_crdir_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_COMP_api_crdir_MT_UX): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_MT_UX_DEBUG):    \
		$(OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_COMP_api_crdir_MT_UX_DEBUG): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_UX):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_COMP_api_rmdir_MT_UX): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_UX_DEBUG):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_COMP_api_rmdir_MT_UX_DEBUG): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp


##############################
# Scratch Tests

$(TARG_TEST_SCRT_srch1_MT_UX):    \
		$(OBJ_TEST_SCRT_srch1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_SCRT_srch1_MT_UX): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_MT_UX_DEBUG):    \
		$(OBJ_TEST_SCRT_srch1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_SCRT_srch1_MT_UX_DEBUG): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch2_MT_UX):    \
		$(OBJ_TEST_SCRT_srch2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_SCRT_srch2_MT_UX): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_MT_UX_DEBUG):    \
		$(OBJ_TEST_SCRT_srch2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_SCRT_srch2_MT_UX_DEBUG): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


##############################
# Unit Tests

$(TARG_TEST_UNIT_api_cmbpaths_MT_UX):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_drvrel_MT_UX):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_api_drvrel_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_api_drvrel_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_UX):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_api_sqzpath_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_api_sqzpath_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c


$(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_UX):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_UX):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_UX):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_c_retcodes_MT_UX):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_UX)\
		$(LIB_CORE_MT_UX)\
		$(LIB_SHWILD_MT_UX)\
		$(LIB_XTESTS_MT_UX)\
		$(TARGET_LIB_MT_UX)

$(OBJ_TEST_UNIT_c_retcodes_MT_UX): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_MT_UX_DEBUG):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_UX_DEBUG) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG)\
		$(LIB_CORE_MT_UX_DEBUG)\
		$(LIB_SHWILD_MT_UX_DEBUG)\
		$(LIB_XTESTS_MT_UX_DEBUG)\
		$(TARGET_LIB_MT_UX_DEBUG)

$(OBJ_TEST_UNIT_c_retcodes_MT_UX_DEBUG): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_UX_DEBUG) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c


############################### end of file ################################
