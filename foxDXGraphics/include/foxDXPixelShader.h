#pragma once
/**
 * @file foxDXPixelShader.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/09
 * @brief Graphics API Pixel Shader Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxDXShader.h"

namespace foxEngineSDK
{

  class DXPixelShader : public DXShader
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXPixelShader();

    /**
     * @brief Default destructor.
     */
    ~DXPixelShader();

    /**
     * @brief Gets the DirectX Pixel Shader.
     */
    ID3D11PixelShader * getPixelShader();

    /**
     * @brief Gets the DirectX Pixel Shader reference.
     */
    ID3D11PixelShader ** getPixelShaderRef();

  private:

    ID3D11PixelShader * m_pixelShader;
  };
}