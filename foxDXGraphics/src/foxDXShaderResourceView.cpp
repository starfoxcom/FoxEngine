/**
 * Includes
 */
#include "foxDXShaderResourceView.h"

namespace foxEngineSDK
{

  
  foxDXShaderResourceView::foxDXShaderResourceView()
  {
  }

  foxDXShaderResourceView::~foxDXShaderResourceView()
  {
    if (m_shaderResourceView) m_shaderResourceView->Release();
    m_shaderResourceView = nullptr;
  }

  ID3D11ShaderResourceView * foxDXShaderResourceView::getShaderResourceView()
  {
    return m_shaderResourceView;
  }
  ID3D11ShaderResourceView ** foxDXShaderResourceView::getShaderResourceViewRef()
  {
    return &m_shaderResourceView;
  }
}