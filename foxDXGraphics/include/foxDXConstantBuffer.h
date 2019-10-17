#pragma once
/**
 * @file foxDXConstantBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/16
 * @brief Graphics API Constant Buffer Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxDXBuffer.h"

namespace foxEngineSDK
{

  class DXConstantBuffer : public DXBuffer
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXConstantBuffer();

    /**
     * @brief Default destructor.
     */
    ~DXConstantBuffer();

    /**
     * @brief Sets the Constant Buffer Desc.
     * @param _structSize The size, in bytes, of the constant buffer struct.
     */
    void setConstantBufferDesc(uint32 _structSize);

  private:

  };
}