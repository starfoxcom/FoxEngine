/**
 * Includes
 */
#include "foxDXPixelShader.h"

namespace foxEngineSDK
{

  foxDXPixelShader::foxDXPixelShader()
  {
  }

  foxDXPixelShader::~foxDXPixelShader()
  {
  }

  ID3D11PixelShader * foxDXPixelShader::getPixelShader()
  {
    return m_pixelShader;
  }

  ID3D11PixelShader ** foxDXPixelShader::getPixelShaderRef()
  {
    return &m_pixelShader;
  }

}