define_example_program(test.scratch.ignore_inaccessible_nodes main.c)

if(Pantheios_FOUND)

	target_link_libraries(test.scratch.ignore_inaccessible_nodes
		PRIVATE
			Pantheios::Pantheios.core
			Pantheios::Pantheios.fe.all
			Pantheios::Pantheios.be.AnsiConsole
			Pantheios::Pantheios.bec.AnsiConsole
			Pantheios::Pantheios.util
	)
endif(Pantheios_FOUND)
