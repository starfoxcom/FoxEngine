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
#include "foxPrerequisitesUtilities.h"

 /**
 * Libs
 */
namespace foxEngineSDK
{

  class DXSwapChain
  {
  public:
    DXSwapChain();
    ~DXSwapChain();

    void setSwapChainDesc(
      HWND _windowHandler,
      uint32 _bufferCount = 1,
      uint32 _numerator = 60,
      uint32 _denominator = 1,
      uint32 _sampleCount = 1,
      uint32 _sampleQuality = 0,
      bool _windowed = true);

    void present();

    IDXGISwapChain ** getSwapChainRef();

    IDXGISwapChain * getSwapChain();

    DXGI_SWAP_CHAIN_DESC * getSwapChainDesc();

  private:
    DXGI_SWAP_CHAIN_DESC m_swapChainDesc;
    IDXGISwapChain * m_swapChain;
  };
}

