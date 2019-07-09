#include "foxDXViewport.h"

namespace foxEngineSDK
{
  DXViewport::DXViewport()
  {
  }
  DXViewport::~DXViewport()
  {
  }
  void DXViewport::initViewport(float _width, float _height)
  {
    m_viewport.Width = _width;
    m_viewport.Height = _height;
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;
  }
  D3D11_VIEWPORT * DXViewport::getViewport()
  {
    return &m_viewport;
  }
}
