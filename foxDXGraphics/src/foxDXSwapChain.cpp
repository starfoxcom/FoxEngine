/**
 * Includes
 */
#include "foxDXSwapChain.h"

namespace foxEngineSDK
{

  foxDXSwapChain::foxDXSwapChain()
  {
  }

  foxDXSwapChain::~foxDXSwapChain()
  {
    if (m_swapChain) m_swapChain->Release();
    m_swapChain = nullptr;
  }

  IDXGISwapChain * foxDXSwapChain::getSwapChain()
  {
    return m_swapChain;
  }

  IDXGISwapChain ** foxDXSwapChain::getSwapChainRef()
  {
    return &m_swapChain;
  }

  void foxDXSwapChain::present()
  {
    m_swapChain->Present(0, 0);
  }


}