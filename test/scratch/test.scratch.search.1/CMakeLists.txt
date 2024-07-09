
add_executable(test_scratch_search_1
	test.scratch.search.1.c
)

target_link_libraries(test_scratch_search_1
	PRIVATE
		recls
)

target_compile_options(test_scratch_search_1 PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
		-Werror -Wall -Wextra -pedantic
	>
	$<$<CXX_COMPILER_ID:MSVC>:
		/WX /W4
	>
)

