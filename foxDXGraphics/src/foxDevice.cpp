#include "foxDevice.h"


namespace foxEngineSDK
{

  Device::Device()
  {
  }


  Device::~Device()
  {
  }

  ID3D11Device ** Device::getDeviceRef()
  {
    return &m_device;
  }

  ID3D11Device * Device::getDevice()
  {
    return m_device;
  }
}
