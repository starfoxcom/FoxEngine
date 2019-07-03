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

namespace foxEngineSDK
{

  class PixelShader
  {
  public:
    PixelShader();
    ~PixelShader();

    ID3D11PixelShader ** getPixelShaderRef();

    ID3D11PixelShader * getPixelShader();

    ID3DBlob * getPSBlop();

  private:

    ID3D11PixelShader * m_pixelShader;

    ID3DBlob* m_PSBlob;
  };
}