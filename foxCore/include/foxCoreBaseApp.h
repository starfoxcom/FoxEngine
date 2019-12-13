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

#include "foxPrerequisitesUtilities.h"
#include "foxCoreRenderWindow.h"
#include "foxMatrix4.h"


namespace foxEngineSDK
{


  /**
   * Forward Declarations
   */
  class foxModel;

  class FOX_CORE_EXPORT foxBaseApp
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxBaseApp();

    /**
     * @brief Default destructor.
     */
    ~foxBaseApp();

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

    foxRenderWindow m_renderWindow;

    int32 m_RSValue = 1;

    foxModel * m_model;

    Matrix4 m_world;
    Matrix4 m_view;
    Matrix4 m_projection;
    Vector4 m_meshColor;

    Vector4 m_eye;
    Vector4 m_at;
    Vector4 m_up;

    struct constantBuffer
    {
      Matrix4 world;
      Matrix4 view;
      Matrix4 projection;
      Vector4 meshColor;
    };
  };
}