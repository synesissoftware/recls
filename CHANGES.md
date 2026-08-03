# recls - CHANGES <!-- omit in toc -->


## 1.9.8 - 3rd August 2026

* Added CMake build (**CMakeLists.txt**, **cmake/**, examples and tests) for the 1.9 line, alongside retained **build/** makefiles and Visual C++ projects;
* Added modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with multi-platform matrix and install-smoke coverage;
* Added CMake helper scripts (**prepare_cmake.sh**, **build_cmake.sh**, **clean_cmake.sh**, **remove_cmake_artefacts.sh**, **run_all_examples.sh**, **run_all_unit_tests.sh**, **run_all_scratch_tests.sh**) and **.sis** project metadata;
* Added editor/meta boilerplate (**.vimrc**, **.vscode/settings.json**; expanded **.gitattributes** / **.gitignore**, preserving 1.9 makefile and **.dsp** trees);
* README CI badge targets **ci.yml** on branch **dev-1.9**;
* Added **RECLS_VER_PATCH** (aliased as **RECLS_VER_REVISION**) and set version to **1.9.8**;
* Compatibility with modern **STLSoft**: `unixstl_exception` / `winstl_exception` gating in **api.util.create_directory.cpp** / **api.util.remove_directory.cpp**; C++11+ **root_sequence** without `std::unary_function`; MSVC **/wd4996** for deprecated **file_path_buffer**;
* Build/CI hygiene across examples and tests (strict C prototypes, `getcwd` checks, unused-parameter silencing, MinGW FTP node init, **platformstl_C_get_console_width**, create-directory unit tests under **$HOME**);


## 1.9.7 - 30th December 2023

* Version bump to **1.9.7**; copyright years updated in **recls.h**;


<!-- ########################### end of file ########################### -->
