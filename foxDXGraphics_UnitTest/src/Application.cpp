#include "Application.h"
#include "foxLog.h"
#include "foxVector2.h"
#include "foxVector3.h"
#include "foxVector4.h"
#include "foxPlatformMath.h"
#include "externals/imgui.h"
#include "externals/imgui_impl_win32.h"
#include "externals/imgui_impl_dx11.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#define STB_IMAGE_IMPLEMENTATION
#include "externals/stb_image.h"



bool BaseApp::run()
{
  Log::Log(Log::LOGINFO, true) << "Application start";

  int32 width = 640;
  int32 height = 480;

  //Init window
  if (!m_renderWindow.initWindow(
    GetModuleHandle(NULL),
    "Window Class 1",
    "Fox Engine Unit Test",
    width,
    height))
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
    Vector2 tex;
  };

  struct vertex2
  {
    Vector3 pos;
    Vector4 color;
  };

  vertex2 colorCube[]
  {
    { Vector3(-1.0f, 1.0f, -1.0f), Vector4(0.0f, 0.0f, 1.0f, 1.0f) },
    { Vector3(1.0f, 1.0f, -1.0f),  Vector4(0.0f, 1.0f, 0.0f, 1.0f) },
    { Vector3(1.0f, 1.0f, 1.0f),   Vector4(0.0f, 1.0f, 1.0f, 1.0f) },
    { Vector3(-1.0f, 1.0f, 1.0f),  Vector4(1.0f, 0.0f, 0.0f, 1.0f) },
    { Vector3(-1.0f, -1.0f, -1.0f),Vector4(1.0f, 0.0f, 1.0f, 1.0f) },
    { Vector3(1.0f, -1.0f, -1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f) },
    { Vector3(1.0f, -1.0f, 1.0f),  Vector4(1.0f, 1.0f, 1.0f, 1.0f) },
    { Vector3(-1.0f, -1.0f, 1.0f), Vector4(0.0f, 0.0f, 0.0f, 1.0f) },
  };

  vertex textureCube[]
  {
    { Vector3(-1.0f, 1.0f, -1.0f),  Vector2(0.0f, 0.0f)  },
    { Vector3(1.0f, 1.0f, -1.0f),   Vector2(1.0f, 0.0f)  },
    { Vector3(1.0f, 1.0f, 1.0f),    Vector2(1.0f, 1.0f)  },
    { Vector3(-1.0f, 1.0f, 1.0f),   Vector2(0.0f, 1.0f)  },
    { Vector3(-1.0f, -1.0f, -1.0f), Vector2(0.0f, 0.0f)  },
    { Vector3(1.0f, -1.0f, -1.0f),  Vector2(1.0f, 0.0f)  },
    { Vector3(1.0f, -1.0f, 1.0f),   Vector2(1.0f, 1.0f)  },
    { Vector3(-1.0f, -1.0f, 1.0f),  Vector2(0.0f, 1.0f)  },
  };

  vertex2 triangle[]
  {
    {Vector3( 0.0f,  0.5f, 0.0f),  Vector4( 1.0f,  0.0f, 0.0f, 1.0f)},
    {Vector3( 0.5f, -0.5f, 0.0f),  Vector4( 0.0f,  0.0f, 1.0f, 1.0f)},
    {Vector3(-0.5f, -0.5f, 0.0f),  Vector4( 0.0f,  1.0f, 0.0f, 1.0f)},
  };

  uint32 indices[]
  {
   3,1,0,
   2,1,3,

   0,5,4,
   1,5,0,

   3,4,7,
   0,4,3,

   1,6,5,
   2,6,1,

   2,7,6,
   3,7,2,

   6,4,5,
   7,4,6,
  };

  //Initialize the graphicsAPI
  m_graphicsAPI.initDXGraphicsAPI(m_renderWindow.getWindowHandle());

  //Init Imgui
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;
  ImGui::StyleColorsDark();
  if (!ImGui_ImplWin32_Init(m_renderWindow.getWindowHandle()))
  {

    Log(Log::LOGERROR, true) << "Imgui couldn't be initialized.";
  }

  else
  {

    if (!ImGui_ImplDX11_Init(m_graphicsAPI.getDevice(), m_graphicsAPI.getDeviceContext()))
    {

      Log(Log::LOGERROR, true) << "Imgui couldn't be initialized.";
    }

    else
    {

      Log(Log::LOGINFO, true) << "Imgui Initialized successfully.";
    }
  }


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
    "TEXCOORD",
    0,
    FOXGI_FORMAT::E::K_R32G32_FLOAT,
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

  //Create and set the vertex data size, in bytes
  uint32 vertexDataSize = sizeof(textureCube);

  //Create the vertex buffer
  m_graphicsAPI.createVertexBuffer(textureCube ,vertexDataSize);

  //Create and set the vertex struct size, in bytes
  uint32 vertexStructSize = sizeof(vertex);
  
  //Set the vertex buffer
  m_graphicsAPI.setVertexBuffer(vertexStructSize);

  //Create and set the index data size, in bytes
  uint32 indexDataSize = sizeof(indices);

  //Create the index buffer
  m_graphicsAPI.createIndexBuffer(indices, indexDataSize);
  
  //Set the index buffer
  m_graphicsAPI.setIndexBuffer();

  //Set primitive topology
  m_graphicsAPI.setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E::K_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  //Create and set the constant struct size, in bytes
  uint32 constantStructSize = sizeof(constantBuffer);
  
  //Create constant buffer
  m_graphicsAPI.createConstantBuffer(constantStructSize);

  //Create sampler state
  m_graphicsAPI.createSamplerState();

  //Set the world matrix to a identity matrix
  m_world.toIdentity();

  //Create and set the eye, target and up vectors
  Vector4 eye(0.0f, 5.0f, -5.0f, 0.0f);
  Vector4 at(0.0f, 1.0f, 0.0f, 0.0f);
  Vector4 up(0.0f, 1.0f, 0.0f, 0.0f);

  //Set the view matrix to look at matrix
  m_view.toLookAt(eye, at, up);

  //Set the projection matrix to a perspective field of view matrix
  m_projection.toPerspectiveFOV(Math::HALF_PI, width / static_cast<float>(height), 0.01f, 100.0f);

  //Set the color of the mesh
  m_meshColor = Vector4(0.7f, 0.7f, 0.7f, 1.0f);


  //Wait for the next message in the queue, store the result in msg
  while (m_renderWindow.processMessages() == true)
  {

    //Update logic
    update();

    //Render
    render();

  }

  //Returns the processed messages
  return m_renderWindow.processMessages();
}

void BaseApp::update()
{

  //Create and set the delta time
  static float rotateValue = Math::PI * 0.000125f;

  //Rotate in Y the world matrix by the delta time
  m_world.rotateInY(rotateValue);

  //Create a constant buffer
  constantBuffer cb;

  //Set the world, view and projection constant buffer matrices with their respective transposed matrices
  cb.world = m_world.transposed();
  cb.view = m_view.transposed();
  cb.projection = m_projection.transposed();

  //Set the mesh color constant buffer
  cb.meshColor = m_meshColor;

  //Update the constant buffer data
  m_graphicsAPI.updateConstantBuffer(&cb);
}

void BaseApp::render()
{

  //Create and set the clear color
  float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };
  
  //Clear the Render Target View with the specified color
  m_graphicsAPI.clearRenderTargetView(clearColor);

  //Clear the Depth Stencil View
  m_graphicsAPI.clearDepthStencilView();

  //Set the Vertex Shader
  m_graphicsAPI.setVertexShader();

  //Set the Vertex Constant Buffer
  m_graphicsAPI.setVSConstantBuffers();

  //Set the Pixel Shader
  m_graphicsAPI.setPixelShader();

  //Set the Pixel Constant Buffer
  m_graphicsAPI.setPSConstantBuffers();

  //Set the Rasterizer State
  switch (m_RSValue)
  {
  case 1:
    m_graphicsAPI.setSolidRS();
    break;
  case 2:
    m_graphicsAPI.setWireframeRS();
    break;
  }

  //Set the Pixel Sampler
  m_graphicsAPI.setPSSamplerState();

  //Draw
  //m_graphicsAPI.draw(3, 0);
  m_graphicsAPI.drawIndexed(36, 0, 0);

  //Start the Dear ImGui frame
  ImGui_ImplDX11_NewFrame();
  ImGui_ImplWin32_NewFrame();
  ImGui::NewFrame();

  //Framerate window
  {
    ImGui::Begin("Framerate", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar);
    ImGui::SetWindowSize(ImVec2(200, 30));
    ImGui::SetWindowPos(ImVec2(2, 2));
    ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
  }

  //Rasterizer states window
  {
    ImGui::Begin("Rasterizer states", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);
    ImGui::SetWindowSize(ImVec2(150,100));
    ImGui::BeginGroup();

    ImGui::RadioButton("Solid",&m_RSValue, 1);
    ImGui::RadioButton("Wire frame",&m_RSValue, 2);

    ImGui::EndGroup();
    ImGui::End();
  }


  //Loading tool window
  {
    ImGui::Begin("Loading tool", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);

    //Load Model Button
    if (ImGui::Button("Load Model"))
    {
      char filename[MAX_PATH];

      bool bMustLoad = false;


      OPENFILENAME ofn;
      ZeroMemory(&filename, sizeof(filename));
      ZeroMemory(&ofn, sizeof(ofn));
      ofn.lStructSize = sizeof(ofn);
      ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
      ofn.lpstrFilter = "Any File\0*.*\0";
      ofn.lpstrFile = filename;
      ofn.nMaxFile = MAX_PATH;
      ofn.lpstrTitle = "Select a Model to load";
      ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
      if (GetOpenFileNameA(&ofn))
      {
        Log(Log::LOGINFO, true) << "You chose the file [" << filename << "]";
        if (filename > 0)
        {
          bMustLoad = true;
        }

        if (bMustLoad)
        {
          //Load Model with file
          Assimp::Importer importer;
          const auto model = importer.ReadFile(filename,
            aiProcess_CalcTangentSpace |
            aiProcess_Triangulate |
            aiProcess_JoinIdenticalVertices |
            aiProcess_SortByPType);

          //Here you call the load function from model class
          ///TODO: Model and Mesh Class

        }
      }
      else
      {
        Log(Log::LOGERROR, true) << "File couldn't be loaded.";
      }
    }

    //Load texture Button
    if (ImGui::Button("Load Texture"))
    {
      //Get file from dialog
      char filename[MAX_PATH];

      bool bMustLoad = false;

      OPENFILENAME ofn;
      ZeroMemory(&filename, sizeof(filename));
      ZeroMemory(&ofn, sizeof(ofn));
      ofn.lStructSize = sizeof(ofn);
      ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
      ofn.lpstrFilter = "JPG Files\0*.jpg\0PNG Files\0*.png\0Any File\0*.*\0";
      ofn.lpstrFile = filename;
      ofn.nMaxFile = MAX_PATH;
      ofn.lpstrTitle = "Select a Texture to load";
      ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;
      if (GetOpenFileNameA(&ofn))
      {
        Log(Log::LOGINFO, true) << "You chose the file [" << filename << "]";
        if (filename > 0)
        {
          bMustLoad = true;
        }

        if (bMustLoad)
        {
          //Load texture with image file
          int width, height, channels;

          auto * image = stbi_load(filename,
            &width,
            &height,
            &channels,
            STBI_rgb_alpha);

          Log(Log::LOGINFO, true) << "File loaded successfully.";

          m_graphicsAPI.createShaderResourceViewFromFile(image, width, height);

          stbi_image_free(image);

          m_graphicsAPI.setShaderResources();

        }
      }
      else
      {
        Log(Log::LOGERROR, true) << "File couldn't be loaded.";
      }
    }
    ImGui::End();
  }

  //Imgui Rendering
  ImGui::Render();
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

  //Present the new frame
  m_graphicsAPI.present();

}

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{

  ImGui_ImplDX11_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();
}