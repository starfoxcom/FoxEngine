/**
 * Includes
 */
#include <vector>
#include <fstream>
#include <iostream>

#include "foxLog.h"
#include "foxDXGraphicsAPI.h"
#include "foxDXRenderWindow.h"
#include "foxDXSwapChain.h"
#include "foxDXDevice.h"
#include "foxDXDeviceContext.h"
#include "foxDXTexture.h"
#include "foxDXRenderTargetView.h"
#include "foxDXDepthStencilView.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"

namespace foxEngineSDK
{

  DXGraphicsAPI::DXGraphicsAPI()
  {

    m_renderWindow = new DXRenderWindow();
    m_swapChain = new DXSwapChain();
    m_device = new DXDevice();
    m_deviceContext = new DXDeviceContext();
    m_renderTargetView = new DXRenderTargetView();
    //m_depthStencilBuffer = new DXTexture();
    //m_depthStencilView = new DXDepthStencilView();
    m_vertexShader = new DXVertexShader();
    m_pixelShader = new DXPixelShader();
    m_inputLayout = new DXInputLayout();
    m_vertexBuffer = new DXVertexBuffer();
    //m_indexBuffer = new DXIndexBuffer();
  }

  DXGraphicsAPI::~DXGraphicsAPI()
  {
    delete m_renderWindow;
    delete m_swapChain;
    delete m_device;
    delete m_deviceContext;
    delete m_renderTargetView;
    //delete m_depthStencilBuffer;
    //delete m_depthStencilView;
    delete m_vertexShader;
    delete m_pixelShader;
    delete m_inputLayout;
    delete m_vertexBuffer;
    //delete m_indexBuffer;
  }

  bool DXGraphicsAPI::initWindow(
    HINSTANCE _hInstance,
    std::string _windowClass,
    std::string _windowTitle,
    int32 _width,
    int32 _height)
  {
    return m_renderWindow->initialize(_hInstance, _windowClass, _windowTitle, _width, _height);
  }

  bool DXGraphicsAPI::processMessages()
  {
    return m_renderWindow->processMessages();
  }

  bool DXGraphicsAPI::initDXGraphicsAPI()
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(m_renderWindow->getWindowHandle(), &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.bottom - windowRect.top;

    if (!createDeviceAndSwapChain())
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API.";
      return false;
    }

    if (!createRenderTargetView())
    {
      Log(Log::LOGERROR, true) << "Failed to initialize the graphics API.";
      return false;
    }

    //if (!createDepthStencilView())
    //{
    //  Log(Log::LOGERROR, true) << "Failed to initialize the graphics API.";
    //  return false;
    //}

    m_deviceContext->getDeviceContext()->OMSetRenderTargets(
      1,
      m_renderTargetView->getRenderTargetViewRef(),
      NULL);

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
    return true;


  }

  ID3D11Device * DXGraphicsAPI::getDevice()
  {
    return m_device->getDevice();
  }

  ID3D11DeviceContext * DXGraphicsAPI::getDeviceContext()
  {
    return m_deviceContext->getDeviceContext();
  }

  void DXGraphicsAPI::addInputElement(
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

  bool DXGraphicsAPI::createVertexShader(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {

    m_vertexShader->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);

    return m_device->createVertexShader(m_vertexShader);
  }

  bool DXGraphicsAPI::createPixelShader(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {

    m_pixelShader->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);

    return m_device->createPixelShader(m_pixelShader);
  }

  bool DXGraphicsAPI::createInputLayout()
  {
    return m_device->createInputLayout(m_inputLayout, m_vertexShader);
  }

  void DXGraphicsAPI::setInputLayout()
  {
    m_deviceContext->setInputLayout(m_inputLayout);
  }

  bool DXGraphicsAPI::createVertexBuffer(const void * _data, uint32 _dataSize)
  {
    return m_device->createVertexBuffer(m_vertexBuffer, _data, _dataSize);
  }

  void DXGraphicsAPI::setVertexBuffer(uint32 _structSize, uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setVertexBuffer(m_vertexBuffer, _startSlot, _numOfBuffers, _structSize);
  }

  bool DXGraphicsAPI::createIndexBuffer(const void * _data, uint32 _dataSize, uint32 _length)
  {
    return m_device->createIndexBuffer(m_indexBuffer, _data, _dataSize, _length);
  }

  void DXGraphicsAPI::setIndexBuffer(FOXGI_FORMAT::E _format, uint32 _offset)
  {
    m_deviceContext->setIndexBuffer(m_indexBuffer, _format, _offset);
  }

  void DXGraphicsAPI::setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->setPrimitiveTopology(_topology);
  }

  void DXGraphicsAPI::clearRenderTargetView(float * _RGBAColor)
  {
    m_deviceContext->clearRenderTargetView(m_renderTargetView, _RGBAColor);
  }

  void DXGraphicsAPI::clearDepthStencilView()
  {
    m_deviceContext->clearDepthStencilView(m_depthStencilView);
  }

  void DXGraphicsAPI::setVertexShader()
  {
    m_deviceContext->setVertexShader(m_vertexShader);
  }

  void DXGraphicsAPI::setPixelShader()
  {
    m_deviceContext->setPixelShader(m_pixelShader);
  }

  void DXGraphicsAPI::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->draw(_vertexCount, _vertexStart);
  }

  void DXGraphicsAPI::drawIndexed(uint32 _indexCount, uint32 _vertexStart, uint32 _indexStart)
  {
    m_deviceContext->drawIndexed(_indexCount, _vertexStart, _indexStart);
  }

  void DXGraphicsAPI::present()
  {
    m_swapChain->present();
  }

  void DXGraphicsAPI::cleanUpDXGraphicsAPI()
  {

    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->ClearState();

    //if (m_indexBuffer->getBuffer()) m_indexBuffer->getBuffer()->Release();
    if (m_vertexBuffer->getBuffer()) m_vertexBuffer->getBuffer()->Release();
    if (m_inputLayout->getInputLayout()) m_inputLayout->getInputLayout()->Release();
    if (m_vertexShader->getVertexShader()) m_vertexShader->getVertexShader()->Release();
    //if (m_depthStencilBuffer->getTexture()) m_depthStencilBuffer->getTexture()->Release();
    //if (m_depthStencilView->getDepthStencilView()) m_depthStencilView->getDepthStencilView()->Release();
    if (m_renderTargetView->getRenderTargetView()) m_renderTargetView->getRenderTargetView()->Release();
    if (m_swapChain->getSwapChain()) m_swapChain->getSwapChain()->Release();
    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->Release();
    if (m_device->getDevice()) m_device->getDevice()->Release();
  }

  bool DXGraphicsAPI::createDeviceAndSwapChain()
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(m_renderWindow->getWindowHandle(), &windowRect);

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
    scd.OutputWindow = m_renderWindow->getWindowHandle();
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

  bool DXGraphicsAPI::createRenderTargetView()
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

  bool DXGraphicsAPI::createDepthStencilView()
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(m_renderWindow->getWindowHandle(), &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.top - windowRect.bottom;

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

    if (FAILED(m_device->createDepthStencilView(
      m_depthStencilBuffer->getTexture(),
      m_depthStencilView->getDepthStencilViewRef())))
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

}