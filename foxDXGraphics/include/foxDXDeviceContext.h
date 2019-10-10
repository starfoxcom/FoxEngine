#pragma once
/**
 * @file foxDXDeviceContext.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Device Context Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  /**
   * Forward declarations
   */
  class DXRenderTargetView;
  class DXDepthStencilView;
  class DXInputLayout;

  class DXDeviceContext
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXDeviceContext();

    /**
     * @brief DEfault destructor.
     */
    ~DXDeviceContext();

    /**
     * @brief Gets the DirectX Device Context.
     */
    ID3D11DeviceContext * getDeviceContext();

    /**
     * @brief Gets the DirectX Device Context reference.
     */
    ID3D11DeviceContext ** getDeviceContextRef();

    /**
     * @brief Clears the DirectX Render Target View.
     * @param _renderTargetView The Graphics API Render Target View.
     * @param _RGBAColor The color to clear with.
     */
    void clearRenderTargetView(DXRenderTargetView * _renderTargetView, float * _RGBAColor);

    /**
     * @brief Clears the DirectX Depth Stencil View.
     * @param _depthStencilView The Graphics API Depth Stencil View.
     */
    void clearDepthStencilView(DXDepthStencilView * _depthStencilView);

    /**
     * @brief Sets the DirectX Input Layout.
     * @param _inputLayout The Graphics API Input Layout.
     */
    void setInputLayout(DXInputLayout * _inputLayout);

  private:

    ID3D11DeviceContext * m_deviceContext; /**< Device Context class object member.*/
  };
}