# CLASP.Ruby Examples

|Name|Language|Source & Description|Summary|
|---|---|---|---|
|**example_c_1**|C|[examples/c/example_c_1/main.c](./examples/c/example_c_1/main.c)<br/>[examples/c/example_c_1.md](./examples/c/example_c_1.md)|Illustrates recursive search, via `Recls_Search()`, and display of each full path.|
|**example_c_2**|C|[examples/c/example_c_2/main.c](./examples/c/example_c_2/main.c)<br/>[examples/c/example_c_2.md](./examples/c/example_c_2.md)|Illustrates callback recursive search, via `Recls_SearchFeedback()`, and display of each full path.|
|**example_c_3**|C|[examples/c/example_c_3/main.c](./examples/c/example_c_3/main.c)<br/>[examples/c/example_c_3.md](./examples/c/example_c_3.md)|Illustrates use of `Recls_Stat()`, `Recls_Search()`, `Recls_SqueezePath()`, `Recls_CalcDirectoryEntrySize()`.|
|**example_c_4**|C|[examples/c/example_c_4/main.c](./examples/c/example_c_4/main.c)<br/>[examples/c/example_c_4.md](./examples/c/example_c_4.md)|Illustrates non-recursive search for directories (`RECLS_F_DIRECTORIES`) and elimination of non-empty directories by `Recls_IsDirectoryEntryEmpty()`.|
|**example_c_5**|C|[examples/c/example_c_5/main.c](./examples/c/example_c_5/main.c)<br/>[examples/c/example_c_5.md](./examples/c/example_c_5.md)|Illustrates obtaining `stat()` of home directory via `Recls_Stat()`, then recursive search of files (`RECLS_F_FILES`) and directories (`RECLS_F_DIRECTORIES`), listing search-relative paths via `Recls_DeriveRelativePath()`.|
|**example_c_6**|C|[examples/c/example_c_6/main.c](./examples/c/example_c_6/main.c)<br/>[examples/c/example_c_6.md](./examples/c/example_c_6.md)|Illustrates obtaining `stat()` of current directory via `Recls_Stat()`, then breakdown of path elements (such as directory-path, directory, stem, extension, etc.).|
|**example_c_7**|C|[examples/c/example_c_7/main.c](./examples/c/example_c_7/main.c)<br/>[examples/c/example_c_7.md](./examples/c/example_c_7.md)|Illustrates obtaining `stat()` of current directory via `Recls_Stat()`, and then combining with a relative path via `Recls_CombinePaths()`.|
|**example_c_8**|C|[examples/c/example_c_8/main.c](./examples/c/example_c_8/main.c)<br/>[examples/c/example_c_8.md](./examples/c/example_c_8.md)|Illustrates elicitation of roots via `Recls_GetRoots()` and `Recls_GetSelectedRoots()`, and then obtaining size of files under one of the selected roots via `Recls_CalcDirectorySize()`.|
|**example_cpp_1**|C++|[examples/cpp/example_cpp_1/main.cpp](./examples/cpp/example_cpp_1/main.cpp)<br/>[examples/cpp/example_cpp_1.md](./examples/cpp/example_cpp_1.md)|Illustrates recursive search using `recls::search_sequence`|
|**example_cpp_2**|C++|[examples/cpp/example_cpp_2/main.cpp](./examples/cpp/example_cpp_2/main.cpp)<br/>[examples/cpp/example_cpp_2.md](./examples/cpp/example_cpp_2.md)|Illustrates obtaining `stat()` of home directory using `recls::stat`, then recursive search under that of files matching a complex pattern|
|**example_cpp_3**|C++|[examples/cpp/example_cpp_3/main.cpp](./examples/cpp/example_cpp_3/main.cpp)<br/>[examples/cpp/example_cpp_3.md](./examples/cpp/example_cpp_3.md)|Illustrates obtaining `stat()` of home directory using `recls::stat`, then recursive search under that of files matching a complex pattern|


<!-- ########################### end of file ########################### -->

