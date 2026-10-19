# recls - Components Inventory (working ledger) <!-- omit in toc -->

This is the working ledger of the components of **recls** **1.10.0-rc5**: every substantive public capability introduced in **1.10.x**, the notable **1.9.x** additions, the legacy core that matters, and a full inventory of public headers under **include/recls/**. It is the source of truth for the Components tables in **README.md**. It was generated on 20th October 2026 from the working tree at tag **1.10.0-rc5**.


## Table of Contents <!-- omit in toc -->

- [Method](#method)
- [Summary](#summary)
- [B - New in 1.10.x](#b---new-in-110x)
- [C - Notable in 1.9.x](#c---notable-in-19x)
- [D - Legacy core (≤1.8)](#d---legacy-core-18)
- [E - Used by other SIS projects](#e---used-by-other-sis-projects)
- [Other signals](#other-signals)
  - [Deprecated / to-deprecate](#deprecated--to-deprecate)
  - [1.10 enhancement candidates from CHANGES.md](#110-enhancement-candidates-from-changesmd)
- [Full inventory](#full-inventory)
  - [Public headers](#public-headers)
  - [Support / excluded paths](#support--excluded-paths)


## Method

* **Unit** — hybrid, because **recls** has few public headers and most 1.10 value is API surface inside existing headers:
  * a **public header stem** (`.h` / `.hpp`; pairs under **recls/** and **recls/cpp/** count once each); and/or
  * a **notable API unit** — a C function / flag / type, or a C++ type / free function, that a consumer would seek by name;
* **Support headers** (paths containing `internal/`, `implicit_link`, compiler discriminators, `assert.h`, `fwd.hpp`, `classfwd.hpp`, `common.hpp`, `traits.hpp`) are inventoried but **not** nominated for README Notable tables unless they are the only home of a public type;
* **Since** — first release recorded in **CHANGES.md** (preferred) or the earliest Git tag in this repository that contains the symbol. Tag history begins at **1.9.1**, so every pre-existing header / API shows **≤1.8** (or **≤1.9.1** when the first recorded mention is the 1.9.1 dump). Stub / "not currently supported" declarations that later gained real behaviour are dated at the **behaviour** release, not the stub. Badges in the B / C / D tables use the same colours as **README.md**: dark grey for **≤1.8**, orange for **1.9.x**, blue for **1.10+**;
* **Layer** — **C** (core API in **recls.h** / **ftp.h** / **unix.h** / **windows.h**), **C++** (binding under **recls/cpp/** and **recls.hpp**), or **Platform** (unix / windows / FTP facets);
* **E** — `#include <recls/…>` from non-test, non-example sources in other freelibs projects (and noted tools). Tests/examples are a weaker signal and are omitted here unless no other consumer exists;
* **B / C / D** — curated for README; the full public-header list is under [Full inventory](#full-inventory);


## Summary

| Set | Count |
| --- | ---: |
| Public header files under **include/recls/** (excl. **internal/**) | 20 |
| of which support / not README-nominated | 7 |
| of which substantive public headers | 13 |
| Support files under **internal/** | 17 |
| B — notable new / behaviourally new in 1.10.x | 14 |
| C — notable in 1.9.x | 8 |
| D — legacy core units (≤1.8) | 12 |
| E — other SIS projects known to include **recls** | 1 (**libCLImate**) |


## B - New in 1.10.x

| Component | Layer | Since | Notes |
| --- | --- | --- | --- |
| [`RECLS_F_SOCKETS`](../include/recls/recls.h) / [`Recls_IsEntrySocket()`](../include/recls/recls.h) / [`recls::entry::is_socket()`](../include/recls/cpp/entry.hpp) | C / C++ | [![since 1.10.0-beta1](https://img.shields.io/badge/since-1.10.0--beta1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta1) [![since 1.10.0-beta5](https://img.shields.io/badge/since-1.10.0--beta5-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta5) | `IsEntrySocket` at beta1; search flag / **example_c_9** at beta5; skipped on Windows CMake cells |
| [`RECLS_F_DEVICES`](../include/recls/recls.h) / [`Recls_IsEntryDevice()`](../include/recls/recls.h) / [`recls::entry::is_device()`](../include/recls/cpp/entry.hpp) | C / C++ | [![since 1.10.0-beta6](https://img.shields.io/badge/since-1.10.0--beta6-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta6) | Real device search (flag existed earlier as unsupported stub); **example_c_10** |
| [`recls::device()`](../include/recls/cpp/entry.hpp) / [`recls::directory()`](../include/recls/cpp/entry.hpp) / [`recls::file()`](../include/recls/cpp/entry.hpp) / [`recls::socket()`](../include/recls/cpp/entry.hpp) | C++ | [![since 1.10.0-rc2](https://img.shields.io/badge/since-1.10.0--rc2-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc2) | Typed `stat`-like helpers (filter or throw) |
| [`RECLS_F_NO_BREAK_INFINITE_LOOPS`](../include/recls/recls.h) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Opt out of Linux/macOS directory-loop guard |
| [`RECLS_F_IGNORE_HIDDEN_ENTRIES`](../include/recls/recls.h) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Renamed from Windows-only flag; Unix behaviour added |
| [`RECLS_REMDIR_F_REMOVE_SOCKETS`](../include/recls/recls.h) | C | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Moderates [`Recls_RemoveDirectory()`](../include/recls/recls.h) |
| [`Recls_GetFileSizeGibiBytes()`](../include/recls/recls.h) (and Ki/Me/Te siblings) | C | [![since 1.10.0-beta4](https://img.shields.io/badge/since-1.10.0--beta4-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta4) | IEC binary size helpers; SI helpers corrected |
| [`Recls_IsEntry*()`](../include/recls/recls.h) rename family | C | [![since 1.10.0-beta1](https://img.shields.io/badge/since-1.10.0--beta1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-beta1) | Supersedes `Recls_IsFile*()` (compat retained) |
| [`recls::search_sequence`](../include/recls/cpp/search_sequence.hpp) progress overload | C++ | [![since 1.10.0-alpha1](https://img.shields.io/badge/since-1.10.0--alpha1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-alpha1) | 4th/5th parameters for directory feedback |
| CMake package / helpers | Packaging | [![since 1.10.0-alpha5](https://img.shields.io/badge/since-1.10.0--alpha5-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-alpha5) | Primary install path; see **INSTALL.md** |
| **UNIXem** support (`--use-unixem`) | Platform | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Evaluate UNIX path on Windows; floor **1.14.1** at rc4 |
| `recls_rc_t` insertion operator | C++ | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Diagnostics / iostreams |
| `std::atomic` refcounting (C++14+) | C++ | [![since 1.10.0-rc1](https://img.shields.io/badge/since-1.10.0--rc1-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc1) | Replaces PThreads / Windows threads dependency |
| Modular CI (**ci.yml** / **ci-cell.yml**) | Packaging | [![since 1.10.0-rc3](https://img.shields.io/badge/since-1.10.0--rc3-0969da.svg)](https://github.com/synesissoftware/recls/releases/tag/1.10.0-rc3) | Install-smoke; Windows **.cmd** dogfood at rc4 |


## C - Notable in 1.9.x

| Component | Layer | Since | Notes |
| --- | --- | --- | --- |
| [`NO_MORE_DATA_exception`](../include/recls/cpp/exceptions.hpp) | C++ | [![since 1.9.6](https://img.shields.io/badge/since-1.9.6-bf8700.svg)](https://github.com/synesissoftware/recls/releases/tag/1.9.6) | Maps `RECLS_RC_NO_MORE_DATA` |
| [`RECLS_F_LINK_COUNT`](../include/recls/recls.h) / `numLinks` | C | [![since ≤1.9.1-alpha7](https://img.shields.io/badge/since-%E2%89%A41.9.1--alpha7-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Link-count elicitation |
| [`RECLS_F_NODE_INDEX`](../include/recls/recls.h) / `deviceId` / `nodeIndex` / `volumeSerialNumber` | C | [![since ≤1.9.1-alpha8](https://img.shields.io/badge/since-%E2%89%A41.9.1--alpha8-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Entry identity fields |
| [`Recls_GetErrno()`](../include/recls/recls.h) | C | [![since ≤1.9.1-alpha7](https://img.shields.io/badge/since-%E2%89%A41.9.1--alpha7-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Platform errno bridge |
| [`Recls_ResultCodeToUnixErrorCode()`](../include/recls/recls.h) / [`Recls_ResultCodeToWindowsErrorCode()`](../include/recls/recls.h) | C | [![since ≤1.9.1-alpha7](https://img.shields.io/badge/since-%E2%89%A41.9.1--alpha7-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Result-code translation |
| `RECLS_RC_ENTRY_IS_DIRECTORY` / `RECLS_RC_ENTRY_IS_NOT_DIRECTORY` | C | [![since ≤1.9.1-alpha7](https://img.shields.io/badge/since-%E2%89%A41.9.1--alpha7-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Replaced `RECLS_RC_WRONG_ENTRY_TYPE` |
| [`recls/cpp/unix.hpp`](../include/recls/cpp/unix.hpp) / [`recls/cpp/windows.hpp`](../include/recls/cpp/windows.hpp) | C++ | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Platform facets of the C++ binding |
| [`recls/recls.hpp`](../include/recls/recls.hpp) umbrella | C++ | [![since ≤1.9.1](https://img.shields.io/badge/since-%E2%89%A41.9.1-bf8700.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Header-only C++ entry (Created 2010) |


## D - Legacy core (≤1.8)

| Component | Layer | Since | Notes |
| --- | --- | --- | --- |
| [`recls/recls.h`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Core C API (Created 2003) |
| [`Recls_Search()`](../include/recls/recls.h) / [`Recls_SearchFeedback()`](../include/recls/recls.h) / [`Recls_SearchProcess()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Search control |
| [`Recls_Stat()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Single-path elicitation |
| [`Recls_GetNext()`](../include/recls/recls.h) / [`Recls_GetDetails()`](../include/recls/recls.h) / [`Recls_GetNextDetails()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Search enumeration |
| [`Recls_GetRoots()`](../include/recls/recls.h) / [`Recls_GetSelectedRoots()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | File-system roots |
| [`Recls_CombinePaths()`](../include/recls/recls.h) / [`Recls_DeriveRelativePath()`](../include/recls/recls.h) / [`Recls_SqueezePath()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Path utilities |
| [`Recls_CreateDirectory()`](../include/recls/recls.h) / [`Recls_RemoveDirectory()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Directory create/remove (1.10 adds socket-removal flags) |
| [`Recls_CalcDirectorySize()`](../include/recls/recls.h) | C | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Directory size |
| [`recls::search_sequence`](../include/recls/cpp/search_sequence.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Primary C++ search sequence (Created 2003) |
| [`recls::entry`](../include/recls/cpp/entry.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Entry facade (Created 2003) |
| [`recls::root_sequence`](../include/recls/cpp/root_sequence.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Roots enumeration (Created 2004) |
| [`recls::directory_parts`](../include/recls/cpp/directory_parts.hpp) | C++ | [![since ≤1.8](https://img.shields.io/badge/since-%E2%89%A41.8-404040.svg)](https://github.com/synesissoftware/recls/blob/master/CHANGES.md) | Path part sequence (Created 2003) |


## E - Used by other SIS projects

| Project | Signal |
| --- | --- |
| [**libCLImate**](https://github.com/synesissoftware/libCLImate) | Documents **recls** as a dependency; implicit-link and scratch versions pull it in |

Broader Ruby / tool usage of **recls.Ruby** is tracked separately (see freelibs **.management/strategy/recls-helpers/**); this ledger is the C/C++ library only.


## Other signals


### Deprecated / to-deprecate

* FTP search ([`recls/ftp.h`](../include/recls/ftp.h), [`recls::ftp_search_sequence`](../include/recls/cpp/ftp_search_sequence.hpp)) — nominated for deprecation in **TODO.md**;
* `Recls_IsFile*()` — superseded by `Recls_IsEntry*()` (compat retained);


### 1.10 enhancement candidates from CHANGES.md

Raw **CHANGES.md** items that enhanced existing units rather than introducing new headers (already folded into B where they are the primary story):

* macOS / Linux infinite-loop guard (default on; `RECLS_F_NO_BREAK_INFINITE_LOOPS` to disable);
* Hidden-entry suppression on Unix;
* `RECLS_F_STOP_ON_ACCESS_FAILURE` consistency;
* Pattern-string sharing across search nodes (memory);
* Apple / `__unix__` platform recognition in **platform.h** (rc4);
* Optional **2be** / **Diagnosticism** discovery for examples / **test.scratch.versions**;


## Full inventory


### Public headers

| Header | Created | Layer | Role | README-notable? |
| --- | --- | --- | --- | --- |
| [`recls/recls.h`](../include/recls/recls.h) | 15th August 2003 | C | Core C API | yes (D + B flags/APIs) |
| [`recls/recls.hpp`](../include/recls/recls.hpp) | 5th January 2010 | C++ | C++ umbrella | yes (C) |
| [`recls/ftp.h`](../include/recls/ftp.h) | 18th August 2003 | C / Platform | FTP search API | yes (deprecate signal) |
| [`recls/unix.h`](../include/recls/unix.h) | 18th August 2003 | Platform | Unix facet | yes (layer) |
| [`recls/windows.h`](../include/recls/windows.h) | 18th August 2003 | Platform | Windows facet | yes (layer) |
| [`recls/cpp/search_sequence.hpp`](../include/recls/cpp/search_sequence.hpp) | 10th September 2003 | C++ | Search sequence | yes (D + B) |
| [`recls/cpp/entry.hpp`](../include/recls/cpp/entry.hpp) | 18th August 2003 | C++ | Entry + typed `stat` helpers | yes (D + B) |
| [`recls/cpp/exceptions.hpp`](../include/recls/cpp/exceptions.hpp) | 10th September 2003 | C++ | Exceptions | yes (C: `NO_MORE_DATA_exception`) |
| [`recls/cpp/util.hpp`](../include/recls/cpp/util.hpp) | 18th August 2003 | C++ | Path / directory utilities | yes (D) |
| [`recls/cpp/directory_parts.hpp`](../include/recls/cpp/directory_parts.hpp) | 18th August 2003 | C++ | Directory parts | yes (D) |
| [`recls/cpp/root_sequence.hpp`](../include/recls/cpp/root_sequence.hpp) | 25th March 2004 | C++ | Root sequence | yes (D) |
| [`recls/cpp/ftp_search_sequence.hpp`](../include/recls/cpp/ftp_search_sequence.hpp) | 10th September 2003 | C++ | FTP search sequence | yes (deprecate signal) |
| [`recls/cpp/unix.hpp`](../include/recls/cpp/unix.hpp) | 6th November 2011 | C++ | Unix C++ facet | yes (C) |
| [`recls/cpp/windows.hpp`](../include/recls/cpp/windows.hpp) | 13th November 2010 | C++ | Windows C++ facet | yes (C) |
| [`recls/cpp/common.hpp`](../include/recls/cpp/common.hpp) | 18th August 2003 | C++ | Shared C++ support | no (support) |
| [`recls/cpp/traits.hpp`](../include/recls/cpp/traits.hpp) | 25th March 2004 | C++ | Traits | no (support) |
| [`recls/cpp/classfwd.hpp`](../include/recls/cpp/classfwd.hpp) | 23rd November 2011 | C++ | Forward decls | no (support) |
| [`recls/fwd.hpp`](../include/recls/fwd.hpp) | (fwd) | C++ | Forward decls | no (support) |
| [`recls/assert.h`](../include/recls/assert.h) | (assert) | C | Assertions | no (support) |
| [`recls/implicit_link.h`](../include/recls/implicit_link.h) | (link) | C | Implicit link | no (support) |


### Support / excluded paths

Under **include/recls/internal/**: compiler discriminators (`compiler_*.h`, `compiler.h`), `language.h`, `platform.h`, `platform_types.h`, `recls_filesize.h`, `recls_time.h`, `retcodes.h`, `safestr.h`, `warning/` — counted as support; not nominated for README Notable tables.


<!-- ########################### end of file ########################### -->
