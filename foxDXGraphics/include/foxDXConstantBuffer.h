#pragma once

/**
 * @file foxDXConstantBuffer.h
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
#include "foxMatrix4.h"

 /**
 * Libs
 */

namespace foxEngineSDK
{

  struct constantBuffer
  {
    Matrix4 world;
    Matrix4 view;
    Matrix4 projection;
  };

  class DXConstantBuffer : public DXBuffer
  {
  public:
    DXConstantBuffer();
    ~DXConstantBuffer();

    void setBufferDesc();
  };
}