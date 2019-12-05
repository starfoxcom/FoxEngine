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

  class foxDXSolidRS : public foxDXRasterizerState
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXSolidRS();

    /**
     * @brief Default destructor.
     */
    ~foxDXSolidRS();

  private:

  };
}