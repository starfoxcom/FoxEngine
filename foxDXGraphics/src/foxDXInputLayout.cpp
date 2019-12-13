/**
 * Includes
 */
#include "foxDXInputLayout.h"

namespace foxEngineSDK
{

  foxDXInputLayout::foxDXInputLayout()
  {
  }

  foxDXInputLayout::~foxDXInputLayout()
  {
    if (m_inputLayout) m_inputLayout->Release();
    m_inputLayout = nullptr;
  }

  ID3D11InputLayout * foxDXInputLayout::getInputLayout()
  {
    return m_inputLayout;
  }

  ID3D11InputLayout ** foxDXInputLayout::getInputLayoutRef()
  {
    return &m_inputLayout;
  }

  D3D11_INPUT_ELEMENT_DESC * foxDXInputLayout::getInputElementDesc()
  {
    return &m_inputElements[0];
  }

  uint32 foxDXInputLayout::getInputElementsNum()
  {
    return static_cast<uint32>(m_inputElements.size());
  }

  void foxDXInputLayout::addElement(
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