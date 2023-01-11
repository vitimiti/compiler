# ==================================================================================================
# The MIT License (MIT)
#
# Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# ==================================================================================================

cmake_minimum_required(VERSION 3.20)

option(VITIMITI_COMPILER_BUILD_API_DOCS
       "Whether to build the API documentation or not" OFF)

option(VITIMITI_COMPILER_INSTALL_LIBRARY
       "Whether to install the library or not" OFF)

option(WINDOWS_EXPORT_SYMBOLS "Whether to export symbols on Windows or not" OFF)

project(
  VITIMITI_COMPILER
  VERSION 1.0.0
  DESCRIPTION "Common preprocessor definitions"
  HOMEPAGE_URL "https://github.com/vitimiti/compiler"
  LANGUAGES C CXX)

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(
  ${PROJECT_NAME} INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDE_DIRS}>)

if(WIN32 AND WINDOWS_EXPORT_SYMBOLS)
  add_compile_definitions(WINDOWS_EXPORT_SYMBOLS)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

if(VITIMITI_COMPILER_BUILD_API_DOCS)
  add_subdirectory(docs)
endif()

if(VITIMITI_COMPILER_INSTALL_LIBRARY)
  include(GNUInstallDirs)
  message(TRACE
          "Configuring installation system with prefix ${CMAKE_INSTALL_PREFIX}")

  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
    "compiler-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)

  configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/compiler-config.cmake.in"
    "${PROJECT_BINARY_DIR}/compiler-config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vitimiti)

  install(
    TARGETS ${PROJECT_NAME}
    EXPORT VITIMITI_COMPILER_TARGETS
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_LIBDIR})

  install(
    EXPORT VITIMITI_COMPILER_TARGETS
    FILE compiler-targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vitimiti)

  install(FILES "${PROJECT_BINARY_DIR}/compiler-config.cmake"
                "${PROJECT_BINARY_DIR}/compiler-config-version.cmake"
          DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/vitimiti)

  install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/vitimiti/compiler
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/vitimiti)

  include(CPack)
  if(WIN32)
    set(CPACK_PACKAGE_NAME VitimitiCompiler)
    set(CPACK_PACKAGE_FILE_NAME VitimitiCompiler-${PROJECT_VERSION})
  else()
    set(CPACK_PACKAGE_NAME vitimiti-compiler)
    set(CPACK_PACKAGE_FILE_NAME vitimiti-compiler-${PROJECT_VERSION})
  endif()

  set(CPACK_PACKAGE_DIRECTORY ${CMAKE_BINARY_DIR}/packages)
  set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
  set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
  set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
  set(CPACK_PACKAGE_DESCRIPTION ${PROJECT_DESCRIPTION})
  set(CPACK_PACKAGE_HOMEPAGE_URL ${PROJECT_HOMEPAGE_URL})
  set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE.md")
  set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/LICENSE.md")
endif()
