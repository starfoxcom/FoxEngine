#pragma once
/**
 * @file foxDXDevice.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Device Class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"


namespace foxEngineSDK
{

  /**
   * Forward Declarations
   */
  class DXVertexShader;
  class DXPixelShader;
  class DXInputLayout;
  class DXVertexBuffer;
  class DXIndexBuffer;


  class DXDevice
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXDevice();

    /**
     * @brief Default destructor.
     */
    ~DXDevice();

    /**
     * @brief Gets the DirectX Device.
     */
    ID3D11Device * getDevice();

    /**
     * @brief Gets the DirectX Device reference.
     */
    ID3D11Device ** getDeviceRef();

    /**
     * @brief Create the DirectX Render Target View.
     * @param _backBuffer The Back Buffer.
     * @param _renderTargetViewRef The Render Target View reference.
     */
    bool createRenderTargetView(
      ID3D11Texture2D * _backBuffer,
      ID3D11RenderTargetView ** _renderTargetViewRef);

    /**
     * @brief Create the DirectX texture.
     * @param _textureDesc The texture Desc.
     * @param _texture The Texture object.
     * @param _initData The texture initial data.
     */
    bool createTexture2D(
      D3D11_TEXTURE2D_DESC * _textureDesc,
      ID3D11Texture2D ** _texture,
      D3D11_SUBRESOURCE_DATA * _initData = 0);

    /**
     * @brief Create the DirectX Depth Stencil View.
     * @param _depthStencilBuffer The Depth Stencil Buffer.
     * @param _depthStencilView The Depth Stencil View object.
     * @param _depthStencilViewDesc The Depth Stencil View Desc.
     */
    bool createDepthStencilView(
      ID3D11Texture2D * _depthStencilBuffer,
      ID3D11DepthStencilView ** _depthStencilView,
      D3D11_DEPTH_STENCIL_VIEW_DESC * _depthStencilViewDesc = 0);

    /**
     * @brief Create the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    bool createVertexShader(DXVertexShader * _vertexShader);

    /**
     * @brief Create the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    bool createPixelShader(DXPixelShader * _pixelShader);

    /**
     * @brief Create the DirectX Input Layout.
     * @param _inputLayout The Graphics API Input Layout.
     */
    bool createInputLayout(DXInputLayout * _inputLayout, DXVertexShader * _vertexShader);

    /**
     * @brief Create the DirectX Vertex Buffer.
     * @param _vertexBuffer The Graphics API Vertex Buffer.
     * @param _data The vertex data.
     * @param _dataSize The vertex data size in bytes.
     * @param _length The length of the vertex data.
     */
    bool createVertexBuffer(DXVertexBuffer * _vertexBuffer, const void * _data, uint32 _dataSize);

    /**
     * @brief Create the DirectX Index Buffer.
     * @param _vertexBuffer The Graphics API Index Buffer.
     * @param _data The index data.
     * @param _dataSize The index data size in bytes.
     * @param _length The length of the index data.
     */
    bool createIndexBuffer(DXIndexBuffer * _indexBuffer, const void * _data, uint32 _dataSize, uint32 _length);

  private:

    ID3D11Device * m_device; /**< Device class object member.*/
  };
}