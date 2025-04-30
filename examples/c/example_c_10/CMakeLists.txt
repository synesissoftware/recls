define_example_program(example_c_10 main.c)

if(Pantheios_FOUND)

	target_link_libraries(example_c_10
		PRIVATE
			Pantheios::Pantheios.core
			Pantheios::Pantheios.fe.all
			Pantheios::Pantheios.be.AnsiConsole
			Pantheios::Pantheios.bec.AnsiConsole
			Pantheios::Pantheios.util
	)
endif(Pantheios_FOUND)
