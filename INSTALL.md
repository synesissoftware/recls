# recls - Installation and Use <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **recls**, from
   https://github.com/synesissoftware/recls/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/recls/
   ```

2. Prepare the CMake configuration, via the **prepare_cmake.sh** script, as
   in:

   ```bash
   $ cd ~/open-source/recls
   $ ./prepare_cmake.sh
   ```

   **NOTE**: if you intend only to build the library then you can eschew building of examples (`-E`) and tests (`-T`) and use the command:

   ```bash
   $ cd ~/open-source/recls
   $ ./prepare_cmake.sh -E -T
   ```

   You will still need [**STLSoft**](https://github.com/synesissoftware/STLSoft) (1.11 or later).

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 2 then you do
   not need this step.)

4. As a check, execute the built test program files via the
   **run_all_unit_tests.sh** script, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:

   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

6. Then to use the library, it is a simple matter as follows:

   1. Assuming a simplest possible program to verify the installation:

        ```c
        // main.c
        #include <recls/recls.h>
        #include <stdio.h>
        #include <stdlib.h>

        int main(int argc, char* argv[])
        {
          ((void)&argc);
          ((void)&argv);

          printf("recls wildcards: %s\n", Recls_GetWildcardsAll());

          return EXIT_SUCCESS;
        }
        ```

   2. Compile your project against **recls**:

      Due to the installation step (Step 5 above) there is no requirement
      for an explicit include directory for **recls**:

      ```bash
      $ cc -c -D UNIX main.c
      ```

   3. Link your project against **recls**:

      Due to the installation step (Step 5 above) there is no requirement
      for an explicit library directory for **recls**:

      ```bash
      $ c++ main.o -lrecls
      ```

   4. Test your project:

      Then you can run, as in:

      ```bash
      $ ./a.out
      recls wildcards: ...
      $
      ```


<!-- ########################### end of file ########################### -->

