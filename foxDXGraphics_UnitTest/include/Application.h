#pragma once
/**
* Includes
*/
#include <windowsx.h>
#include <windows.h>
#include "foxDXGraphicsAPI.h"
#include "RenderWindow.h"



using namespace foxEngineSDK;

class BaseApp
{
public:
  BaseApp();
  ~BaseApp();

  bool run();

  void update();

  void render();

private:

  DXGraphicsAPI m_graphicsAPI;
  
  RenderWindow m_renderWindow;

};