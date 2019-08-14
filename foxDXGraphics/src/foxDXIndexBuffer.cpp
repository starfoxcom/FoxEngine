#include "foxDXIndexBuffer.h"


namespace foxEngineSDK
{

  DXIndexBuffer::DXIndexBuffer()
  {
  }


  DXIndexBuffer::~DXIndexBuffer()
  {
  }

  void DXIndexBuffer::setBufferDesc(uint32 _indexCount)
  {
    m_bufferDesc = new D3D11_BUFFER_DESC();

    m_bufferDesc->Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc->ByteWidth = sizeof(uint32) * _indexCount;
    m_bufferDesc->BindFlags = D3D11_BIND_INDEX_BUFFER;
    m_bufferDesc->CPUAccessFlags = 0;
  }

  void DXIndexBuffer::setSubresourceData(
    const void * _indices)
  {

    m_initData = new D3D11_SUBRESOURCE_DATA();

    m_initData->pSysMem = _indices;
  }
}