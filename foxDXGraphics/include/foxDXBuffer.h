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

    /**
     * @brief Gets the DirectX buffer desc.
     * @param 
     */
    D3D11_BUFFER_DESC getBufferDesc();

    /**
     * @brief Gets the DirectX sub resource data.
     */
    D3D11_SUBRESOURCE_DATA getSubResourceData();
  
  protected:

    D3D11_BUFFER_DESC m_bufferDesc; /**< Buffer descriptor class object member.*/

    ID3D11Buffer * m_buffer; /**< Buffer class object member.*/

    D3D11_SUBRESOURCE_DATA m_initData; /**< Sub resource data class object member.*/

  };
}