/**
 * Includes
 */
#include "foxDXVertexBuffer.h"

namespace foxEngineSDK
{


  DXVertexBuffer::DXVertexBuffer()
  {
  }

  DXVertexBuffer::~DXVertexBuffer()
  {
  }

  void DXVertexBuffer::setVertexBufferDesc(const void * _data, uint32 _length)
  {

    m_bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc.ByteWidth = sizeof(_data) * _length;
    m_bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bufferDesc.CPUAccessFlags = 0;
    m_bufferDesc.MiscFlags = 0;
    m_bufferDesc.StructureByteStride = 0;
  }

  void DXVertexBuffer::setSubResourceData(const void * _data)
  {
    m_initData.pSysMem = _data;
  }

}