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
#include "foxPlatformTypes.h"

/**
 * Libs
 */

namespace foxEngineSDK
{

  class DXVertexShader;
  class DXInputLayout;
  class DXPixelShader;
  class DXVertexBuffer;
  class DXIndexBuffer;

  class DXDevice
  {
  public:
    DXDevice();
    ~DXDevice();

    ID3D11Device ** getDeviceRef();

    ID3D11Device * getDevice();

    bool createVertexShader(DXVertexShader * _vertexShader);

    bool createInputLayout(DXInputLayout * _inputLayout, DXVertexShader * _vertexShader);

    bool createPixelShader(DXPixelShader * _pixelShader);

    bool createVertexBuffer(DXVertexBuffer * _vertexBuffer);

    bool createIndexBuffer(DXIndexBuffer * _indexBuffer);


  private:
    ID3D11Device * m_device;
  };
}

