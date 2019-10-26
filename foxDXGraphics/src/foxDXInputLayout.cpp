/**
 * Includes
 */
#include "foxDXInputLayout.h"

namespace foxEngineSDK
{

  DXInputLayout::DXInputLayout()
  {
  }

  DXInputLayout::~DXInputLayout()
  {
  }

  ID3D11InputLayout * DXInputLayout::getInputLayout()
  {
    return m_inputLayout;
  }

  ID3D11InputLayout ** DXInputLayout::getInputLayoutRef()
  {
    return &m_inputLayout;
  }

  D3D11_INPUT_ELEMENT_DESC * DXInputLayout::getInputElementDesc()
  {
    return &m_inputElements[0];
  }

  uint32 DXInputLayout::getInputElementsNum()
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
    uint32 _instanceDataStepRate)
  {

    D3D11_INPUT_ELEMENT_DESC element
    {
      _semanticName,
      _semanticIndex,
      static_cast<DXGI_FORMAT>(_format),
      _inputSlot,
      _alignedByteOffset,
      static_cast<D3D11_INPUT_CLASSIFICATION>(_inputSlotClass),
      _instanceDataStepRate
    };

    m_inputElements.push_back(element);
  }

}