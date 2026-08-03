
# ######################################################################## #
# File:     /src/CMakeLists.txt
#
# Purpose:  CMake lists file for recls core library (1.9 line)
#
# Created:  ...
# Updated:  3rd August 2026
#
# ######################################################################## #


if(_BUILD_AS_UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(_BUILD_AS_UNIX)

if(_BUILD_AS_WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()

	add_definitions(-DRECLS_API_FTP)
endif(_BUILD_AS_WIN32)

if(MSVC)
	if(MSVC_VERSION LESS 1920)

		add_compile_options("/wd4822")
	endif()

	if(MSVC_VERSION GREATER_EQUAL 1914)

		add_compile_options("/Zc:__cplusplus")

		add_definitions(-D_SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING)
	endif()
endif(MSVC)


set(COMMON_IMPLEMENTATION_FILES

	ReclsFileSearch.cpp
	ReclsFileSearchDirectoryNode.cpp
	ReclsSearch.cpp

	api.entryinfo.cpp
	api.error.cpp
	api.extended.cpp
	api.search.cpp
	api.util.combine_paths.cpp
	api.util.create_directory.cpp
	api.util.derive_relative_path.cpp
	api.util.get_file_sizes.cpp
	api.util.remove_directory.cpp
	api.util.squeeze_path.cpp
	api.util.stat.cpp

	impl.entryinfo.cpp
	impl.fileinfo.cpp
	impl.snprintf.cpp
	impl.trace.cpp
	impl.util.cpp
)

set(UNIX_IMPLEMENTATION_FILES

	api.unix.cpp

	impl.fileinfo.unix.cpp
	impl.util.unix.cpp
)

set(WINDOWS_IMPLEMENTATION_FILES

	ReclsFtpSearchDirectoryNode_windows.cpp
	ReclsFtpSearch_windows.cpp

	api.ftp.windows.cpp
	api.retcodes.windows.cpp
	api.windows.cpp

	impl.fileinfo.windows.cpp
	impl.util.windows.cpp
)


if(_BUILD_AS_UNIX)

	set(COMMON_IMPLEMENTATION_FILES "${COMMON_IMPLEMENTATION_FILES};${UNIX_IMPLEMENTATION_FILES};")
endif(_BUILD_AS_UNIX)

if(_BUILD_AS_WIN32)

	set(COMMON_IMPLEMENTATION_FILES "${COMMON_IMPLEMENTATION_FILES};${WINDOWS_IMPLEMENTATION_FILES};")
endif(_BUILD_AS_WIN32)


add_library(core
	${COMMON_IMPLEMENTATION_FILES}
)

set_target_properties(core PROPERTIES
	OUTPUT_NAME "recls"
)

target_include_directories(core
	PUBLIC
		$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
		$<INSTALL_INTERFACE:include>
)

target_link_libraries(core
	PRIVATE
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
		$<$<BOOL:${UNIXem_FOUND}>:UNIXem::UNIXem>
)

target_compile_options(core
	PRIVATE
		$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
			-Werror -Wall -Wextra -pedantic

			-Wno-deprecated-copy
			-Wno-deprecated-declarations
			-Wno-\#pragma-messages
			$<$<BOOL:CMAKE_CXX_STANDARD GREATER_EQUAL 2000>:-Wno-deprecated-volatile>
		>
		$<$<CXX_COMPILER_ID:MSVC>:
			/WX /W4
		>
)


# ##########################################################
# install

install(TARGETS core
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# install the include/recls/*/ subdirectories here, as do not (yet) know how to do so via PUBLIC_HEADER property
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/
	DESTINATION include/${PROJECT_NAME_LOWER}
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #
