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
#include "foxGraphicsCommons.h"

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
  class Device;
  class SwapChain;
  class DeviceContext;
  class RenderTargetView;
  class Texture;
  class Viewport;
  class VertexShader;
  class InputLayout;

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
     * @brief Initialize the viewport.
     * @param _width The width of the window.
     * @param _height The height of the window.
     */
    void initViewport(float _width, float _height);

    /**
     * @brief Creates the vertex shader
     * @param _filename The name of the shader file
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

    /**
     * 
     */
    void addInputElement(
      const char * _semanticName,
      uint32 _semanticIndex,
      FOXGI_FORMAT::E _format,
      uint32 _inputSlot,
      uint32 _alignedByteOffset,
      FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
      uint32 _instanceDataSetpRate);

    /**
     * @brief Creates the input layout
     */
    bool createInputLayout();

    /**
     * @brief Cleans up the device.
     */
    void cleanupDevice();

    /**
     * @brief Render the window frame.
     */
    void render();

    /**
     * SETTERS
     */
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

    /**
     * @brief Sets the input layout
     */
    void setInputLayout();



  private:

    RenderWindow * m_renderWindow;

    SwapChain * m_swapChain;

    Device * m_device;

    DeviceContext * m_deviceContext;

    Texture * m_texture;

    Viewport * m_viewport;

    RenderTargetView * m_renderTargetView;

    VertexShader * m_vertexShader;

    InputLayout * m_inputLayout;
  };
}


