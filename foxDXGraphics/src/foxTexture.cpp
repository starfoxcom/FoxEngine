#include "foxTexture.h"


namespace foxEngineSDK
{

  Texture::Texture()
  {
  }

  Texture::~Texture()
  {
  }
  ID3D11Texture2D * Texture::getTexture()
  {
    return m_texture;
  }
  ID3D11Texture2D ** Texture::getTextureRef()
  {
    return &m_texture;
  }
}