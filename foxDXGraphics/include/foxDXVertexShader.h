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

#include "foxDXShader.h"

namespace foxEngineSDK
{

  class DXVertexShader : public DXShader
  {
  public:
    DXVertexShader();
    ~DXVertexShader();

    ID3D11VertexShader ** getVertexShaderRef();

    ID3D11VertexShader * getVertexShader();

  private:

    ID3D11VertexShader * m_vertexShader;
  };
}
