/**
 * Includes
 */
#include "foxDXBuffer.h"

namespace foxEngineSDK
{

  DXBuffer::DXBuffer()
  {
  }

  DXBuffer::~DXBuffer()
  {
  }

  ID3D11Buffer * DXBuffer::getBuffer()
  {
    return m_buffer;
  }

  ID3D11Buffer ** DXBuffer::getBufferRef()
  {
    return &m_buffer;
  }

  D3D11_BUFFER_DESC DXBuffer::getBufferDesc()
  {
    return m_bufferDesc;
  }

  D3D11_SUBRESOURCE_DATA DXBuffer::getSubResourceData()
  {
    return m_initData;
  }

}