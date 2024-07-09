
add_executable(test_unit_api_combine_paths
	test.unit.api.combine_paths.c
)

target_link_libraries(test_unit_api_combine_paths
	PRIVATE
		recls
		xTests::xTests.core
)

target_compile_options(test_unit_api_combine_paths PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

