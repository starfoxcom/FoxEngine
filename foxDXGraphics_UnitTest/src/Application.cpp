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