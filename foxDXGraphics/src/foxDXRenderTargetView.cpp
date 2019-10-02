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