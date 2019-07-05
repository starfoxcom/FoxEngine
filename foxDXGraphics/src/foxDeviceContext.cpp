#include "foxDeviceContext.h"
#include "foxInputLayout.h"


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
}
