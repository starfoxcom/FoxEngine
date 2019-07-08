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
#include "foxPrerequisitesUtilities.h"
#include "foxGraphicsCommons.h"

/**
* Libs
*/

namespace foxEngineSDK
{

  class RenderTargetView;
  class InputLayout;
  class VertexBuffer;
  class VertexShader;
  class PixelShader;

  class DeviceContext
  {
  public:
    DeviceContext();
    ~DeviceContext();

    ID3D11DeviceContext ** getDeviceContextRef();

    ID3D11DeviceContext * getDeviceContext();

    void clearRenderTargetView(RenderTargetView* _renderTargetView, float * _clearColor);

    void setInputLayout(InputLayout * _inputLayout);

    void setIAVertexBuffers(
      VertexBuffer * _vertexBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers);

    void setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology);

    void setVertexShader(VertexShader * _vertexShader);

    void setPixelShader(PixelShader * _pixelShader);

    void draw(uint32 _vertexCount, uint32 _vertexStart);

  private:
    ID3D11DeviceContext * m_deviceContext;
  };
}

