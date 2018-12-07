#pragma once
/**
* Includes
*/
#include <windowsx.h>
#include <windows.h>
#include "foxDXGraphicsAPI.h"

using namespace foxEngineSDK;

class BaseApp
{
public:
  BaseApp();
  ~BaseApp();

  int run();

  void render();

private:
  HWND m_windowHandler; /**< Windows handler */

  DXGraphicsAPI m_graphicsAPI;

};