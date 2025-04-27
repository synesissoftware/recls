list(APPEND X_MSVC_CUSTOM_WARNINGS_TO_BE_SUPPRESSED
	4267 # to allow x.size() to be passed to XTESTS_TEST_MULTIBYTE_STRING_EQUAL_N()
)
define_automated_test_program(test.unit.util.file_sizes entry.c)
