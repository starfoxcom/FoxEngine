#pragma once
/**
 * @file foxDXSamplerState.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/30
 * @brief Graphics API Sampler State Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class DXSamplerState
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXSamplerState();

    /**
     * @brief Default destructor.
     */
    ~DXSamplerState();

    /**
     * @brief Gets the DirectX Sampler State.
     */
    ID3D11SamplerState * getSamplerState();

    /**
     * @brief Gets the DirectX Sampler State reference.
     */
    ID3D11SamplerState ** getSamplerStateRef();

  private:

    ID3D11SamplerState * m_samplerState = nullptr; /**< Sampler State class object member.*/

  };
}
