# CLASP.Ruby Examples

| Name | Language | Source & Description | Summary |
| --- | --- | --- | --- |
|**example_c_1**|C|[examples/c/example_c_1/main.c](./examples/c/example_c_1/main.c)<br/>[examples/c/example_c_1.md](./examples/c/example_c_1.md)|Demonstrates recursive search for all files under a given directory including all appropriate failure handling.|
|**example_c_2**|C|[examples/c/example_c_2/main.c](./examples/c/example_c_2/main.c)<br/>[examples/c/example_c_2.md](./examples/c/example_c_2.md)|Demonstrates recursive search with feedback for all files matching a multi-part pattern under a given directory including all appropriate failure handling.|
|**example_c_3**|C|[examples/c/example_c_3/main.c](./examples/c/example_c_3/main.c)<br/>[examples/c/example_c_3.md](./examples/c/example_c_3.md)|Demonstrates non-recursive search for all files and directories under a given directory and displays their size, that being the size of all contained files (including in sub-directories) in the case of directories.|
|**example_c_4**|C|[examples/c/example_c_4/main.c](./examples/c/example_c_4/main.c)<br/>[examples/c/example_c_4.md](./examples/c/example_c_4.md)|Demonstrates recursive search for all directories under the home or a named directory and displays the full path for any of them that has no files in it (or any of its subdirectories).|
|**example_c_5**|C|[examples/c/example_c_5/main.c](./examples/c/example_c_5/main.c)<br/>[examples/c/example_c_5.md](./examples/c/example_c_5.md)|Demonstrates recursive search via process callback function, in which the entry's path is shown relative to the home or given directory.|
|**example_c_6**|C|[examples/c/example_c_6/main.c](./examples/c/example_c_6/main.c)<br/>[examples/c/example_c_6.md](./examples/c/example_c_6.md)|Demonstrates use of `Recls_Stat()` on current directory or named path, showing various elements of the path in exploded form|
|**example_c_7**|C|[examples/c/example_c_7/main.c](./examples/c/example_c_7/main.c)<br/>[examples/c/example_c_7.md](./examples/c/example_c_7.md)|Demonstrates combining of paths via `Recls_CombinePaths()`.|
|**example_c_8**|C|[examples/c/example_c_8/main.c](./examples/c/example_c_8/main.c)<br/>[examples/c/example_c_8.md](./examples/c/example_c_8.md)|Demonstrates elicitation of roots via `Recls_GetRoots()` and `Recls_GetSelectedRoots()`, and then obtaining size of files under one of the selected roots via `Recls_CalcDirectorySize()`.|
|**example_cpp_1**|C++|[examples/cpp/example_cpp_1/main.cpp](./examples/cpp/example_cpp_1/main.cpp)<br/>[examples/cpp/example_cpp_1.md](./examples/cpp/example_cpp_1.md)|Demonstrates recursive search for all files under a given directory including all appropriate failure handling.|
|**example_cpp_2**|C++|[examples/cpp/example_cpp_2/main.cpp](./examples/cpp/example_cpp_2/main.cpp)<br/>[examples/cpp/example_cpp_2.md](./examples/cpp/example_cpp_2.md)|Demonstrates obtaining `stat()` of home directory using `recls::stat`, then recursive search under that of files matching a complex pattern|
|**example_cpp_3**|C++|[examples/cpp/example_cpp_3/main.cpp](./examples/cpp/example_cpp_3/main.cpp)<br/>[examples/cpp/example_cpp_3.md](./examples/cpp/example_cpp_3.md)|Demonstrates use of `recls::stat()` on current directory or named path, optionally specifying a type filter (use `"--help"` for usage), showing various elements of the path in exploded form|


<!-- ########################### end of file ########################### -->

