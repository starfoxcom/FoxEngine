#include "foxDeviceContext.h"
#include "foxInputLayout.h"
#include "foxVertexBuffer.h"


namespace foxEngineSDK
{

  DeviceContext::DeviceContext()
  {
  }


  DeviceContext::~DeviceContext()
  {
  }

  ID3D11DeviceContext ** DeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }

  ID3D11DeviceContext * DeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
  void DeviceContext::setInputLayout(InputLayout * _inputLayout)
  {

    m_deviceContext->IASetInputLayout(_inputLayout->getInputLayout());
  }

  void DeviceContext::setIAVertexBuffers(
    VertexBuffer * _vertexBuffer,
    uint32 _startSlot,
    uint32 _numOfBuffers)
  {
    uint32 stride = sizeof(simpleVertex);
    uint32 offset = 0;

    m_deviceContext->IASetVertexBuffers(
      _startSlot,
      _numOfBuffers,
      _vertexBuffer->getVertexBufferRef(),
      &stride,
      &offset);
  }
  void DeviceContext::setIAPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology)
  {
    m_deviceContext->IASetPrimitiveTopology(static_cast<D3D11_PRIMITIVE_TOPOLOGY>(_topology));
  }
}
