
add_executable(test_unit_cpp_derive_relative_path
    test.unit.cpp.derive_relative_path.cpp
)

target_link_libraries(test_unit_cpp_derive_relative_path
    recls
    xTests::xTests.core
)

target_compile_options(test_unit_cpp_derive_relative_path PRIVATE
    $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:
        -Werror -Wall -Wextra -pedantic
    >
    $<$<CXX_COMPILER_ID:MSVC>:
        /WX /W4
    >
)

