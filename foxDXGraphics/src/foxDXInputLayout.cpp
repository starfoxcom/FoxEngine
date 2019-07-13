#include "foxDXInputLayout.h"


namespace foxEngineSDK
{

  DXInputLayout::DXInputLayout()
  {

    m_inputElementDesc = nullptr;
  }


  DXInputLayout::~DXInputLayout()
  {
    delete[] m_inputElementDesc;
  }

  ID3D11InputLayout ** DXInputLayout::getInputLayoutRef()
  {
    return &m_inputLayout;
  }
  ID3D11InputLayout * DXInputLayout::getInputLayout()
  {
    return m_inputLayout;
  }
  D3D11_INPUT_ELEMENT_DESC * DXInputLayout::getInputLayoutDesc()
  {
    if (m_inputElementDesc != nullptr)
    {
      delete[] m_inputElementDesc;
    }

    m_inputElementDesc = new D3D11_INPUT_ELEMENT_DESC[m_inputElements.size()];

    for (uint32 i = 0; i < m_inputElements.size(); ++i)
    {

      m_inputElementDesc[i].SemanticName = m_inputElements[i].semanticName;
      m_inputElementDesc[i].SemanticIndex = m_inputElements[i].semanticIndex;
      m_inputElementDesc[i].Format = static_cast<DXGI_FORMAT>(m_inputElements[i].format);
      m_inputElementDesc[i].InputSlot = m_inputElements[i].inputSlot;
      m_inputElementDesc[i].AlignedByteOffset = m_inputElements[i].alignedByteOffset;
      m_inputElementDesc[i].InputSlotClass = static_cast<D3D11_INPUT_CLASSIFICATION>(m_inputElements[i].inputSlotClass);
      m_inputElementDesc[i].InstanceDataStepRate = m_inputElements[i].instanceDataStepRate;
    }

    return m_inputElementDesc;
  }
  uint32 DXInputLayout::getInputLayoutNumElements()
  {
    return static_cast<uint32>(m_inputElements.size());
  }

  void DXInputLayout::addElement(
    const char * _semanticName,
    uint32 _semanticIndex,
    FOXGI_FORMAT::E _format,
    uint32 _inputSlot,
    uint32 _alignedByteOffset,
    FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
    uint32 _instanceDataSetpRate)
  {

    InputElements element
    {
      _semanticName,
      _semanticIndex,
      _format,
      _inputSlot,
      _alignedByteOffset,
      _inputSlotClass,
      _instanceDataSetpRate
    };

    m_inputElements.push_back(element);
  }
}
