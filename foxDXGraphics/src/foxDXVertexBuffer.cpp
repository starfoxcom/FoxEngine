#include "foxDXVertexBuffer.h"


namespace foxEngineSDK
{

  DXVertexBuffer::DXVertexBuffer()
  {
    m_bufferDesc = nullptr;
    m_initData = nullptr;
  }


  DXVertexBuffer::~DXVertexBuffer()
  {
    delete m_bufferDesc;
    delete m_initData;
  }

  void DXVertexBuffer::setBufferDesc()
  {
    m_bufferDesc = new D3D11_BUFFER_DESC();

    m_bufferDesc->Usage = D3D11_USAGE_DYNAMIC;
    m_bufferDesc->ByteWidth = sizeof(simpleVertex2) * 3;
    m_bufferDesc->BindFlags = D3D11_BIND_VERTEX_BUFFER;
    m_bufferDesc->CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
  }

  void DXVertexBuffer::setSubresourceData(
    const void * _triangle,
    uint32 _sysMemPitch,
    uint32 _sysMemSlicePitch)
  {

    m_initData = new D3D11_SUBRESOURCE_DATA();

    m_initData->pSysMem = _triangle;
    m_initData->SysMemPitch = _sysMemPitch;
    m_initData->SysMemSlicePitch = _sysMemSlicePitch;
  }

  D3D11_SUBRESOURCE_DATA * DXVertexBuffer::getSubresourceData()
  {
    return m_initData;
  }

  ID3D11Buffer ** DXVertexBuffer::getVertexBufferRef()
  {
    return &m_vertexBuffer;
  }

  ID3D11Buffer * DXVertexBuffer::getVertexBuffer()
  {
    return m_vertexBuffer;
  }

  D3D11_BUFFER_DESC * DXVertexBuffer::getBufferDesc()
  {
    return m_bufferDesc;
  }
}