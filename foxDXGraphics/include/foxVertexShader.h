/**
* @file foxVertexShader.h
* @author --
* @date ---
* @brief Implementation of vertex shader
*/

#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxGraphicsDefines.h"

namespace foxEngineSDK
{

  class FOX_GRAPHICS_EXPORT VertexShader
  {
  public:
    VertexShader();
    ~VertexShader();

    ID3D11VertexShader ** getVertexShaderRef();

    ID3D11VertexShader * getVertexShader();

  private:

    ID3D11VertexShader * m_vertexShader;
  };
}
