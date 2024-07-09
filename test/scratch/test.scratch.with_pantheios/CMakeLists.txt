
add_executable(test_scratch_with_pantheios
	test.scratch.with_pantheios.cpp
)

target_link_libraries(test_scratch_with_pantheios
	PRIVATE
		recls
)

target_compile_options(test_scratch_with_pantheios PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

