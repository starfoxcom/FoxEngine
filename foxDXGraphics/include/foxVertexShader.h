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

#include "foxGraphicsDefines.h"

#include "foxShader.h"

namespace foxEngineSDK
{

  class VertexShader : public Shader
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
