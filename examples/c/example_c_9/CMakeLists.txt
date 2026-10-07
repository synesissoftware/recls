# Socket search requires a UNIX host, so skip it on Windows (even when
# emulating UNIX on Windows).
if(WIN32)

	return()
endif(WIN32)

define_example_program(example_c_9 main.c)

if(Pantheios_FOUND)

	target_link_libraries(example_c_9
		PRIVATE
			Pantheios::Pantheios.core
			Pantheios::Pantheios.fe.all
			Pantheios::Pantheios.be.AnsiConsole
			Pantheios::Pantheios.bec.AnsiConsole
			Pantheios::Pantheios.util
	)
endif(Pantheios_FOUND)
