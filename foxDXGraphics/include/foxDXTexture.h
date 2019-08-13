#pragma once

#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"
#include "foxGraphicsCommons.h"

namespace foxEngineSDK
{

  class DXTexture
  {
  public:
    DXTexture();
    ~DXTexture();

    ID3D11Texture2D * getTexture();

    ID3D11Texture2D ** getTextureRef();

    D3D11_TEXTURE2D_DESC getTextureDesc();

    D3D11_TEXTURE2D_DESC *getTextureDescRef();

    void setTextureDesc(
      uint32 _width,
      uint32 _height,
      uint32 _bindFlag,
      uint32 _mipLevels = 1,
      uint32 _arraySize = 1,
      FOXGI_FORMAT::E _format = FOXGI_FORMAT::E::K_D24_UNORM_S8_UINT,
      uint32 _sampleCount = 1,
      uint32 _sampleQuality = 0);

  private:

    ID3D11Texture2D * m_texture;

    D3D11_TEXTURE2D_DESC m_textureDesc;
  };
}