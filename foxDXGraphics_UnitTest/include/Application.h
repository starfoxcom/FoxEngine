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

  bool run();

private:

  DXGraphicsAPI m_graphicsAPI;

};