#pragma once
/**
* Includes
*/
#include <windowsx.h>
#include <windows.h>
#include "foxDXGraphicsAPI.h"
#include "RenderWindow.h"
#include "foxMatrix4.h"



using namespace foxEngineSDK;

/**
 * Forward Declarations
 */

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

  Matrix4 m_world;
  Matrix4 m_view;
  Matrix4 m_projection;

  int32 m_RSValue = 1;

  struct constantBuffer
  {
    Matrix4 world;
    Matrix4 view;
    Matrix4 projection;
  };

};