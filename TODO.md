# recls - TODO <!-- omit in toc -->

## recls 1.10

* [x] Fix up GigaBytes / GibiBytes;
* [x] macOS infinite (circular) descending recursive search identification and solution;
* [x] `RECLS_F_SOCKETS`;
* [x] `RECLS_F_DEVICES`;
* [ ] `RECLS_F_NO_FOLLOW_LINKS`;
* [ ] Add `RECLS_REMDIR_F_REMOVE_SOCKETS`;
* [ ] Prefer wherever possible to use `RECLS_PLATFORM_*` to `PLATFORMSTL_OS_IS_*`;
* [ ] Renamed/replace **master-1.10** branch to/with **master**;
* [ ] Deal with non-default searching of .-names on Unix (because `glob()` does not by default);
* [ ] Expand progress feedbacks to:
  * [ ] provide warning about inaccessible directories;
  * [ ] indicate visit count (for directory hard-links, as found on macOS);
* [x] Remove Visual C++ project files, etc.;
* [ ] Remove plethora of old makefiles;
* [ ] Provide small number of more "intelligent" makefiles;
* [ ] Change all remaining example/test program source files to generic names;


## recls 1.11

* [ ] `Recls_SetApiLogFunction()` flags;
* [ ] **recls.NET**-like ability to handle in-process failures - such as inaccessible directories - and allow a handler to specify to skip the failed directory, thereby continuing;
* [ ] Ensure links are processed sensibly;
* [ ] Bazel, Jam, SCons, etc. scripts;
* [ ] Filtering by callback (within the search function(s)), possibly supporting lambdas;


<!-- ########################### end of file ########################### -->

