
add_executable(test_scratch_cpp_api
	test.scratch.cpp_api.cpp
)

target_link_libraries(test_scratch_cpp_api
	PRIVATE
		recls
		$<$<STREQUAL:${STLSOFT_INCLUDE_DIR},>:STLSoft::STLSoft>
)

if(WIN32)

	target_link_libraries(test_scratch_cpp_api
		PRIVATE
			wininet
	)
endif(WIN32)

target_compile_options(test_scratch_cpp_api PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

