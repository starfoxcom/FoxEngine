/**
* @file foxDevice.h
* @author --
* @date ---
* @brief Implementation of device.
*/
#pragma once

/**
 * Includes
 */
#include <d3d11.h>

/**
 * Libs
 */

namespace foxEngineSDK
{

  class Device
  {
  public:
    Device();
    ~Device();

    ID3D11Device ** getDeviceRef();

    ID3D11Device * getDevice();

  private:
    ID3D11Device * m_device;
  };
}

