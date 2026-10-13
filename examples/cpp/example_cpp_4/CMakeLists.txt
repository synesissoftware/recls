define_example_program(example_cpp_4 main.cpp)

if(MSVC)

	target_compile_definitions(example_cpp_4
		PRIVATE
			_CRT_SECURE_NO_WARNINGS
	)
endif()

target_link_libraries(example_cpp_4
	PRIVATE
		2be::core
)

if(Pantheios_FOUND)

	target_link_libraries(example_cpp_4
		PRIVATE
			Pantheios::Pantheios.core
			Pantheios::Pantheios.fe.all
			Pantheios::Pantheios.be.AnsiConsole
			Pantheios::Pantheios.bec.AnsiConsole
			Pantheios::Pantheios.util
	)
endif(Pantheios_FOUND)
