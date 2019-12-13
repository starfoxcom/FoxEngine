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
     * @brief Adds an Input Element to the Input Layout.
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

    /**
     * @brief Creates the Vertex Shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    virtual bool createVertexShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel) = 0;

    /**
     * @brief Creates the Vertex Shader.
     * @param _filename The name of the shader file.
     * @param _entryPoint The entry point for the vertex shader.
     * @param _shaderModel The shader model.
     */
    virtual bool createPixelShader(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel) = 0;

    /**
     * @brief Creates the Input Layout.
     */
    virtual bool createInputLayout() = 0;

    /**
     * @brief Sets the Input Layout.
     */
    virtual void setInputLayout() = 0;

    /**
     * @brief Creates the Vertex Buffer.
     * @param _data The vertex data.
     * @param _dataSize The vertex data size in bytes.
     * @param _length The length of the vertex data.
     */
    virtual bool createVertexBuffer(const void * _data, uint32 _dataSize) = 0;

    /**
     * @brief Sets the Vertex Buffer.
     * @param _structSize The vertex struct size in bytes.
     * @param _startSlot The input slot in which to start binding vertex buffers.
     * @param _numOfBuffers The number of vertex buffers we are binding to the input slots.
     */
    virtual void setVertexBuffer(
      uint32 _structSize,
      uint32 _startSlot = 0,
      uint32 _numOfBuffers = 1) = 0;

    /**
     * @brief Creates the Index Buffer.
     * @param _data The index data.
     * @param _dataSize The index data size in bytes.
     */
    virtual bool createIndexBuffer(const void * _data, uint32 _dataSize) = 0;

    /**
     * @brief Sets the Index Buffer.
     * @param _format The format of the indices.
     * @param _offset The offset measured in bytes, from the start of the index buffer
                      to the position in the index buffer the input assembly should start
                      reading the data.
     */
    virtual void setIndexBuffer(
      FOXGI_FORMAT::E _format = FOXGI_FORMAT::E::K_R32_UINT,
      uint32 _offset = 0) = 0;

    /**
     * @brief Sets the primitive topology.
     * @param _topology The topology to set.
     */
    virtual void setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology) = 0;

    /**
     * @brief Creates the Constant Buffer.
     * @param _structSize The constant struct size in bytes.
     * @param _data The constant buffer data.
     */
    virtual bool createConstantBuffer(uint32 _structSize) = 0;

    /**
     * @brief Creates the Shader Resource View.
     * @param _data The resource data to create with.
     * @param _width The resource width.
     * @param _height The resource height.
     */
    virtual bool createShaderResourceViewFromFile(
      const void * _data,
      uint32 _width,
      uint32 _height) = 0;

    /**
     * @brief Creates the Sampler State.
     */
    virtual bool createSamplerState() = 0;

    /**
     * @brief Updates the Constant Buffer data.
     * @param _data The constant buffer data to update with.
     */
    virtual void updateConstantBuffer(const void * _data) = 0;

    /**
     * @brief Clears the Render Target View.
     * @param _RGBAColor The color to clean with.
     */
    virtual void clearRenderTargetView(float * _RGBAColor) = 0;

    /**
     * @brief Clears the Depth Stencil View.
     */
    virtual void clearDepthStencilView() = 0;

    /**
     * @brief Sets the Vertex Shader.
     */
    virtual void setVertexShader() = 0;

    /**
     * @brief Sets the Vertex Constant Buffer.
     * @param _startSlot The starting index slot of the constant buffer.
     * @param _numOfBuffers The number of constant buffers.
     */
    virtual void setVSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1) = 0;

    /**
     * @brief Sets the Pixel Constant Buffer.
     * @param _startSlot The starting index slot of the constant buffer.
     * @param _numOfBuffers The number of constant buffer.
     */
    virtual void setPSConstantBuffers(uint32 _startSlot = 0, uint32 _numOfBuffers = 1) = 0;

    /**
     * @brief Sets the Shader Resources.
     * @param _startSlot The starting index of the shader resource.
     * @param _numOfViews The number of shader Resource Views.
     */
    virtual void setShaderResources(uint32 _startSlot = 0, uint32 _numOfViews = 1) = 0;

    /**
     * @brief Sets the Pixel Shader.
     */
    virtual void setPixelShader() = 0;

    /**
     * @brief Sets the Solid Rasterizer State.
     */
    virtual void setSolidRS() = 0;

    /**
     * @brief Sets the Wire frame Rasterizer State.
     */
    virtual void setWireframeRS() = 0;

    /**
     * @brief Sets the Sampler State.
     * @param _startSlot The starting index slot of the Sampler State.
     * @param _numOfSamplers The number of Sampler States.
     */
    virtual void setPSSamplerState(uint32 _startSlot = 0, uint32 _numOfSamplers = 1) = 0;

    /**
     * @brief Draws the vertices.
     * @param _vertexCount The total count of vertices.
     * @param _vertexStart The starting point of the vertices.
     */
    virtual void draw(uint32 _vertexCount, uint32 _vertexStart) = 0;

    /**
     * @brief Draws the indices.
     * @param _indexCount The total count of indices.
     * @param _indexStart The starting point of the vertices.
     * @param _vertexStart _The starting point of the indices.
     */
    virtual void drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart) = 0;

    /**
     * @brief Present the information from the back buffer to the front buffer.
     */
    virtual void present() = 0;

    /**
     * @brief Test function to know if dll access is possible.
     */
    virtual void test() = 0;
  private:

  };
}