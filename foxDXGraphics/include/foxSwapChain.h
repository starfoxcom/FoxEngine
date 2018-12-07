/**
* @file foxSwapChain.h
* @author --
* @date ---
* @brief Implementation of swap chain.
*/
#pragma once

/**
 * Includes
 */
#include <d3d11.h>

 /**
 * Libs
 */
namespace foxEngineSDK
{

  class SwapChain
  {
  public:
    SwapChain();
    ~SwapChain();

    void setSwapChainDesc(
      HWND _windowHandler,
      UINT _backBuffers = 1,
      DXGI_FORMAT _format = DXGI_FORMAT_R8G8B8A8_UNORM,
      UINT _samples = 4,
      BOOL _windowed = TRUE,
      DXGI_SWAP_CHAIN_FLAG _flag = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH);

    IDXGISwapChain ** getSwapChainRef();

    IDXGISwapChain * getSwapChain();

    DXGI_SWAP_CHAIN_DESC getSwapChainDesc();




  private:
    DXGI_SWAP_CHAIN_DESC m_swapChainDesc;
    IDXGISwapChain * m_swapChain;

  };
}

