/**
 * Includes
 */
#include "foxLog.h"
#include "foxCoreBaseApp.h"

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


using createGraphicsAPI = void*(*)();

BaseApp::BaseApp()
{

}

BaseApp::~BaseApp()
{

  ImGui_ImplDX11_Shutdown();
  ImGui_ImplWin32_Shutdown();
  ImGui::DestroyContext();
}

bool BaseApp::run()
{

  Log::Log(Log::LOGINFO, true) << "Application start";

  int32 width = 640;
  int32 height = 480;

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

    if (!ImGui_ImplDX11_Init(
      static_cast<ID3D11Device*>(m_graphicsAPI->instance().getDevice()),
      static_cast<ID3D11DeviceContext*>(m_graphicsAPI->instance().getDeviceContext())))
    {

      Log(Log::LOGERROR, true) << "Imgui couldn't be initialized.";
    }

    else
    {

      Log(Log::LOGINFO, true) << "Imgui Initialized successfully.";
    }
  }

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

}

void BaseApp::render()
{

  //Create and set the clear color
  float clearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f };

  //Clear the Render Target View with the specified color
  m_graphicsAPI->instance().clearRenderTargetView(clearColor);

  //Clear the Depth Stencil View
  m_graphicsAPI->instance().clearDepthStencilView();


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

  //Imgui Rendering
  ImGui::Render();
  ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

  //Present the new frame
  m_graphicsAPI->instance().present();

}

void BaseApp::loadLibrary(String _dllName, String _dllMethod)
{

  HINSTANCE hinstLib;
  createGraphicsAPI ProcAdd;
  BOOL fFreeResult, fRunTimeLinkSuccess = FALSE;
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
    }
    // Free the DLL module.

    //fFreeResult = FreeLibrary(hinstLib);
  }

  // If unable to call the DLL function, use an alternative.
  if (!fRunTimeLinkSuccess)
    Log() << "Message printed from executable.";
}
