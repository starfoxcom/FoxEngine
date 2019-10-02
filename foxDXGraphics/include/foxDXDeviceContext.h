#pragma once
/**
 * @file foxDXDeviceContext.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Device Context Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  class DXDeviceContext
  {
  public:

    //Default constructor
    DXDeviceContext();

    //Default destructor
    ~DXDeviceContext();

    //Get the DirectX Device Context
    ID3D11DeviceContext * getDeviceContext();

    //Get the DirectX Device Context reference
    ID3D11DeviceContext ** getDeviceContextRef();

  private:

    ID3D11DeviceContext * m_deviceContext; /**< Device Context class object member*/
  };
}