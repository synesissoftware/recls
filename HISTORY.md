# recls - History


30th April 2025 - 1.10.1 beta6
------------------------------

 * Added support for searching for/stat()-ing devices: `RECLS_F_DEVICES`, `RECLS_RC_ENTRY_IS_DEVICE`, **example_10** (which searches for devices), `recls::cpp::entry#is_device()`;
 * Ensuring full support across operating systems for `RECLS_F_STOP_ON_ACCESS_FAILURE`, including adding **test.scratch.ignore_inaccessible_nodes**;
 * Added **example_9** (which searches for sockets);
 * Adjusted logging threshold constants in order to be compatible with Pantheios (as configured via `Recls_SetApiLogFunction()`);
 * Reduction in memory use (by sharing patterns string rather than replicating at every directory node);
 * Various tidyings and consistency fixes;


22nd April 2025 - 1.10.1 beta5
------------------------------

 * Added support for searching for/stat()-ing sockets: `RECLS_F_SOCKETS`, `RECLS_RC_ENTRY_IS_FILE`, `RECLS_RC_ENTRY_IS_SOCKET`;


17th April 2025 - 1.10.1 beta4
------------------------------

 * Added `Recls_GetFileSizeGibiBytes()`, `Recls_GetFileSizeKibiBytes()`, `Recls_GetFileSizeMebiBytes()`, `Recls_GetFileSizeTebiBytes()`;
 * Fixed calculations (from 1,024 factor to 1,000) for `Recls_GetFileSizeGigaBytes()`, `Recls_GetFileSizeKiloBytes()`, `Recls_GetFileSizeMegaBytes()`;
 * Added `Recls_GetFileSizeTeraBytes()`;
 * Canonicalising all unit/component test implementation file names;
 * Removed all implicit-link implementation files;
 * Removed all Visual C++ solution/project files;


16th April 2025 - 1.10.1 beta3
------------------------------

 * Fixes to `Recls_SqueezePath()`;
 * Wholesale improvements to examples;


23rd February 2025 - 1.10.1 beta2
---------------------------------

 * GCC compatibility;
 * tidying;


23rd February 2025 - 1.10.1 beta1
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

