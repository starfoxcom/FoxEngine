#include "foxInputLayout.h"


namespace foxEngineSDK
{

  InputLayout::InputLayout()
  {
  }


  InputLayout::~InputLayout()
  {
  }
  ID3D11InputLayout ** InputLayout::getInputLayoutRef()
  {
    return &m_inputLayout;
  }
  ID3D11InputLayout * InputLayout::getInputLayout()
  {
    return m_inputLayout;
  }
  D3D11_INPUT_ELEMENT_DESC * InputLayout::getInputLayoutDesc()
  {
    return &m_inputLayoutDesc[0];
  }
  uint32 InputLayout::getInputLayoutNumElements()
  {
  
    uint32 result = ARRAYSIZE(m_inputLayoutDesc);
    return result;
  }
}
