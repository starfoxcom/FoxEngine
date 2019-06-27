#pragma once

#include <d3d11.h>
#include "foxGraphicsDefines.h"

namespace foxEngineSDK
{

  class Texture
  {
  public:
    Texture();
    ~Texture();

    ID3D11Texture2D * getTexture();

    ID3D11Texture2D ** getTextureRef();

  private:

    ID3D11Texture2D * m_texture;
  };
}