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
  }

  DXGraphicsAPI::~DXGraphicsAPI()
  {
    delete m_renderWindow;
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
  
}