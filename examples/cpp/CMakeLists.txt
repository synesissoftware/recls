add_subdirectory(example_cpp_1)
add_subdirectory(example_cpp_2)
if(X_CMAKE_CXX_FULLSTANDARD GREATER_EQUAL 2011)

	add_subdirectory(example_cpp_3)
	add_subdirectory(example_cpp_4)
endif()
