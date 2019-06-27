/**
* @file foxDXGraphicsAPI.h
* @author --
* @date ---
* @brief Implementation of DirectX.
*/
#pragma once

/**
 * Includes
 */
#include <d3dcompiler.h>
#include <d3d11.h>

#include "foxLog.h"
#include "foxGraphicsDefines.h"

/**
 * Libs, since the .libs have been added in the project settings, this is no longer needed
 */
//#pragma comment(lib, "d3dcompiler.lib")


namespace foxEngineSDK
{
/**
 * Forward declarations
 */
  class RenderWindow;
  class SwapChain;
  class Device;
  class DeviceContext;
  class Texture;
  class RenderTargetView;
  class VertexShader;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:

    enum ShaderType
    {
      VERTEX = 0,
      PIXEL
    };

    DXGraphicsAPI();
    ~DXGraphicsAPI();

    /**
     * RenderWindow functions
     */
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
     * @brief Gets the window handle.
     */
    //HWND getWindowHandle();

    /**
     * @brief Process the messages of the window.
     */
    bool processMessages();

    /**
     * @brief Initialize the device.
     */
    bool initDevice();

    /**
     * @brief Creates the vertex shader
     */
    bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);
    /**
     * @brief Cleans up the device.
     */
    void cleanupDevice();

    /**
     * @brief Render the window frame.
     */
    void render();

    /**
     * SwapChain functions
     */
    void setSwapChainDesc(
      uint32 _bufferCount = 1,
      uint32 _numerator = 60,
      uint32 _denominator = 1,
      uint32 _sampleCount = 1,
      uint32 _sampleQuality = 0,
      bool _windowed = true);



  private:

    RenderWindow * m_renderWindow;

    SwapChain * m_swapChain;

    Device * m_device;

    DeviceContext * m_deviceContext;

    Texture * m_texture;

    RenderTargetView * m_renderTargetView;

    VertexShader * m_vertexShader;
  };
}


