############################################################################
# File:     makefile
#
# Purpose:  Makefile for the recls project,
#           for the GCC 9.2 compiler,
#           on the Win32 platform
#
# Created:  16th October 2019
# Updated:  22nd December 2020
#
############################################################################


############################################################################
# environment check

ifndef STLSOFT
$(error STLSOFT must be defined)
endif # !STLSOFT

############################################################################
# symbols

########################################
# project & compiler version

COMP_TAG            =   gcc92
ARCH_TAG            =   
OS_TAG              =   
PROJ_TAG            =   recls
PROJ_VER_MAJOR      =   1
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG    =   $(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XTESTS_VER_MAJOR    =   0
XTESTS_TAG_VER      =   xtests.$(XTESTS_VER_MAJOR)

UNIXEM_VER_MAJOR    =   1
UNIXEM_TAG_VER      =   unixem.$(UNIXEM_VER_MAJOR)

PROJ_MAKEFILE_NAME  =   makefile

########################################
# testing verbosity

ifndef TEST_VERBOSITY
TEST_VERBOSITY      =   2
endif # !TEST_VERBOSITY

########################################
# directories

PROJ_BASE_DIR           =   ../..
PROJ_BIN_DIR            =   $(PROJ_BASE_DIR)/bin
PROJ_INCLUDE_DIR        =   $(PROJ_BASE_DIR)/include
PROJ_LIB_DIR            =   $(PROJ_BASE_DIR)/lib
PROJ_OBJ_DIR            =   .
PROJ_SRC_DIR            =   $(PROJ_BASE_DIR)/src
PROJ_EXAMPLES_DIR       =   $(PROJ_BASE_DIR)/examples
PROJ_SAMPLES_DIR        =   $(PROJ_BASE_DIR)/samples
PROJ_TEST_ROOT_DIR      =   $(PROJ_BASE_DIR)/test
PROJ_TEST_COMPONENT_DIR =   $(PROJ_TEST_ROOT_DIR)/component
PROJ_TEST_PERFORMANCE_DIR	=	$(PROJ_TEST_ROOT_DIR)/performance
PROJ_TEST_SCRATCH_DIR   =   $(PROJ_TEST_ROOT_DIR)/scratch
PROJ_TEST_UNIT_DIR      =   $(PROJ_TEST_ROOT_DIR)/unit

SHWILD_PROJ_INCLUDE		=	
ifdef RECLS_SHWILD_BASE_DIR
SHWILD_INCLUDE_DIR		=   $(RECLS_SHWILD_BASE_DIR)/include
SHWILD_SRC_DIR			=   $(RECLS_SHWILD_BASE_DIR)/src
SHWILD_PROJ_INCLUDE		=	-I$(SHWILD_INCLUDE_DIR)
else
SHWILD_INCLUDE_DIR		=   $(PROJ_BASE_DIR)/include
SHWILD_SRC_DIR			=   $(PROJ_SRC_DIR)/shwild
endif # !RECLS_SHWILD_BASE_DIR

XCONTRACT_PROJ_INCLUDE	=	

XTESTS_PROJ_INCLUDE		=	
ifdef RECLS_XTESTS_BASE_DIR
XTESTS_INCLUDE_DIR		=   $(RECLS_XTESTS_BASE_DIR)/include
XTESTS_SRC_DIR			=   $(RECLS_XTESTS_BASE_DIR)/src
XTESTS_PROJ_INCLUDE		=	-I$(XTESTS_INCLUDE_DIR)
else
XTESTS_INCLUDE_DIR		=   $(PROJ_BASE_DIR)/include
XTESTS_SRC_DIR			=   $(PROJ_SRC_DIR)/xtests
endif # !RECLS_XTESTS_BASE_DIR

ifdef STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=	-I$(STLSOFT_1_10)/include
else # ? STLSOFT_1_10
STLSOFT_1_10_INCLUDE	=
endif # !STLSOFT_1_10


STLSOFT_PROJ_INCLUDE	=	-I$(STLSOFT)/include

########################################
# tools

CC                      =   gcc
CPPC                    =   g++
AR                      =   ar
LD                      =   g++
RM                      =   rm -f
CP                      =   cp
RC                      =   rc

# includes

INCLUDES_LEADER         =   

PROJ_INCLUDE            =   -I$(PROJ_INCLUDE_DIR)

ENV_INCLUDES            =

COMMON_INCLUDES         =





# lib

LIBS_LEADER             =   

# lib paths

ENV_LIBPATHS        =
COMMON_LIBPATHS         =


LIBPATHS=\
$(LIBS_LEADER)\
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_D=\
 -lkernel32 -ladvapi32 -lole32 -loleaut32 -lshlwapi -luser32 -luuid -lwininet -lws2_32 \
 \

TARGET_LIB_MT_R=\
 -lkernel32 -ladvapi32 -lole32 -loleaut32 -lshlwapi -luser32 -luuid -lwininet -lws2_32 \
 \

TARGET_LIB_ST_D=\
 -lkernel32 -ladvapi32 -lole32 -loleaut32 -lshlwapi -luser32 -luuid -lwininet -lws2_32 \
 \

TARGET_LIB_ST_R=\
 -lkernel32 -ladvapi32 -lole32 -loleaut32 -lshlwapi -luser32 -luuid -lwininet -lws2_32 \
 \


# #defines

OS_DEFS				=	-DWIN32

COMMON_DEFS_		= \
 -DB64_NO_USE_XCONTRACT\
 -DB64_NO_USE_XCOVER\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCONTRACT\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 \

COMMON_DEFS			= \
 $(COMMON_DEFS_)\
 \

CUSTOM_DEFS			=

CC_CUSTOM_DEFS		=	$(CUSTOM_DEFS)

CPPC_CUSTOM_DEFS	=	$(CUSTOM_DEFS)



# CC flags

CC_F_NOLOGO           =   
CC_F_COMPILE_ONLY     =   -c
CC_F_WARNING_MAX      =   -Wall -pedantic -Wno-long-long -Wno-unused-value -Wundef -Wshadow
CC_F_WARNING_ERR      =   -Werror
CC_F_MINIMUM_SIZE     =   -O1
CC_F_MAXIMUM_SPEED    =   -O3

CC_FLAGS_BASE=\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CC_FLAGS_MT_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_R=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_ST_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_ST_R=\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -Wall -pedantic -Wno-long-long -Wno-non-virtual-dtor -Wno-parentheses -Wno-unused-value
CPPC_F_WARNING_ERR      =   -Werror
CPPC_F_EXCEPTIONS_ON    =   
CPPC_F_EXCEPTIONS_OFF   =   
CPPC_F_EXCEPTIONS		=	$(CPPC_F_EXCEPTIONS_ON)
CPPC_F_RTTI_ON          =   
CPPC_F_RTTI_OFF         =   
CPPC_F_RTTI             =   $(CPPC_F_RTTI_ON)
CPPC_F_MINIMUM_SIZE     =   -O1
CPPC_F_MAXIMUM_SPEED	=	-O3

CPPC_FLAGS_BASE=\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

CPPC_FLAGS_MT_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_ST_R=\
 $(CPPC_FLAGS_BASE)\
 \



# CC defines

CC_DEFS_BASE=\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CC_CUSTOM_DEFS)\
 \

CC_DEFS_MT_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_R=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_ST_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_ST_R=\
 $(CC_DEFS_BASE)\
 \


# CPPC defines

CPPC_DEFS_BASE=\
 $(COMMON_DEFS)\
 $(OS_DEFS)\
 $(CPPC_CUSTOM_DEFS)\
 \

CPPC_DEFS_MT_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_MT_R=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_ST_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_ST_R=\
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
 $(ENV_INCLUDES)\
 \

CC_INCLUDES_MT_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_R=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_ST_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_ST_R=\
 $(CC_INCLUDES_BASE)\
 \



CC_SHWILD_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_ST_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_ST_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_R=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_ST_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_ST_R=\
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
 $(ENV_INCLUDES)\
 \

CPPC_INCLUDES_MT_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_MT_R=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_ST_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_ST_R=\
 $(CPPC_INCLUDES_BASE)\
 \



CPPC_SHWILD_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_ST_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_ST_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_D=\
 $(CC_FLAGS_MT_D)\
 $(CC_CUSTOM_DEFS_DEBUG) -D_REENTRANT -UNDEBUG -D_DEBUG\
 \
 $(CC_DEFS_MT_D)\
 $(CC_INCLUDES_MT_D)
CC_ARGS_MT_R=\
 $(CC_FLAGS_MT_R)\
 -D_REENTRANT -U_DEBUG -DNDEBUG $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_RELEASE)\
 \
 $(CC_DEFS_MT_R)\
 $(CC_INCLUDES_MT_R)
CC_ARGS_ST_D=\
 $(CC_FLAGS_ST_D)\
 $(CC_CUSTOM_DEFS_DEBUG) -UNDEBUG -D_DEBUG\
 \
 $(CC_DEFS_ST_D)\
 $(CC_INCLUDES_ST_D)
CC_ARGS_ST_R=\
 $(CC_FLAGS_ST_R)\
 $(CC_F_MAXIMUM_SPEED) $(CC_CUSTOM_DEFS_RELEASE) -U_DEBUG -DNDEBUG\
 \
 $(CC_DEFS_ST_R)\
 $(CC_INCLUDES_ST_R)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -D_REENTRANT -UNDEBUG -D_DEBUG\
 \
 $(CPPC_DEFS_MT_D)\
 $(CPPC_INCLUDES_MT_D)

CPPC_ARGS_core_MT_D=\
 -DRECLS_API_FTP\
 $(CPPC_ARGS_MT_D)\
 \

CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 -D_REENTRANT -U_DEBUG -DNDEBUG $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_RELEASE)\
 \
 $(CPPC_DEFS_MT_R)\
 $(CPPC_INCLUDES_MT_R)

CPPC_ARGS_core_MT_R=\
 -DRECLS_API_FTP\
 $(CPPC_ARGS_MT_R)\
 \

CPPC_ARGS_ST_D=\
 $(CPPC_FLAGS_ST_D)\
 $(CPPC_CUSTOM_DEFS_DEBUG) -UNDEBUG -D_DEBUG\
 \
 $(CPPC_DEFS_ST_D)\
 $(CPPC_INCLUDES_ST_D)

CPPC_ARGS_core_ST_D=\
 -DRECLS_API_FTP\
 $(CPPC_ARGS_ST_D)\
 \

CPPC_ARGS_ST_R=\
 $(CPPC_FLAGS_ST_R)\
 $(CPPC_F_MAXIMUM_SPEED) $(CPPC_CUSTOM_DEFS_RELEASE) -U_DEBUG -DNDEBUG\
 \
 $(CPPC_DEFS_ST_R)\
 $(CPPC_INCLUDES_ST_R)

CPPC_ARGS_core_ST_R=\
 -DRECLS_API_FTP\
 $(CPPC_ARGS_ST_R)\
 \




# AR Args

AR_ARGS             =   


# LD flags

LD_F_NOLOGO				=   

LD_FLAGS_BASE=\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_ST_R=\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE=\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_ST_R=\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_D= $(LD_FLAGS_MT_D)  $(LD_INCLUDES_MT_D)
LD_ARGS_MT_R= $(LD_FLAGS_MT_R)  $(LD_INCLUDES_MT_R)
LD_ARGS_ST_D= $(LD_FLAGS_ST_D)  $(LD_INCLUDES_ST_D)
LD_ARGS_ST_R= $(LD_FLAGS_ST_R)  $(LD_INCLUDES_ST_R)



# 3rd party libraries

3PTY_LIBS_BASE=\
 -lole32\
 -loleaut32\
 \


3PTY_LIBS_MT_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_MT_R	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_ST_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_ST_R	=\
 $(3PTY_LIBS_BASE)\
 \


############################################################################
# headers

CORE_HEADERS=\
 $(PROJ_INCLUDE_DIR)/recls/assert.h\
 $(PROJ_INCLUDE_DIR)/recls/ftp.h\
 $(PROJ_INCLUDE_DIR)/recls/implicit_link.h\
 $(PROJ_INCLUDE_DIR)/recls/recls.h\
 $(PROJ_INCLUDE_DIR)/recls/unix.h\
 $(PROJ_INCLUDE_DIR)/recls/windows.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_borland.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_ch.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_como.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_dmc.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_gcc.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_intel.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_msvc.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_mwerks.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_vectorc.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/compiler_watcom.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/language.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/platform.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/platform_types.h\
 $(PROJ_INCLUDE_DIR)/recls/internal/retcodes.h\
 \

CPP_API_HEADERS=\
 $(PROJ_INCLUDE_DIR)/recls/recls.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/common.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/directory_parts.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/entry.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/exceptions.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/ftp_search_sequence.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/root_sequence.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/search_sequence.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/traits.hpp\
 $(PROJ_INCLUDE_DIR)/recls/cpp/util.hpp\
 \


SHWILD_HEADERS=\
 $(SHWILD_INCLUDE_DIR)/shwild/shwild.h\
 $(SHWILD_INCLUDE_DIR)/shwild/shwild.hpp\
 \

XTESTS_HEADERS=\
 $(XTESTS_INCLUDE_DIR)/xtests/xtests.h\
 $(XTESTS_INCLUDE_DIR)/xtests/internal/safestr.h\
 \

############################################################################
# targets

########################################
# libraries

# recls
LIB_CORE_MT_D           =   $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_MT_R           =   $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_ST_D           =   $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).debug.lib
LIB_CORE_ST_R           =   $(PROJ_LIB_DIR)/$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).lib

# shwild
LIB_SHWILD_MT_D         =   $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_MT_R         =   $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_ST_D         =   $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).debug.lib
LIB_SHWILD_ST_R         =   $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).lib

# xtests
LIB_XTESTS_MT_D         =   $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XTESTS_MT_R         =   $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_ST_D         =   $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).debug.lib
LIB_XTESTS_ST_R         =   $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).lib

########################################
# examples

TARG_EX_ex_c_1_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_2_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_3_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_4_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_5_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_6_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_7_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_8_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_1_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_2_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_3_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_4_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_5_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_6_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_7_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_8_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_1_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_2_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_3_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_4_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_5_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_6_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_7_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_8_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_c_1_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_2_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_3_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_4_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_5_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_6_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_7_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_c_8_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).exe

TARG_EX_ex_cpp_1_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_2_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_3_MT_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_1_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_2_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_3_MT_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_1_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_cpp_2_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_cpp_3_ST_D	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).debug.exe
TARG_EX_ex_cpp_1_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_cpp_2_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).exe
TARG_EX_ex_cpp_3_ST_R	=	$(PROJ_BIN_DIR)/$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).exe

########################################
# tests

##############################
# component tests

TARG_TEST_COMP_api_crdir_MT_D	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_api_rmdir_MT_D	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_api_crdir_MT_R	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_rmdir_MT_R	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_crdir_ST_D	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_api_rmdir_ST_D	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_COMP_api_crdir_ST_R	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_COMP_api_rmdir_ST_R	=   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).exe

##############################
# scratch tests

TARG_TEST_SCRT_srch1_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_srch2_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_srch1_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch2_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch1_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_srch2_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_SCRT_srch1_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_SCRT_srch2_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).exe

##############################
# unit tests

TARG_TEST_UNIT_api_cmbpaths_MT_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_drvrel_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_sqzpath_MT_D   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_drvrel_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_D   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_retcodes_MT_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_c_retcodes_MT_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_cmbpaths_MT_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_drvrel_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_sqzpath_MT_R   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_drvrel_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_R   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_retcodes_MT_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_c_retcodes_MT_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_cmbpaths_ST_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_drvrel_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_sqzpath_ST_D   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_ST_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_cpp_drvrel_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_cpp_sqzpath_ST_D   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_cpp_retcodes_ST_D  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_c_retcodes_ST_D    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).debug.exe
TARG_TEST_UNIT_api_cmbpaths_ST_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_drvrel_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_api_sqzpath_ST_R   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_cpp_cmbpaths_ST_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_cpp_drvrel_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_cpp_sqzpath_ST_R   =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_cpp_retcodes_ST_R  =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).exe
TARG_TEST_UNIT_c_retcodes_ST_R    =   $(PROJ_BIN_DIR)/$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).exe


############################################################################
# objects

########################################
# libraries

# recls

OBJ_CR_api_entryinfo_MT_D		= $(PROJ_OBJ_DIR)/api.entryinfo.mt.debug.obj
OBJ_CR_api_error_MT_D			= $(PROJ_OBJ_DIR)/api.error.mt.debug.obj
OBJ_CR_api_extended_MT_D		= $(PROJ_OBJ_DIR)/api.extended.mt.debug.obj
OBJ_CR_api_combpath_MT_D		= $(PROJ_OBJ_DIR)/api.combpath.mt.debug.obj
OBJ_CR_api_derrpath_MT_D		= $(PROJ_OBJ_DIR)/api.derrpath.mt.debug.obj
OBJ_CR_api_getflsizs_MT_D		= $(PROJ_OBJ_DIR)/api.getflsizs.mt.debug.obj
OBJ_CR_api_sqzpath_MT_D		= $(PROJ_OBJ_DIR)/api.sqzpath.mt.debug.obj
OBJ_CR_api_stat_MT_D			= $(PROJ_OBJ_DIR)/api.stat.mt.debug.obj
OBJ_CR_api_crdir_MT_D			= $(PROJ_OBJ_DIR)/api.crdir.mt.debug.obj
OBJ_CR_api_rc_win_MT_D		= $(PROJ_OBJ_DIR)/api.retcodes.windows.mt.debug.obj
OBJ_CR_api_rmdir_MT_D			= $(PROJ_OBJ_DIR)/api.rmdir.mt.debug.obj
OBJ_CR_api_search_MT_D		= $(PROJ_OBJ_DIR)/api.search.mt.debug.obj
OBJ_CR_impl_debug_MT_D		= $(PROJ_OBJ_DIR)/impl.trace.mt.debug.obj
OBJ_CR_impl_entryinfo_MT_D	= $(PROJ_OBJ_DIR)/impl.entryinfo.mt.debug.obj
OBJ_CR_impl_fileinfo_MT_D		= $(PROJ_OBJ_DIR)/impl.fileinfo.mt.debug.obj
OBJ_CR_impl_snprintf_MT_D		= $(PROJ_OBJ_DIR)/impl.snprintf.mt.debug.obj
OBJ_CR_impl_util_MT_D			= $(PROJ_OBJ_DIR)/impl.util.mt.debug.obj
OBJ_CR_Srch_MT_D				= $(PROJ_OBJ_DIR)/ReclsSearch.mt.debug.obj
OBJ_CR_FlSrch_MT_D			= $(PROJ_OBJ_DIR)/ReclsFileSearch.mt.debug.obj
OBJ_CR_FlSchDirNode_MT_D		= $(PROJ_OBJ_DIR)/ReclsFileSearchDirectoryNode.mt.debug.obj
OBJ_CR_api_win32_MT_D				= $(PROJ_OBJ_DIR)/api.win32.mt.debug.obj
OBJ_CR_impl_fileinfo_win32_MT_D	= $(PROJ_OBJ_DIR)/impl.fileinfo.win32.mt.debug.obj
OBJ_CR_impl_util_win32_MT_D		= $(PROJ_OBJ_DIR)/impl.util.win32.mt.debug.obj
OBJ_CR_api_ftp_windows_MT_D	= $(PROJ_OBJ_DIR)/api.ftp.windows.mt.debug.obj
OBJ_CR_FtpSchDirNode_win_MT_D	= $(PROJ_OBJ_DIR)/ReclsFtpSearchDirectoryNode_windows.mt.debug.obj
OBJ_CR_FtpSrch_windows_MT_D	= $(PROJ_OBJ_DIR)/ReclsFtpSearch_windows.mt.debug.obj



OBJ_CORE_MT_D=\
 $(OBJ_CR_api_entryinfo_MT_D)\
 $(OBJ_CR_api_error_MT_D)\
 $(OBJ_CR_api_extended_MT_D)\
 $(OBJ_CR_api_combpath_MT_D)\
 $(OBJ_CR_api_derrpath_MT_D)\
 $(OBJ_CR_api_getflsizs_MT_D)\
 $(OBJ_CR_api_sqzpath_MT_D)\
 $(OBJ_CR_api_stat_MT_D)\
 $(OBJ_CR_api_crdir_MT_D)\
 $(OBJ_CR_api_rmdir_MT_D)\
 $(OBJ_CR_api_rc_win_MT_D)\
 $(OBJ_CR_api_search_MT_D)\
 $(OBJ_CR_impl_debug_MT_D)\
 $(OBJ_CR_impl_entryinfo_MT_D)\
 $(OBJ_CR_impl_fileinfo_MT_D)\
 $(OBJ_CR_impl_snprintf_MT_D)\
 $(OBJ_CR_impl_util_MT_D)\
 $(OBJ_CR_Srch_MT_D)\
 $(OBJ_CR_FlSrch_MT_D)\
 $(OBJ_CR_FlSchDirNode_MT_D)\
 $(OBJ_CR_api_win32_MT_D)\
 $(OBJ_CR_impl_fileinfo_win32_MT_D)\
 $(OBJ_CR_impl_util_win32_MT_D)\
 $(OBJ_CR_api_ftp_windows_MT_D)\
 $(OBJ_CR_FtpSchDirNode_win_MT_D)\
 $(OBJ_CR_FtpSrch_windows_MT_D)\
 \

OBJ_CR_api_entryinfo_MT_R		= $(PROJ_OBJ_DIR)/api.entryinfo.mt.obj
OBJ_CR_api_error_MT_R			= $(PROJ_OBJ_DIR)/api.error.mt.obj
OBJ_CR_api_extended_MT_R		= $(PROJ_OBJ_DIR)/api.extended.mt.obj
OBJ_CR_api_combpath_MT_R		= $(PROJ_OBJ_DIR)/api.combpath.mt.obj
OBJ_CR_api_derrpath_MT_R		= $(PROJ_OBJ_DIR)/api.derrpath.mt.obj
OBJ_CR_api_getflsizs_MT_R		= $(PROJ_OBJ_DIR)/api.getflsizs.mt.obj
OBJ_CR_api_sqzpath_MT_R		= $(PROJ_OBJ_DIR)/api.sqzpath.mt.obj
OBJ_CR_api_stat_MT_R			= $(PROJ_OBJ_DIR)/api.stat.mt.obj
OBJ_CR_api_crdir_MT_R			= $(PROJ_OBJ_DIR)/api.crdir.mt.obj
OBJ_CR_api_rc_win_MT_R		= $(PROJ_OBJ_DIR)/api.retcodes.windows.mt.obj
OBJ_CR_api_rmdir_MT_R			= $(PROJ_OBJ_DIR)/api.rmdir.mt.obj
OBJ_CR_api_search_MT_R		= $(PROJ_OBJ_DIR)/api.search.mt.obj
OBJ_CR_impl_debug_MT_R		= $(PROJ_OBJ_DIR)/impl.trace.mt.obj
OBJ_CR_impl_entryinfo_MT_R	= $(PROJ_OBJ_DIR)/impl.entryinfo.mt.obj
OBJ_CR_impl_fileinfo_MT_R		= $(PROJ_OBJ_DIR)/impl.fileinfo.mt.obj
OBJ_CR_impl_snprintf_MT_R		= $(PROJ_OBJ_DIR)/impl.snprintf.mt.obj
OBJ_CR_impl_util_MT_R			= $(PROJ_OBJ_DIR)/impl.util.mt.obj
OBJ_CR_Srch_MT_R				= $(PROJ_OBJ_DIR)/ReclsSearch.mt.obj
OBJ_CR_FlSrch_MT_R			= $(PROJ_OBJ_DIR)/ReclsFileSearch.mt.obj
OBJ_CR_FlSchDirNode_MT_R		= $(PROJ_OBJ_DIR)/ReclsFileSearchDirectoryNode.mt.obj
OBJ_CR_api_win32_MT_R				= $(PROJ_OBJ_DIR)/api.win32.mt.obj
OBJ_CR_impl_fileinfo_win32_MT_R	= $(PROJ_OBJ_DIR)/impl.fileinfo.win32.mt.obj
OBJ_CR_impl_util_win32_MT_R		= $(PROJ_OBJ_DIR)/impl.util.win32.mt.obj
OBJ_CR_api_ftp_windows_MT_R	= $(PROJ_OBJ_DIR)/api.ftp.windows.mt.obj
OBJ_CR_FtpSchDirNode_win_MT_R	= $(PROJ_OBJ_DIR)/ReclsFtpSearchDirectoryNode_windows.mt.obj
OBJ_CR_FtpSrch_windows_MT_R	= $(PROJ_OBJ_DIR)/ReclsFtpSearch_windows.mt.obj



OBJ_CORE_MT_R=\
 $(OBJ_CR_api_entryinfo_MT_R)\
 $(OBJ_CR_api_error_MT_R)\
 $(OBJ_CR_api_extended_MT_R)\
 $(OBJ_CR_api_combpath_MT_R)\
 $(OBJ_CR_api_derrpath_MT_R)\
 $(OBJ_CR_api_getflsizs_MT_R)\
 $(OBJ_CR_api_sqzpath_MT_R)\
 $(OBJ_CR_api_stat_MT_R)\
 $(OBJ_CR_api_crdir_MT_R)\
 $(OBJ_CR_api_rmdir_MT_R)\
 $(OBJ_CR_api_rc_win_MT_R)\
 $(OBJ_CR_api_search_MT_R)\
 $(OBJ_CR_impl_debug_MT_R)\
 $(OBJ_CR_impl_entryinfo_MT_R)\
 $(OBJ_CR_impl_fileinfo_MT_R)\
 $(OBJ_CR_impl_snprintf_MT_R)\
 $(OBJ_CR_impl_util_MT_R)\
 $(OBJ_CR_Srch_MT_R)\
 $(OBJ_CR_FlSrch_MT_R)\
 $(OBJ_CR_FlSchDirNode_MT_R)\
 $(OBJ_CR_api_win32_MT_R)\
 $(OBJ_CR_impl_fileinfo_win32_MT_R)\
 $(OBJ_CR_impl_util_win32_MT_R)\
 $(OBJ_CR_api_ftp_windows_MT_R)\
 $(OBJ_CR_FtpSchDirNode_win_MT_R)\
 $(OBJ_CR_FtpSrch_windows_MT_R)\
 \

OBJ_CR_api_entryinfo_ST_D		= $(PROJ_OBJ_DIR)/api.entryinfo.debug.obj
OBJ_CR_api_error_ST_D			= $(PROJ_OBJ_DIR)/api.error.debug.obj
OBJ_CR_api_extended_ST_D		= $(PROJ_OBJ_DIR)/api.extended.debug.obj
OBJ_CR_api_combpath_ST_D		= $(PROJ_OBJ_DIR)/api.combpath.debug.obj
OBJ_CR_api_derrpath_ST_D		= $(PROJ_OBJ_DIR)/api.derrpath.debug.obj
OBJ_CR_api_getflsizs_ST_D		= $(PROJ_OBJ_DIR)/api.getflsizs.debug.obj
OBJ_CR_api_sqzpath_ST_D		= $(PROJ_OBJ_DIR)/api.sqzpath.debug.obj
OBJ_CR_api_stat_ST_D			= $(PROJ_OBJ_DIR)/api.stat.debug.obj
OBJ_CR_api_crdir_ST_D			= $(PROJ_OBJ_DIR)/api.crdir.debug.obj
OBJ_CR_api_rc_win_ST_D		= $(PROJ_OBJ_DIR)/api.retcodes.windows.debug.obj
OBJ_CR_api_rmdir_ST_D			= $(PROJ_OBJ_DIR)/api.rmdir.debug.obj
OBJ_CR_api_search_ST_D		= $(PROJ_OBJ_DIR)/api.search.debug.obj
OBJ_CR_impl_debug_ST_D		= $(PROJ_OBJ_DIR)/impl.trace.debug.obj
OBJ_CR_impl_entryinfo_ST_D	= $(PROJ_OBJ_DIR)/impl.entryinfo.debug.obj
OBJ_CR_impl_fileinfo_ST_D		= $(PROJ_OBJ_DIR)/impl.fileinfo.debug.obj
OBJ_CR_impl_snprintf_ST_D		= $(PROJ_OBJ_DIR)/impl.snprintf.debug.obj
OBJ_CR_impl_util_ST_D			= $(PROJ_OBJ_DIR)/impl.util.debug.obj
OBJ_CR_Srch_ST_D				= $(PROJ_OBJ_DIR)/ReclsSearch.debug.obj
OBJ_CR_FlSrch_ST_D			= $(PROJ_OBJ_DIR)/ReclsFileSearch.debug.obj
OBJ_CR_FlSchDirNode_ST_D		= $(PROJ_OBJ_DIR)/ReclsFileSearchDirectoryNode.debug.obj
OBJ_CR_api_win32_ST_D				= $(PROJ_OBJ_DIR)/api.win32.debug.obj
OBJ_CR_impl_fileinfo_win32_ST_D	= $(PROJ_OBJ_DIR)/impl.fileinfo.win32.debug.obj
OBJ_CR_impl_util_win32_ST_D		= $(PROJ_OBJ_DIR)/impl.util.win32.debug.obj
OBJ_CR_api_ftp_windows_ST_D	= $(PROJ_OBJ_DIR)/api.ftp.windows.debug.obj
OBJ_CR_FtpSchDirNode_win_ST_D	= $(PROJ_OBJ_DIR)/ReclsFtpSearchDirectoryNode_windows.debug.obj
OBJ_CR_FtpSrch_windows_ST_D	= $(PROJ_OBJ_DIR)/ReclsFtpSearch_windows.debug.obj



OBJ_CORE_ST_D=\
 $(OBJ_CR_api_entryinfo_ST_D)\
 $(OBJ_CR_api_error_ST_D)\
 $(OBJ_CR_api_extended_ST_D)\
 $(OBJ_CR_api_combpath_ST_D)\
 $(OBJ_CR_api_derrpath_ST_D)\
 $(OBJ_CR_api_getflsizs_ST_D)\
 $(OBJ_CR_api_sqzpath_ST_D)\
 $(OBJ_CR_api_stat_ST_D)\
 $(OBJ_CR_api_crdir_ST_D)\
 $(OBJ_CR_api_rmdir_ST_D)\
 $(OBJ_CR_api_rc_win_ST_D)\
 $(OBJ_CR_api_search_ST_D)\
 $(OBJ_CR_impl_debug_ST_D)\
 $(OBJ_CR_impl_entryinfo_ST_D)\
 $(OBJ_CR_impl_fileinfo_ST_D)\
 $(OBJ_CR_impl_snprintf_ST_D)\
 $(OBJ_CR_impl_util_ST_D)\
 $(OBJ_CR_Srch_ST_D)\
 $(OBJ_CR_FlSrch_ST_D)\
 $(OBJ_CR_FlSchDirNode_ST_D)\
 $(OBJ_CR_api_win32_ST_D)\
 $(OBJ_CR_impl_fileinfo_win32_ST_D)\
 $(OBJ_CR_impl_util_win32_ST_D)\
 $(OBJ_CR_api_ftp_windows_ST_D)\
 $(OBJ_CR_FtpSchDirNode_win_ST_D)\
 $(OBJ_CR_FtpSrch_windows_ST_D)\
 \

OBJ_CR_api_entryinfo_ST_R		= $(PROJ_OBJ_DIR)/api.entryinfo.obj
OBJ_CR_api_error_ST_R			= $(PROJ_OBJ_DIR)/api.error.obj
OBJ_CR_api_extended_ST_R		= $(PROJ_OBJ_DIR)/api.extended.obj
OBJ_CR_api_combpath_ST_R		= $(PROJ_OBJ_DIR)/api.combpath.obj
OBJ_CR_api_derrpath_ST_R		= $(PROJ_OBJ_DIR)/api.derrpath.obj
OBJ_CR_api_getflsizs_ST_R		= $(PROJ_OBJ_DIR)/api.getflsizs.obj
OBJ_CR_api_sqzpath_ST_R		= $(PROJ_OBJ_DIR)/api.sqzpath.obj
OBJ_CR_api_stat_ST_R			= $(PROJ_OBJ_DIR)/api.stat.obj
OBJ_CR_api_crdir_ST_R			= $(PROJ_OBJ_DIR)/api.crdir.obj
OBJ_CR_api_rc_win_ST_R		= $(PROJ_OBJ_DIR)/api.retcodes.windows.obj
OBJ_CR_api_rmdir_ST_R			= $(PROJ_OBJ_DIR)/api.rmdir.obj
OBJ_CR_api_search_ST_R		= $(PROJ_OBJ_DIR)/api.search.obj
OBJ_CR_impl_debug_ST_R		= $(PROJ_OBJ_DIR)/impl.trace.obj
OBJ_CR_impl_entryinfo_ST_R	= $(PROJ_OBJ_DIR)/impl.entryinfo.obj
OBJ_CR_impl_fileinfo_ST_R		= $(PROJ_OBJ_DIR)/impl.fileinfo.obj
OBJ_CR_impl_snprintf_ST_R		= $(PROJ_OBJ_DIR)/impl.snprintf.obj
OBJ_CR_impl_util_ST_R			= $(PROJ_OBJ_DIR)/impl.util.obj
OBJ_CR_Srch_ST_R				= $(PROJ_OBJ_DIR)/ReclsSearch.obj
OBJ_CR_FlSrch_ST_R			= $(PROJ_OBJ_DIR)/ReclsFileSearch.obj
OBJ_CR_FlSchDirNode_ST_R		= $(PROJ_OBJ_DIR)/ReclsFileSearchDirectoryNode.obj
OBJ_CR_api_win32_ST_R				= $(PROJ_OBJ_DIR)/api.win32.obj
OBJ_CR_impl_fileinfo_win32_ST_R	= $(PROJ_OBJ_DIR)/impl.fileinfo.win32.obj
OBJ_CR_impl_util_win32_ST_R		= $(PROJ_OBJ_DIR)/impl.util.win32.obj
OBJ_CR_api_ftp_windows_ST_R	= $(PROJ_OBJ_DIR)/api.ftp.windows.obj
OBJ_CR_FtpSchDirNode_win_ST_R	= $(PROJ_OBJ_DIR)/ReclsFtpSearchDirectoryNode_windows.obj
OBJ_CR_FtpSrch_windows_ST_R	= $(PROJ_OBJ_DIR)/ReclsFtpSearch_windows.obj



OBJ_CORE_ST_R=\
 $(OBJ_CR_api_entryinfo_ST_R)\
 $(OBJ_CR_api_error_ST_R)\
 $(OBJ_CR_api_extended_ST_R)\
 $(OBJ_CR_api_combpath_ST_R)\
 $(OBJ_CR_api_derrpath_ST_R)\
 $(OBJ_CR_api_getflsizs_ST_R)\
 $(OBJ_CR_api_sqzpath_ST_R)\
 $(OBJ_CR_api_stat_ST_R)\
 $(OBJ_CR_api_crdir_ST_R)\
 $(OBJ_CR_api_rmdir_ST_R)\
 $(OBJ_CR_api_rc_win_ST_R)\
 $(OBJ_CR_api_search_ST_R)\
 $(OBJ_CR_impl_debug_ST_R)\
 $(OBJ_CR_impl_entryinfo_ST_R)\
 $(OBJ_CR_impl_fileinfo_ST_R)\
 $(OBJ_CR_impl_snprintf_ST_R)\
 $(OBJ_CR_impl_util_ST_R)\
 $(OBJ_CR_Srch_ST_R)\
 $(OBJ_CR_FlSrch_ST_R)\
 $(OBJ_CR_FlSchDirNode_ST_R)\
 $(OBJ_CR_api_win32_ST_R)\
 $(OBJ_CR_impl_fileinfo_win32_ST_R)\
 $(OBJ_CR_impl_util_win32_ST_R)\
 $(OBJ_CR_api_ftp_windows_ST_R)\
 $(OBJ_CR_FtpSchDirNode_win_ST_R)\
 $(OBJ_CR_FtpSrch_windows_ST_R)\
 \


# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)/shwild.recls.api.mt.debug.obj
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)/shwild.recls.matches.mt.debug.obj
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)/shwild.recls.pattern.mt.debug.obj

OBJ_SHWILD_MT_D=\
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)/shwild.recls.api.mt.obj
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)/shwild.recls.matches.mt.obj
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)/shwild.recls.pattern.mt.obj

OBJ_SHWILD_MT_R=\
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \

OBJ_shw_api_ST_D            = $(PROJ_OBJ_DIR)/shwild.recls.api.debug.obj
OBJ_shw_matches_ST_D        = $(PROJ_OBJ_DIR)/shwild.recls.matches.debug.obj
OBJ_shw_pattern_ST_D        = $(PROJ_OBJ_DIR)/shwild.recls.pattern.debug.obj

OBJ_SHWILD_ST_D=\
 $(OBJ_shw_api_ST_D)\
 $(OBJ_shw_matches_ST_D)\
 $(OBJ_shw_pattern_ST_D)\
 \

OBJ_shw_api_ST_R            = $(PROJ_OBJ_DIR)/shwild.recls.api.obj
OBJ_shw_matches_ST_R        = $(PROJ_OBJ_DIR)/shwild.recls.matches.obj
OBJ_shw_pattern_ST_R        = $(PROJ_OBJ_DIR)/shwild.recls.pattern.obj

OBJ_SHWILD_ST_R=\
 $(OBJ_shw_api_ST_R)\
 $(OBJ_shw_matches_ST_R)\
 $(OBJ_shw_pattern_ST_R)\
 \


# xtests

OBJ_xts_core_MT_D           = $(PROJ_OBJ_DIR)/xtests.recls.core.api.mt.debug.obj

OBJ_XTESTS_MT_D=\
 $(OBJ_xts_core_MT_D)\
 \

OBJ_xts_core_MT_R           = $(PROJ_OBJ_DIR)/xtests.recls.core.api.mt.obj

OBJ_XTESTS_MT_R=\
 $(OBJ_xts_core_MT_R)\
 \

OBJ_xts_core_ST_D           = $(PROJ_OBJ_DIR)/xtests.recls.core.api.debug.obj

OBJ_XTESTS_ST_D=\
 $(OBJ_xts_core_ST_D)\
 \

OBJ_xts_core_ST_R           = $(PROJ_OBJ_DIR)/xtests.recls.core.api.obj

OBJ_XTESTS_ST_R=\
 $(OBJ_xts_core_ST_R)\
 \


########################################
# examples

OBJ_EX_ex_c_1_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_1.mt.debug.obj
OBJ_EX_ex_c_2_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_2.mt.debug.obj
OBJ_EX_ex_c_3_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_3.mt.debug.obj
OBJ_EX_ex_c_4_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_4.mt.debug.obj
OBJ_EX_ex_c_5_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_5.mt.debug.obj
OBJ_EX_ex_c_6_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_6.mt.debug.obj
OBJ_EX_ex_c_7_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_7.mt.debug.obj
OBJ_EX_ex_c_8_MT_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_8.mt.debug.obj
OBJ_EX_ex_c_1_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_1.mt.obj
OBJ_EX_ex_c_2_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_2.mt.obj
OBJ_EX_ex_c_3_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_3.mt.obj
OBJ_EX_ex_c_4_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_4.mt.obj
OBJ_EX_ex_c_5_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_5.mt.obj
OBJ_EX_ex_c_6_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_6.mt.obj
OBJ_EX_ex_c_7_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_7.mt.obj
OBJ_EX_ex_c_8_MT_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_8.mt.obj
OBJ_EX_ex_c_1_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_1.debug.obj
OBJ_EX_ex_c_2_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_2.debug.obj
OBJ_EX_ex_c_3_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_3.debug.obj
OBJ_EX_ex_c_4_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_4.debug.obj
OBJ_EX_ex_c_5_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_5.debug.obj
OBJ_EX_ex_c_6_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_6.debug.obj
OBJ_EX_ex_c_7_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_7.debug.obj
OBJ_EX_ex_c_8_ST_D =   $(PROJ_OBJ_DIR)/ex.c.example_c_8.debug.obj
OBJ_EX_ex_c_1_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_1.obj
OBJ_EX_ex_c_2_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_2.obj
OBJ_EX_ex_c_3_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_3.obj
OBJ_EX_ex_c_4_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_4.obj
OBJ_EX_ex_c_5_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_5.obj
OBJ_EX_ex_c_6_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_6.obj
OBJ_EX_ex_c_7_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_7.obj
OBJ_EX_ex_c_8_ST_R =   $(PROJ_OBJ_DIR)/ex.c.example_c_8.obj

OBJ_EX_ex_cpp_1_MT_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_1.mt.debug.obj
OBJ_EX_ex_cpp_2_MT_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_2.mt.debug.obj
OBJ_EX_ex_cpp_3_MT_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_3.mt.debug.obj
OBJ_EX_ex_cpp_1_MT_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_1.mt.obj
OBJ_EX_ex_cpp_2_MT_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_2.mt.obj
OBJ_EX_ex_cpp_3_MT_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_3.mt.obj
OBJ_EX_ex_cpp_1_ST_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_1.debug.obj
OBJ_EX_ex_cpp_2_ST_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_2.debug.obj
OBJ_EX_ex_cpp_3_ST_D =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_3.debug.obj
OBJ_EX_ex_cpp_1_ST_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_1.obj
OBJ_EX_ex_cpp_2_ST_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_2.obj
OBJ_EX_ex_cpp_3_ST_R =   $(PROJ_OBJ_DIR)/ex.cpp.example_cpp_3.obj

########################################
# tests

##############################
# component tests

OBJ_TEST_COMP_api_crdir_MT_D =   $(PROJ_OBJ_DIR)/test.component.util.cpp.create_directory.mt.debug.obj
OBJ_TEST_COMP_api_rmdir_MT_D =   $(PROJ_OBJ_DIR)/test.component.util.cpp.remove_directory.mt.debug.obj
OBJ_TEST_COMP_api_crdir_MT_R =   $(PROJ_OBJ_DIR)/test.component.util.cpp.create_directory.mt.obj
OBJ_TEST_COMP_api_rmdir_MT_R =   $(PROJ_OBJ_DIR)/test.component.util.cpp.remove_directory.mt.obj
OBJ_TEST_COMP_api_crdir_ST_D =   $(PROJ_OBJ_DIR)/test.component.util.cpp.create_directory.debug.obj
OBJ_TEST_COMP_api_rmdir_ST_D =   $(PROJ_OBJ_DIR)/test.component.util.cpp.remove_directory.debug.obj
OBJ_TEST_COMP_api_crdir_ST_R =   $(PROJ_OBJ_DIR)/test.component.util.cpp.create_directory.obj
OBJ_TEST_COMP_api_rmdir_ST_R =   $(PROJ_OBJ_DIR)/test.component.util.cpp.remove_directory.obj

##############################
# scratch tests

OBJ_TEST_SCRT_srch1_MT_D   =   $(PROJ_OBJ_DIR)/test.scratch.search.1.mt.debug.obj
OBJ_TEST_SCRT_srch2_MT_D   =   $(PROJ_OBJ_DIR)/test.scratch.search.2.mt.debug.obj
OBJ_TEST_SCRT_srch1_MT_R   =   $(PROJ_OBJ_DIR)/test.scratch.search.1.mt.obj
OBJ_TEST_SCRT_srch2_MT_R   =   $(PROJ_OBJ_DIR)/test.scratch.search.2.mt.obj
OBJ_TEST_SCRT_srch1_ST_D   =   $(PROJ_OBJ_DIR)/test.scratch.search.1.debug.obj
OBJ_TEST_SCRT_srch2_ST_D   =   $(PROJ_OBJ_DIR)/test.scratch.search.2.debug.obj
OBJ_TEST_SCRT_srch1_ST_R   =   $(PROJ_OBJ_DIR)/test.scratch.search.1.obj
OBJ_TEST_SCRT_srch2_ST_R   =   $(PROJ_OBJ_DIR)/test.scratch.search.2.obj

##############################
# unit tests

OBJ_TEST_UNIT_api_cmbpaths_MT_D	=   $(PROJ_OBJ_DIR)/test.unit.api.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_api_drvrel_MT_D		=   $(PROJ_OBJ_DIR)/test.unit.api.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_api_sqzpath_MT_D	=   $(PROJ_OBJ_DIR)/test.unit.api.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_D		=   $(PROJ_OBJ_DIR)/test.unit.cpp.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.retcodes.mt.debug.obj
OBJ_TEST_UNIT_c_retcodes_MT_D		=   $(PROJ_OBJ_DIR)/test.unit.c.retcodes.mt.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_MT_R	=   $(PROJ_OBJ_DIR)/test.unit.api.combine_paths.mt.obj
OBJ_TEST_UNIT_api_drvrel_MT_R		=   $(PROJ_OBJ_DIR)/test.unit.api.derive_relative_path.mt.obj
OBJ_TEST_UNIT_api_sqzpath_MT_R	=   $(PROJ_OBJ_DIR)/test.unit.api.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.combine_paths.mt.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_R		=   $(PROJ_OBJ_DIR)/test.unit.cpp.derive_relative_path.mt.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.retcodes.mt.obj
OBJ_TEST_UNIT_c_retcodes_MT_R		=   $(PROJ_OBJ_DIR)/test.unit.c.retcodes.mt.obj
OBJ_TEST_UNIT_api_cmbpaths_ST_D	=   $(PROJ_OBJ_DIR)/test.unit.api.combine_paths.debug.obj
OBJ_TEST_UNIT_api_drvrel_ST_D		=   $(PROJ_OBJ_DIR)/test.unit.api.derive_relative_path.debug.obj
OBJ_TEST_UNIT_api_sqzpath_ST_D	=   $(PROJ_OBJ_DIR)/test.unit.api.squeeze_path.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_ST_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.combine_paths.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_ST_D		=   $(PROJ_OBJ_DIR)/test.unit.cpp.derive_relative_path.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_ST_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.squeeze_path.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_ST_D	=   $(PROJ_OBJ_DIR)/test.unit.cpp.retcodes.debug.obj
OBJ_TEST_UNIT_c_retcodes_ST_D		=   $(PROJ_OBJ_DIR)/test.unit.c.retcodes.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_ST_R	=   $(PROJ_OBJ_DIR)/test.unit.api.combine_paths.obj
OBJ_TEST_UNIT_api_drvrel_ST_R		=   $(PROJ_OBJ_DIR)/test.unit.api.derive_relative_path.obj
OBJ_TEST_UNIT_api_sqzpath_ST_R	=   $(PROJ_OBJ_DIR)/test.unit.api.squeeze_path.obj
OBJ_TEST_UNIT_cpp_cmbpaths_ST_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.combine_paths.obj
OBJ_TEST_UNIT_cpp_drvrel_ST_R		=   $(PROJ_OBJ_DIR)/test.unit.cpp.derive_relative_path.obj
OBJ_TEST_UNIT_cpp_sqzpath_ST_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.squeeze_path.obj
OBJ_TEST_UNIT_cpp_retcodes_ST_R	=   $(PROJ_OBJ_DIR)/test.unit.cpp.retcodes.obj
OBJ_TEST_UNIT_c_retcodes_ST_R		=   $(PROJ_OBJ_DIR)/test.unit.c.retcodes.obj

##################################################
# target groups

########################################
# objects

# recls
OBJS_CORE=\
 $(OBJ_CORE_MT_D)\
 $(OBJ_CORE_MT_R)\
 $(OBJ_CORE_ST_D)\
 $(OBJ_CORE_ST_R)\
 \

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_MT_R)\
 $(OBJ_SHWILD_ST_D)\
 $(OBJ_SHWILD_ST_R)\
 \

# xtests
OBJS_XTESTS=\
 $(OBJ_XTESTS_MT_D)\
 $(OBJ_XTESTS_MT_R)\
 $(OBJ_XTESTS_ST_D)\
 $(OBJ_XTESTS_ST_R)\
 \

# Examples 
OBJS_EXAMPLE=\
 $(OBJ_EX_ex_c_1_MT_D)\
 $(OBJ_EX_ex_c_2_MT_D)\
 $(OBJ_EX_ex_c_3_MT_D)\
 $(OBJ_EX_ex_c_4_MT_D)\
 $(OBJ_EX_ex_c_5_MT_D)\
 $(OBJ_EX_ex_c_6_MT_D)\
 $(OBJ_EX_ex_c_7_MT_D)\
 $(OBJ_EX_ex_c_8_MT_D)\
 $(OBJ_EX_ex_cpp_1_MT_D)\
 $(OBJ_EX_ex_cpp_2_MT_D)\
 $(OBJ_EX_ex_cpp_3_MT_D)\
 $(OBJ_EX_ex_c_1_MT_R)\
 $(OBJ_EX_ex_c_2_MT_R)\
 $(OBJ_EX_ex_c_3_MT_R)\
 $(OBJ_EX_ex_c_4_MT_R)\
 $(OBJ_EX_ex_c_5_MT_R)\
 $(OBJ_EX_ex_c_6_MT_R)\
 $(OBJ_EX_ex_c_7_MT_R)\
 $(OBJ_EX_ex_c_8_MT_R)\
 $(OBJ_EX_ex_cpp_1_MT_R)\
 $(OBJ_EX_ex_cpp_2_MT_R)\
 $(OBJ_EX_ex_cpp_3_MT_R)\
 $(OBJ_EX_ex_c_1_ST_D)\
 $(OBJ_EX_ex_c_2_ST_D)\
 $(OBJ_EX_ex_c_3_ST_D)\
 $(OBJ_EX_ex_c_4_ST_D)\
 $(OBJ_EX_ex_c_5_ST_D)\
 $(OBJ_EX_ex_c_6_ST_D)\
 $(OBJ_EX_ex_c_7_ST_D)\
 $(OBJ_EX_ex_c_8_ST_D)\
 $(OBJ_EX_ex_cpp_1_ST_D)\
 $(OBJ_EX_ex_cpp_2_ST_D)\
 $(OBJ_EX_ex_cpp_3_ST_D)\
 $(OBJ_EX_ex_c_1_ST_R)\
 $(OBJ_EX_ex_c_2_ST_R)\
 $(OBJ_EX_ex_c_3_ST_R)\
 $(OBJ_EX_ex_c_4_ST_R)\
 $(OBJ_EX_ex_c_5_ST_R)\
 $(OBJ_EX_ex_c_6_ST_R)\
 $(OBJ_EX_ex_c_7_ST_R)\
 $(OBJ_EX_ex_c_8_ST_R)\
 $(OBJ_EX_ex_cpp_1_ST_R)\
 $(OBJ_EX_ex_cpp_2_ST_R)\
 $(OBJ_EX_ex_cpp_3_ST_R)\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_api_crdir_MT_D)\
 $(OBJ_TEST_COMP_api_rmdir_MT_D)\
 $(OBJ_TEST_COMP_api_crdir_MT_R)\
 $(OBJ_TEST_COMP_api_rmdir_MT_R)\
 $(OBJ_TEST_COMP_api_crdir_ST_D)\
 $(OBJ_TEST_COMP_api_rmdir_ST_D)\
 $(OBJ_TEST_COMP_api_crdir_ST_R)\
 $(OBJ_TEST_COMP_api_rmdir_ST_R)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_srch1_MT_D)\
 $(OBJ_TEST_SCRT_srch1_MT_R)\
 $(OBJ_TEST_SCRT_srch1_ST_D)\
 $(OBJ_TEST_SCRT_srch1_ST_R)\
 \

# TODO: Add this project
# $(OBJ_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) \


# Unit Tests
OBJS_TEST_UNIT=\
 $(OBJ_TEST_UNIT_api_cmbpaths_MT_D)\
 $(OBJ_TEST_UNIT_api_sqzpath_MT_D)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)\
 $(OBJ_TEST_UNIT_cpp_drvrel_MT_D)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)\
 $(OBJ_TEST_UNIT_cpp_retcodes_MT_D)\
 $(OBJ_TEST_UNIT_c_retcodes_MT_D)\
 $(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
 $(OBJ_TEST_UNIT_c_retcodes_MT_R)\
 $(OBJ_TEST_UNIT_api_cmbpaths_ST_D)\
 $(OBJ_TEST_UNIT_api_sqzpath_ST_D)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D)\
 $(OBJ_TEST_UNIT_cpp_drvrel_ST_D)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_ST_D)\
 $(OBJ_TEST_UNIT_cpp_retcodes_ST_D)\
 $(OBJ_TEST_UNIT_c_retcodes_ST_D)\
 $(OBJ_TEST_UNIT_api_cmbpaths_ST_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_ST_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_ST_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_ST_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_ST_R)\
 $(OBJ_TEST_UNIT_c_retcodes_ST_R)\
 \

# TODO: Add this project
# $(OBJ_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ] ) \

########################################
# libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_MT_R)\
 $(LIB_CORE_ST_D)\
 $(LIB_CORE_ST_R)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_MT_R)\
 $(LIB_SHWILD_ST_D)\
 $(LIB_SHWILD_ST_R)\
 \

TARGETS_LIB_XTESTS=\
 $(LIB_XTESTS_MT_D)\
 $(LIB_XTESTS_MT_R)\
 $(LIB_XTESTS_ST_D)\
 $(LIB_XTESTS_ST_R)\
 \

########################################
# programs

TARGETS_EXAMPLE_C=\
 $(TARG_EX_ex_c_1_MT_D)\
 $(TARG_EX_ex_c_2_MT_D)\
 $(TARG_EX_ex_c_3_MT_D)\
 $(TARG_EX_ex_c_4_MT_D)\
 $(TARG_EX_ex_c_5_MT_D)\
 $(TARG_EX_ex_c_6_MT_D)\
 $(TARG_EX_ex_c_7_MT_D)\
 $(TARG_EX_ex_c_8_MT_D)\
 $(TARG_EX_ex_c_1_MT_R)\
 $(TARG_EX_ex_c_2_MT_R)\
 $(TARG_EX_ex_c_3_MT_R)\
 $(TARG_EX_ex_c_4_MT_R)\
 $(TARG_EX_ex_c_5_MT_R)\
 $(TARG_EX_ex_c_6_MT_R)\
 $(TARG_EX_ex_c_7_MT_R)\
 $(TARG_EX_ex_c_8_MT_R)\
 $(TARG_EX_ex_c_1_ST_D)\
 $(TARG_EX_ex_c_2_ST_D)\
 $(TARG_EX_ex_c_3_ST_D)\
 $(TARG_EX_ex_c_4_ST_D)\
 $(TARG_EX_ex_c_5_ST_D)\
 $(TARG_EX_ex_c_6_ST_D)\
 $(TARG_EX_ex_c_7_ST_D)\
 $(TARG_EX_ex_c_8_ST_D)\
 $(TARG_EX_ex_c_1_ST_R)\
 $(TARG_EX_ex_c_2_ST_R)\
 $(TARG_EX_ex_c_3_ST_R)\
 $(TARG_EX_ex_c_4_ST_R)\
 $(TARG_EX_ex_c_5_ST_R)\
 $(TARG_EX_ex_c_6_ST_R)\
 $(TARG_EX_ex_c_7_ST_R)\
 $(TARG_EX_ex_c_8_ST_R)\
 \

TARGETS_EXAMPLE_CPP=\
 $(TARG_EX_ex_cpp_1_MT_D)\
 $(TARG_EX_ex_cpp_2_MT_D)\
 $(TARG_EX_ex_cpp_3_MT_D)\
 $(TARG_EX_ex_cpp_1_MT_R)\
 $(TARG_EX_ex_cpp_2_MT_R)\
 $(TARG_EX_ex_cpp_3_MT_R)\
 $(TARG_EX_ex_cpp_1_ST_D)\
 $(TARG_EX_ex_cpp_2_ST_D)\
 $(TARG_EX_ex_cpp_3_ST_D)\
 $(TARG_EX_ex_cpp_1_ST_R)\
 $(TARG_EX_ex_cpp_2_ST_R)\
 $(TARG_EX_ex_cpp_3_ST_R)\
 \

TARGETS_EXAMPLE=\
 $(TARGETS_EXAMPLE_C)\
 $(TARGETS_EXAMPLE_CPP)\
 \

TARGETS_SAMPLE=\
 \

TARGETS_TEST_COMPONENT=\
 $(TARG_TEST_COMP_api_crdir_MT_D)\
 $(TARG_TEST_COMP_api_rmdir_MT_D)\
 $(TARG_TEST_COMP_api_crdir_MT_R)\
 $(TARG_TEST_COMP_api_rmdir_MT_R)\
 $(TARG_TEST_COMP_api_crdir_ST_D)\
 $(TARG_TEST_COMP_api_rmdir_ST_D)\
 $(TARG_TEST_COMP_api_crdir_ST_R)\
 $(TARG_TEST_COMP_api_rmdir_ST_R)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_srch1_MT_D)\
 $(TARG_TEST_SCRT_srch1_MT_R)\
 $(TARG_TEST_SCRT_srch1_ST_D)\
 $(TARG_TEST_SCRT_srch1_ST_R)\
 \

# TODO: Add this project
# $(TARG_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) \


TARGETS_TEST_UNIT=\
 $(TARG_TEST_UNIT_api_cmbpaths_MT_D)\
 $(TARG_TEST_UNIT_api_sqzpath_MT_D)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_MT_D)\
 $(TARG_TEST_UNIT_cpp_drvrel_MT_D)\
 $(TARG_TEST_UNIT_cpp_sqzpath_MT_D)\
 $(TARG_TEST_UNIT_cpp_retcodes_MT_D)\
 $(TARG_TEST_UNIT_c_retcodes_MT_D)\
 $(TARG_TEST_UNIT_api_cmbpaths_MT_R)\
 $(TARG_TEST_UNIT_api_sqzpath_MT_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_MT_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_MT_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_MT_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_MT_R)\
 $(TARG_TEST_UNIT_c_retcodes_MT_R)\
 $(TARG_TEST_UNIT_api_cmbpaths_ST_D)\
 $(TARG_TEST_UNIT_api_sqzpath_ST_D)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_ST_D)\
 $(TARG_TEST_UNIT_cpp_drvrel_ST_D)\
 $(TARG_TEST_UNIT_cpp_sqzpath_ST_D)\
 $(TARG_TEST_UNIT_cpp_retcodes_ST_D)\
 $(TARG_TEST_UNIT_c_retcodes_ST_D)\
 $(TARG_TEST_UNIT_api_cmbpaths_ST_R)\
 $(TARG_TEST_UNIT_api_sqzpath_ST_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_ST_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_ST_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_ST_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_ST_R)\
 $(TARG_TEST_UNIT_c_retcodes_ST_R)\
 \

# TODO: Add this project
# $(TARG_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ])\

############################################################################
# external targets (invokable by make)

# primary

_default:                   build

usage:
	@echo "make [usage | compile | build | test | clean] - default is 'build'"

# infrastructure

check.lib.dir:              $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)

check.bin.dir:              $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_BIN_DIR)


# compile targets

compile.libs.core:          $(PROJ_MAKEFILE_NAME)   $(OBJS_CORE)

compile.libs.shwild:        $(PROJ_MAKEFILE_NAME)   $(OBJS_SHWILD)

compile.libs.xtests:        $(PROJ_MAKEFILE_NAME)   $(OBJS_XTESTS)

compile.libs:                                       compile.libs.core compile.libs.shwild compile.libs.xtests

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

build.libs.xtests:          check.lib.dir           $(TARGETS_LIB_XTESTS)

build.libs:                                         build.libs.core build.libs.shwild build.libs.xtests

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
	$(TARG_TEST_COMP_api_crdir_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_ST_R) --verbosity=$(TEST_VERBOSITY)

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_srch1_MT_D)
	$(TARG_TEST_SCRT_srch1_MT_R)
	$(TARG_TEST_SCRT_srch1_ST_D)
	$(TARG_TEST_SCRT_srch1_ST_R)


# TODO: Add this project
#	$(TARG_TEST_SCRT_srch1 [ ` [ MakeSymbolTag ] ` ] ) 

test.unit_:
	@echo Running Test:Unit programs ...
	$(TARG_TEST_UNIT_api_cmbpaths_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_ST_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_ST_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_ST_R) --verbosity=$(TEST_VERBOSITY)

# TODO: Add this project
#	$(TARG_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ] ) --verbosity=$(TEST_VERBOSITY)


test.ex.c_:
	@echo C Example programs ...
	-$(TARG_EX_ex_c_1_MT_D)
	-$(TARG_EX_ex_c_2_MT_D)
	-$(TARG_EX_ex_c_3_MT_D)
	-$(TARG_EX_ex_c_4_MT_D)
	-$(TARG_EX_ex_c_5_MT_D)
	-$(TARG_EX_ex_c_6_MT_D)
	-$(TARG_EX_ex_c_7_MT_D)
	-$(TARG_EX_ex_c_8_MT_D)
	-$(TARG_EX_ex_c_1_MT_R)
	-$(TARG_EX_ex_c_2_MT_R)
	-$(TARG_EX_ex_c_3_MT_R)
	-$(TARG_EX_ex_c_4_MT_R)
	-$(TARG_EX_ex_c_5_MT_R)
	-$(TARG_EX_ex_c_6_MT_R)
	-$(TARG_EX_ex_c_7_MT_R)
	-$(TARG_EX_ex_c_8_MT_R)
	-$(TARG_EX_ex_c_1_ST_D)
	-$(TARG_EX_ex_c_2_ST_D)
	-$(TARG_EX_ex_c_3_ST_D)
	-$(TARG_EX_ex_c_4_ST_D)
	-$(TARG_EX_ex_c_5_ST_D)
	-$(TARG_EX_ex_c_6_ST_D)
	-$(TARG_EX_ex_c_7_ST_D)
	-$(TARG_EX_ex_c_8_ST_D)
	-$(TARG_EX_ex_c_1_ST_R)
	-$(TARG_EX_ex_c_2_ST_R)
	-$(TARG_EX_ex_c_3_ST_R)
	-$(TARG_EX_ex_c_4_ST_R)
	-$(TARG_EX_ex_c_5_ST_R)
	-$(TARG_EX_ex_c_6_ST_R)
	-$(TARG_EX_ex_c_7_ST_R)
	-$(TARG_EX_ex_c_8_ST_R)

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
	@-if exist $(LIB_CORE_MT_D) $(RM) $(LIB_CORE_MT_D)
	@-if exist $(LIB_CORE_MT_R) $(RM) $(LIB_CORE_MT_R)
	@-if exist $(LIB_CORE_ST_D) $(RM) $(LIB_CORE_ST_D)
	@-if exist $(LIB_CORE_ST_R) $(RM) $(LIB_CORE_ST_R)
	@-if exist $(OBJ_CR_api_entryinfo_MT_D) $(RM) $(OBJ_CR_api_entryinfo_MT_D)
	@-if exist $(OBJ_CR_api_error_MT_D) $(RM) $(OBJ_CR_api_error_MT_D)
	@-if exist $(OBJ_CR_api_extended_MT_D) $(RM) $(OBJ_CR_api_extended_MT_D)
	@-if exist $(OBJ_CR_api_combpath_MT_D) $(RM) $(OBJ_CR_api_combpath_MT_D)
	@-if exist $(OBJ_CR_api_derrpath_MT_D) $(RM) $(OBJ_CR_api_derrpath_MT_D)
	@-if exist $(OBJ_CR_api_getflsizs_MT_D) $(RM) $(OBJ_CR_api_getflsizs_MT_D)
	@-if exist $(OBJ_CR_api_sqzpath_MT_D) $(RM) $(OBJ_CR_api_sqzpath_MT_D)
	@-if exist $(OBJ_CR_api_stat_MT_D) $(RM) $(OBJ_CR_api_stat_MT_D)
	@-if exist $(OBJ_CR_api_crdir_MT_D) $(RM) $(OBJ_CR_api_crdir_MT_D)
	@-if exist $(OBJ_CR_api_rmdir_MT_D) $(RM) $(OBJ_CR_api_rmdir_MT_D)
	@-if exist $(OBJ_CR_api_rc_win_MT_D) $(RM) $(OBJ_CR_api_rc_win_MT_D)
	@-if exist $(OBJ_CR_api_search_MT_D) $(RM) $(OBJ_CR_api_search_MT_D)
	@-if exist $(OBJ_CR_impl_debug_MT_D) $(RM) $(OBJ_CR_impl_debug_MT_D)
	@-if exist $(OBJ_CR_impl_entryinfo_MT_D) $(RM) $(OBJ_CR_impl_entryinfo_MT_D)
	@-if exist $(OBJ_CR_impl_fileinfo_MT_D) $(RM) $(OBJ_CR_impl_fileinfo_MT_D)
	@-if exist $(OBJ_CR_impl_snprintf_MT_D) $(RM) $(OBJ_CR_impl_snprintf_MT_D)
	@-if exist $(OBJ_CR_impl_util_MT_D) $(RM) $(OBJ_CR_impl_util_MT_D)
	@-if exist $(OBJ_CR_Srch_MT_D) $(RM) $(OBJ_CR_Srch_MT_D)
	@-if exist $(OBJ_CR_FlSrch_MT_D) $(RM) $(OBJ_CR_FlSrch_MT_D)
	@-if exist $(OBJ_CR_FlSchDirNode_MT_D) $(RM) $(OBJ_CR_FlSchDirNode_MT_D)
	@-if exist $(OBJ_CR_api_win32_MT_D) $(RM) $(OBJ_CR_api_win32_MT_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win32_MT_D) $(RM) $(OBJ_CR_impl_fileinfo_win32_MT_D)
	@-if exist $(OBJ_CR_impl_util_win32_MT_D) $(RM) $(OBJ_CR_impl_util_win32_MT_D)
	@-if exist $(OBJ_CR_api_ftp_windows_MT_D) $(RM) $(OBJ_CR_api_ftp_windows_MT_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_MT_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_MT_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_MT_D) $(RM) $(OBJ_CR_FtpSrch_windows_MT_D)
	@-if exist $(OBJ_CR_api_entryinfo_MT_R) $(RM) $(OBJ_CR_api_entryinfo_MT_R)
	@-if exist $(OBJ_CR_api_error_MT_R) $(RM) $(OBJ_CR_api_error_MT_R)
	@-if exist $(OBJ_CR_api_extended_MT_R) $(RM) $(OBJ_CR_api_extended_MT_R)
	@-if exist $(OBJ_CR_api_combpath_MT_R) $(RM) $(OBJ_CR_api_combpath_MT_R)
	@-if exist $(OBJ_CR_api_derrpath_MT_R) $(RM) $(OBJ_CR_api_derrpath_MT_R)
	@-if exist $(OBJ_CR_api_getflsizs_MT_R) $(RM) $(OBJ_CR_api_getflsizs_MT_R)
	@-if exist $(OBJ_CR_api_sqzpath_MT_R) $(RM) $(OBJ_CR_api_sqzpath_MT_R)
	@-if exist $(OBJ_CR_api_stat_MT_R) $(RM) $(OBJ_CR_api_stat_MT_R)
	@-if exist $(OBJ_CR_api_crdir_MT_R) $(RM) $(OBJ_CR_api_crdir_MT_R)
	@-if exist $(OBJ_CR_api_rmdir_MT_R) $(RM) $(OBJ_CR_api_rmdir_MT_R)
	@-if exist $(OBJ_CR_api_rc_win_MT_R) $(RM) $(OBJ_CR_api_rc_win_MT_R)
	@-if exist $(OBJ_CR_api_search_MT_R) $(RM) $(OBJ_CR_api_search_MT_R)
	@-if exist $(OBJ_CR_impl_debug_MT_R) $(RM) $(OBJ_CR_impl_debug_MT_R)
	@-if exist $(OBJ_CR_impl_entryinfo_MT_R) $(RM) $(OBJ_CR_impl_entryinfo_MT_R)
	@-if exist $(OBJ_CR_impl_fileinfo_MT_R) $(RM) $(OBJ_CR_impl_fileinfo_MT_R)
	@-if exist $(OBJ_CR_impl_snprintf_MT_R) $(RM) $(OBJ_CR_impl_snprintf_MT_R)
	@-if exist $(OBJ_CR_impl_util_MT_R) $(RM) $(OBJ_CR_impl_util_MT_R)
	@-if exist $(OBJ_CR_Srch_MT_R) $(RM) $(OBJ_CR_Srch_MT_R)
	@-if exist $(OBJ_CR_FlSrch_MT_R) $(RM) $(OBJ_CR_FlSrch_MT_R)
	@-if exist $(OBJ_CR_FlSchDirNode_MT_R) $(RM) $(OBJ_CR_FlSchDirNode_MT_R)
	@-if exist $(OBJ_CR_api_win32_MT_R) $(RM) $(OBJ_CR_api_win32_MT_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win32_MT_R) $(RM) $(OBJ_CR_impl_fileinfo_win32_MT_R)
	@-if exist $(OBJ_CR_impl_util_win32_MT_R) $(RM) $(OBJ_CR_impl_util_win32_MT_R)
	@-if exist $(OBJ_CR_api_ftp_windows_MT_R) $(RM) $(OBJ_CR_api_ftp_windows_MT_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_MT_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_MT_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_MT_R) $(RM) $(OBJ_CR_FtpSrch_windows_MT_R)
	@-if exist $(OBJ_CR_api_entryinfo_ST_D) $(RM) $(OBJ_CR_api_entryinfo_ST_D)
	@-if exist $(OBJ_CR_api_error_ST_D) $(RM) $(OBJ_CR_api_error_ST_D)
	@-if exist $(OBJ_CR_api_extended_ST_D) $(RM) $(OBJ_CR_api_extended_ST_D)
	@-if exist $(OBJ_CR_api_combpath_ST_D) $(RM) $(OBJ_CR_api_combpath_ST_D)
	@-if exist $(OBJ_CR_api_derrpath_ST_D) $(RM) $(OBJ_CR_api_derrpath_ST_D)
	@-if exist $(OBJ_CR_api_getflsizs_ST_D) $(RM) $(OBJ_CR_api_getflsizs_ST_D)
	@-if exist $(OBJ_CR_api_sqzpath_ST_D) $(RM) $(OBJ_CR_api_sqzpath_ST_D)
	@-if exist $(OBJ_CR_api_stat_ST_D) $(RM) $(OBJ_CR_api_stat_ST_D)
	@-if exist $(OBJ_CR_api_crdir_ST_D) $(RM) $(OBJ_CR_api_crdir_ST_D)
	@-if exist $(OBJ_CR_api_rmdir_ST_D) $(RM) $(OBJ_CR_api_rmdir_ST_D)
	@-if exist $(OBJ_CR_api_rc_win_ST_D) $(RM) $(OBJ_CR_api_rc_win_ST_D)
	@-if exist $(OBJ_CR_api_search_ST_D) $(RM) $(OBJ_CR_api_search_ST_D)
	@-if exist $(OBJ_CR_impl_debug_ST_D) $(RM) $(OBJ_CR_impl_debug_ST_D)
	@-if exist $(OBJ_CR_impl_entryinfo_ST_D) $(RM) $(OBJ_CR_impl_entryinfo_ST_D)
	@-if exist $(OBJ_CR_impl_fileinfo_ST_D) $(RM) $(OBJ_CR_impl_fileinfo_ST_D)
	@-if exist $(OBJ_CR_impl_snprintf_ST_D) $(RM) $(OBJ_CR_impl_snprintf_ST_D)
	@-if exist $(OBJ_CR_impl_util_ST_D) $(RM) $(OBJ_CR_impl_util_ST_D)
	@-if exist $(OBJ_CR_Srch_ST_D) $(RM) $(OBJ_CR_Srch_ST_D)
	@-if exist $(OBJ_CR_FlSrch_ST_D) $(RM) $(OBJ_CR_FlSrch_ST_D)
	@-if exist $(OBJ_CR_FlSchDirNode_ST_D) $(RM) $(OBJ_CR_FlSchDirNode_ST_D)
	@-if exist $(OBJ_CR_api_win32_ST_D) $(RM) $(OBJ_CR_api_win32_ST_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win32_ST_D) $(RM) $(OBJ_CR_impl_fileinfo_win32_ST_D)
	@-if exist $(OBJ_CR_impl_util_win32_ST_D) $(RM) $(OBJ_CR_impl_util_win32_ST_D)
	@-if exist $(OBJ_CR_api_ftp_windows_ST_D) $(RM) $(OBJ_CR_api_ftp_windows_ST_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_ST_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_ST_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_ST_D) $(RM) $(OBJ_CR_FtpSrch_windows_ST_D)
	@-if exist $(OBJ_CR_api_entryinfo_ST_R) $(RM) $(OBJ_CR_api_entryinfo_ST_R)
	@-if exist $(OBJ_CR_api_error_ST_R) $(RM) $(OBJ_CR_api_error_ST_R)
	@-if exist $(OBJ_CR_api_extended_ST_R) $(RM) $(OBJ_CR_api_extended_ST_R)
	@-if exist $(OBJ_CR_api_combpath_ST_R) $(RM) $(OBJ_CR_api_combpath_ST_R)
	@-if exist $(OBJ_CR_api_derrpath_ST_R) $(RM) $(OBJ_CR_api_derrpath_ST_R)
	@-if exist $(OBJ_CR_api_getflsizs_ST_R) $(RM) $(OBJ_CR_api_getflsizs_ST_R)
	@-if exist $(OBJ_CR_api_sqzpath_ST_R) $(RM) $(OBJ_CR_api_sqzpath_ST_R)
	@-if exist $(OBJ_CR_api_stat_ST_R) $(RM) $(OBJ_CR_api_stat_ST_R)
	@-if exist $(OBJ_CR_api_crdir_ST_R) $(RM) $(OBJ_CR_api_crdir_ST_R)
	@-if exist $(OBJ_CR_api_rmdir_ST_R) $(RM) $(OBJ_CR_api_rmdir_ST_R)
	@-if exist $(OBJ_CR_api_rc_win_ST_R) $(RM) $(OBJ_CR_api_rc_win_ST_R)
	@-if exist $(OBJ_CR_api_search_ST_R) $(RM) $(OBJ_CR_api_search_ST_R)
	@-if exist $(OBJ_CR_impl_debug_ST_R) $(RM) $(OBJ_CR_impl_debug_ST_R)
	@-if exist $(OBJ_CR_impl_entryinfo_ST_R) $(RM) $(OBJ_CR_impl_entryinfo_ST_R)
	@-if exist $(OBJ_CR_impl_fileinfo_ST_R) $(RM) $(OBJ_CR_impl_fileinfo_ST_R)
	@-if exist $(OBJ_CR_impl_snprintf_ST_R) $(RM) $(OBJ_CR_impl_snprintf_ST_R)
	@-if exist $(OBJ_CR_impl_util_ST_R) $(RM) $(OBJ_CR_impl_util_ST_R)
	@-if exist $(OBJ_CR_Srch_ST_R) $(RM) $(OBJ_CR_Srch_ST_R)
	@-if exist $(OBJ_CR_FlSrch_ST_R) $(RM) $(OBJ_CR_FlSrch_ST_R)
	@-if exist $(OBJ_CR_FlSchDirNode_ST_R) $(RM) $(OBJ_CR_FlSchDirNode_ST_R)
	@-if exist $(OBJ_CR_api_win32_ST_R) $(RM) $(OBJ_CR_api_win32_ST_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win32_ST_R) $(RM) $(OBJ_CR_impl_fileinfo_win32_ST_R)
	@-if exist $(OBJ_CR_impl_util_win32_ST_R) $(RM) $(OBJ_CR_impl_util_win32_ST_R)
	@-if exist $(OBJ_CR_api_ftp_windows_ST_R) $(RM) $(OBJ_CR_api_ftp_windows_ST_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_ST_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_ST_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_ST_R) $(RM) $(OBJ_CR_FtpSrch_windows_ST_R)

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-if exist shwild.*.obj $(RM) shwild.*.obj
	@-if exist $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_TAG)*.lib $(RM) $(PROJ_LIB_DIR)/$(SHWILD_TAG_VER).recls.$(COMP_TAG)*.lib

clean.libs.xtests:
	@echo Cleaning xTests libraries ...
	@-if exist xtests.*.obj $(RM) xtests.*.obj
	@-if exist $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_TAG)*.lib $(RM) $(PROJ_LIB_DIR)/$(XTESTS_TAG_VER).recls.$(COMP_TAG)*.lib

clean.libs:                                         clean.libs.core clean.libs.shwild clean.libs.xtests

clean.examples:
	@echo cleaning Example programs ...
	@-if exist $(TARG_EX_ex_c_1_MT_D) $(RM) $(TARG_EX_ex_c_1_MT_D)
	@-if exist $(OBJ_EX_ex_c_1_MT_D) $(RM) $(OBJ_EX_ex_c_1_MT_D)
	@-if exist $(TARG_EX_ex_c_2_MT_D) $(RM) $(TARG_EX_ex_c_2_MT_D)
	@-if exist $(OBJ_EX_ex_c_2_MT_D) $(RM) $(OBJ_EX_ex_c_2_MT_D)
	@-if exist $(TARG_EX_ex_c_3_MT_D) $(RM) $(TARG_EX_ex_c_3_MT_D)
	@-if exist $(OBJ_EX_ex_c_3_MT_D) $(RM) $(OBJ_EX_ex_c_3_MT_D)
	@-if exist $(TARG_EX_ex_c_4_MT_D) $(RM) $(TARG_EX_ex_c_4_MT_D)
	@-if exist $(OBJ_EX_ex_c_4_MT_D) $(RM) $(OBJ_EX_ex_c_4_MT_D)
	@-if exist $(TARG_EX_ex_c_5_MT_D) $(RM) $(TARG_EX_ex_c_5_MT_D)
	@-if exist $(OBJ_EX_ex_c_5_MT_D) $(RM) $(OBJ_EX_ex_c_5_MT_D)
	@-if exist $(TARG_EX_ex_c_6_MT_D) $(RM) $(TARG_EX_ex_c_6_MT_D)
	@-if exist $(OBJ_EX_ex_c_6_MT_D) $(RM) $(OBJ_EX_ex_c_6_MT_D)
	@-if exist $(TARG_EX_ex_c_7_MT_D) $(RM) $(TARG_EX_ex_c_7_MT_D)
	@-if exist $(OBJ_EX_ex_c_7_MT_D) $(RM) $(OBJ_EX_ex_c_7_MT_D)
	@-if exist $(TARG_EX_ex_c_8_MT_D) $(RM) $(TARG_EX_ex_c_8_MT_D)
	@-if exist $(OBJ_EX_ex_c_8_MT_D) $(RM) $(OBJ_EX_ex_c_8_MT_D)
	@-if exist $(TARG_EX_ex_cpp_1_MT_D) $(RM) $(TARG_EX_ex_cpp_1_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_1_MT_D) $(RM) $(OBJ_EX_ex_cpp_1_MT_D)
	@-if exist $(TARG_EX_ex_cpp_2_MT_D) $(RM) $(TARG_EX_ex_cpp_2_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_2_MT_D) $(RM) $(OBJ_EX_ex_cpp_2_MT_D)
	@-if exist $(TARG_EX_ex_cpp_3_MT_D) $(RM) $(TARG_EX_ex_cpp_3_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_3_MT_D) $(RM) $(OBJ_EX_ex_cpp_3_MT_D)
	@-if exist $(TARG_EX_ex_c_1_MT_R) $(RM) $(TARG_EX_ex_c_1_MT_R)
	@-if exist $(OBJ_EX_ex_c_1_MT_R) $(RM) $(OBJ_EX_ex_c_1_MT_R)
	@-if exist $(TARG_EX_ex_c_2_MT_R) $(RM) $(TARG_EX_ex_c_2_MT_R)
	@-if exist $(OBJ_EX_ex_c_2_MT_R) $(RM) $(OBJ_EX_ex_c_2_MT_R)
	@-if exist $(TARG_EX_ex_c_3_MT_R) $(RM) $(TARG_EX_ex_c_3_MT_R)
	@-if exist $(OBJ_EX_ex_c_3_MT_R) $(RM) $(OBJ_EX_ex_c_3_MT_R)
	@-if exist $(TARG_EX_ex_c_4_MT_R) $(RM) $(TARG_EX_ex_c_4_MT_R)
	@-if exist $(OBJ_EX_ex_c_4_MT_R) $(RM) $(OBJ_EX_ex_c_4_MT_R)
	@-if exist $(TARG_EX_ex_c_5_MT_R) $(RM) $(TARG_EX_ex_c_5_MT_R)
	@-if exist $(OBJ_EX_ex_c_5_MT_R) $(RM) $(OBJ_EX_ex_c_5_MT_R)
	@-if exist $(TARG_EX_ex_c_6_MT_R) $(RM) $(TARG_EX_ex_c_6_MT_R)
	@-if exist $(OBJ_EX_ex_c_6_MT_R) $(RM) $(OBJ_EX_ex_c_6_MT_R)
	@-if exist $(TARG_EX_ex_c_7_MT_R) $(RM) $(TARG_EX_ex_c_7_MT_R)
	@-if exist $(OBJ_EX_ex_c_7_MT_R) $(RM) $(OBJ_EX_ex_c_7_MT_R)
	@-if exist $(TARG_EX_ex_c_8_MT_R) $(RM) $(TARG_EX_ex_c_8_MT_R)
	@-if exist $(OBJ_EX_ex_c_8_MT_R) $(RM) $(OBJ_EX_ex_c_8_MT_R)
	@-if exist $(TARG_EX_ex_cpp_1_MT_R) $(RM) $(TARG_EX_ex_cpp_1_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_1_MT_R) $(RM) $(OBJ_EX_ex_cpp_1_MT_R)
	@-if exist $(TARG_EX_ex_cpp_2_MT_R) $(RM) $(TARG_EX_ex_cpp_2_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_2_MT_R) $(RM) $(OBJ_EX_ex_cpp_2_MT_R)
	@-if exist $(TARG_EX_ex_cpp_3_MT_R) $(RM) $(TARG_EX_ex_cpp_3_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_3_MT_R) $(RM) $(OBJ_EX_ex_cpp_3_MT_R)
	@-if exist $(TARG_EX_ex_c_1_ST_D) $(RM) $(TARG_EX_ex_c_1_ST_D)
	@-if exist $(OBJ_EX_ex_c_1_ST_D) $(RM) $(OBJ_EX_ex_c_1_ST_D)
	@-if exist $(TARG_EX_ex_c_2_ST_D) $(RM) $(TARG_EX_ex_c_2_ST_D)
	@-if exist $(OBJ_EX_ex_c_2_ST_D) $(RM) $(OBJ_EX_ex_c_2_ST_D)
	@-if exist $(TARG_EX_ex_c_3_ST_D) $(RM) $(TARG_EX_ex_c_3_ST_D)
	@-if exist $(OBJ_EX_ex_c_3_ST_D) $(RM) $(OBJ_EX_ex_c_3_ST_D)
	@-if exist $(TARG_EX_ex_c_4_ST_D) $(RM) $(TARG_EX_ex_c_4_ST_D)
	@-if exist $(OBJ_EX_ex_c_4_ST_D) $(RM) $(OBJ_EX_ex_c_4_ST_D)
	@-if exist $(TARG_EX_ex_c_5_ST_D) $(RM) $(TARG_EX_ex_c_5_ST_D)
	@-if exist $(OBJ_EX_ex_c_5_ST_D) $(RM) $(OBJ_EX_ex_c_5_ST_D)
	@-if exist $(TARG_EX_ex_c_6_ST_D) $(RM) $(TARG_EX_ex_c_6_ST_D)
	@-if exist $(OBJ_EX_ex_c_6_ST_D) $(RM) $(OBJ_EX_ex_c_6_ST_D)
	@-if exist $(TARG_EX_ex_c_7_ST_D) $(RM) $(TARG_EX_ex_c_7_ST_D)
	@-if exist $(OBJ_EX_ex_c_7_ST_D) $(RM) $(OBJ_EX_ex_c_7_ST_D)
	@-if exist $(TARG_EX_ex_c_8_ST_D) $(RM) $(TARG_EX_ex_c_8_ST_D)
	@-if exist $(OBJ_EX_ex_c_8_ST_D) $(RM) $(OBJ_EX_ex_c_8_ST_D)
	@-if exist $(TARG_EX_ex_cpp_1_ST_D) $(RM) $(TARG_EX_ex_cpp_1_ST_D)
	@-if exist $(OBJ_EX_ex_cpp_1_ST_D) $(RM) $(OBJ_EX_ex_cpp_1_ST_D)
	@-if exist $(TARG_EX_ex_cpp_2_ST_D) $(RM) $(TARG_EX_ex_cpp_2_ST_D)
	@-if exist $(OBJ_EX_ex_cpp_2_ST_D) $(RM) $(OBJ_EX_ex_cpp_2_ST_D)
	@-if exist $(TARG_EX_ex_cpp_3_ST_D) $(RM) $(TARG_EX_ex_cpp_3_ST_D)
	@-if exist $(OBJ_EX_ex_cpp_3_ST_D) $(RM) $(OBJ_EX_ex_cpp_3_ST_D)
	@-if exist $(TARG_EX_ex_c_1_ST_R) $(RM) $(TARG_EX_ex_c_1_ST_R)
	@-if exist $(OBJ_EX_ex_c_1_ST_R) $(RM) $(OBJ_EX_ex_c_1_ST_R)
	@-if exist $(TARG_EX_ex_c_2_ST_R) $(RM) $(TARG_EX_ex_c_2_ST_R)
	@-if exist $(OBJ_EX_ex_c_2_ST_R) $(RM) $(OBJ_EX_ex_c_2_ST_R)
	@-if exist $(TARG_EX_ex_c_3_ST_R) $(RM) $(TARG_EX_ex_c_3_ST_R)
	@-if exist $(OBJ_EX_ex_c_3_ST_R) $(RM) $(OBJ_EX_ex_c_3_ST_R)
	@-if exist $(TARG_EX_ex_c_4_ST_R) $(RM) $(TARG_EX_ex_c_4_ST_R)
	@-if exist $(OBJ_EX_ex_c_4_ST_R) $(RM) $(OBJ_EX_ex_c_4_ST_R)
	@-if exist $(TARG_EX_ex_c_5_ST_R) $(RM) $(TARG_EX_ex_c_5_ST_R)
	@-if exist $(OBJ_EX_ex_c_5_ST_R) $(RM) $(OBJ_EX_ex_c_5_ST_R)
	@-if exist $(TARG_EX_ex_c_6_ST_R) $(RM) $(TARG_EX_ex_c_6_ST_R)
	@-if exist $(OBJ_EX_ex_c_6_ST_R) $(RM) $(OBJ_EX_ex_c_6_ST_R)
	@-if exist $(TARG_EX_ex_c_7_ST_R) $(RM) $(TARG_EX_ex_c_7_ST_R)
	@-if exist $(OBJ_EX_ex_c_7_ST_R) $(RM) $(OBJ_EX_ex_c_7_ST_R)
	@-if exist $(TARG_EX_ex_c_8_ST_R) $(RM) $(TARG_EX_ex_c_8_ST_R)
	@-if exist $(OBJ_EX_ex_c_8_ST_R) $(RM) $(OBJ_EX_ex_c_8_ST_R)
	@-if exist $(TARG_EX_ex_cpp_1_ST_R) $(RM) $(TARG_EX_ex_cpp_1_ST_R)
	@-if exist $(OBJ_EX_ex_cpp_1_ST_R) $(RM) $(OBJ_EX_ex_cpp_1_ST_R)
	@-if exist $(TARG_EX_ex_cpp_2_ST_R) $(RM) $(TARG_EX_ex_cpp_2_ST_R)
	@-if exist $(OBJ_EX_ex_cpp_2_ST_R) $(RM) $(OBJ_EX_ex_cpp_2_ST_R)
	@-if exist $(TARG_EX_ex_cpp_3_ST_R) $(RM) $(TARG_EX_ex_cpp_3_ST_R)
	@-if exist $(OBJ_EX_ex_cpp_3_ST_R) $(RM) $(OBJ_EX_ex_cpp_3_ST_R)

clean.samples:
	@echo cleaning Sample programs ...

clean.test.component:
	@echo Cleaning Test::Component files ...
	@-if exist $(TARG_TEST_COMP_api_crdir_MT_D) $(RM) $(TARG_TEST_COMP_api_crdir_MT_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_MT_D) $(RM) $(TARG_TEST_COMP_api_rmdir_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_MT_D) $(RM) $(OBJ_TEST_COMP_api_crdir_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_MT_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_MT_D)
	@-if exist $(TARG_TEST_COMP_api_crdir_MT_R) $(RM) $(TARG_TEST_COMP_api_crdir_MT_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_MT_R) $(RM) $(TARG_TEST_COMP_api_rmdir_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_MT_R) $(RM) $(OBJ_TEST_COMP_api_crdir_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_MT_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_MT_R)
	@-if exist $(TARG_TEST_COMP_api_crdir_ST_D) $(RM) $(TARG_TEST_COMP_api_crdir_ST_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_ST_D) $(RM) $(TARG_TEST_COMP_api_rmdir_ST_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_ST_D) $(RM) $(OBJ_TEST_COMP_api_crdir_ST_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_ST_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_ST_D)
	@-if exist $(TARG_TEST_COMP_api_crdir_ST_R) $(RM) $(TARG_TEST_COMP_api_crdir_ST_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_ST_R) $(RM) $(TARG_TEST_COMP_api_rmdir_ST_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_ST_R) $(RM) $(OBJ_TEST_COMP_api_crdir_ST_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_ST_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_ST_R)

clean.test.scratch:
	@-if exist $(TARG_TEST_SCRT_srch1_MT_D) $(RM) $(TARG_TEST_SCRT_srch1_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_MT_D) $(RM) $(OBJ_TEST_SCRT_srch1_MT_D)
	@-if exist $(TARG_TEST_SCRT_srch2_MT_D) $(RM) $(TARG_TEST_SCRT_srch2_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_MT_D) $(RM) $(OBJ_TEST_SCRT_srch2_MT_D)
	@-if exist $(TARG_TEST_SCRT_srch1_MT_R) $(RM) $(TARG_TEST_SCRT_srch1_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_MT_R) $(RM) $(OBJ_TEST_SCRT_srch1_MT_R)
	@-if exist $(TARG_TEST_SCRT_srch2_MT_R) $(RM) $(TARG_TEST_SCRT_srch2_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_MT_R) $(RM) $(OBJ_TEST_SCRT_srch2_MT_R)
	@-if exist $(TARG_TEST_SCRT_srch1_ST_D) $(RM) $(TARG_TEST_SCRT_srch1_ST_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_ST_D) $(RM) $(OBJ_TEST_SCRT_srch1_ST_D)
	@-if exist $(TARG_TEST_SCRT_srch2_ST_D) $(RM) $(TARG_TEST_SCRT_srch2_ST_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_ST_D) $(RM) $(OBJ_TEST_SCRT_srch2_ST_D)
	@-if exist $(TARG_TEST_SCRT_srch1_ST_R) $(RM) $(TARG_TEST_SCRT_srch1_ST_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_ST_R) $(RM) $(OBJ_TEST_SCRT_srch1_ST_R)
	@-if exist $(TARG_TEST_SCRT_srch2_ST_R) $(RM) $(TARG_TEST_SCRT_srch2_ST_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_ST_R) $(RM) $(OBJ_TEST_SCRT_srch2_ST_R)

clean.test.unit:
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_MT_D) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_MT_D) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_MT_D) $(RM) $(TARG_TEST_UNIT_api_drvrel_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_MT_D) $(RM) $(OBJ_TEST_UNIT_api_drvrel_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_MT_D) $(RM) $(TARG_TEST_UNIT_api_sqzpath_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_MT_D) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_MT_D)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_MT_D) $(RM) $(TARG_TEST_UNIT_c_retcodes_MT_D)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_MT_D) $(RM) $(OBJ_TEST_UNIT_c_retcodes_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_MT_R) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_MT_R) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_MT_R) $(RM) $(TARG_TEST_UNIT_api_drvrel_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_MT_R) $(RM) $(OBJ_TEST_UNIT_api_drvrel_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_MT_R) $(RM) $(TARG_TEST_UNIT_api_sqzpath_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_MT_R) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_MT_R)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_MT_R) $(RM) $(TARG_TEST_UNIT_c_retcodes_MT_R)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_MT_R) $(RM) $(OBJ_TEST_UNIT_c_retcodes_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_ST_D) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_ST_D) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_ST_D) $(RM) $(TARG_TEST_UNIT_api_drvrel_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_ST_D) $(RM) $(OBJ_TEST_UNIT_api_drvrel_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_ST_D) $(RM) $(TARG_TEST_UNIT_api_sqzpath_ST_D)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_ST_D) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_ST_D)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_ST_D) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_ST_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_ST_D) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_ST_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_ST_D) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_ST_D)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_ST_D) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_ST_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_ST_D) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_ST_D)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_ST_D) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_ST_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_ST_D) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_ST_D)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_ST_D) $(RM) $(TARG_TEST_UNIT_c_retcodes_ST_D)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_ST_D) $(RM) $(OBJ_TEST_UNIT_c_retcodes_ST_D)
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_ST_R) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_ST_R) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_ST_R) $(RM) $(TARG_TEST_UNIT_api_drvrel_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_ST_R) $(RM) $(OBJ_TEST_UNIT_api_drvrel_ST_R)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_ST_R) $(RM) $(TARG_TEST_UNIT_api_sqzpath_ST_R)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_ST_R) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_ST_R)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_ST_R) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_ST_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_ST_R) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_ST_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_ST_R) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_ST_R)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_ST_R) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_ST_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_ST_R) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_ST_R)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_ST_R) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_ST_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_ST_R) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_ST_R)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_ST_R) $(RM) $(TARG_TEST_UNIT_c_retcodes_ST_R)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_ST_R) $(RM) $(OBJ_TEST_UNIT_c_retcodes_ST_R)

clean.test:                                         clean.test.unit clean.test.component clean.test.scratch

clean:                                              clean.libs clean.test clean.examples clean.samples

clean.all:                                          clean


############################################################################
# build targets

##################################################
# libraries

########################################
# Main library - 'recls.X.core.a'

$(LIB_CORE_MT_D): $(OBJ_CORE_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_MT_D)

$(OBJ_CR_api_entryinfo_MT_D): $(PROJ_SRC_DIR)/api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.entryinfo.cpp
$(OBJ_CR_api_error_MT_D): $(PROJ_SRC_DIR)/api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.error.cpp
$(OBJ_CR_api_extended_MT_D): $(PROJ_SRC_DIR)/api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.extended.cpp
$(OBJ_CR_api_combpath_MT_D): $(PROJ_SRC_DIR)/api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_D): $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_D): $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_D): $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_D): $(PROJ_SRC_DIR)/api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_D): $(PROJ_SRC_DIR)/api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_D): $(PROJ_SRC_DIR)/api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_MT_D): $(PROJ_SRC_DIR)/api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.retcodes.windows.cpp
$(OBJ_CR_api_search_MT_D): $(PROJ_SRC_DIR)/api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.search.cpp
$(OBJ_CR_impl_debug_MT_D): $(PROJ_SRC_DIR)/impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_D): $(PROJ_SRC_DIR)/impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_D): $(PROJ_SRC_DIR)/impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_D): $(PROJ_SRC_DIR)/impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_D): $(PROJ_SRC_DIR)/impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.util.cpp
$(OBJ_CR_Srch_MT_D): $(PROJ_SRC_DIR)/ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_D): $(PROJ_SRC_DIR)/ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_D): $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win32_MT_D): $(PROJ_SRC_DIR)/api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.windows.cpp
$(OBJ_CR_impl_fileinfo_win32_MT_D): $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win32_MT_D): $(PROJ_SRC_DIR)/impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_MT_D): $(PROJ_SRC_DIR)/api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_MT_D): $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_MT_D): $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_D) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp


$(LIB_CORE_MT_R): $(OBJ_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_MT_R)

$(OBJ_CR_api_entryinfo_MT_R): $(PROJ_SRC_DIR)/api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.entryinfo.cpp
$(OBJ_CR_api_error_MT_R): $(PROJ_SRC_DIR)/api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.error.cpp
$(OBJ_CR_api_extended_MT_R): $(PROJ_SRC_DIR)/api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.extended.cpp
$(OBJ_CR_api_combpath_MT_R): $(PROJ_SRC_DIR)/api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_R): $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_R): $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_R): $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_R): $(PROJ_SRC_DIR)/api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_R): $(PROJ_SRC_DIR)/api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_R): $(PROJ_SRC_DIR)/api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_MT_R): $(PROJ_SRC_DIR)/api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.retcodes.windows.cpp
$(OBJ_CR_api_search_MT_R): $(PROJ_SRC_DIR)/api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.search.cpp
$(OBJ_CR_impl_debug_MT_R): $(PROJ_SRC_DIR)/impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_R): $(PROJ_SRC_DIR)/impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_R): $(PROJ_SRC_DIR)/impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_R): $(PROJ_SRC_DIR)/impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_R): $(PROJ_SRC_DIR)/impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.util.cpp
$(OBJ_CR_Srch_MT_R): $(PROJ_SRC_DIR)/ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_R): $(PROJ_SRC_DIR)/ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_R): $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win32_MT_R): $(PROJ_SRC_DIR)/api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.windows.cpp
$(OBJ_CR_impl_fileinfo_win32_MT_R): $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win32_MT_R): $(PROJ_SRC_DIR)/impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_MT_R): $(PROJ_SRC_DIR)/api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_MT_R): $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_MT_R): $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_MT_R) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp


$(LIB_CORE_ST_D): $(OBJ_CORE_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_ST_D)

$(OBJ_CR_api_entryinfo_ST_D): $(PROJ_SRC_DIR)/api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.entryinfo.cpp
$(OBJ_CR_api_error_ST_D): $(PROJ_SRC_DIR)/api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.error.cpp
$(OBJ_CR_api_extended_ST_D): $(PROJ_SRC_DIR)/api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.extended.cpp
$(OBJ_CR_api_combpath_ST_D): $(PROJ_SRC_DIR)/api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_ST_D): $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_ST_D): $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_ST_D): $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_ST_D): $(PROJ_SRC_DIR)/api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.stat.cpp
$(OBJ_CR_api_crdir_ST_D): $(PROJ_SRC_DIR)/api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_ST_D): $(PROJ_SRC_DIR)/api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_ST_D): $(PROJ_SRC_DIR)/api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.retcodes.windows.cpp
$(OBJ_CR_api_search_ST_D): $(PROJ_SRC_DIR)/api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.search.cpp
$(OBJ_CR_impl_debug_ST_D): $(PROJ_SRC_DIR)/impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.trace.cpp
$(OBJ_CR_impl_entryinfo_ST_D): $(PROJ_SRC_DIR)/impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_ST_D): $(PROJ_SRC_DIR)/impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_ST_D): $(PROJ_SRC_DIR)/impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.snprintf.cpp
$(OBJ_CR_impl_util_ST_D): $(PROJ_SRC_DIR)/impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.util.cpp
$(OBJ_CR_Srch_ST_D): $(PROJ_SRC_DIR)/ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/ReclsSearch.cpp
$(OBJ_CR_FlSrch_ST_D): $(PROJ_SRC_DIR)/ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_ST_D): $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win32_ST_D): $(PROJ_SRC_DIR)/api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.windows.cpp
$(OBJ_CR_impl_fileinfo_win32_ST_D): $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win32_ST_D): $(PROJ_SRC_DIR)/impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_ST_D): $(PROJ_SRC_DIR)/api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_ST_D): $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_ST_D): $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_D) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp


$(LIB_CORE_ST_R): $(OBJ_CORE_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_CORE_ST_R)

$(OBJ_CR_api_entryinfo_ST_R): $(PROJ_SRC_DIR)/api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.entryinfo.cpp
$(OBJ_CR_api_error_ST_R): $(PROJ_SRC_DIR)/api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.error.cpp
$(OBJ_CR_api_extended_ST_R): $(PROJ_SRC_DIR)/api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.extended.cpp
$(OBJ_CR_api_combpath_ST_R): $(PROJ_SRC_DIR)/api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_ST_R): $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_ST_R): $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_ST_R): $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_ST_R): $(PROJ_SRC_DIR)/api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.stat.cpp
$(OBJ_CR_api_crdir_ST_R): $(PROJ_SRC_DIR)/api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_ST_R): $(PROJ_SRC_DIR)/api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_ST_R): $(PROJ_SRC_DIR)/api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.retcodes.windows.cpp
$(OBJ_CR_api_search_ST_R): $(PROJ_SRC_DIR)/api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.search.cpp
$(OBJ_CR_impl_debug_ST_R): $(PROJ_SRC_DIR)/impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.trace.cpp
$(OBJ_CR_impl_entryinfo_ST_R): $(PROJ_SRC_DIR)/impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_ST_R): $(PROJ_SRC_DIR)/impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_ST_R): $(PROJ_SRC_DIR)/impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.snprintf.cpp
$(OBJ_CR_impl_util_ST_R): $(PROJ_SRC_DIR)/impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.util.cpp
$(OBJ_CR_Srch_ST_R): $(PROJ_SRC_DIR)/ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/ReclsSearch.cpp
$(OBJ_CR_FlSrch_ST_R): $(PROJ_SRC_DIR)/ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_ST_R): $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win32_ST_R): $(PROJ_SRC_DIR)/api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.windows.cpp
$(OBJ_CR_impl_fileinfo_win32_ST_R): $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win32_ST_R): $(PROJ_SRC_DIR)/impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_ST_R): $(PROJ_SRC_DIR)/api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_ST_R): $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_ST_R): $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_core_ST_R) -o $@ $(PROJ_SRC_DIR)/ReclsFtpSearch_windows.cpp



########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_ST_D): $(OBJ_SHWILD_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_ST_D)

$(OBJ_shw_api_ST_D): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_ST_D): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_ST_D): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_SHWILD_INCLUDES_ST_D) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp

$(LIB_SHWILD_ST_R): $(OBJ_SHWILD_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_SHWILD_ST_R)

$(OBJ_shw_api_ST_R): $(SHWILD_SRC_DIR)/api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/api.cpp
$(OBJ_shw_matches_ST_R): $(SHWILD_SRC_DIR)/matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/matches.cpp
$(OBJ_shw_pattern_ST_R): $(SHWILD_SRC_DIR)/pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_SHWILD_INCLUDES_ST_R) -o $@ $(SHWILD_SRC_DIR)/pattern.cpp


########################################
# xTests library - 'xtests.X.recls.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_D): $(OBJ_XTESTS_ST_D) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_ST_D)

$(OBJ_xts_core_ST_D): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) $(CPPC_XTESTS_INCLUDES_ST_D) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp

$(LIB_XTESTS_ST_R): $(OBJ_XTESTS_ST_R) $(PROJ_MAKEFILE_NAME)
	@-mkdir -p $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -r $@ $(OBJ_XTESTS_ST_R)

$(OBJ_xts_core_ST_R): $(XTESTS_SRC_DIR)/xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) $(CPPC_XTESTS_INCLUDES_ST_R) -o $@ $(XTESTS_SRC_DIR)/xtests.core.cpp


##################################################
# examples

$(TARG_EX_ex_c_1_MT_D):    \
		$(OBJ_EX_ex_c_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_1_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c

$(TARG_EX_ex_c_1_MT_R):    \
		$(OBJ_EX_ex_c_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_1_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c

$(TARG_EX_ex_c_1_ST_D):    \
		$(OBJ_EX_ex_c_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_1_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c

$(TARG_EX_ex_c_1_ST_R):    \
		$(OBJ_EX_ex_c_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_1_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_1/example_c_1.c

$(TARG_EX_ex_c_2_MT_D):    \
		$(OBJ_EX_ex_c_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_2_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c

$(TARG_EX_ex_c_2_MT_R):    \
		$(OBJ_EX_ex_c_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_2_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c

$(TARG_EX_ex_c_2_ST_D):    \
		$(OBJ_EX_ex_c_2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_2_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c

$(TARG_EX_ex_c_2_ST_R):    \
		$(OBJ_EX_ex_c_2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_2_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_2/example_c_2.c

$(TARG_EX_ex_c_3_MT_D):    \
		$(OBJ_EX_ex_c_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_3_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c

$(TARG_EX_ex_c_3_MT_R):    \
		$(OBJ_EX_ex_c_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_3_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c

$(TARG_EX_ex_c_3_ST_D):    \
		$(OBJ_EX_ex_c_3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_3_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c

$(TARG_EX_ex_c_3_ST_R):    \
		$(OBJ_EX_ex_c_3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_3_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_3/example_c_3.c

$(TARG_EX_ex_c_4_MT_D):    \
		$(OBJ_EX_ex_c_4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_4_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c

$(TARG_EX_ex_c_4_MT_R):    \
		$(OBJ_EX_ex_c_4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_4_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c

$(TARG_EX_ex_c_4_ST_D):    \
		$(OBJ_EX_ex_c_4_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_4_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_4_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c

$(TARG_EX_ex_c_4_ST_R):    \
		$(OBJ_EX_ex_c_4_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_4_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_4_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_4/example_c_4.c

$(TARG_EX_ex_c_5_MT_D):    \
		$(OBJ_EX_ex_c_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_5_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c

$(TARG_EX_ex_c_5_MT_R):    \
		$(OBJ_EX_ex_c_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_5_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c

$(TARG_EX_ex_c_5_ST_D):    \
		$(OBJ_EX_ex_c_5_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_5_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_5_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c

$(TARG_EX_ex_c_5_ST_R):    \
		$(OBJ_EX_ex_c_5_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_5_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_5_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_5/example_c_5.c

$(TARG_EX_ex_c_6_MT_D):    \
		$(OBJ_EX_ex_c_6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_6_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c

$(TARG_EX_ex_c_6_MT_R):    \
		$(OBJ_EX_ex_c_6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_6_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c

$(TARG_EX_ex_c_6_ST_D):    \
		$(OBJ_EX_ex_c_6_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_6_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_6_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c

$(TARG_EX_ex_c_6_ST_R):    \
		$(OBJ_EX_ex_c_6_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_6_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_6_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_6/example_c_6.c

$(TARG_EX_ex_c_7_MT_D):    \
		$(OBJ_EX_ex_c_7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_7_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c

$(TARG_EX_ex_c_7_MT_R):    \
		$(OBJ_EX_ex_c_7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_7_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c

$(TARG_EX_ex_c_7_ST_D):    \
		$(OBJ_EX_ex_c_7_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_7_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_7_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c

$(TARG_EX_ex_c_7_ST_R):    \
		$(OBJ_EX_ex_c_7_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_7_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_7_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_7/example_c_7.c

$(TARG_EX_ex_c_8_MT_D):    \
		$(OBJ_EX_ex_c_8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_c_8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_8_MT_D): $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c

$(TARG_EX_ex_c_8_MT_R):    \
		$(OBJ_EX_ex_c_8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_c_8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_8_MT_R): $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c

$(TARG_EX_ex_c_8_ST_D):    \
		$(OBJ_EX_ex_c_8_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_c_8_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_c_8_ST_D): $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c

$(TARG_EX_ex_c_8_ST_R):    \
		$(OBJ_EX_ex_c_8_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_c_8_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_c_8_ST_R): $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/c/example_c_8/example_c_8.c


$(TARG_EX_ex_cpp_1_MT_D):    \
		$(OBJ_EX_ex_cpp_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_cpp_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_1_MT_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_MT_R):    \
		$(OBJ_EX_ex_cpp_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_cpp_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_1_MT_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_ST_D):    \
		$(OBJ_EX_ex_cpp_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_cpp_1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_cpp_1_ST_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_ST_R):    \
		$(OBJ_EX_ex_cpp_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_cpp_1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_cpp_1_ST_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_1/example_cpp_1.cpp

$(TARG_EX_ex_cpp_2_MT_D):    \
		$(OBJ_EX_ex_cpp_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_cpp_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_2_MT_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_MT_R):    \
		$(OBJ_EX_ex_cpp_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_cpp_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_2_MT_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_ST_D):    \
		$(OBJ_EX_ex_cpp_2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_cpp_2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_cpp_2_ST_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_ST_R):    \
		$(OBJ_EX_ex_cpp_2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_cpp_2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_cpp_2_ST_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_2/example_cpp_2.cpp

$(TARG_EX_ex_cpp_3_MT_D):    \
		$(OBJ_EX_ex_cpp_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_EX_ex_cpp_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_3_MT_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_MT_R):    \
		$(OBJ_EX_ex_cpp_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_EX_ex_cpp_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_3_MT_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_ST_D):    \
		$(OBJ_EX_ex_cpp_3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_EX_ex_cpp_3_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_EX_ex_cpp_3_ST_D): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_ST_R):    \
		$(OBJ_EX_ex_cpp_3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_EX_ex_cpp_3_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_EX_ex_cpp_3_ST_R): $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_EXAMPLES_DIR)/cpp/example_cpp_3/example_cpp_3.cpp


##################################################
# tests




##############################
# component tests

$(TARG_TEST_COMP_api_crdir_MT_D):    \
		$(OBJ_TEST_COMP_api_crdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_api_crdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_api_crdir_MT_D): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_MT_R):    \
		$(OBJ_TEST_COMP_api_crdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_api_crdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_api_crdir_MT_R): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_ST_D):    \
		$(OBJ_TEST_COMP_api_crdir_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_api_crdir_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_api_crdir_ST_D): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_ST_R):    \
		$(OBJ_TEST_COMP_api_crdir_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_api_crdir_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_api_crdir_ST_R): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.create_directory/test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_D):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_api_rmdir_MT_D): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_R):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_api_rmdir_MT_R): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_ST_D):    \
		$(OBJ_TEST_COMP_api_rmdir_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_COMP_api_rmdir_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_COMP_api_rmdir_ST_D): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_ST_R):    \
		$(OBJ_TEST_COMP_api_rmdir_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_COMP_api_rmdir_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_COMP_api_rmdir_ST_R): $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_COMPONENT_DIR)/test.component.util.cpp.remove_directory/test.component.util.cpp.remove_directory.cpp


##############################
# scratch tests

$(TARG_TEST_SCRT_srch1_MT_D):    \
		$(OBJ_TEST_SCRT_srch1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_srch1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_srch1_MT_D): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_MT_R):    \
		$(OBJ_TEST_SCRT_srch1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_srch1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_srch1_MT_R): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_ST_D):    \
		$(OBJ_TEST_SCRT_srch1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_srch1_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_srch1_ST_D): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_ST_R):    \
		$(OBJ_TEST_SCRT_srch1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_srch1_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_srch1_ST_R): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.1/test.scratch.search.1.c


$(TARG_TEST_SCRT_srch2_MT_D):    \
		$(OBJ_TEST_SCRT_srch2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_SCRT_srch2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_srch2_MT_D): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_MT_R):    \
		$(OBJ_TEST_SCRT_srch2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_SCRT_srch2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_srch2_MT_R): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_ST_D):    \
		$(OBJ_TEST_SCRT_srch2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_SCRT_srch2_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_SCRT_srch2_ST_D): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_ST_R):    \
		$(OBJ_TEST_SCRT_srch2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_SCRT_srch2_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_SCRT_srch2_ST_R): $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_SCRATCH_DIR)/test.scratch.search.2/test.scratch.search.2.c


##############################
# unit tests

$(TARG_TEST_UNIT_api_cmbpaths_MT_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_MT_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_ST_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_cmbpaths_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_ST_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_cmbpaths_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.combine_paths/test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_drvrel_MT_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_drvrel_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_MT_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_drvrel_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_ST_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_drvrel_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_drvrel_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_ST_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_drvrel_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_drvrel_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.derive_relative_path/test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_sqzpath_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_sqzpath_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_ST_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_api_sqzpath_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_api_sqzpath_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_ST_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_api_sqzpath_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_api_sqzpath_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.api.squeeze_path/test.unit.api.squeeze_path.c


$(TARG_TEST_UNIT_cpp_cmbpaths_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_ST_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_ST_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.combine_paths/test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_ST_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_cpp_drvrel_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_ST_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_cpp_drvrel_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.derive_relative_path/test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_ST_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_ST_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.squeeze_path/test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_ST_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_cpp_retcodes_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_ST_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_cpp_retcodes_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.cpp.retcodes/test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_c_retcodes_MT_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -o $@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_c_retcodes_MT_D): $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_MT_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -o $@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_c_retcodes_MT_R): $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_ST_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_D) -o $@ \
		$(OBJ_TEST_UNIT_c_retcodes_ST_D)\
		$(LIB_CORE_ST_D)\
		$(LIB_SHWILD_ST_D)\
		$(LIB_XTESTS_ST_D)\
		$(TARGET_LIB_ST_D)

$(OBJ_TEST_UNIT_c_retcodes_ST_D): $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_D) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_ST_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_ST_R) -o $@ \
		$(OBJ_TEST_UNIT_c_retcodes_ST_R)\
		$(LIB_CORE_ST_R)\
		$(LIB_SHWILD_ST_R)\
		$(LIB_XTESTS_ST_R)\
		$(TARGET_LIB_ST_R)

$(OBJ_TEST_UNIT_c_retcodes_ST_R): $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_ST_R) -o $@ $(PROJ_TEST_UNIT_DIR)/test.unit.c.retcodes/test.unit.c.retcodes.c


############################### end of file ################################
