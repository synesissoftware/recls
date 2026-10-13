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

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_b64
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			b64::core
	)
endif(b64_FOUND)

if(Diagnosticism_FOUND)

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_Diagnosticism
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			Diagnosticism::core
	)
endif(Diagnosticism_FOUND)

if(Pantheios_FOUND)

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_Pantheios
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			Pantheios::Pantheios.core
	)
endif(Pantheios_FOUND)

if(shwild_FOUND)

	target_compile_definitions(test.scratch.versions
		PRIVATE
			HAS_shwild
	)

	target_link_libraries(test.scratch.versions
		PRIVATE
			shwild::core
	)
endif(shwild_FOUND)
