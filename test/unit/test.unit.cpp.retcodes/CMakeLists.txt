
add_executable(test_unit_cpp_retcodes
	test.unit.cpp.retcodes.cpp
)

target_link_libraries(test_unit_cpp_retcodes
	PRIVATE
		recls
		xTests::xTests.core
)

target_compile_options(test_unit_cpp_retcodes PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

