#pragma once
/**
 * @file foxDXGraphicsAPI.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Implementation of DirectX.
 */

/**
 * Includes
 */
#include <d3dcompiler.h>
#include <d3d11.h>

#include "foxGraphicsDefines.h"
#include "foxGraphicsCommons.h"

#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{
/**
 * Forward declarations
 */
  class DXRenderWindow;
  class DXSwapChain;
  class DXDevice;
  class DXDeviceContext;
  class DXTexture;
  class DXRenderTargetView;
  class DXDepthStencilView;
  class DXInputLayout;
  class DXVertexBuffer;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI
  {
  public:

    /**
     * @brief Default constructor
     */
    DXGraphicsAPI();

    /**
     * @brief Default destructor
     */
    ~DXGraphicsAPI();

    /**
     * @brief Initialize the graphics Window.
     * @param _hInstance The instance of the application.
     * @param _windowClass The name of the window class.
     * @param _windowTitle The title of the window.
     * @param _width The width of the window.
     * @param _height The height of the window.
     */
    bool initWindow(
      HINSTANCE _hInstance,
      std::string _windowClass,
      std::string _windowTitle,
      int32 _width,
      int32 _height);

    /**
     * @brief Process the messages of the window.
     */
    bool processMessages();

    /**
     * @brief Initialize the DirectX Graphics API.
     */
    bool initDXGraphicsAPI();

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
    void addInputElement(
      const char * _semanticName,
      uint32 _semanticIndex,
      FOXGI_FORMAT::E _format,
      uint32 _inputSlot,
      uint32 _alignedByteOffset,
      FOX_INPUT_CLASSIFICATION::E _inputSlotClass,
      uint32 _instanceDataStepRate);

    /**
     * @brief Creates the Input Layout.
     */
    bool createInputLayout();

    /**
     * @brief Creates the Vertex Buffer.
     * @param _data The vertex data.
     * @param _length The length of the vertex data.
     */
    bool createVertexBuffer(const void * _data, uint32 _length);

    /**
     * @brief Clears the Render Target View.
     * @param _RGBAColor The color to clean with.
     */
    void clearRenderTargetView(float * _RGBAColor);

    /**
     * @brief Clears the Depth Stencil View.
     */
    void clearDepthStencilView();

    /**
     * @brief Present the information from the back buffer to the front buffer.
     */
    void present();

    /**
     * @brief Cleans up the Graphics API.
     */
    void cleanUpDXGraphicsAPI();

  private:

    /**
     * @brief Creates the device and Swap Chain.
     */
    bool createDeviceAndSwapChain();

    /**
     * @brief Creates the Render Target View.
     */
    bool createRenderTargetView();

    /**
     * @brief Creates the Depth Stencil View.
     */
    bool createDepthStencilView();

    DXRenderWindow * m_renderWindow; /**< Render Window member.*/

    DXSwapChain * m_swapChain; /**< Swap Chain member.*/

    DXDevice * m_device; /**< Device class object member.*/

    DXDeviceContext * m_deviceContext; /**< Device Context member.*/

    DXRenderTargetView * m_renderTargetView; /**< Render Target View member.*/

    DXTexture * m_depthStencilBuffer; /**< Depth Stencil Buffer member.*/

    DXDepthStencilView * m_depthStencilView; /**< Depth Stencil View member.*/

    DXInputLayout * m_inputLayout; /**< Input Layout member.*/

    DXVertexBuffer * m_vertexBuffer; /**< Vertex Buffer member.*/


  };
}


