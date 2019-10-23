/**
 * Includes
 */
#include "foxDXWireframeRS.h"

namespace foxEngineSDK
{

  DXWireframeRS::DXWireframeRS()
  {
  }

  DXWireframeRS::~DXWireframeRS()
  {
  }

  void DXWireframeRS::setWireframeRSDesc()
  {

    ZeroMemory(&m_rasterizerDesc, sizeof(m_rasterizerDesc));

    m_rasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
    m_rasterizerDesc.CullMode = D3D11_CULL_NONE;
    m_rasterizerDesc.FrontCounterClockwise = false;
    m_rasterizerDesc.DepthBias = 0;
    m_rasterizerDesc.DepthBiasClamp = 0.0f;
    m_rasterizerDesc.SlopeScaledDepthBias = 0.0f;
    m_rasterizerDesc.DepthClipEnable = true;
    m_rasterizerDesc.ScissorEnable = false;
    m_rasterizerDesc.MultisampleEnable = false;
    m_rasterizerDesc.AntialiasedLineEnable = false;
  }


}