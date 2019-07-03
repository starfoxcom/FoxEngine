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
#include "foxGraphicsDefines.h"
#include "foxPlatformTypes.h"

namespace foxEngineSDK
{
  class Viewport
  {

  public:
    Viewport();
    ~Viewport();

    void initViewport(float _width, float _height);

    D3D11_VIEWPORT * getViewport();


  private:
    D3D11_VIEWPORT m_viewport;
  };
}