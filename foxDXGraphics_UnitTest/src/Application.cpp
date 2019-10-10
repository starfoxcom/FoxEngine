#include "Application.h"
#include "foxLog.h"
#include "foxVector3.h"
#include "foxVector4.h"



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

  struct vertex
  {
    Vector3 pos;
    Vector4 color;
  };

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
    16,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  //Create vertex shader
  m_graphicsAPI.createVertexShader("shaders.shader", "VS", "vs_4_0");
  //Create pixel shader

  //Create the input layout

  //Create the vertex buffer

  //Set the vertex buffer

  //Create the index buffer

  //Set the index buffer

  //Set primitive topology

  //Create constant buffer



  //Wait for the next message in the queue, store the result in msg
  while (m_graphicsAPI.processMessages() == true)
  {

    //Update logic
    update();

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