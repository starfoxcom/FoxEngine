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
#include "foxMatrix4.h"

namespace foxEngineSDK
{
/**
 * Forward declarations
 */
  class DXRenderWindow;
  class DXSwapChain;
  class DXDevice;
  class DXDeviceContext;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:

    //Default constructor
    DXGraphicsAPI();

    //Default destructor
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

  private:

    /**
     * @brief Initialize the device and Swap Chain.
     */
    bool initDeviceAndSwapChain();

    DXRenderWindow * m_renderWindow; /**< Render Window class object member.*/

    DXSwapChain * m_swapChain; /**< Swap Chain class object member.*/

    DXDevice * m_device; /**< Device class object member.*/

    DXDeviceContext * m_deviceContext; /**< Device Context class object member.*/


  };
}


