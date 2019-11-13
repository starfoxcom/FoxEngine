/**
 * Includes
 */
#include "foxDXRenderTargetView.h"

namespace foxEngineSDK
{

  DXRenderTargetView::DXRenderTargetView()
  {
  }

  DXRenderTargetView::~DXRenderTargetView()
  {
    if (m_renderTargetView) m_renderTargetView->Release();
    m_renderTargetView = nullptr;
  }

  ID3D11RenderTargetView * DXRenderTargetView::getRenderTargetView()
  {
    return m_renderTargetView;
  }

  ID3D11RenderTargetView ** DXRenderTargetView::getRenderTargetViewRef()
  {
    return &m_renderTargetView;
  }

}