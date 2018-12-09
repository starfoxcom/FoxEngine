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
class SwapChain;
class Device;
class DeviceContext;
class VertexBuffer;
class InputLayout;
class RenderTargetView;
class VertexShader;
class PixelShader;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:
    DXGraphicsAPI();
    ~DXGraphicsAPI();

    /**
     * @brief Initializes the graphics API.
     * @param _windowHandler The window application.
     */
    void init(HWND _windowHandler);

    /**
     * @brief Initializes the graphic content.
     */
    void initGraphics();

    /**
     * @brief Releases all D3D11 objects.
     */
    void destroy();

    /**
     * @brief Initializes pipeline
     */
    HRESULT initPipeline(const char * _fileName);

    SwapChain * getSwapChain();

    DeviceContext * getDeviceContext();

    RenderTargetView * getRenderTargetView();

    VertexBuffer * getVertexBuffer();

  private:

    SwapChain * m_swapChain;

    Device * m_device;

    DeviceContext * m_deviceContext;

    VertexBuffer * m_vertexBuffer;

    InputLayout * m_inputLayout;

    RenderTargetView * m_renderTargetView;

    VertexShader * m_vertexShader;

    PixelShader * m_pixelShader;
  };
}


