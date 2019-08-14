#include <vector>
#include <fstream>
#include <iostream>
  
#include "foxDXGraphicsAPI.h"
#include "foxDXRenderWindow.h"
#include "foxDXSwapChain.h"
#include "foxDXDevice.h"
#include "foxDXDeviceContext.h"
#include "foxDXTexture.h"
#include "foxDXViewport.h"
#include "foxDXRenderTargetView.h"
#include "foxDXVertexShader.h"
#include "foxDXInputLayout.h"
#include "foxDXPixelShader.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXConstantBuffer.h"
#include "foxDXDepthStencilView.h"
#include "foxPlatformMath.h"

namespace foxEngineSDK
{

  DXGraphicsAPI::DXGraphicsAPI()
  {

    m_renderWindow = new DXRenderWindow();
    m_swapChain = new DXSwapChain();
    m_device = new DXDevice();
    m_deviceContext = new DXDeviceContext();
    m_backBuffer = new DXTexture();
    m_depthStencil = new DXTexture();
    m_depthStencilView = new DXDepthStencilVew();
    m_viewport = new DXViewport();
    m_renderTargetView = new DXRenderTargetView();
    m_vertexShader = new DXVertexShader();
    m_inputLayout = new DXInputLayout();
    m_vertexBuffer = new DXVertexBuffer();
    m_indexBuffer = new DXIndexBuffer();
    m_constantBuffer = new DXConstantBuffer();
  }

  DXGraphicsAPI::~DXGraphicsAPI()
  {
    delete m_renderWindow;
    delete m_swapChain;
    delete m_device;
    delete m_deviceContext;
    delete m_backBuffer;
    delete m_depthStencil;
    delete m_depthStencilView;
    delete m_viewport;
    delete m_renderTargetView;
    delete m_vertexShader;
    delete m_inputLayout;
    delete m_vertexBuffer;
    delete m_indexBuffer;
    delete m_constantBuffer;
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

    setSwapChainDesc(width, height);

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

    if (FAILED(m_swapChain->getSwapChain()->GetBuffer(
      0,
      __uuidof(ID3D11Texture2D),
      (LPVOID*)m_backBuffer->getTextureRef())))
    {
      Log(Log::LOGERROR, true) << "Failed to retrieve buffer";
      return false;
    }
    else
    {
      Log() << "Retrieved buffer successfully";
    }

    //Need to create the createRenderTargetView Function
    if (FAILED(m_device->getDevice()->CreateRenderTargetView(
      m_backBuffer->getTexture(),
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

    m_backBuffer->getTexture()->Release();

    createTexture2D(width, height, FOX_BIND_FLAG::E::K_BIND_DEPTH_STENCIL);

    createDepthStencilView();

    m_deviceContext->getDeviceContext()->OMSetRenderTargets(
      1,
      m_renderTargetView->getRenderTargetViewRef(),
      m_depthStencilView->getDepthStencilView());

    initViewport(static_cast<float>(width), static_cast<float>(height));

    m_deviceContext->getDeviceContext()->RSSetViewports(1, m_viewport->getViewportRef());

    m_world.toIdentity();

    m_spin = m_orbit = m_translation = m_scalation = m_world;

    m_translation.translate(-4.0f, 0.5f, 0.0f);
    m_scalation.scale(0.3f, 0.3f, 0.3f);

    Vector4 eye(0.0f, 2.0f, -5.0f, 0.0f);
    Vector4 at(0.0f, 1.0f, 0.0f, 0.0f);
    Vector4 up(0.0f, 1.0f, 0.0f, 0.0f);
    
    m_view.toLookAt(eye, at, up);

    m_projection.toPerspectiveFOV(Math::HALF_PI, width / static_cast<float>(height), 0.01f, 100.0f);

    return true;
  }

  bool DXGraphicsAPI::createTexture2D(uint32 _width, uint32 _height, uint32 _bindFlag)
  {
    return m_device->createTexture2D(m_depthStencil, _width, _height, _bindFlag);
  }

  bool DXGraphicsAPI::createDepthStencilView()
  {
    return m_device->createDepthStencilView(m_depthStencil, m_depthStencilView);
  }

  void DXGraphicsAPI::initViewport(float _width, float _height)
  {
    m_viewport->initViewport(_width, _height);
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
      const char * _shaderModel,
    const uint32 _index)
  {
    m_pixelShaders.push_back(new DXPixelShader());
    m_pixelShaders[_index]->compileShaderFromFile(_fileName, _entryPoint, _shaderModel);
    return m_device->createPixelShader(m_pixelShaders[_index]);
  }

  bool DXGraphicsAPI::createVertexBuffer()
  {
    return m_device->createVertexBuffer(m_vertexBuffer);
  }

  bool DXGraphicsAPI::createIndexBuffer()
  {
    return m_device->createIndexBuffer(m_indexBuffer);
  }

  bool DXGraphicsAPI::createConstantBuffer()
  {
    return m_device->createConstantBuffer(m_constantBuffer);
  }

  void DXGraphicsAPI::addInputElement(
    const char * _semanticName,
    uint32 _semanticIndex,
    FOXGI_FORMAT::E _format,
    uint32 _inputSlot,
    uint32 _alignedByteOffset,
    FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
    uint32 _instanceDataSetpRate)
  {

    m_inputLayout->addElement(
      _semanticName,
      _semanticIndex,
      _format,
      _inputSlot,
      _alignedByteOffset,
      _inputSlotClass,
      _instanceDataSetpRate);

  }

  bool DXGraphicsAPI::createInputLayout()
  {
    return m_device->createInputLayout(m_inputLayout, m_vertexShader);
  }

  void DXGraphicsAPI::cleanupDevice()
  {

    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->ClearState();

    if (m_constantBuffer->getBuffer()) m_constantBuffer->getBuffer()->Release();
    if (m_vertexBuffer->getBuffer()) m_vertexBuffer->getBuffer()->Release();
    if (m_indexBuffer->getBuffer()) m_indexBuffer->getBuffer()->Release();
    if (m_inputLayout->getInputLayout()) m_inputLayout->getInputLayout()->Release();
    if (m_vertexShader->getVertexShader()) m_vertexShader->getVertexShader()->Release();
    for(int32 i = 0; i < m_pixelShaders.size(); ++i)
    if (m_pixelShaders[i]->getPixelShader()) m_pixelShaders[i]->getPixelShader()->Release();
    if (m_depthStencil->getTexture()) m_depthStencil->getTexture()->Release();
    if (m_depthStencilView->getDepthStencilView()) m_depthStencilView->getDepthStencilView()->Release();
    if (m_renderTargetView->getRenderTargetView()) m_renderTargetView->getRenderTargetView()->Release();
    if (m_swapChain->getSwapChain()) m_swapChain->getSwapChain()->Release();
    if (m_deviceContext->getDeviceContext()) m_deviceContext->getDeviceContext()->Release();
    if (m_device->getDevice()) m_device->getDevice()->Release();
  }

  void DXGraphicsAPI::render()
  {

    float t = 0.0f;
    t += Math::PI * 0.000125f;

    m_world.rotateInY(t);

    Vector4 vLightDirs[2] =
    {
        Vector4(-0.577f, 0.577f, -0.577f, 1.0f),
        Vector4(0.0f, 0.0f, -1.0f, 1.0f),
    };
    Vector4 vLightColors[2] =
    {
        Vector4(0.5f, 0.5f, 0.5f, 1.0f),
        Vector4(0.5f, 0.0f, 0.0f, 1.0f)
    };

    m_orbit.rotateInY(-t * -2.0f);

    vLightDirs[1] = m_orbit * vLightDirs[1];

    float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };

    clearRenderTargetView(clearColor);

    clearDepthStencilView();

    constantBuffer cb;

    cb.world = m_world.transposed();
    cb.view = m_view.transposed();
    cb.projection = m_projection.transposed();
    cb.lightDir[0] = vLightDirs[0];
    cb.lightDir[1] = vLightDirs[1];
    cb.lightColor[0] = vLightColors[0];
    cb.lightColor[1] = vLightColors[1];
    cb.outputColor = Vector4(0, 0, 0, 0);

    updateConstantBuffer(&cb);

    setVertexShader();

    setVSConstantBuffers();

    setPixelShader(0);

    setPSConstantBuffers();

    drawIndexed(36, 0, 0);

    for (int32 i = 0; i < 2; ++i)
    {
      Matrix4 light;
      light.toIdentity();
      light.translate(vLightDirs[i].x * 10, vLightDirs[i].y * 10, vLightDirs[i].z * 10);
      light.scale(0.2f, 0.2f, 0.2f);

      cb.world = light.transposed();
      cb.outputColor = vLightColors[i];

      updateConstantBuffer(&cb);

      setPixelShader(1);

      drawIndexed(36, 0, 0);
    }
    
    present();
  }

  void DXGraphicsAPI::clearRenderTargetView(float * _clearColor)
  {
    m_deviceContext->clearRenderTargetView(m_renderTargetView, _clearColor);
  }

  void DXGraphicsAPI::clearDepthStencilView()
  {
    m_deviceContext->clearDepthStencilView(m_depthStencilView);
  }

  void DXGraphicsAPI::updateConstantBuffer(const void * _data)
  {
    m_deviceContext->updateConstantBuffer(m_constantBuffer, _data);
  }

  void DXGraphicsAPI::setSwapChainDesc(
    uint32 _width,
    uint32 _height,
    uint32 _bufferCount,
    uint32 _numerator,
    uint32 _denominator,
    uint32 _sampleCount,
    uint32 _sampleQuality,
    bool _windowed)
  {
    m_swapChain->setSwapChainDesc(
      m_renderWindow->getWindowHandle(),
      _width,
      _height,
      _bufferCount,
      _numerator,
      _denominator,
      _sampleCount,
      _sampleQuality,
      _windowed);
  }

  void DXGraphicsAPI::setInputLayout()
  {
    m_deviceContext->setInputLayout(m_inputLayout);
  }

  void DXGraphicsAPI::setIAVertexBuffer(uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setIAVertexBuffers(m_vertexBuffer, _startSlot, _numOfBuffers);
  }

  void DXGraphicsAPI::setIAIndexBuffer(FOXGI_FORMAT::E _format, uint32 _offset)
  {
    m_deviceContext->setIAIndexBuffers(m_indexBuffer, _format, _offset);
  }

  void DXGraphicsAPI::setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->setIAPrimitiveTopology(_topology);
  }

  void DXGraphicsAPI::setVertexShader()
  {
    m_deviceContext->setVertexShader(m_vertexShader);
  }

  void DXGraphicsAPI::setVSConstantBuffers(uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setVSConstantBuffers(m_constantBuffer, _startSlot, _numOfBuffers);
  }

  void DXGraphicsAPI::setPSConstantBuffers(uint32 _startSlot, uint32 _numOfBuffers)
  {
    m_deviceContext->setPSConstantBuffers(m_constantBuffer, _startSlot, _numOfBuffers);
  }

  void DXGraphicsAPI::setPixelShader(const uint32 _index)
  {
    m_deviceContext->setPixelShader(m_pixelShaders[_index]);
  }

  void DXGraphicsAPI::draw(uint32 _vertexCount, uint32 _vertexStart)
  {
    m_deviceContext->draw(_vertexCount, _vertexStart);
  }

  void DXGraphicsAPI::drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart)
  {
    m_deviceContext->drawIndexed(_indexCount, _indexStart, _vertexStart);
  }

  void DXGraphicsAPI::present()
  {
    m_swapChain->present();
  }
  
}