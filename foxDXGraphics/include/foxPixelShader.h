/**
* @file foxPixelShader.h
* @author --
* @date ---
* @brief Implementation of render pixel shader
*/

#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxGraphicsDefines.h"
#include "foxShader.h"

namespace foxEngineSDK
{

  class PixelShader : public Shader
  {
  public:
    PixelShader();
    ~PixelShader();

    ID3D11PixelShader ** getPixelShaderRef();

    ID3D11PixelShader * getPixelShader();

  private:

    ID3D11PixelShader * m_pixelShader;
  };
}
