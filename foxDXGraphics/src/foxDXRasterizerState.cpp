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
    if (m_rasterizerState) m_rasterizerState->Release();
    m_rasterizerState = nullptr;

  }

  ID3D11RasterizerState * DXRasterizerState::getRasterizerState()
  {
    return m_rasterizerState;
  }

  ID3D11RasterizerState ** DXRasterizerState::getRasterizerStateRef()
  {
    return &m_rasterizerState;
  }


}