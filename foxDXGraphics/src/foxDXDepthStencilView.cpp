/**
 * Includes
 */
#include "foxDXDepthStencilView.h"

namespace foxEngineSDK
{


  DXDepthStencilView::DXDepthStencilView()
  {
  }

  DXDepthStencilView::~DXDepthStencilView()
  {
    if (m_depthStencilView) m_depthStencilView->Release();
    m_depthStencilView = nullptr;
  }

  ID3D11DepthStencilView * DXDepthStencilView::getDepthStencilView()
  {
    return m_depthStencilView;
  }

  ID3D11DepthStencilView ** DXDepthStencilView::getDepthStencilViewRef()
  {
    return &m_depthStencilView;
  }

}