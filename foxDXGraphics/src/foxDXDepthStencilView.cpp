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