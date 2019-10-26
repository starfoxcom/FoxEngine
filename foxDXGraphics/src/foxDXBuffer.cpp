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

  ID3D11Buffer** DXBuffer::getBufferRef()
  {
    return &m_buffer;
  }

}