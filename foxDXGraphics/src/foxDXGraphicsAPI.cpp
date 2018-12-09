#include <vector>
#include <fstream>
#include <iostream>
  
#include "foxDXGraphicsAPI.h"
#include "foxSwapChain.h"
#include "foxDevice.h"
#include "foxDeviceContext.h"
#include "foxVertexBuffer.h"
#include "foxInputLayout.h"
#include "foxRenderTargetView.h"
#include "foxVertexShader.h"
#include "foxPixelShader.h"

namespace foxEngineSDK
{

  DXGraphicsAPI::DXGraphicsAPI()
  {
  }

  DXGraphicsAPI::~DXGraphicsAPI()
  {

    destroy();
  }

  void DXGraphicsAPI::init(HWND _windowHandler)
  {

    //Create new swap chain object
    m_swapChain = new SwapChain();

    //Create new device object
    m_device = new Device();

    //Create new device context object
    m_deviceContext = new DeviceContext();

    //Create new render target view object
    m_renderTargetView = new RenderTargetView();

    //Set swap chain description
    m_swapChain->setSwapChainDesc(_windowHandler);

    //Set the feature levels
    D3D_FEATURE_LEVEL featureLevels[] =
    {
      D3D_FEATURE_LEVEL_11_1,
      D3D_FEATURE_LEVEL_11_0,
      D3D_FEATURE_LEVEL_10_1,
      D3D_FEATURE_LEVEL_10_0,
      D3D_FEATURE_LEVEL_9_3,
      D3D_FEATURE_LEVEL_9_2,
      D3D_FEATURE_LEVEL_9_1
    };

    //Create device, device context and swap chain
    D3D11CreateDeviceAndSwapChain(
      NULL,
      D3D_DRIVER_TYPE_HARDWARE,
      NULL,
      NULL,
      featureLevels,
      7,
      D3D11_SDK_VERSION,
      m_swapChain->getSwapChainDesc(),
      m_swapChain->getSwapChainRef(),
      m_device->getDeviceRef(),
      NULL,
      m_deviceContext->getDEviceContextRef());

    //Create texture object
    ID3D11Texture2D * texture;

    //Get the buffer for the texture
    m_swapChain->getSwapChain()->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&texture);

    //Create render target view
    m_device->getDevice()->CreateRenderTargetView(texture, NULL, m_renderTargetView->getRenderTargetViewRef());

    //Release texture
    texture->Release();

    //Set render target
    m_deviceContext->getDeviceContext()->OMSetRenderTargets(1, m_renderTargetView->getRenderTargetViewRef(), NULL);

    //Create viewport object
    D3D11_VIEWPORT viewport;

    //Clear out the viewport for use
    ZeroMemory(&viewport, sizeof(D3D11_VIEWPORT));

    //Create rect
    RECT rect;

    //Get the client rect
    GetClientRect(_windowHandler, &rect);

    //Set the viewport
    viewport.TopLeftX = 0;
    viewport.TopLeftY = 0;
    viewport.Width = static_cast<FLOAT>(rect.right);
    viewport.Height = static_cast<FLOAT>(rect.bottom);

    //Set the viewport
    m_deviceContext->getDeviceContext()->RSSetViewports(1, &viewport);

    initPipeline("shaders.shader");
    initGraphics();


  }

  void DXGraphicsAPI::initGraphics()
  {

    //Create new vertex buffer object
    m_vertexBuffer = new VertexBuffer();

    //Create a triangle with the vertex struct
    vertex triangle[]
    {
      // X     Y     Z     W     R     G     B     A     NX    NY    NZ    NW    U     V
      { 0.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
      // X       Y    Z     W     R     G     B     A     NX    NY    NZ    NW    U     V
      { 0.45f, -0.5, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f },
      //  X       Y     Z     W     R     G     B     A     NX    NY    NZ    NW    U     V
      { -0.45f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }
    };

    //Create a triangle with the vertex struct
    //vertex2 triangle2[]
    //{
    //  {
    //    Vector4(0.0f,0.5f,0.0f,1.0f),
    //    Vector4(1.0f,0.0f,0.0f,1.0f),
    //    Vector4(0.0f,0.0f,0.0f,0.0f),
    //    Vector2(0.0f,0.0f)
    //  },
    //  {
    //    Vector4(0.45f,-0.5f,0.0f,1.0f),
    //    Vector4(0.0f,1.0f,0.0f,1.0f),
    //    Vector4(0.0f,0.0f,0.0f,0.0f),
    //    Vector2(0.0f,0.0f)
    //  },
    //  {
    //    Vector4(-0.45f,-0.5f,0.0f,1.0f),
    //    Vector4(0.0f,0.0f,1.0f,1.0f),
    //    Vector4(0.0f,0.0f,0.0f,0.0f),
    //    Vector2(0.0f,0.0f)
    //  }
    //};

    //Set vertex buffer description
    m_vertexBuffer->setBufferDesc();

    //Create sub resource data object
    D3D11_SUBRESOURCE_DATA InitData;

    //Set resource data description
    InitData.pSysMem = triangle;
    InitData.SysMemPitch = 0;
    InitData.SysMemSlicePitch = 0;

    //Create buffer
    m_device->getDevice()->CreateBuffer(
      m_vertexBuffer->getBufferDesc(),
      &InitData,
      m_vertexBuffer->getVertexBufferRef());

    

  }

  HRESULT DXGraphicsAPI::initPipeline(const char * _fileName)
  {

    HRESULT hr;

    m_inputLayout = new InputLayout();

    m_vertexShader = new VertexShader();

    m_pixelShader = new PixelShader();

    //Get file
    std::fstream file(_fileName, std::ios::in | std::ios::binary | std::ios::ate);

    //Create data buffer
    std::vector<char> dataBuffer;

    if (!file.is_open())
    {
      return -1;
    }

    size_t fileSize = static_cast<size_t>(file.tellg());

    dataBuffer.resize(fileSize);

    file.seekp(std::ios::beg);

    file.read(&dataBuffer[0], fileSize);

    file.close();

    ID3DBlob *VS, *PS;
    ID3DBlob *VSError, *PSError;

    //Compile the vertex shader
    hr = D3DCompile(
      &dataBuffer[0],
      fileSize,
      NULL,
      NULL,
      NULL,
      "VSMain",
      "vs_5_0",
      D3DCOMPILE_ENABLE_STRICTNESS,
      0,
      &VS,
      &VSError);

    if (FAILED(hr))
    {
      if (VSError)
      {
        OutputDebugStringA((char*)VSError->GetBufferPointer());
        VSError->Release();
      }
      if (VS)
      {
        VS->Release();
      }
      return hr;
    }

    //Compile the pixel shader
    hr = D3DCompile(
      &dataBuffer[0],
      fileSize,
      NULL,
      NULL,
      NULL,
      "PSMain",
      "ps_5_0",
      D3DCOMPILE_OPTIMIZATION_LEVEL3,
      NULL,
      &PS,
      &PSError);

    if (FAILED(hr))
    {
      if (VSError)
      {
        OutputDebugStringA((char*)PSError->GetBufferPointer());
        PSError->Release();
      }
      if (PS)
      {
        PS->Release();
      }
      return hr;
    }

    //Create vertex shader
    m_device->getDevice()->CreateVertexShader(
      VS->GetBufferPointer(),
      VS->GetBufferSize(),
      NULL,
      m_vertexShader->getVertexShaderRef());

    //Create pixel shader
    m_device->getDevice()->CreatePixelShader(
      PS->GetBufferPointer(),
      PS->GetBufferSize(),
      NULL,
      m_pixelShader->getPixelShaderRef());

    //Set vertex shader
    m_deviceContext->getDeviceContext()->VSSetShader(m_vertexShader->getVertexShader(), 0, 0);

    //Set pixel shader
    m_deviceContext->getDeviceContext()->PSSetShader(m_pixelShader->getPixelShader(), 0, 0);

    D3D11_INPUT_ELEMENT_DESC inputElementDesc[]
    {
      {"POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
      {"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    };

    m_device->getDevice()->CreateInputLayout(
      inputElementDesc,
      2,
      VS->GetBufferPointer(),
      VS->GetBufferSize(),
      m_inputLayout->getInputLayoutRef());

    m_deviceContext->getDeviceContext()->IASetInputLayout(m_inputLayout->getInputLayout());

    return S_OK;
  }

  SwapChain * DXGraphicsAPI::getSwapChain()
  {
    return m_swapChain;
  }

  DeviceContext * DXGraphicsAPI::getDeviceContext()
  {
    return m_deviceContext;
  }

  RenderTargetView * DXGraphicsAPI::getRenderTargetView()
  {
    return m_renderTargetView;
  }

  VertexBuffer * DXGraphicsAPI::getVertexBuffer()
  {
    return m_vertexBuffer;
  }

  void DXGraphicsAPI::destroy()
  {
    m_swapChain->getSwapChain()->SetFullscreenState(FALSE, NULL);

    m_inputLayout->getInputLayout()->Release();
    m_pixelShader->getPixelShader()->Release();
    m_vertexShader->getVertexShader()->Release();
    m_renderTargetView->getRenderTargetView()->Release();
    m_swapChain->getSwapChain()->Release();
    m_deviceContext->getDeviceContext()->Release();
    m_device->getDevice()->Release();

  }
}