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

  class foxDXSwapChain
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXSwapChain();

    /**
     * @brief Default destructor.
     */
    ~foxDXSwapChain();

    /**
     * @brief Gets the DirectX Swap Chain.
     */
    IDXGISwapChain * getSwapChain();

    /**
     * @brief Gets the DirectX Swap Chain reference.
     */
    IDXGISwapChain ** getSwapChainRef();

    /**
     * @brief Present the information from the back buffer to the front buffer.
     */
    void present();

  private:

    IDXGISwapChain * m_swapChain = nullptr; /**< Swap Chain class object member*/

  };
}