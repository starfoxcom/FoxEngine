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
#include "foxDXRenderTargetView.h"

namespace foxEngineSDK
{

  DXGraphicsAPI::DXGraphicsAPI()
  {

    m_renderWindow = new DXRenderWindow();
    m_swapChain = new DXSwapChain();
    m_device = new DXDevice();
    m_deviceContext = new DXDeviceContext();
    m_renderTargetView = new DXRenderTargetView();
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

  bool DXGraphicsAPI::createDeviceAndSwapChain()
  {

    //Create window rect variable object
    RECT windowRect;

    //Get the actual window rect
    GetClientRect(m_renderWindow->getWindowHandle(), &windowRect);

    //Create and set the width and height from the obtained window rect
    uint32 width = windowRect.right - windowRect.left;
    uint32 height = windowRect.top - windowRect.bottom;

    //Create and set the device flags variable
    uint32 createDeviceFlags = 0;

    //On debug enabled
#ifdef _DEBUG
    createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif // DEBUG

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

}