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
#include "foxPrerequisitesUtilities.h"
#include "foxGraphicsCommons.h"

namespace foxEngineSDK
{

  struct InputElements
  {
    const char _semanticName;
    uint32 _semanticIndex;
    FXGI_FORMAT::E _format;
    uint32 _alignedByteOffset;
    FX_INPUT_CLASSIFICATION::E _inputSlotClass;
    uint32 _instanceDataStepRate;
  };

  class InputLayout
  {
  public:
    InputLayout();
    ~InputLayout();

    ID3D11InputLayout ** getInputLayoutRef();
    
    ID3D11InputLayout * getInputLayout();
    
    std::vector<InputElements> * getInputLayoutDesc();                           
    
    uint32 getInputLayoutNumElements();

  private:
    ID3D11InputLayout * m_inputLayout;

    std::vector<InputElements> m_inputElements;
  };
}
