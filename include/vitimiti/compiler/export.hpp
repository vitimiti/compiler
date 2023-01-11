//================================================================================================//
// The MIT License (MIT)
//
// Copyright (c) 2023 Victor Matia <vmatir@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//================================================================================================//

#ifndef VITIMITI_COMPILER_EXPORT_HPP
#define VITIMITI_COMPILER_EXPORT_HPP

/// \file export.hpp
/// \brief Preprocessor exporting.
///
/// Allow exporting or hiding APIs.

/// \def VITIMITI_API_EXPORT
/// \brief Export an API object.
/// \remarks On Windows, this macro actually hides the object if \code
/// WINDOWS_EXPORT_SYMBOLS \endcode is undefined.
/// \see VITIMITI_API_IMPORT
///
/// Export the API object marked by this macro in MSVC, GCC, Clang and MinGW,
/// depending on the OS. In any other compiler cases, these macros are defined
/// to nothing and don't mark the API for export.

/// \def VITIMITI_API_IMPORT
/// \brief Hide an API object.
/// \see VITIMITI_API_EXPORT
///
/// Hide the API object marked by this macro in MSVC, GCC, Clang and MinGW,
/// depending on the OS. In any other compiler cases, these macros are defined
/// to nothing and don't mark the API for import.

#if defined _WIN32 || defined __CYGWIN__
#  ifdef WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define VITIMITI_API_EXPORT __attribute__((dllexport))
#      define VITIMITI_API_IMPORT __attribute__((dllimport))
#    else // __GNUC__
#      define VITIMITI_API_EXPORT __declspec(dllexport)
#      define VITIMITI_API_IMPORT __declspec(dllimport)
#    endif // __GNUC__
#  else    // WINDOWS_EXPORT_SYMBOLS
#    ifdef __GNUC__
#      define VITIMITI_API_EXPORT __attribute__((dllimport))
#      define VITIMITI_API_IMPORT __attribute__((dllimport))
#    else // __GNUC__
#      define VITIMITI_API_EXPORT __declspec(dllimport)
#      define VITIMITI_API_IMPORT __declspec(dllimport)
#    endif // __GNUC__
#  endif   // WINDOWS_EXPORT_SYMBOLS
#  define VITIMIT_API_EXPORT
#  define VITIMITI_API_IMPORT
#else // _WIN32 || __CYGWIN__
#  if __GNUC__ >= 4
#    define VITIMITI_API_EXPORT __attribute__((visibility("default")))
#    define VITIMITI_API_IMPORT __attribute__((visibility("hidden")))
#  else // __GNUC__ >= 4
#    define VITIMITI_API_EXPORT
#    define VITIMITI_API_IMPORT
#  endif // __GNUC__ >= 4
#endif   // _WIN32 || __CYGWIN__

#endif // VITIMITI_COMPILER_EXPORT_HPP