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
#include "foxDXShader.h"

namespace foxEngineSDK
{

  class DXPixelShader : public DXShader
  {
  public:
    DXPixelShader();
    ~DXPixelShader();

    ID3D11PixelShader ** getPixelShaderRef();

    ID3D11PixelShader * getPixelShader();

  private:

    ID3D11PixelShader * m_pixelShader;
  };
}
