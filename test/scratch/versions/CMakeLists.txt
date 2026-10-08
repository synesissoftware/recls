define_example_program(test.scratch.versions main.cpp)

if(2be_FOUND)

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_2be
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			2be::core
	)
endif(2be_FOUND)

if(b64_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			b64::core
	)
endif(b64_FOUND)

if(Pantheios_FOUND)

	target_link_libraries(test.scratch.versions
		PRIVATE
			Pantheios::Pantheios.core
	)
endif(Pantheios_FOUND)

if(xTests_FOUND)

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_xTests
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			$<IF:$<VERSION_LESS:${xTests_VERSION},"0.23">,xTests::xTests.core,xTests::core>
	)
endif(xTests_FOUND)
