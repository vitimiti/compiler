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

find_package(Doxygen REQUIRED dot)

set(DOXYGEN_PROJECT_NAME "Vitimiti's Compiler")
set(DOXYGEN_PROJECT_NUMBER ${PROJECT_VERSION})
set(DOXYGEN_PROJECT_BRIEF ${PROJECT_DESCRIPTION})
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(DOXYGEN_CREATE_SUBDIRS YES)
set(DOXYGEN_FILE_PATTERNS *.hpp)
set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_SOURCE_BROWSER YES)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_GENERATE_LATEX YES)
set(DOXYGEN_GENERATE_RTF YES)
set(DOXYGEN_GENERATE_MAN YES)
set(DOXYGEN_GENERATE_XML YES)
set(DOXYGEN_GENERATE_DOCBOOK YES)
set(DOXYGEN_HAVE_DOT YES)
set(DOXYGEN_CALL_GRAPH YES)
set(DOXYGEN_CALLER_GRAPH YES)
set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE "${CMAKE_SOURCE_DIR}/README.md")

doxygen_add_docs(
  VITIMITI_COMPILER_API_DOCS "${CMAKE_SOURCE_DIR}/README.md"
  "${CMAKE_SOURCE_DIR}/include" ALL
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  COMMENT "Generate doxygen documentation")
