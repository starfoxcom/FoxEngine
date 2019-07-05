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

  class VertexShader;
  class InputLayout;
  class PixelShader;
  class VertexBuffer;

  class Device
  {
  public:
    Device();
    ~Device();

    ID3D11Device ** getDeviceRef();

    ID3D11Device * getDevice();

    bool createVertexShader(VertexShader * _vertexShader);

    bool createInputLayout(InputLayout * _inputLayout, VertexShader * _vertexShader);

    bool createPixelShader(PixelShader * _pixelShader);

    bool createVertexBuffer(
      VertexBuffer * _vertexBuffer,
      int32 _cpuAcces,
      int32 _miscFlag);

  private:
    ID3D11Device * m_device;
  };
}

