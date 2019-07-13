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

  class DXRenderTargetView;
  class DXInputLayout;
  class DXVertexBuffer;
  class DXIndexBuffer;
  class DXVertexShader;
  class DXPixelShader;

  class DXDeviceContext
  {
  public:
    DXDeviceContext();
    ~DXDeviceContext();

    ID3D11DeviceContext ** getDeviceContextRef();

    ID3D11DeviceContext * getDeviceContext();

    void clearRenderTargetView(DXRenderTargetView* _renderTargetView, float * _clearColor);

    void setInputLayout(DXInputLayout * _inputLayout);

    void setIAVertexBuffers(
      DXVertexBuffer * _vertexBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers);

    void setIAIndexBuffers(
      DXIndexBuffer * _indexBuffer,
      FOXGI_FORMAT::E _format,
      uint32 _offset);

    void setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology);

    void setVertexShader(DXVertexShader * _vertexShader);

    void setPixelShader(DXPixelShader * _pixelShader);

    void draw(uint32 _vertexCount, uint32 _vertexStart);

  private:
    ID3D11DeviceContext * m_deviceContext;
  };
}

