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

#include "foxSwapChain.h"
#include "foxDevice.h"
#include "foxDeviceContext.h"
#include "foxVertexBuffer.h"

/**
 * Libs, since the .libs have been added in the project settings, this is no longer needed
 */
//#pragma comment(lib, "d3dcompiler.lib")

namespace foxEngineSDK
{

  class DXGraphicsAPI
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


    SwapChain * m_swapChain;
    //IDXGISwapChain * m_swapChain;

    Device * m_device;
    //ID3D11Device * m_device;

    DeviceContext * m_deviceContext;
    //ID3D11DeviceContext * m_deviceContext;

    VertexBuffer * m_vertexBuffer;

    ID3D11InputLayout * m_inputLayout;

    ID3D11RenderTargetView * m_renderTargetView;

    ID3D11VertexShader * m_vertexShader;

    ID3D11PixelShader * m_pixelShader;

  private:

  };
}


