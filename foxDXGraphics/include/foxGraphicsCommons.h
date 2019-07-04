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
  namespace FXGI_FORMAT
  {
    enum E
    {
      K_UNKNOWN = 0,
      
      K_R32G32B32A32_FLOAT,
      K_R32G32B32A32_UINT,

      K_R32G32B32_FLOAT,
      K_R32G32B32_UINT,

      K_R16G16B16A16_FLOAT,
      K_R16G16B16A16_UINT,

      K_R32G32_FLOAT,
      K_R32G32_UINT,

      K_R8G8B8A8_FLOAT,
      K_R8G8B8A8_UNORM,

      K_R16G16_FLOAT,
      K_R16G16_UINT,

      K_R8G8_UINT,

      K_R8_UINT,

      K_R32_UINT,

      K_D24_UNORM_S8_UINT
    };
  }

  namespace FX_INPUT_CLASSIFICATION
  {
    enum E
    {
      K_INPUT_PER_VERTEX_DATA = 0,
      K_INPUT_PER_INSTANCE_DATA
    };
  }
}