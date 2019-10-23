#pragma once
/**
 * @file RenderWindow.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/16
 * @brief Implementation of render window.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxPrerequisitesUtilities.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace foxEngineSDK
{

  class RenderWindow
  {
  public:

    /**
     * @brief Default constructor.
     */
    RenderWindow();

    /**
     * @brief Default destructor.
     */
    ~RenderWindow();

    /**
     * @brief Initialize the Window.
     * @param _hInstance The instance of the application.
     * @param _windowClass The name of the window class.
     * @param _windowTitle The title of the window.
     * @param _width The width of the window.
     * @param _height The height of the window.
     */
    bool initWindow(
      HINSTANCE _hInstance,
      std::string _windowClass,
      std::string _windowTitle,
      int32 _width,
      int32 _height);

    /**
    * @brief Process the messages of the window.
    */
    bool processMessages();

    /**
     * @brief Gets the Window Handle.
     */
    HWND getWindowHandle();

  private:

    /**
     * @brief Registers the window class.
     */
    bool registerWindowClass();

    HWND m_windowHandle = NULL; /**< Window Handle variable.*/
    HINSTANCE m_hInstance = NULL; /**< Instance Handle variable.*/
    std::string m_windowClass = ""; /**< Window Class name variable.*/
    std::string m_windowTitle = ""; /**< Window Title name variable.*/
    int32 m_width = 0; /**< Window Width variable.*/
    int32 m_height = 0; /**< Window Height variable.*/
  };
}