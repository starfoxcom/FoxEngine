#include "foxViewport.h"

namespace foxEngineSDK
{
  Viewport::Viewport()
  {
  }
  Viewport::~Viewport()
  {
  }
  void Viewport::initViewport(float _width, float _height)
  {
    m_viewport.Width = _width;
    m_viewport.Height = _height;
    m_viewport.MinDepth = 0.0f;
    m_viewport.MaxDepth = 1.0f;
    m_viewport.TopLeftX = 0;
    m_viewport.TopLeftY = 0;
  }
  D3D11_VIEWPORT * Viewport::getViewport()
  {
    return &m_viewport;
  }
}
