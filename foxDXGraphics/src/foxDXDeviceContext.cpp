/**
 * Includes
 */
#include "foxDXDeviceContext.h"
#include "foxDXRenderTargetView.h"
#include "foxDXDepthStencilView.h"
#include "foxDXInputLayout.h"

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

}