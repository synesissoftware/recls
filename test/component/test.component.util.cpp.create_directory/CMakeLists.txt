
add_executable(test_component_util_cpp_create_directory
	test.component.util.cpp.create_directory.cpp
)

target_link_libraries(test_component_util_cpp_create_directory
	PRIVATE
		recls
		xTests::xTests.core
)

target_compile_options(test_component_util_cpp_create_directory PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

