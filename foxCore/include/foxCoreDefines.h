/**
 * @file foxCoreDefines.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/11/22
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
#       define FOX_CORE_EXPORT
#     else
#       if defined(FOX_CORE_EXPORTS)
#         define FOX_CORE_EXPORT __declspec(dllexport)
#       else
#         define FOX_CORE_EXPORT __declspec(dllimport)
#       endif
#     endif
#   else                                    //Any other compiler
#     if defined(FOX_STATIC_LIB)
#       define FOX_CORE_EXPORT
#     else
#       if defined(FOX_CORE_EXPORTS)
#         define FOX_CORE_EXPORT __attribute__((dllexport))
#       else
#         define FOX_CORE_EXPORT __attribute__((dllimport))
#       endif
#     endif
#   endif
#define FOX_CORE_HIDDEN
#else                                       //Linux/Mac settings
#   define FOX_CORE_EXPORT __attribute__((visibility("default")))
#   define FOX_CORE_HIDDEN __attribute__((visibility("hidden")))
#endif