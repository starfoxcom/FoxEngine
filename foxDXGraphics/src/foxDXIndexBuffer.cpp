/**
 * Includes
 */
#include "foxDXIndexBuffer.h"

namespace foxEngineSDK
{
  
  DXIndexBuffer::DXIndexBuffer()
  {
  }

  DXIndexBuffer::~DXIndexBuffer()
  {
  }

  void DXIndexBuffer::setIndexBufferDesc(const void * _data, uint32 _length)
  {

    m_bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc.ByteWidth = sizeof(_data) * _length;
    m_bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    m_bufferDesc.CPUAccessFlags = 0;
    m_bufferDesc.MiscFlags = 0;
    m_bufferDesc.StructureByteStride = 0;
  }

  void DXIndexBuffer::setSubResourceData(const void * _data)
  {
    m_initData.pSysMem = _data;
  }

}