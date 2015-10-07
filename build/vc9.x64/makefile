############################################################################
# File:     makefile
#
# Purpose:  Makefile for the recls project, for the Visual C++ 9 (x64 64-bit)
#           compiler, on Win64
#
# Created:  23rd September 2003
# Updated:  30th September 2015
#
############################################################################


############################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # !STLSOFT

############################################################################
# Symbols

########################################
# Project & compiler version

COMP_TAG            =   vc9
ARCH_TAG            =   .x64
OS_TAG				=   
PROJ_TAG            =   recls
PROJ_VER_MAJOR      =   1
PROJ_TAG_VER        =   $(PROJ_TAG).$(PROJ_VER_MAJOR)
COMP_ARCH_OS_TAG	=	$(COMP_TAG)$(OS_TAG)$(ARCH_TAG)

SHWILD_VER_MAJOR    =   0
SHWILD_TAG_VER      =   shwild.$(SHWILD_VER_MAJOR)

XCOVER_VER_MAJOR    =   0
XCOVER_TAG_VER      =   xcover.$(XCOVER_VER_MAJOR)

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

XCOVER_PROJ_INCLUDE		=	
!ifdef RECLS_XCOVER_BASE_DIR
XCOVER_INCLUDE_DIR		=   $(RECLS_XCOVER_BASE_DIR)\include
XCOVER_SRC_DIR			=   $(RECLS_XCOVER_BASE_DIR)\src
XCOVER_PROJ_INCLUDE		=	-I$(XCOVER_INCLUDE_DIR)
!else
XCOVER_INCLUDE_DIR		=   $(PROJ_BASE_DIR)\include
XCOVER_SRC_DIR			=   $(PROJ_SRC_DIR)\xcover
!endif # !RECLS_XCOVER_BASE_DIR

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
$(COMMON_LIBPATHS)\
$(ENV_LIBPATHS)\
\


# lib names

TARGET_LIB_MT_D=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_DLL_D=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_DLL_R=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_MT_R=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_W_MT_D=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_W_DLL_D=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_W_DLL_R=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \

TARGET_LIB_W_MT_R=\
 advapi32.lib kernel32.lib ole32.lib oleaut32.lib shlwapi.lib user32.lib uuid.lib wininet.lib \
 \


# #defines

COMMON_DEFS 		=	-DWIN64




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

CC_FLAGS_MT_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_DLL_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_DLL_R=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_MT_R=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_W_MT_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_W_DLL_D=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_W_DLL_R=\
 $(CC_FLAGS_BASE)\
 \

CC_FLAGS_W_MT_R=\
 $(CC_FLAGS_BASE)\
 \


# CPPC flags

CPPC_F_NOLOGO           =   -nologo
CPPC_F_COMPILE_ONLY     =   -c
CPPC_F_WARNING_MAX      =   -W4 -wd4800
CPPC_F_WARNING_ERR      =   -WX
CPPC_F_EXCEPTIONS_ON    =   -EHsc
CPPC_F_EXCEPTIONS_OFF   =   -GX- -wd4530
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

CPPC_FLAGS_MT_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_DLL_R=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_MT_R=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_W_MT_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_W_DLL_D=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_W_DLL_R=\
 $(CPPC_FLAGS_BASE)\
 \

CPPC_FLAGS_W_MT_R=\
 $(CPPC_FLAGS_BASE)\
 \


# CC defines

CC_DEFS_BASE=\
 $(COMMON_DEFS)\
 \

CC_DEFS_MT_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_DLL_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_DLL_R=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_MT_R=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_W_MT_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_W_DLL_D=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_W_DLL_R=\
 $(CC_DEFS_BASE)\
 \

CC_DEFS_W_MT_R=\
 $(CC_DEFS_BASE)\
 \



# CPPC defines

CPPC_DEFS_BASE=\
 $(COMMON_DEFS)\
 \

CPPC_DEFS_MT_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_DLL_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_DLL_R=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_MT_R=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_W_MT_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_W_DLL_D=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_W_DLL_R=\
 $(CPPC_DEFS_BASE)\
 \

CPPC_DEFS_W_MT_R=\
 $(CPPC_DEFS_BASE)\
 \



# CC includes

CC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XCOVER_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(ENV_INCLUDES)\
 \

CC_INCLUDES_MT_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_DLL_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_DLL_R=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_MT_R=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_W_MT_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_W_DLL_D=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_W_DLL_R=\
 $(CC_INCLUDES_BASE)\
 \

CC_INCLUDES_W_MT_R=\
 $(CC_INCLUDES_BASE)\
 \



CC_SHWILD_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_DLL_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_DLL_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_MT_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_W_MT_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_W_DLL_D=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_W_DLL_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \

CC_SHWILD_INCLUDES_W_MT_R=\
 $(CC_SHWILD_INCLUDES_BASE)\
 \


CC_XTESTS_INCLUDES_BASE=\
 $(CC_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_DLL_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_DLL_R=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_MT_R=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_W_MT_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_W_DLL_D=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_W_DLL_R=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \

CC_XTESTS_INCLUDES_W_MT_R=\
 $(CC_XTESTS_INCLUDES_BASE)\
 \



# CPPC includes

CPPC_INCLUDES_BASE=\
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(SHWILD_PROJ_INCLUDE)\
 $(XCONTRACT_PROJ_INCLUDE)\
 $(XCOVER_PROJ_INCLUDE)\
 $(XTESTS_PROJ_INCLUDE)\
 $(STLSOFT_1_10_INCLUDE)\
 $(STLSOFT_PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 $(ENV_INCLUDES)\
 \

CPPC_INCLUDES_MT_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_DLL_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_DLL_R=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_MT_R=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_W_MT_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_W_DLL_D=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_W_DLL_R=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_INCLUDES_W_MT_R=\
 $(CPPC_INCLUDES_BASE)\
 \



CPPC_SHWILD_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_DLL_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_MT_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_W_MT_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_W_DLL_D=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_W_DLL_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \

CPPC_SHWILD_INCLUDES_W_MT_R=\
 $(CPPC_SHWILD_INCLUDES_BASE)\
 \


CPPC_XTESTS_INCLUDES_BASE=\
 $(CPPC_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_DLL_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_MT_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_W_MT_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_W_DLL_D=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_W_DLL_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \

CPPC_XTESTS_INCLUDES_W_MT_R=\
 $(CPPC_XTESTS_INCLUDES_BASE)\
 \



# CC args (= flags + defines + includes)

CC_ARGS_MT_D=\
 $(CC_FLAGS_MT_D)\
 -MTd -D_DEBUG -Zi -Fd$*.pdb\
 $(CC_DEFS_MT_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_MT_D)
CC_ARGS_DLL_D=\
 $(CC_FLAGS_DLL_D)\
 -MDd -D_DEBUG -Zi -Fd$*.pdb\
 $(CC_DEFS_DLL_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_DLL_D)
CC_ARGS_DLL_R=\
 $(CC_FLAGS_DLL_R)\
 -MD -DNDEBUG\
 $(CC_DEFS_DLL_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_DLL_R)
CC_ARGS_MT_R=\
 $(CC_FLAGS_MT_R)\
 -MT -DNDEBUG\
 $(CC_DEFS_MT_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_MT_R)
CC_ARGS_W_MT_D=\
 $(CC_FLAGS_W_MT_D)\
 -MTd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.pdb\
 $(CC_DEFS_W_MT_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_W_MT_D)
CC_ARGS_W_DLL_D=\
 $(CC_FLAGS_W_DLL_D)\
 -MDd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.pdb\
 $(CC_DEFS_W_DLL_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_W_DLL_D)
CC_ARGS_W_DLL_R=\
 $(CC_FLAGS_W_DLL_R)\
 -MD -DUNICODE -D_UNICODE -DNDEBUG\
 $(CC_DEFS_W_DLL_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_W_DLL_R)
CC_ARGS_W_MT_R=\
 $(CC_FLAGS_W_MT_R)\
 -MT -DUNICODE -D_UNICODE -DNDEBUG\
 $(CC_DEFS_W_MT_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CC_INCLUDES_W_MT_R)

# CPPC args (= flags + defines + includes)

CPPC_ARGS_MT_D=\
 $(CPPC_FLAGS_MT_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -D_DEBUG -Zi -Fd$*.pdb\
 $(CPPC_DEFS_MT_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_MT_D)
CPPC_ARGS_DLL_D=\
 $(CPPC_FLAGS_DLL_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -D_DEBUG -Zi -Fd$*.pdb\
 $(CPPC_DEFS_DLL_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_DLL_D)
CPPC_ARGS_DLL_R=\
 $(CPPC_FLAGS_DLL_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DNDEBUG\
 $(CPPC_DEFS_DLL_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_DLL_R)
CPPC_ARGS_MT_R=\
 $(CPPC_FLAGS_MT_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DNDEBUG\
 $(CPPC_DEFS_MT_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_MT_R)
CPPC_ARGS_W_MT_D=\
 $(CPPC_FLAGS_W_MT_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MTd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.pdb\
 $(CPPC_DEFS_W_MT_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_W_MT_D)
CPPC_ARGS_W_DLL_D=\
 $(CPPC_FLAGS_W_DLL_D)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MDd -DUNICODE -D_UNICODE -D_DEBUG -Zi -Fd$*.pdb\
 $(CPPC_DEFS_W_DLL_D)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_W_DLL_D)
CPPC_ARGS_W_DLL_R=\
 $(CPPC_FLAGS_W_DLL_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MD -DUNICODE -D_UNICODE -DNDEBUG\
 $(CPPC_DEFS_W_DLL_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_W_DLL_R)
CPPC_ARGS_W_MT_R=\
 $(CPPC_FLAGS_W_MT_R)\
 $(CPPC_F_EXCEPTIONS_ON) $(CPPC_F_RTTI_ON) -MT -DUNICODE -D_UNICODE -DNDEBUG\
 $(CPPC_DEFS_W_MT_R)\
 -DRECLS_NO_IMPLICIT_LINK\
 -DSHWILD_QUALITY_NO_USE_XCOVER\
 $(CPPC_INCLUDES_W_MT_R)



# AR Args

AR_ARGS             =   -nologo


# LD flags

LD_F_NOLOGO				=   -nologo

LD_FLAGS_BASE=\
 $(LD_F_NOLOGO)\
 \

LD_FLAGS_MT_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_DLL_R=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_MT_R=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_W_MT_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_W_DLL_D=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_W_DLL_R=\
 $(LD_FLAGS_BASE)\
 \

LD_FLAGS_W_MT_R=\
 $(LD_FLAGS_BASE)\
 \


# LD includes

LD_INCLUDES_BASE=\
 $(LIBPATHS)\
 \

LD_INCLUDES_MT_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_DLL_R=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_MT_R=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_W_MT_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_W_DLL_D=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_W_DLL_R=\
 $(LD_INCLUDES_BASE)\
 \

LD_INCLUDES_W_MT_R=\
 $(LD_INCLUDES_BASE)\
 \


# LD args

LD_ARGS_MT_D= $(LD_FLAGS_MT_D)  $(LD_INCLUDES_MT_D)
LD_ARGS_DLL_D= $(LD_FLAGS_DLL_D)  $(LD_INCLUDES_DLL_D)
LD_ARGS_DLL_R= $(LD_FLAGS_DLL_R)  $(LD_INCLUDES_DLL_R)
LD_ARGS_MT_R= $(LD_FLAGS_MT_R)  $(LD_INCLUDES_MT_R)
LD_ARGS_W_MT_D= $(LD_FLAGS_W_MT_D)  $(LD_INCLUDES_W_MT_D)
LD_ARGS_W_DLL_D= $(LD_FLAGS_W_DLL_D)  $(LD_INCLUDES_W_DLL_D)
LD_ARGS_W_DLL_R= $(LD_FLAGS_W_DLL_R)  $(LD_INCLUDES_W_DLL_R)
LD_ARGS_W_MT_R= $(LD_FLAGS_W_MT_R)  $(LD_INCLUDES_W_MT_R)



# 3rd party libraries

3PTY_LIBS_BASE=\
 ole32.lib\
 oleaut32.lib\
 \


3PTY_LIBS_MT_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_DLL_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_DLL_R	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_MT_R	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_W_MT_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_W_DLL_D	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_W_DLL_R	=\
 $(3PTY_LIBS_BASE)\
 \

3PTY_LIBS_W_MT_R	=\
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

XCOVER_HEADERS=\
 $(XCOVER_INCLUDE_DIR)\xcover\xcover.h\
 $(XCOVER_INCLUDE_DIR)\xcover\internal\reporter.h\
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
LIB_CORE_MT_D           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_CORE_DLL_D           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_CORE_DLL_R           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).dll.lib
LIB_CORE_MT_R           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).mt.lib
LIB_CORE_W_MT_D           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_CORE_W_DLL_D           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_CORE_W_DLL_R           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_CORE_W_MT_R           =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_ARCH_OS_TAG).widestring.mt.lib

# shwild
LIB_SHWILD_MT_D         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_SHWILD_DLL_D         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_SHWILD_DLL_R         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.lib
LIB_SHWILD_MT_R         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_SHWILD_W_MT_D         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_SHWILD_W_DLL_D         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_SHWILD_W_DLL_R         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_SHWILD_W_MT_R         =   $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.lib

# xcover
LIB_XCOVER_MT_D         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XCOVER_DLL_D         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_XCOVER_DLL_R         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.lib
LIB_XCOVER_MT_R         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XCOVER_W_MT_D         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_XCOVER_W_DLL_D         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_XCOVER_W_DLL_R         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_XCOVER_W_MT_R         =   $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.lib

# xtests
LIB_XTESTS_MT_D         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.debug.lib
LIB_XTESTS_DLL_D         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.debug.lib
LIB_XTESTS_DLL_R         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).dll.lib
LIB_XTESTS_MT_R         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).mt.lib
LIB_XTESTS_W_MT_D         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.debug.lib
LIB_XTESTS_W_DLL_D         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.debug.lib
LIB_XTESTS_W_DLL_R         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.dll.lib
LIB_XTESTS_W_MT_R         =   $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_ARCH_OS_TAG).widestring.mt.lib

########################################
# Examples

TARG_EX_ex_c_1_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_2_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_3_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_4_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_5_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_6_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_7_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_8_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_c_1_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_2_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_3_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_4_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_5_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_6_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_7_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_8_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_c_1_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_2_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_3_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_4_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_5_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_6_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_7_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_8_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_c_1_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_2_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_3_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_4_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_5_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_6_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_7_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_8_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_c_1_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_2_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_3_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_4_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_5_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_6_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_7_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_8_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_c_1_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_2_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_3_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_4_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_5_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_6_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_7_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_8_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_c_1_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_2_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_3_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_4_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_5_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_6_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_7_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_8_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_c_1_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_1.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_2_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_2.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_3_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_3.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_4_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_4.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_5_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_5.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_6_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_6.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_7_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_7.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_c_8_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.c.example_c_8.$(COMP_ARCH_OS_TAG).widestring.mt.exe

TARG_EX_ex_cpp_1_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_2_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_3_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_EX_ex_cpp_1_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_cpp_2_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_cpp_3_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_EX_ex_cpp_1_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_cpp_2_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_cpp_3_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).dll.exe
TARG_EX_ex_cpp_1_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_2_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_3_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).mt.exe
TARG_EX_ex_cpp_1_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_cpp_2_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_cpp_3_W_MT_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_EX_ex_cpp_1_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_cpp_2_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_cpp_3_W_DLL_D	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_EX_ex_cpp_1_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_cpp_2_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_cpp_3_W_DLL_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_EX_ex_cpp_1_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_1.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_cpp_2_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_2.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_EX_ex_cpp_3_W_MT_R	=	$(PROJ_BIN_DIR)\$(PROJ_TAG_VER).ex.cpp.example_cpp_3.$(COMP_ARCH_OS_TAG).widestring.mt.exe

########################################
# Tests

##############################
# Component Tests

TARG_TEST_COMP_api_crdir_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_api_rmdir_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_COMP_api_crdir_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_api_rmdir_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_COMP_api_crdir_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_api_rmdir_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_COMP_api_crdir_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_rmdir_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_COMP_api_crdir_W_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_api_rmdir_W_MT_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_COMP_api_crdir_W_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_api_rmdir_W_DLL_D	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_COMP_api_crdir_W_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_api_rmdir_W_DLL_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_COMP_api_crdir_W_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.create_directory.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_COMP_api_rmdir_W_MT_R	=   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.util.cpp.remove_directory.$(COMP_ARCH_OS_TAG).widestring.mt.exe

##############################
# Scratch Tests

TARG_TEST_SCRT_srch1_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_srch2_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_SCRT_srch1_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_srch2_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_SCRT_srch1_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_srch2_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_SCRT_srch1_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch2_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_SCRT_srch1_W_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_SCRT_srch2_W_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_SCRT_srch1_W_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_SCRT_srch2_W_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_SCRT_srch1_W_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_SCRT_srch2_W_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_SCRT_srch1_W_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.1.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_SCRT_srch2_W_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.search.2.$(COMP_ARCH_OS_TAG).widestring.mt.exe

##############################
# Unit Tests

TARG_TEST_UNIT_api_cmbpaths_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_drvrel_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_sqzpath_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_drvrel_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_cpp_retcodes_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_c_retcodes_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.debug.exe
TARG_TEST_UNIT_api_cmbpaths_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_drvrel_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_sqzpath_DLL_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_cpp_drvrel_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_DLL_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_cpp_retcodes_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_c_retcodes_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).dll.debug.exe
TARG_TEST_UNIT_api_cmbpaths_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_drvrel_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_sqzpath_DLL_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_cpp_cmbpaths_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_cpp_drvrel_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_cpp_sqzpath_DLL_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_cpp_retcodes_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_c_retcodes_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).dll.exe
TARG_TEST_UNIT_api_cmbpaths_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_drvrel_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_sqzpath_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_cmbpaths_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_drvrel_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_sqzpath_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_cpp_retcodes_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_c_retcodes_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).mt.exe
TARG_TEST_UNIT_api_cmbpaths_W_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_drvrel_W_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_sqzpath_W_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_cpp_drvrel_W_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_W_MT_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_cpp_retcodes_W_MT_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_c_retcodes_W_MT_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).widestring.mt.debug.exe
TARG_TEST_UNIT_api_cmbpaths_W_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_drvrel_W_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_sqzpath_W_DLL_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_cpp_drvrel_W_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_cpp_retcodes_W_DLL_D  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_c_retcodes_W_DLL_D    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).widestring.dll.debug.exe
TARG_TEST_UNIT_api_cmbpaths_W_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_drvrel_W_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_sqzpath_W_DLL_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_cpp_drvrel_W_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_cpp_retcodes_W_DLL_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_c_retcodes_W_DLL_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).widestring.dll.exe
TARG_TEST_UNIT_api_cmbpaths_W_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.combine_paths.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_drvrel_W_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_api_sqzpath_W_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.api.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.combine_paths.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_cpp_drvrel_W_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.derive_relative_path.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_cpp_sqzpath_W_MT_R   =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.squeeze_path.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_cpp_retcodes_W_MT_R  =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.cpp.retcodes.$(COMP_ARCH_OS_TAG).widestring.mt.exe
TARG_TEST_UNIT_c_retcodes_W_MT_R    =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.c.retcodes.$(COMP_ARCH_OS_TAG).widestring.mt.exe


############################################################################
# Objects

########################################
# Libraries

# recls

OBJ_CR_api_entryinfo_MT_D		= $(PROJ_OBJ_DIR)\api.entryinfo.mt.debug.obj
OBJ_CR_api_error_MT_D			= $(PROJ_OBJ_DIR)\api.error.mt.debug.obj
OBJ_CR_api_extended_MT_D		= $(PROJ_OBJ_DIR)\api.extended.mt.debug.obj
OBJ_CR_api_combpath_MT_D		= $(PROJ_OBJ_DIR)\api.combpath.mt.debug.obj
OBJ_CR_api_derrpath_MT_D		= $(PROJ_OBJ_DIR)\api.derrpath.mt.debug.obj
OBJ_CR_api_getflsizs_MT_D		= $(PROJ_OBJ_DIR)\api.getflsizs.mt.debug.obj
OBJ_CR_api_sqzpath_MT_D		= $(PROJ_OBJ_DIR)\api.sqzpath.mt.debug.obj
OBJ_CR_api_stat_MT_D			= $(PROJ_OBJ_DIR)\api.stat.mt.debug.obj
OBJ_CR_api_crdir_MT_D			= $(PROJ_OBJ_DIR)\api.crdir.mt.debug.obj
OBJ_CR_api_rc_win_MT_D		= $(PROJ_OBJ_DIR)\api.retcodes.windows.mt.debug.obj
OBJ_CR_api_rmdir_MT_D			= $(PROJ_OBJ_DIR)\api.rmdir.mt.debug.obj
OBJ_CR_api_search_MT_D		= $(PROJ_OBJ_DIR)\api.search.mt.debug.obj
OBJ_CR_impl_debug_MT_D		= $(PROJ_OBJ_DIR)\impl.trace.mt.debug.obj
OBJ_CR_impl_entryinfo_MT_D	= $(PROJ_OBJ_DIR)\impl.entryinfo.mt.debug.obj
OBJ_CR_impl_fileinfo_MT_D		= $(PROJ_OBJ_DIR)\impl.fileinfo.mt.debug.obj
OBJ_CR_impl_snprintf_MT_D		= $(PROJ_OBJ_DIR)\impl.snprintf.mt.debug.obj
OBJ_CR_impl_util_MT_D			= $(PROJ_OBJ_DIR)\impl.util.mt.debug.obj
OBJ_CR_Srch_MT_D				= $(PROJ_OBJ_DIR)\ReclsSearch.mt.debug.obj
OBJ_CR_FlSrch_MT_D			= $(PROJ_OBJ_DIR)\ReclsFileSearch.mt.debug.obj
OBJ_CR_FlSchDirNode_MT_D		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.mt.debug.obj
OBJ_CR_api_win64_MT_D				= $(PROJ_OBJ_DIR)\api.win64.mt.debug.obj
OBJ_CR_impl_fileinfo_win64_MT_D	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.mt.debug.obj
OBJ_CR_impl_util_win64_MT_D		= $(PROJ_OBJ_DIR)\impl.util.win64.mt.debug.obj
OBJ_CR_api_ftp_windows_MT_D	= $(PROJ_OBJ_DIR)\api.ftp.windows.mt.debug.obj
OBJ_CR_FtpSchDirNode_win_MT_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.mt.debug.obj
OBJ_CR_FtpSrch_windows_MT_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.mt.debug.obj



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
 $(OBJ_CR_api_win64_MT_D)\
 $(OBJ_CR_impl_fileinfo_win64_MT_D)\
 $(OBJ_CR_impl_util_win64_MT_D)\
 $(OBJ_CR_api_ftp_windows_MT_D)\
 $(OBJ_CR_FtpSchDirNode_win_MT_D)\
 $(OBJ_CR_FtpSrch_windows_MT_D)\
 \

OBJ_CR_api_entryinfo_DLL_D		= $(PROJ_OBJ_DIR)\api.entryinfo.dll.debug.obj
OBJ_CR_api_error_DLL_D			= $(PROJ_OBJ_DIR)\api.error.dll.debug.obj
OBJ_CR_api_extended_DLL_D		= $(PROJ_OBJ_DIR)\api.extended.dll.debug.obj
OBJ_CR_api_combpath_DLL_D		= $(PROJ_OBJ_DIR)\api.combpath.dll.debug.obj
OBJ_CR_api_derrpath_DLL_D		= $(PROJ_OBJ_DIR)\api.derrpath.dll.debug.obj
OBJ_CR_api_getflsizs_DLL_D		= $(PROJ_OBJ_DIR)\api.getflsizs.dll.debug.obj
OBJ_CR_api_sqzpath_DLL_D		= $(PROJ_OBJ_DIR)\api.sqzpath.dll.debug.obj
OBJ_CR_api_stat_DLL_D			= $(PROJ_OBJ_DIR)\api.stat.dll.debug.obj
OBJ_CR_api_crdir_DLL_D			= $(PROJ_OBJ_DIR)\api.crdir.dll.debug.obj
OBJ_CR_api_rc_win_DLL_D		= $(PROJ_OBJ_DIR)\api.retcodes.windows.dll.debug.obj
OBJ_CR_api_rmdir_DLL_D			= $(PROJ_OBJ_DIR)\api.rmdir.dll.debug.obj
OBJ_CR_api_search_DLL_D		= $(PROJ_OBJ_DIR)\api.search.dll.debug.obj
OBJ_CR_impl_debug_DLL_D		= $(PROJ_OBJ_DIR)\impl.trace.dll.debug.obj
OBJ_CR_impl_entryinfo_DLL_D	= $(PROJ_OBJ_DIR)\impl.entryinfo.dll.debug.obj
OBJ_CR_impl_fileinfo_DLL_D		= $(PROJ_OBJ_DIR)\impl.fileinfo.dll.debug.obj
OBJ_CR_impl_snprintf_DLL_D		= $(PROJ_OBJ_DIR)\impl.snprintf.dll.debug.obj
OBJ_CR_impl_util_DLL_D			= $(PROJ_OBJ_DIR)\impl.util.dll.debug.obj
OBJ_CR_Srch_DLL_D				= $(PROJ_OBJ_DIR)\ReclsSearch.dll.debug.obj
OBJ_CR_FlSrch_DLL_D			= $(PROJ_OBJ_DIR)\ReclsFileSearch.dll.debug.obj
OBJ_CR_FlSchDirNode_DLL_D		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.dll.debug.obj
OBJ_CR_api_win64_DLL_D				= $(PROJ_OBJ_DIR)\api.win64.dll.debug.obj
OBJ_CR_impl_fileinfo_win64_DLL_D	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.dll.debug.obj
OBJ_CR_impl_util_win64_DLL_D		= $(PROJ_OBJ_DIR)\impl.util.win64.dll.debug.obj
OBJ_CR_api_ftp_windows_DLL_D	= $(PROJ_OBJ_DIR)\api.ftp.windows.dll.debug.obj
OBJ_CR_FtpSchDirNode_win_DLL_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.dll.debug.obj
OBJ_CR_FtpSrch_windows_DLL_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.dll.debug.obj



OBJ_CORE_DLL_D=\
 $(OBJ_CR_api_entryinfo_DLL_D)\
 $(OBJ_CR_api_error_DLL_D)\
 $(OBJ_CR_api_extended_DLL_D)\
 $(OBJ_CR_api_combpath_DLL_D)\
 $(OBJ_CR_api_derrpath_DLL_D)\
 $(OBJ_CR_api_getflsizs_DLL_D)\
 $(OBJ_CR_api_sqzpath_DLL_D)\
 $(OBJ_CR_api_stat_DLL_D)\
 $(OBJ_CR_api_crdir_DLL_D)\
 $(OBJ_CR_api_rmdir_DLL_D)\
 $(OBJ_CR_api_rc_win_DLL_D)\
 $(OBJ_CR_api_search_DLL_D)\
 $(OBJ_CR_impl_debug_DLL_D)\
 $(OBJ_CR_impl_entryinfo_DLL_D)\
 $(OBJ_CR_impl_fileinfo_DLL_D)\
 $(OBJ_CR_impl_snprintf_DLL_D)\
 $(OBJ_CR_impl_util_DLL_D)\
 $(OBJ_CR_Srch_DLL_D)\
 $(OBJ_CR_FlSrch_DLL_D)\
 $(OBJ_CR_FlSchDirNode_DLL_D)\
 $(OBJ_CR_api_win64_DLL_D)\
 $(OBJ_CR_impl_fileinfo_win64_DLL_D)\
 $(OBJ_CR_impl_util_win64_DLL_D)\
 $(OBJ_CR_api_ftp_windows_DLL_D)\
 $(OBJ_CR_FtpSchDirNode_win_DLL_D)\
 $(OBJ_CR_FtpSrch_windows_DLL_D)\
 \

OBJ_CR_api_entryinfo_DLL_R		= $(PROJ_OBJ_DIR)\api.entryinfo.dll.obj
OBJ_CR_api_error_DLL_R			= $(PROJ_OBJ_DIR)\api.error.dll.obj
OBJ_CR_api_extended_DLL_R		= $(PROJ_OBJ_DIR)\api.extended.dll.obj
OBJ_CR_api_combpath_DLL_R		= $(PROJ_OBJ_DIR)\api.combpath.dll.obj
OBJ_CR_api_derrpath_DLL_R		= $(PROJ_OBJ_DIR)\api.derrpath.dll.obj
OBJ_CR_api_getflsizs_DLL_R		= $(PROJ_OBJ_DIR)\api.getflsizs.dll.obj
OBJ_CR_api_sqzpath_DLL_R		= $(PROJ_OBJ_DIR)\api.sqzpath.dll.obj
OBJ_CR_api_stat_DLL_R			= $(PROJ_OBJ_DIR)\api.stat.dll.obj
OBJ_CR_api_crdir_DLL_R			= $(PROJ_OBJ_DIR)\api.crdir.dll.obj
OBJ_CR_api_rc_win_DLL_R		= $(PROJ_OBJ_DIR)\api.retcodes.windows.dll.obj
OBJ_CR_api_rmdir_DLL_R			= $(PROJ_OBJ_DIR)\api.rmdir.dll.obj
OBJ_CR_api_search_DLL_R		= $(PROJ_OBJ_DIR)\api.search.dll.obj
OBJ_CR_impl_debug_DLL_R		= $(PROJ_OBJ_DIR)\impl.trace.dll.obj
OBJ_CR_impl_entryinfo_DLL_R	= $(PROJ_OBJ_DIR)\impl.entryinfo.dll.obj
OBJ_CR_impl_fileinfo_DLL_R		= $(PROJ_OBJ_DIR)\impl.fileinfo.dll.obj
OBJ_CR_impl_snprintf_DLL_R		= $(PROJ_OBJ_DIR)\impl.snprintf.dll.obj
OBJ_CR_impl_util_DLL_R			= $(PROJ_OBJ_DIR)\impl.util.dll.obj
OBJ_CR_Srch_DLL_R				= $(PROJ_OBJ_DIR)\ReclsSearch.dll.obj
OBJ_CR_FlSrch_DLL_R			= $(PROJ_OBJ_DIR)\ReclsFileSearch.dll.obj
OBJ_CR_FlSchDirNode_DLL_R		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.dll.obj
OBJ_CR_api_win64_DLL_R				= $(PROJ_OBJ_DIR)\api.win64.dll.obj
OBJ_CR_impl_fileinfo_win64_DLL_R	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.dll.obj
OBJ_CR_impl_util_win64_DLL_R		= $(PROJ_OBJ_DIR)\impl.util.win64.dll.obj
OBJ_CR_api_ftp_windows_DLL_R	= $(PROJ_OBJ_DIR)\api.ftp.windows.dll.obj
OBJ_CR_FtpSchDirNode_win_DLL_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.dll.obj
OBJ_CR_FtpSrch_windows_DLL_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.dll.obj



OBJ_CORE_DLL_R=\
 $(OBJ_CR_api_entryinfo_DLL_R)\
 $(OBJ_CR_api_error_DLL_R)\
 $(OBJ_CR_api_extended_DLL_R)\
 $(OBJ_CR_api_combpath_DLL_R)\
 $(OBJ_CR_api_derrpath_DLL_R)\
 $(OBJ_CR_api_getflsizs_DLL_R)\
 $(OBJ_CR_api_sqzpath_DLL_R)\
 $(OBJ_CR_api_stat_DLL_R)\
 $(OBJ_CR_api_crdir_DLL_R)\
 $(OBJ_CR_api_rmdir_DLL_R)\
 $(OBJ_CR_api_rc_win_DLL_R)\
 $(OBJ_CR_api_search_DLL_R)\
 $(OBJ_CR_impl_debug_DLL_R)\
 $(OBJ_CR_impl_entryinfo_DLL_R)\
 $(OBJ_CR_impl_fileinfo_DLL_R)\
 $(OBJ_CR_impl_snprintf_DLL_R)\
 $(OBJ_CR_impl_util_DLL_R)\
 $(OBJ_CR_Srch_DLL_R)\
 $(OBJ_CR_FlSrch_DLL_R)\
 $(OBJ_CR_FlSchDirNode_DLL_R)\
 $(OBJ_CR_api_win64_DLL_R)\
 $(OBJ_CR_impl_fileinfo_win64_DLL_R)\
 $(OBJ_CR_impl_util_win64_DLL_R)\
 $(OBJ_CR_api_ftp_windows_DLL_R)\
 $(OBJ_CR_FtpSchDirNode_win_DLL_R)\
 $(OBJ_CR_FtpSrch_windows_DLL_R)\
 \

OBJ_CR_api_entryinfo_MT_R		= $(PROJ_OBJ_DIR)\api.entryinfo.mt.obj
OBJ_CR_api_error_MT_R			= $(PROJ_OBJ_DIR)\api.error.mt.obj
OBJ_CR_api_extended_MT_R		= $(PROJ_OBJ_DIR)\api.extended.mt.obj
OBJ_CR_api_combpath_MT_R		= $(PROJ_OBJ_DIR)\api.combpath.mt.obj
OBJ_CR_api_derrpath_MT_R		= $(PROJ_OBJ_DIR)\api.derrpath.mt.obj
OBJ_CR_api_getflsizs_MT_R		= $(PROJ_OBJ_DIR)\api.getflsizs.mt.obj
OBJ_CR_api_sqzpath_MT_R		= $(PROJ_OBJ_DIR)\api.sqzpath.mt.obj
OBJ_CR_api_stat_MT_R			= $(PROJ_OBJ_DIR)\api.stat.mt.obj
OBJ_CR_api_crdir_MT_R			= $(PROJ_OBJ_DIR)\api.crdir.mt.obj
OBJ_CR_api_rc_win_MT_R		= $(PROJ_OBJ_DIR)\api.retcodes.windows.mt.obj
OBJ_CR_api_rmdir_MT_R			= $(PROJ_OBJ_DIR)\api.rmdir.mt.obj
OBJ_CR_api_search_MT_R		= $(PROJ_OBJ_DIR)\api.search.mt.obj
OBJ_CR_impl_debug_MT_R		= $(PROJ_OBJ_DIR)\impl.trace.mt.obj
OBJ_CR_impl_entryinfo_MT_R	= $(PROJ_OBJ_DIR)\impl.entryinfo.mt.obj
OBJ_CR_impl_fileinfo_MT_R		= $(PROJ_OBJ_DIR)\impl.fileinfo.mt.obj
OBJ_CR_impl_snprintf_MT_R		= $(PROJ_OBJ_DIR)\impl.snprintf.mt.obj
OBJ_CR_impl_util_MT_R			= $(PROJ_OBJ_DIR)\impl.util.mt.obj
OBJ_CR_Srch_MT_R				= $(PROJ_OBJ_DIR)\ReclsSearch.mt.obj
OBJ_CR_FlSrch_MT_R			= $(PROJ_OBJ_DIR)\ReclsFileSearch.mt.obj
OBJ_CR_FlSchDirNode_MT_R		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.mt.obj
OBJ_CR_api_win64_MT_R				= $(PROJ_OBJ_DIR)\api.win64.mt.obj
OBJ_CR_impl_fileinfo_win64_MT_R	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.mt.obj
OBJ_CR_impl_util_win64_MT_R		= $(PROJ_OBJ_DIR)\impl.util.win64.mt.obj
OBJ_CR_api_ftp_windows_MT_R	= $(PROJ_OBJ_DIR)\api.ftp.windows.mt.obj
OBJ_CR_FtpSchDirNode_win_MT_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.mt.obj
OBJ_CR_FtpSrch_windows_MT_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.mt.obj



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
 $(OBJ_CR_api_win64_MT_R)\
 $(OBJ_CR_impl_fileinfo_win64_MT_R)\
 $(OBJ_CR_impl_util_win64_MT_R)\
 $(OBJ_CR_api_ftp_windows_MT_R)\
 $(OBJ_CR_FtpSchDirNode_win_MT_R)\
 $(OBJ_CR_FtpSrch_windows_MT_R)\
 \

OBJ_CR_api_entryinfo_W_MT_D		= $(PROJ_OBJ_DIR)\api.entryinfo.widestring.mt.debug.obj
OBJ_CR_api_error_W_MT_D			= $(PROJ_OBJ_DIR)\api.error.widestring.mt.debug.obj
OBJ_CR_api_extended_W_MT_D		= $(PROJ_OBJ_DIR)\api.extended.widestring.mt.debug.obj
OBJ_CR_api_combpath_W_MT_D		= $(PROJ_OBJ_DIR)\api.combpath.widestring.mt.debug.obj
OBJ_CR_api_derrpath_W_MT_D		= $(PROJ_OBJ_DIR)\api.derrpath.widestring.mt.debug.obj
OBJ_CR_api_getflsizs_W_MT_D		= $(PROJ_OBJ_DIR)\api.getflsizs.widestring.mt.debug.obj
OBJ_CR_api_sqzpath_W_MT_D		= $(PROJ_OBJ_DIR)\api.sqzpath.widestring.mt.debug.obj
OBJ_CR_api_stat_W_MT_D			= $(PROJ_OBJ_DIR)\api.stat.widestring.mt.debug.obj
OBJ_CR_api_crdir_W_MT_D			= $(PROJ_OBJ_DIR)\api.crdir.widestring.mt.debug.obj
OBJ_CR_api_rc_win_W_MT_D		= $(PROJ_OBJ_DIR)\api.retcodes.windows.widestring.mt.debug.obj
OBJ_CR_api_rmdir_W_MT_D			= $(PROJ_OBJ_DIR)\api.rmdir.widestring.mt.debug.obj
OBJ_CR_api_search_W_MT_D		= $(PROJ_OBJ_DIR)\api.search.widestring.mt.debug.obj
OBJ_CR_impl_debug_W_MT_D		= $(PROJ_OBJ_DIR)\impl.trace.widestring.mt.debug.obj
OBJ_CR_impl_entryinfo_W_MT_D	= $(PROJ_OBJ_DIR)\impl.entryinfo.widestring.mt.debug.obj
OBJ_CR_impl_fileinfo_W_MT_D		= $(PROJ_OBJ_DIR)\impl.fileinfo.widestring.mt.debug.obj
OBJ_CR_impl_snprintf_W_MT_D		= $(PROJ_OBJ_DIR)\impl.snprintf.widestring.mt.debug.obj
OBJ_CR_impl_util_W_MT_D			= $(PROJ_OBJ_DIR)\impl.util.widestring.mt.debug.obj
OBJ_CR_Srch_W_MT_D				= $(PROJ_OBJ_DIR)\ReclsSearch.widestring.mt.debug.obj
OBJ_CR_FlSrch_W_MT_D			= $(PROJ_OBJ_DIR)\ReclsFileSearch.widestring.mt.debug.obj
OBJ_CR_FlSchDirNode_W_MT_D		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.widestring.mt.debug.obj
OBJ_CR_api_win64_W_MT_D				= $(PROJ_OBJ_DIR)\api.win64.widestring.mt.debug.obj
OBJ_CR_impl_fileinfo_win64_W_MT_D	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.widestring.mt.debug.obj
OBJ_CR_impl_util_win64_W_MT_D		= $(PROJ_OBJ_DIR)\impl.util.win64.widestring.mt.debug.obj
OBJ_CR_api_ftp_windows_W_MT_D	= $(PROJ_OBJ_DIR)\api.ftp.windows.widestring.mt.debug.obj
OBJ_CR_FtpSchDirNode_win_W_MT_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.widestring.mt.debug.obj
OBJ_CR_FtpSrch_windows_W_MT_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.widestring.mt.debug.obj



OBJ_CORE_W_MT_D=\
 $(OBJ_CR_api_entryinfo_W_MT_D)\
 $(OBJ_CR_api_error_W_MT_D)\
 $(OBJ_CR_api_extended_W_MT_D)\
 $(OBJ_CR_api_combpath_W_MT_D)\
 $(OBJ_CR_api_derrpath_W_MT_D)\
 $(OBJ_CR_api_getflsizs_W_MT_D)\
 $(OBJ_CR_api_sqzpath_W_MT_D)\
 $(OBJ_CR_api_stat_W_MT_D)\
 $(OBJ_CR_api_crdir_W_MT_D)\
 $(OBJ_CR_api_rmdir_W_MT_D)\
 $(OBJ_CR_api_rc_win_W_MT_D)\
 $(OBJ_CR_api_search_W_MT_D)\
 $(OBJ_CR_impl_debug_W_MT_D)\
 $(OBJ_CR_impl_entryinfo_W_MT_D)\
 $(OBJ_CR_impl_fileinfo_W_MT_D)\
 $(OBJ_CR_impl_snprintf_W_MT_D)\
 $(OBJ_CR_impl_util_W_MT_D)\
 $(OBJ_CR_Srch_W_MT_D)\
 $(OBJ_CR_FlSrch_W_MT_D)\
 $(OBJ_CR_FlSchDirNode_W_MT_D)\
 $(OBJ_CR_api_win64_W_MT_D)\
 $(OBJ_CR_impl_fileinfo_win64_W_MT_D)\
 $(OBJ_CR_impl_util_win64_W_MT_D)\
 $(OBJ_CR_api_ftp_windows_W_MT_D)\
 $(OBJ_CR_FtpSchDirNode_win_W_MT_D)\
 $(OBJ_CR_FtpSrch_windows_W_MT_D)\
 \

OBJ_CR_api_entryinfo_W_DLL_D		= $(PROJ_OBJ_DIR)\api.entryinfo.widestring.dll.debug.obj
OBJ_CR_api_error_W_DLL_D			= $(PROJ_OBJ_DIR)\api.error.widestring.dll.debug.obj
OBJ_CR_api_extended_W_DLL_D		= $(PROJ_OBJ_DIR)\api.extended.widestring.dll.debug.obj
OBJ_CR_api_combpath_W_DLL_D		= $(PROJ_OBJ_DIR)\api.combpath.widestring.dll.debug.obj
OBJ_CR_api_derrpath_W_DLL_D		= $(PROJ_OBJ_DIR)\api.derrpath.widestring.dll.debug.obj
OBJ_CR_api_getflsizs_W_DLL_D		= $(PROJ_OBJ_DIR)\api.getflsizs.widestring.dll.debug.obj
OBJ_CR_api_sqzpath_W_DLL_D		= $(PROJ_OBJ_DIR)\api.sqzpath.widestring.dll.debug.obj
OBJ_CR_api_stat_W_DLL_D			= $(PROJ_OBJ_DIR)\api.stat.widestring.dll.debug.obj
OBJ_CR_api_crdir_W_DLL_D			= $(PROJ_OBJ_DIR)\api.crdir.widestring.dll.debug.obj
OBJ_CR_api_rc_win_W_DLL_D		= $(PROJ_OBJ_DIR)\api.retcodes.windows.widestring.dll.debug.obj
OBJ_CR_api_rmdir_W_DLL_D			= $(PROJ_OBJ_DIR)\api.rmdir.widestring.dll.debug.obj
OBJ_CR_api_search_W_DLL_D		= $(PROJ_OBJ_DIR)\api.search.widestring.dll.debug.obj
OBJ_CR_impl_debug_W_DLL_D		= $(PROJ_OBJ_DIR)\impl.trace.widestring.dll.debug.obj
OBJ_CR_impl_entryinfo_W_DLL_D	= $(PROJ_OBJ_DIR)\impl.entryinfo.widestring.dll.debug.obj
OBJ_CR_impl_fileinfo_W_DLL_D		= $(PROJ_OBJ_DIR)\impl.fileinfo.widestring.dll.debug.obj
OBJ_CR_impl_snprintf_W_DLL_D		= $(PROJ_OBJ_DIR)\impl.snprintf.widestring.dll.debug.obj
OBJ_CR_impl_util_W_DLL_D			= $(PROJ_OBJ_DIR)\impl.util.widestring.dll.debug.obj
OBJ_CR_Srch_W_DLL_D				= $(PROJ_OBJ_DIR)\ReclsSearch.widestring.dll.debug.obj
OBJ_CR_FlSrch_W_DLL_D			= $(PROJ_OBJ_DIR)\ReclsFileSearch.widestring.dll.debug.obj
OBJ_CR_FlSchDirNode_W_DLL_D		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.widestring.dll.debug.obj
OBJ_CR_api_win64_W_DLL_D				= $(PROJ_OBJ_DIR)\api.win64.widestring.dll.debug.obj
OBJ_CR_impl_fileinfo_win64_W_DLL_D	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.widestring.dll.debug.obj
OBJ_CR_impl_util_win64_W_DLL_D		= $(PROJ_OBJ_DIR)\impl.util.win64.widestring.dll.debug.obj
OBJ_CR_api_ftp_windows_W_DLL_D	= $(PROJ_OBJ_DIR)\api.ftp.windows.widestring.dll.debug.obj
OBJ_CR_FtpSchDirNode_win_W_DLL_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.widestring.dll.debug.obj
OBJ_CR_FtpSrch_windows_W_DLL_D	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.widestring.dll.debug.obj



OBJ_CORE_W_DLL_D=\
 $(OBJ_CR_api_entryinfo_W_DLL_D)\
 $(OBJ_CR_api_error_W_DLL_D)\
 $(OBJ_CR_api_extended_W_DLL_D)\
 $(OBJ_CR_api_combpath_W_DLL_D)\
 $(OBJ_CR_api_derrpath_W_DLL_D)\
 $(OBJ_CR_api_getflsizs_W_DLL_D)\
 $(OBJ_CR_api_sqzpath_W_DLL_D)\
 $(OBJ_CR_api_stat_W_DLL_D)\
 $(OBJ_CR_api_crdir_W_DLL_D)\
 $(OBJ_CR_api_rmdir_W_DLL_D)\
 $(OBJ_CR_api_rc_win_W_DLL_D)\
 $(OBJ_CR_api_search_W_DLL_D)\
 $(OBJ_CR_impl_debug_W_DLL_D)\
 $(OBJ_CR_impl_entryinfo_W_DLL_D)\
 $(OBJ_CR_impl_fileinfo_W_DLL_D)\
 $(OBJ_CR_impl_snprintf_W_DLL_D)\
 $(OBJ_CR_impl_util_W_DLL_D)\
 $(OBJ_CR_Srch_W_DLL_D)\
 $(OBJ_CR_FlSrch_W_DLL_D)\
 $(OBJ_CR_FlSchDirNode_W_DLL_D)\
 $(OBJ_CR_api_win64_W_DLL_D)\
 $(OBJ_CR_impl_fileinfo_win64_W_DLL_D)\
 $(OBJ_CR_impl_util_win64_W_DLL_D)\
 $(OBJ_CR_api_ftp_windows_W_DLL_D)\
 $(OBJ_CR_FtpSchDirNode_win_W_DLL_D)\
 $(OBJ_CR_FtpSrch_windows_W_DLL_D)\
 \

OBJ_CR_api_entryinfo_W_DLL_R		= $(PROJ_OBJ_DIR)\api.entryinfo.widestring.dll.obj
OBJ_CR_api_error_W_DLL_R			= $(PROJ_OBJ_DIR)\api.error.widestring.dll.obj
OBJ_CR_api_extended_W_DLL_R		= $(PROJ_OBJ_DIR)\api.extended.widestring.dll.obj
OBJ_CR_api_combpath_W_DLL_R		= $(PROJ_OBJ_DIR)\api.combpath.widestring.dll.obj
OBJ_CR_api_derrpath_W_DLL_R		= $(PROJ_OBJ_DIR)\api.derrpath.widestring.dll.obj
OBJ_CR_api_getflsizs_W_DLL_R		= $(PROJ_OBJ_DIR)\api.getflsizs.widestring.dll.obj
OBJ_CR_api_sqzpath_W_DLL_R		= $(PROJ_OBJ_DIR)\api.sqzpath.widestring.dll.obj
OBJ_CR_api_stat_W_DLL_R			= $(PROJ_OBJ_DIR)\api.stat.widestring.dll.obj
OBJ_CR_api_crdir_W_DLL_R			= $(PROJ_OBJ_DIR)\api.crdir.widestring.dll.obj
OBJ_CR_api_rc_win_W_DLL_R		= $(PROJ_OBJ_DIR)\api.retcodes.windows.widestring.dll.obj
OBJ_CR_api_rmdir_W_DLL_R			= $(PROJ_OBJ_DIR)\api.rmdir.widestring.dll.obj
OBJ_CR_api_search_W_DLL_R		= $(PROJ_OBJ_DIR)\api.search.widestring.dll.obj
OBJ_CR_impl_debug_W_DLL_R		= $(PROJ_OBJ_DIR)\impl.trace.widestring.dll.obj
OBJ_CR_impl_entryinfo_W_DLL_R	= $(PROJ_OBJ_DIR)\impl.entryinfo.widestring.dll.obj
OBJ_CR_impl_fileinfo_W_DLL_R		= $(PROJ_OBJ_DIR)\impl.fileinfo.widestring.dll.obj
OBJ_CR_impl_snprintf_W_DLL_R		= $(PROJ_OBJ_DIR)\impl.snprintf.widestring.dll.obj
OBJ_CR_impl_util_W_DLL_R			= $(PROJ_OBJ_DIR)\impl.util.widestring.dll.obj
OBJ_CR_Srch_W_DLL_R				= $(PROJ_OBJ_DIR)\ReclsSearch.widestring.dll.obj
OBJ_CR_FlSrch_W_DLL_R			= $(PROJ_OBJ_DIR)\ReclsFileSearch.widestring.dll.obj
OBJ_CR_FlSchDirNode_W_DLL_R		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.widestring.dll.obj
OBJ_CR_api_win64_W_DLL_R				= $(PROJ_OBJ_DIR)\api.win64.widestring.dll.obj
OBJ_CR_impl_fileinfo_win64_W_DLL_R	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.widestring.dll.obj
OBJ_CR_impl_util_win64_W_DLL_R		= $(PROJ_OBJ_DIR)\impl.util.win64.widestring.dll.obj
OBJ_CR_api_ftp_windows_W_DLL_R	= $(PROJ_OBJ_DIR)\api.ftp.windows.widestring.dll.obj
OBJ_CR_FtpSchDirNode_win_W_DLL_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.widestring.dll.obj
OBJ_CR_FtpSrch_windows_W_DLL_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.widestring.dll.obj



OBJ_CORE_W_DLL_R=\
 $(OBJ_CR_api_entryinfo_W_DLL_R)\
 $(OBJ_CR_api_error_W_DLL_R)\
 $(OBJ_CR_api_extended_W_DLL_R)\
 $(OBJ_CR_api_combpath_W_DLL_R)\
 $(OBJ_CR_api_derrpath_W_DLL_R)\
 $(OBJ_CR_api_getflsizs_W_DLL_R)\
 $(OBJ_CR_api_sqzpath_W_DLL_R)\
 $(OBJ_CR_api_stat_W_DLL_R)\
 $(OBJ_CR_api_crdir_W_DLL_R)\
 $(OBJ_CR_api_rmdir_W_DLL_R)\
 $(OBJ_CR_api_rc_win_W_DLL_R)\
 $(OBJ_CR_api_search_W_DLL_R)\
 $(OBJ_CR_impl_debug_W_DLL_R)\
 $(OBJ_CR_impl_entryinfo_W_DLL_R)\
 $(OBJ_CR_impl_fileinfo_W_DLL_R)\
 $(OBJ_CR_impl_snprintf_W_DLL_R)\
 $(OBJ_CR_impl_util_W_DLL_R)\
 $(OBJ_CR_Srch_W_DLL_R)\
 $(OBJ_CR_FlSrch_W_DLL_R)\
 $(OBJ_CR_FlSchDirNode_W_DLL_R)\
 $(OBJ_CR_api_win64_W_DLL_R)\
 $(OBJ_CR_impl_fileinfo_win64_W_DLL_R)\
 $(OBJ_CR_impl_util_win64_W_DLL_R)\
 $(OBJ_CR_api_ftp_windows_W_DLL_R)\
 $(OBJ_CR_FtpSchDirNode_win_W_DLL_R)\
 $(OBJ_CR_FtpSrch_windows_W_DLL_R)\
 \

OBJ_CR_api_entryinfo_W_MT_R		= $(PROJ_OBJ_DIR)\api.entryinfo.widestring.mt.obj
OBJ_CR_api_error_W_MT_R			= $(PROJ_OBJ_DIR)\api.error.widestring.mt.obj
OBJ_CR_api_extended_W_MT_R		= $(PROJ_OBJ_DIR)\api.extended.widestring.mt.obj
OBJ_CR_api_combpath_W_MT_R		= $(PROJ_OBJ_DIR)\api.combpath.widestring.mt.obj
OBJ_CR_api_derrpath_W_MT_R		= $(PROJ_OBJ_DIR)\api.derrpath.widestring.mt.obj
OBJ_CR_api_getflsizs_W_MT_R		= $(PROJ_OBJ_DIR)\api.getflsizs.widestring.mt.obj
OBJ_CR_api_sqzpath_W_MT_R		= $(PROJ_OBJ_DIR)\api.sqzpath.widestring.mt.obj
OBJ_CR_api_stat_W_MT_R			= $(PROJ_OBJ_DIR)\api.stat.widestring.mt.obj
OBJ_CR_api_crdir_W_MT_R			= $(PROJ_OBJ_DIR)\api.crdir.widestring.mt.obj
OBJ_CR_api_rc_win_W_MT_R		= $(PROJ_OBJ_DIR)\api.retcodes.windows.widestring.mt.obj
OBJ_CR_api_rmdir_W_MT_R			= $(PROJ_OBJ_DIR)\api.rmdir.widestring.mt.obj
OBJ_CR_api_search_W_MT_R		= $(PROJ_OBJ_DIR)\api.search.widestring.mt.obj
OBJ_CR_impl_debug_W_MT_R		= $(PROJ_OBJ_DIR)\impl.trace.widestring.mt.obj
OBJ_CR_impl_entryinfo_W_MT_R	= $(PROJ_OBJ_DIR)\impl.entryinfo.widestring.mt.obj
OBJ_CR_impl_fileinfo_W_MT_R		= $(PROJ_OBJ_DIR)\impl.fileinfo.widestring.mt.obj
OBJ_CR_impl_snprintf_W_MT_R		= $(PROJ_OBJ_DIR)\impl.snprintf.widestring.mt.obj
OBJ_CR_impl_util_W_MT_R			= $(PROJ_OBJ_DIR)\impl.util.widestring.mt.obj
OBJ_CR_Srch_W_MT_R				= $(PROJ_OBJ_DIR)\ReclsSearch.widestring.mt.obj
OBJ_CR_FlSrch_W_MT_R			= $(PROJ_OBJ_DIR)\ReclsFileSearch.widestring.mt.obj
OBJ_CR_FlSchDirNode_W_MT_R		= $(PROJ_OBJ_DIR)\ReclsFileSearchDirectoryNode.widestring.mt.obj
OBJ_CR_api_win64_W_MT_R				= $(PROJ_OBJ_DIR)\api.win64.widestring.mt.obj
OBJ_CR_impl_fileinfo_win64_W_MT_R	= $(PROJ_OBJ_DIR)\impl.fileinfo.win64.widestring.mt.obj
OBJ_CR_impl_util_win64_W_MT_R		= $(PROJ_OBJ_DIR)\impl.util.win64.widestring.mt.obj
OBJ_CR_api_ftp_windows_W_MT_R	= $(PROJ_OBJ_DIR)\api.ftp.windows.widestring.mt.obj
OBJ_CR_FtpSchDirNode_win_W_MT_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearchDirectoryNode_windows.widestring.mt.obj
OBJ_CR_FtpSrch_windows_W_MT_R	= $(PROJ_OBJ_DIR)\ReclsFtpSearch_windows.widestring.mt.obj



OBJ_CORE_W_MT_R=\
 $(OBJ_CR_api_entryinfo_W_MT_R)\
 $(OBJ_CR_api_error_W_MT_R)\
 $(OBJ_CR_api_extended_W_MT_R)\
 $(OBJ_CR_api_combpath_W_MT_R)\
 $(OBJ_CR_api_derrpath_W_MT_R)\
 $(OBJ_CR_api_getflsizs_W_MT_R)\
 $(OBJ_CR_api_sqzpath_W_MT_R)\
 $(OBJ_CR_api_stat_W_MT_R)\
 $(OBJ_CR_api_crdir_W_MT_R)\
 $(OBJ_CR_api_rmdir_W_MT_R)\
 $(OBJ_CR_api_rc_win_W_MT_R)\
 $(OBJ_CR_api_search_W_MT_R)\
 $(OBJ_CR_impl_debug_W_MT_R)\
 $(OBJ_CR_impl_entryinfo_W_MT_R)\
 $(OBJ_CR_impl_fileinfo_W_MT_R)\
 $(OBJ_CR_impl_snprintf_W_MT_R)\
 $(OBJ_CR_impl_util_W_MT_R)\
 $(OBJ_CR_Srch_W_MT_R)\
 $(OBJ_CR_FlSrch_W_MT_R)\
 $(OBJ_CR_FlSchDirNode_W_MT_R)\
 $(OBJ_CR_api_win64_W_MT_R)\
 $(OBJ_CR_impl_fileinfo_win64_W_MT_R)\
 $(OBJ_CR_impl_util_win64_W_MT_R)\
 $(OBJ_CR_api_ftp_windows_W_MT_R)\
 $(OBJ_CR_FtpSchDirNode_win_W_MT_R)\
 $(OBJ_CR_FtpSrch_windows_W_MT_R)\
 \


# shwild

OBJ_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.debug.obj
OBJ_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.debug.obj
OBJ_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.debug.obj
PDB_shw_api_MT_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.debug.pdb
PDB_shw_matches_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.debug.pdb
PDB_shw_pattern_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.debug.pdb

OBJ_SHWILD_MT_D=\
 $(OBJ_shw_api_MT_D)\
 $(OBJ_shw_matches_MT_D)\
 $(OBJ_shw_pattern_MT_D)\
 \

PDB_SHWILD_MT_D=\
 $(PDB_shw_api_MT_D)\
 $(PDB_shw_matches_MT_D)\
 $(PDB_shw_pattern_MT_D)\
 \

OBJ_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.dll.debug.obj
OBJ_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.dll.debug.obj
OBJ_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.dll.debug.obj
PDB_shw_api_DLL_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.dll.debug.pdb
PDB_shw_matches_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.dll.debug.pdb
PDB_shw_pattern_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.dll.debug.pdb

OBJ_SHWILD_DLL_D=\
 $(OBJ_shw_api_DLL_D)\
 $(OBJ_shw_matches_DLL_D)\
 $(OBJ_shw_pattern_DLL_D)\
 \

PDB_SHWILD_DLL_D=\
 $(PDB_shw_api_DLL_D)\
 $(PDB_shw_matches_DLL_D)\
 $(PDB_shw_pattern_DLL_D)\
 \

OBJ_shw_api_DLL_R            = $(PROJ_OBJ_DIR)\shwild.recls.api.dll.obj
OBJ_shw_matches_DLL_R        = $(PROJ_OBJ_DIR)\shwild.recls.matches.dll.obj
OBJ_shw_pattern_DLL_R        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.dll.obj

OBJ_SHWILD_DLL_R=\
 $(OBJ_shw_api_DLL_R)\
 $(OBJ_shw_matches_DLL_R)\
 $(OBJ_shw_pattern_DLL_R)\
 \

OBJ_shw_api_MT_R            = $(PROJ_OBJ_DIR)\shwild.recls.api.mt.obj
OBJ_shw_matches_MT_R        = $(PROJ_OBJ_DIR)\shwild.recls.matches.mt.obj
OBJ_shw_pattern_MT_R        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.mt.obj

OBJ_SHWILD_MT_R=\
 $(OBJ_shw_api_MT_R)\
 $(OBJ_shw_matches_MT_R)\
 $(OBJ_shw_pattern_MT_R)\
 \

OBJ_shw_api_W_MT_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.mt.debug.obj
OBJ_shw_matches_W_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.mt.debug.obj
OBJ_shw_pattern_W_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.mt.debug.obj
PDB_shw_api_W_MT_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.mt.debug.pdb
PDB_shw_matches_W_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.mt.debug.pdb
PDB_shw_pattern_W_MT_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.mt.debug.pdb

OBJ_SHWILD_W_MT_D=\
 $(OBJ_shw_api_W_MT_D)\
 $(OBJ_shw_matches_W_MT_D)\
 $(OBJ_shw_pattern_W_MT_D)\
 \

PDB_SHWILD_W_MT_D=\
 $(PDB_shw_api_W_MT_D)\
 $(PDB_shw_matches_W_MT_D)\
 $(PDB_shw_pattern_W_MT_D)\
 \

OBJ_shw_api_W_DLL_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.dll.debug.obj
OBJ_shw_matches_W_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.dll.debug.obj
OBJ_shw_pattern_W_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.dll.debug.obj
PDB_shw_api_W_DLL_D            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.dll.debug.pdb
PDB_shw_matches_W_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.dll.debug.pdb
PDB_shw_pattern_W_DLL_D        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.dll.debug.pdb

OBJ_SHWILD_W_DLL_D=\
 $(OBJ_shw_api_W_DLL_D)\
 $(OBJ_shw_matches_W_DLL_D)\
 $(OBJ_shw_pattern_W_DLL_D)\
 \

PDB_SHWILD_W_DLL_D=\
 $(PDB_shw_api_W_DLL_D)\
 $(PDB_shw_matches_W_DLL_D)\
 $(PDB_shw_pattern_W_DLL_D)\
 \

OBJ_shw_api_W_DLL_R            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.dll.obj
OBJ_shw_matches_W_DLL_R        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.dll.obj
OBJ_shw_pattern_W_DLL_R        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.dll.obj

OBJ_SHWILD_W_DLL_R=\
 $(OBJ_shw_api_W_DLL_R)\
 $(OBJ_shw_matches_W_DLL_R)\
 $(OBJ_shw_pattern_W_DLL_R)\
 \

OBJ_shw_api_W_MT_R            = $(PROJ_OBJ_DIR)\shwild.recls.api.widestring.mt.obj
OBJ_shw_matches_W_MT_R        = $(PROJ_OBJ_DIR)\shwild.recls.matches.widestring.mt.obj
OBJ_shw_pattern_W_MT_R        = $(PROJ_OBJ_DIR)\shwild.recls.pattern.widestring.mt.obj

OBJ_SHWILD_W_MT_R=\
 $(OBJ_shw_api_W_MT_R)\
 $(OBJ_shw_matches_W_MT_R)\
 $(OBJ_shw_pattern_W_MT_R)\
 \


# xCover

OBJ_xcv_core_MT_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.mt.debug.obj
PDB_xcv_core_MT_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.mt.debug.pdb

OBJ_XCOVER_MT_D=\
 $(OBJ_xcv_core_MT_D)\
 \

PDB_CORE_MT_D=\
 $(PDB_xcv_core_MT_D)\
 \

OBJ_xcv_core_DLL_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.dll.debug.obj
PDB_xcv_core_DLL_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.dll.debug.pdb

OBJ_XCOVER_DLL_D=\
 $(OBJ_xcv_core_DLL_D)\
 \

PDB_CORE_DLL_D=\
 $(PDB_xcv_core_DLL_D)\
 \

OBJ_xcv_core_DLL_R           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.dll.obj

OBJ_XCOVER_DLL_R=\
 $(OBJ_xcv_core_DLL_R)\
 \

OBJ_xcv_core_MT_R           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.mt.obj

OBJ_XCOVER_MT_R=\
 $(OBJ_xcv_core_MT_R)\
 \

OBJ_xcv_core_W_MT_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.mt.debug.obj
PDB_xcv_core_W_MT_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.mt.debug.pdb

OBJ_XCOVER_W_MT_D=\
 $(OBJ_xcv_core_W_MT_D)\
 \

PDB_CORE_W_MT_D=\
 $(PDB_xcv_core_W_MT_D)\
 \

OBJ_xcv_core_W_DLL_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.dll.debug.obj
PDB_xcv_core_W_DLL_D           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.dll.debug.pdb

OBJ_XCOVER_W_DLL_D=\
 $(OBJ_xcv_core_W_DLL_D)\
 \

PDB_CORE_W_DLL_D=\
 $(PDB_xcv_core_W_DLL_D)\
 \

OBJ_xcv_core_W_DLL_R           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.dll.obj

OBJ_XCOVER_W_DLL_R=\
 $(OBJ_xcv_core_W_DLL_R)\
 \

OBJ_xcv_core_W_MT_R           = $(PROJ_OBJ_DIR)\xcover.recls.core.api.widestring.mt.obj

OBJ_XCOVER_W_MT_R=\
 $(OBJ_xcv_core_W_MT_R)\
 \


# xtests

OBJ_xts_core_MT_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.debug.obj
PDB_xts_core_MT_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.debug.pdb

OBJ_XTESTS_MT_D=\
 $(OBJ_xts_core_MT_D)\
 \

PDB_CORE_MT_D=\
 $(PDB_xts_core_MT_D)\
 \

OBJ_xts_core_DLL_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.dll.debug.obj
PDB_xts_core_DLL_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.dll.debug.pdb

OBJ_XTESTS_DLL_D=\
 $(OBJ_xts_core_DLL_D)\
 \

PDB_CORE_DLL_D=\
 $(PDB_xts_core_DLL_D)\
 \

OBJ_xts_core_DLL_R           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.dll.obj

OBJ_XTESTS_DLL_R=\
 $(OBJ_xts_core_DLL_R)\
 \

OBJ_xts_core_MT_R           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.mt.obj

OBJ_XTESTS_MT_R=\
 $(OBJ_xts_core_MT_R)\
 \

OBJ_xts_core_W_MT_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.mt.debug.obj
PDB_xts_core_W_MT_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.mt.debug.pdb

OBJ_XTESTS_W_MT_D=\
 $(OBJ_xts_core_W_MT_D)\
 \

PDB_CORE_W_MT_D=\
 $(PDB_xts_core_W_MT_D)\
 \

OBJ_xts_core_W_DLL_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.dll.debug.obj
PDB_xts_core_W_DLL_D           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.dll.debug.pdb

OBJ_XTESTS_W_DLL_D=\
 $(OBJ_xts_core_W_DLL_D)\
 \

PDB_CORE_W_DLL_D=\
 $(PDB_xts_core_W_DLL_D)\
 \

OBJ_xts_core_W_DLL_R           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.dll.obj

OBJ_XTESTS_W_DLL_R=\
 $(OBJ_xts_core_W_DLL_R)\
 \

OBJ_xts_core_W_MT_R           = $(PROJ_OBJ_DIR)\xtests.recls.core.api.widestring.mt.obj

OBJ_XTESTS_W_MT_R=\
 $(OBJ_xts_core_W_MT_R)\
 \


########################################
# Examples

OBJ_EX_ex_c_1_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.mt.debug.obj
OBJ_EX_ex_c_2_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.mt.debug.obj
OBJ_EX_ex_c_3_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.mt.debug.obj
OBJ_EX_ex_c_4_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.mt.debug.obj
OBJ_EX_ex_c_5_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.mt.debug.obj
OBJ_EX_ex_c_6_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.mt.debug.obj
OBJ_EX_ex_c_7_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.mt.debug.obj
OBJ_EX_ex_c_8_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.mt.debug.obj
OBJ_EX_ex_c_1_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.dll.debug.obj
OBJ_EX_ex_c_2_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.dll.debug.obj
OBJ_EX_ex_c_3_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.dll.debug.obj
OBJ_EX_ex_c_4_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.dll.debug.obj
OBJ_EX_ex_c_5_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.dll.debug.obj
OBJ_EX_ex_c_6_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.dll.debug.obj
OBJ_EX_ex_c_7_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.dll.debug.obj
OBJ_EX_ex_c_8_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.dll.debug.obj
OBJ_EX_ex_c_1_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.dll.obj
OBJ_EX_ex_c_2_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.dll.obj
OBJ_EX_ex_c_3_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.dll.obj
OBJ_EX_ex_c_4_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.dll.obj
OBJ_EX_ex_c_5_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.dll.obj
OBJ_EX_ex_c_6_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.dll.obj
OBJ_EX_ex_c_7_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.dll.obj
OBJ_EX_ex_c_8_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.dll.obj
OBJ_EX_ex_c_1_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.mt.obj
OBJ_EX_ex_c_2_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.mt.obj
OBJ_EX_ex_c_3_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.mt.obj
OBJ_EX_ex_c_4_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.mt.obj
OBJ_EX_ex_c_5_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.mt.obj
OBJ_EX_ex_c_6_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.mt.obj
OBJ_EX_ex_c_7_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.mt.obj
OBJ_EX_ex_c_8_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.mt.obj
OBJ_EX_ex_c_1_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.widestring.mt.debug.obj
OBJ_EX_ex_c_2_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.widestring.mt.debug.obj
OBJ_EX_ex_c_3_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.widestring.mt.debug.obj
OBJ_EX_ex_c_4_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.widestring.mt.debug.obj
OBJ_EX_ex_c_5_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.widestring.mt.debug.obj
OBJ_EX_ex_c_6_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.widestring.mt.debug.obj
OBJ_EX_ex_c_7_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.widestring.mt.debug.obj
OBJ_EX_ex_c_8_W_MT_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.widestring.mt.debug.obj
OBJ_EX_ex_c_1_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.widestring.dll.debug.obj
OBJ_EX_ex_c_2_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.widestring.dll.debug.obj
OBJ_EX_ex_c_3_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.widestring.dll.debug.obj
OBJ_EX_ex_c_4_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.widestring.dll.debug.obj
OBJ_EX_ex_c_5_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.widestring.dll.debug.obj
OBJ_EX_ex_c_6_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.widestring.dll.debug.obj
OBJ_EX_ex_c_7_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.widestring.dll.debug.obj
OBJ_EX_ex_c_8_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.widestring.dll.debug.obj
OBJ_EX_ex_c_1_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.widestring.dll.obj
OBJ_EX_ex_c_2_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.widestring.dll.obj
OBJ_EX_ex_c_3_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.widestring.dll.obj
OBJ_EX_ex_c_4_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.widestring.dll.obj
OBJ_EX_ex_c_5_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.widestring.dll.obj
OBJ_EX_ex_c_6_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.widestring.dll.obj
OBJ_EX_ex_c_7_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.widestring.dll.obj
OBJ_EX_ex_c_8_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.widestring.dll.obj
OBJ_EX_ex_c_1_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_1.widestring.mt.obj
OBJ_EX_ex_c_2_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_2.widestring.mt.obj
OBJ_EX_ex_c_3_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_3.widestring.mt.obj
OBJ_EX_ex_c_4_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_4.widestring.mt.obj
OBJ_EX_ex_c_5_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_5.widestring.mt.obj
OBJ_EX_ex_c_6_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_6.widestring.mt.obj
OBJ_EX_ex_c_7_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_7.widestring.mt.obj
OBJ_EX_ex_c_8_W_MT_R =   $(PROJ_OBJ_DIR)\ex.c.example_c_8.widestring.mt.obj

OBJ_EX_ex_cpp_1_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.mt.debug.obj
OBJ_EX_ex_cpp_2_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.mt.debug.obj
OBJ_EX_ex_cpp_3_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.mt.debug.obj
OBJ_EX_ex_cpp_1_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.dll.debug.obj
OBJ_EX_ex_cpp_2_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.dll.debug.obj
OBJ_EX_ex_cpp_3_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.dll.debug.obj
OBJ_EX_ex_cpp_1_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.dll.obj
OBJ_EX_ex_cpp_2_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.dll.obj
OBJ_EX_ex_cpp_3_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.dll.obj
OBJ_EX_ex_cpp_1_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.mt.obj
OBJ_EX_ex_cpp_2_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.mt.obj
OBJ_EX_ex_cpp_3_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.mt.obj
OBJ_EX_ex_cpp_1_W_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.widestring.mt.debug.obj
OBJ_EX_ex_cpp_2_W_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.widestring.mt.debug.obj
OBJ_EX_ex_cpp_3_W_MT_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.widestring.mt.debug.obj
OBJ_EX_ex_cpp_1_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.widestring.dll.debug.obj
OBJ_EX_ex_cpp_2_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.widestring.dll.debug.obj
OBJ_EX_ex_cpp_3_W_DLL_D =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.widestring.dll.debug.obj
OBJ_EX_ex_cpp_1_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.widestring.dll.obj
OBJ_EX_ex_cpp_2_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.widestring.dll.obj
OBJ_EX_ex_cpp_3_W_DLL_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.widestring.dll.obj
OBJ_EX_ex_cpp_1_W_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_1.widestring.mt.obj
OBJ_EX_ex_cpp_2_W_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_2.widestring.mt.obj
OBJ_EX_ex_cpp_3_W_MT_R =   $(PROJ_OBJ_DIR)\ex.cpp.example_cpp_3.widestring.mt.obj

########################################
# Tests

##############################
# Component Tests

OBJ_TEST_COMP_api_crdir_MT_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.mt.debug.obj
OBJ_TEST_COMP_api_rmdir_MT_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.mt.debug.obj
OBJ_TEST_COMP_api_crdir_DLL_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.dll.debug.obj
OBJ_TEST_COMP_api_rmdir_DLL_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.dll.debug.obj
OBJ_TEST_COMP_api_crdir_DLL_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.dll.obj
OBJ_TEST_COMP_api_rmdir_DLL_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.dll.obj
OBJ_TEST_COMP_api_crdir_MT_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.mt.obj
OBJ_TEST_COMP_api_rmdir_MT_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.mt.obj
OBJ_TEST_COMP_api_crdir_W_MT_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.widestring.mt.debug.obj
OBJ_TEST_COMP_api_rmdir_W_MT_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.widestring.mt.debug.obj
OBJ_TEST_COMP_api_crdir_W_DLL_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.widestring.dll.debug.obj
OBJ_TEST_COMP_api_rmdir_W_DLL_D =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.widestring.dll.debug.obj
OBJ_TEST_COMP_api_crdir_W_DLL_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.widestring.dll.obj
OBJ_TEST_COMP_api_rmdir_W_DLL_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.widestring.dll.obj
OBJ_TEST_COMP_api_crdir_W_MT_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.create_directory.widestring.mt.obj
OBJ_TEST_COMP_api_rmdir_W_MT_R =   $(PROJ_OBJ_DIR)\test.component.util.cpp.remove_directory.widestring.mt.obj

##############################
# Scratch Tests

OBJ_TEST_SCRT_srch1_MT_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.mt.debug.obj
OBJ_TEST_SCRT_srch2_MT_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.mt.debug.obj
OBJ_TEST_SCRT_srch1_DLL_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.dll.debug.obj
OBJ_TEST_SCRT_srch2_DLL_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.dll.debug.obj
OBJ_TEST_SCRT_srch1_DLL_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.dll.obj
OBJ_TEST_SCRT_srch2_DLL_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.dll.obj
OBJ_TEST_SCRT_srch1_MT_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.mt.obj
OBJ_TEST_SCRT_srch2_MT_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.mt.obj
OBJ_TEST_SCRT_srch1_W_MT_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.widestring.mt.debug.obj
OBJ_TEST_SCRT_srch2_W_MT_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.widestring.mt.debug.obj
OBJ_TEST_SCRT_srch1_W_DLL_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.widestring.dll.debug.obj
OBJ_TEST_SCRT_srch2_W_DLL_D   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.widestring.dll.debug.obj
OBJ_TEST_SCRT_srch1_W_DLL_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.widestring.dll.obj
OBJ_TEST_SCRT_srch2_W_DLL_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.widestring.dll.obj
OBJ_TEST_SCRT_srch1_W_MT_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.1.widestring.mt.obj
OBJ_TEST_SCRT_srch2_W_MT_R   =   $(PROJ_OBJ_DIR)\test.scratch.search.2.widestring.mt.obj

##############################
# Unit Tests

OBJ_TEST_UNIT_api_cmbpaths_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_api_drvrel_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_api_sqzpath_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.mt.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.mt.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.mt.debug.obj
OBJ_TEST_UNIT_c_retcodes_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.mt.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.dll.debug.obj
OBJ_TEST_UNIT_api_drvrel_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.dll.debug.obj
OBJ_TEST_UNIT_api_sqzpath_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.dll.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.dll.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.dll.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.dll.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.dll.debug.obj
OBJ_TEST_UNIT_c_retcodes_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.dll.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.dll.obj
OBJ_TEST_UNIT_api_drvrel_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.dll.obj
OBJ_TEST_UNIT_api_sqzpath_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.dll.obj
OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.dll.obj
OBJ_TEST_UNIT_cpp_drvrel_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.dll.obj
OBJ_TEST_UNIT_cpp_sqzpath_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.dll.obj
OBJ_TEST_UNIT_cpp_retcodes_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.dll.obj
OBJ_TEST_UNIT_c_retcodes_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.dll.obj
OBJ_TEST_UNIT_api_cmbpaths_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.mt.obj
OBJ_TEST_UNIT_api_drvrel_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.mt.obj
OBJ_TEST_UNIT_api_sqzpath_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_cmbpaths_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.mt.obj
OBJ_TEST_UNIT_cpp_drvrel_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.mt.obj
OBJ_TEST_UNIT_cpp_sqzpath_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.mt.obj
OBJ_TEST_UNIT_cpp_retcodes_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.mt.obj
OBJ_TEST_UNIT_c_retcodes_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.mt.obj
OBJ_TEST_UNIT_api_cmbpaths_W_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_drvrel_W_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_sqzpath_W_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.widestring.mt.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.widestring.mt.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_W_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.widestring.mt.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.widestring.mt.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_W_MT_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.widestring.mt.debug.obj
OBJ_TEST_UNIT_c_retcodes_W_MT_D		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.widestring.mt.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_drvrel_W_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_sqzpath_W_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.widestring.dll.debug.obj
OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.widestring.dll.debug.obj
OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.widestring.dll.debug.obj
OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.widestring.dll.debug.obj
OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.widestring.dll.debug.obj
OBJ_TEST_UNIT_c_retcodes_W_DLL_D		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.widestring.dll.debug.obj
OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.widestring.dll.obj
OBJ_TEST_UNIT_api_drvrel_W_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.widestring.dll.obj
OBJ_TEST_UNIT_api_sqzpath_W_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.widestring.dll.obj
OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.widestring.dll.obj
OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.widestring.dll.obj
OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.widestring.dll.obj
OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.widestring.dll.obj
OBJ_TEST_UNIT_c_retcodes_W_DLL_R		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.widestring.dll.obj
OBJ_TEST_UNIT_api_cmbpaths_W_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.combine_paths.widestring.mt.obj
OBJ_TEST_UNIT_api_drvrel_W_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.api.derive_relative_path.widestring.mt.obj
OBJ_TEST_UNIT_api_sqzpath_W_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.api.squeeze_path.widestring.mt.obj
OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.combine_paths.widestring.mt.obj
OBJ_TEST_UNIT_cpp_drvrel_W_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.cpp.derive_relative_path.widestring.mt.obj
OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.squeeze_path.widestring.mt.obj
OBJ_TEST_UNIT_cpp_retcodes_W_MT_R	=   $(PROJ_OBJ_DIR)\test.unit.cpp.retcodes.widestring.mt.obj
OBJ_TEST_UNIT_c_retcodes_W_MT_R		=   $(PROJ_OBJ_DIR)\test.unit.c.retcodes.widestring.mt.obj

##################################################
# Target groups

########################################
# Objects

# recls
OBJS_CORE=\
 $(OBJ_CORE_MT_D)\
 $(OBJ_CORE_DLL_D)\
 $(OBJ_CORE_DLL_R)\
 $(OBJ_CORE_MT_R)\
 $(OBJ_CORE_W_MT_D)\
 $(OBJ_CORE_W_DLL_D)\
 $(OBJ_CORE_W_DLL_R)\
 $(OBJ_CORE_W_MT_R)\
 \

# shwild
OBJS_SHWILD=\
 $(OBJ_SHWILD_MT_D)\
 $(OBJ_SHWILD_DLL_D)\
 $(OBJ_SHWILD_DLL_R)\
 $(OBJ_SHWILD_MT_R)\
 $(OBJ_SHWILD_W_MT_D)\
 $(OBJ_SHWILD_W_DLL_D)\
 $(OBJ_SHWILD_W_DLL_R)\
 $(OBJ_SHWILD_W_MT_R)\
 \

# xcover
OBJS_XCOVER=\
 $(OBJ_XCOVER_MT_D)\
 $(OBJ_XCOVER_DLL_D)\
 $(OBJ_XCOVER_DLL_R)\
 $(OBJ_XCOVER_MT_R)\
 $(OBJ_XCOVER_W_MT_D)\
 $(OBJ_XCOVER_W_DLL_D)\
 $(OBJ_XCOVER_W_DLL_R)\
 $(OBJ_XCOVER_W_MT_R)\
 \

# xtests
OBJS_XTESTS=\
 $(OBJ_XTESTS_MT_D)\
 $(OBJ_XTESTS_DLL_D)\
 $(OBJ_XTESTS_DLL_R)\
 $(OBJ_XTESTS_MT_R)\
 $(OBJ_XTESTS_W_MT_D)\
 $(OBJ_XTESTS_W_DLL_D)\
 $(OBJ_XTESTS_W_DLL_R)\
 $(OBJ_XTESTS_W_MT_R)\
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
 $(OBJ_EX_ex_c_1_DLL_D)\
 $(OBJ_EX_ex_c_2_DLL_D)\
 $(OBJ_EX_ex_c_3_DLL_D)\
 $(OBJ_EX_ex_c_4_DLL_D)\
 $(OBJ_EX_ex_c_5_DLL_D)\
 $(OBJ_EX_ex_c_6_DLL_D)\
 $(OBJ_EX_ex_c_7_DLL_D)\
 $(OBJ_EX_ex_c_8_DLL_D)\
 $(OBJ_EX_ex_cpp_1_DLL_D)\
 $(OBJ_EX_ex_cpp_2_DLL_D)\
 $(OBJ_EX_ex_cpp_3_DLL_D)\
 $(OBJ_EX_ex_c_1_DLL_R)\
 $(OBJ_EX_ex_c_2_DLL_R)\
 $(OBJ_EX_ex_c_3_DLL_R)\
 $(OBJ_EX_ex_c_4_DLL_R)\
 $(OBJ_EX_ex_c_5_DLL_R)\
 $(OBJ_EX_ex_c_6_DLL_R)\
 $(OBJ_EX_ex_c_7_DLL_R)\
 $(OBJ_EX_ex_c_8_DLL_R)\
 $(OBJ_EX_ex_cpp_1_DLL_R)\
 $(OBJ_EX_ex_cpp_2_DLL_R)\
 $(OBJ_EX_ex_cpp_3_DLL_R)\
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
 $(OBJ_EX_ex_c_1_W_MT_D)\
 $(OBJ_EX_ex_c_2_W_MT_D)\
 $(OBJ_EX_ex_c_3_W_MT_D)\
 $(OBJ_EX_ex_c_4_W_MT_D)\
 $(OBJ_EX_ex_c_5_W_MT_D)\
 $(OBJ_EX_ex_c_6_W_MT_D)\
 $(OBJ_EX_ex_c_7_W_MT_D)\
 $(OBJ_EX_ex_c_8_W_MT_D)\
 $(OBJ_EX_ex_cpp_1_W_MT_D)\
 $(OBJ_EX_ex_cpp_2_W_MT_D)\
 $(OBJ_EX_ex_cpp_3_W_MT_D)\
 $(OBJ_EX_ex_c_1_W_DLL_D)\
 $(OBJ_EX_ex_c_2_W_DLL_D)\
 $(OBJ_EX_ex_c_3_W_DLL_D)\
 $(OBJ_EX_ex_c_4_W_DLL_D)\
 $(OBJ_EX_ex_c_5_W_DLL_D)\
 $(OBJ_EX_ex_c_6_W_DLL_D)\
 $(OBJ_EX_ex_c_7_W_DLL_D)\
 $(OBJ_EX_ex_c_8_W_DLL_D)\
 $(OBJ_EX_ex_cpp_1_W_DLL_D)\
 $(OBJ_EX_ex_cpp_2_W_DLL_D)\
 $(OBJ_EX_ex_cpp_3_W_DLL_D)\
 $(OBJ_EX_ex_c_1_W_DLL_R)\
 $(OBJ_EX_ex_c_2_W_DLL_R)\
 $(OBJ_EX_ex_c_3_W_DLL_R)\
 $(OBJ_EX_ex_c_4_W_DLL_R)\
 $(OBJ_EX_ex_c_5_W_DLL_R)\
 $(OBJ_EX_ex_c_6_W_DLL_R)\
 $(OBJ_EX_ex_c_7_W_DLL_R)\
 $(OBJ_EX_ex_c_8_W_DLL_R)\
 $(OBJ_EX_ex_cpp_1_W_DLL_R)\
 $(OBJ_EX_ex_cpp_2_W_DLL_R)\
 $(OBJ_EX_ex_cpp_3_W_DLL_R)\
 $(OBJ_EX_ex_c_1_W_MT_R)\
 $(OBJ_EX_ex_c_2_W_MT_R)\
 $(OBJ_EX_ex_c_3_W_MT_R)\
 $(OBJ_EX_ex_c_4_W_MT_R)\
 $(OBJ_EX_ex_c_5_W_MT_R)\
 $(OBJ_EX_ex_c_6_W_MT_R)\
 $(OBJ_EX_ex_c_7_W_MT_R)\
 $(OBJ_EX_ex_c_8_W_MT_R)\
 $(OBJ_EX_ex_cpp_1_W_MT_R)\
 $(OBJ_EX_ex_cpp_2_W_MT_R)\
 $(OBJ_EX_ex_cpp_3_W_MT_R)\
 \

# Component Tests
OBJS_TEST_COMPONENT=\
 $(OBJ_TEST_COMP_api_crdir_MT_D)\
 $(OBJ_TEST_COMP_api_rmdir_MT_D)\
 $(OBJ_TEST_COMP_api_crdir_DLL_D)\
 $(OBJ_TEST_COMP_api_rmdir_DLL_D)\
 $(OBJ_TEST_COMP_api_crdir_DLL_R)\
 $(OBJ_TEST_COMP_api_rmdir_DLL_R)\
 $(OBJ_TEST_COMP_api_crdir_MT_R)\
 $(OBJ_TEST_COMP_api_rmdir_MT_R)\
 $(OBJ_TEST_COMP_api_crdir_W_MT_D)\
 $(OBJ_TEST_COMP_api_rmdir_W_MT_D)\
 $(OBJ_TEST_COMP_api_crdir_W_DLL_D)\
 $(OBJ_TEST_COMP_api_rmdir_W_DLL_D)\
 $(OBJ_TEST_COMP_api_crdir_W_DLL_R)\
 $(OBJ_TEST_COMP_api_rmdir_W_DLL_R)\
 $(OBJ_TEST_COMP_api_crdir_W_MT_R)\
 $(OBJ_TEST_COMP_api_rmdir_W_MT_R)\
 \

# Scratch Tests
OBJS_TEST_SCRATCH=\
 $(OBJ_TEST_SCRT_srch1_MT_D)\
 $(OBJ_TEST_SCRT_srch1_DLL_D)\
 $(OBJ_TEST_SCRT_srch1_DLL_R)\
 $(OBJ_TEST_SCRT_srch1_MT_R)\
 $(OBJ_TEST_SCRT_srch1_W_MT_D)\
 $(OBJ_TEST_SCRT_srch1_W_DLL_D)\
 $(OBJ_TEST_SCRT_srch1_W_DLL_R)\
 $(OBJ_TEST_SCRT_srch1_W_MT_R)\
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
 $(OBJ_TEST_UNIT_api_cmbpaths_DLL_D)\
 $(OBJ_TEST_UNIT_api_sqzpath_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_drvrel_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_retcodes_DLL_D)\
 $(OBJ_TEST_UNIT_c_retcodes_DLL_D)\
 $(OBJ_TEST_UNIT_api_cmbpaths_DLL_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_DLL_R)\
 $(OBJ_TEST_UNIT_c_retcodes_DLL_R)\
 $(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
 $(OBJ_TEST_UNIT_c_retcodes_MT_R)\
 $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D)\
 $(OBJ_TEST_UNIT_api_sqzpath_W_MT_D)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D)\
 $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D)\
 $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D)\
 $(OBJ_TEST_UNIT_c_retcodes_W_MT_D)\
 $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D)\
 $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D)\
 $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D)\
 $(OBJ_TEST_UNIT_c_retcodes_W_DLL_D)\
 $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R)\
 $(OBJ_TEST_UNIT_c_retcodes_W_DLL_R)\
 $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R)\
 $(OBJ_TEST_UNIT_api_sqzpath_W_MT_R)\
 $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R)\
 $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R)\
 $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R)\
 $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R)\
 $(OBJ_TEST_UNIT_c_retcodes_W_MT_R)\
 \

# TODO: Add this project
# $(OBJ_TEST_UNIT_api_drvrel [ ` [ MakeSymbolTag ] ` ] ) \

########################################
# Libraries

TARGETS_LIB_CORE=\
 $(LIB_CORE_MT_D)\
 $(LIB_CORE_DLL_D)\
 $(LIB_CORE_DLL_R)\
 $(LIB_CORE_MT_R)\
 $(LIB_CORE_W_MT_D)\
 $(LIB_CORE_W_DLL_D)\
 $(LIB_CORE_W_DLL_R)\
 $(LIB_CORE_W_MT_R)\
 \

TARGETS_LIB_SHWILD=\
 $(LIB_SHWILD_MT_D)\
 $(LIB_SHWILD_DLL_D)\
 $(LIB_SHWILD_DLL_R)\
 $(LIB_SHWILD_MT_R)\
 $(LIB_SHWILD_W_MT_D)\
 $(LIB_SHWILD_W_DLL_D)\
 $(LIB_SHWILD_W_DLL_R)\
 $(LIB_SHWILD_W_MT_R)\
 \

TARGETS_LIB_XCOVER=\
 $(LIB_XCOVER_MT_D)\
 $(LIB_XCOVER_DLL_D)\
 $(LIB_XCOVER_DLL_R)\
 $(LIB_XCOVER_MT_R)\
 $(LIB_XCOVER_W_MT_D)\
 $(LIB_XCOVER_W_DLL_D)\
 $(LIB_XCOVER_W_DLL_R)\
 $(LIB_XCOVER_W_MT_R)\
 \

TARGETS_LIB_XTESTS=\
 $(LIB_XTESTS_MT_D)\
 $(LIB_XTESTS_DLL_D)\
 $(LIB_XTESTS_DLL_R)\
 $(LIB_XTESTS_MT_R)\
 $(LIB_XTESTS_W_MT_D)\
 $(LIB_XTESTS_W_DLL_D)\
 $(LIB_XTESTS_W_DLL_R)\
 $(LIB_XTESTS_W_MT_R)\
 \

########################################
# Programs

TARGETS_EXAMPLE_C=\
 $(TARG_EX_ex_c_1_MT_D)\
 $(TARG_EX_ex_c_2_MT_D)\
 $(TARG_EX_ex_c_3_MT_D)\
 $(TARG_EX_ex_c_4_MT_D)\
 $(TARG_EX_ex_c_5_MT_D)\
 $(TARG_EX_ex_c_6_MT_D)\
 $(TARG_EX_ex_c_7_MT_D)\
 $(TARG_EX_ex_c_8_MT_D)\
 $(TARG_EX_ex_c_1_DLL_D)\
 $(TARG_EX_ex_c_2_DLL_D)\
 $(TARG_EX_ex_c_3_DLL_D)\
 $(TARG_EX_ex_c_4_DLL_D)\
 $(TARG_EX_ex_c_5_DLL_D)\
 $(TARG_EX_ex_c_6_DLL_D)\
 $(TARG_EX_ex_c_7_DLL_D)\
 $(TARG_EX_ex_c_8_DLL_D)\
 $(TARG_EX_ex_c_1_DLL_R)\
 $(TARG_EX_ex_c_2_DLL_R)\
 $(TARG_EX_ex_c_3_DLL_R)\
 $(TARG_EX_ex_c_4_DLL_R)\
 $(TARG_EX_ex_c_5_DLL_R)\
 $(TARG_EX_ex_c_6_DLL_R)\
 $(TARG_EX_ex_c_7_DLL_R)\
 $(TARG_EX_ex_c_8_DLL_R)\
 $(TARG_EX_ex_c_1_MT_R)\
 $(TARG_EX_ex_c_2_MT_R)\
 $(TARG_EX_ex_c_3_MT_R)\
 $(TARG_EX_ex_c_4_MT_R)\
 $(TARG_EX_ex_c_5_MT_R)\
 $(TARG_EX_ex_c_6_MT_R)\
 $(TARG_EX_ex_c_7_MT_R)\
 $(TARG_EX_ex_c_8_MT_R)\
 $(TARG_EX_ex_c_1_W_MT_D)\
 $(TARG_EX_ex_c_2_W_MT_D)\
 $(TARG_EX_ex_c_3_W_MT_D)\
 $(TARG_EX_ex_c_4_W_MT_D)\
 $(TARG_EX_ex_c_5_W_MT_D)\
 $(TARG_EX_ex_c_6_W_MT_D)\
 $(TARG_EX_ex_c_7_W_MT_D)\
 $(TARG_EX_ex_c_8_W_MT_D)\
 $(TARG_EX_ex_c_1_W_DLL_D)\
 $(TARG_EX_ex_c_2_W_DLL_D)\
 $(TARG_EX_ex_c_3_W_DLL_D)\
 $(TARG_EX_ex_c_4_W_DLL_D)\
 $(TARG_EX_ex_c_5_W_DLL_D)\
 $(TARG_EX_ex_c_6_W_DLL_D)\
 $(TARG_EX_ex_c_7_W_DLL_D)\
 $(TARG_EX_ex_c_8_W_DLL_D)\
 $(TARG_EX_ex_c_1_W_DLL_R)\
 $(TARG_EX_ex_c_2_W_DLL_R)\
 $(TARG_EX_ex_c_3_W_DLL_R)\
 $(TARG_EX_ex_c_4_W_DLL_R)\
 $(TARG_EX_ex_c_5_W_DLL_R)\
 $(TARG_EX_ex_c_6_W_DLL_R)\
 $(TARG_EX_ex_c_7_W_DLL_R)\
 $(TARG_EX_ex_c_8_W_DLL_R)\
 $(TARG_EX_ex_c_1_W_MT_R)\
 $(TARG_EX_ex_c_2_W_MT_R)\
 $(TARG_EX_ex_c_3_W_MT_R)\
 $(TARG_EX_ex_c_4_W_MT_R)\
 $(TARG_EX_ex_c_5_W_MT_R)\
 $(TARG_EX_ex_c_6_W_MT_R)\
 $(TARG_EX_ex_c_7_W_MT_R)\
 $(TARG_EX_ex_c_8_W_MT_R)\
 \

TARGETS_EXAMPLE_CPP=\
 $(TARG_EX_ex_cpp_1_MT_D)\
 $(TARG_EX_ex_cpp_2_MT_D)\
 $(TARG_EX_ex_cpp_3_MT_D)\
 $(TARG_EX_ex_cpp_1_DLL_D)\
 $(TARG_EX_ex_cpp_2_DLL_D)\
 $(TARG_EX_ex_cpp_3_DLL_D)\
 $(TARG_EX_ex_cpp_1_DLL_R)\
 $(TARG_EX_ex_cpp_2_DLL_R)\
 $(TARG_EX_ex_cpp_3_DLL_R)\
 $(TARG_EX_ex_cpp_1_MT_R)\
 $(TARG_EX_ex_cpp_2_MT_R)\
 $(TARG_EX_ex_cpp_3_MT_R)\
 $(TARG_EX_ex_cpp_1_W_MT_D)\
 $(TARG_EX_ex_cpp_2_W_MT_D)\
 $(TARG_EX_ex_cpp_3_W_MT_D)\
 $(TARG_EX_ex_cpp_1_W_DLL_D)\
 $(TARG_EX_ex_cpp_2_W_DLL_D)\
 $(TARG_EX_ex_cpp_3_W_DLL_D)\
 $(TARG_EX_ex_cpp_1_W_DLL_R)\
 $(TARG_EX_ex_cpp_2_W_DLL_R)\
 $(TARG_EX_ex_cpp_3_W_DLL_R)\
 $(TARG_EX_ex_cpp_1_W_MT_R)\
 $(TARG_EX_ex_cpp_2_W_MT_R)\
 $(TARG_EX_ex_cpp_3_W_MT_R)\
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
 $(TARG_TEST_COMP_api_crdir_DLL_D)\
 $(TARG_TEST_COMP_api_rmdir_DLL_D)\
 $(TARG_TEST_COMP_api_crdir_DLL_R)\
 $(TARG_TEST_COMP_api_rmdir_DLL_R)\
 $(TARG_TEST_COMP_api_crdir_MT_R)\
 $(TARG_TEST_COMP_api_rmdir_MT_R)\
 $(TARG_TEST_COMP_api_crdir_W_MT_D)\
 $(TARG_TEST_COMP_api_rmdir_W_MT_D)\
 $(TARG_TEST_COMP_api_crdir_W_DLL_D)\
 $(TARG_TEST_COMP_api_rmdir_W_DLL_D)\
 $(TARG_TEST_COMP_api_crdir_W_DLL_R)\
 $(TARG_TEST_COMP_api_rmdir_W_DLL_R)\
 $(TARG_TEST_COMP_api_crdir_W_MT_R)\
 $(TARG_TEST_COMP_api_rmdir_W_MT_R)\
 \

TARGETS_TEST_SCRATCH=\
 $(TARG_TEST_SCRT_srch1_MT_D)\
 $(TARG_TEST_SCRT_srch1_DLL_D)\
 $(TARG_TEST_SCRT_srch1_DLL_R)\
 $(TARG_TEST_SCRT_srch1_MT_R)\
 $(TARG_TEST_SCRT_srch1_W_MT_D)\
 $(TARG_TEST_SCRT_srch1_W_DLL_D)\
 $(TARG_TEST_SCRT_srch1_W_DLL_R)\
 $(TARG_TEST_SCRT_srch1_W_MT_R)\
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
 $(TARG_TEST_UNIT_api_cmbpaths_DLL_D)\
 $(TARG_TEST_UNIT_api_sqzpath_DLL_D)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_D)\
 $(TARG_TEST_UNIT_cpp_drvrel_DLL_D)\
 $(TARG_TEST_UNIT_cpp_sqzpath_DLL_D)\
 $(TARG_TEST_UNIT_cpp_retcodes_DLL_D)\
 $(TARG_TEST_UNIT_c_retcodes_DLL_D)\
 $(TARG_TEST_UNIT_api_cmbpaths_DLL_R)\
 $(TARG_TEST_UNIT_api_sqzpath_DLL_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_DLL_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_DLL_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_DLL_R)\
 $(TARG_TEST_UNIT_c_retcodes_DLL_R)\
 $(TARG_TEST_UNIT_api_cmbpaths_MT_R)\
 $(TARG_TEST_UNIT_api_sqzpath_MT_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_MT_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_MT_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_MT_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_MT_R)\
 $(TARG_TEST_UNIT_c_retcodes_MT_R)\
 $(TARG_TEST_UNIT_api_cmbpaths_W_MT_D)\
 $(TARG_TEST_UNIT_api_sqzpath_W_MT_D)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D)\
 $(TARG_TEST_UNIT_cpp_drvrel_W_MT_D)\
 $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_D)\
 $(TARG_TEST_UNIT_cpp_retcodes_W_MT_D)\
 $(TARG_TEST_UNIT_c_retcodes_W_MT_D)\
 $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_D)\
 $(TARG_TEST_UNIT_api_sqzpath_W_DLL_D)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D)\
 $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_D)\
 $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D)\
 $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_D)\
 $(TARG_TEST_UNIT_c_retcodes_W_DLL_D)\
 $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_R)\
 $(TARG_TEST_UNIT_api_sqzpath_W_DLL_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_R)\
 $(TARG_TEST_UNIT_c_retcodes_W_DLL_R)\
 $(TARG_TEST_UNIT_api_cmbpaths_W_MT_R)\
 $(TARG_TEST_UNIT_api_sqzpath_W_MT_R)\
 $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R)\
 $(TARG_TEST_UNIT_cpp_drvrel_W_MT_R)\
 $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_R)\
 $(TARG_TEST_UNIT_cpp_retcodes_W_MT_R)\
 $(TARG_TEST_UNIT_c_retcodes_W_MT_R)\
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
	$(TARG_TEST_COMP_api_crdir_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_crdir_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_COMP_api_rmdir_W_MT_R) --verbosity=$(TEST_VERBOSITY)

test.scratch_:
	@echo Running Test:Scratch programs ...
	$(TARG_TEST_SCRT_srch1_MT_D)
	$(TARG_TEST_SCRT_srch1_DLL_D)
	$(TARG_TEST_SCRT_srch1_DLL_R)
	$(TARG_TEST_SCRT_srch1_MT_R)
	$(TARG_TEST_SCRT_srch1_W_MT_D)
	$(TARG_TEST_SCRT_srch1_W_DLL_D)
	$(TARG_TEST_SCRT_srch1_W_DLL_R)
	$(TARG_TEST_SCRT_srch1_W_MT_R)


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
	$(TARG_TEST_UNIT_api_cmbpaths_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_W_MT_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_W_DLL_D) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_W_DLL_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_cmbpaths_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_api_sqzpath_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_drvrel_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_sqzpath_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_cpp_retcodes_W_MT_R) --verbosity=$(TEST_VERBOSITY)
	$(TARG_TEST_UNIT_c_retcodes_W_MT_R) --verbosity=$(TEST_VERBOSITY)

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
	-$(TARG_EX_ex_c_1_DLL_D)
	-$(TARG_EX_ex_c_2_DLL_D)
	-$(TARG_EX_ex_c_3_DLL_D)
	-$(TARG_EX_ex_c_4_DLL_D)
	-$(TARG_EX_ex_c_5_DLL_D)
	-$(TARG_EX_ex_c_6_DLL_D)
	-$(TARG_EX_ex_c_7_DLL_D)
	-$(TARG_EX_ex_c_8_DLL_D)
	-$(TARG_EX_ex_c_1_DLL_R)
	-$(TARG_EX_ex_c_2_DLL_R)
	-$(TARG_EX_ex_c_3_DLL_R)
	-$(TARG_EX_ex_c_4_DLL_R)
	-$(TARG_EX_ex_c_5_DLL_R)
	-$(TARG_EX_ex_c_6_DLL_R)
	-$(TARG_EX_ex_c_7_DLL_R)
	-$(TARG_EX_ex_c_8_DLL_R)
	-$(TARG_EX_ex_c_1_MT_R)
	-$(TARG_EX_ex_c_2_MT_R)
	-$(TARG_EX_ex_c_3_MT_R)
	-$(TARG_EX_ex_c_4_MT_R)
	-$(TARG_EX_ex_c_5_MT_R)
	-$(TARG_EX_ex_c_6_MT_R)
	-$(TARG_EX_ex_c_7_MT_R)
	-$(TARG_EX_ex_c_8_MT_R)
	-$(TARG_EX_ex_c_1_W_MT_D)
	-$(TARG_EX_ex_c_2_W_MT_D)
	-$(TARG_EX_ex_c_3_W_MT_D)
	-$(TARG_EX_ex_c_4_W_MT_D)
	-$(TARG_EX_ex_c_5_W_MT_D)
	-$(TARG_EX_ex_c_6_W_MT_D)
	-$(TARG_EX_ex_c_7_W_MT_D)
	-$(TARG_EX_ex_c_8_W_MT_D)
	-$(TARG_EX_ex_c_1_W_DLL_D)
	-$(TARG_EX_ex_c_2_W_DLL_D)
	-$(TARG_EX_ex_c_3_W_DLL_D)
	-$(TARG_EX_ex_c_4_W_DLL_D)
	-$(TARG_EX_ex_c_5_W_DLL_D)
	-$(TARG_EX_ex_c_6_W_DLL_D)
	-$(TARG_EX_ex_c_7_W_DLL_D)
	-$(TARG_EX_ex_c_8_W_DLL_D)
	-$(TARG_EX_ex_c_1_W_DLL_R)
	-$(TARG_EX_ex_c_2_W_DLL_R)
	-$(TARG_EX_ex_c_3_W_DLL_R)
	-$(TARG_EX_ex_c_4_W_DLL_R)
	-$(TARG_EX_ex_c_5_W_DLL_R)
	-$(TARG_EX_ex_c_6_W_DLL_R)
	-$(TARG_EX_ex_c_7_W_DLL_R)
	-$(TARG_EX_ex_c_8_W_DLL_R)
	-$(TARG_EX_ex_c_1_W_MT_R)
	-$(TARG_EX_ex_c_2_W_MT_R)
	-$(TARG_EX_ex_c_3_W_MT_R)
	-$(TARG_EX_ex_c_4_W_MT_R)
	-$(TARG_EX_ex_c_5_W_MT_R)
	-$(TARG_EX_ex_c_6_W_MT_R)
	-$(TARG_EX_ex_c_7_W_MT_R)
	-$(TARG_EX_ex_c_8_W_MT_R)

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
	@-if exist $(LIB_CORE_DLL_D) $(RM) $(LIB_CORE_DLL_D)
	@-if exist $(LIB_CORE_DLL_R) $(RM) $(LIB_CORE_DLL_R)
	@-if exist $(LIB_CORE_MT_R) $(RM) $(LIB_CORE_MT_R)
	@-if exist $(LIB_CORE_W_MT_D) $(RM) $(LIB_CORE_W_MT_D)
	@-if exist $(LIB_CORE_W_DLL_D) $(RM) $(LIB_CORE_W_DLL_D)
	@-if exist $(LIB_CORE_W_DLL_R) $(RM) $(LIB_CORE_W_DLL_R)
	@-if exist $(LIB_CORE_W_MT_R) $(RM) $(LIB_CORE_W_MT_R)
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
	@-if exist $(OBJ_CR_api_win64_MT_D) $(RM) $(OBJ_CR_api_win64_MT_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_MT_D) $(RM) $(OBJ_CR_impl_fileinfo_win64_MT_D)
	@-if exist $(OBJ_CR_impl_util_win64_MT_D) $(RM) $(OBJ_CR_impl_util_win64_MT_D)
	@-if exist $(OBJ_CR_api_ftp_windows_MT_D) $(RM) $(OBJ_CR_api_ftp_windows_MT_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_MT_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_MT_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_MT_D) $(RM) $(OBJ_CR_FtpSrch_windows_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_DLL_D) $(RM) $(OBJ_CR_api_entryinfo_DLL_D)
	@-if exist $(OBJ_CR_api_error_DLL_D) $(RM) $(OBJ_CR_api_error_DLL_D)
	@-if exist $(OBJ_CR_api_extended_DLL_D) $(RM) $(OBJ_CR_api_extended_DLL_D)
	@-if exist $(OBJ_CR_api_combpath_DLL_D) $(RM) $(OBJ_CR_api_combpath_DLL_D)
	@-if exist $(OBJ_CR_api_derrpath_DLL_D) $(RM) $(OBJ_CR_api_derrpath_DLL_D)
	@-if exist $(OBJ_CR_api_getflsizs_DLL_D) $(RM) $(OBJ_CR_api_getflsizs_DLL_D)
	@-if exist $(OBJ_CR_api_sqzpath_DLL_D) $(RM) $(OBJ_CR_api_sqzpath_DLL_D)
	@-if exist $(OBJ_CR_api_stat_DLL_D) $(RM) $(OBJ_CR_api_stat_DLL_D)
	@-if exist $(OBJ_CR_api_crdir_DLL_D) $(RM) $(OBJ_CR_api_crdir_DLL_D)
	@-if exist $(OBJ_CR_api_rmdir_DLL_D) $(RM) $(OBJ_CR_api_rmdir_DLL_D)
	@-if exist $(OBJ_CR_api_rc_win_DLL_D) $(RM) $(OBJ_CR_api_rc_win_DLL_D)
	@-if exist $(OBJ_CR_api_search_DLL_D) $(RM) $(OBJ_CR_api_search_DLL_D)
	@-if exist $(OBJ_CR_impl_debug_DLL_D) $(RM) $(OBJ_CR_impl_debug_DLL_D)
	@-if exist $(OBJ_CR_impl_entryinfo_DLL_D) $(RM) $(OBJ_CR_impl_entryinfo_DLL_D)
	@-if exist $(OBJ_CR_impl_fileinfo_DLL_D) $(RM) $(OBJ_CR_impl_fileinfo_DLL_D)
	@-if exist $(OBJ_CR_impl_snprintf_DLL_D) $(RM) $(OBJ_CR_impl_snprintf_DLL_D)
	@-if exist $(OBJ_CR_impl_util_DLL_D) $(RM) $(OBJ_CR_impl_util_DLL_D)
	@-if exist $(OBJ_CR_Srch_DLL_D) $(RM) $(OBJ_CR_Srch_DLL_D)
	@-if exist $(OBJ_CR_FlSrch_DLL_D) $(RM) $(OBJ_CR_FlSrch_DLL_D)
	@-if exist $(OBJ_CR_FlSchDirNode_DLL_D) $(RM) $(OBJ_CR_FlSchDirNode_DLL_D)
	@-if exist $(OBJ_CR_api_win64_DLL_D) $(RM) $(OBJ_CR_api_win64_DLL_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_DLL_D) $(RM) $(OBJ_CR_impl_fileinfo_win64_DLL_D)
	@-if exist $(OBJ_CR_impl_util_win64_DLL_D) $(RM) $(OBJ_CR_impl_util_win64_DLL_D)
	@-if exist $(OBJ_CR_api_ftp_windows_DLL_D) $(RM) $(OBJ_CR_api_ftp_windows_DLL_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_DLL_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_DLL_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_DLL_D) $(RM) $(OBJ_CR_FtpSrch_windows_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_DLL_R) $(RM) $(OBJ_CR_api_entryinfo_DLL_R)
	@-if exist $(OBJ_CR_api_error_DLL_R) $(RM) $(OBJ_CR_api_error_DLL_R)
	@-if exist $(OBJ_CR_api_extended_DLL_R) $(RM) $(OBJ_CR_api_extended_DLL_R)
	@-if exist $(OBJ_CR_api_combpath_DLL_R) $(RM) $(OBJ_CR_api_combpath_DLL_R)
	@-if exist $(OBJ_CR_api_derrpath_DLL_R) $(RM) $(OBJ_CR_api_derrpath_DLL_R)
	@-if exist $(OBJ_CR_api_getflsizs_DLL_R) $(RM) $(OBJ_CR_api_getflsizs_DLL_R)
	@-if exist $(OBJ_CR_api_sqzpath_DLL_R) $(RM) $(OBJ_CR_api_sqzpath_DLL_R)
	@-if exist $(OBJ_CR_api_stat_DLL_R) $(RM) $(OBJ_CR_api_stat_DLL_R)
	@-if exist $(OBJ_CR_api_crdir_DLL_R) $(RM) $(OBJ_CR_api_crdir_DLL_R)
	@-if exist $(OBJ_CR_api_rmdir_DLL_R) $(RM) $(OBJ_CR_api_rmdir_DLL_R)
	@-if exist $(OBJ_CR_api_rc_win_DLL_R) $(RM) $(OBJ_CR_api_rc_win_DLL_R)
	@-if exist $(OBJ_CR_api_search_DLL_R) $(RM) $(OBJ_CR_api_search_DLL_R)
	@-if exist $(OBJ_CR_impl_debug_DLL_R) $(RM) $(OBJ_CR_impl_debug_DLL_R)
	@-if exist $(OBJ_CR_impl_entryinfo_DLL_R) $(RM) $(OBJ_CR_impl_entryinfo_DLL_R)
	@-if exist $(OBJ_CR_impl_fileinfo_DLL_R) $(RM) $(OBJ_CR_impl_fileinfo_DLL_R)
	@-if exist $(OBJ_CR_impl_snprintf_DLL_R) $(RM) $(OBJ_CR_impl_snprintf_DLL_R)
	@-if exist $(OBJ_CR_impl_util_DLL_R) $(RM) $(OBJ_CR_impl_util_DLL_R)
	@-if exist $(OBJ_CR_Srch_DLL_R) $(RM) $(OBJ_CR_Srch_DLL_R)
	@-if exist $(OBJ_CR_FlSrch_DLL_R) $(RM) $(OBJ_CR_FlSrch_DLL_R)
	@-if exist $(OBJ_CR_FlSchDirNode_DLL_R) $(RM) $(OBJ_CR_FlSchDirNode_DLL_R)
	@-if exist $(OBJ_CR_api_win64_DLL_R) $(RM) $(OBJ_CR_api_win64_DLL_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_DLL_R) $(RM) $(OBJ_CR_impl_fileinfo_win64_DLL_R)
	@-if exist $(OBJ_CR_impl_util_win64_DLL_R) $(RM) $(OBJ_CR_impl_util_win64_DLL_R)
	@-if exist $(OBJ_CR_api_ftp_windows_DLL_R) $(RM) $(OBJ_CR_api_ftp_windows_DLL_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_DLL_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_DLL_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_DLL_R) $(RM) $(OBJ_CR_FtpSrch_windows_DLL_R)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
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
	@-if exist $(OBJ_CR_api_win64_MT_R) $(RM) $(OBJ_CR_api_win64_MT_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_MT_R) $(RM) $(OBJ_CR_impl_fileinfo_win64_MT_R)
	@-if exist $(OBJ_CR_impl_util_win64_MT_R) $(RM) $(OBJ_CR_impl_util_win64_MT_R)
	@-if exist $(OBJ_CR_api_ftp_windows_MT_R) $(RM) $(OBJ_CR_api_ftp_windows_MT_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_MT_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_MT_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_MT_R) $(RM) $(OBJ_CR_FtpSrch_windows_MT_R)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_W_MT_D) $(RM) $(OBJ_CR_api_entryinfo_W_MT_D)
	@-if exist $(OBJ_CR_api_error_W_MT_D) $(RM) $(OBJ_CR_api_error_W_MT_D)
	@-if exist $(OBJ_CR_api_extended_W_MT_D) $(RM) $(OBJ_CR_api_extended_W_MT_D)
	@-if exist $(OBJ_CR_api_combpath_W_MT_D) $(RM) $(OBJ_CR_api_combpath_W_MT_D)
	@-if exist $(OBJ_CR_api_derrpath_W_MT_D) $(RM) $(OBJ_CR_api_derrpath_W_MT_D)
	@-if exist $(OBJ_CR_api_getflsizs_W_MT_D) $(RM) $(OBJ_CR_api_getflsizs_W_MT_D)
	@-if exist $(OBJ_CR_api_sqzpath_W_MT_D) $(RM) $(OBJ_CR_api_sqzpath_W_MT_D)
	@-if exist $(OBJ_CR_api_stat_W_MT_D) $(RM) $(OBJ_CR_api_stat_W_MT_D)
	@-if exist $(OBJ_CR_api_crdir_W_MT_D) $(RM) $(OBJ_CR_api_crdir_W_MT_D)
	@-if exist $(OBJ_CR_api_rmdir_W_MT_D) $(RM) $(OBJ_CR_api_rmdir_W_MT_D)
	@-if exist $(OBJ_CR_api_rc_win_W_MT_D) $(RM) $(OBJ_CR_api_rc_win_W_MT_D)
	@-if exist $(OBJ_CR_api_search_W_MT_D) $(RM) $(OBJ_CR_api_search_W_MT_D)
	@-if exist $(OBJ_CR_impl_debug_W_MT_D) $(RM) $(OBJ_CR_impl_debug_W_MT_D)
	@-if exist $(OBJ_CR_impl_entryinfo_W_MT_D) $(RM) $(OBJ_CR_impl_entryinfo_W_MT_D)
	@-if exist $(OBJ_CR_impl_fileinfo_W_MT_D) $(RM) $(OBJ_CR_impl_fileinfo_W_MT_D)
	@-if exist $(OBJ_CR_impl_snprintf_W_MT_D) $(RM) $(OBJ_CR_impl_snprintf_W_MT_D)
	@-if exist $(OBJ_CR_impl_util_W_MT_D) $(RM) $(OBJ_CR_impl_util_W_MT_D)
	@-if exist $(OBJ_CR_Srch_W_MT_D) $(RM) $(OBJ_CR_Srch_W_MT_D)
	@-if exist $(OBJ_CR_FlSrch_W_MT_D) $(RM) $(OBJ_CR_FlSrch_W_MT_D)
	@-if exist $(OBJ_CR_FlSchDirNode_W_MT_D) $(RM) $(OBJ_CR_FlSchDirNode_W_MT_D)
	@-if exist $(OBJ_CR_api_win64_W_MT_D) $(RM) $(OBJ_CR_api_win64_W_MT_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_W_MT_D) $(RM) $(OBJ_CR_impl_fileinfo_win64_W_MT_D)
	@-if exist $(OBJ_CR_impl_util_win64_W_MT_D) $(RM) $(OBJ_CR_impl_util_win64_W_MT_D)
	@-if exist $(OBJ_CR_api_ftp_windows_W_MT_D) $(RM) $(OBJ_CR_api_ftp_windows_W_MT_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_W_MT_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_W_MT_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_W_MT_D) $(RM) $(OBJ_CR_FtpSrch_windows_W_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_W_DLL_D) $(RM) $(OBJ_CR_api_entryinfo_W_DLL_D)
	@-if exist $(OBJ_CR_api_error_W_DLL_D) $(RM) $(OBJ_CR_api_error_W_DLL_D)
	@-if exist $(OBJ_CR_api_extended_W_DLL_D) $(RM) $(OBJ_CR_api_extended_W_DLL_D)
	@-if exist $(OBJ_CR_api_combpath_W_DLL_D) $(RM) $(OBJ_CR_api_combpath_W_DLL_D)
	@-if exist $(OBJ_CR_api_derrpath_W_DLL_D) $(RM) $(OBJ_CR_api_derrpath_W_DLL_D)
	@-if exist $(OBJ_CR_api_getflsizs_W_DLL_D) $(RM) $(OBJ_CR_api_getflsizs_W_DLL_D)
	@-if exist $(OBJ_CR_api_sqzpath_W_DLL_D) $(RM) $(OBJ_CR_api_sqzpath_W_DLL_D)
	@-if exist $(OBJ_CR_api_stat_W_DLL_D) $(RM) $(OBJ_CR_api_stat_W_DLL_D)
	@-if exist $(OBJ_CR_api_crdir_W_DLL_D) $(RM) $(OBJ_CR_api_crdir_W_DLL_D)
	@-if exist $(OBJ_CR_api_rmdir_W_DLL_D) $(RM) $(OBJ_CR_api_rmdir_W_DLL_D)
	@-if exist $(OBJ_CR_api_rc_win_W_DLL_D) $(RM) $(OBJ_CR_api_rc_win_W_DLL_D)
	@-if exist $(OBJ_CR_api_search_W_DLL_D) $(RM) $(OBJ_CR_api_search_W_DLL_D)
	@-if exist $(OBJ_CR_impl_debug_W_DLL_D) $(RM) $(OBJ_CR_impl_debug_W_DLL_D)
	@-if exist $(OBJ_CR_impl_entryinfo_W_DLL_D) $(RM) $(OBJ_CR_impl_entryinfo_W_DLL_D)
	@-if exist $(OBJ_CR_impl_fileinfo_W_DLL_D) $(RM) $(OBJ_CR_impl_fileinfo_W_DLL_D)
	@-if exist $(OBJ_CR_impl_snprintf_W_DLL_D) $(RM) $(OBJ_CR_impl_snprintf_W_DLL_D)
	@-if exist $(OBJ_CR_impl_util_W_DLL_D) $(RM) $(OBJ_CR_impl_util_W_DLL_D)
	@-if exist $(OBJ_CR_Srch_W_DLL_D) $(RM) $(OBJ_CR_Srch_W_DLL_D)
	@-if exist $(OBJ_CR_FlSrch_W_DLL_D) $(RM) $(OBJ_CR_FlSrch_W_DLL_D)
	@-if exist $(OBJ_CR_FlSchDirNode_W_DLL_D) $(RM) $(OBJ_CR_FlSchDirNode_W_DLL_D)
	@-if exist $(OBJ_CR_api_win64_W_DLL_D) $(RM) $(OBJ_CR_api_win64_W_DLL_D)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_W_DLL_D) $(RM) $(OBJ_CR_impl_fileinfo_win64_W_DLL_D)
	@-if exist $(OBJ_CR_impl_util_win64_W_DLL_D) $(RM) $(OBJ_CR_impl_util_win64_W_DLL_D)
	@-if exist $(OBJ_CR_api_ftp_windows_W_DLL_D) $(RM) $(OBJ_CR_api_ftp_windows_W_DLL_D)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_W_DLL_D) $(RM) $(OBJ_CR_FtpSchDirNode_win_W_DLL_D)
	@-if exist $(OBJ_CR_FtpSrch_windows_W_DLL_D) $(RM) $(OBJ_CR_FtpSrch_windows_W_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_W_DLL_R) $(RM) $(OBJ_CR_api_entryinfo_W_DLL_R)
	@-if exist $(OBJ_CR_api_error_W_DLL_R) $(RM) $(OBJ_CR_api_error_W_DLL_R)
	@-if exist $(OBJ_CR_api_extended_W_DLL_R) $(RM) $(OBJ_CR_api_extended_W_DLL_R)
	@-if exist $(OBJ_CR_api_combpath_W_DLL_R) $(RM) $(OBJ_CR_api_combpath_W_DLL_R)
	@-if exist $(OBJ_CR_api_derrpath_W_DLL_R) $(RM) $(OBJ_CR_api_derrpath_W_DLL_R)
	@-if exist $(OBJ_CR_api_getflsizs_W_DLL_R) $(RM) $(OBJ_CR_api_getflsizs_W_DLL_R)
	@-if exist $(OBJ_CR_api_sqzpath_W_DLL_R) $(RM) $(OBJ_CR_api_sqzpath_W_DLL_R)
	@-if exist $(OBJ_CR_api_stat_W_DLL_R) $(RM) $(OBJ_CR_api_stat_W_DLL_R)
	@-if exist $(OBJ_CR_api_crdir_W_DLL_R) $(RM) $(OBJ_CR_api_crdir_W_DLL_R)
	@-if exist $(OBJ_CR_api_rmdir_W_DLL_R) $(RM) $(OBJ_CR_api_rmdir_W_DLL_R)
	@-if exist $(OBJ_CR_api_rc_win_W_DLL_R) $(RM) $(OBJ_CR_api_rc_win_W_DLL_R)
	@-if exist $(OBJ_CR_api_search_W_DLL_R) $(RM) $(OBJ_CR_api_search_W_DLL_R)
	@-if exist $(OBJ_CR_impl_debug_W_DLL_R) $(RM) $(OBJ_CR_impl_debug_W_DLL_R)
	@-if exist $(OBJ_CR_impl_entryinfo_W_DLL_R) $(RM) $(OBJ_CR_impl_entryinfo_W_DLL_R)
	@-if exist $(OBJ_CR_impl_fileinfo_W_DLL_R) $(RM) $(OBJ_CR_impl_fileinfo_W_DLL_R)
	@-if exist $(OBJ_CR_impl_snprintf_W_DLL_R) $(RM) $(OBJ_CR_impl_snprintf_W_DLL_R)
	@-if exist $(OBJ_CR_impl_util_W_DLL_R) $(RM) $(OBJ_CR_impl_util_W_DLL_R)
	@-if exist $(OBJ_CR_Srch_W_DLL_R) $(RM) $(OBJ_CR_Srch_W_DLL_R)
	@-if exist $(OBJ_CR_FlSrch_W_DLL_R) $(RM) $(OBJ_CR_FlSrch_W_DLL_R)
	@-if exist $(OBJ_CR_FlSchDirNode_W_DLL_R) $(RM) $(OBJ_CR_FlSchDirNode_W_DLL_R)
	@-if exist $(OBJ_CR_api_win64_W_DLL_R) $(RM) $(OBJ_CR_api_win64_W_DLL_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_W_DLL_R) $(RM) $(OBJ_CR_impl_fileinfo_win64_W_DLL_R)
	@-if exist $(OBJ_CR_impl_util_win64_W_DLL_R) $(RM) $(OBJ_CR_impl_util_win64_W_DLL_R)
	@-if exist $(OBJ_CR_api_ftp_windows_W_DLL_R) $(RM) $(OBJ_CR_api_ftp_windows_W_DLL_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_W_DLL_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_W_DLL_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_W_DLL_R) $(RM) $(OBJ_CR_FtpSrch_windows_W_DLL_R)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb
	@-if exist $(OBJ_CR_api_entryinfo_W_MT_R) $(RM) $(OBJ_CR_api_entryinfo_W_MT_R)
	@-if exist $(OBJ_CR_api_error_W_MT_R) $(RM) $(OBJ_CR_api_error_W_MT_R)
	@-if exist $(OBJ_CR_api_extended_W_MT_R) $(RM) $(OBJ_CR_api_extended_W_MT_R)
	@-if exist $(OBJ_CR_api_combpath_W_MT_R) $(RM) $(OBJ_CR_api_combpath_W_MT_R)
	@-if exist $(OBJ_CR_api_derrpath_W_MT_R) $(RM) $(OBJ_CR_api_derrpath_W_MT_R)
	@-if exist $(OBJ_CR_api_getflsizs_W_MT_R) $(RM) $(OBJ_CR_api_getflsizs_W_MT_R)
	@-if exist $(OBJ_CR_api_sqzpath_W_MT_R) $(RM) $(OBJ_CR_api_sqzpath_W_MT_R)
	@-if exist $(OBJ_CR_api_stat_W_MT_R) $(RM) $(OBJ_CR_api_stat_W_MT_R)
	@-if exist $(OBJ_CR_api_crdir_W_MT_R) $(RM) $(OBJ_CR_api_crdir_W_MT_R)
	@-if exist $(OBJ_CR_api_rmdir_W_MT_R) $(RM) $(OBJ_CR_api_rmdir_W_MT_R)
	@-if exist $(OBJ_CR_api_rc_win_W_MT_R) $(RM) $(OBJ_CR_api_rc_win_W_MT_R)
	@-if exist $(OBJ_CR_api_search_W_MT_R) $(RM) $(OBJ_CR_api_search_W_MT_R)
	@-if exist $(OBJ_CR_impl_debug_W_MT_R) $(RM) $(OBJ_CR_impl_debug_W_MT_R)
	@-if exist $(OBJ_CR_impl_entryinfo_W_MT_R) $(RM) $(OBJ_CR_impl_entryinfo_W_MT_R)
	@-if exist $(OBJ_CR_impl_fileinfo_W_MT_R) $(RM) $(OBJ_CR_impl_fileinfo_W_MT_R)
	@-if exist $(OBJ_CR_impl_snprintf_W_MT_R) $(RM) $(OBJ_CR_impl_snprintf_W_MT_R)
	@-if exist $(OBJ_CR_impl_util_W_MT_R) $(RM) $(OBJ_CR_impl_util_W_MT_R)
	@-if exist $(OBJ_CR_Srch_W_MT_R) $(RM) $(OBJ_CR_Srch_W_MT_R)
	@-if exist $(OBJ_CR_FlSrch_W_MT_R) $(RM) $(OBJ_CR_FlSrch_W_MT_R)
	@-if exist $(OBJ_CR_FlSchDirNode_W_MT_R) $(RM) $(OBJ_CR_FlSchDirNode_W_MT_R)
	@-if exist $(OBJ_CR_api_win64_W_MT_R) $(RM) $(OBJ_CR_api_win64_W_MT_R)
	@-if exist $(OBJ_CR_impl_fileinfo_win64_W_MT_R) $(RM) $(OBJ_CR_impl_fileinfo_win64_W_MT_R)
	@-if exist $(OBJ_CR_impl_util_win64_W_MT_R) $(RM) $(OBJ_CR_impl_util_win64_W_MT_R)
	@-if exist $(OBJ_CR_api_ftp_windows_W_MT_R) $(RM) $(OBJ_CR_api_ftp_windows_W_MT_R)
	@-if exist $(OBJ_CR_FtpSchDirNode_win_W_MT_R) $(RM) $(OBJ_CR_FtpSchDirNode_win_W_MT_R)
	@-if exist $(OBJ_CR_FtpSrch_windows_W_MT_R) $(RM) $(OBJ_CR_FtpSrch_windows_W_MT_R)
	@-if exist $(PROJ_OBJ_DIR)\api.*.pdb $(RM) $(PROJ_OBJ_DIR)\api.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\impl.*.pdb $(RM) $(PROJ_OBJ_DIR)\impl.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\recls*.pdb $(RM) $(PROJ_OBJ_DIR)\recls*.pdb

clean.libs.shwild:
	@echo Cleaning shwild libraries ...
	@-if exist shwild.*.obj $(RM) shwild.*.obj
	@-if exist shwild.*.pdb $(RM) shwild.*.pdb
	@-if exist $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(SHWILD_TAG_VER).recls.$(COMP_TAG)*.lib

clean.libs.xcover:
	@echo Cleaning xCover libraries ...
	@-if exist xcover.*.obj $(RM) xcover.*.obj
	@-if exist xcover.*.pdb $(RM) xcover.*.pdb
	@-if exist $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(XCOVER_TAG_VER).recls.$(COMP_TAG)*.lib

clean.libs.xtests:
	@echo Cleaning xTests libraries ...
	@-if exist xtests.*.obj $(RM) xtests.*.obj
	@-if exist xtests.*.pdb $(RM) xtests.*.pdb
	@-if exist $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_TAG)*.lib $(RM) $(PROJ_LIB_DIR)\$(XTESTS_TAG_VER).recls.$(COMP_TAG)*.lib

clean.libs:                                         clean.libs.core clean.libs.shwild clean.libs.xcover clean.libs.xtests

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
	@-if exist $(PROJ_OBJ_DIR)\ex.c.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.c.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\ex.cpp.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.cpp.*.pdb
	@-if exist $(TARG_EX_ex_c_1_DLL_D) $(RM) $(TARG_EX_ex_c_1_DLL_D)
	@-if exist $(OBJ_EX_ex_c_1_DLL_D) $(RM) $(OBJ_EX_ex_c_1_DLL_D)
	@-if exist $(TARG_EX_ex_c_2_DLL_D) $(RM) $(TARG_EX_ex_c_2_DLL_D)
	@-if exist $(OBJ_EX_ex_c_2_DLL_D) $(RM) $(OBJ_EX_ex_c_2_DLL_D)
	@-if exist $(TARG_EX_ex_c_3_DLL_D) $(RM) $(TARG_EX_ex_c_3_DLL_D)
	@-if exist $(OBJ_EX_ex_c_3_DLL_D) $(RM) $(OBJ_EX_ex_c_3_DLL_D)
	@-if exist $(TARG_EX_ex_c_4_DLL_D) $(RM) $(TARG_EX_ex_c_4_DLL_D)
	@-if exist $(OBJ_EX_ex_c_4_DLL_D) $(RM) $(OBJ_EX_ex_c_4_DLL_D)
	@-if exist $(TARG_EX_ex_c_5_DLL_D) $(RM) $(TARG_EX_ex_c_5_DLL_D)
	@-if exist $(OBJ_EX_ex_c_5_DLL_D) $(RM) $(OBJ_EX_ex_c_5_DLL_D)
	@-if exist $(TARG_EX_ex_c_6_DLL_D) $(RM) $(TARG_EX_ex_c_6_DLL_D)
	@-if exist $(OBJ_EX_ex_c_6_DLL_D) $(RM) $(OBJ_EX_ex_c_6_DLL_D)
	@-if exist $(TARG_EX_ex_c_7_DLL_D) $(RM) $(TARG_EX_ex_c_7_DLL_D)
	@-if exist $(OBJ_EX_ex_c_7_DLL_D) $(RM) $(OBJ_EX_ex_c_7_DLL_D)
	@-if exist $(TARG_EX_ex_c_8_DLL_D) $(RM) $(TARG_EX_ex_c_8_DLL_D)
	@-if exist $(OBJ_EX_ex_c_8_DLL_D) $(RM) $(OBJ_EX_ex_c_8_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_1_DLL_D) $(RM) $(TARG_EX_ex_cpp_1_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_1_DLL_D) $(RM) $(OBJ_EX_ex_cpp_1_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_2_DLL_D) $(RM) $(TARG_EX_ex_cpp_2_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_2_DLL_D) $(RM) $(OBJ_EX_ex_cpp_2_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_3_DLL_D) $(RM) $(TARG_EX_ex_cpp_3_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_3_DLL_D) $(RM) $(OBJ_EX_ex_cpp_3_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\ex.c.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.c.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\ex.cpp.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.cpp.*.pdb
	@-if exist $(TARG_EX_ex_c_1_DLL_R) $(RM) $(TARG_EX_ex_c_1_DLL_R)
	@-if exist $(OBJ_EX_ex_c_1_DLL_R) $(RM) $(OBJ_EX_ex_c_1_DLL_R)
	@-if exist $(TARG_EX_ex_c_2_DLL_R) $(RM) $(TARG_EX_ex_c_2_DLL_R)
	@-if exist $(OBJ_EX_ex_c_2_DLL_R) $(RM) $(OBJ_EX_ex_c_2_DLL_R)
	@-if exist $(TARG_EX_ex_c_3_DLL_R) $(RM) $(TARG_EX_ex_c_3_DLL_R)
	@-if exist $(OBJ_EX_ex_c_3_DLL_R) $(RM) $(OBJ_EX_ex_c_3_DLL_R)
	@-if exist $(TARG_EX_ex_c_4_DLL_R) $(RM) $(TARG_EX_ex_c_4_DLL_R)
	@-if exist $(OBJ_EX_ex_c_4_DLL_R) $(RM) $(OBJ_EX_ex_c_4_DLL_R)
	@-if exist $(TARG_EX_ex_c_5_DLL_R) $(RM) $(TARG_EX_ex_c_5_DLL_R)
	@-if exist $(OBJ_EX_ex_c_5_DLL_R) $(RM) $(OBJ_EX_ex_c_5_DLL_R)
	@-if exist $(TARG_EX_ex_c_6_DLL_R) $(RM) $(TARG_EX_ex_c_6_DLL_R)
	@-if exist $(OBJ_EX_ex_c_6_DLL_R) $(RM) $(OBJ_EX_ex_c_6_DLL_R)
	@-if exist $(TARG_EX_ex_c_7_DLL_R) $(RM) $(TARG_EX_ex_c_7_DLL_R)
	@-if exist $(OBJ_EX_ex_c_7_DLL_R) $(RM) $(OBJ_EX_ex_c_7_DLL_R)
	@-if exist $(TARG_EX_ex_c_8_DLL_R) $(RM) $(TARG_EX_ex_c_8_DLL_R)
	@-if exist $(OBJ_EX_ex_c_8_DLL_R) $(RM) $(OBJ_EX_ex_c_8_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_1_DLL_R) $(RM) $(TARG_EX_ex_cpp_1_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_1_DLL_R) $(RM) $(OBJ_EX_ex_cpp_1_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_2_DLL_R) $(RM) $(TARG_EX_ex_cpp_2_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_2_DLL_R) $(RM) $(OBJ_EX_ex_cpp_2_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_3_DLL_R) $(RM) $(TARG_EX_ex_cpp_3_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_3_DLL_R) $(RM) $(OBJ_EX_ex_cpp_3_DLL_R)
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
	@-if exist $(TARG_EX_ex_c_1_W_MT_D) $(RM) $(TARG_EX_ex_c_1_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_1_W_MT_D) $(RM) $(OBJ_EX_ex_c_1_W_MT_D)
	@-if exist $(TARG_EX_ex_c_2_W_MT_D) $(RM) $(TARG_EX_ex_c_2_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_2_W_MT_D) $(RM) $(OBJ_EX_ex_c_2_W_MT_D)
	@-if exist $(TARG_EX_ex_c_3_W_MT_D) $(RM) $(TARG_EX_ex_c_3_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_3_W_MT_D) $(RM) $(OBJ_EX_ex_c_3_W_MT_D)
	@-if exist $(TARG_EX_ex_c_4_W_MT_D) $(RM) $(TARG_EX_ex_c_4_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_4_W_MT_D) $(RM) $(OBJ_EX_ex_c_4_W_MT_D)
	@-if exist $(TARG_EX_ex_c_5_W_MT_D) $(RM) $(TARG_EX_ex_c_5_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_5_W_MT_D) $(RM) $(OBJ_EX_ex_c_5_W_MT_D)
	@-if exist $(TARG_EX_ex_c_6_W_MT_D) $(RM) $(TARG_EX_ex_c_6_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_6_W_MT_D) $(RM) $(OBJ_EX_ex_c_6_W_MT_D)
	@-if exist $(TARG_EX_ex_c_7_W_MT_D) $(RM) $(TARG_EX_ex_c_7_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_7_W_MT_D) $(RM) $(OBJ_EX_ex_c_7_W_MT_D)
	@-if exist $(TARG_EX_ex_c_8_W_MT_D) $(RM) $(TARG_EX_ex_c_8_W_MT_D)
	@-if exist $(OBJ_EX_ex_c_8_W_MT_D) $(RM) $(OBJ_EX_ex_c_8_W_MT_D)
	@-if exist $(TARG_EX_ex_cpp_1_W_MT_D) $(RM) $(TARG_EX_ex_cpp_1_W_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_1_W_MT_D) $(RM) $(OBJ_EX_ex_cpp_1_W_MT_D)
	@-if exist $(TARG_EX_ex_cpp_2_W_MT_D) $(RM) $(TARG_EX_ex_cpp_2_W_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_2_W_MT_D) $(RM) $(OBJ_EX_ex_cpp_2_W_MT_D)
	@-if exist $(TARG_EX_ex_cpp_3_W_MT_D) $(RM) $(TARG_EX_ex_cpp_3_W_MT_D)
	@-if exist $(OBJ_EX_ex_cpp_3_W_MT_D) $(RM) $(OBJ_EX_ex_cpp_3_W_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\ex.c.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.c.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\ex.cpp.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.cpp.*.pdb
	@-if exist $(TARG_EX_ex_c_1_W_DLL_D) $(RM) $(TARG_EX_ex_c_1_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_1_W_DLL_D) $(RM) $(OBJ_EX_ex_c_1_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_2_W_DLL_D) $(RM) $(TARG_EX_ex_c_2_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_2_W_DLL_D) $(RM) $(OBJ_EX_ex_c_2_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_3_W_DLL_D) $(RM) $(TARG_EX_ex_c_3_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_3_W_DLL_D) $(RM) $(OBJ_EX_ex_c_3_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_4_W_DLL_D) $(RM) $(TARG_EX_ex_c_4_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_4_W_DLL_D) $(RM) $(OBJ_EX_ex_c_4_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_5_W_DLL_D) $(RM) $(TARG_EX_ex_c_5_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_5_W_DLL_D) $(RM) $(OBJ_EX_ex_c_5_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_6_W_DLL_D) $(RM) $(TARG_EX_ex_c_6_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_6_W_DLL_D) $(RM) $(OBJ_EX_ex_c_6_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_7_W_DLL_D) $(RM) $(TARG_EX_ex_c_7_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_7_W_DLL_D) $(RM) $(OBJ_EX_ex_c_7_W_DLL_D)
	@-if exist $(TARG_EX_ex_c_8_W_DLL_D) $(RM) $(TARG_EX_ex_c_8_W_DLL_D)
	@-if exist $(OBJ_EX_ex_c_8_W_DLL_D) $(RM) $(OBJ_EX_ex_c_8_W_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_1_W_DLL_D) $(RM) $(TARG_EX_ex_cpp_1_W_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_1_W_DLL_D) $(RM) $(OBJ_EX_ex_cpp_1_W_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_2_W_DLL_D) $(RM) $(TARG_EX_ex_cpp_2_W_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_2_W_DLL_D) $(RM) $(OBJ_EX_ex_cpp_2_W_DLL_D)
	@-if exist $(TARG_EX_ex_cpp_3_W_DLL_D) $(RM) $(TARG_EX_ex_cpp_3_W_DLL_D)
	@-if exist $(OBJ_EX_ex_cpp_3_W_DLL_D) $(RM) $(OBJ_EX_ex_cpp_3_W_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\ex.c.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.c.*.pdb
	@-if exist $(PROJ_OBJ_DIR)\ex.cpp.*.pdb $(RM) $(PROJ_OBJ_DIR)\ex.cpp.*.pdb
	@-if exist $(TARG_EX_ex_c_1_W_DLL_R) $(RM) $(TARG_EX_ex_c_1_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_1_W_DLL_R) $(RM) $(OBJ_EX_ex_c_1_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_2_W_DLL_R) $(RM) $(TARG_EX_ex_c_2_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_2_W_DLL_R) $(RM) $(OBJ_EX_ex_c_2_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_3_W_DLL_R) $(RM) $(TARG_EX_ex_c_3_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_3_W_DLL_R) $(RM) $(OBJ_EX_ex_c_3_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_4_W_DLL_R) $(RM) $(TARG_EX_ex_c_4_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_4_W_DLL_R) $(RM) $(OBJ_EX_ex_c_4_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_5_W_DLL_R) $(RM) $(TARG_EX_ex_c_5_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_5_W_DLL_R) $(RM) $(OBJ_EX_ex_c_5_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_6_W_DLL_R) $(RM) $(TARG_EX_ex_c_6_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_6_W_DLL_R) $(RM) $(OBJ_EX_ex_c_6_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_7_W_DLL_R) $(RM) $(TARG_EX_ex_c_7_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_7_W_DLL_R) $(RM) $(OBJ_EX_ex_c_7_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_8_W_DLL_R) $(RM) $(TARG_EX_ex_c_8_W_DLL_R)
	@-if exist $(OBJ_EX_ex_c_8_W_DLL_R) $(RM) $(OBJ_EX_ex_c_8_W_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_1_W_DLL_R) $(RM) $(TARG_EX_ex_cpp_1_W_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_1_W_DLL_R) $(RM) $(OBJ_EX_ex_cpp_1_W_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_2_W_DLL_R) $(RM) $(TARG_EX_ex_cpp_2_W_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_2_W_DLL_R) $(RM) $(OBJ_EX_ex_cpp_2_W_DLL_R)
	@-if exist $(TARG_EX_ex_cpp_3_W_DLL_R) $(RM) $(TARG_EX_ex_cpp_3_W_DLL_R)
	@-if exist $(OBJ_EX_ex_cpp_3_W_DLL_R) $(RM) $(OBJ_EX_ex_cpp_3_W_DLL_R)
	@-if exist $(TARG_EX_ex_c_1_W_MT_R) $(RM) $(TARG_EX_ex_c_1_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_1_W_MT_R) $(RM) $(OBJ_EX_ex_c_1_W_MT_R)
	@-if exist $(TARG_EX_ex_c_2_W_MT_R) $(RM) $(TARG_EX_ex_c_2_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_2_W_MT_R) $(RM) $(OBJ_EX_ex_c_2_W_MT_R)
	@-if exist $(TARG_EX_ex_c_3_W_MT_R) $(RM) $(TARG_EX_ex_c_3_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_3_W_MT_R) $(RM) $(OBJ_EX_ex_c_3_W_MT_R)
	@-if exist $(TARG_EX_ex_c_4_W_MT_R) $(RM) $(TARG_EX_ex_c_4_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_4_W_MT_R) $(RM) $(OBJ_EX_ex_c_4_W_MT_R)
	@-if exist $(TARG_EX_ex_c_5_W_MT_R) $(RM) $(TARG_EX_ex_c_5_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_5_W_MT_R) $(RM) $(OBJ_EX_ex_c_5_W_MT_R)
	@-if exist $(TARG_EX_ex_c_6_W_MT_R) $(RM) $(TARG_EX_ex_c_6_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_6_W_MT_R) $(RM) $(OBJ_EX_ex_c_6_W_MT_R)
	@-if exist $(TARG_EX_ex_c_7_W_MT_R) $(RM) $(TARG_EX_ex_c_7_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_7_W_MT_R) $(RM) $(OBJ_EX_ex_c_7_W_MT_R)
	@-if exist $(TARG_EX_ex_c_8_W_MT_R) $(RM) $(TARG_EX_ex_c_8_W_MT_R)
	@-if exist $(OBJ_EX_ex_c_8_W_MT_R) $(RM) $(OBJ_EX_ex_c_8_W_MT_R)
	@-if exist $(TARG_EX_ex_cpp_1_W_MT_R) $(RM) $(TARG_EX_ex_cpp_1_W_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_1_W_MT_R) $(RM) $(OBJ_EX_ex_cpp_1_W_MT_R)
	@-if exist $(TARG_EX_ex_cpp_2_W_MT_R) $(RM) $(TARG_EX_ex_cpp_2_W_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_2_W_MT_R) $(RM) $(OBJ_EX_ex_cpp_2_W_MT_R)
	@-if exist $(TARG_EX_ex_cpp_3_W_MT_R) $(RM) $(TARG_EX_ex_cpp_3_W_MT_R)
	@-if exist $(OBJ_EX_ex_cpp_3_W_MT_R) $(RM) $(OBJ_EX_ex_cpp_3_W_MT_R)

clean.samples:
	@echo cleaning Sample programs ...

clean.test.component:
	@echo Cleaning Test::Component files ...
	@-if exist $(TARG_TEST_COMP_api_crdir_MT_D) $(RM) $(TARG_TEST_COMP_api_crdir_MT_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_MT_D) $(RM) $(TARG_TEST_COMP_api_rmdir_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_MT_D) $(RM) $(OBJ_TEST_COMP_api_crdir_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_MT_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\test.component.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_DLL_D) $(RM) $(TARG_TEST_COMP_api_crdir_DLL_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_DLL_D) $(RM) $(TARG_TEST_COMP_api_rmdir_DLL_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_DLL_D) $(RM) $(OBJ_TEST_COMP_api_crdir_DLL_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_DLL_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.component.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_DLL_R) $(RM) $(TARG_TEST_COMP_api_crdir_DLL_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_DLL_R) $(RM) $(TARG_TEST_COMP_api_rmdir_DLL_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_DLL_R) $(RM) $(OBJ_TEST_COMP_api_crdir_DLL_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_DLL_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_MT_R) $(RM) $(TARG_TEST_COMP_api_crdir_MT_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_MT_R) $(RM) $(TARG_TEST_COMP_api_rmdir_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_MT_R) $(RM) $(OBJ_TEST_COMP_api_crdir_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_MT_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_MT_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_W_MT_D) $(RM) $(TARG_TEST_COMP_api_crdir_W_MT_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_W_MT_D) $(RM) $(TARG_TEST_COMP_api_rmdir_W_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_W_MT_D) $(RM) $(OBJ_TEST_COMP_api_crdir_W_MT_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_W_MT_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_W_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\test.component.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_W_DLL_D) $(RM) $(TARG_TEST_COMP_api_crdir_W_DLL_D)
	@-if exist $(TARG_TEST_COMP_api_rmdir_W_DLL_D) $(RM) $(TARG_TEST_COMP_api_rmdir_W_DLL_D)
	@-if exist $(OBJ_TEST_COMP_api_crdir_W_DLL_D) $(RM) $(OBJ_TEST_COMP_api_crdir_W_DLL_D)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_W_DLL_D) $(RM) $(OBJ_TEST_COMP_api_rmdir_W_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.component.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.component.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_W_DLL_R) $(RM) $(TARG_TEST_COMP_api_crdir_W_DLL_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_W_DLL_R) $(RM) $(TARG_TEST_COMP_api_rmdir_W_DLL_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_W_DLL_R) $(RM) $(OBJ_TEST_COMP_api_crdir_W_DLL_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_W_DLL_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_W_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest
	@-if exist $(TARG_TEST_COMP_api_crdir_W_MT_R) $(RM) $(TARG_TEST_COMP_api_crdir_W_MT_R)
	@-if exist $(TARG_TEST_COMP_api_rmdir_W_MT_R) $(RM) $(TARG_TEST_COMP_api_rmdir_W_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_crdir_W_MT_R) $(RM) $(OBJ_TEST_COMP_api_crdir_W_MT_R)
	@-if exist $(OBJ_TEST_COMP_api_rmdir_W_MT_R) $(RM) $(OBJ_TEST_COMP_api_rmdir_W_MT_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.component.*.manifest

clean.test.scratch:
	@-if exist $(TARG_TEST_SCRT_srch1_MT_D) $(RM) $(TARG_TEST_SCRT_srch1_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_MT_D) $(RM) $(OBJ_TEST_SCRT_srch1_MT_D)
	@-if exist $(TARG_TEST_SCRT_srch2_MT_D) $(RM) $(TARG_TEST_SCRT_srch2_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_MT_D) $(RM) $(OBJ_TEST_SCRT_srch2_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\test.scratch.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.scratch.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_DLL_D) $(RM) $(TARG_TEST_SCRT_srch1_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_DLL_D) $(RM) $(OBJ_TEST_SCRT_srch1_DLL_D)
	@-if exist $(TARG_TEST_SCRT_srch2_DLL_D) $(RM) $(TARG_TEST_SCRT_srch2_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_DLL_D) $(RM) $(OBJ_TEST_SCRT_srch2_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.scratch.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.scratch.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_DLL_R) $(RM) $(TARG_TEST_SCRT_srch1_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_DLL_R) $(RM) $(OBJ_TEST_SCRT_srch1_DLL_R)
	@-if exist $(TARG_TEST_SCRT_srch2_DLL_R) $(RM) $(TARG_TEST_SCRT_srch2_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_DLL_R) $(RM) $(OBJ_TEST_SCRT_srch2_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_MT_R) $(RM) $(TARG_TEST_SCRT_srch1_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_MT_R) $(RM) $(OBJ_TEST_SCRT_srch1_MT_R)
	@-if exist $(TARG_TEST_SCRT_srch2_MT_R) $(RM) $(TARG_TEST_SCRT_srch2_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_MT_R) $(RM) $(OBJ_TEST_SCRT_srch2_MT_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_W_MT_D) $(RM) $(TARG_TEST_SCRT_srch1_W_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_W_MT_D) $(RM) $(OBJ_TEST_SCRT_srch1_W_MT_D)
	@-if exist $(TARG_TEST_SCRT_srch2_W_MT_D) $(RM) $(TARG_TEST_SCRT_srch2_W_MT_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_W_MT_D) $(RM) $(OBJ_TEST_SCRT_srch2_W_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\test.scratch.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.scratch.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_W_DLL_D) $(RM) $(TARG_TEST_SCRT_srch1_W_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_srch1_W_DLL_D) $(RM) $(OBJ_TEST_SCRT_srch1_W_DLL_D)
	@-if exist $(TARG_TEST_SCRT_srch2_W_DLL_D) $(RM) $(TARG_TEST_SCRT_srch2_W_DLL_D)
	@-if exist $(OBJ_TEST_SCRT_srch2_W_DLL_D) $(RM) $(OBJ_TEST_SCRT_srch2_W_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.scratch.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.scratch.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_W_DLL_R) $(RM) $(TARG_TEST_SCRT_srch1_W_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_W_DLL_R) $(RM) $(OBJ_TEST_SCRT_srch1_W_DLL_R)
	@-if exist $(TARG_TEST_SCRT_srch2_W_DLL_R) $(RM) $(TARG_TEST_SCRT_srch2_W_DLL_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_W_DLL_R) $(RM) $(OBJ_TEST_SCRT_srch2_W_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest
	@-if exist $(TARG_TEST_SCRT_srch1_W_MT_R) $(RM) $(TARG_TEST_SCRT_srch1_W_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch1_W_MT_R) $(RM) $(OBJ_TEST_SCRT_srch1_W_MT_R)
	@-if exist $(TARG_TEST_SCRT_srch2_W_MT_R) $(RM) $(TARG_TEST_SCRT_srch2_W_MT_R)
	@-if exist $(OBJ_TEST_SCRT_srch2_W_MT_R) $(RM) $(OBJ_TEST_SCRT_srch2_W_MT_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.scratch.*.manifest

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
	@-if exist $(PROJ_OBJ_DIR)\test.unit.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_DLL_D) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_DLL_D) $(RM) $(TARG_TEST_UNIT_api_drvrel_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_drvrel_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_DLL_D) $(RM) $(TARG_TEST_UNIT_api_sqzpath_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_DLL_D)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_DLL_D) $(RM) $(TARG_TEST_UNIT_c_retcodes_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_DLL_D) $(RM) $(OBJ_TEST_UNIT_c_retcodes_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.unit.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_DLL_R) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_DLL_R) $(RM) $(TARG_TEST_UNIT_api_drvrel_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_drvrel_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_DLL_R) $(RM) $(TARG_TEST_UNIT_api_sqzpath_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_DLL_R)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_DLL_R) $(RM) $(TARG_TEST_UNIT_c_retcodes_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_DLL_R) $(RM) $(OBJ_TEST_UNIT_c_retcodes_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
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
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_W_MT_D) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_W_MT_D) $(RM) $(TARG_TEST_UNIT_api_drvrel_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_W_MT_D) $(RM) $(OBJ_TEST_UNIT_api_drvrel_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_W_MT_D) $(RM) $(TARG_TEST_UNIT_api_sqzpath_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_W_MT_D) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_W_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_W_MT_D) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_W_MT_D) $(RM) $(TARG_TEST_UNIT_c_retcodes_W_MT_D)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_W_MT_D) $(RM) $(OBJ_TEST_UNIT_c_retcodes_W_MT_D)
	@-if exist $(PROJ_OBJ_DIR)\test.unit.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_D) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_W_DLL_D) $(RM) $(TARG_TEST_UNIT_api_drvrel_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_drvrel_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_W_DLL_D) $(RM) $(TARG_TEST_UNIT_api_sqzpath_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_D) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_W_DLL_D) $(RM) $(TARG_TEST_UNIT_c_retcodes_W_DLL_D)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_W_DLL_D) $(RM) $(OBJ_TEST_UNIT_c_retcodes_W_DLL_D)
	@-if exist $(PROJ_OBJ_DIR)\test.unit.*.pdb $(RM) $(PROJ_OBJ_DIR)\test.unit.*.pdb
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_R) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_W_DLL_R) $(RM) $(TARG_TEST_UNIT_api_drvrel_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_drvrel_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_W_DLL_R) $(RM) $(TARG_TEST_UNIT_api_sqzpath_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_R) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_W_DLL_R) $(RM) $(TARG_TEST_UNIT_c_retcodes_W_DLL_R)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_W_DLL_R) $(RM) $(OBJ_TEST_UNIT_c_retcodes_W_DLL_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest
	@-if exist $(TARG_TEST_UNIT_api_cmbpaths_W_MT_R) $(RM) $(TARG_TEST_UNIT_api_cmbpaths_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R) $(RM) $(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_drvrel_W_MT_R) $(RM) $(TARG_TEST_UNIT_api_drvrel_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_drvrel_W_MT_R) $(RM) $(OBJ_TEST_UNIT_api_drvrel_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_api_sqzpath_W_MT_R) $(RM) $(TARG_TEST_UNIT_api_sqzpath_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_api_sqzpath_W_MT_R) $(RM) $(OBJ_TEST_UNIT_api_sqzpath_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_drvrel_W_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_drvrel_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_sqzpath_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_cpp_retcodes_W_MT_R) $(RM) $(TARG_TEST_UNIT_cpp_retcodes_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R) $(RM) $(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R)
	@-if exist $(TARG_TEST_UNIT_c_retcodes_W_MT_R) $(RM) $(TARG_TEST_UNIT_c_retcodes_W_MT_R)
	@-if exist $(OBJ_TEST_UNIT_c_retcodes_W_MT_R) $(RM) $(OBJ_TEST_UNIT_c_retcodes_W_MT_R)
	@-if exist $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest $(RM) $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test.unit.*.manifest

clean.test:                                         clean.test.unit clean.test.component clean.test.scratch

clean:                                              clean.libs clean.test clean.examples clean.samples

clean.all:                                          clean


############################################################################
# build targets

##################################################
# Libraries

########################################
# Main library - 'recls.X.core.a'

$(LIB_CORE_MT_D): $(OBJ_CORE_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_D)

$(OBJ_CR_api_entryinfo_MT_D): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_MT_D): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_MT_D): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_MT_D): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_D): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_D): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_D): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_D): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_D): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_D): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_MT_D): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_MT_D): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_MT_D): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_D): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_D): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_D): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_D): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_MT_D): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_D): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_D): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_MT_D): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_MT_D): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_MT_D): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_MT_D): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_MT_D): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_MT_D): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_DLL_D): $(OBJ_CORE_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_D)

$(OBJ_CR_api_entryinfo_DLL_D): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_DLL_D): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_DLL_D): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_DLL_D): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_DLL_D): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_DLL_D): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_DLL_D): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_DLL_D): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_DLL_D): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_DLL_D): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_DLL_D): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_DLL_D): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_DLL_D): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_DLL_D): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_DLL_D): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_DLL_D): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_DLL_D): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_DLL_D): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_DLL_D): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_DLL_D): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_DLL_D): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_DLL_D): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_DLL_D): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_DLL_D): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_DLL_D): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_DLL_D): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_DLL_R): $(OBJ_CORE_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_DLL_R)

$(OBJ_CR_api_entryinfo_DLL_R): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_DLL_R): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_DLL_R): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_DLL_R): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_DLL_R): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_DLL_R): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_DLL_R): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_DLL_R): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_DLL_R): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_DLL_R): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_DLL_R): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_DLL_R): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_DLL_R): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_DLL_R): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_DLL_R): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_DLL_R): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_DLL_R): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_DLL_R): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_DLL_R): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_DLL_R): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_DLL_R): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_DLL_R): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_DLL_R): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_DLL_R): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_DLL_R): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_DLL_R): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_MT_R): $(OBJ_CORE_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_MT_R)

$(OBJ_CR_api_entryinfo_MT_R): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_MT_R): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_MT_R): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_MT_R): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_MT_R): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_MT_R): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_MT_R): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_MT_R): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_MT_R): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_MT_R): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_MT_R): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_MT_R): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_MT_R): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_MT_R): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_MT_R): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_MT_R): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_MT_R): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_MT_R): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_MT_R): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_MT_R): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_MT_R): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_MT_R): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_MT_R): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_MT_R): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_MT_R): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_MT_R): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_W_MT_D): $(OBJ_CORE_W_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_W_MT_D)

$(OBJ_CR_api_entryinfo_W_MT_D): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_W_MT_D): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_W_MT_D): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_W_MT_D): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_W_MT_D): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_W_MT_D): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_W_MT_D): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_W_MT_D): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_W_MT_D): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_W_MT_D): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_W_MT_D): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_W_MT_D): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_W_MT_D): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_W_MT_D): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_W_MT_D): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_W_MT_D): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_W_MT_D): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_W_MT_D): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_W_MT_D): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_W_MT_D): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_W_MT_D): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_W_MT_D): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_W_MT_D): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_W_MT_D): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_W_MT_D): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_W_MT_D): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_W_DLL_D): $(OBJ_CORE_W_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_W_DLL_D)

$(OBJ_CR_api_entryinfo_W_DLL_D): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_W_DLL_D): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_W_DLL_D): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_W_DLL_D): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_W_DLL_D): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_W_DLL_D): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_W_DLL_D): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_W_DLL_D): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_W_DLL_D): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_W_DLL_D): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_W_DLL_D): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_W_DLL_D): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_W_DLL_D): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_W_DLL_D): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_W_DLL_D): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_W_DLL_D): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_W_DLL_D): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_W_DLL_D): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_W_DLL_D): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_W_DLL_D): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_W_DLL_D): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_W_DLL_D): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_W_DLL_D): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_W_DLL_D): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_W_DLL_D): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_W_DLL_D): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_W_DLL_R): $(OBJ_CORE_W_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_W_DLL_R)

$(OBJ_CR_api_entryinfo_W_DLL_R): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_W_DLL_R): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_W_DLL_R): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_W_DLL_R): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_W_DLL_R): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_W_DLL_R): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_W_DLL_R): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_W_DLL_R): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_W_DLL_R): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_W_DLL_R): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_W_DLL_R): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_W_DLL_R): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_W_DLL_R): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_W_DLL_R): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_W_DLL_R): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_W_DLL_R): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_W_DLL_R): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_W_DLL_R): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_W_DLL_R): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_W_DLL_R): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_W_DLL_R): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_W_DLL_R): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_W_DLL_R): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_W_DLL_R): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_W_DLL_R): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_W_DLL_R): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp


$(LIB_CORE_W_MT_R): $(OBJ_CORE_W_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_CORE_W_MT_R)

$(OBJ_CR_api_entryinfo_W_MT_R): $(PROJ_SRC_DIR)\api.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.entryinfo.cpp
$(OBJ_CR_api_error_W_MT_R): $(PROJ_SRC_DIR)\api.error.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.error.cpp
$(OBJ_CR_api_extended_W_MT_R): $(PROJ_SRC_DIR)\api.extended.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.extended.cpp
$(OBJ_CR_api_combpath_W_MT_R): $(PROJ_SRC_DIR)\api.util.combine_paths.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.combine_paths.cpp
$(OBJ_CR_api_derrpath_W_MT_R): $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.derive_relative_path.cpp
$(OBJ_CR_api_getflsizs_W_MT_R): $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.get_file_sizes.cpp
$(OBJ_CR_api_sqzpath_W_MT_R): $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.squeeze_path.cpp
$(OBJ_CR_api_stat_W_MT_R): $(PROJ_SRC_DIR)\api.util.stat.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.stat.cpp
$(OBJ_CR_api_crdir_W_MT_R): $(PROJ_SRC_DIR)\api.util.create_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.create_directory.cpp
$(OBJ_CR_api_rmdir_W_MT_R): $(PROJ_SRC_DIR)\api.util.remove_directory.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.util.remove_directory.cpp
$(OBJ_CR_api_rc_win_W_MT_R): $(PROJ_SRC_DIR)\api.retcodes.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.retcodes.windows.cpp
$(OBJ_CR_api_search_W_MT_R): $(PROJ_SRC_DIR)\api.search.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.search.cpp
$(OBJ_CR_impl_debug_W_MT_R): $(PROJ_SRC_DIR)\impl.trace.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.trace.cpp
$(OBJ_CR_impl_entryinfo_W_MT_R): $(PROJ_SRC_DIR)\impl.entryinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.entryinfo.cpp
$(OBJ_CR_impl_fileinfo_W_MT_R): $(PROJ_SRC_DIR)\impl.fileinfo.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.cpp
$(OBJ_CR_impl_snprintf_W_MT_R): $(PROJ_SRC_DIR)\impl.snprintf.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.snprintf.cpp
$(OBJ_CR_impl_util_W_MT_R): $(PROJ_SRC_DIR)\impl.util.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.cpp
$(OBJ_CR_Srch_W_MT_R): $(PROJ_SRC_DIR)\ReclsSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsSearch.cpp
$(OBJ_CR_FlSrch_W_MT_R): $(PROJ_SRC_DIR)\ReclsFileSearch.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearch.cpp
$(OBJ_CR_FlSchDirNode_W_MT_R): $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFileSearchDirectoryNode.cpp
$(OBJ_CR_api_win64_W_MT_R): $(PROJ_SRC_DIR)\api.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.windows.cpp
$(OBJ_CR_impl_fileinfo_win64_W_MT_R): $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.fileinfo.windows.cpp
$(OBJ_CR_impl_util_win64_W_MT_R): $(PROJ_SRC_DIR)\impl.util.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\impl.util.windows.cpp
$(OBJ_CR_api_ftp_windows_W_MT_R): $(PROJ_SRC_DIR)\api.ftp.windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\api.ftp.windows.cpp
$(OBJ_CR_FtpSchDirNode_win_W_MT_R): $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearchDirectoryNode_windows.cpp
$(OBJ_CR_FtpSrch_windows_W_MT_R): $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_SRC_DIR)\ReclsFtpSearch_windows.cpp



########################################
# shwild library - 'shwild.X.core.a'

$(LIB_SHWILD_MT_D): $(OBJ_SHWILD_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_D)

$(OBJ_shw_api_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_SHWILD_INCLUDES_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_D): $(OBJ_SHWILD_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_D)

$(OBJ_shw_api_DLL_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_SHWILD_INCLUDES_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_DLL_R): $(OBJ_SHWILD_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_DLL_R)

$(OBJ_shw_api_DLL_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_DLL_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_DLL_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_SHWILD_INCLUDES_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_MT_R): $(OBJ_SHWILD_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_MT_R)

$(OBJ_shw_api_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_SHWILD_INCLUDES_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_W_MT_D): $(OBJ_SHWILD_W_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_W_MT_D)

$(OBJ_shw_api_W_MT_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) $(CPPC_SHWILD_INCLUDES_W_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_W_MT_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) $(CPPC_SHWILD_INCLUDES_W_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_W_MT_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) $(CPPC_SHWILD_INCLUDES_W_MT_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_W_DLL_D): $(OBJ_SHWILD_W_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_W_DLL_D)

$(OBJ_shw_api_W_DLL_D): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) $(CPPC_SHWILD_INCLUDES_W_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_W_DLL_D): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) $(CPPC_SHWILD_INCLUDES_W_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_W_DLL_D): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) $(CPPC_SHWILD_INCLUDES_W_DLL_D) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_W_DLL_R): $(OBJ_SHWILD_W_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_W_DLL_R)

$(OBJ_shw_api_W_DLL_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) $(CPPC_SHWILD_INCLUDES_W_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_W_DLL_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) $(CPPC_SHWILD_INCLUDES_W_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_W_DLL_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) $(CPPC_SHWILD_INCLUDES_W_DLL_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp

$(LIB_SHWILD_W_MT_R): $(OBJ_SHWILD_W_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_SHWILD_W_MT_R)

$(OBJ_shw_api_W_MT_R): $(SHWILD_SRC_DIR)\api.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) $(CPPC_SHWILD_INCLUDES_W_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\api.cpp
$(OBJ_shw_matches_W_MT_R): $(SHWILD_SRC_DIR)\matches.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) $(CPPC_SHWILD_INCLUDES_W_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\matches.cpp
$(OBJ_shw_pattern_W_MT_R): $(SHWILD_SRC_DIR)\pattern.cpp $(SHWILD_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) $(CPPC_SHWILD_INCLUDES_W_MT_R) -Fo$@ $(SHWILD_SRC_DIR)\pattern.cpp


########################################
# xCover library - 'xcover.X.recls.core.a'

$(LIB_XCOVER_MT_D): $(OBJ_XCOVER_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_MT_D)

$(OBJ_xcv_core_MT_D): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XCOVER_INCLUDES_MT_D) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_DLL_D): $(OBJ_XCOVER_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_DLL_D)

$(OBJ_xcv_core_DLL_D): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_XCOVER_INCLUDES_DLL_D) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_DLL_R): $(OBJ_XCOVER_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_DLL_R)

$(OBJ_xcv_core_DLL_R): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_XCOVER_INCLUDES_DLL_R) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_MT_R): $(OBJ_XCOVER_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_MT_R)

$(OBJ_xcv_core_MT_R): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XCOVER_INCLUDES_MT_R) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_W_MT_D): $(OBJ_XCOVER_W_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_W_MT_D)

$(OBJ_xcv_core_W_MT_D): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) $(CPPC_XCOVER_INCLUDES_W_MT_D) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_W_DLL_D): $(OBJ_XCOVER_W_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_W_DLL_D)

$(OBJ_xcv_core_W_DLL_D): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) $(CPPC_XCOVER_INCLUDES_W_DLL_D) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_W_DLL_R): $(OBJ_XCOVER_W_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_W_DLL_R)

$(OBJ_xcv_core_W_DLL_R): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) $(CPPC_XCOVER_INCLUDES_W_DLL_R) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp

$(LIB_XCOVER_W_MT_R): $(OBJ_XCOVER_W_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XCOVER_W_MT_R)

$(OBJ_xcv_core_W_MT_R): $(XCOVER_SRC_DIR)\xcover.core.cpp $(XCOVER_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) $(CPPC_XCOVER_INCLUDES_W_MT_R) -Fo$@ $(XCOVER_SRC_DIR)\xcover.core.cpp


########################################
# xTests library - 'xtests.X.recls.core.a'

$(LIB_XTESTS_MT_D): $(OBJ_XTESTS_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_D)

$(OBJ_xts_core_MT_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) $(CPPC_XTESTS_INCLUDES_MT_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_D): $(OBJ_XTESTS_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_D)

$(OBJ_xts_core_DLL_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) $(CPPC_XTESTS_INCLUDES_DLL_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_DLL_R): $(OBJ_XTESTS_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_DLL_R)

$(OBJ_xts_core_DLL_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) $(CPPC_XTESTS_INCLUDES_DLL_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_MT_R): $(OBJ_XTESTS_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_MT_R)

$(OBJ_xts_core_MT_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) $(CPPC_XTESTS_INCLUDES_MT_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_W_MT_D): $(OBJ_XTESTS_W_MT_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_W_MT_D)

$(OBJ_xts_core_W_MT_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) $(CPPC_XTESTS_INCLUDES_W_MT_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_W_DLL_D): $(OBJ_XTESTS_W_DLL_D) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_W_DLL_D)

$(OBJ_xts_core_W_DLL_D): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) $(CPPC_XTESTS_INCLUDES_W_DLL_D) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_W_DLL_R): $(OBJ_XTESTS_W_DLL_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_W_DLL_R)

$(OBJ_xts_core_W_DLL_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) $(CPPC_XTESTS_INCLUDES_W_DLL_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp

$(LIB_XTESTS_W_MT_R): $(OBJ_XTESTS_W_MT_R) $(PROJ_MAKEFILE_NAME)
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_XTESTS_W_MT_R)

$(OBJ_xts_core_W_MT_R): $(XTESTS_SRC_DIR)\xtests.core.cpp $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) $(CPPC_XTESTS_INCLUDES_W_MT_R) -Fo$@ $(XTESTS_SRC_DIR)\xtests.core.cpp


##################################################
# Examples

$(TARG_EX_ex_c_1_MT_D):    \
		$(OBJ_EX_ex_c_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_1_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_DLL_D):    \
		$(OBJ_EX_ex_c_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_1_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_DLL_R):    \
		$(OBJ_EX_ex_c_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_1_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_MT_R):    \
		$(OBJ_EX_ex_c_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_1_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_W_MT_D):    \
		$(OBJ_EX_ex_c_1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_1_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_W_DLL_D):    \
		$(OBJ_EX_ex_c_1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_1_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_W_DLL_R):    \
		$(OBJ_EX_ex_c_1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_1_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_1_W_MT_R):    \
		$(OBJ_EX_ex_c_1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_1_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c

$(TARG_EX_ex_c_2_MT_D):    \
		$(OBJ_EX_ex_c_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_2_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_DLL_D):    \
		$(OBJ_EX_ex_c_2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_2_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_DLL_R):    \
		$(OBJ_EX_ex_c_2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_2_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_MT_R):    \
		$(OBJ_EX_ex_c_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_2_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_W_MT_D):    \
		$(OBJ_EX_ex_c_2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_2_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_W_DLL_D):    \
		$(OBJ_EX_ex_c_2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_2_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_W_DLL_R):    \
		$(OBJ_EX_ex_c_2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_2_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_2_W_MT_R):    \
		$(OBJ_EX_ex_c_2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_2_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c

$(TARG_EX_ex_c_3_MT_D):    \
		$(OBJ_EX_ex_c_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_3_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_DLL_D):    \
		$(OBJ_EX_ex_c_3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_3_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_DLL_R):    \
		$(OBJ_EX_ex_c_3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_3_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_MT_R):    \
		$(OBJ_EX_ex_c_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_3_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_W_MT_D):    \
		$(OBJ_EX_ex_c_3_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_3_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_3_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_W_DLL_D):    \
		$(OBJ_EX_ex_c_3_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_3_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_3_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_W_DLL_R):    \
		$(OBJ_EX_ex_c_3_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_3_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_3_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_3_W_MT_R):    \
		$(OBJ_EX_ex_c_3_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_3_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_3_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c

$(TARG_EX_ex_c_4_MT_D):    \
		$(OBJ_EX_ex_c_4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_4_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_4_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_DLL_D):    \
		$(OBJ_EX_ex_c_4_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_4_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_4_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_DLL_R):    \
		$(OBJ_EX_ex_c_4_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_4_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_4_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_MT_R):    \
		$(OBJ_EX_ex_c_4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_4_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_4_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_W_MT_D):    \
		$(OBJ_EX_ex_c_4_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_4_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_4_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_W_DLL_D):    \
		$(OBJ_EX_ex_c_4_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_4_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_4_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_W_DLL_R):    \
		$(OBJ_EX_ex_c_4_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_4_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_4_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_4_W_MT_R):    \
		$(OBJ_EX_ex_c_4_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_4_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_4_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c

$(TARG_EX_ex_c_5_MT_D):    \
		$(OBJ_EX_ex_c_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_5_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_5_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_DLL_D):    \
		$(OBJ_EX_ex_c_5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_5_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_5_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_DLL_R):    \
		$(OBJ_EX_ex_c_5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_5_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_5_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_MT_R):    \
		$(OBJ_EX_ex_c_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_5_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_5_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_W_MT_D):    \
		$(OBJ_EX_ex_c_5_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_5_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_5_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_W_DLL_D):    \
		$(OBJ_EX_ex_c_5_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_5_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_5_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_W_DLL_R):    \
		$(OBJ_EX_ex_c_5_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_5_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_5_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_5_W_MT_R):    \
		$(OBJ_EX_ex_c_5_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_5_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_5_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c

$(TARG_EX_ex_c_6_MT_D):    \
		$(OBJ_EX_ex_c_6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_6_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_6_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_DLL_D):    \
		$(OBJ_EX_ex_c_6_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_6_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_6_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_DLL_R):    \
		$(OBJ_EX_ex_c_6_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_6_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_6_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_MT_R):    \
		$(OBJ_EX_ex_c_6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_6_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_6_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_W_MT_D):    \
		$(OBJ_EX_ex_c_6_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_6_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_6_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_W_DLL_D):    \
		$(OBJ_EX_ex_c_6_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_6_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_6_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_W_DLL_R):    \
		$(OBJ_EX_ex_c_6_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_6_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_6_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_6_W_MT_R):    \
		$(OBJ_EX_ex_c_6_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_6_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_6_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c

$(TARG_EX_ex_c_7_MT_D):    \
		$(OBJ_EX_ex_c_7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_7_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_7_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_DLL_D):    \
		$(OBJ_EX_ex_c_7_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_7_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_7_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_DLL_R):    \
		$(OBJ_EX_ex_c_7_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_7_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_7_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_MT_R):    \
		$(OBJ_EX_ex_c_7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_7_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_7_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_W_MT_D):    \
		$(OBJ_EX_ex_c_7_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_7_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_7_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_W_DLL_D):    \
		$(OBJ_EX_ex_c_7_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_7_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_7_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_W_DLL_R):    \
		$(OBJ_EX_ex_c_7_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_7_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_7_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_7_W_MT_R):    \
		$(OBJ_EX_ex_c_7_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_7_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_7_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c

$(TARG_EX_ex_c_8_MT_D):    \
		$(OBJ_EX_ex_c_8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_8_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_c_8_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_DLL_D):    \
		$(OBJ_EX_ex_c_8_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_8_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_c_8_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_DLL_R):    \
		$(OBJ_EX_ex_c_8_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_8_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_c_8_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_MT_R):    \
		$(OBJ_EX_ex_c_8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_8_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_c_8_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_W_MT_D):    \
		$(OBJ_EX_ex_c_8_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_c_8_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_c_8_W_MT_D): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_W_DLL_D):    \
		$(OBJ_EX_ex_c_8_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_c_8_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_c_8_W_DLL_D): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_W_DLL_R):    \
		$(OBJ_EX_ex_c_8_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_c_8_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_c_8_W_DLL_R): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

$(TARG_EX_ex_c_8_W_MT_R):    \
		$(OBJ_EX_ex_c_8_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_c_8_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_c_8_W_MT_R): $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c


$(TARG_EX_ex_cpp_1_MT_D):    \
		$(OBJ_EX_ex_cpp_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_1_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_DLL_D):    \
		$(OBJ_EX_ex_cpp_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_cpp_1_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_DLL_R):    \
		$(OBJ_EX_ex_cpp_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_cpp_1_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_MT_R):    \
		$(OBJ_EX_ex_cpp_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_1_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_W_MT_D):    \
		$(OBJ_EX_ex_cpp_1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_cpp_1_W_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_W_DLL_D):    \
		$(OBJ_EX_ex_cpp_1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_cpp_1_W_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_W_DLL_R):    \
		$(OBJ_EX_ex_cpp_1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_cpp_1_W_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_1_W_MT_R):    \
		$(OBJ_EX_ex_cpp_1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_cpp_1_W_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp

$(TARG_EX_ex_cpp_2_MT_D):    \
		$(OBJ_EX_ex_cpp_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_2_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_DLL_D):    \
		$(OBJ_EX_ex_cpp_2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_cpp_2_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_DLL_R):    \
		$(OBJ_EX_ex_cpp_2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_cpp_2_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_MT_R):    \
		$(OBJ_EX_ex_cpp_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_2_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_W_MT_D):    \
		$(OBJ_EX_ex_cpp_2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_cpp_2_W_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_W_DLL_D):    \
		$(OBJ_EX_ex_cpp_2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_cpp_2_W_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_W_DLL_R):    \
		$(OBJ_EX_ex_cpp_2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_cpp_2_W_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_2_W_MT_R):    \
		$(OBJ_EX_ex_cpp_2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_cpp_2_W_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp

$(TARG_EX_ex_cpp_3_MT_D):    \
		$(OBJ_EX_ex_cpp_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_3_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_EX_ex_cpp_3_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_DLL_D):    \
		$(OBJ_EX_ex_cpp_3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_3_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_EX_ex_cpp_3_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_DLL_R):    \
		$(OBJ_EX_ex_cpp_3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_3_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_EX_ex_cpp_3_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_MT_R):    \
		$(OBJ_EX_ex_cpp_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_3_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_EX_ex_cpp_3_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_W_MT_D):    \
		$(OBJ_EX_ex_cpp_3_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_EX_ex_cpp_3_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_EX_ex_cpp_3_W_MT_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_W_DLL_D):    \
		$(OBJ_EX_ex_cpp_3_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_EX_ex_cpp_3_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_EX_ex_cpp_3_W_DLL_D): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_W_DLL_R):    \
		$(OBJ_EX_ex_cpp_3_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_EX_ex_cpp_3_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_EX_ex_cpp_3_W_DLL_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp

$(TARG_EX_ex_cpp_3_W_MT_R):    \
		$(OBJ_EX_ex_cpp_3_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_EX_ex_cpp_3_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_EX_ex_cpp_3_W_MT_R): $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp


##################################################
# Tests




##############################
# Component Tests

$(TARG_TEST_COMP_api_crdir_MT_D):    \
		$(OBJ_TEST_COMP_api_crdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_api_crdir_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_DLL_D):    \
		$(OBJ_TEST_COMP_api_crdir_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_api_crdir_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_DLL_R):    \
		$(OBJ_TEST_COMP_api_crdir_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_api_crdir_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_MT_R):    \
		$(OBJ_TEST_COMP_api_crdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_api_crdir_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_W_MT_D):    \
		$(OBJ_TEST_COMP_api_crdir_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_COMP_api_crdir_W_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_W_DLL_D):    \
		$(OBJ_TEST_COMP_api_crdir_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_COMP_api_crdir_W_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_W_DLL_R):    \
		$(OBJ_TEST_COMP_api_crdir_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_COMP_api_crdir_W_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_crdir_W_MT_R):    \
		$(OBJ_TEST_COMP_api_crdir_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_api_crdir_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_COMP_api_crdir_W_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.create_directory\test.component.util.cpp.create_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_D):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_COMP_api_rmdir_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_DLL_D):    \
		$(OBJ_TEST_COMP_api_rmdir_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_COMP_api_rmdir_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_DLL_R):    \
		$(OBJ_TEST_COMP_api_rmdir_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_COMP_api_rmdir_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_MT_R):    \
		$(OBJ_TEST_COMP_api_rmdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_COMP_api_rmdir_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_W_MT_D):    \
		$(OBJ_TEST_COMP_api_rmdir_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_COMP_api_rmdir_W_MT_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_W_DLL_D):    \
		$(OBJ_TEST_COMP_api_rmdir_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_COMP_api_rmdir_W_DLL_D): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_W_DLL_R):    \
		$(OBJ_TEST_COMP_api_rmdir_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_COMP_api_rmdir_W_DLL_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp

$(TARG_TEST_COMP_api_rmdir_W_MT_R):    \
		$(OBJ_TEST_COMP_api_rmdir_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_COMP_api_rmdir_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_COMP_api_rmdir_W_MT_R): $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_COMPONENT_DIR)\test.component.util.cpp.remove_directory\test.component.util.cpp.remove_directory.cpp


##############################
# Scratch Tests

$(TARG_TEST_SCRT_srch1_MT_D):    \
		$(OBJ_TEST_SCRT_srch1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_srch1_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_DLL_D):    \
		$(OBJ_TEST_SCRT_srch1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_srch1_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_DLL_R):    \
		$(OBJ_TEST_SCRT_srch1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_srch1_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_MT_R):    \
		$(OBJ_TEST_SCRT_srch1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_srch1_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_W_MT_D):    \
		$(OBJ_TEST_SCRT_srch1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_SCRT_srch1_W_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_W_DLL_D):    \
		$(OBJ_TEST_SCRT_srch1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_SCRT_srch1_W_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_W_DLL_R):    \
		$(OBJ_TEST_SCRT_srch1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_SCRT_srch1_W_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch1_W_MT_R):    \
		$(OBJ_TEST_SCRT_srch1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch1_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_SCRT_srch1_W_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.1\test.scratch.search.1.c


$(TARG_TEST_SCRT_srch2_MT_D):    \
		$(OBJ_TEST_SCRT_srch2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_SCRT_srch2_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_DLL_D):    \
		$(OBJ_TEST_SCRT_srch2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_SCRT_srch2_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_DLL_R):    \
		$(OBJ_TEST_SCRT_srch2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_SCRT_srch2_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_MT_R):    \
		$(OBJ_TEST_SCRT_srch2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_SCRT_srch2_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_W_MT_D):    \
		$(OBJ_TEST_SCRT_srch2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_SCRT_srch2_W_MT_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_W_DLL_D):    \
		$(OBJ_TEST_SCRT_srch2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_SCRT_srch2_W_DLL_D): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_W_DLL_R):    \
		$(OBJ_TEST_SCRT_srch2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_SCRT_srch2_W_DLL_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


$(TARG_TEST_SCRT_srch2_W_MT_R):    \
		$(OBJ_TEST_SCRT_srch2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_SCRT_srch2_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_SCRT_srch2_W_MT_R): $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_SCRATCH_DIR)\test.scratch.search.2\test.scratch.search.2.c


##############################
# Unit Tests

$(TARG_TEST_UNIT_api_cmbpaths_MT_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_DLL_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_cmbpaths_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_DLL_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_cmbpaths_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_MT_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_cmbpaths_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_W_MT_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_W_DLL_D):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_W_DLL_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_api_cmbpaths_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_cmbpaths_W_MT_R):    \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_api_cmbpaths_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.combine_paths\test.unit.api.combine_paths.c

$(TARG_TEST_UNIT_api_drvrel_MT_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_drvrel_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_DLL_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_drvrel_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_DLL_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_drvrel_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_MT_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_drvrel_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_W_MT_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_api_drvrel_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_W_DLL_D):    \
		$(OBJ_TEST_UNIT_api_drvrel_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_api_drvrel_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_W_DLL_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_api_drvrel_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_drvrel_W_MT_R):    \
		$(OBJ_TEST_UNIT_api_drvrel_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_drvrel_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_api_drvrel_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.derive_relative_path\test.unit.api.derive_relative_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_api_sqzpath_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_DLL_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_api_sqzpath_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_DLL_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_api_sqzpath_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_MT_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_api_sqzpath_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_W_MT_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_api_sqzpath_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_W_DLL_D):    \
		$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_W_DLL_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_api_sqzpath_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c

$(TARG_TEST_UNIT_api_sqzpath_W_MT_R):    \
		$(OBJ_TEST_UNIT_api_sqzpath_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_api_sqzpath_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_api_sqzpath_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.api.squeeze_path\test.unit.api.squeeze_path.c


$(TARG_TEST_UNIT_cpp_cmbpaths_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_W_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_cmbpaths_W_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_cpp_cmbpaths_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.combine_paths\test.unit.cpp.combine_paths.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_cpp_drvrel_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_cpp_drvrel_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_drvrel_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_W_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_W_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_W_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_cpp_drvrel_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_drvrel_W_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_cpp_drvrel_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.derive_relative_path\test.unit.cpp.derive_relative_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_W_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_W_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_sqzpath_W_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_cpp_sqzpath_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.squeeze_path\test.unit.cpp.squeeze_path.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_cpp_retcodes_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_cpp_retcodes_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_cpp_retcodes_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_W_MT_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_W_DLL_D):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_W_DLL_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_cpp_retcodes_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_cpp_retcodes_W_MT_R):    \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_cpp_retcodes_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp $(CPP_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CPPC) $(CPPC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.cpp.retcodes\test.unit.cpp.retcodes.cpp

$(TARG_TEST_UNIT_c_retcodes_MT_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_D)\
		$(LIB_CORE_MT_D)\
		$(LIB_SHWILD_MT_D)\
		$(LIB_XCOVER_MT_D)\
		$(LIB_XTESTS_MT_D)\
		$(TARGET_LIB_MT_D)

$(OBJ_TEST_UNIT_c_retcodes_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_DLL_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_DLL_D)\
		$(LIB_CORE_DLL_D)\
		$(LIB_SHWILD_DLL_D)\
		$(LIB_XCOVER_DLL_D)\
		$(LIB_XTESTS_DLL_D)\
		$(TARGET_LIB_DLL_D)

$(OBJ_TEST_UNIT_c_retcodes_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_DLL_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_DLL_R)\
		$(LIB_CORE_DLL_R)\
		$(LIB_SHWILD_DLL_R)\
		$(LIB_XCOVER_DLL_R)\
		$(LIB_XTESTS_DLL_R)\
		$(TARGET_LIB_DLL_R)

$(OBJ_TEST_UNIT_c_retcodes_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_MT_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_MT_R)\
		$(LIB_CORE_MT_R)\
		$(LIB_SHWILD_MT_R)\
		$(LIB_XCOVER_MT_R)\
		$(LIB_XTESTS_MT_R)\
		$(TARGET_LIB_MT_R)

$(OBJ_TEST_UNIT_c_retcodes_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_W_MT_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_D) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_W_MT_D)\
		$(LIB_CORE_W_MT_D)\
		$(LIB_SHWILD_W_MT_D)\
		$(LIB_XCOVER_W_MT_D)\
		$(LIB_XTESTS_W_MT_D)\
		$(TARGET_LIB_W_MT_D)

$(OBJ_TEST_UNIT_c_retcodes_W_MT_D): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_W_DLL_D):    \
		$(OBJ_TEST_UNIT_c_retcodes_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_D) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_W_DLL_D)\
		$(LIB_CORE_W_DLL_D)\
		$(LIB_SHWILD_W_DLL_D)\
		$(LIB_XCOVER_W_DLL_D)\
		$(LIB_XTESTS_W_DLL_D)\
		$(TARGET_LIB_W_DLL_D)

$(OBJ_TEST_UNIT_c_retcodes_W_DLL_D): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_D) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_W_DLL_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_DLL_R) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_W_DLL_R)\
		$(LIB_CORE_W_DLL_R)\
		$(LIB_SHWILD_W_DLL_R)\
		$(LIB_XCOVER_W_DLL_R)\
		$(LIB_XTESTS_W_DLL_R)\
		$(TARGET_LIB_W_DLL_R)

$(OBJ_TEST_UNIT_c_retcodes_W_DLL_R): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_DLL_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c

$(TARG_TEST_UNIT_c_retcodes_W_MT_R):    \
		$(OBJ_TEST_UNIT_c_retcodes_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(PROJ_MAKEFILE_NAME)
	$(LD) $(LD_ARGS_W_MT_R) -out:$@ \
		$(OBJ_TEST_UNIT_c_retcodes_W_MT_R)\
		$(LIB_CORE_W_MT_R)\
		$(LIB_SHWILD_W_MT_R)\
		$(LIB_XCOVER_W_MT_R)\
		$(LIB_XTESTS_W_MT_R)\
		$(TARGET_LIB_W_MT_R)

$(OBJ_TEST_UNIT_c_retcodes_W_MT_R): $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c $(C_API_HEADERS) $(CORE_HEADERS) $(SHWILD_HEADERS) $(XTESTS_HEADERS) $(PROJ_MAKEFILE_NAME)
	$(CC) $(CC_ARGS_W_MT_R) -Fo$@ $(PROJ_TEST_UNIT_DIR)\test.unit.c.retcodes\test.unit.c.retcodes.c


############################### end of file ################################
