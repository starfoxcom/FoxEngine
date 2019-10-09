#include "Application.h"
#include "foxLog.h"



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

  //Initialize the graphicsAPI
  m_graphicsAPI.initDXGraphicsAPI();

  //Add Input Elements for the input layout
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
    12,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  //Wait for the next message in the queue, store the result in msg
  while (m_graphicsAPI.processMessages() == true)
  {

    //Update logic

    //Render
    render();

  }

  //Clean up the Graphics API
  m_graphicsAPI.cleanUpDXGraphicsAPI();

  return m_graphicsAPI.processMessages();
}

void BaseApp::update()
{
}

void BaseApp::render()
{

  //Create and set the clear color
  float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
  
  //Clear the Render Target View with the specified color
  m_graphicsAPI.clearRenderTargetView(clearColor);

  //Clear the Depth Stencil View
  m_graphicsAPI.clearDepthStencilView();

  //Present the new frame
  m_graphicsAPI.present();
}

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{
}