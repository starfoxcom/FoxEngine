/**
 * Includes
 */
#include "foxLog.h"
#include "foxCoreBaseApp.h"

#include "foxVector2.h"
#include "foxVector3.h"
#include "foxVector4.h"
#include "foxPlatformMath.h"

#include "foxCoreModel.h"

#include "externals/imgui.h"
#include "externals/imgui_impl_win32.h"
#include "externals/imgui_impl_dx11.h"
#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

#define STB_IMAGE_IMPLEMENTATION
#include "externals/stb_image.h"


using createGraphicsAPI = void*(*)();

namespace foxEngineSDK
{


  foxBaseApp::foxBaseApp()
  {
    m_model = new foxModel();
  }

  foxBaseApp::~foxBaseApp()
  {

    delete m_model;
    ImGui_ImplDX11_Shutdown();
    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
  }

  bool foxBaseApp::run()
  {

    Log::Log(Log::LOGINFO, true) << "Application start";

    int32 width = 1280;
    int32 height = 720;

    //Init window
    if (!m_renderWindow.initWindow(
      GetModuleHandle(NULL),
      "Window Class 1",
      "Fox Engine",
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

    String dllName = "foxDXGraphics";

    String dllMethod = "createObject";

    //Load the Graphics API dll
    loadLibrary(dllName, dllMethod);

    //Check if the instance is started up
    if (m_graphicsAPI->instance().isStarted())
    {

      Log(Log::LOGINFO, true) << "instance is started up.";
    }
    else
    {

      Log(Log::LOGERROR, true) << "Instance is not started up.";
    }

    //Initialize the graphics API
    m_graphicsAPI->instance().initGraphicsAPI(m_renderWindow.getWindowHandle());

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

      if (!ImGui_ImplDX11_Init(m_graphicsAPI->instance().getDevice(),
        m_graphicsAPI->instance().getDeviceContext()))
      {

        Log(Log::LOGERROR, true) << "Imgui couldn't be initialized.";
      }

      else
      {

        Log(Log::LOGINFO, true) << "Imgui Initialized successfully.";
      }
    }

    //Create vertex shader
    m_graphicsAPI->instance().createVertexShader("shaders.shader", "VS", "vs_4_0");

    //Add Input Elements for the input layout
    m_graphicsAPI->instance().addInputElement(
      "POSITION",
      0,
      FOXGI_FORMAT::E::K_R32G32B32_FLOAT,
      0,
      0,
      FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
      0);

    m_graphicsAPI->instance().addInputElement(
      "TEXCOORD",
      0,
      FOXGI_FORMAT::E::K_R32G32_FLOAT,
      0,
      12,
      FOX_INPUT_CLASSIFICATION::E::K_INPUT_PER_VERTEX_DATA,
      0);

    //Create pixel shader
    m_graphicsAPI->instance().createPixelShader("shaders.shader", "PS", "ps_4_0");

    //Create the input layout
    m_graphicsAPI->instance().createInputLayout();

    //Set the input layout
    m_graphicsAPI->instance().setInputLayout();

    //Set primitive topology
    m_graphicsAPI->instance().setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E::K_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

    //Create and set the constant struct size, in bytes
    uint32 constantStructSize = sizeof(constantBuffer);

    //Create constant buffer
    m_graphicsAPI->instance().createConstantBuffer(constantStructSize);

    //Create sampler state
    m_graphicsAPI->instance().createSamplerState();

    //Set the world matrix to a identity matrix
    m_world.toIdentity();

    //Create and set the eye, target and up vectors
    m_eye = Vector4(0.0f, 5.0f, -5.0f, 0.0f);
    m_at = Vector4(0.0f, 1.0f, 0.0f, 0.0f);
    m_up = Vector4(0.0f, 1.0f, 0.0f, 0.0f);
    //Set the view matrix to look at matrix
    m_view.toLookAt(m_eye, m_at, m_up);

    //Set the projection matrix to a perspective field of view matrix
    m_projection.toPerspectiveFOV(Math::HALF_PI, width / static_cast<float>(height), 0.01f, 1000.0f);

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

  void foxBaseApp::update()
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
    m_graphicsAPI->instance().updateConstantBuffer(&cb);
  }

  void foxBaseApp::render()
  {

    //Create and set the clear color
    float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };

    //Clear the Render Target View with the specified color
    m_graphicsAPI->instance().clearRenderTargetView(clearColor);

    //Clear the Depth Stencil View
    m_graphicsAPI->instance().clearDepthStencilView();

    //Set the Vertex Shader
    m_graphicsAPI->instance().setVertexShader();

    //Set the Vertex Constant Buffer
    m_graphicsAPI->instance().setVSConstantBuffers();

    //Set the Pixel Shader
    m_graphicsAPI->instance().setPixelShader();

    //Set the Pixel Constant Buffer
    m_graphicsAPI->instance().setPSConstantBuffers();

    //Set the Rasterizer State
    switch (m_RSValue)
    {
    case 1:
      m_graphicsAPI->instance().setSolidRS();
      break;
    case 2:
      m_graphicsAPI->instance().setWireframeRS();
      break;
    }

    //Set the Pixel Sampler
    m_graphicsAPI->instance().setPSSamplerState();

    //Draw
    //m_graphicsAPI.draw(3, 0);
    //m_graphicsAPI->instance().drawIndexed(36, 0, 0);
    m_model->draw();


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
      ImGui::SetWindowSize(ImVec2(150, 100));
      ImGui::BeginGroup();

      ImGui::RadioButton("Solid", &m_RSValue, 1);
      ImGui::RadioButton("Wire frame", &m_RSValue, 2);

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
            m_model->loadModel(filename);

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
        ofn.lpstrFilter = "Any File\0*.*\0";
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

            m_graphicsAPI->instance().createShaderResourceViewFromFile(image, width, height);

            stbi_image_free(image);

            m_graphicsAPI->instance().setShaderResources();

          }
        }
        else
        {
          Log(Log::LOGERROR, true) << "File couldn't be loaded.";
        }
      }
      ImGui::End();
    }

    //Hard coded Camera tool window
    {
      ImGui::Begin("Hard Coded View", 0, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_AlwaysAutoResize);
      ImGui::DragFloat3("Eye", &m_eye[0], 0.01f);

      ImGui::DragFloat3("At", &m_at[0], 0.01f);
      
      ImGui::DragFloat3("Up", &m_up[0], 0.01f);

      m_view.toLookAt(m_eye, m_at, m_up);


      ImGui::End();
    }
    //Imgui Rendering
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

    //Present the new frame
    m_graphicsAPI->instance().present();

  }

  void foxBaseApp::loadLibrary(String _dllName, String _dllMethod)
  {

    HINSTANCE hinstLib;
    createGraphicsAPI ProcAdd;
    BOOL freeResult, fRunTimeLinkSuccess = FALSE;
    // Get a handle to the DLL module.
#if _DEBUG

    _dllName += "d.dll";
#else

    _dllName += ".dll";
#endif // _DEBUG

    hinstLib = LoadLibrary(_dllName.c_str());

    // If the handle is valid, try to get the function address.

    if (hinstLib != nullptr)
    {
      ProcAdd = (createGraphicsAPI)GetProcAddress(hinstLib, _dllMethod.c_str());

      // If the function address is valid, call the function.

      if (nullptr != ProcAdd)
      {
        fRunTimeLinkSuccess = TRUE;
        ProcAdd();

        Log() << "dll loaded successfully.";
      }
      else
      {
        Log(Log::LOGERROR, true) << "Error loading that shit.";
      // Free the DLL module.

      freeResult = FreeLibrary(hinstLib);
      }
    }

    // If unable to call the DLL function, use an alternative.
    if (!fRunTimeLinkSuccess)
      Log() << "Message printed from executable.";
  }
}
