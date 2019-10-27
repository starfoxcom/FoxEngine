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
#include "foxGraphicsCommons.h"

namespace foxEngineSDK
{

  /**
   * Forward declarations
   */
  class DXRenderTargetView;
  class DXDepthStencilView;
  class DXRasterizerState;
  class DXVertexShader;
  class DXPixelShader;
  class DXInputLayout;
  class DXVertexBuffer;
  class DXIndexBuffer;
  class DXConstantBuffer;
  class DXShaderResourceView;

  class DXDeviceContext
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXDeviceContext();

    /**
     * @brief DEfault destructor.
     */
    ~DXDeviceContext();

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
    void clearRenderTargetView(DXRenderTargetView * _renderTargetView, float * _RGBAColor);

    /**
     * @brief Clears the DirectX Depth Stencil View.
     * @param _depthStencilView The Graphics API Depth Stencil View.
     */
    void clearDepthStencilView(DXDepthStencilView * _depthStencilView);

    /**
     * @brief Sets the DirectX Input Layout.
     * @param _inputLayout The Graphics API Input Layout.
     */
    void setInputLayout(DXInputLayout * _inputLayout);

    /**
     * @brief Sets the DirectX Vertex Buffer.
     * @param _vertexBuffer The Graphics API Vertex Buffer.
     * @param _startSlot The input slot in which to start binding vertex buffers.
     * @param _numOfBuffers The number of vertex buffers we are binding to the input slots.
     * @param _structSize The vertex struct size in bytes.
     */
    void setVertexBuffer(
      DXVertexBuffer * _vertexBuffer,
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
      DXIndexBuffer * _indexBuffer,
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
    void updateConstantBuffer(DXConstantBuffer * _constantBuffer, const void * _data);

    /**
     * @brief Sets the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    void setVertexShader(DXVertexShader * _vertexShader);

    /**
     * @brief Sets the DirectX Constant Buffer.
     * @param _constantBuffer The Graphics API Constant Buffer.
     * @param _startSlot Index into the device's zero-based array to begin setting 
                         constant buffers to.
     * @param _numOfBuffers Number of buffers to set.
     */
    void setConstantBuffers(
      DXConstantBuffer * _constantBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers);

    /**
     * @brief Sets the DirectX Shader Resources.
     * @param
     */
    void setShaderResources(
      DXShaderResourceView * _shaderResourceViews,
      uint32 _startSlot,
      uint32 _numOfViews);

    /**
     * @brief Sets the DirectX Pixel Shader.
     * @param _pixelShader The Graphics API Pixel Shader.
     */
    void setPixelShader(DXPixelShader * _pixelShader);

    /**
     * @brief Sets the DirectX Rasterizer State.
     * @param _rasterizerState The Graphics API Rasterizer state.
     */
    void setRasterizerState(DXRasterizerState * _rasterizerState);

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

  private:

    ID3D11DeviceContext * m_deviceContext; /**< Device Context class object member.*/
  };
}