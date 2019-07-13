#include "foxDXConstantBuffer.h"

namespace foxEngineSDK
{
  DXConstantBuffer::DXConstantBuffer()
  {
  }


  DXConstantBuffer::~DXConstantBuffer()
  {
  }

  void DXConstantBuffer::setBufferDesc()
  {
    m_bufferDesc = new D3D11_BUFFER_DESC();

    m_bufferDesc->Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc->ByteWidth = sizeof(constantBuffer);
    m_bufferDesc->BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    m_bufferDesc->CPUAccessFlags = 0;
  }
}