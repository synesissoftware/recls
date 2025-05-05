if(xTests_VERSION VERSION_GREATER_EQUAL 0.20.5)

	add_subdirectory(test.component.util.cpp.create_directory)
	add_subdirectory(test.component.util.cpp.remove_directory)
endif(xTests_VERSION VERSION_GREATER_EQUAL 0.20.5)

if(UNIX)

	add_subdirectory(test.component.util.cpp.is_socket)
endif(UNIX)
