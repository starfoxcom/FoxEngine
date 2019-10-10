/**
 * Includes
 */
#include "foxDXDeviceContext.h"
#include "foxDXRenderTargetView.h"
#include "foxDXDepthStencilView.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"

namespace foxEngineSDK
{

  DXDeviceContext::DXDeviceContext()
  {
  }

  DXDeviceContext::~DXDeviceContext()
  {
  }
  ID3D11DeviceContext * DXDeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
  ID3D11DeviceContext ** DXDeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }

  void DXDeviceContext::clearRenderTargetView(
    DXRenderTargetView * _renderTargetView,
    float * _RGBAColor)
  {
    m_deviceContext->ClearRenderTargetView(
      _renderTargetView->getRenderTargetView(),
      _RGBAColor);
  }

  void DXDeviceContext::clearDepthStencilView(DXDepthStencilView * _depthStencilView)
  {
    m_deviceContext->ClearDepthStencilView(
      _depthStencilView->getDepthStencilView(), D3D11_CLEAR_DEPTH, 1.0f, 0);
  }

  void DXDeviceContext::setInputLayout(DXInputLayout * _inputLayout)
  {
    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void DXDeviceContext::setVertexBuffer(
    DXVertexBuffer * _vertexBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers,
    const void * _data)
  {

    uint32 stride = sizeof(_data);
    uint32 offset = 0;

    m_deviceContext->IASetVertexBuffers(
      _startSlot,
      _numOfBuffers,
      _vertexBuffer->getBufferRef(),
      &stride,
      &offset);
  }

  void DXDeviceContext::setIndexBuffer(
    DXIndexBuffer * _indexBuffer,
    FOXGI_FORMAT::E _format,
    uint32 _offset)
  {

    m_deviceContext->IASetIndexBuffer(
      _indexBuffer->getBuffer(),
      static_cast<DXGI_FORMAT>(_format),
      _offset);
  }

}