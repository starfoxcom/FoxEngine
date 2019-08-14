#include "foxDXVertexBuffer.h"


namespace foxEngineSDK
{

  DXVertexBuffer::DXVertexBuffer()
  {
  }


  DXVertexBuffer::~DXVertexBuffer()
  {
  }

  void DXVertexBuffer::setBufferDesc(uint32 _vertexCount)
  {
    m_bufferDesc = new D3D11_BUFFER_DESC();

    m_bufferDesc->Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc->ByteWidth = sizeof(vertex) * _vertexCount;
    m_bufferDesc->BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bufferDesc->CPUAccessFlags = 0;
  }

  void DXVertexBuffer::setSubresourceData(
    const void * _triangle)
  {

    m_initData = new D3D11_SUBRESOURCE_DATA();

    m_initData->pSysMem = _triangle;
  }
}