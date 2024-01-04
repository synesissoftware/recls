
add_executable(test_c_1
    test_c_1.c
)

target_link_libraries(test_c_1
    recls
)

target_compile_options(test_c_1 PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic

        -Wno-format
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

