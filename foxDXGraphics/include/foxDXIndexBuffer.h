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

  class DXIndexBuffer : public DXBuffer
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXIndexBuffer();

    /**
     * @brief Default destructor.
     */
    ~DXIndexBuffer();

    /**
     * @brief Sets the Index Buffer Desc.
     * @param _dataSize The size, in bytes, of the index buffer to create.
     */
    void setIndexBufferDesc(uint32 _dataSize);

    /**
     * @brief Sets the Index Buffer sub resource data.
     * @param _data A pointer to a system memory array which contains the data
                    to initialize the index buffer.
     */
    void setSubResourceData(const void * _data);

  private:


  };
}