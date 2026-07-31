# **recls** Changes <!-- omit in toc -->


## 1.10.0 (release candidate 3) - 31st July 2026

* Added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with install-smoke coverage;
* Removed **HISTORY.md** (content merged into **CHANGES.md**);
* Converted **CHANGES.txt** to **CHANGES.md** (version-first headings; trailing semicolons);
* Trimmed **INSTALL.md** and **README.md** (badges; Components; CMake-only guidance); README CI badge now targets **ci.yml**;
* CMake: added `option(BUILD_TESTING …)` for parity with peer libraries;
* Project boilerplate updates;


## 1.10.0 (release candidate 2) - 30th June 2025

* Added `recls::device()`, `recls::directory()`, `recls::file()`, and `recls::socket()` stat-like functions, that attempt to obtain a file-system entry and then filter (or throw) for specific file type;
* Added **libver** scratch-test;
* Fixed boilerplate, wherein various 1.10.0-xxx releases were erroneously tagged 1.10.1-xxx;


## 1.10.0 (release candidate 1) - 6th May 2025

* Added `RECLS_F_NO_BREAK_INFINITE_LOOPS` search flag and (initial) supporting logic, which cures the macOS infinite-loop problem;
* Added `RECLS_REMDIR_F_REMOVE_SOCKETS` flag and supporting logic in `Recls_RemoveDirectory()`;
* Changed search flag `RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS` to `RECLS_F_IGNORE_HIDDEN_ENTRIES` and implemented hidden entry suppression on Unix (as it already was for Windows);
* Fixed logic to ensure `RECLS_F_STOP_ON_ACCESS_FAILURE` works correctly for UNIX and consistently with Windows behaviour;
* Ensuring `RECLS_RC_ACCESS_DENIED` is propagated fully and enhanced associated diagnostics warnings;
* Added **UNIXem** support, which allows UNIX-like functionality to be evaluated on Windows, using the **UNIXem** library, activated by `--use-unixem` for **prepare_cmake.sh**;
* Added `--msvc-mt` flag to **prepare_cmake.sh**, which causes CMake build to use statically linked runtime library;
* Added `--no-b64` flag to **prepare_cmake.sh**, which suppresses discovery of **b64** package;
* Added `--no-pantheios` / `--no-pan` flags to **prepare_cmake.sh**, which suppress discovery of **Pantheios** (and **b64**) packages;
* Added `--no-shwild` flag to **prepare_cmake.sh**, which suppresses discovery of **shwild** package;
* CMake helper script files now all specify the make command default to `mingw32-make.exe` when MinGW is detected;
* CMake scripts now recognise `SIS_CMAKE_MAKE_COMMAND` in addition to `SIS_CMAKE_COMMAND`;
* Compatibility improvements, for compilers (Clang, GCC, VC++), language versions (C++98, C++11, C++14, C++17, C++20) and operating systems (Linux, macOS, Windows);
* Added insertion operator for `recls_rc_t`;
* Removed dependency on **PThreads** / **Windows threads** in favour of **std::atomic** for C++14 or later;
* Simplified testing/assertion of STLSoft projects' versions;
* Added **example_c_9**, which demonstrates recursive search for all sockets under a given directory including all appropriate failure handling;
* Added **example_c_10**, which demonstrates recursive search for all devices under a given directory including all appropriate failure handling;
* Added **example_cpp_4**, which demonstrates use of `Recls_RemoveDirectory()`, optionally including files and sockets;
* Added scratch test **test.scratch.stop_on_access_failure**;
* Applied `__attribute__((format(printf, ...)))` where appropriate, and fixes to resulting warnings;
* Various optimisations, such as sharing patterns string with search nodes to reduce memory consumption;
* Various miscellaneous improvements, such as applying `noexcept`, adding more diagnostics, tidying of layout, and so forth;
* Simplified use of `error_desc` types;
* Replaced instances of `STLSOFT_NUM_ELEMENTS()` with `RECLS_NUM_ELEMENTS()`;
* Replaced instances of `PLATFORMSTL_OS_IS_UNIX` with `RECLS_PLATFORM_IS_UNIX`;
* Replaced instances of `PLATFORMSTL_OS_IS_WINDOWS` with `RECLS_PLATFORM_IS_WINDOWS`;
* Added and applied `RECLS_PLATFORM_IS_UNIX_EMULATED_ON_WINDOWS` / `RECLS_PLATFORM_IS_UNIX_NON_EMULATED_ON_WINDOWS`;
* Renamed entry-point implementation file for scratch test programs to **main.c** / **main.cpp**;
* Renamed entry-point implementation file for test programs to **main.c** / **main.cpp** / **entry.c** / **entry.cpp**;
* Renamed scratch test **test_c_1** to **test.scratch.entry_attributes**;
* Sorting of **TODO.md** in readiness for 1.11 work streams;


## 1.10.0 (beta 6) - 30th April 2025

* Added support for searching for/stat()-ing devices: `RECLS_F_DEVICES`, `RECLS_RC_ENTRY_IS_DEVICE`, **example_c_10** (which searches for devices), `recls::cpp::entry#is_device()`;
* Ensuring full support across operating systems for `RECLS_F_STOP_ON_ACCESS_FAILURE`, including adding **test.scratch.ignore_inaccessible_nodes**;
* Added **example_c_9** (which searches for sockets);
* Adjusted logging threshold constants in order to be compatible with Pantheios (as configured via `Recls_SetApiLogFunction()`);
* Reduction in memory use (by sharing patterns string rather than replicating at every directory node);
**prepare_cmake.sh** / **CMakeLists.txt**: added `--no-b64`, `--no-pantheios`, `--no-shwild` / `CMAKE_NO_*` flags;
* Applied `__attribute__((format(printf, ...)))` where appropriate, and fixes to ensuing warnings;
* Applied `recls_progress_fn_param_t` throughout;
* Visual C++ compatibility improvements;
* Simplified testing/assertion of STLSoft projects' versions;
* Various tidyings and consistency fixes;


## 1.10.0 (beta 5) - 22nd April 2025

* Added support for searching for/stat()-ing sockets: `RECLS_F_SOCKETS`, `RECLS_RC_ENTRY_IS_FILE`, `RECLS_RC_ENTRY_IS_SOCKET`;


## 1.10.0 (beta 4) - 17th April 2025

* Added `Recls_GetFileSizeGibiBytes()`, `Recls_GetFileSizeKibiBytes()`, `Recls_GetFileSizeMebiBytes()`, `Recls_GetFileSizeTebiBytes()`;
* Fixed calculations (from 1,024 factor to 1,000) for `Recls_GetFileSizeGigaBytes()`, `Recls_GetFileSizeKiloBytes()`, `Recls_GetFileSizeMegaBytes()`;
* Added `Recls_GetFileSizeTeraBytes()`;
* Added **test.unit.util.file_sizes**;
* Canonicalising all unit/component test implementation file names;
* Removed all implicit-link implementation files;
* Removed all Visual C++ solution/project files;


## 1.10.0 (beta 3) - 17th April 2025

* Fixes to `Recls_SqueezePath()`;
* Wholesale improvements to examples (incl. **example_c_2** feedback, optional search-directory, memory-usage fix);
* Renamed example entry-point implementation files to **main.c** / **main.cpp**;
* Added examples documentation;
* Updated dependency requirements;


## 1.10.0 (beta 2) - 23rd February 2025

* GCC compatibility;
**test.scratch.with_pantheios**: removed need for function pointer cast;
* Boilerplate and tidying;


## 1.10.0 (beta 1) - 23rd February 2025

* Added `Recls_IsEntrySocket()` API function and `recls::entry#is_socket()`;
* Renamed API functions `Recls_IsFile*()` => `Recls_IsEntry*()`, and added backwards-compatible functions;
* Added component test **test.component.util.cpp.is_socket**;
* Ensured compatibility with Pantheios / CMake (incl. **test.scratch.with_pantheios**);
* Updated dependency requirements;


## 1.10.0 (alpha 9) - 23rd October 2024

* Fleshed out **INSTALL.md**;
* CMake build script consistency and minor fixes;
* Updated dependency requirements (now depends on 0.25+ of **xTests**);
* Project boilerplate / settings / ignores improvements;


## 1.10.0 (alpha 8) - 18th October 2024

* CMake / GCC / MinGW compatibility improvements;
* Tightening up CMake constructs;
* Visual C++ (19xx+) compatibility;


## 1.10.0 (alpha 7) - 17th October 2024

* Ensuring all **recls/cpp/*.hpp** files are self-sufficient;
* MinGW compatibility;
* Significant enhancement and refactoring around use of CMake;
* Compatibility with legacy versions of Visual C++;
* Added **cmake/LanguageFullVersion.cmake** (defines `X_CMAKE_CXX_FULLSTANDARD`);
* Added **cmake/TargetMacros.cmake** (`define_automated_test_program()` / `define_example_program()`), applied throughout examples and tests;
* Renamed CMake core library target from **recls::recls** to **recls::core**;
* Tidying of component / scratch / unit test program code;
* Updated compatibility with **xTests** latest;


## 1.10.0 (alpha 6) - 10th July 2024

* Visual C++ 17 (2022) compatibility;
* CMake Windows compatibility;
* GCC compatibility improvements;


## 1.10.0 (alpha 5) - 4th January 2024

* Initial CMake support (building and installation; verified on macOS);
* Renamed project boilerplate `.txt` files to `.md` (Markdown);
* Project boilerplate updates;


## 1.10.0 (alpha 3) - 29th March 2021

* search-relative-path now contains trailing slash for directories when RECLS_F_MARK_DIRS specified;
* VC++ 15, 16 compatibility;
* C++11/14/17 compatibility;
* GCC and Clang compatibility;
* recls::entry::compare() now implemented in terms of *stl::system_traits<>::path_str_compare();
* simplified project and props files, for prospective compatibility;
* various makefile improvements;
* various fixes and refactorings;


## 1.10.0 (alpha 1) - 4th January 2021

* improved flexibility in treatment of search-directory and patterns;
* significant refactoring, simplification, removal of dead code;
* improved flexibility to recls::cpp::search_sequence, allowing for specification of progress function+param;
* various C++11+ improvements to C++ API;
* added Visual C++ 10 solution and project files, and props files for easy addition of support for all subsequent versions;
* added makefiles for Visual C++ 14, 15, and 16;
* added makefiles for several Borland versions;
* added makefiles for several GCC versions;
* removed support for Visual C++ versions 9 and earlier;
* removed xCover from recls 1.10;
* adjusted all makefiles so can specify shwild and xTests directories (so bundling no longer needed);
* removed all use of STLSoft's (basic_|)file_path_buffer, which is deprecated in STLSoft 1.10;
* numerous improvements to automated and scratch tests;


## 1.9.7 - 30th December 2023

* Declared **RECLS_VER_1_9_7** and bumped revision to **1.9.7**;


## 1.9.6 - 29th January 2017

* added NO_MORE_DATA_exception;
* added (CC|CPPC)_CUSTOM_DEFS_(DEBUG|RELEASE) to makefiles, for customising builds;
* forward compatibility with STLSoft 1.10+;
* now only uses xCover if RECLS_QUALITY_USE_XCOVER defined (and requisite features are supported);


## 1.9.4 - 9th October 2015

* GCC compatibility;
* added MinGW (GCC 4.7) makefile;
* NOTE: bundles shwild 0.10.1;
* NOTE: bundles xCover 0.3.3;
* NOTE: bundles xTests 0.18.5;
* NOTE: depends on STLSoft 1.9.121;


## 1.9.3 - 7th October 2015

* Clang compatibility;
* UNIX compatibility;
* NOTE: bundles shwild 0.10.1;
* NOTE: bundles xTests 0.18.4;
* NOTE: depends on STLSoft 1.9.121;


## 1.9.2 - 7th October 2015

* fixed makefile defects;
* NOTE: bundles shwild 0.10.1;
* NOTE: bundles xTests 0.18.4;
* NOTE: depends on STLSoft 1.9.121;


## 1.9.1 - 28th September 2015

* added new API and entry methods;
* Clang-compatibility;
* VC++ 11/12/14-compatibility;
* Widestring-compatibility in makefiles;
* NOTE: bundles shwild 0.10.1;
* NOTE: bundles xTests 0.18.3;
* NOTE: depends on STLSoft 1.9.121;


## 1.9.1 (alpha 8) - 4th June 2012

* changed entry field volumeSerialNumber to deviceId;
* added entry field volumeSerialNumber (and search flag RECLS_F_NODE_INDEX);
* added entry field nodeIndex;
* improvements to diagnostic logging;
* corrected wildcards-all use in test programs for given all platforms;
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.16.2;
* NOTE: depends on STLSoft 1.9.113;


## 1.9.1 (alpha 7) - 30th November 2011

* added numLinks member to recls_entryinfo_t;
* added member numRelativeDirectoryParts to recls_entryinfo_t;
* added RECLS_F_LINK_COUNT flag;
* added Recls_GetErrno();
* added Recls_ResultCodeToUnixErrorCode();
* added Recls_ResultCodeToWindowsErrorCode();
* added 64-bit compatibility (currently Windows-only);
* removed RECLS_RC_WRONG_ENTRY_TYPE status code; added RECLS_RC_ENTRY_IS_DIRECTORY and RECLS_RC_ENTRY_IS_NOT_DIRECTORY status codes;
* Recls_Stat() now returns RECLS_RC_FAIL when a std::exception-derived exception is caught;
* fix to RECLS_FAILED() (C-definition);
* weakened contract (on Windows) to allow for full-path pattern;
* now copes with search directory surrounded by quotes;
* added test.unit.cpp.retcodes project;
* added test.unit.c.retcodes project;
* added test.scratch.links project;
* added GCC 4.5 and GCC 4.6 makefile;
* simplified the naming of bin and lib targets within the makefiles;
* corrected defect in clean.libs target, whereby the snprintf*.obj files were not cleaned (Windows-only);
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.16.2;
* NOTE: depends on STLSoft 1.9.111;


## 1.9.1 (alpha 6) - 18th October 2010

* recls::entry: added get_file_size() method, ~ deprecated size() method;
* recls::recls_exception: added 'patterns' property;
* added recls_snprintf and recls_svnprintf;
* fixed defects that prevented full wide-string compilation;
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.16.1;
* NOTE: depends on STLSoft 1.9.101;


## 1.9.1 (alpha 5) - 7th June 2010

* added comparison operators for recls::cpp::entry;
* added subscript operator to recls::cpp::root_sequence;
* changed recls_rc_t to be an opaque type, in order to avoid problems with string access shims matching any integers;
* failure to stat is not reported as an error;
* various minor fixes;
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.15.1;
* NOTE: depends on STLSoft 1.9.98;


## 1.9.1 (alpha 4) - 4th April 2010

* fixed invalid calculation in stat();
* fixed path-relativity defect;
* widestring compatibility in C++ API;
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.15.1;
* NOTE: depends on STLSoft 1.9.97;


## 1.9.1 (alpha 3) - 10th March 2010

* Added support for Visual C++ 10 (including makefiles and implicit linking);
* NOTE: bundles shwild 0.9.19;
* NOTE: bundles xTests 0.14.5;
* NOTE: depends on STLSoft 1.9.96;


## 1.9.1 (alpha 2) - 11th February 2010

* added VC++ 9 (Visual Studio 2008) solution/project files;
* added Recls_GetFileSizeGigaBytes(), Recls_GetFileSizeMegaBytes(), Recls_GetFileSizeKiloBytes() API functions;
* corrected defects/missing features in examples;
* corrected 32/64-bit compiler warnings;
* NOTE: core depends on STLSoft 1.9.92 (or later);
* NOTE: C++ mapping also depends on STLSoft 1.10 alpha 13 (or later);


## 1.9.1 (alpha 1) - 9th February 2010

* first release of recls 1.9;
* merging 1.8's C++ and STL APIs into one: include <recls/recls.hpp> for new C++ API;
* prototypical code coverage;
* refactored implicit link functionality;
* API type name changes, e.g. recls_fileinfo_t => recls_entryinfo_t, recls_info_t => recls_entry_t;
* removed the Recls_OutstandingDetails() API function;
* user-specifiable diagnostic logging;
* NOTE: this distribution contains only core library and C++ mapping; other language mappings are not included;


## 1.8.13 - 8th June 2008

* Unicode compatibility and builds;
* Unicode compatibility in implicit_link.h header;
* Mac-OS-X bug in definition of rc_atomic_t;
* fix to src/recls_atomic.h, to prevent inclusion of platformstl/synch/atomic_functions.h on platformst that do not support atomic integer operations;
* Unicode builds for core library and examples for VC++ (all versions);
* Unicode compatibility;


## 1.8.12 - 8th June 2008

* added 64-bit Windows compatibility;
* now relies on STLSoft 1.9.45;
* fix to Recls_DeriveRelativePath() for when origin is empty string;
* fix to basic_search_sequence_value_type against self-assignment;
* Borland C/C++ 5.82 (Turbo C++) makefile;
* test.unit.combine_paths;
* test.unit.derive_relative_path;
* test.unit.squeeze_path;


## 1.8.11 - 7th October 2007

* fix to home path ('~') elicitation on UNIX;
* compilation on 64-bit UNIX;


## 1.8.10 - 2nd June 2007

* fix to Recls_SearchFeedback() (and, hence, Recls_Search()) when both searchRoot and pattern are NULL;
* general fixes for Unicode compilation;
* fixes to namespace-exports for shims for Recls::Entry;


## 1.8.9 - 19th May 2007

* distribution is now rooted at recls-1.8.9. In other words, the file include/recls/recls.h will now be at recls-1.8.9/include/recls/recls.h;
* Recls::Entry::to_str method, to allow use with operations that expect a string;


## 1.8.8 - 30th April 2007

* Compatible with STLSoft 1.9.1 (version released with Extended STL, vol 1: CD);


## 1.8.7 - 16th April 2007

* Recls::combinePaths can now accept either/both of the two path (fragment) parameters as Entry instances. For the left-hand parameter, the instance will be converted to string via the 'Entry::path' attribute. For the right-hand instance parameter, the instance will be converted to string via the 'Entry::searchRelativePath' attribute. This provides significant simplification (and convenience) in client code when working with source and destination directory hierarchies;


## 1.8.6 - 6th April 2007

* fixed 'bug' (in Recls_DeriveRelativePath()) whereby deriving a relative path would contain unnecessary parts, e.g. the relativity of /usr/include/stlsoft/unixstl/ with respect to /usr/include/stlsoft/ would be ../stlsoft/unixstl;
* if (searchRoot is NULL and pattern is a single absolute + wild) or (searchRoot is a single absolute + wild and pattern is NULL), it will split them and do "the sensible thing";
* Recls::FileSearch::new can now accept nil for search directory and/or pattern;
* fixed recls/stl/search_sequence.hpp to be compatible with STLSoft 1.9.1 beta 47 (or later);
* now relies on STLSoft 1.9.1 beta 47 (or later), available from http://stlsoft.org/downloads.html;


## 1.8.5 - 27th February 2007

* fixed bug whereby an unrelated search dir is not correctly represented in the file entry info;
* all STLSoft inclusions are now updated for the changes to the STLSoft directory structure with STLSoft 1.9.1 beta 44 (download from http://stlsoft.org/downloads.html);


## 1.8.4 - 8th September 2006

* all STLSoft inclusions are now updated for the changes to the STLSoft directory structure with STLSoft 1.9.1 beta 22 (download from http://stlsoft.org/downloads.html);
* FileSearch.WildcardsAll;
* now allows searchRoot and/or pattern parameters to FileSearch::new to be instances of Entry, as well as strings;


## 1.8.3 - 16th August 2006

* all STLSoft inclusions are now updated for the changes to the STLSoft directory structure with STLSoft 1.9.1 beta 19 (download from http://stlsoft.org/downloads.html);
* FileEntry::length();
* FileEntry::Exists;
* Fixed bugs in FileSearch.CombinePaths() and FileSearch.DeriveRelativePaths();


## 1.8.2 - 26th July 2006

* all STLSoft inclusions are now updated for the changes to the STLSoft directory structure with STLSoft 1.9.1 beta 16 (download from http://stlsoft.org/downloads.html);
* Fixed minor bug in recls_api.SqueezePath();
* Recls_DoesEntryExist();
* Entry.isFile property;
* Entry.exist? property;


## 1.8.1 - 17th June 2006

* supports handling of ~ home directory mapping;
* supports platform-independent pattern separator of |;
* all headers incorporate #pragma once (for supporting compilers);
* RECLS_ASSERT() and RECLS_MESSAGE_ASSERT() replace now deprecated recls_assert() and recls_message_assert();
* implicit linking header now responds to RECLS_NO_IMPLICIT_LINK;
* RECLS_F_USE_TILDE_ON_NO_SEARCHROOT flag, which interprets a NULL or empty searchRoot as the home directory, rather than the current directory;
* RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WIN32 flag, which causes hidden files and directories to be skipped on Win32. The next release will rename this flag to RECLS_F_IGNORE_HIDDEN_FILES, and will also work for UNIX;
* all obsolete headers in the include directory now use #error to prevent their inclusion;
* Property syntax support for DMC++ (8.46+);
* Unicode (wchar_t) build compatible;
* recls::cpp::FileSearch::CombinePaths() method;
* recls::cpp::FileSearch::DeriveRelativePath() method;
* recls::cpp::FileSearch::SqueezePath() method;
* SearchFlags class, which acts as an enumeration;
* SelectedRootsFlags class, which acts as an enumeration;
* SearchFlags coclass, that may be used for named specification of search constants in scripts;
* SelectedRootsFlags coclass, that may be used for named specification of root type constants in scripts;
* IFileSearch3 interface, and new methods SelectedRoots(), CombinePaths(), DeriveRelativePath() and SqueezePath();
* fixed bug in EnumEntry::Reset(), where the search handle was not set to NULL;
* one-parameter stat() overload, where flags are implicitly 0;
* getSelectedRoots() method;
* combinePaths() method;
* deriveRelativePath() method;
* squeezePath() method;
* updated Search member constants with RECLS_F_MARK_DIRS, RECLS_F_ALLOW_REPARSE_DIRS and RECLS_F_USE_TILDE_ON_NO_SEARCHROOT;
* org.recls.FileSearch.getRoots();
* org.recls.Search.getRoots();
* org.recls.FileSearch.getSelectedRoots();
* org.recls.FileSearch.combinePaths();
* org.recls.FileSearch.deriveRelativePath();
* org.recls.FileSearch.squeezePath();
* JNI library renamed from recls_jni[.dll|.so] to recls.jni[.dll|.so];
* recls.FileEntry.SearchRelativePath property;
* recls.FileEntry.SearchDirectory property;
* recls.FileSearch.Roots();
* recls.FileSearch.SelectedRoots();
* recls.FileSearch.CombinePaths();
* recls.FileSearch.DeriveRelativePath();
* recls.FileSearch.SqueezePath();
* recls.FileSearch.Stat() now returns null if a matching entry is not found. It still throws an instance of ReclsException if the operation fails for another reason;
* module flags FIXED_DRIVES, NETWORK_DRIVES, CDROM_DRIVES, REMOVABLE_DRIVES and RAM_DRIVES, for use with module function selectedRoots();
* module function roots();
* module function selectedRoots();
* module function combinePaths();
* module function deriveRelativePath();
* module function squeezePath();
* recls::stl::combine_paths();
* recls::stl::derive_relative_path();
* recls::stl::squeeze_path();
* recls::stl::root_sequence now has a constructor that takes RECLS_ROOTS_FLAG flags;


## 1.7.2 - 31st December 2005

* Digital Mars now supports the C++ Property syntax;
* changed the boolean type used by search_sequence, so that adapting the iterators by all the lovely new STLSoft iterator adaptors doesn't cause warnings about truncation from int to bool;


## 1.6.4 - 27th December 2005

* new search flag RECLS_F_MARK_DIRS, which appends a trailing slash to the paths of any entries returned that are directories;
* new search flag RECLS_F_ALLOW_REPARSE_DIRS, which follows reparse directories on Win2K/XP. This is off by default, to avoid infinite search loops on pathologically configured systems;
* new search flag RECLS_F_CALLBACKS_STDCALL_ON_WIN32, which invokes callbacks using the StdCall calling convention. (This was needed to interface with C# delegates.);
* [C++ only] All search flags are now declared without the RECLS_F_ prefix, e.g. ALLOW_REPARSE_DIRS as well as RECLS_F_ALLOW_REPARSE_DIRS;
* the core library header files now have a new structure, as follows (where $RECLS_ROOT is the directory in which recls is installed):;
* new core API function Recls_GetSelectedRoots(), which only returns roots of selected disk types according to its flags (a combination of the new RECLS_ROOTS_FLAG enumeration);
* new core API function Recls_SearchFeedback(), which calls back to a caller-supplied function as the search enters each directory searched;
* new core API function Recls_CalcDirectorySizeFeedback(), which provides feedback callbacks when searching directories for the calculation;
* new core API function Recls_GetSearchRelativePathProperty(), which gives the path of each entry relative to the search directory. (In other words, it removes the search path from the full path.);
* new core API function Recls_GetSearchDirectoryProperty(), which gives the full path of the search directory;
* all the following mappings have corresponding changes to their;
* mappings now support C++ Properties (as described in chapter 35 of Imperfect C++, http://imperfectcplusplus.com), which means that the;


## 1.6.4 - 17th July 2005

* further reduction (around 2-6KB, varying between compilers) of linked code size, as a result of using the updated winstl::basic_findfile_sequence template, which internally handles multi-part patterns;


## 1.6.3 - 28th June 2005

* minor changes to test files sources, for maximum compatibility with compilers, including GCC 3.3 and 4.0 on Mac OS-X;
* addition of three more test programs - C_minimal, Cpp_minimal and STL_minimal - that demonstrate minimal and easy use of the C++ and STL mappings;
* addition of a "Getting Started" page within the documentation;


## 1.6.2 - 23rd May 2005

* The implementation is significantly refactored, to reduce source and binary sizes, as described in the July instalment of the "Positive Integration"  column in C/C++ Users Journal (http://www.cuj.com);
* Header files in the old mappings/Cpp directory now redirect to <recls/cpp/search.hpp>, <recls/cpp/entry.hpp>, etc;
* mappings now use new STLSoft C-compatible components, i.e. <winstl/time_conversion_functions.h>;
* Java mapping now uses the STLSoft sub-project PlatformSTL;


<!-- ########################### end of file ########################### -->
