
add_subdirectory(test.scratch.cpp_api)
add_subdirectory(test.scratch.links)
add_subdirectory(test.scratch.search.1)
if(Pantheios_FOUND)

	add_subdirectory(test.scratch.with_pantheios)
endif(Pantheios_FOUND)
add_subdirectory(test_c_1)

