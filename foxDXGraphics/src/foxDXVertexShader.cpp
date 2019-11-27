/**
 * Includes
 */
#include "foxDXVertexShader.h"

namespace foxEngineSDK
{


  DXVertexShader::DXVertexShader()
  {
  }

  DXVertexShader::~DXVertexShader()
  {
    if (m_vertexShader) m_vertexShader->Release();

    m_vertexShader = nullptr;
  }

  ID3D11VertexShader * DXVertexShader::getVertexShader()
  {
    return m_vertexShader;
  }

  ID3D11VertexShader ** DXVertexShader::getVertexShaderRef()
  {
    return &m_vertexShader;
  }

}