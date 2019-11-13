#pragma once
/**
 * @file foxDXBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/09
 * @brief Buffer base class.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class DXBuffer
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXBuffer();

    /**
     * @brief Default destructor.
     */
    ~DXBuffer();

    /**
     * @brief Gets the DirectX buffer.
     */
    ID3D11Buffer * getBuffer();

    /**
     * @brief Gets the DirectX buffer reference.
     */
    ID3D11Buffer ** getBufferRef();
  
  protected:

    ID3D11Buffer * m_buffer = nullptr; /**< Buffer class object member.*/

  };
}