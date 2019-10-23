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
  class DXSwapChain;
  class DXDevice;
  class DXDeviceContext;
  class DXTexture;
  class DXRenderTargetView;
  class DXDepthStencilView;
  class DXWireframeRS;
  class DXSolidRS;
  class DXVertexShader;
  class DXPixelShader;
  class DXInputLayout;
  class DXVertexBuffer;
  class DXIndexBuffer;
  class DXConstantBuffer;

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
     * @brief Initialize the DirectX Graphics API.
     */
    bool initDXGraphicsAPI(HWND _windowHandle);

    /**
     * @brief Gets the Device.
     */
    ID3D11Device * getDevice();

    /**
     * @brief Gets the Device Context.
     */
    ID3D11DeviceContext * getDeviceContext();

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
     * @brief Creates the Vertex Shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

    /**
 * @brief Creates the Vertex Shader.
 * @param _filename The name of the shader file.
 * @param _entryPoint The entry point for the vertex shader.
 * @param _shaderModel The shader model.
 */
    bool createPixelShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

    /**
     * @brief Creates the Input Layout.
     */
    bool createInputLayout();

    /**
     * @brief Sets the Input Layout.
     */
    void setInputLayout();

    /**
     * @brief Creates the Vertex Buffer.
     * @param _data The vertex data.
     * @param _dataSize The vertex data size in bytes.
     * @param _length The length of the vertex data.
     */
    bool createVertexBuffer(const void * _data, uint32 _dataSize);

    /**
     * @brief Sets the Vertex Buffer.
     * @param _structSize The vertex struct size in bytes.
     * @param _startSlot The input slot in which to start binding vertex buffers.
     * @param _numOfBuffers The number of vertex buffers we are binding to the input slots.
     */
    void setVertexBuffer(uint32 _structSize, uint32 _startSlot = 0, uint32 _numOfBuffers = 1);

    /**
     * @brief Creates the Index Buffer.
     * @param _data The index data.
     * @param _dataSize The index data size in bytes.
     */
    bool createIndexBuffer(const void * _data, uint32 _dataSize);

    /**
     * @brief Sets the Index Buffer.
     * @param _format The format of the indices.
     * @param _offset The offset measured in bytes, from the start of the index buffer 
                      to the position in the index buffer the input assembly should start 
                      reading the data.
     */
    void setIndexBuffer(FOXGI_FORMAT::E _format = FOXGI_FORMAT::E::K_R32_UINT, uint32 _offset = 0);

    /**
     * @brief Sets the primitive topology.
     * @param _topology The topology to set.
     */
    void setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology);

    /**
     * @brief Creates the Constant Buffer.
     * @param _structSize The constant struct size in bytes.
     * @param _data The constant buffer data.
     */
    bool createConstantBuffer(uint32 _structSize);

    /**
     * @brief Updates the Constant Buffer data.
     * @param _data The constant buffer data to update with.
     */
    void updateConstantBuffer(const void * _data);

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
     * @brief Sets the Vertex Shader.
     */
    void setVertexShader();

    /**
     * @brief Sets the Constant Buffer.
     */
    void setConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBufers = 1);

    /**
     * @brief Sets the Pixel Shader.
     */
    void setPixelShader();

    /**
     * @brief Sets the Solid Rasterizer State.
     */
    void setSolidRS();

    /**
     * @brief Sets the Wire frame Rasterizer State.
     */
    void setWireframeRS();

    /**
     * @brief Draws the vertices.
     * @param _vertexCount The total count of vertices.
     * @param _vertexStart The starting point of the vertices.
     */
    void draw(uint32 _vertexCount, uint32 _vertexStart);

    /**
     * @brief Draws the indices.
     * @param _indexCount The total count of indices.
     * @param _indexStart The starting point of the vertices.
     * @param _vertexStart _The starting point of the indices.
     */
    void drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart);

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
    bool createDeviceAndSwapChain(HWND _windowHandle);

    /**
     * @brief Creates the Render Target View.
     */
    bool createRenderTargetView();

    /**
     * @brief Creates the Depth Stencil View.
     */
    bool createDepthStencilView(HWND _windowHandle);

    /**
     * @brief Creates the Solid Rasterizer State.
     */
    bool createSolidRS();

    /**
     * @brief Creates the Wire frame Rasterizer State.
     */
    bool createWireframeRS();

    DXSwapChain * m_swapChain; /**< Swap Chain member.*/

    DXDevice * m_device; /**< Device class object member.*/

    DXDeviceContext * m_deviceContext; /**< Device Context member.*/

    DXRenderTargetView * m_renderTargetView; /**< Render Target View member.*/

    DXTexture * m_depthStencilBuffer; /**< Depth Stencil Buffer member.*/

    DXDepthStencilView * m_depthStencilView; /**< Depth Stencil View member.*/

    DXSolidRS * m_solidRS; /**< Solid Rasterizer state member.*/

    DXWireframeRS * m_wireframeRS; /**< Wire frame Rasterizer state member.*/

    DXVertexShader * m_vertexShader; /**< Vertex Shader member.*/

    DXPixelShader * m_pixelShader; /**< Pixel Shader member.*/

    DXInputLayout * m_inputLayout; /**< Input Layout member.*/

    DXVertexBuffer * m_vertexBuffer; /**< Vertex Buffer member.*/

    DXIndexBuffer * m_indexBuffer; /**< Index Buffer member.*/

    DXConstantBuffer * m_constantBuffer; /**< Constant Buffer member.*/

  };
}


