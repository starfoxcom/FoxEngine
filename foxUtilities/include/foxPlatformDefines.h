/**
 * @file foxPlatformDefines.h
 * @author ---
 * @date ---
 * @brief Some definitions to describe the target platform
 *
 * This definitions are meant to describe the target platform
 */

#pragma once

/**
 * Initial platform/compiler-related stuff to set.
 */
#define FOX_PLATFORM_WIN32      1       //Windows Platform
#define FOX_PLATFORM_LINUX      2       //Linux Platform
#define FOX_PLATFORM_OSX        3       //Apple Platform
#define FOX_PLATFORM_IOS        4       //iPhone Platform
#define FOX_PLATFORM_ANDROID    5       //Android Platform
#define FOX_PLATFORM_PS4        6       //PlayStation 4 Platform

#define FOX_COMPILER_MSVC       1       //Visual Studio Compiler
#define FOX_COMPILER_GNUC       2       //GCC Compiler
#define FOX_COMPILER_INTEL      3       //Intel Compiler
#define FOX_COMPILER_CLANG      4       //Clang Compiler

#define FOX_ARCHITECTURE_x86_32 1       //Intel x86 32 Bits
#define FOX_ARCHITECTURE_x86_64 2       //Intel x86 64 Bits

#define FOX_ENDIAN_LITTLE       1       //Little Endian
#define FOX_ENDIAN_BIG          2       //Big Endian

//Define actual endian type (little endian for Windows, Linux, Apple & PS4)
#define FOX_ENDIAN FOX_ENDIAN_LITTLE

/**
 * Compiler type and version.
 */
#if defined(__clang__)
#   define FOX_COMPILER FOX_COMPILER_CLANG
#   define FOX_COMP_VER __clang_version__
#   define FOX_THREADLOCAL __thread
#   define FOX_STDCALL __attribute__((stdcall))
#   define FOX_CDECL __attribute__((cdecl))
#   define FOX_FALLTHROUGH [[clang::fallthrough]];
#elif defined(__GNUC__) //Check after Clang, as Clang defines this too
#   define FOX_COMPILER FOX_COMPILER_GNUC
#   define FOX_COMP_VER (((__GNUC__) * 100) + (__GNUC_MINOR__ * 10) + __GNUC_PATCHLEVEL__)
#   define FOX_THREADLOCAL __thread
#   define FOX_STDCALL __attribute__((stdcall))
#   define FOX_CDECL __attribute__((cdecl))
#   define FOX_FALLTHROUGH __attribute__((fallthrough));
#elif defined(__INTEL_COMPILER)
#   define FOX_COMPILER FOX_COMPILER_INTEL
#   define FOX_COMP_VER __INTEL_COMPILER
#   define FOX_STDCALL __stdcall
#   define FOX_CDECL __cdecl
#   define FOX_FALLTHROUGH

/**
 * FOX_THREADLOCAL define is down below because Intel compiler defines it
 * differently based on platform
 */

//Check after Clang & Intel, we could be building with either with VS
#elif defined(_MSC_VER)
#   define FOX_COMPILER FOX_COMPILER_MSVC
#   define FOX_COMP_VER _MSC_VER
#   define FOX_THREADLOCAL __declspec(thread)
#   define FOX_STDCALL __stdcall
#   define FOX_CDECL __cdecl
#   define FOX_FALLTHROUGH
#   undef  __PRETTY_FUNCTION__
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
//No know compiler found, send the error to the output (if any)
#   pragma error "No known compiler. "

#endif

/**
 * See if we can user __forceinline or if we need to user __inline instead.
 */
#if FOX_COMPILER == FOX_COMPILER_MSVC       //If we are compiling on Visual Studio
#   if FOX_COMP_VER >= 1200                 //If we are on Visual Studio 6 or higher
#     define FORCEINLINE __forceinline      //Set __forceinline
#     ifndef RESTRICT
#       define RESTRICT __restrict          //No alias hint
#     endif
#   endif
#elif defined(__MINGW32__)                  //If we are on a Unix type system
#   if !defined(FORCEINLINE)
#     define FORCEINLINE __inline           //Set __inline
#     ifndef RESTRICT
#       define RESTRICT                     //No alias hint
#     endif
#   endif
#else
#   define FORCEINLINE __inline             //Any other compiler
#   ifndef RESTRICT
#     define RESTRICT __restrict            //No alias hint
#   endif
#endif

/**
 * Find the current platform
 */
#if defined(__WIN32__) || defined(_WIN32)   //If it's a Windows platform
#   define FOX_PLATFORM FOX_PLATFORM_WIN32
#elif defined(__APPLE_CC__)                 //If it's an Apple platform
#   define FOX_PLATFORM FOX_PLATFORM_OSX
#elif defined(__ORBIS__)                    //If it's a PlayStation 4
#   define FOX_PLATFORM FOX_PLATFORM_PS4
#else                                       //Will consider it as a Linux platform
#   define FOX_PLATFORM FOX_PLATFORM_LINUX
#endif

/**
 * Find the architecture type
 */
#if defined(__x86_64__) || defined(_M_X64)  //If this is a x64 compile
#   define FOX_ARCH_TYPE FOX_ARCHITECTURE_x86_64
#else                                       //If it's a x86 compile
#   define FOX_ARCH_TYPE FOX_ARCHITECTURE_x86_32
#endif
/**
 * Memory Alignment macros
 */
#if FOX_COMPILER == FOX_COMPILER_MSVC       //If we are compiling on Visual Studio
#   define MS_ALIGN(n) __declspec(align(n))
#   ifndef GCC_PACK
#     define GCC_PACK(n)
#   endif
#   ifndef GCC_ALIGN
#     define GCC_ALIGN(n)
#   endif
#elif (FOX_COMPILER == FOX_COMPILER_GNUC && FOX_PLATFORM == FOX_PLATFORM_PS4)
#   define MS_ALIGN(n)
#   define GCC_PACK(n)
#   define GCC_ALIGN(n) __attribute__((__aligned__(n)))
#else                                       //If we are on Unix type system
#   define MS_ALIGN(n)
#   define GCC_PACK(n) __attribute__((packed,aligned(n)))
#   define GCC_ALIGN(n) __attribute__((aligned(n)))
#endif

/**
 * For throw override (deprecated on c++11 but Visual Studio does not have handle noexcept
 */
#if FOX_COMPILER == FOX_COMPILER_MSVC
#   define _NOEXCEPT noexcept
#elif FOX_COMPILER == FOX_COMPILER_INTEL
#   define _NOEXCEPT noexcept
#elif FOX_COMPILER == FOX_COMPILER_GNUC
#   define _NOEXCEPT noexcept
#else
#   define _NOEXCEPT
#endif

/**
 * Library export specifics
 */
#if FOX_PLATFORM == FOX_PLATFORM_WIN32
#   if FOX_COMPILER == FOX_COMPILER_MSVC
#     if defined(FOX_STATIC_LIB)
#       define FOX_UTILITY_EXPORT
#     else
#       if defined(FOX_UTILITY_EXPORTS)
#         define FOX_UTILITY_EXPORT __declspec(dllexport)
#       else
#         define FOX_UTILITY_EXPORT __declspec(dllimport)
#       endif
#     endif
#   else                                    //Any other compiler
#     if defined(FOX_STATIC_LIB)
#       define FOX_UTILITY_EXPORT
#     else
#       if defined(FOX_UTILITY_EXPORTS)
#         define FOX_UTILITY_EXPORT __attribute__((dllexport))
#       else
#         define FOX_UTILITY_EXPORT __attribute__((dllimport))
#       endif
#     endif
#   endif
#define FOX_UTILITY_HIDDEN
#else                                       //Linux/Mac settings
#   define FOX_UTILITY_EXPORT __attribute__((visibility("default")))
#   define FOX_UTILITY_HIDDEN __attribute__((visibility("hidden")))
#endif

//DLL export for plugins
#if FOX_PLATFORM == FOX_PLATFORM_WIN32
#   if FOX_COMPILER == FOX_COMPILER_MSVC
#     define FOX_PLUGIN_EXPORT __declspec(dllexport)
#   else
#     define FOX_PLUGIN_EXPORT __attribute__((dllexport))
#   endif
#define FOX_UTILITY_HIDDEN
#else                                       //Linux/Mac settings
#   define FOX_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

/**
 * Windows specific settings
 */
//Win32 compilers use _DEBUG for specifying debug builds. For MinGW, we set DEBUG
#if FOX_PLATFORM == FOX_PLATFORM_WIN32
#   if defined(_DEBUG) ||   defined (DEBUG)
#     define FOX_DEBUG_MODE 1               //Specifies that we are on a DEBUG build
#   else
#     define FOX_DEBUG_MODE 0               //We are not on a DEBUG build
#   endif
#   if FOX_COMPILER == FOX_COMPILER_INTEL
#     define FOX_THREADLOCAL __declspec(thread) //Set the local thread for the Intel compiler
#   endif
#endif                                      //FOX_PLATFORM == FOX_PLATFORM_WIN32

/**
 * Linux/Apple specific settings
 */
#if FOX_PLATFORM == FOX_PLATFORM_LINUX || FOX_PLATFORM == FOX_PLATFORM_OSX
#   define stricmp strcasecmp

//If we are on a DEBUG build
#   if defined(_DEBUG) ||   defined (DEBUG)
#     define FOX_DEBUG_MODE 1               //Specifies that we are on a DEBUG build
#   else
#     define FOX_DEBUG_MODE 0               //We are not on a DEBUG build
#   endif
#   if FOX_COMPILER == FOX_COMPILER_INTEL
#     define FOX_THREADLOCAL __thread       //Set the local thread for the Intel compiler
#   endif
#endif           //FOX_PLATFORM == FOX_PLATFORM_LINUX || FOX_PLATFORM == FOX_PLATFORM_OSX

/**
 * PS4 specific settings
 */
#if FOX_PLATFORM == FOX_PLATFORM_PS4
#   if defined(_DEBUG) ||   defined (DEBUG)
#     define FOX_DEBUG_MODE 1               //Specifies that we are on a DEBUG build
#   else
#     define FOX_DEBUG_MODE 0               //We are not on a DEBUG build
#   endif
#endif      //FOX_PLATFORM == FOX_PLATFORM_LINUX || FOX_PLATFORM == FOX_PLATFORM_OSX

/**
 * Definition of Debug macros
 */
#if FOX_DEBUG_MODE
#   define FOX_DEBUG_ONLY(x) x
#   define FOX_ASSERT(x) assert(x)
#else
#   define FOX_DEBUG_ONLY(x)
#   define FOX_ASSERT(x)
#endif

/**
 * Disable some compiler warnings
 */

//If we are compiling with Visual Studio
#if FOX_COMPILER == FOX_COMPILER_MSVC
    /**
     * TODO: This is not deactivated anywhere, therefore it applies to any file
     * that includes this header. Right now I don't have an easier way to apply
     * these warning globally so  I'm keeping it this way.
     */

    //Secure versions aren't multi platform, so we won't be using them
#   define _CRT_SECURE_NO_WARNINGS

    /**
     * Disable: "<type> needs to have DLL interface to be used by clients"
     * Happens on STL member variables which are not public therefore is ok
     */
#   pragma warning (disable: 4251)

    //Disable: 'X' Function call with parameters that may be unsafe
#   pragma warning (disable:4996)

    /**
     * Disable: decorated name length exceeded, name was truncated. Happens with
     * really long type names. Even fairly standard use of std::unordered_map
     * with custom parameters, meaning I can't really do much to avoid it.
     * It shouldn't effect execution but might cause problems if you compile
     * library with one compiler and use it in another.
     */
#   pragma warning (disable:4503)

#endif