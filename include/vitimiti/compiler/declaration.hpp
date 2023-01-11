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

#ifndef VITIMITI_COMPILER_DECLARATION_HPP
#define VITIMITI_COMPILER_DECLARATION_HPP

/// \file declaration.hpp
/// \brief Declare methods with compiler extensions.
///
/// Allow the use of compiler extensions for MSVC in a cross-compiler way.

/// \def VITIMITI_DECLARATION_C_DECL
/// \brief Mark a function as a C declaration on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_CLR_CALL
/// \see VITIMITI_DECLARATION_STD_CALL
/// \see VITIMITI_DECLARATION_FAST_CALL
/// \see VITIMITI_DECLARATION_THIS_CALL
/// \see VITIMITI_DECLARATION_VECTOR_CALL

/// \def VITIMITI_DECLARATION_CLR_CALL
/// \brief Mark a function as a CLR call on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_C_DECL
/// \see VITIMITI_DECLARATION_STD_CALL
/// \see VITIMITI_DECLARATION_FAST_CALL
/// \see VITIMITI_DECLARATION_THIS_CALL
/// \see VITIMITI_DECLARATION_VECTOR_CALL

/// \def VITIMITI_DECLARATION_STD_CALL
/// \brief Mark a function as a standard call on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_C_DECL
/// \see VITIMITI_DECLARATION_CLR_CALL
/// \see VITIMITI_DECLARATION_FAST_CALL
/// \see VITIMITI_DECLARATION_THIS_CALL
/// \see VITIMITI_DECLARATION_VECTOR_CALL

/// \def VITIMITI_DECLARATION_FAST_CALL
/// \brief Mark a function as a fast call on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_C_DECL
/// \see VITIMITI_DECLARATION_CLR_CALL
/// \see VITIMITI_DECLARATION_STD_CALL
/// \see VITIMITI_DECLARATION_THIS_CALL
/// \see VITIMITI_DECLARATION_VECTOR_CALL

/// \def VITIMITI_DECLARATION_THIS_CALL
/// \brief Mark a function as a call to self on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_C_DECL
/// \see VITIMITI_DECLARATION_CLR_CALL
/// \see VITIMITI_DECLARATION_STD_CALL
/// \see VITIMITI_DECLARATION_FAST_CALL
/// \see VITIMITI_DECLARATION_VECTOR_CALL

/// \def VITIMITI_DECLARATION_VECTOR_CALL
/// \brief Mark a function as a vector call on Windows systems.
/// \remarks This macro is defined to nothing outside of Windows.
/// \see VITIMITI_DECLARATION_C_DECL
/// \see VITIMITI_DECLARATION_CLR_CALL
/// \see VITIMITI_DECLARATION_STD_CALL
/// \see VITIMITI_DECLARATION_FAST_CALL
/// \see VITIMITI_DECLARATION_THIS_CALL

#if defined _WIN32 || defined __CYGWIN__
#  define VITIMITI_DECLARATION_C_DECL      __cdecl
#  define VITIMITI_DECLARATION_CLR_CALL    __clrcall
#  define VITIMITI_DECLARATION_STD_CALL    __stdcall
#  define VITIMITI_DECLARATION_FAST_CALL   __fastcall
#  define VITIMITI_DECLARATION_THIS_CALL   __thiscall
#  define VITIMITI_DECLARATION_VECTOR_CALL __vectorcall
#else // _WIN32 || __CYGWIN__
#  define VITIMITI_DECLARATION_C_DECL
#  define VITIMITI_DECLARATION_CLR_CALL
#  define VITIMITI_DECLARATION_STD_CALL
#  define VITIMITI_DECLARATION_FAST_CALL
#  define VITIMITI_DECLARATION_THIS_CALL
#  define VITIMITI_DECLARATION_VECTOR_CALL
#endif // _WIN32 || __CYGWIN__

#endif // VITIMITI_COMPILER_DECLARATION_HPP