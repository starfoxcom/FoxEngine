#include "foxDXDeviceContext.h"
#include "foxDXRenderTargetView.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"


namespace foxEngineSDK
{

  DXDeviceContext::DXDeviceContext()
  {
  }


  DXDeviceContext::~DXDeviceContext()
  {
  }

  ID3D11DeviceContext ** DXDeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }

  ID3D11DeviceContext * DXDeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
  void DXDeviceContext::clearRenderTargetView(
    DXRenderTargetView * _renderTargetView,
    float * _clearColor)
  {
    m_deviceContext->ClearRenderTargetView(
      _renderTargetView->getRenderTargetView(),
      _clearColor);
  }
  void DXDeviceContext::setInputLayout(DXInputLayout * _inputLayout)
  {

    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void DXDeviceContext::setIAVertexBuffers(
    DXVertexBuffer * _vertexBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    uint32 stride = sizeof(simpleVertex2);
    uint32 offset = 0;

    m_deviceContext->IASetVertexBuffers(
      _startSlot,
      _numOfBuffers,
      _vertexBuffer->getBufferRef(),
      &stride,
      &offset);
  }
  void DXDeviceContext::setIAIndexBuffers(
    DXIndexBuffer * _indexBuffer,
    FOXGI_FORMAT::E _format,
    uint32 _offset)
  {
    m_deviceContext->IASetIndexBuffer(
      _indexBuffer->getBuffer(),
      static_cast<DXGI_FORMAT>(_format),
      _offset);
  }
  void DXDeviceContext::setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_topology));
  }
  void DXDeviceContext::setVertexShader(DXVertexShader * _vertexShader)
  {
    m_deviceContext->VSSetShader(_vertexShader->getVertexShader(), NULL, 0);
  }
  void DXDeviceContext::setPixelShader(DXPixelShader * _pixelShader)
  {
    m_deviceContext->PSSetShader(_pixelShader->getPixelShader(), NULL, 0);
  }
  void DXDeviceContext::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->Draw(_vertexCount, _vertexStart);
  }
}
