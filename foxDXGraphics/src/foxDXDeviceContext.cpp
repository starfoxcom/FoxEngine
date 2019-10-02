/**
 * Includes
 */
#include "foxDXDeviceContext.h"

namespace foxEngineSDK
{

  DXDeviceContext::DXDeviceContext()
  {
  }

  DXDeviceContext::~DXDeviceContext()
  {
  }
  ID3D11DeviceContext * DXDeviceContext::getDeviceContext()
  {
    return m_deviceContext;
  }
  ID3D11DeviceContext ** DXDeviceContext::getDeviceContextRef()
  {
    return &m_deviceContext;
  }
}