
define_example_program(test.scratch.with_pantheios test.scratch.with_pantheios.cpp)

target_link_libraries(test.scratch.with_pantheios
	PRIVATE
		Pantheios::Pantheios.core
		Pantheios::Pantheios.fe.all
		Pantheios::Pantheios.be.AnsiConsole
		Pantheios::Pantheios.bec.AnsiConsole
		Pantheios::Pantheios.util
)
