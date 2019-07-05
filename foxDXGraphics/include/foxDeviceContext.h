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

/**
* Libs
*/

namespace foxEngineSDK
{

  class InputLayout;

  class DeviceContext
  {
  public:
    DeviceContext();
    ~DeviceContext();

    ID3D11DeviceContext ** getDeviceContextRef();

    ID3D11DeviceContext * getDeviceContext();

    void setInputLayout(InputLayout * _inputLayout);

  private:
    ID3D11DeviceContext * m_deviceContext;
  };
}

