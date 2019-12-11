/**
 * Includes
 */
#include "foxCoreRenderWindow.h"
#include "foxLog.h"
#include "externals/imgui.h"
#include "externals/imgui_impl_win32.h"
#include "externals/imgui_impl_dx11.h"

namespace foxEngineSDK
{

  CoreRenderWindow::CoreRenderWindow()
  {
  }

  CoreRenderWindow::~CoreRenderWindow()
  {
  }

  LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
  {

    if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
      return true;

    //Sort through and find what code to run for the message given
    switch (message)
    {
      //This message is read when the window is closed
    case WM_DESTROY:

      //Close the app entirely
      PostQuitMessage(0);
      return 0;
      break;
    }

    //Handle any messages the switch statement didn't
    return DefWindowProc(hWnd, message, wParam, lParam);
  }

  bool CoreRenderWindow::initWindow(
    HINSTANCE _hInstance,
    std::string _windowClass,
    std::string _windowTitle,
    int32 _width,
    int32 _height)
  {
    
    this->m_hInstance = _hInstance;
    this->m_windowClass = _windowClass;
    this->m_windowTitle = _windowTitle;
    this->m_width = _width;
    this->m_height = _height;

    this->registerWindowClass();

    this->m_windowHandle = CreateWindowEx(
      NULL,
      this->m_windowClass.c_str(),
      this->m_windowTitle.c_str(),
      WS_OVERLAPPEDWINDOW,
      0,
      0,
      this->m_width,
      this->m_height,
      NULL,
      NULL,
      this->m_hInstance,
      NULL);

    if (!this->m_windowHandle)
    {
      
      Log(Log::LOGERROR, true) << "Window Handle couldn't be created";
      return false;
    }

    //Display window on screen
    ShowWindow(m_windowHandle, SW_SHOW);

    return true;
  }

  bool CoreRenderWindow::processMessages()
  {
    
    MSG msg = { 0 };

    if (PeekMessage(&msg, this->m_windowHandle, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    if (msg.message == WM_NULL)
    {
      if (!IsWindow(this->m_windowHandle))
      {
        this->m_windowHandle = NULL;
        UnregisterClass(this->m_windowClass.c_str(), this->m_hInstance);
        return false;
      }
    }

    return true;
  }

  HWND CoreRenderWindow::getWindowHandle()
  {
    return m_windowHandle;
  }

  bool CoreRenderWindow::registerWindowClass()
  {
    
    WNDCLASSEX windowClass;

    windowClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    windowClass.lpfnWndProc = WindowProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = this->m_hInstance;
    windowClass.hIcon = NULL;
    windowClass.hIconSm = NULL;
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
    windowClass.lpszMenuName = NULL;
    windowClass.lpszClassName = this->m_windowClass.c_str();
    windowClass.cbSize = sizeof(WNDCLASSEX);

    if (!RegisterClassEx(&windowClass))
    {
      return false;
    }

    return true;
  }

}