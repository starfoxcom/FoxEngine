/**
 * Includes
 */
#include "foxDXRasterizerState.h"

namespace foxEngineSDK
{

  foxDXRasterizerState::foxDXRasterizerState()
  {
  }

  foxDXRasterizerState::~foxDXRasterizerState()
  {
    if (m_rasterizerState) m_rasterizerState->Release();
    m_rasterizerState = nullptr;

  }

  ID3D11RasterizerState * foxDXRasterizerState::getRasterizerState()
  {
    return m_rasterizerState;
  }

  ID3D11RasterizerState ** foxDXRasterizerState::getRasterizerStateRef()
  {
    return &m_rasterizerState;
  }


}