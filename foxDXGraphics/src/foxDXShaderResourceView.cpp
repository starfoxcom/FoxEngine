/**
 * Includes
 */
#include "foxDXShaderResourceView.h"

namespace foxEngineSDK
{

  
  DXShaderResourceView::DXShaderResourceView()
  {
  }

  DXShaderResourceView::~DXShaderResourceView()
  {
    if (m_shaderResourceView) m_shaderResourceView->Release();
    m_shaderResourceView = nullptr;
  }

  ID3D11ShaderResourceView * DXShaderResourceView::getShaderResourceView()
  {
    return m_shaderResourceView;
  }
  ID3D11ShaderResourceView ** DXShaderResourceView::getShaderResourceViewRef()
  {
    return &m_shaderResourceView;
  }
}