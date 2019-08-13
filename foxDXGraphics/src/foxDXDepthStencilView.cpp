#include "foxDXDepthStencilView.h"
#include "foxDXTexture.h"

foxEngineSDK::DXDepthStencilVew::DXDepthStencilVew()
{
  m_depthStencilView = nullptr;
}

foxEngineSDK::DXDepthStencilVew::~DXDepthStencilVew()
{
  if (m_depthStencilView != nullptr)
    m_depthStencilView = nullptr;
  delete m_depthStencilView;
}

void foxEngineSDK::DXDepthStencilVew::setDepthStencilViewDesc(DXTexture * _texture)
{

  ZeroMemory(&m_depthStencilViewDesc, sizeof(m_depthStencilViewDesc));

  m_depthStencilViewDesc.Format = _texture->getTextureDesc().Format;
  m_depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
  m_depthStencilViewDesc.Texture2D.MipSlice = 0;
}

ID3D11DepthStencilView * foxEngineSDK::DXDepthStencilVew::getDepthStencilView()
{
  return m_depthStencilView;
}

ID3D11DepthStencilView ** foxEngineSDK::DXDepthStencilVew::getDepthStencilViewRef()
{
  return &m_depthStencilView;
}

D3D11_DEPTH_STENCIL_VIEW_DESC * foxEngineSDK::DXDepthStencilVew::getDepthStencilViewDesc()
{
  return &m_depthStencilViewDesc;
}
