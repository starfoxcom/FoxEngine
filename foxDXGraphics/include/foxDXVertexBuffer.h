#pragma once
/**
 * @file foxDXVertexBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/09
 * @brief Graphics API Vertex Buffer Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxDXBuffer.h"

namespace foxEngineSDK
{

  class DXVertexBuffer : public DXBuffer
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXVertexBuffer();

    /**
     * @brief Default destructor.
     */
    ~DXVertexBuffer();

  private:

  };
}