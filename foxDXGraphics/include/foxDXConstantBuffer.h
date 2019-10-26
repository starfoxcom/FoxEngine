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

  private:

  };
}