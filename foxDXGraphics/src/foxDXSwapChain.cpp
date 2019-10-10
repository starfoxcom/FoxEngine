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