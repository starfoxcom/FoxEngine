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

#include "foxPrerequisitesUtilities.h"

#include "foxCoreGraphicsAPI.h"

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
  class DXShaderResourceView;
  class DXSamplerState;

  class FOX_GRAPHICS_EXPORT DXGraphicsAPI : public foxGraphicsAPI
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
     * @param _windowHandle The window handler.
     */
    bool initGraphicsAPI(HWND _windowHandle);

    /**
     * @brief Gets the Device.
     */
    void * getDevice() override;

    /**
     * @brief Gets the Device Context.
     */
    void * getDeviceContext() override;

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
      uint32 _instanceDataStepRate) override;

    /**
     * @brief Creates the Vertex Shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel) override;

    /**
     * @brief Creates the Vertex Shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    bool createPixelShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel) override;

    /**
     * @brief Creates the Input Layout.
     */
    bool createInputLayout() override;

    /**
     * @brief Sets the Input Layout.
     */
    void setInputLayout() override;

    /**
     * @brief Creates the Vertex Buffer.
     * @param _data The vertex data.
     * @param _dataSize The vertex data size in bytes.
     * @param _length The length of the vertex data.
     */
    bool createVertexBuffer(const void * _data, uint32 _dataSize) override;

    /**
     * @brief Sets the Vertex Buffer.
     * @param _structSize The vertex struct size in bytes.
     * @param _startSlot The input slot in which to start binding vertex buffers.
     * @param _numOfBuffers The number of vertex buffers we are binding to the input slots.
     */
    void setVertexBuffer(
      uint32 _structSize,
      uint32 _startSlot = 0,
      uint32 _numOfBuffers = 1) override;

    /**
     * @brief Creates the Index Buffer.
     * @param _data The index data.
     * @param _dataSize The index data size in bytes.
     */
    bool createIndexBuffer(const void * _data, uint32 _dataSize) override;

    /**
     * @brief Sets the Index Buffer.
     * @param _format The format of the indices.
     * @param _offset The offset measured in bytes, from the start of the index buffer 
                      to the position in the index buffer the input assembly should start 
                      reading the data.
     */
    void setIndexBuffer(
      FOXGI_FORMAT::E _format = FOXGI_FORMAT::E::K_R32_UINT,
      uint32 _offset = 0) override;

    /**
     * @brief Sets the primitive topology.
     * @param _topology The topology to set.
     */
    void setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology) override;

    /**
     * @brief Creates the Constant Buffer.
     * @param _structSize The constant struct size in bytes.
     * @param _data The constant buffer data.
     */
    bool createConstantBuffer(uint32 _structSize) override;

    /**
     * @brief Creates the Shader Resource View.
     * @param _data The resource data to create with.
     * @param _width The resource width.
     * @param _height The resource height.
     */
    bool createShaderResourceViewFromFile(
      const void * _data,
      uint32 _width,
      uint32 _height) override;

    /**
     * @brief Creates the Sampler State.
     */
    bool createSamplerState() override;

    /**
     * @brief Updates the Constant Buffer data.
     * @param _data The constant buffer data to update with.
     */
    void updateConstantBuffer(const void * _data) override;

    /**
     * @brief Clears the Render Target View.
     * @param _RGBAColor The color to clean with.
     */
    void clearRenderTargetView(float * _RGBAColor) override;

    /**
     * @brief Clears the Depth Stencil View.
     */
    void clearDepthStencilView() override;

    /**
     * @brief Sets the Vertex Shader.
     */
    void setVertexShader() override;

    /**
     * @brief Sets the Vertex Constant Buffer.
     * @param _startSlot The starting index slot of the constant buffer.
     * @param _numOfBuffers The number of constant buffers.
     */
    void setVSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1) override;

    /**
     * @brief Sets the Pixel Constant Buffer.
     * @param _startSlot The starting index slot of the constant buffer.
     * @param _numOfBuffers The number of constant buffer.
     */
    void setPSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1) override;

    /**
     * @brief Sets the Shader Resources.
     * @param _startSlot The starting index of the shader resource.
     * @param _numOfViews The number of shader Resource Views.
     */
    void setShaderResources(uint32 _startSlot = 0, uint32 _numOfViews = 1) override;

    /**
     * @brief Sets the Pixel Shader.
     */
    void setPixelShader() override;

    /**
     * @brief Sets the Solid Rasterizer State.
     */
    void setSolidRS() override;

    /**
     * @brief Sets the Wire frame Rasterizer State.
     */
    void setWireframeRS() override;

    /**
     * @brief Sets the Sampler State.
     * @param _startSlot The starting index slot of the Sampler State.
     * @param _numOfSamplers The number of Sampler States.
     */
    void setPSSamplerState(uint32 _startSlot = 0, uint32 _numOfSamplers = 1) override;

    /**
     * @brief Draws the vertices.
     * @param _vertexCount The total count of vertices.
     * @param _vertexStart The starting point of the vertices.
     */
    void draw(uint32 _vertexCount, uint32 _vertexStart) override;

    /**
     * @brief Draws the indices.
     * @param _indexCount The total count of indices.
     * @param _indexStart The starting point of the vertices.
     * @param _vertexStart _The starting point of the indices.
     */
    void drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart) override;

    /**
     * @brief Present the information from the back buffer to the front buffer.
     */
    void present() override;

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

    DXDevice * m_device = nullptr; /**< Device class object member.*/

    DXDeviceContext * m_deviceContext = nullptr; /**< Device Context member.*/

    DXSwapChain * m_swapChain = nullptr; /**< Swap Chain member.*/

    DXRenderTargetView * m_renderTargetView = nullptr; /**< Render Target View member.*/

    DXDepthStencilView * m_depthStencilView = nullptr; /**< Depth Stencil View member.*/

    DXTexture * m_depthStencilBuffer = nullptr; /**< Depth Stencil Buffer member.*/

    DXSolidRS * m_solidRS = nullptr; /**< Solid Rasterizer state member.*/

    DXWireframeRS * m_wireframeRS = nullptr; /**< Wire frame Rasterizer state member.*/

    DXVertexShader * m_vertexShader = nullptr; /**< Vertex Shader member.*/

    DXPixelShader * m_pixelShader = nullptr; /**< Pixel Shader member.*/

    DXInputLayout * m_inputLayout = nullptr; /**< Input Layout member.*/

    DXVertexBuffer * m_vertexBuffer = nullptr; /**< Vertex Buffer member.*/

    DXIndexBuffer * m_indexBuffer = nullptr; /**< Index Buffer member.*/

    DXConstantBuffer * m_constantBuffer = nullptr; /**< Constant Buffer member.*/

    DXTexture * m_diffuse = nullptr; /**< Diffuse Texture member.*/

    DXShaderResourceView * m_shaderResourceView = nullptr; /**< Shader Resource View member.*/

    DXSamplerState * m_samplerState = nullptr; /**< Sampler State member.*/

  };
}


