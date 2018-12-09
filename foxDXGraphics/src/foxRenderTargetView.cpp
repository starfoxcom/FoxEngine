
/**
 * Includes
 */
#include "foxRenderTargetView.h"

namespace foxEngineSDK
{

  RenderTargetView::RenderTargetView()
  {
  }


  RenderTargetView::~RenderTargetView()
  {
  }

  ID3D11RenderTargetView ** RenderTargetView::getRenderTargetViewRef()
  {
    return &m_renderTargetView;
  }

  ID3D11RenderTargetView * RenderTargetView::getRenderTargetView()
  {
    return m_renderTargetView;
  }
}
