#include "foxDXVertexShader.h"


namespace foxEngineSDK
{

  DXVertexShader::DXVertexShader()
  {
  }


  DXVertexShader::~DXVertexShader()
  {
  }
  ID3D11VertexShader ** DXVertexShader::getVertexShaderRef()
  {
    return &m_vertexShader;
  }
  ID3D11VertexShader * DXVertexShader::getVertexShader()
  {
    return m_vertexShader;
  }
}
