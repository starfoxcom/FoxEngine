#include "foxSwapChain.h"


namespace foxEngineSDK
{

  SwapChain::SwapChain()
  {
  }


  SwapChain::~SwapChain()
  {
  }

  void SwapChain::setSwapChainDesc(
    HWND _windowHandler,
    UINT _backBuffers,
    DXGI_FORMAT _format,
    UINT _samples,
    BOOL _windowed,
    DXGI_SWAP_CHAIN_FLAG _flag)
  {

    //Clear out the swap chain for use
    ZeroMemory(&m_swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    //Set the swap chain description
    m_swapChainDesc.BufferCount = _backBuffers;                     //One back buffer
    m_swapChainDesc.BufferDesc.Format = _format;                    //Use 32-bit color
    m_swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;  //How swap chain is to be used
    m_swapChainDesc.OutputWindow = _windowHandler;                  //The window to be used
    m_swapChainDesc.SampleDesc.Count = _samples;                     //How many multi samples
    m_swapChainDesc.Windowed = _windowed;                           //Windowed/full-screen mode
    m_swapChainDesc.Flags = _flag;                                  //Allow full-screen switch
  }

  IDXGISwapChain * SwapChain::getSwapChain()
  {
    return m_swapChain;
  }

  IDXGISwapChain ** SwapChain::getSwapChainRef()
  {
    return &m_swapChain;
  }

  DXGI_SWAP_CHAIN_DESC * SwapChain::getSwapChainDesc()
  {
    return &m_swapChainDesc;
  }
}
