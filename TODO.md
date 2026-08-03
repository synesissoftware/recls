# recls - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)


## Functional improvements

* [x] ~~~Fix up GigaBytes / GibiBytes~~~ - ✅;
* [x] ~~~macOS infinite (circular) descending recursive search identification and solution~~~ - ✅;
* [x] ~~~`RECLS_F_SOCKETS`~~~ - ✅;
* [x] ~~~`RECLS_F_DEVICES`~~~ - ✅;
* [x] ~~~Prefer wherever possible to use `RECLS_PLATFORM_*` to `PLATFORMSTL_OS_IS_*`~~~ - ✅;
* [x] ~~~Change `RECLS_F_IGNORE_HIDDEN_ENTRIES_ON_WINDOWS` to `RECLS_F_IGNORE_HIDDEN_ENTRIES` and implement for **Unix**~~~ - ✅;
* [ ] Rename/replace **master-1.10** branch to/with **master**;
* [ ] Deal with non-default searching of .-names on Unix (because `glob()` does not by default);
* [ ] Expand progress feedbacks to:
  * [ ] provide warning about inaccessible directories;
  * [ ] indicate visit count (for directory hard-links, as found on macOS);
* [ ] Add `RECLS_REMDIR_F_REMOVE_SOCKETS`;
* [x] ~~~Change all remaining example/test program source files to generic names~~~ - ✅;
* [x] ~~~**UNIXem** support~~~ - ✅;
* [ ] `Recls_SetApiLogFunction()` flags;
* [ ] **recls.NET**-like ability to handle in-process failures - such as inaccessible directories - and allow a handler to specify to skip the failed directory, thereby continuing;
* [ ] Ensure links are processed sensibly:
  * [ ] `RECLS_F_NO_FOLLOW_LINKS`;
* [ ] Proper handling of Windows drives, UNC, etc. - current implementation is pretty naive;
* [ ] Deprecate the FTP search;
* [ ] Filtering by callback (within the search function(s)), possibly supporting lambdas;


## Performance improvements

* \<none>


## Packaging improvements

* [x] ~~~Modular GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with install-smoke~~~ - ✅;
* [x] ~~~**CHANGES.txt** → **CHANGES.md**; remove **HISTORY.md**~~~ - ✅;
* [x] ~~~README badges / Components; **INSTALL.md** hygiene~~~ - ✅;

* [x] ~~~Remove Visual C++ project files, etc.~~~ - ✅;
* [x] ~~~Remove plethora of old makefiles~~~ - ✅;
* [-] ~~~Provide small number of more "intelligent" makefiles~~~ - ❌;
* [ ] Bazel, Jam, SCons, etc. scripts;


<!-- ########################### end of file ########################### -->
