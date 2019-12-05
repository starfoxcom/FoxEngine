/**
 * Includes
 */
#include "foxDXVertexShader.h"

namespace foxEngineSDK
{


  foxDXVertexShader::foxDXVertexShader()
  {
  }

  foxDXVertexShader::~foxDXVertexShader()
  {
    if (m_vertexShader) m_vertexShader->Release();

    m_vertexShader = nullptr;
  }

  ID3D11VertexShader * foxDXVertexShader::getVertexShader()
  {
    return m_vertexShader;
  }

  ID3D11VertexShader ** foxDXVertexShader::getVertexShaderRef()
  {
    return &m_vertexShader;
  }

}