/**
 * Includes
 */
#include "foxDXTexture.h"

namespace foxEngineSDK
{


  foxDXTexture::foxDXTexture()
  {
  }

  foxDXTexture::~foxDXTexture()
  {
    if (m_texture) m_texture->Release();
    m_texture = nullptr;
  }

  ID3D11Texture2D * foxDXTexture::getTexture()
  {
    return m_texture;
  }

  ID3D11Texture2D ** foxDXTexture::getTextureRef()
  {
    return &m_texture;
  }

}