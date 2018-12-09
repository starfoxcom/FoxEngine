/**
* @file foxInputLayout.h
* @author --
* @date ---
* @brief Implementation of input layout.
*/
#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxGraphicsDefines.h"

namespace foxEngineSDK
{

  class FOX_GRAPHICS_EXPORT InputLayout
  {
  public:
    InputLayout();
    ~InputLayout();

    ID3D11InputLayout ** getInputLayoutRef();

    ID3D11InputLayout * getInputLayout();

  private:
    ID3D11InputLayout * m_inputLayout;
  };
}
