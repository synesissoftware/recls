# CLASP.Ruby Examples

| Name | Language | Source & Description | Summary |
| --- | --- | --- | --- |
|**example_c_1**|C|[examples/c/example_c_1/main.c](./examples/c/example_c_1/main.c)<br/>[examples/c/example_c_1.md](./examples/c/example_c_1.md)|Demonstrates recursive search for all files under a given directory including all appropriate failure handling.|
|**example_c_2**|C|[examples/c/example_c_2/main.c](./examples/c/example_c_2/main.c)<br/>[examples/c/example_c_2.md](./examples/c/example_c_2.md)|Demonstrates recursive search with feedback for all files matching a multi-part pattern under a given directory including all appropriate failure handling.|
|**example_c_3**|C|[examples/c/example_c_3/main.c](./examples/c/example_c_3/main.c)<br/>[examples/c/example_c_3.md](./examples/c/example_c_3.md)|Demonstrates non-recursive search for all files and directories under a given directory and displays their size, that being the size of all contained files (including in sub-directories) in the case of directories.|
|**example_c_4**|C|[examples/c/example_c_4/main.c](./examples/c/example_c_4/main.c)<br/>[examples/c/example_c_4.md](./examples/c/example_c_4.md)|Demonstrates recursive search for all directories under the home or a named directory and displays the full path for any of them that has no files in it (or any of its subdirectories).|
|**example_c_5**|C|[examples/c/example_c_5/main.c](./examples/c/example_c_5/main.c)<br/>[examples/c/example_c_5.md](./examples/c/example_c_5.md)|Demonstrates obtaining `stat()` of home directory via `Recls_Stat()`, then recursive search of files (`RECLS_F_FILES`) and directories (`RECLS_F_DIRECTORIES`), listing search-relative paths via `Recls_DeriveRelativePath()`.|
|**example_c_6**|C|[examples/c/example_c_6/main.c](./examples/c/example_c_6/main.c)<br/>[examples/c/example_c_6.md](./examples/c/example_c_6.md)|Demonstrates obtaining `stat()` of current directory via `Recls_Stat()`, then breakdown of path elements (such as directory-path, directory, stem, extension, etc.).|
|**example_c_7**|C|[examples/c/example_c_7/main.c](./examples/c/example_c_7/main.c)<br/>[examples/c/example_c_7.md](./examples/c/example_c_7.md)|Demonstrates obtaining `stat()` of current directory via `Recls_Stat()`, and then combining with a relative path via `Recls_CombinePaths()`.|
|**example_c_8**|C|[examples/c/example_c_8/main.c](./examples/c/example_c_8/main.c)<br/>[examples/c/example_c_8.md](./examples/c/example_c_8.md)|Demonstrates elicitation of roots via `Recls_GetRoots()` and `Recls_GetSelectedRoots()`, and then obtaining size of files under one of the selected roots via `Recls_CalcDirectorySize()`.|
|**example_cpp_1**|C++|[examples/cpp/example_cpp_1/main.cpp](./examples/cpp/example_cpp_1/main.cpp)<br/>[examples/cpp/example_cpp_1.md](./examples/cpp/example_cpp_1.md)|Demonstrates recursive search using `recls::search_sequence`|
|**example_cpp_2**|C++|[examples/cpp/example_cpp_2/main.cpp](./examples/cpp/example_cpp_2/main.cpp)<br/>[examples/cpp/example_cpp_2.md](./examples/cpp/example_cpp_2.md)|Demonstrates obtaining `stat()` of home directory using `recls::stat`, then recursive search under that of files matching a complex pattern|
|**example_cpp_3**|C++|[examples/cpp/example_cpp_3/main.cpp](./examples/cpp/example_cpp_3/main.cpp)<br/>[examples/cpp/example_cpp_3.md](./examples/cpp/example_cpp_3.md)|Demonstrates obtaining `stat()` of home directory using `recls::stat`, then recursive search under that of files matching a complex pattern|


<!-- ########################### end of file ########################### -->

