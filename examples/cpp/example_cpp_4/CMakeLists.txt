define_example_program(example_cpp_4 main.cpp)

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
