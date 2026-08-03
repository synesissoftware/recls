# recls <!-- omit in toc -->

**rec**ursive **ls**


![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)
![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/recls.svg)](https://github.com/synesissoftware/recls/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/recls)](https://github.com/synesissoftware/recls/commits/master)
[![CMake on multiple platforms](https://github.com/synesissoftware/recls/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/recls/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
- [Installation](#installation)
- [Components](#components)
	- [C API / core library](#c-api--core-library)
	- [C++ API](#c-api)
- [Examples](#examples)
- [Project Information](#project-information)
	- [Where to get help](#where-to-get-help)
	- [Contribution guidelines](#contribution-guidelines)
	- [Dependencies](#dependencies)
	- [Related projects](#related-projects)
	- [License](#license)


## Introduction

**recls** - **rec**ursive **ls** - is a platform-independent recursive file-system search library implemented in C and C++ with a C-API, and a C++ binding.

**recls** is completely free and includes source released under a BSD-style license.


## Installation

Detailed instructions — via **CMake** — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.


## Components


### C API / core library

The **recls** C API provides recursive (and non-recursive) file-system search, stat-like entry queries, path utilities, and related helpers via **recls/recls.h**.


### C++ API

The **recls** C++ API is a header-only binding over the core library, via **recls/recls.hpp** and the headers under **recls/cpp/**.


## Examples

Examples are provided in the `examples` directory, along with a markdown description for each. A detailed list TOC of them is provided in [EXAMPLES.md](./EXAMPLES.md).


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/recls "GitHub Page")


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/recls.

If you'd like to help out with the project, please raise an issue via [GitHub Page](https://github.com/synesissoftware/recls/issues "GitHub Page") - you'll be very welcome!


### Dependencies


#### STLSoft <!-- omit in toc -->

**recls** depends on the **STLSoft** libraries, version 1.11.1 (or later).

* [STLSoft](https://github.com/synesissoftware/STLSoft/);


#### Development Dependencies (required for testing) <!-- omit in toc -->

* [xTests](https://github.com/synesissoftware/xTests/);
* [shwild](https://github.com/synesissoftware/shwild/) (optional);
* [Pantheios](https://github.com/synesissoftware/Pantheios/) (optional);
* [b64](https://github.com/synesissoftware/b64/) (optional; often via Pantheios);
* [UNIXem](https://github.com/synesissoftware/UNIXem/) (optional; Windows UNIX-emulation builds);


### Related projects

Projects in which **recls** is used include:

* [**libCLImate**](https://github.com/synesissoftware/libCLImate)


### License

**recls** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
