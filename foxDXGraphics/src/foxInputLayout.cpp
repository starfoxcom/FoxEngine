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
}
