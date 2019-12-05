/**
 * Includes
 */
#include "foxDXRenderTargetView.h"

namespace foxEngineSDK
{

  foxDXRenderTargetView::foxDXRenderTargetView()
  {
  }

  foxDXRenderTargetView::~foxDXRenderTargetView()
  {
    if (m_renderTargetView) m_renderTargetView->Release();
    m_renderTargetView = nullptr;
  }

  ID3D11RenderTargetView * foxDXRenderTargetView::getRenderTargetView()
  {
    return m_renderTargetView;
  }

  ID3D11RenderTargetView ** foxDXRenderTargetView::getRenderTargetViewRef()
  {
    return &m_renderTargetView;
  }

}