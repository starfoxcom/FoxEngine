#pragma once
/**
 * @file foxDXRasterizerState.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/21
 * @brief Graphics API Rasterizer State Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class DXRasterizerState
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXRasterizerState();

    /**
     * @brief Default destructor.
     */
    ~DXRasterizerState();

    /**
     * @brief Gets the DirectX Rasterizer State.
     */
    ID3D11RasterizerState * getRasterizerState();

    /**
     * @brief Gets the DirectX Rasterizer State reference.
     */
    ID3D11RasterizerState ** getRasterizerStateRef();

    /**
     * @brief Gets the DirectX Rasterizer State Desc.
     */
    D3D11_RASTERIZER_DESC getRasterizerStateDesc();

    protected:

    ID3D11RasterizerState * m_rasterizerState; /**< Rasterizer state class object member.*/

    D3D11_RASTERIZER_DESC m_rasterizerDesc; /**< Rasterizer descriptor class object member.*/

  };

}