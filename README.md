# recls <!-- omit in toc -->

**rec**ursive **ls**


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/recls.svg)](https://github.com/synesissoftware/recls/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/recls)](https://github.com/synesissoftware/recls/commits/master)
[![CI](https://github.com/synesissoftware/recls/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/recls/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Developer Experience](#developer-experience)
- [Installation](#installation)
- [Components](#components)
  - [Layers](#layers)
  - [Notable components](#notable-components)
    - [New in 1.10](#new-in-110)
    - [Notable in 1.9](#notable-in-19)
    - [Legacy core](#legacy-core)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**recls** - **rec**ursive **ls** - is a platform-independent recursive file-system search library implemented in C and C++ with a C-API and a header-only C++ binding. It provides recursive (and non-recursive) search, `stat`-like entry queries, path utilities, directory create/remove helpers, and related facilities across Unix and Windows.

**recls** is completely free and includes source released under a BSD-style license. The current line is **1.10**.


## Developer Experience

The shortest path from a clone to a green check:

1. **Need** — a C/C++ toolchain, **CMake**, and [**STLSoft**](https://github.com/synesissoftware/STLSoft/) **1.11.4** or later on the include path / install prefix. For unit tests, also [**xTests**](https://github.com/synesissoftware/xTests/). Optional: **2be** (for **example_cpp_4**), **Diagnosticism** (richer **test.scratch.versions**), **UNIXem** (UNIX-on-Windows via `./prepare_cmake.sh --use-unixem`);
2. **Build** —

   ```bash
   ./prepare_cmake.sh
   ./build_cmake.sh
   ```

   Library-only (no examples or tests): `./prepare_cmake.sh -E -T` then `./build_cmake.sh`;
3. **Try** —

   ```bash
   ./run_all_unit_tests.sh
   # or one example, e.g.:
   ./run_all_examples.sh
   ```

   Friction worth knowing up front: **example_c_9** (sockets) and **example_c_10** (devices) are skipped on Windows CMake builds — those search types need a real UNIX host (or **UNIXem**). **example_cpp_4** is skipped when **2be** is absent or suppressed with `--no-2be`;
4. **Read next** — [INSTALL.md](./INSTALL.md) (CMake prepare / install / consumer link), [EXAMPLES.md](./EXAMPLES.md) (example TOC), [FAQ.md](./FAQ.md), and the working components ledger [strategy/COMPONENTS-INVENTORY.md](./strategy/COMPONENTS-INVENTORY.md).


## Installation

Detailed instructions — via **CMake** — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.

In short:

1. Clone the repository;
2. `./prepare_cmake.sh` (add `-E -T` to skip examples and tests);
3. `./build_cmake.sh` (or pass `--run-make` / `-m` to prepare);
4. Optionally `./run_all_unit_tests.sh`, then `cmake --install` as shown in **INSTALL.md**.


## Components

**recls** is organised as a **C core library** plus a **header-only C++ binding**, with thin platform and FTP facets. The working ledger of headers and notable API units — including *since* provenance — is [strategy/COMPONENTS-INVENTORY.md](./strategy/COMPONENTS-INVENTORY.md). The tables below are the curated README view.


### Layers

* **C API / core** — recursive and non-recursive search, entry queries, path and directory helpers via [`recls/recls.h`](include/recls/recls.h);
* **C++ API** — header-only binding over the core via [`recls/recls.hpp`](include/recls/recls.hpp) and the headers under [`recls/cpp/`](include/recls/cpp/);
* **Platform facets** — [`recls/unix.h`](include/recls/unix.h) / [`recls/cpp/unix.hpp`](include/recls/cpp/unix.hpp) and [`recls/windows.h`](include/recls/windows.h) / [`recls/cpp/windows.hpp`](include/recls/cpp/windows.hpp);
* **FTP** (legacy; Windows-only; nominated for deprecation) — [`recls/ftp.h`](include/recls/ftp.h) and [`recls/cpp/ftp_search_sequence.hpp`](include/recls/cpp/ftp_search_sequence.hpp).


### Notable components

Badges are coloured by era: dark grey for **≤1.8** (and early 1.9 dumps), orange for **1.9.x**, blue for **1.10+**. Tag history in this repository begins at **1.9.1**, so older *since* values are estimates from header `Created:` dates and **CHANGES.md**.


#### New in 1.10

| Component | Layer | Since |
| --- | --- | --- |
| [`RECLS_F_SOCKETS`](include/recls/recls.h) / [`Recls_IsEntrySocket()`](include/recls/recls.h) / [`recls::entry::is_socket()`](include/recls/cpp/entry.hpp) | C / C++ | [![since 1.10.0-beta5](https://img.shields.io/badge/since-1.10.0--beta5-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta5) |
| [`RECLS_F_DEVICES`](include/recls/recls.h) / [`recls::entry::is_device()`](include/recls/cpp/entry.hpp) | C / C++ | [![since 1.10.0-beta6](https://img.shields.io/badge/since-1.10.0--beta6-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta6) |
| [`recls::device()`](include/recls/cpp/entry.hpp) / [`recls::directory()`](include/recls/cpp/entry.hpp) / [`recls::file()`](include/recls/cpp/entry.hpp) / [`recls::socket()`](include/recls/cpp/entry.hpp) | C++ | [![since 1.10.0-rc2](https://img.shields.io/badge/since-1.10.0--rc2-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc2) |
| [`RECLS_F_NO_BREAK_INFINITE_LOOPS`](include/recls/recls.h) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) |
| [`RECLS_F_IGNORE_HIDDEN_ENTRIES`](include/recls/recls.h) (Unix + Windows) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) |
| [`RECLS_REMDIR_F_REMOVE_SOCKETS`](include/recls/recls.h) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) |
| [`Recls_GetFileSizeGibiBytes()`](include/recls/recls.h) (and Ki/Me/Te siblings) | C | [![since 1.10.0-beta4](https://img.shields.io/badge/since-1.10.0--beta4-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta4) |
| [`Recls_IsEntry*()`](include/recls/recls.h) (supersedes `Recls_IsFile*()`) | C | [![since 1.10.0-beta1](https://img.shields.io/badge/since-1.10.0--beta1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta1) |
| [`recls::search_sequence`](include/recls/cpp/search_sequence.hpp) progress feedback | C++ | [![since 1.10.0-alpha1](https://img.shields.io/badge/since-1.10.0--alpha1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-alpha1) |
| **UNIXem** (`./prepare_cmake.sh --use-unixem`) | Platform | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) |
| CMake install / **ci.yml** | Packaging | [![since 1.10.0-alpha5](https://img.shields.io/badge/since-1.10.0--alpha5-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-alpha5) |


#### Notable in 1.9

| Component | Layer | Since |
| --- | --- | --- |
| [`NO_MORE_DATA_exception`](include/recls/cpp/exceptions.hpp) | C++ | [![since 1.9.6](https://img.shields.io/badge/since-1.9.6-bf8700.svg)](https://github.com/synesissoftware/recls/releases/tag/1.9.6) |
| [`RECLS_F_LINK_COUNT`](include/recls/recls.h) / `numLinks` | C | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`RECLS_F_NODE_INDEX`](include/recls/recls.h) / `deviceId` / `nodeIndex` | C | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`Recls_GetErrno()`](include/recls/recls.h) | C | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`recls/recls.hpp`](include/recls/recls.hpp) | C++ | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`recls/cpp/unix.hpp`](include/recls/cpp/unix.hpp) / [`recls/cpp/windows.hpp`](include/recls/cpp/windows.hpp) | C++ | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |


#### Legacy core

| Component | Layer | Since |
| --- | --- | --- |
| [`recls/recls.h`](include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`Recls_Search()`](include/recls/recls.h) / [`Recls_SearchFeedback()`](include/recls/recls.h) / [`Recls_SearchProcess()`](include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`Recls_Stat()`](include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`Recls_GetRoots()`](include/recls/recls.h) / [`Recls_CombinePaths()`](include/recls/recls.h) / [`Recls_RemoveDirectory()`](include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`recls::search_sequence`](include/recls/cpp/search_sequence.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`recls::entry`](include/recls/cpp/entry.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |
| [`recls::root_sequence`](include/recls/cpp/root_sequence.hpp) / [`recls::directory_parts`](include/recls/cpp/directory_parts.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) |


## Examples

Examples are provided in the `examples` directory, along with a markdown description for each. A detailed list TOC of them is provided in [EXAMPLES.md](./EXAMPLES.md).

Quick picks:

* **example_c_1** / **example_cpp_1** — recursive search for all files (normative first try);
* **example_c_6** / **example_cpp_3** — `Recls_Stat()` / `recls::stat` path explosion;
* **example_c_9** / **example_c_10** — sockets / devices (UNIX hosts);
* **example_cpp_4** — `Recls_RemoveDirectory()` (needs **2be** for the smoke path).


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/recls "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/recls.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/recls/issues "GitHub Page") - you'll be very welcome!


### Dependencies


#### STLSoft <!-- omit in toc -->

**recls** depends on the **STLSoft** libraries, version **1.11.4** (or later).

* [STLSoft](https://github.com/synesissoftware/STLSoft/);


#### Development Dependencies (optional for examples) <!-- omit in toc -->

* [2be](https://github.com/synesissoftware/2be/) (**example_cpp_4** smoke — skipped when absent or with **`--no-2be`**);


#### Development Dependencies (required for testing) <!-- omit in toc -->

* [xTests](https://github.com/synesissoftware/xTests/);
* [b64](https://github.com/synesissoftware/b64/) (optional; often via Pantheios);
* [Diagnosticism](https://github.com/synesissoftware/Diagnosticism/) (optional; version-string formatting in **test.scratch.versions**);
* [Pantheios](https://github.com/synesissoftware/Pantheios/) (optional);
* [shwild](https://github.com/synesissoftware/shwild/) (optional);
* [UNIXem](https://github.com/synesissoftware/UNIXem/) (optional; Windows UNIX-emulation builds);


### Related projects

Projects in which **recls** is used include:

* [**libCLImate**](https://github.com/synesissoftware/libCLImate)


### License

**recls** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
