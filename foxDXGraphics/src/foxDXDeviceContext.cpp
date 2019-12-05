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
#include "foxDXSamplerState.h"

namespace foxEngineSDK
{

  foxDXDeviceContext::foxDXDeviceContext()
  {
  }

  foxDXDeviceContext::~foxDXDeviceContext()
  {
    if (m_deviceContext) m_deviceContext->ClearState();

    if (m_deviceContext) m_deviceContext->Release();

    m_deviceContext = nullptr;
  }

  ID3D11DeviceContext * foxDXDeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }

  ID3D11DeviceContext ** foxDXDeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }

  void foxDXDeviceContext::clearRenderTargetView(
    foxDXRenderTargetView * _renderTargetView,
    float * _RGBAColor)
  {
    m_deviceContext->ClearRenderTargetView(
      _renderTargetView->getRenderTargetView(),
      _RGBAColor);
  }

  void foxDXDeviceContext::clearDepthStencilView(foxDXDepthStencilView * _depthStencilView)
  {
    m_deviceContext->ClearDepthStencilView(
      _depthStencilView->getDepthStencilView(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
  }

  void foxDXDeviceContext::setInputLayout(foxDXInputLayout * _inputLayout)
  {
    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void foxDXDeviceContext::setVertexBuffer(
    foxDXVertexBuffer * _vertexBuffer,
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

  void foxDXDeviceContext::setIndexBuffer(
    foxDXIndexBuffer * _indexBuffer,
    FOXGI_FORMAT::E _format,
    uint32 _offset)
  {

    m_deviceContext->IASetIndexBuffer(
      _indexBuffer->getBuffer(),
      static_cast<DXGI_FORMAT>(_format),
      _offset);
  }

  void foxDXDeviceContext::setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_topology));
  }

  void foxDXDeviceContext::updateConstantBuffer(foxDXConstantBuffer * _constantBuffer, const void * _data)
  {
    m_deviceContext->UpdateSubresource(_constantBuffer->getBuffer(), 0, NULL, _data, 0, 0);
  }

  void foxDXDeviceContext::setVertexShader(foxDXVertexShader * _vertexShader)
  {
    m_deviceContext->VSSetShader(_vertexShader->getVertexShader(), NULL, 0);
  }

  void foxDXDeviceContext::setVSConstantBuffers(
    foxDXConstantBuffer * _constantBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    m_deviceContext->VSSetConstantBuffers(_startSlot, _numOfBuffers, _constantBuffer->getBufferRef());
  }

  void foxDXDeviceContext::setPSConstantBuffers(
    foxDXConstantBuffer * _constantBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    m_deviceContext->PSSetConstantBuffers(_startSlot, _numOfBuffers, _constantBuffer->getBufferRef());
  }

  void foxDXDeviceContext::setShaderResources(
    foxDXShaderResourceView * _shaderResourceViews,
    uint32 _startSlot,
    uint32 _numOfViews)
  {
    m_deviceContext->PSSetShaderResources(
      _startSlot,
      _numOfViews,
      _shaderResourceViews->getShaderResourceViewRef());
  }

  void foxDXDeviceContext::setPixelShader(foxDXPixelShader * _pixelShader)
  {
    m_deviceContext->PSSetShader(_pixelShader->getPixelShader(), NULL, 0);
  }

  void foxDXDeviceContext::setRasterizerState(foxDXRasterizerState * _rasterizerState)
  {
    m_deviceContext->RSSetState(_rasterizerState->getRasterizerState());
  }

  void foxDXDeviceContext::setPSSamplerState(
    foxDXSamplerState * _samplerState,
    uint32 _startSlot,
    uint32 _numOfSamplers)
  {
    m_deviceContext->PSSetSamplers(_startSlot, _numOfSamplers, _samplerState->getSamplerStateRef());
  }

  void foxDXDeviceContext::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->Draw(_vertexCount, _vertexStart);
  }

  void foxDXDeviceContext::drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart)
  {
    m_deviceContext->DrawIndexed(_indexCount, _indexStart, _vertexStart);
  }

}