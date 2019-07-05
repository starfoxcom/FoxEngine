#include "Application.h"
#include "foxDeviceContext.h"
#include "foxVertexBuffer.h"
#include "foxSwapChain.h"
#include "foxRenderTargetView.h"


bool BaseApp::run()
{
  Log::Log(Log::LOGINFO, true) << "Application start";

  //Init window
  if (!m_graphicsAPI.initWindow(
    GetModuleHandle(nullptr),
    "Window Class 1",
    "First window program",
    640,
    480))
  {
    Log(Log::LOGERROR, true) << "Window couldn't init.";
    return false;
  }
  else
  {
    Log() << "Window initialized";
  }

  if (!m_graphicsAPI.initDevice())
  {
    Log(Log::LOGERROR, true) << "Couldn't  init device";
    m_graphicsAPI.cleanupDevice();
    
    return false;
  }

  //Init Viewport


  m_graphicsAPI.createVertexShader("shaders.shader", "VSMain", "vs_4_0");

  m_graphicsAPI.addInputElement(
    "POSITION",
    0,
    FOXGI_FORMAT::E::K_R32G32B32_FLOAT,
    0,
    0,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  m_graphicsAPI.addInputElement(
    "COLOR",
    0,
    FOXGI_FORMAT::E::K_R32G32B32_FLOAT,
    0,
    16,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  m_graphicsAPI.createInputLayout();

  //Wait for the next message in the queue, store the result in msg
  while (m_graphicsAPI.processMessages() == true)
  {

    //Render 
    m_graphicsAPI.render();
  }

  m_graphicsAPI.cleanupDevice();

  return m_graphicsAPI.processMessages();
}

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{
}