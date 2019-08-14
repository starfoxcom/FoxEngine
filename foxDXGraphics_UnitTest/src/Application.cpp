#include "Application.h"



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


  m_graphicsAPI.createVertexShader("shaders.shader", "VS", "vs_4_0");

  m_graphicsAPI.addInputElement(
    "POSITION",
    0,
    FOXGI_FORMAT::E::K_R32G32B32_FLOAT,
    0,
    0,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);


  m_graphicsAPI.addInputElement(
    "NORMAL",
    0,
    FOXGI_FORMAT::E::K_R32G32B32A32_FLOAT,
    0,
    12,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  m_graphicsAPI.createInputLayout();

  m_graphicsAPI.setInputLayout();

  m_graphicsAPI.createPixelShader("shaders.shader", "PS", "ps_4_0", 0);

  m_graphicsAPI.createPixelShader("shaders.shader", "PSSolid", "ps_4_0", 1);

  //Here is where the model will be created, but for now a triangle is only what we have
  m_graphicsAPI.createVertexBuffer();

  m_graphicsAPI.setIAVertexBuffer();

  m_graphicsAPI.createIndexBuffer();

  m_graphicsAPI.setIAIndexBuffer(FOXGI_FORMAT::E::K_R32_UINT, 0);

  m_graphicsAPI.setIAPrimitiveTopology(
    FOX_PRIMITIVE_TOPOLOGY::E::K_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  m_graphicsAPI.createConstantBuffer();

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