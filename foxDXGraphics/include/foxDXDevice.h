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
  class foxDXVertexShader;
  class foxDXPixelShader;
  class foxDXInputLayout;
  class foxDXVertexBuffer;
  class foxDXIndexBuffer;
  class foxDXConstantBuffer;
  class foxDXRasterizerState;
  class foxDXTexture;
  class foxDXShaderResourceView;
  class foxDXSamplerState;

  class foxDXDevice
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXDevice();

    /**
     * @brief Default destructor.
     */
    ~foxDXDevice();

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
      D3D11_SUBRESOURCE_DATA * _initData = NULL);

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
     * @brief Create the DirectX Rasterizer State.
     * @param _raterizerState The Graphics API Rasterizer State.
     * @param _rasterizerDesc The Rasterizer State Desc.
     */
    bool createRasterizerState(
      foxDXRasterizerState * _rasterizerState,
      D3D11_RASTERIZER_DESC _rasterizerDesc);

    /**
     * @brief Create the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    bool createVertexShader(foxDXVertexShader * _vertexShader);

    /**
     * @brief Create the DirectX Vertex Shader.
     * @param _vertexShader The Graphics API Vertex Shader.
     */
    bool createPixelShader(foxDXPixelShader * _pixelShader);

    /**
     * @brief Create the DirectX Input Layout.
     * @param _inputLayout The Graphics API Input Layout.
     */
    bool createInputLayout(foxDXInputLayout * _inputLayout, foxDXVertexShader * _vertexShader);

    /**
     * @brief Create the DirectX Vertex Buffer.
     * @param _vertexBuffer The Graphics API Vertex Buffer.
     * @param _data The vertex data.
     * @param _dataSize The vertex data size in bytes.
     * @param _length The length of the vertex data.
     */
    bool createVertexBuffer(foxDXVertexBuffer * _vertexBuffer, const void * _data, uint32 _dataSize);

    /**
     * @brief Create the DirectX Index Buffer.
     * @param _vertexBuffer The Graphics API Index Buffer.
     * @param _data The index data.
     * @param _dataSize The index data size in bytes.
     */
    bool createIndexBuffer(foxDXIndexBuffer * _indexBuffer, const void * _data, uint32 _dataSize);

    /**
     * @brief Create the DirectX Constant Buffer.
     * @param _constantBuffer The Graphics API Constant Buffer.
     * @param _structSize The constant buffer struct size in bytes.
     */
    bool createConstantBuffer(
      foxDXConstantBuffer * _constantBuffer,
      uint32 _structSize);

    /**
     * @brief Create the DirectX Shader Resource View.
     * @param _texture The Graphics API Texture.
     * @param _shaderResourceView The Graphics API Shader Resource View.
     */
    bool createShaderResourceView(
      foxDXTexture * _texture,
      foxDXShaderResourceView * _shaderResourceView);

    /**
     * @brief Create the DirectX Sampler State.
     * @param _samplerState The Graphics API Sampler State.
     */
    bool createSamplerState(
    foxDXSamplerState * _samplerState);


  private:

    ID3D11Device * m_device = nullptr; /**< Device class object member.*/
  };
}