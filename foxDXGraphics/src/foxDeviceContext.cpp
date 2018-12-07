#include "foxDeviceContext.h"


namespace foxEngineSDK
{

  DeviceContext::DeviceContext()
  {
  }


  DeviceContext::~DeviceContext()
  {
  }

  ID3D11DeviceContext ** DeviceContext::getDEviceContextRef()
  {
    return &m_deviceContext;
  }

  ID3D11DeviceContext * DeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
}
