#include "CoreApplication.h"
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

CoreBaseApp::CoreBaseApp()
{

  m_graphicsAPI->startUp<foxGraphicsAPI>();
}

CoreBaseApp::~CoreBaseApp()
{
}

bool CoreBaseApp::run()
{

  Log(Log::LOGINFO, true) << "Core Application Start.";

  int32 width = 640;
  int32 height = 480;

  //Init window
  if (!m_renderWindow.initWindow(
    GetModuleHandle(NULL),
    "Window Class 1",
    "Fox Core Engine Unit Test",
    width,
    height))
  {

    Log(Log::LOGERROR, true) << "Window couldn't init.";
    return false;
  }

  else
  {

    Log() << "Window initialized.";
  }

  //Initialize the graphics API
  m_graphicsAPI->initGraphicsAPI(m_renderWindow.getWindowHandle());

  while (m_renderWindow.processMessages() == true)
  {

    //Update logic


    //Render
  }

  //Returns the processed messages
  return m_renderWindow.processMessages();
}