/**
 * Includes
 */
#include "foxDXDevice.h"

namespace foxEngineSDK
{

  DXDevice::DXDevice()
  {
  }

  DXDevice::~DXDevice()
  {
  }

  ID3D11Device * DXDevice::getDevice()
  {
    return m_device;
  }

  ID3D11Device ** DXDevice::getDeviceRef()
  {
    return &m_device;
  }


}