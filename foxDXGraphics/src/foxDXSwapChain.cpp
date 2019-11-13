/**
 * Includes
 */
#include "foxDXSwapChain.h"

namespace foxEngineSDK
{

  DXSwapChain::DXSwapChain()
  {
  }

  DXSwapChain::~DXSwapChain()
  {
    if (m_swapChain) m_swapChain->Release();
    m_swapChain = nullptr;
  }

  IDXGISwapChain * DXSwapChain::getSwapChain()
  {
    return m_swapChain;
  }

  IDXGISwapChain ** DXSwapChain::getSwapChainRef()
  {
    return &m_swapChain;
  }

  void DXSwapChain::present()
  {
    m_swapChain->Present(0, 0);
  }


}