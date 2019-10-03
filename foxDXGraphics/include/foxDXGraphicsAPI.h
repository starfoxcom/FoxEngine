#pragma once
/**
 * @file foxDXGraphicsAPI.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Implementation of DirectX.
 */

/**
 * Includes
 */
#include <d3dcompiler.h>
#include <d3d11.h>

#include "foxGraphicsDefines.h"
#include "foxGraphicsCommons.h"

#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{
/**
 * Forward declarations
 */
  class DXRenderWindow;
  class DXSwapChain;
  class DXDevice;
  class DXDeviceContext;
  class DXTexture;
  class DXRenderTargetView;
  class DXDepthStencilView;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:

    /**
     * @brief Default constructor
     */
    DXGraphicsAPI();

    /**
     * @brief Default destructor
     */
    ~DXGraphicsAPI();

    /**
     * @brief Initialize the graphics Window.
     * @param _hInstance The instance of the application.
     * @param _windowClass The name of the window class.
     * @param _windowTitle The title of the window.
     * @param _width The width of the window.
     * @param _height The height of the window.
     */
    bool initWindow(
      HINSTANCE _hInstance,
      std::string _windowClass,
      std::string _windowTitle,
      int32 _width,
      int32 _height);

    /**
     * @brief Process the messages of the window.
     */
    bool processMessages();

    /**
     * @brief Initialize the DirectX Graphics API.
     */
    bool initDXGraphicsAPI();

    /**
     * @brief Clears the Render Target View.
     * @param _RGBAColor The color to clean with.
     */
    void clearRenderTargetView(float * _RGBAColor);

    /**
     * @brief Clears the Depth Stencil View.
     */
    void clearDepthStencilView();

    /**
     * @brief Present the information from the back buffer to the front buffer.
     */
    void present();

    /**
     * @brief Cleans up the Graphics API.
     */
    void cleanUpDXGraphicsAPI();

  private:

    /**
     * @brief Creates the device and Swap Chain.
     */
    bool createDeviceAndSwapChain();

    /**
     * @brief Creates the Render Target View.
     */
    bool createRenderTargetView();

    /**
     * @brief Creates the Depth Stencil View.
     */
    bool createDepthStencilView();

    DXRenderWindow * m_renderWindow; /**< Render Window member.*/

    DXSwapChain * m_swapChain; /**< Swap Chain member.*/

    DXDevice * m_device; /**< Device class object member.*/

    DXDeviceContext * m_deviceContext; /**< Device Context member.*/

    DXRenderTargetView * m_renderTargetView; /**< Render Target View member.*/

    DXTexture * m_depthStencilBuffer; /**< Depth Stencil Buffer member.*/

    DXDepthStencilView * m_depthStencilView; /**< Depth Stencil View member.*/


  };
}


