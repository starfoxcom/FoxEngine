#include "foxDeviceContext.h"
#include "foxRenderTargetView.h"
#include "foxInputLayout.h"
#include "foxVertexBuffer.h"
#include "foxVertexShader.h"
#include "foxPixelShader.h"


namespace foxEngineSDK
{

  DeviceContext::DeviceContext()
  {
  }


  DeviceContext::~DeviceContext()
  {
  }

  ID3D11DeviceContext ** DeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }

  ID3D11DeviceContext * DeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
  void DeviceContext::clearRenderTargetView(
    RenderTargetView * _renderTargetView,
    float * _clearColor)
  {
    m_deviceContext->ClearRenderTargetView(
      _renderTargetView->getRenderTargetView(),
      _clearColor);
  }
  void DeviceContext::setInputLayout(InputLayout * _inputLayout)
  {

    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void DeviceContext::setIAVertexBuffers(
    VertexBuffer * _vertexBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    uint32 stride = sizeof(simpleVertex);
    uint32 offset = 0;

    m_deviceContext->IASetVertexBuffers(
      _startSlot,
      _numOfBuffers,
      _vertexBuffer->getVertexBufferRef(),
      &stride,
      &offset);
  }
  void DeviceContext::setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_topology));
  }
  void DeviceContext::setVertexShader(VertexShader * _vertexShader)
  {
    m_deviceContext->VSSetShader(_vertexShader->getVertexShader(), NULL, 0);
  }
  void DeviceContext::setPixelShader(PixelShader * _pixelShader)
  {
    m_deviceContext->PSSetShader(_pixelShader->getPixelShader(), NULL, 0);
  }
  void DeviceContext::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->Draw(_vertexCount, _vertexStart);
  }
}
