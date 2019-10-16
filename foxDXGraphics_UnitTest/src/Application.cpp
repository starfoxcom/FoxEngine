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
  };

  struct vertex2
  {
    Vector3 pos;
    Vector4 color;
  };

  vertex vertices[]
  {
    Vector3(-1.0f, -1.0f, -1.0f),
    Vector3(-1.0f, +1.0f, -1.0f),
    Vector3(+1.0f, +1.0f, -1.0f),
    Vector3(+1.0f, -1.0f, -1.0f),
    Vector3(-1.0f, -1.0f, +1.0f),
    Vector3(-1.0f, +1.0f, +1.0f),
    Vector3(+1.0f, +1.0f, +1.0f),
    Vector3(+1.0f, -1.0f, +1.0f),
  };

  vertex vertices2[]
  {
    Vector3(0.0f, 0.5f, 0.0f),
    Vector3(0.5f, -0.5f, 0.0f),
    Vector3(-0.5f, -0.5f, 0.0f),
  };

  vertex2 vertices3[]
  {
    {Vector3( 0.0f,  0.5f, 0.0f),  Vector4( 1.0f,  0.0f, 0.0f, 1.0f)},
    {Vector3(-0.5f, -0.5f, 0.0f),  Vector4( 0.0f,  1.0f, 0.0f, 1.0f)},
    {Vector3( 0.5f, -0.5f, 0.0f),  Vector4( 0.0f,  0.0f, 1.0f, 1.0f)},
  };

  uint32 indices[]
  {
    0, 1, 2, // Triangle 0
    0, 2, 3, // Triangle 1
    0, 3, 4, // Triangle 2
    0, 4, 5, // Triangle 3
    0, 5, 6, // Triangle 4
    0, 6, 7, // Triangle 5
    0, 7, 8, // Triangle 6
    0, 8, 1  // Triangle 7
  };

  //Initialize the graphicsAPI
  m_graphicsAPI.initDXGraphicsAPI();

  //Create vertex shader
  m_graphicsAPI.createVertexShader("shaders.shader", "VS", "vs_4_0");

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
    FOXGI_FORMAT::E::K_R32G32B32A32_FLOAT,
    0,
    12,
    FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
    0);

  //Create pixel shader
  m_graphicsAPI.createPixelShader("shaders.shader", "PS", "ps_4_0");

  //Create the input layout
  m_graphicsAPI.createInputLayout();

  //Set the input layout
  m_graphicsAPI.setInputLayout();

  uint32 vertexDataSize = sizeof(vertices3);

  //Create the vertex buffer
  m_graphicsAPI.createVertexBuffer(vertices3 ,vertexDataSize);

  uint32 vertexStructSize = sizeof(vertex2);
  //Set the vertex buffer
  m_graphicsAPI.setVertexBuffer(vertexStructSize);

  uint32 indexDataSize = sizeof(indices);

  //Create the index buffer
  //m_graphicsAPI.createIndexBuffer(indices, indexDataSize, 24);
  
  //Set the index buffer
  //m_graphicsAPI.setIndexBuffer();

  //Set primitive topology
  m_graphicsAPI.setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E::K_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

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
  //m_graphicsAPI.clearDepthStencilView();

  //Set the Vertex Shader
  m_graphicsAPI.setVertexShader();

  //Set the Pixel Shader
  m_graphicsAPI.setPixelShader();

  //Draw
  m_graphicsAPI.draw(3, 0);

  //Present the new frame
  m_graphicsAPI.present();
}

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{
}