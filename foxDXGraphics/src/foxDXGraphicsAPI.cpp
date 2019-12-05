/**
 * Includes
 */
#include <vector>
#include <fstream>
#include <iostream>

#include "foxLog.h"
#include "foxDXGraphicsAPI.h"
#include "foxDXSwapChain.h"
#include "foxDXDevice.h"
#include "foxDXDeviceContext.h"
#include "foxDXTexture.h"
#include "foxDXRenderTargetView.h"
#include "foxDXDepthStencilView.h"
#include "foxDXSolidRS.h"
#include "foxDXWireframeRS.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXConstantBuffer.h"
#include "foxDXShaderResourceView.h"
#include "foxDXSamplerState.h"

namespace foxEngineSDK
{

  foxDXGraphicsAPI::foxDXGraphicsAPI()
  {

    m_device = new foxDXDevice();
    m_deviceContext = new foxDXDeviceContext();
    m_swapChain = new foxDXSwapChain();
    m_renderTargetView = new foxDXRenderTargetView();
    m_depthStencilBuffer = new foxDXTexture();
    m_depthStencilView = new foxDXDepthStencilView();
    m_wireframeRS = new foxDXWireframeRS();
    m_solidRS = new foxDXSolidRS();
    m_vertexShader = new foxDXVertexShader();
    m_pixelShader = new foxDXPixelShader();
    m_inputLayout = new foxDXInputLayout();
    m_vertexBuffer = new foxDXVertexBuffer();
    m_indexBuffer = new foxDXIndexBuffer();
    m_constantBuffer = new foxDXConstantBuffer();
    m_diffuse = new foxDXTexture();
    m_shaderResourceView = new foxDXShaderResourceView();
    m_samplerState = new foxDXSamplerState();
  }

  foxDXGraphicsAPI::~foxDXGraphicsAPI()
  {
    delete m_device;
    delete m_deviceContext;
    delete m_swapChain;
    delete m_renderTargetView;
    delete m_depthStencilBuffer;
    delete m_depthStencilView;
    delete m_solidRS;
    delete m_wireframeRS;
    delete m_vertexShader;
    delete m_pixelShader;
    delete m_inputLayout;
    delete m_vertexBuffer;
    delete m_indexBuffer;
    delete m_constantBuffer;
    delete m_diffuse;
    delete m_shaderResourceView;
    delete m_samplerState;
  }

  bool foxDXGraphicsAPI::initGraphicsAPI(HWND _windowHandle)
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(_windowHandle, &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.bottom - windowRect.top;

    if (!createDeviceAndSwapChain(_windowHandle))
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API. [Device and Swap Chain].";
      return false;
    }

    if (!createRenderTargetView())
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API. [Render Target View].";
      return false;
    }

    if (!createDepthStencilView(_windowHandle))
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API. [Depth Stencil View].";
      return false;
    }

    if (!createSolidRS())
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API. [Solid Rasterizer state].";
      return false;
    }

    if (!createWireframeRS())
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API. [Wire frame Rasterizer state].";
      return false;
    }

    m_deviceContext->getDeviceContext()->OMSetRenderTargets(
      1,
      m_renderTargetView->getRenderTargetViewRef(),
      m_depthStencilView->getDepthStencilView());

    //Create and set the viewport
    D3D11_VIEWPORT vp;

    vp.Width = (FLOAT)width;
    vp.Height = (FLOAT)height;
    vp.MinDepth = 0.0f;
    vp.MaxDepth = 1.0f;
    vp.TopLeftX = 0;
    vp.TopLeftY = 0;
    m_deviceContext->getDeviceContext()->RSSetViewports(1, &vp);

    Log() << "Graphics API initialized successfully";

    foxGraphicsAPI::instance() = new foxDXGraphicsAPI
    return true;


  }

  void * foxDXGraphicsAPI::getDevice()
  {
    return m_device->getDevice();
  }

  void * foxDXGraphicsAPI::getDeviceContext()
  {
    return m_deviceContext->getDeviceContext();
  }

  void foxDXGraphicsAPI::addInputElement(
    const char * _semanticName,
    uint32 _semanticIndex,
    FOXGI_FORMAT::E _format,
    uint32 _inputSlot,
    uint32 _alignedByteOffset,
    FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
    uint32 _instanceDataStepRate)
  {

    m_inputLayout->addElement(
      _semanticName,
      _semanticIndex,
      _format,
      _inputSlot,
      _alignedByteOffset,
      _inputSlotClass,
      _instanceDataStepRate);
  }

  bool foxDXGraphicsAPI::createVertexShader(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {

    m_vertexShader->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);

    return m_device->createVertexShader(m_vertexShader);
  }

  bool foxDXGraphicsAPI::createPixelShader(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {

    m_pixelShader->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);

    return m_device->createPixelShader(m_pixelShader);
  }

  bool foxDXGraphicsAPI::createInputLayout()
  {
    return m_device->createInputLayout(m_inputLayout, m_vertexShader);
  }

  void foxDXGraphicsAPI::setInputLayout()
  {
    m_deviceContext->setInputLayout(m_inputLayout);
  }

  bool foxDXGraphicsAPI::createVertexBuffer(const void * _data, uint32 _dataSize)
  {
    return m_device->createVertexBuffer(m_vertexBuffer, _data, _dataSize);
  }

  void foxDXGraphicsAPI::setVertexBuffer(uint32 _structSize, uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setVertexBuffer(m_vertexBuffer, _startSlot, _numOfBuffers, _structSize);
  }

  bool foxDXGraphicsAPI::createIndexBuffer(const void * _data, uint32 _dataSize)
  {
    return m_device->createIndexBuffer(m_indexBuffer, _data, _dataSize);
  }

  void foxDXGraphicsAPI::setIndexBuffer(FOXGI_FORMAT::E _format, uint32 _offset)
  {
    m_deviceContext->setIndexBuffer(m_indexBuffer, _format, _offset);
  }

  void foxDXGraphicsAPI::setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->setPrimitiveTopology(_topology);
  }

  bool foxDXGraphicsAPI::createConstantBuffer(uint32 _structSize)
  {
    return m_device->createConstantBuffer(m_constantBuffer, _structSize);
  }

  bool foxDXGraphicsAPI::createShaderResourceViewFromFile(
    const void * _data,
    uint32 _width,
    uint32 _height)
  {

    D3D11_TEXTURE2D_DESC td;

    td.Width = _width;
    td.Height = _height;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    td.SampleDesc.Count = 1;
    td.SampleDesc.Quality = 0;
    td.Usage = D3D11_USAGE_DEFAULT;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    td.CPUAccessFlags = 0;
    td.MiscFlags = 0;

    D3D11_SUBRESOURCE_DATA initData;

    ZeroMemory(&initData, sizeof(initData));
    initData.pSysMem = _data;
    initData.SysMemPitch = _width * 4;


    if (FAILED(m_device->createTexture2D(&td, m_diffuse->getTextureRef(), &initData)))
    {

      Log(Log::LOGERROR, true) << "Failed to create Texture2D. [Shader Resource View]";
      return false;
    }

    Log() << "Created Texture2D successfully. [Shader Resource View]";

    return m_device->createShaderResourceView(m_diffuse, m_shaderResourceView);

  }

  bool foxDXGraphicsAPI::createSamplerState()
  {
    return m_device->createSamplerState(m_samplerState);
  }

  void foxDXGraphicsAPI::updateConstantBuffer(const void * _data)
  {
    m_deviceContext->updateConstantBuffer(m_constantBuffer, _data);
  }

  void foxDXGraphicsAPI::clearRenderTargetView(float * _RGBAColor)
  {
    m_deviceContext->clearRenderTargetView(m_renderTargetView, _RGBAColor);
  }

  void foxDXGraphicsAPI::clearDepthStencilView()
  {
    m_deviceContext->clearDepthStencilView(m_depthStencilView);
  }

  void foxDXGraphicsAPI::setVertexShader()
  {
    m_deviceContext->setVertexShader(m_vertexShader);
  }

  void foxDXGraphicsAPI::setVSConstantBuffers(uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setVSConstantBuffers(m_constantBuffer, _startSlot, _numOfBuffers);
  }

  void foxDXGraphicsAPI::setPSConstantBuffers(uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setPSConstantBuffers(m_constantBuffer, _startSlot, _numOfBuffers);
  }

  void foxDXGraphicsAPI::setShaderResources(uint32 _startSlot, uint32 _numOfViews)
  {
    m_deviceContext->setShaderResources(m_shaderResourceView, _startSlot, _numOfViews);
  }

  void foxDXGraphicsAPI::setPixelShader()
  {
    m_deviceContext->setPixelShader(m_pixelShader);
  }

  void foxDXGraphicsAPI::setSolidRS()
  {
    m_deviceContext->setRasterizerState(m_solidRS);
  }

  void foxDXGraphicsAPI::setWireframeRS()
  {
    m_deviceContext->setRasterizerState(m_wireframeRS);
  }

  void foxDXGraphicsAPI::setPSSamplerState(uint32 _startSlot, uint32 _numOfSamplers)
  {
    m_deviceContext->setPSSamplerState(m_samplerState, _startSlot, _numOfSamplers);
  }

  void foxDXGraphicsAPI::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->draw(_vertexCount, _vertexStart);
  }

  void foxDXGraphicsAPI::drawIndexed(uint32 _indexCount, uint32 _vertexStart, uint32 _indexStart)
  {
    m_deviceContext->drawIndexed(_indexCount, _vertexStart, _indexStart);
  }

  void foxDXGraphicsAPI::present()
  {
    m_swapChain->present();
  }

  bool foxDXGraphicsAPI::createDeviceAndSwapChain(HWND _windowHandle)
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(_windowHandle, &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.bottom - windowRect.top;

    //Create and set the device flags variable
    uint32 createDeviceFlags = 0;

    //On debug enabled
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // _DEBUG

    //Create and set the feature levels
    D3D_FEATURE_LEVEL featureLevels[] =
    {
      D3D_FEATURE_LEVEL_11_0,
      D3D_FEATURE_LEVEL_10_1,
      D3D_FEATURE_LEVEL_10_0,
    };

    //Create and set the number of feature levels
    uint32 numFeatureLevels = ARRAYSIZE(featureLevels);

    //Create and set the Swap Chain Desc
    DXGI_SWAP_CHAIN_DESC scd;

    ZeroMemory(&scd, sizeof(scd));

    scd.BufferDesc.Width = width;
    scd.BufferDesc.Height = height;
    scd.BufferDesc.RefreshRate.Numerator = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
    scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
    scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
    scd.SampleDesc.Count = 1;
    scd.SampleDesc.Quality = 0;
    scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.BufferCount = 1;
    scd.OutputWindow = _windowHandle;
    scd.Windowed = true;
    scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
    scd.Flags = 0;

    //Create Device and Swap Chain
    if (FAILED(D3D11CreateDeviceAndSwapChain(
      NULL,
      D3D_DRIVER_TYPE_HARDWARE,
      NULL,
      0,
      featureLevels, numFeatureLevels,
      D3D11_SDK_VERSION,
      &scd,
      m_swapChain->getSwapChainRef(),
      m_device->getDeviceRef(),
      NULL,
      m_deviceContext->getDeviceContextRef())))
    {
      Log(Log::LOGERROR, true) << "Failed to create Device and Swap Chain.";
      return false;
    }
    else
    {
      Log() << "Device and Swap Chain created successfully.";
      return true;
    }
  }

  bool foxDXGraphicsAPI::createRenderTargetView()
  {

    //Create the back buffer
    ID3D11Texture2D * backBuffer;

    //Retrieve the Swap Chain buffer
    if (FAILED(m_swapChain->getSwapChain()->GetBuffer(
      0,
      __uuidof(ID3D11Texture2D),
      (LPVOID *)&backBuffer)))
    {

      Log(Log::LOGERROR, true) << "Failed to retrieve Swap Chain Buffer.";
      return false;
    }

    else
    {

      Log() << "Retrieved Swap Chain Buffer successfully.";
    }

    //Create the Render Target View
    if (FAILED(m_device->createRenderTargetView(
      backBuffer,
      m_renderTargetView->getRenderTargetViewRef())))
    {

      Log(Log::LOGERROR, true) << "Failed to create Render Target View.";
      return false;
    }
    else
    {

      Log() << "Created Render Target View successfully.";

      //Release the buffer
      backBuffer->Release();
      return true;
    }
  }

  bool foxDXGraphicsAPI::createDepthStencilView(HWND _windowHandle)
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(_windowHandle, &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.bottom - windowRect.top;

    //Create and set the Depth Stencil Desc
    D3D11_TEXTURE2D_DESC dsd;

    dsd.Width = width;
    dsd.Height = height;
    dsd.MipLevels = 1;
    dsd.ArraySize = 1;
    dsd.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
    dsd.SampleDesc.Count = 1;
    dsd.SampleDesc.Quality = 0;
    dsd.Usage = D3D11_USAGE_DEFAULT;
    dsd.BindFlags = D3D11_BIND_DEPTH_STENCIL;
    dsd.CPUAccessFlags = 0;
    dsd.MiscFlags = 0;

    if (FAILED(m_device->createTexture2D(&dsd, m_depthStencilBuffer->getTextureRef())))
    {

      Log(Log::LOGERROR, true) << "Failed to create Texture2D.";
      return false;
    }

    else
    {

      Log() << "Created Texture2D successfully.";
    }

    D3D11_DEPTH_STENCIL_VIEW_DESC dsvd;

    ZeroMemory(&dsvd, sizeof(dsvd));
    dsvd.Format = dsd.Format;
    dsvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
    dsvd.Texture2D.MipSlice = 0;

    if (FAILED(m_device->createDepthStencilView(
      m_depthStencilBuffer->getTexture(),
      m_depthStencilView->getDepthStencilViewRef(),
      &dsvd)))
    {

      Log(Log::LOGERROR, true) << "Failed to create Depth Stencil View.";
      return false;
    }

    else
    {

      Log() << "Created Depth Stencil View successfully.";
      return true;
    }
  }

  bool foxDXGraphicsAPI::createSolidRS()
  {

    D3D11_RASTERIZER_DESC m_rasterizerDesc;

    ZeroMemory(&m_rasterizerDesc, sizeof(m_rasterizerDesc));

    m_rasterizerDesc.FillMode = D3D11_FILL_SOLID;
    m_rasterizerDesc.CullMode = D3D11_CULL_BACK;
    m_rasterizerDesc.FrontCounterClockwise = false;
    m_rasterizerDesc.DepthBias = 0;
    m_rasterizerDesc.DepthBiasClamp = 0.0f;
    m_rasterizerDesc.SlopeScaledDepthBias = 0.0f;
    m_rasterizerDesc.DepthClipEnable = true;
    m_rasterizerDesc.ScissorEnable = false;
    m_rasterizerDesc.MultisampleEnable = false;
    m_rasterizerDesc.AntialiasedLineEnable = false;

    if (FAILED(m_device->createRasterizerState(m_solidRS, m_rasterizerDesc)))
    {

      Log(Log::LOGERROR, true) << "Failed to create Solid Rasterizer state.";
      return false;
    }

    Log() << "Created Solid Rasterizer state successfully.";
    return true;
  }

  bool foxDXGraphicsAPI::createWireframeRS()
  {

    D3D11_RASTERIZER_DESC m_rasterizerDesc;

    ZeroMemory(&m_rasterizerDesc, sizeof(m_rasterizerDesc));

    m_rasterizerDesc.FillMode = D3D11_FILL_WIREFRAME;
    m_rasterizerDesc.CullMode = D3D11_CULL_NONE;
    m_rasterizerDesc.FrontCounterClockwise = false;
    m_rasterizerDesc.DepthBias = 0;
    m_rasterizerDesc.DepthBiasClamp = 0.0f;
    m_rasterizerDesc.SlopeScaledDepthBias = 0.0f;
    m_rasterizerDesc.DepthClipEnable = true;
    m_rasterizerDesc.ScissorEnable = false;
    m_rasterizerDesc.MultisampleEnable = false;
    m_rasterizerDesc.AntialiasedLineEnable = false;

    if (FAILED(m_device->createRasterizerState(m_wireframeRS, m_rasterizerDesc)))
    {

      Log(Log::LOGERROR, true) << "Failed to create Wire frame Rasterizer state.";
      return false;
    }

    Log() << "Created Wire frame Rasterizer state successfully.";
    return true;
  }

}