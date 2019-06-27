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
#include "foxPlatformTypes.h"

namespace foxEngineSDK
{

  class InputLayout
  {
  public:
    InputLayout();
    ~InputLayout();

    //ID3D11InputLayout ** getInputLayoutRef();
    //
    //ID3D11InputLayout * getInputLayout();
    //
    //D3D11_INPUT_ELEMENT_DESC * getInputLayoutDesc();
    //
    //uint32 getInputLayoutNumElements();

  private:
    ID3D11InputLayout * m_inputLayout;

    //D3D11_INPUT_ELEMENT_DESC m_inputLayoutDesc[] =
    //{
    //  { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 }
    //};
  };
}
