# Vitimiti's Compiler

This is a header only library that sets compiler preprocessor options to be able to easily export
and use multi-compiler options.

You may generate extra documentation by passing down the
option `-VITIMITI_COMPILER_BUILD_API_DOCS:BOOL=ON`.

## Example Usage

To export your API, you may do:

```cpp
#include <vitimiti/compiler/export.hpp>

namespace my::api {
class VITIMITI_EXPORT obj {
public:
  // ...

private:
  // ...
};
}
```

To declare a function's call type and export it, you may do:

```cpp
#include <vitimiti/compiler/declaration.hpp>
#include <vitimiti/compiler/export.hpp>

namespace my::api {
VITIMITI_EXPORT auto VITIMITI_DECLARATION_STD_CALL
my_function() -> void {
  // ...
}
}
```

## How To use

You should use this library as a header only library. Therefore, there is no library to link to,
just directories to include.

This library, like all of Vitimiti's libraries, is in a structure of `(library-path)/include/vitimiti` and the name of the library, in this case `compiler`, forming the final
path `(library-path)/include/vitimiti`. Knowing this, you have two options:

### Downloading the source code and including it in your project

Simply download the source code into your computer and indicate in your CMake where the include
directory is found. For
example: `target_include_directories(\${PROJECT_NAME} PRIVATE \${CMAKE_SOURCE_DIR}/vendor/include)`
will allow you to do, for example: `#include <vitimiti/compiler/export.hpp>` assuming that the
include directory has a directory called `vitimiti` which includes the compiler headers, respecting
therefore the structure of the original project.

### Using FetchContent

If you use FetchContent, you can download this project's sources without including them in your
project and use them the same.

For example, if you had done `add_subdirectory(vendor)` where `vendor` is a directory which includes
a `CMakeLists.txt`, this file could include the following:

```cmake
include(FetchContent)

FetchContent_Declare(
  VITIMITI_COMPILER
  GIT_REPOSITORY https://github.com/vitimiti/compiler.git
  GIT_TAG main)

FetchContent_MakeAvailable(VITIMITI_COMPILER)
```

With this included, you may then do, in your project's
CMakeLists.txt: `target_include_directories(\${PROJECT_NAME} PRIVATE \${VITIMITI_COMPILER_SOURCE_DIR}/include)`.

Now you will be able to do, in your sources: `#include <vitimiti/compiler/export.hpp>`.

## Supported Compilers

- MSVC (cl.exe)
- GCC (gcc / g++)
- Clang (clang / clang++)
- MinGW (i686-mingw-w64-gcc / i686-mingw-w64-g++ / x86_64-mingw-w64-gcc / x86_64-mingw-w64-g++)

Other compilers may work with some of the API but they are not tested.

## API Exporting / Importing

- VITIMITI_API_EXPORT
  - Windows:
    - MSVC:
      - If WINDOWS_EXPORT_SYMBOLS is defined: `__declspec(dllexport)`
      - If WINDOWS_EXPORT_SYMBOLS is **not** defined: `__declspec(dllimport)`
    - GCC / Clang / MinGW:
      - If WINDOWS_EXPORT_SYMBOLS is defined: `__attribute__((dllexport))`
      - If WINDOWS_EXPORT_SYMBOLS is **not** defined: `__attribute__((dllimport))`
  - UNIX / Linux / Mac:
    - GCC / Clang / MinGW: `__attribute__((visibility("default")))`
- VITIMITI_API_IMPORT
  - Windows:
    - MSVC: `__declspec(dllimport)`
    - GCC / Clang / MinGW: `__attribute__((dllimport))`
  - UNIX / Linux / Mac: `__attribute__((visibility("hidden")))`

## Function Declaration

- VITIMITI_DECLARATION_C_DECL:
  - Windows:
    - MSVC: `__cdecl`
- VITIMITI_DECLARATION_CLR_CALL:
  - Windows:
    - MSVC: `__clrcall`
- VITIMITI_DECLARATION_STD_CALL:
  - Windows:
    - MSVC: `__stdcall`
- VITIMITI_DECLARATION_FAST_CALL:
  - Windows:
    - MSVC: `__fastcall`
- VITIMITI_DECLARATION_THIS_CALL:
  - Windows:
    - MSVC: `__thiscall`
- VITIMITI_DECLARATION_VECTOR_CALL:
  - Windows:
    - MSVC: `__vectorcall`

All of these declarations are undefined in other compilers.

## CMake Options

- VITIMITI_COMPILER_BUILD_API_DOCS (BOOL): Whether to build the documentation (requires graphviz's
  dot and doxygen to be in the `$PATH`).
- VITIMITI_COMPILER_INSTALL_LIBRARY (BOOL): Whether to generate install scripts.
- WINDOWS_EXPORT_SYMBOLS (BOOL): Whether to export symbols in Windows or not.

To pass an option, simply include it as a `-D` option to cmake. For example, to simply build the
documentation because we are developing this library:

```bash
mkdir build
cd build
cmake -DVITIMITI_COMPILER_BUILD_API_DOCS:BOOL=ON ../
```

But if we are using this library to build a different library that needs to export its symbols on
Windows so that other applications may use it, you'd build this project passing options to
the `CMakeLists.txt` file of this library:

```bash
mkdir build
cd build
cmake -DWINDOWS_EXPORT_SYMBOLS:BOOL=ON -DMY_PROJECT_OPTIONS -DCMAKE_BUILD_TYPE=Release ../
```

And if, during the development of his library, we wish to create install scripts, we'd do:

```bash
mkdir build
cd build
cmake -DVITIMITI_COMPILER_BUILD_API_DOCS:BOOL=ON -DVITIMITI_COMPILER_INSTALL_LIBRARY:BOOL=ON ../
```

As this will allow us to also install the API documentation within the system.
