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

  class DXDepthStencilView
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXDepthStencilView();

    /**
     * @brief Default destructor.
     */
    ~DXDepthStencilView();

    /**
     * @brief Gets the DirectX Depth Stencil View.
    */
    ID3D11DepthStencilView * getDepthStencilView();

    /**
     * @brief Gets the DirectX Depth Stencil View reference.
     */
    ID3D11DepthStencilView ** getDepthStencilViewRef();

  private:

    ID3D11DepthStencilView * m_depthStencilView; /**< Depth Stencil View class object member.*/
  };
}