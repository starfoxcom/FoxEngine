#pragma once
/**
 * @file foxDXSolidRS.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/22
 * @brief Graphics API Solid Rasterizer State class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"
#include "foxDXRasterizerState.h"

namespace foxEngineSDK
{

  class DXSolidRS : public DXRasterizerState
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXSolidRS();

    /**
     * @brief Default destructor.
     */
    ~DXSolidRS();

    /**
     * @brief Sets the solid Rasterizer state Desc.
     */
    void setSolidRSDesc();

  private:

  };
}