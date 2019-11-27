#pragma once
/**
 * @file foxDXInputLayout.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/04
 * @brief Graphics API Input Layout class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  class DXInputLayout
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXInputLayout();

    /**
     * @brief Default destructor.
     */
    ~DXInputLayout();

    /**
     * @brief Gets the DirectX Input Layout.
     */
    ID3D11InputLayout * getInputLayout();

    /**
     * @brief Gets the DirectX Input Layout reference.
     */
    ID3D11InputLayout ** getInputLayoutRef();

    /**
     * @brief Gets the DirectX Input Element Desc.
     */
    D3D11_INPUT_ELEMENT_DESC * getInputElementDesc();

    /**
     * @brief Gets the number of input elements.
     */
    uint32 getInputElementsNum();

    /**
     * @brief Adds an Input Element to the DirectX Input Layout.
     * @param _semanticName Name to associate with the element.
     * @param _semanticIndex Index to attach to a semantic.
     * @param _format Enumerated type specifying the format of the vertex element to Direct3D.
     * @param _inputSlot Specifies the input slot index this element will come from.
     * @param _alignedByteOffset For a single input slot, this is the offset, in bytes,
     *                           from the start of the C++ vertex structure to the start
     *                           of the vertex component.
     * @param _inputSlotClass Specifies the type of input classification.
     * @param _instanceDataStepRate TBD.
     */
    void addElement(
      const char * _semanticName,
      uint32 _semanticIndex,
      FOXGI_FORMAT::E _format,
      uint32 _inputSlot,
      uint32 _alignedByteOffset,
      FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
      uint32 _instanceDataSetpRate);

  private:

    ID3D11InputLayout * m_inputLayout = nullptr; /**< Input Layout class object member.*/

    std::vector<D3D11_INPUT_ELEMENT_DESC> m_inputElements; /**< Input Element vector.*/
  };
}