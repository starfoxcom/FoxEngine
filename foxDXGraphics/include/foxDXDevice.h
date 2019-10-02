#pragma once
/**
 * @file foxDXDevice.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Device Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>


namespace foxEngineSDK
{

  /**
   * Forward Declarations
   */


  class DXDevice
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXDevice();

    /**
     * @brief Default destructor.
     */
    ~DXDevice();

    /**
     * @brief Gets the DirectX Device.
     * @return The DirectX Device.
     */
    ID3D11Device * getDevice();

    /**
     * @brief Gets the DirectX Device reference.
     * @return The DirectX Device reference.
     */
    ID3D11Device ** getDeviceRef();

    /**
     * @brief Create the DirectX Render Target View.
     * @param _backBuffer The Back Buffer.
     * @param _renderTargetViewRef The Render Target View reference.
     * @return true on success.
     */
    bool createRenderTargetView(
      ID3D11Texture2D * _backBuffer,
      ID3D11RenderTargetView ** _renderTargetViewRef);

  private:

    ID3D11Device * m_device; /**< Device class object member.*/
  };
}