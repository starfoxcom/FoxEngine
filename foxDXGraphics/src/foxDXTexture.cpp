#include "foxDXTexture.h"


namespace foxEngineSDK
{

  DXTexture::DXTexture()
  {
    m_texture = nullptr;
  }

  DXTexture::~DXTexture()
  {
    if(m_texture != nullptr)
      m_texture = nullptr;
    delete m_texture;
  }

  ID3D11Texture2D * DXTexture::getTexture()
  {
    return m_texture;
  }

  ID3D11Texture2D ** DXTexture::getTextureRef()
  {
    return &m_texture;
  }

  D3D11_TEXTURE2D_DESC DXTexture::getTextureDesc()
  {
    return m_textureDesc;
  }

  D3D11_TEXTURE2D_DESC * DXTexture::getTextureDescRef()
  {
    return &m_textureDesc;
  }

  void DXTexture::setTextureDesc(
    uint32 _width,
    uint32 _height,
    uint32 _bindFlag,
    uint32 _mipLevels,
    uint32 _arraySize,
    FOXGI_FORMAT::E _format,
    uint32 _sampleCount,
    uint32 _sampleQuality)
  {

    ZeroMemory(&m_textureDesc, sizeof(m_textureDesc));

    m_textureDesc.Width = _width;
    m_textureDesc.Height = _height;
    m_textureDesc.MipLevels = _mipLevels;
    m_textureDesc.ArraySize = _arraySize;
    m_textureDesc.Format = static_cast<DXGI_FORMAT>(_format);
    m_textureDesc.SampleDesc.Count = _sampleCount;
    m_textureDesc.SampleDesc.Quality = _sampleQuality;
    m_textureDesc.Usage = D3D11_USAGE_DEFAULT;
    m_textureDesc.BindFlags = _bindFlag;
    m_textureDesc.CPUAccessFlags = 0;
    m_textureDesc.MiscFlags = 0;

  }
}