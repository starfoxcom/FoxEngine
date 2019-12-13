/**
 * Includes
 */
#include "foxDXBuffer.h"

namespace foxEngineSDK
{

  foxDXBuffer::foxDXBuffer()
  {
  }

  foxDXBuffer::~foxDXBuffer()
  {
    if (m_buffer) m_buffer->Release();
    m_buffer = nullptr;

  }

  ID3D11Buffer * foxDXBuffer::getBuffer()
  {
    return m_buffer;
  }

  ID3D11Buffer** foxDXBuffer::getBufferRef()
  {
    return &m_buffer;
  }

}