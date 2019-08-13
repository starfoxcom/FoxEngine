/**
* @file foxInputLayout.h
* @author --
* @date ---
* @brief Implementation of input layout.
*/
#pragma once

/**
* Includes
*/

namespace foxEngineSDK
{
  namespace FOXGI_FORMAT
  {
    enum E
    {
      K_UNKNOWN = 0,
      
      K_R32G32B32A32_FLOAT = 2,
      K_R32G32B32A32_UINT = 3,

      K_R32G32B32_FLOAT = 6,
      K_R32G32B32_UINT = 7,

      K_R16G16B16A16_FLOAT = 10,
      K_R16G16B16A16_UINT = 12,

      K_R32G32_FLOAT = 16,
      K_R32G32_UINT = 17,

      //K_R8G8B8A8_FLOAT,
      K_R8G8B8A8_UNORM = 28,

      K_R16G16_FLOAT = 34,
      K_R16G16_UINT = 36,

      K_R8G8_UINT = 50,

      K_R16_UINT = 57,

      K_R8_UINT = 62,

      K_R32_UINT = 42,

      K_D24_UNORM_S8_UINT = 45
    };
  }

  namespace FOX_INPUT_CLASSIFICATION
  {
    enum E
    {
      K_INPUT_PER_VERTEX_DATA = 0,
      K_INPUT_PER_INSTANCE_DATA = 1
    };
  }

  namespace FOX_PRIMITIVE_TOPOLOGY
  {
    enum E
    {
      K_PRIMITIVE_TOPOLOGY_UNDEFINDED = 0,
      K_PRIMITIVE_TOPOLOGY_TRIANGLELIST = 4
    };
  }

  namespace FOX_BIND_FLAG
  {
    enum E
    {
      K_BIND_VERTEX_BUFFER = 1,
      K_BIND_INDEX_BUFFER = 2,
      K_BIND_CONSTANT_BUFFER = 4,
      K_BIND_SHADER_RESOURCE = 8,
      K_BIND_STREAM_OUTPUT = 16,
      K_BIND_RENDER_TARGET = 32,
      K_BIND_DEPTH_STENCIL = 64,
      K_BIND_UNORDERED_ACCESS = 128

    };
  }
}