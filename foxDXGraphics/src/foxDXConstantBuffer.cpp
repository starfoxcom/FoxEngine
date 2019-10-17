/**
 * Includes
 */
#include "foxDXConstantBuffer.h"

namespace foxEngineSDK
{

  DXConstantBuffer::DXConstantBuffer()
  {
  }

  DXConstantBuffer::~DXConstantBuffer()
  {
  }

  void DXConstantBuffer::setConstantBufferDesc(uint32 _structSize)
  {

    ZeroMemory(&m_bufferDesc, sizeof(m_bufferDesc));
    m_bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    m_bufferDesc.ByteWidth = _structSize;
    m_bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    m_bufferDesc.CPUAccessFlags = 0;
    m_bufferDesc.MiscFlags = 0;
    m_bufferDesc.StructureByteStride = 0;
  }

}