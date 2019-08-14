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
#include "foxMatrix4.h"

/**
 * Libs, since the .libs have been added in the project settings, this is no longer needed
 */
//#pragma comment(lib, "d3dcompiler.lib")


namespace foxEngineSDK
{
/**
 * Forward declarations
 */
  class DXRenderWindow;
  class DXDevice;
  class DXSwapChain;
  class DXDeviceContext;
  class DXRenderTargetView;
  class DXTexture;
  class DXDepthStencilVew;
  class DXViewport;
  class DXVertexShader;
  class DXInputLayout;
  class DXPixelShader;
  class DXVertexBuffer;
  class DXIndexBuffer;
  class DXConstantBuffer;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:

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
     * @brief Creates the texture
     * @param _width The window width.
     * @param _height The window height.
     */
    bool createTexture2D(
      uint32 _width,
      uint32 _height,
      uint32 _bindFlag);

    /**
     * @brief Creates the Depth Stencil View
     */
    bool createDepthStencilView();

    /**
     * @brief Initialize the viewport.
     * @param _width The width of the window.
     * @param _height The height of the window.
     */
    void initViewport(float _width, float _height);

    /**
     * @brief Creates the vertex shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

    /**
     * @brief Creates the pixel shader.
     * @param @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the pixel shader.
     * @param _shaderModel The shader model.
     */
    bool createPixelShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel,
      const uint32 _index);

    /**
     * @brief Creates the vertex buffer.
     * @param _cpuAcces
     * @param _miscFlag
     */
    bool createVertexBuffer();

    /**
     * @brief Creates the index buffer.
     * @param _cpuAcces
     * @param _miscFlag
     */
    bool createIndexBuffer();

    /**
     * @brief Creates the constant buffer.
     * @param _cpuAcces
     * @param _miscFlag
     */
    bool createConstantBuffer();

    /**
     * @brief Adds an input element to the input layout element descriptor
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
     * @brief Cleans the render target view.
     * @param _clearColor The color which will be used to clear the render target.
     */
    void clearRenderTargetView(float * _clearColor);

    void clearDepthStencilView();

    /**
     * @brief Updates the constant buffer.
     * @param _data The data to update.
     */
    void updateConstantBuffer(const void * _data);

    //////////////////////////////////////////////////////////////////////////
    // SETTERS
    //////////////////////////////////////////////////////////////////////////
    /**
     * SwapChain functions
     */
    void setSwapChainDesc(
      uint32 _width,
      uint32 _height,
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

    /**
     * @brief Sets the vertex buffer input assembly.
     * @param _startSlot
     * @param _numOfBuffers
     */
    void setIAVertexBuffer(uint32 _startSlot = 0, uint32 _numOfBuffers = 1);

    /**
     * @brief Sets the index buffer input assembly.
     * @param _format The Index buffer format.
     * @param _offset The offset of the Index buffer.
     */
    void setIAIndexBuffer(FOXGI_FORMAT::E _format, uint32 _offset);

    /**
     * @brief Sets the primitive topology
     * @param _topology The topology to set.
     */
    void setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology);

    /**
     * @brief Sets the vertex shader.
     */
    void setVertexShader();

    /**
     * @brief Sets the vertex constant buffer.
     * @param _startSlot
     * @param _numOfBuffers
     */
    void setVSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1);

    /**
     * @brief Sets the pixel constant buffer.
     * @param _startSlot
     * @param _numOfBuffers
     */
    void setPSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1);

    /**
     * @brief Sets the pixel shader.
     */
    void setPixelShader(const uint32 _index);

    /**
     * @brief Draws the vertices.
     * @param _vertexCount The total count of vertices.
     * @param _vertexStart The starting point of the vertices.
     */
    void draw(uint32 _vertexCount, uint32 _vertexStart);

    /**
     * @brief Draws the indices.
     * @param _indexCount
     * @param _indexStart
     * @param _vertexStart
     */
    void drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart);

    /**
     * @brief Present the information from the back to the front buffer.
     */
    void present();




  private:

    DXRenderWindow * m_renderWindow;

    DXSwapChain * m_swapChain;

    DXDevice * m_device;

    DXDeviceContext * m_deviceContext;

    DXTexture * m_backBuffer;

    DXTexture * m_depthStencil;

    DXDepthStencilVew * m_depthStencilView;

    DXViewport * m_viewport;

    DXRenderTargetView * m_renderTargetView;

    DXVertexShader * m_vertexShader;

    DXInputLayout * m_inputLayout;

    std::vector<DXPixelShader*> m_pixelShaders;

    DXVertexBuffer * m_vertexBuffer;

    DXIndexBuffer * m_indexBuffer;

    DXConstantBuffer * m_constantBuffer;

    //These matrices are going to be on the Camera class, when that class gets created.
    Matrix4 m_world;

    Matrix4 m_view;

    Matrix4 m_projection;

    Matrix4 m_spin;
    
    Matrix4 m_orbit;

    Matrix4 m_translation;

    Matrix4 m_scalation;
  };
}


