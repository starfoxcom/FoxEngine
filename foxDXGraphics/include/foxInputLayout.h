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
    const char * semanticName;
    uint32 semanticIndex;
    FOXGI_FORMAT::E format;
    uint32 inputSlot;
    uint32 alignedByteOffset;
    FOX_INPUT_CLASSIFICATION::E inputSlotClass;
    uint32 instanceDataStepRate;
  };

  class InputLayout
  {
  public:
    InputLayout();
    ~InputLayout();

    ID3D11InputLayout ** getInputLayoutRef();
    
    ID3D11InputLayout * getInputLayout();
    
    D3D11_INPUT_ELEMENT_DESC * getInputLayoutDesc();
    
    uint32 getInputLayoutNumElements();

    void addElement(
      const char * _semanticName,
      uint32 _semanticIndex,
      FOXGI_FORMAT::E _format,
      uint32 _inputSlot,
      uint32 _alignedByteOffset,
      FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
      uint32 _instanceDataSetpRate);

  private:
    ID3D11InputLayout * m_inputLayout;

    D3D11_INPUT_ELEMENT_DESC * m_inputElementDesc;

    std::vector<InputElements> m_inputElements;
  };
}
