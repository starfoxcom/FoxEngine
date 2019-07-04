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
  std::vector<InputElements> * InputLayout::getInputLayoutDesc()
  {
    return &m_inputElements;
  }
  uint32 InputLayout::getInputLayoutNumElements()
  {
    return m_inputElements.size();
  }
}
