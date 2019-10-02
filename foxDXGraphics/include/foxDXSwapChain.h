#pragma once
/**
 * @file foxDXSwapChain.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Swap Chain Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  class DXSwapChain
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXSwapChain();

    /**
     * @brief Default destructor.
     */
    ~DXSwapChain();

    /**
     * @brief Gets the DirectX Swap Chain.
     */
    IDXGISwapChain * getSwapChain();

    /**
     * @brief Gets the DirectX Swap Chain reference.
     */
    IDXGISwapChain ** getSwapChainRef();

  private:

    IDXGISwapChain * m_swapChain; /**< Swap Chain class object member*/

  };
}