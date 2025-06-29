# recls - History


6th May 2025 - 1.10.0 release candidate 1
-----------------------------------------

 * Added `RECLS_F_NO_BREAK_INFINITE_LOOPS` search flag and (initial) supporting logic, which cures the macOS infinite-loop problem;
 * Added `RECLS_REMDIR_F_REMOVE_SOCKETS` flag and supporting logic in `Recls_RemoveDirectory()`;
 * Changed search flag `RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS` to `RECLS_F_IGNORE_HIDDEN_ENTRIES` and implemented hidden entry suppression on Unix (as it already was for Windows);
 * Fixed logic to ensure `RECLS_F_STOP_ON_ACCESS_FAILURE` works correctly for UNIX and consistently with Windows behaviour;
 * Ensuring `RECLS_RC_ACCESS_DENIED` is propagated fully and enhanced associated diagnostics warnings;

 * Added **UNIXem** support, which allows UNIX-like functionality to be evaluated on Windows, using the **UNIXem** library, activated by '--use-unixem' for **prepare_cmake.sh**;
 * Added '--msvc-mt' flag to **prepare_cmake.sh**, which causes CMake build to use statically linked runtime library;
 * Added '--no-b64' flag to **prepare_cmake.sh**, which suppresses discovery of **b64** package;
 * Added '--no-pantheios' flag to **prepare_cmake.sh**, which suppresses discovery of **Pantheios** package;
 * Added '--no-shwild' flag to **prepare_cmake.sh**, which suppresses discovery of **shwild** package;
 * CMake helper script files now all specify the make command default to "mingw32-make.exe" when detected use of MinGW;

 * Compatibility improvements, for compilers (Clang, GCC, VC++), language versions (C++98, C++11, C++14, C++17, C++20) and operating systems (Linux, macOS, Windows);
 * Added insertion operator for `recls_rc_t`;
 * Removed dependency on **PThreads** / **Windows threads** in favour of **std::atomic** for C++14 or later;
 * Simplified testing/assertion of STLSoft projects' versions;

 * Added **example_c_9**, which demonstrates recursive search for all sockets under a given directory including all appropriate failure handling;
 * Added **example_c_10**, which demonstrates recursive search for all devices under a given directory including all appropriate failure handling;
 * Added **example_cpp_4**, which demonstrates use of `Recls_RemoveDirectory()`, optionally including files and sockets;
 * Added scratch test **test.scratch.stop_on_access_failure**;


30th April 2025 - 1.10.0 beta6
------------------------------

 * Added support for searching for/stat()-ing devices: `RECLS_F_DEVICES`, `RECLS_RC_ENTRY_IS_DEVICE`, **example_10** (which searches for devices), `recls::cpp::entry#is_device()`;
 * Ensuring full support across operating systems for `RECLS_F_STOP_ON_ACCESS_FAILURE`, including adding **test.scratch.ignore_inaccessible_nodes**;
 * Added **example_9** (which searches for sockets);
 * Adjusted logging threshold constants in order to be compatible with Pantheios (as configured via `Recls_SetApiLogFunction()`);
 * Reduction in memory use (by sharing patterns string rather than replicating at every directory node);
 * **prepare_cmake.sh**: added '--no-b64', '--no-pantheios', '--no-shwild' flags;
 * Various tidyings and consistency fixes;


22nd April 2025 - 1.10.0 beta5
------------------------------

 * Added support for searching for/stat()-ing sockets: `RECLS_F_SOCKETS`, `RECLS_RC_ENTRY_IS_FILE`, `RECLS_RC_ENTRY_IS_SOCKET`;


17th April 2025 - 1.10.0 beta4
------------------------------

 * Added `Recls_GetFileSizeGibiBytes()`, `Recls_GetFileSizeKibiBytes()`, `Recls_GetFileSizeMebiBytes()`, `Recls_GetFileSizeTebiBytes()`;
 * Fixed calculations (from 1,024 factor to 1,000) for `Recls_GetFileSizeGigaBytes()`, `Recls_GetFileSizeKiloBytes()`, `Recls_GetFileSizeMegaBytes()`;
 * Added `Recls_GetFileSizeTeraBytes()`;
 * Canonicalising all unit/component test implementation file names;
 * Removed all implicit-link implementation files;
 * Removed all Visual C++ solution/project files;


16th April 2025 - 1.10.0 beta3
------------------------------

 * Fixes to `Recls_SqueezePath()`;
 * Wholesale improvements to examples;


23rd February 2025 - 1.10.0 beta2
---------------------------------

 * GCC compatibility;
 * tidying;


23rd February 2025 - 1.10.0 beta1
---------------------------------

 * added `Recls_IsEntrySocket()` API function and refactored Entry API;
 * Ensured compatibility with Pantheios;
 * Updated dependency requirements;


23rd October 2024 - 1.10.0 alpha9
---------------------------------

 * Project boilerplate improvements;
 * Updated dependency requirements;


18th October 2024 - 1.10.0 alpha8
---------------------------------

 * CMake build scripts enhancements;
 * Visual C++ (19xx+) compatibility;


17th October 2024 - 1.10.0 alpha7
---------------------------------

 * MinGW compatibility;
 * CMake build scripts enhancements;
 * Tidying of component / scratch / unit test programs;
 * ensuring all **recls/cpp/\*.hpp** files are self-sufficient;


10th July 2024 - 1.10.0 alpha6
-----------------------------

 * Visual C++ 17 (2022) compatibility;
 * CMake Windows compatibility;
 * GCC compatibility improvements;


4th January 2024 - 1.10.0 alpha5
--------------------------------

* T.B.C.


<!-- ########################### end of file ########################### -->

