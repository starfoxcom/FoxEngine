/**
 * Includes
 */
#include "foxDXPixelShader.h"

namespace foxEngineSDK
{

  DXPixelShader::DXPixelShader()
  {
  }

  DXPixelShader::~DXPixelShader()
  {
  }

  ID3D11PixelShader * DXPixelShader::getPixelShader()
  {
    return m_pixelShader;
  }

  ID3D11PixelShader ** DXPixelShader::getPixelShaderRef()
  {
    return &m_pixelShader;
  }

}