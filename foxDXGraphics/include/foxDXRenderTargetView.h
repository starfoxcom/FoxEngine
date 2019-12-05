#pragma once
/**
 * @file foxDXRenderTargetView.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief GRaphics API Render Target View class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  class foxDXRenderTargetView
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXRenderTargetView();

    /**
     * @brief Default destructor.
     */
    ~foxDXRenderTargetView();

    /**
     * @brief Gets the DirectX Render Target View.
     */
    ID3D11RenderTargetView * getRenderTargetView();

    /**
     * @brief Gets the DirectX Render Target View Reference.
     */
    ID3D11RenderTargetView ** getRenderTargetViewRef();

  private:

    ID3D11RenderTargetView *  m_renderTargetView = nullptr; /**< Render Target View class object member.*/

  };
}