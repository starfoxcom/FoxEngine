#include "foxPixelShader.h"


namespace foxEngineSDK
{

  PixelShader::PixelShader()
  {
  }


  PixelShader::~PixelShader()
  {
  }
  ID3D11PixelShader ** PixelShader::getPixelShaderRef()
  {
    return &m_pixelShader;
  }
  ID3D11PixelShader * PixelShader::getPixelShader()
  {
    return m_pixelShader;
  }
  ID3DBlob * PixelShader::getPSBlop()
  {
    return m_PSBlob;
  }
}
