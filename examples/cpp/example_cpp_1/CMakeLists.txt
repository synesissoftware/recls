
add_executable(example_cpp_1
    example_cpp_1.cpp
)

target_link_libraries(example_cpp_1
    recls
)

target_compile_options(example_cpp_1 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

