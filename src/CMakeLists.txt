
if(APPLE)

	message("-- -- adding '/usr/local/include' to include-directories for 'src'")

	include_directories("/usr/local/include")
endif(APPLE)

if(UNIX)

	add_definitions(-DUNIX)
	add_definitions(-Dunix)
endif(UNIX)

if(WIN32)

	if(CMAKE_SIZEOF_VOID_P EQUAL 8)

		message (STATUS "Compiling for 64-bit Windows")

		add_definitions(-DWIN64)
	else()

		message (STATUS "Compiling for 32-bit Windows")

		add_definitions(-DWIN32)
	endif()

	add_definitions(-DRECLS_API_FTP)
endif(WIN32)


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

	impl.api.search.cpp
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


if(UNIX)

	set(COMMON_IMPLEMENTATION_FILES "${COMMON_IMPLEMENTATION_FILES};${UNIX_IMPLEMENTATION_FILES};")
endif(UNIX)

if(WIN32)

	set(COMMON_IMPLEMENTATION_FILES "${COMMON_IMPLEMENTATION_FILES};${WINDOWS_IMPLEMENTATION_FILES};")
endif(WIN32)



add_library(recls
	${COMMON_IMPLEMENTATION_FILES}
)

set_target_properties(recls PROPERTIES
	OUTPUT_NAME "recls"
	# PUBLIC_HEADER "${RECLS_PUBLIC_HEADERS}"
)

target_include_directories(recls PUBLIC
	$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_link_libraries(recls
	PRIVATE
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

target_compile_options(recls PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-deprecated-copy
		-Wno-unused-parameter
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)


# ##########################################################
# install

install(TARGETS recls
	EXPORT project-targets
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
	# PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/recls
)

# install the include/recls/*/ subdirectories here, as do not (yet) know how to do so via PUBLIC_HEADER property
install(
	DIRECTORY ${CMAKE_SOURCE_DIR}/include/${PROJECT_NAME_LOWER}/
	DESTINATION include/${PROJECT_NAME_LOWER}
	FILES_MATCHING
	PATTERN "*.h*"
)


# ############################## end of file ############################# #

