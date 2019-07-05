#include "foxVertexShader.h"


namespace foxEngineSDK
{

  VertexShader::VertexShader()
  {
  }


  VertexShader::~VertexShader()
  {
  }
  ID3D11VertexShader ** VertexShader::getVertexShaderRef()
  {
    return &m_vertexShader;
  }
  ID3D11VertexShader * VertexShader::getVertexShader()
  {
    return m_vertexShader;
  }
}
