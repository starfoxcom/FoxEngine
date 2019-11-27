/**
 * Includes
 */
#include "foxDXSamplerState.h"

namespace foxEngineSDK
{


  DXSamplerState::DXSamplerState()
  {
  }

  DXSamplerState::~DXSamplerState()
  {
    if (m_samplerState) m_samplerState->Release();
    m_samplerState = nullptr;
  }

  ID3D11SamplerState * DXSamplerState::getSamplerState()
  {
    return m_samplerState;
  }

  ID3D11SamplerState ** DXSamplerState::getSamplerStateRef()
  {
    return &m_samplerState;
  }

}