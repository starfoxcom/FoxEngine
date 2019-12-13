#pragma once
/**
 * @file foxDXDepthStencilView.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Depth Stencil View Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  class foxDXDepthStencilView
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXDepthStencilView();

    /**
     * @brief Default destructor.
     */
    ~foxDXDepthStencilView();

    /**
     * @brief Gets the DirectX Depth Stencil View.
    */
    ID3D11DepthStencilView * getDepthStencilView();

    /**
     * @brief Gets the DirectX Depth Stencil View reference.
     */
    ID3D11DepthStencilView ** getDepthStencilViewRef();

  private:

    ID3D11DepthStencilView * m_depthStencilView = nullptr; /**< Depth Stencil View class object member.*/
  };
}