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

  void DXIndexBuffer::setIndexBufferDesc(uint32 _dataSize, uint32 _length)
  {
    ZeroMemory(&m_bufferDesc, sizeof(m_bufferDesc));
    m_bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc.ByteWidth = _dataSize * _length;
    m_bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    m_bufferDesc.CPUAccessFlags = 0;
    m_bufferDesc.MiscFlags = 0;
    m_bufferDesc.StructureByteStride = 0;
  }

  void DXIndexBuffer::setSubResourceData(const void * _data)
  {
    ZeroMemory(&m_initData, sizeof(m_initData));
    m_initData.pSysMem = _data;
  }

}