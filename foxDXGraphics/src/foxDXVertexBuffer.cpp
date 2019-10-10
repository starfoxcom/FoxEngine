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

  void DXVertexBuffer::setVertexBufferDesc(uint32 _dataSize)
  {
    ZeroMemory(&m_bufferDesc, sizeof(m_bufferDesc));
    m_bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc.ByteWidth = _dataSize;
    m_bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bufferDesc.CPUAccessFlags = 0;
    m_bufferDesc.MiscFlags = 0;
    m_bufferDesc.StructureByteStride = 0;
  }

  void DXVertexBuffer::setSubResourceData(const void * _data)
  {

    ZeroMemory(&m_initData, sizeof(m_initData));
    m_initData.pSysMem = _data;
  }

}