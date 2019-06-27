/**
* @file foxRenderTargetView.h
* @author --
* @date ---
* @brief Implementation of render target view.
*/

#pragma once

/**
* Includes
*/
#include <d3d11.h>

namespace foxEngineSDK
{

  class RenderTargetView
  {
  public:
    RenderTargetView();
    ~RenderTargetView();

    ID3D11RenderTargetView ** getRenderTargetViewRef();

    ID3D11RenderTargetView * getRenderTargetView();

  private:

    ID3D11RenderTargetView * m_renderTargetView;
  };
}
