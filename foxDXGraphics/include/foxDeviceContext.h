/**
* @file foxDeviceContext.h
* @author --
* @date ---
* @brief Implementation of device context.
*/
#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxGraphicsDefines.h"

/**
* Libs
*/

namespace foxEngineSDK
{

  class FOX_GRAPHICS_EXPORT DeviceContext
  {
  public:
    DeviceContext();
    ~DeviceContext();

    ID3D11DeviceContext ** getDEviceContextRef();

    ID3D11DeviceContext * getDeviceContext();

  private:
    ID3D11DeviceContext * m_deviceContext;
  };
}

