/**
 * Includes
 */
#include "foxDXDeviceContext.h"
#include "foxDXRenderTargetView.h"
#include "foxDXDepthStencilView.h"
#include "foxDXRasterizerState.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXConstantBuffer.h"
#include "foxDXShaderResourceView.h"

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
      _depthStencilView->getDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
  }

  void DXDeviceContext::setInputLayout(DXInputLayout * _inputLayout)
  {
    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void DXDeviceContext::setVertexBuffer(
    DXVertexBuffer * _vertexBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers,
    uint32 _structSize)
  {

    uint32 stride = _structSize;
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

  void DXDeviceContext::setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_topology));
  }

  void DXDeviceContext::updateConstantBuffer(DXConstantBuffer * _constantBuffer, const void * _data)
  {
    m_deviceContext->UpdateSubresource(_constantBuffer->getBuffer(), 0, NULL, _data, 0, 0);
  }

  void DXDeviceContext::setVertexShader(DXVertexShader * _vertexShader)
  {
    m_deviceContext->VSSetShader(_vertexShader->getVertexShader(), NULL, 0);
  }

  void DXDeviceContext::setConstantBuffers(
    DXConstantBuffer * _constantBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    m_deviceContext->VSSetConstantBuffers(_startSlot, _numOfBuffers, _constantBuffer->getBufferRef());
  }

  void DXDeviceContext::setShaderResources(
    DXShaderResourceView * _shaderResourceViews,
    uint32 _startSlot,
    uint32 _numOfViews)
  {
    m_deviceContext->PSSetShaderResources(
      _startSlot,
      _numOfViews,
      _shaderResourceViews->getShaderResourceViewRef());
  }

  void DXDeviceContext::setPixelShader(DXPixelShader * _pixelShader)
  {
    m_deviceContext->PSSetShader(_pixelShader->getPixelShader(), NULL, 0);
  }

  void DXDeviceContext::setRasterizerState(DXRasterizerState * _rasterizerState)
  {
    m_deviceContext->RSSetState(_rasterizerState->getRasterizerState());
  }

  void DXDeviceContext::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->Draw(_vertexCount, _vertexStart);
  }

  void DXDeviceContext::drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart)
  {
    m_deviceContext->DrawIndexed(_indexCount, _indexStart, _vertexStart);
  }

}