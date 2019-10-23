/**
 * Includes
 */
#include "foxDXRasterizerState.h"

namespace foxEngineSDK
{

  DXRasterizerState::DXRasterizerState()
  {
  }

  DXRasterizerState::~DXRasterizerState()
  {
  }

  ID3D11RasterizerState * DXRasterizerState::getRasterizerState()
  {
    return m_rasterizerState;
  }

  ID3D11RasterizerState ** DXRasterizerState::getRasterizerStateRef()
  {
    return &m_rasterizerState;
  }
  D3D11_RASTERIZER_DESC DXRasterizerState::getRasterizerStateDesc()
  {
    return m_rasterizerDesc;
  }
}