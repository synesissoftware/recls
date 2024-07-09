
add_executable(example_c_4
	example_c_4.c
)

target_link_libraries(example_c_4
	PRIVATE
		recls
)

target_compile_options(example_c_4 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

