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
    uint32 _bufferCount,
    uint32 _numerator,
    uint32 _denominator,
    uint32 _sampleCount,
    uint32 _sampleQuality,
    bool _windowed)
  {

    RECT rect;

    GetClientRect(_windowHandler, &rect);
    uint32 width = width = rect.right - rect.left;
    uint32 height = rect.bottom - rect.top;

    //Clear out the swap chain for use
    ZeroMemory(&m_swapChainDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

    //Set the swap chain description
    m_swapChainDesc.BufferCount = _bufferCount;
    m_swapChainDesc.BufferDesc.Width = width;
    m_swapChainDesc.BufferDesc.Height = height;
    m_swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    m_swapChainDesc.BufferDesc.RefreshRate.Numerator = _numerator;
    m_swapChainDesc.BufferDesc.RefreshRate.Denominator = _denominator;
    m_swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    m_swapChainDesc.OutputWindow = _windowHandler;
    m_swapChainDesc.SampleDesc.Count = _sampleCount;
    m_swapChainDesc.SampleDesc.Quality = _sampleQuality;
    m_swapChainDesc.Windowed = _windowed;
  }

  void SwapChain::present()
  {
    m_swapChain->Present(0, 0);
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
