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

  bool DXDevice::createRenderTargetView(ID3D11Texture2D * _backBuffer, ID3D11RenderTargetView ** _renderTargetViewRef)
  {
    return m_device->CreateRenderTargetView(_backBuffer, 0, _renderTargetViewRef);
  }

}