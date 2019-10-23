#pragma once
/**
 * @file foxDXWireframeState.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/22
 * @brief Graphics API Wire frame Rasterizer State Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"
#include "foxDXRasterizerState.h"

namespace foxEngineSDK
{

  class DXWireframeRS : public DXRasterizerState
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXWireframeRS();

    /**
     * @brief Default destructor.
     */
    ~DXWireframeRS();

    /**
     * @brief Sets the wire frame Rasterizer state Desc.
     */
    void setWireframeRSDesc();

  private:

  };
}