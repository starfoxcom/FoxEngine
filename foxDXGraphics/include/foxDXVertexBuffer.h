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

    /**
     * @brief Sets the Vertex Buffer Desc.
     * @param _dataSize The size, in bytes, of the vertex buffer to create. 
     * @param _length The length of the data to use.
     */
    void setVertexBufferDesc(uint32 _dataSize);

    /**
     * @brief Sets the Vertex Buffer sub resource data.
     * @param _data A pointer to a system memory array which contains the data 
                    to initialize the vertex buffer.
     */
    void setSubResourceData(const void * _data);


  private:

  };
}