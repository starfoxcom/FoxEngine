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
  class DXDevice
  {
  public:

    //Default constructor
    DXDevice();

    //Default destructor
    ~DXDevice();

    //Get the DirectX Device
    ID3D11Device * getDevice();

    //Get the DirectX Device reference
    ID3D11Device ** getDeviceRef();

  private:

    ID3D11Device * m_device; /**< Device class object member*/
  };
}