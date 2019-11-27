#pragma once
/**
 * @file foxCoreGraphicsAPI.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/11/23
 * @brief Implementation of Graphics API
 */
#include "foxCoreDefines.h"
#include "foxModule.h"
#include <windows.h>

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
  private:

  };
}