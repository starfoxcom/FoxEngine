/**
 * Includes
 */
#include "foxDXSamplerState.h"

namespace foxEngineSDK
{


  foxDXSamplerState::foxDXSamplerState()
  {
  }

  foxDXSamplerState::~foxDXSamplerState()
  {
    if (m_samplerState) m_samplerState->Release();
    m_samplerState = nullptr;
  }

  ID3D11SamplerState * foxDXSamplerState::getSamplerState()
  {
    return m_samplerState;
  }

  ID3D11SamplerState ** foxDXSamplerState::getSamplerStateRef()
  {
    return &m_samplerState;
  }

}