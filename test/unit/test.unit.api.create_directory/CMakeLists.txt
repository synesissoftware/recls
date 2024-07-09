
add_executable(test_unit_api_create_directory
	test.unit.api.create_directory.c
)

target_link_libraries(test_unit_api_create_directory
	PRIVATE
		recls
		xTests::xTests.core
)

target_compile_options(test_unit_api_create_directory PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-ignored-qualifiers
		-Wno-unused-result
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

