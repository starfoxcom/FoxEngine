#include "foxVertexBuffer.h"


namespace foxEngineSDK
{

  VertexBuffer::VertexBuffer()
  {
  }


  VertexBuffer::~VertexBuffer()
  {
  }

  void VertexBuffer::setBufferDesc()
  {

    //Clear out the vertex buffer for use
    ZeroMemory(&m_bufferDesc, sizeof(m_bufferDesc));

    m_bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
    m_bufferDesc.ByteWidth = sizeof(vertex) * 3;
    m_bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
  }

  ID3D11Buffer ** VertexBuffer::getVertexBufferRef()
  {
    return &m_vertexBuffer;
  }

  ID3D11Buffer * VertexBuffer::getVertexBuffer()
  {
    return m_vertexBuffer;
  }

  D3D11_BUFFER_DESC * VertexBuffer::getBufferDesc()
  {
    return &m_bufferDesc;
  }
}