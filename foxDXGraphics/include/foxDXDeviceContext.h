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
  class DXInputLayout;
  class DXVertexBuffer;
  class DXIndexBuffer;

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
     */
    void setVertexBuffer(
      DXVertexBuffer * _vertexBuffer,
      uint32 _startSlot,
      uint32 _numOfBuffers,
      const void * _data);

    /**
     * @brief 
     * @param _indexBuffer The Graphics API Index Buffer.
     * @param _format The indices format.
     * @param _offset The indices offset.
     */
    void setIndexBuffer(
      DXIndexBuffer * _indexBuffer,
      FOXGI_FORMAT::E _format,
      uint32 _offset);

  private:

    ID3D11DeviceContext * m_deviceContext; /**< Device Context class object member.*/
  };
}