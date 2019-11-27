/**
 * Includes
 */
#include "foxDXTexture.h"

namespace foxEngineSDK
{


  DXTexture::DXTexture()
  {
  }

  DXTexture::~DXTexture()
  {
    if (m_texture) m_texture->Release();
    m_texture = nullptr;
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