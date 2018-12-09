/**
* @file foxGraphicsDefines.h
* @author ---
* @date ---
* @brief Some definitions to describe the dll export and import.
*
* This definitions are meant to describe the dll export and import.
*/

#pragma once

/**
* Library export specifics
*/
#if FOX_PLATFORM == FOX_PLATFORM_WIN32
#   if FOX_COMPILER == FOX_COMPILER_MSVC
#     if defined(FOX_STATIC_LIB)
#       define FOX_UTILITY_EXPORT
#     else
#       if defined(FOX_GRAPHICS_EXPORTS)
#         define FOX_GRAPHICS_EXPORT __declspec(dllexport)
#       else
#         define FOX_GRAPHICS_EXPORT __declspec(dllimport)
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