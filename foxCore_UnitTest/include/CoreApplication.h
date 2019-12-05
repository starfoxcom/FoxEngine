#pragma once
/**
 * @file CoreApplication.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/12/04
 * @brief unit test application for Core.
 */
#include <windowsx.h>
#include <windows.h>
#include "CoreRenderWindow.h"
#include "foxMatrix4.h"

using namespace foxEngineSDK;

/**
 * Forward Declarations
 */

class CoreBaseApp
{
public:
  CoreBaseApp();
  ~CoreBaseApp();

  bool run();

  void update();

  void render();

private:

  foxGraphicsAPI * m_graphicsAPI;

  CoreRenderWindow m_renderWindow;

};