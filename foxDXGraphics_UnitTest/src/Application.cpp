#include "Application.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
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


int BaseApp::run()
{

  //This struct holds info for the window class
  WNDCLASSEX windowClass;

  //Clear out the window class for use
  ZeroMemory(&windowClass, sizeof(WNDCLASSEX));

  //Fill in the struct with the info needed
  windowClass.cbSize = sizeof(WNDCLASSEX);
  windowClass.style = CS_HREDRAW | CS_VREDRAW;
  windowClass.lpfnWndProc = WindowProc;
  windowClass.hInstance = GetModuleHandle(nullptr);
  windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
  windowClass.hbrBackground = (HBRUSH)COLOR_WINDOW;
  windowClass.lpszClassName = "WindowClass 1";

  //Register the window class
  RegisterClassEx(&windowClass);

  //Calculate the size of the client area
  RECT windowRect = { 0, 0, 640, 480 }; //Set the size, but not the position

  AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE); //adjust the size

  //Create the window and use the result as the handle
  m_windowHandler = CreateWindowEx(
    NULL,
    "WindowClass 1",                     //Name of window class
    "First window program",              //Title of window
    WS_OVERLAPPEDWINDOW,                  //Style of window
    300,                                  //X pos of window
    300,                                  //Y pos of window
    windowRect.right - windowRect.left,   //Width of window
    windowRect.bottom - windowRect.top,   //Height of window
    NULL,                                 //Parent of this window, NULL since no parent
    NULL,                                 //Menu of the window, NULL since no using menus
    GetModuleHandle(nullptr),             //App handle
    NULL);                                //Used with multiple windows, NULL
              
  //Init render
  m_graphicsAPI.init(m_windowHandler);

  //Display window on screen
  ShowWindow(m_windowHandler, SW_SHOW);

  //This struct holds windows event messages
  MSG msg = { 0 };

  //Wait for the next message in the queue, store the result in msg
  while (TRUE)
  {

    //Check to see if any messages are waiting in the queue
    if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {

      //translate keystroke messages into the right format
      TranslateMessage(&msg);

      //Send message to the WindowProc function
      DispatchMessage(&msg);

      if (msg.message == WM_QUIT)
      {
        break;
      }
    }

    //Render 
    render();
  }

  //Return this part of the WM_QUIT message to windows
  return msg.wParam;

}

void BaseApp::render()
{

  //Create and set color array and values
  float color[4] = {0.0f,0.2f,0.4f,1.0f};

  //Clear the render target view
  m_graphicsAPI.m_deviceContext->getDeviceContext()->ClearRenderTargetView(
    m_graphicsAPI.m_renderTargetView,
    color);

  UINT stride = sizeof(vertex);
  UINT offset = 0;

  m_graphicsAPI.m_deviceContext->getDeviceContext()->IASetVertexBuffers(
    0, 1, m_graphicsAPI.m_vertexBuffer->getVertexBufferRef(), &stride, &offset);

  m_graphicsAPI.m_deviceContext->getDeviceContext()->IASetPrimitiveTopology(
    D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

  m_graphicsAPI.m_deviceContext->getDeviceContext()->Draw(3, 0);

  //Show render target on client
  m_graphicsAPI.m_swapChain->getSwapChain()->Present(0, 0);
}

BaseApp::BaseApp()
{
}

BaseApp::~BaseApp()
{
}