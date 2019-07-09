#include "foxDXTexture.h"


namespace foxEngineSDK
{

  DXTexture::DXTexture()
  {
  }

  DXTexture::~DXTexture()
  {
  }
  ID3D11Texture2D * DXTexture::getTexture()
  {
    return m_texture;
  }
  ID3D11Texture2D ** DXTexture::getTextureRef()
  {
    return &m_texture;
  }
}