define_example_program(test.scratch.stop_on_access_failure main.c)

if(Pantheios_FOUND)

	target_link_libraries(test.scratch.stop_on_access_failure
		PRIVATE
			Pantheios::Pantheios.core
			Pantheios::Pantheios.fe.all
			Pantheios::Pantheios.be.AnsiConsole
			Pantheios::Pantheios.bec.AnsiConsole
			Pantheios::Pantheios.util
	)
endif(Pantheios_FOUND)
