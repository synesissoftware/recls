
add_executable(test_scratch_cpp_api
    test.scratch.cpp_api.cpp
)

target_link_libraries(test_scratch_cpp_api
    recls
)

target_compile_options(test_scratch_cpp_api PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

