/**
* @file foxViewport.h
* @author --
* @date ---
* @brief Implementation of viewport.
*/
#pragma once

/**
* Includes
*/
#include <d3d11.h>

namespace foxEngineSDK
{
  class DXViewport
  {

  public:
    DXViewport();
    ~DXViewport();

    void initViewport(float _width, float _height);

    D3D11_VIEWPORT * getViewportRef();


  private:
    D3D11_VIEWPORT m_viewport;
  };
}