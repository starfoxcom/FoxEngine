#pragma once
/**
 * @file foxCoreGraphicsAPI.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/11/23
 * @brief Implementation of Graphics API
 */
#include <windows.h>

#include "foxModule.h"

#include "foxCoreGraphicsCommons.h"
#include "foxCoreDefines.h"

namespace foxEngineSDK
{
  
  class FOX_CORE_EXPORT foxGraphicsAPI : public Module<foxGraphicsAPI>
  {
  public:

    /**
     * @brief Default constructor
     */
    foxGraphicsAPI();

    /**
     * @brief Default destructor.
     */
    ~foxGraphicsAPI();

    /**
     * @brief Initialize the Graphics API.
     * @param _windowHandle The window handler.
     */
    virtual bool initGraphicsAPI(HWND _windowHandle) = 0;

    /**
     * @brief Gets the Device.
     */
    virtual void * getDevice() = 0;

    /**
     * @brief Gets the Device Context.
     */
    virtual void * getDeviceContext() = 0;

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
    virtual void addInputElement(
      const char * _semanticName,
      uint32 _semanticIndex,
      FOXGI_FORMAT::E _format,
      uint32 _inputSlot,
      uint32 _alignedByteOffset,
      FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
      uint32 _instanceDataStepRate) = 0;
  private:

  };
}