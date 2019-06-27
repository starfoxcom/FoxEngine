#pragma once

/**
* @file foxRenderWindow.h
* @author --
* @date ---
* @brief Implementation of render window.
*/

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class RenderWindow
  {

  public:
    bool initialize(
      HINSTANCE _hInstance,
      std::string _windowClass,
      std::string _windowTitle,
      int32 _width,
      int32 _height);

    bool processMessages();

    ~RenderWindow();

    HWND getWindowHandle();

  private:
    bool registerWindowClass();
    
    HWND m_windowHandle = NULL;
    HINSTANCE m_hInstance = NULL;
    std::string m_windowClass = "";
    std::string m_windowTitle = "";
    int32 m_width = 0;
    int32 m_height = 0;
  };
}