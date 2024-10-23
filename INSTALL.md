# recls - Installation and Use <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)
- [Custom makefile](#custom-makefile)


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

   In this case, you do not need to have installed [**STLSoft**](https://github.com/synesissoftware/STLSoft-1.10); otherwise, you will.

3. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 3 then you do
   not need this step.)

4. As a check, execute the built test program files via the
   **build_run_all_unit_tests.sh** script, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

5. Install the library on the host, via `cmake`, as in:


   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

7. Then to use the library, it is a simple matter as follows:

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

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit include directory for **recls**:

      ```bash
      $ cc -c -D UNIX main.c
      ```

   3. Link your project against **recls**:

      Due to the installation step (Step 6 above) there is no requirement
      for an explicit library directory for **recls**:

      ```bash
      $ c++ main.o -lrecls
      ```

   4. Test your project:

      Then you can run, as in:

      ```bash
      $ ./a.out
      using recls (minimally)
      $
      ```


## Custom makefile

Before support for **CMake** was provided, the recommended approach was to
use one of the custom makefiles provided with the project, as follows:

1. Obtain the latest distribution of **recls**, from
   https://github.com/synesissoftware/recls/, as in:

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/recls/
   ```

2. Determine the custom makefile appropriate for your compiler:

   For example, if running on **UNIX** and using **GCC v4.2.1** then the
   requisite **makefile** will reside in **build/gcc42.unix**.

   ```bash
   $ ls -al build/gcc42.unix/makefile
   ```

3. Execute a test build, passing the target `clean`:

   ```bash
   # from within build/gcc42.unix
   $ make clean
   ```

   You should see output such as the following:

   ```
   cleaning Core libraries ...
   cleaning recls libraries ...
   cleaning Test:Component programs ...
   cleaning Test:Scratch programs ...
   cleaning Test:Unit programs ...
   ```

4. Build the **recls** library configurations, using the target `build`:

   ```bash
   # from within build/gcc42.unix
   $ make build
   . . .
   $
   ```

6. Then to use the library, it was customary practice to make available the
   **recls** header files and built files as follows:

   1. Assuming a simplest possible program to verify the installation:

        ```cpp
        // main.cpp
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

   2. Create an environment variable `recls_ROOT` with the value of the
      root directory of the **recls** project, as in:

      ```bash
      $ export recls_ROOT=~/open-source/recls
      ```

   3. Compile your project against **recls**:

      This requires explicit use of the environment variable `recls_ROOT`
      (and the environment variable `STLSOFT` discussed above).

      ```bash
      $ g++ -c -I ${recls_ROOT}/include -std=c++11 main.cpp
      ```

   4. Link your project against **recls**:

      Given the above main step to build the library, examining the **lib**
      directory:

      ```bash
      $ ls -al lib
      ```

      should show a bunch of files, including:

      ```
      . . .
      -rw-r--r--   1 mwan  staff   110K 30 Nov 12:24 librecls.0.core.gcc42.a
      -rw-r--r--   1 mwan  staff   262K 30 Nov 12:24 librecls.0.core.gcc42.debug.a
      -rw-r--r--   1 mwan  staff   110K 30 Nov 12:24 librecls.0.core.gcc42.mt.a
      -rw-r--r--   1 mwan  staff   262K 30 Nov 12:24 librecls.0.core.gcc42.mt.debug.a
      ```

      The best choice is `librecls.0.core.gcc42.a`, which is the archive
      for Release configuration and compiled without `_REENTRANT` as we
      don't care about multithreaded program support in this example.

      So, we link to **recls** via:

      ```bash
      $ g++ main.o -L ${recls_ROOT}/lib -lrecls.0.core.gcc42
      ```

   5. Test your project:

      Run the resulting program with the argument `--verbosity=4` as in:

      ```bash
      $ ./a.out
      using recls (minimally)
      $
      ```



<!-- ########################### end of file ########################### -->

