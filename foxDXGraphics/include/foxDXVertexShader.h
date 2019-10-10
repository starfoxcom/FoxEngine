#pragma once
/**
 * @file foxDXVertexShader.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/09
 * @brief Graphics API Vertex Shader Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxDXShader.h"

namespace foxEngineSDK
{

  class DXVertexShader : public DXShader
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXVertexShader();

    /**
     * @brief Default destructor.
     */
    ~DXVertexShader();

    /**
     * @brief Gets the DirectX Vertex Shader.
     */
    ID3D11VertexShader * getVertexShader();

    /**
     * @brief Gets the DirectX Vertex Shader reference.
     */
    ID3D11VertexShader ** getVertexShaderRef();
  
  private:

    ID3D11VertexShader * m_vertexShader;
  };
}