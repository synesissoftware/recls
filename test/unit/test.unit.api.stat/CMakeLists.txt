
add_executable(test_unit_api_stat
	test.unit.api.stat.c
)

target_link_libraries(test_unit_api_stat
	PRIVATE
		recls
		xTests::xTests.core
)

target_compile_options(test_unit_api_stat PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic

		-Wno-unused-result
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

