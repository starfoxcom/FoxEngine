/**
 * Includes
 */
#include "foxDXDepthStencilView.h"

namespace foxEngineSDK
{


  foxDXDepthStencilView::foxDXDepthStencilView()
  {
  }

  foxDXDepthStencilView::~foxDXDepthStencilView()
  {
    if (m_depthStencilView) m_depthStencilView->Release();
    m_depthStencilView = nullptr;
  }

  ID3D11DepthStencilView * foxDXDepthStencilView::getDepthStencilView()
  {
    return m_depthStencilView;
  }

  ID3D11DepthStencilView ** foxDXDepthStencilView::getDepthStencilViewRef()
  {
    return &m_depthStencilView;
  }

}