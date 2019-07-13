#include "foxDXBuffer.h"


namespace foxEngineSDK
{

  DXBuffer::DXBuffer()
  {
    m_bufferDesc = nullptr;
    m_initData = nullptr;
  }


  DXBuffer::~DXBuffer()
  {
    delete m_bufferDesc;
    delete m_initData;
  }

  D3D11_SUBRESOURCE_DATA * DXBuffer::getSubresourceData()
  {
    return m_initData;
  }

  ID3D11Buffer ** DXBuffer::getBufferRef()
  {
    return &m_Buffer;
  }

  ID3D11Buffer * DXBuffer::getBuffer()
  {
    return m_Buffer;
  }

  D3D11_BUFFER_DESC * DXBuffer::getBufferDesc()
  {
    return m_bufferDesc;
  }
}