
add_subdirectory(test.scratch.cpp_api)
add_subdirectory(test.scratch.ignore_inaccessible_nodes)
add_subdirectory(test.scratch.links)
add_subdirectory(test.scratch.search.1)
add_subdirectory(test.scratch.stop_on_access_failure)
if(Pantheios_FOUND)

	add_subdirectory(test.scratch.with_pantheios)
endif(Pantheios_FOUND)
add_subdirectory(test_c_1)
