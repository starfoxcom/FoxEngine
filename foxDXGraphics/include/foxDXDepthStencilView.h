/**
 * @file foxDXDepthStencilView.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/08/12
 * @brief Implementation of Depth Stencil View
 * 
 */
#pragma once

/**
 * Includes
 */
#include<d3d11.h>

namespace foxEngineSDK
{

  class DXTexture;

  class DXDepthStencilVew
  {
  public:
    DXDepthStencilVew();
    ~DXDepthStencilVew();

    void setDepthStencilViewDesc(DXTexture * _texture);

    ID3D11DepthStencilView * getDepthStencilView();

    ID3D11DepthStencilView ** getDepthStencilViewRef();

    D3D11_DEPTH_STENCIL_VIEW_DESC * getDepthStencilViewDesc();

  private:

    D3D11_DEPTH_STENCIL_VIEW_DESC m_depthStencilViewDesc;

    ID3D11DepthStencilView * m_depthStencilView;

  };

}