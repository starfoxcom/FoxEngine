#pragma once

/**
 * @file foxDXIndexBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/07/13
 * @brief
 * 
 */

 /**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"
#include "foxDXBuffer.h"

 /**
 * Libs
 */

namespace foxEngineSDK
{

  class DXIndexBuffer : public DXBuffer
  {
  public:
    DXIndexBuffer();
    ~DXIndexBuffer();

    void setBufferDesc(uint32 _indexCount);

    void setSubresourceData(
      const void * _indices);
  };
}