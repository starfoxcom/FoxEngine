#pragma once
/**
 * @file foxDXDeviceContext.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Device Context Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

#include "foxPrerequisitesUtilities.h"

#include "foxCoreGraphicsCommons.h"

namespace foxEngineSDK
{

  /**
   * Forward declarations
   */
  class foxDXRenderTargetView;
  class foxDXDepthStencilView;
  class foxDXRasterizerState;
  class foxDXVertexShader;
  class foxDXPixelShader;
  class foxDXInputLayout;
  class foxDXVertexBuffer;
  class foxDXIndexBuffer;
  class foxDXConstantBuffer;
  class foxDXShaderResourceView;
  class foxDXSamplerState;

  class foxDXDeviceContext
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXDeviceContext();

    /**
     * @brief DEfault destructor.
     */
    ~foxDXDeviceContext();

    /**
     * @brief Gets the DirectX Device Context.
     */
    ID3D11DeviceContext * getDeviceContext();

    /**
     * @brief Gets the DirectX Device Context reference.
     */
    ID3D11DeviceContext ** getDeviceContextRef();

    /**
     * @brief Clears the DirectX Render Target View.
     * @param _renderTargetView The Graphics API Render Target View.
     * @param _RGBAColor The color to clear with.
     */
    void clearRenderTargetView(foxDXRenderTargetView * _renderTargetView, float * _RGBAColor);

    /**
     * @brief Clears the DirectX Depth Stencil View.
     * @param _depthStencilView The Graphics API Depth Stencil View.
     */
    void clearDepthStencilView(foxDXDepthStencilView * _depthStencilView);

    /**
     * @brief Sets the DirectX Input Layout.
     * @param _inputLayout The Graphics API Input Layout.
     */
    void setInputLayout(foxDXInputLayout * _inputLayout);

    /**
     * @brief Sets the DirectX Vertex Buffer.
     * @param _vertexBuffer The Graphics API Vertex Buffer.
     * @param _startSlot The input slot in which to start binding vertex buffers.
     * @param _numOfBuffers The number of vertex buffers we are binding to the input slots.
     * @param _structSize The vertex struct size in bytes.
     */
    void setVertexBuffer(
      foxDXVertexBuffer * _vertexBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers,
      uint32 _structSize);

    /**
     * @brief Sets the DirectX Index Buffer.
     * @param _indexBuffer The Graphics API Index Buffer.
     * @param _format The indices format.
     * @param _offset The indices offset.
     */
    void setIndexBuffer(
      foxDXIndexBuffer * _indexBuffer,
      FOXGI_FORMAT::E _format,
      uint32 _offset);

    /**
     * @brief Sets the DirectX Primitive Topology.
     * @param _topology The topology to set.
     */
    void setPrimitiveTopology(FOX_PRIMITIVE_TOPOLOGY::E _topology);

    /**
     * @brief Updates DirectX the Constant Buffer.
     * @param _constnatBuffer The Graphics ÄPI Constant Buffer.
     * @param _data The Constant Buffer data.
     */
    void updateConstantBuffer(foxDXConstantBuffer * _constantBuffer, const void * _data);

    /**
     * @brief Sets the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    void setVertexShader(foxDXVertexShader * _vertexShader);

    /**
     * @brief Sets the DirectX Vertex Constant Buffer.
     * @param _constantBuffer The Graphics API Constant Buffer.
     * @param _startSlot Index into the device's zero-based array to begin setting 
                         constant buffers to.
     * @param _numOfBuffers Number of buffers to set.
     */
    void setVSConstantBuffers(
      foxDXConstantBuffer * _constantBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers);

    /**
     * @brief Sets the DirectX Pixel Constant Buffer.
     * @param _constantBuffer The Graphics API Constant Buffer.
     * @param _startSlot Index into the device's zero-based array to begin setting
                         constant buffers to.
     * @param _numOfBuffers Number of buffers to set.
     */
    void setPSConstantBuffers(
      foxDXConstantBuffer * _constantBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers);

    /**
     * @brief Sets the DirectX Shader Resources.
     * @param
     */
    void setShaderResources(
      foxDXShaderResourceView * _shaderResourceViews,
      uint32 _startSlot,
      uint32 _numOfViews);

    /**
     * @brief Sets the DirectX Pixel Shader.
     * @param _pixelShader The Graphics API Pixel Shader.
     */
    void setPixelShader(foxDXPixelShader * _pixelShader);

    /**
     * @brief Sets the DirectX Rasterizer State.
     * @param _rasterizerState The Graphics API Rasterizer state.
     */
    void setRasterizerState(foxDXRasterizerState * _rasterizerState);

    /**
     * @brief Sets the DirectX Sampler State.
     * @param _samplerState The Graphics API Sampler State.
     */
    void setPSSamplerState(foxDXSamplerState * _samplerState, uint32 _startSlot, uint32 _numOfSamplers);

    /**
     * @brief Draws the vertices.
     * @param _vertexCount The total count of vertices.
     * @param _vertexStart The starting point of the vertices.
     */
    void draw(uint32 _vertexCount, uint32 _vertexStart);

    /**
     * @brief Draws the indices.
     * @param _indexCount The total count of indices.
     * @param _indexStart The starting point of the indices.
     * @param _vertexStart _The starting point of the vertices.
     */
    void drawIndexed(uint32 _indexCount, uint32 _indexStart, uint32 _vertexStart);

  private:

    ID3D11DeviceContext * m_deviceContext = nullptr; /**< Device Context class object member.*/
  };
}