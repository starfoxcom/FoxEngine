#pragma once
/**
 * @file foxCoreBaseApp.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/12/09
 * @brief Core base application class.
 */

/**
 * Includes
 */
#include <windowsx.h>
#include <windows.h>

#include <foxCoreGraphicsAPI.h>

#include "foxCoreRenderWindow.h"
#include "foxPrerequisitesUtilities.h"


using namespace foxEngineSDK;

/**
 * Forward Declarations
 */

class FOX_CORE_EXPORT BaseApp
{
public:

  /**
   * @brief Default constructor.
   */
  BaseApp();

  /**
   * @brief Default destructor.
   */
  ~BaseApp();

  /**
   * @brief Starts the App.
   */
  bool run();

  /**
   * @brief Updates the App logic.
   */
  void update();

  /**
   * @brief Renders the App.
   */
  void render();

private:

  /**
   * @brief Starts up the module instance.
   * @param _dllName The dll name.
   * @param _dllMethod The dll method.
   */
  void loadLibrary(String _dllName, String _dllMethod);

  foxGraphicsAPI * m_graphicsAPI;

  CoreRenderWindow m_renderWindow;

  int32 m_RSValue = 1;

};