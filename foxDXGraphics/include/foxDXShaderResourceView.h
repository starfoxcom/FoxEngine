#pragma once
/**
 * @file DXShaderResourceView.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/26
 * @brief Graphics API Shader Resource View for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class DXShaderResourceView
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXShaderResourceView();

    /**
     * @brief Default destructor.
     */
    ~DXShaderResourceView();

    /**
     * @brief Gets the DirectX Shader Resource View.
     */
    ID3D11ShaderResourceView * getShaderResourceView();

    /**
     * @brief Gets the DirectX Shader Resource View reference.
     */
    ID3D11ShaderResourceView ** getShaderResourceViewRef();

  private:

    ID3D11ShaderResourceView * m_shaderResourceView; /**< Shader Resource View class member object.*/

  };
}