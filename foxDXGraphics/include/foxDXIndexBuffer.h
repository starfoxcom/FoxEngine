#pragma once
/**
 * @file foxDXIndexBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/09
 * @brief Graphics API Index Buffer Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxDXBuffer.h"

namespace foxEngineSDK
{

  class foxDXIndexBuffer : public foxDXBuffer
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXIndexBuffer();

    /**
     * @brief Default destructor.
     */
    ~foxDXIndexBuffer();

  private:


  };
}