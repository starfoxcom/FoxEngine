#include <vector>
#include <fstream>
#include <iostream>
  
#include "foxDXGraphicsAPI.h"
#include "foxRenderWindow.h"
#include "foxSwapChain.h"
#include "foxDevice.h"
#include "foxDeviceContext.h"
#include "foxTexture.h"
#include "foxRenderTargetView.h"
#include "foxVertexShader.h"

namespace foxEngineSDK
{

  DXGraphicsAPI::DXGraphicsAPI()
  {

    m_renderWindow = new RenderWindow();
    m_swapChain = new SwapChain();
    m_device = new Device();
    m_deviceContext = new DeviceContext();
    m_texture = new Texture();
    m_renderTargetView = new RenderTargetView();
    m_vertexShader = new VertexShader();
  }

  DXGraphicsAPI::~DXGraphicsAPI()
  {
    delete m_renderWindow;
    delete m_swapChain;
    delete m_device;
    delete m_deviceContext;
    delete m_renderTargetView;
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

  bool DXGraphicsAPI::initDevice()
  {

    RECT rect;
    
    GetClientRect(m_renderWindow->getWindowHandle(), &rect);
    
    uint32 width = rect.right - rect.left;
    uint32 height = rect.bottom - rect.top;

    D3D_FEATURE_LEVEL featureLevels[] =
    {
      D3D_FEATURE_LEVEL_11_0,
      D3D_FEATURE_LEVEL_10_1,
      D3D_FEATURE_LEVEL_10_0,
    };

    uint32 numFeatureLevels = ARRAYSIZE(featureLevels);

    setSwapChainDesc();

    if (FAILED(D3D11CreateDeviceAndSwapChain(
      NULL,
      D3D_DRIVER_TYPE_HARDWARE,
      NULL,
      0,
      featureLevels, numFeatureLevels,
      D3D11_SDK_VERSION,
      m_swapChain->getSwapChainDesc(),
      m_swapChain->getSwapChainRef(),
      m_device->getDeviceRef(),
      NULL,
      m_deviceContext->getDeviceContextRef())))
    {
      Log(Log::LOGERROR, true) << "Failed to create Device and Swap Chain";
      return false;
    }
    else
    {
      Log() << "Device and Swap Chain created successfully";
    }

    //TODO: Create Texture class

    if (FAILED(m_swapChain->getSwapChain()->GetBuffer(
      0,
      __uuidof(ID3D11Texture2D),
      (LPVOID*)m_texture->getTextureRef())))
    {
      Log(Log::LOGERROR, true) << "Failed to retrieve buffer";
      return false;
    }
    else
    {
      Log() << "Retrieved buffer successfully";
    }

    if (FAILED(m_device->getDevice()->CreateRenderTargetView(
      m_texture->getTexture(),
      NULL,
      m_renderTargetView->getRenderTargetViewRef())))
    {
      Log(Log::LOGERROR, true) << "Failed to create Render Target View";
      return false;
    }
    else
    {
      Log() << "Created Render Target View successfully";
    }

    m_texture->getTexture()->Release();

    m_deviceContext->getDeviceContext()->OMSetRenderTargets(
      1,
      m_renderTargetView->getRenderTargetViewRef(),
      NULL);

    //TODO: Create Viewport class
    D3D11_VIEWPORT viewPort;
    
    viewPort.Width = static_cast<float>(width);
    viewPort.Height = static_cast<float>(height);
    viewPort.MinDepth = 0.0f;
    viewPort.MaxDepth = 1.0f;
    viewPort.TopLeftX = 0;
    viewPort.TopLeftY = 0;

    m_deviceContext->getDeviceContext()->RSSetViewports(1, &viewPort);



    return true;
  }

  bool DXGraphicsAPI::createVertexShader(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {
    m_vertexShader->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);
    return m_device->createVertexShader(m_vertexShader);
  }

  void DXGraphicsAPI::cleanupDevice()
  {

    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->ClearState();

    if (m_renderTargetView->getRenderTargetView()) m_renderTargetView->getRenderTargetView()->Release();
    if (m_swapChain->getSwapChain()) m_swapChain->getSwapChain()->Release();
    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->Release();
    if (m_device->getDevice()) m_device->getDevice()->Release();
  }

  void DXGraphicsAPI::render()
  {

    float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };

    m_deviceContext->getDeviceContext()->ClearRenderTargetView(m_renderTargetView->getRenderTargetView(), clearColor);

    m_swapChain->getSwapChain()->Present(0, 0);
  }

  void DXGraphicsAPI::setSwapChainDesc(
    uint32 _bufferCount,
    uint32 _numerator,
    uint32 _denominator,
    uint32 _sampleCount,
    uint32 _sampleQuality,
    bool _windowed)
  {
    m_swapChain->setSwapChainDesc(
      m_renderWindow->getWindowHandle(),
      _bufferCount,
      _numerator,
      _denominator,
      _sampleCount,
      _sampleQuality,
      _windowed);
  }
  
}