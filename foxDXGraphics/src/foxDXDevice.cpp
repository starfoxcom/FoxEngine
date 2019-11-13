/**
 * Includes
 */
#include "foxDXDevice.h"
#include "foxDXRasterizerState.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXConstantBuffer.h"
#include "foxDXTexture.h"
#include "foxDXShaderResourceView.h"
#include "foxDXSamplerState.h"
#include "foxLog.h"

namespace foxEngineSDK
{

  DXDevice::DXDevice()
  {
  }

  DXDevice::~DXDevice()
  {
    if (m_device) m_device->Release();
    m_device = nullptr;
  }

  ID3D11Device * DXDevice::getDevice()
  {
    return m_device;
  }

  ID3D11Device ** DXDevice::getDeviceRef()
  {
    return &m_device;
  }

  bool DXDevice::createRenderTargetView(
    ID3D11Texture2D * _backBuffer,
    ID3D11RenderTargetView ** _renderTargetViewRef)
  {
    return m_device->CreateRenderTargetView(_backBuffer, 0, _renderTargetViewRef);
  }

  bool DXDevice::createTexture2D(
    D3D11_TEXTURE2D_DESC * _textureDesc,
    ID3D11Texture2D ** _texture,
    D3D11_SUBRESOURCE_DATA * _initData)
  {
    return m_device->CreateTexture2D(_textureDesc, _initData, _texture);
  }

  bool DXDevice::createDepthStencilView(
    ID3D11Texture2D * _depthStencilBuffer,
    ID3D11DepthStencilView ** _depthStencilView,
    D3D11_DEPTH_STENCIL_VIEW_DESC * _depthStencilViewDesc)
  {
    return m_device->CreateDepthStencilView(
      _depthStencilBuffer,
      _depthStencilViewDesc,
      _depthStencilView);
  }
  
  bool DXDevice::createRasterizerState(DXRasterizerState * _rasterizerState, D3D11_RASTERIZER_DESC _rasterizerDesc)
  {

    if (FAILED(m_device->CreateRasterizerState(
      &_rasterizerDesc,
      _rasterizerState->getRasterizerStateRef())))
    {

      Log(Log::LOGERROR, true) << "Rasterizer state couldn't be created.";
      return false;
    }

    Log() << "Rasterizer state created successfully.";
    return true;
  }

  bool DXDevice::createVertexShader(DXVertexShader * _vertexShader)
  {
    if (FAILED(m_device->CreateVertexShader(
      _vertexShader->getBlob()->GetBufferPointer(),
      _vertexShader->getBlob()->GetBufferSize(),
      NULL,
      _vertexShader->getVertexShaderRef())))
    {

      _vertexShader->getBlob()->Release();
      Log(Log::LOGERROR, true) << "Vertex Shader couldn't be created.";
      return false;
    }

    Log() << "Vertex Shader created successfully.";
    return true;
  }

  bool DXDevice::createPixelShader(DXPixelShader * _pixelShader)
  {
    if (FAILED(m_device->CreatePixelShader(
      _pixelShader->getBlob()->GetBufferPointer(),
      _pixelShader->getBlob()->GetBufferSize(),
      NULL,
      _pixelShader->getPixelShaderRef())))
    {

      _pixelShader->getBlob()->Release();
      Log(Log::LOGERROR, true) << "Pixel Shader couldn't be created.";
      return false;
    }

    _pixelShader->getBlob()->Release();
    Log() << "Pixel Shader created successfully.";
    return true;
  }

  bool DXDevice::createInputLayout(
    DXInputLayout * _inputLayout,
    DXVertexShader * _vertexShader)
  {

    if (FAILED(m_device->CreateInputLayout(
      _inputLayout->getInputElementDesc(),
      _inputLayout->getInputElementsNum(),
      _vertexShader->getBlob()->GetBufferPointer(),
      _vertexShader->getBlob()->GetBufferSize(),
      _inputLayout->getInputLayoutRef())))
    {
      _vertexShader->getBlob()->Release();
      Log(Log::LOGERROR, true) << "Input layout couldn't be created.";
      return false;
    }
    _vertexShader->getBlob()->Release();
    Log() << "Input layout created successfully.";
    return true;
  }

  bool DXDevice::createVertexBuffer(
    DXVertexBuffer * _vertexBuffer,
    const void * _data,
    uint32 _dataSize)
  {

    D3D11_BUFFER_DESC bufferDesc;

    ZeroMemory(&bufferDesc, sizeof(bufferDesc));
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = _dataSize;
    bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;
    bufferDesc.StructureByteStride = 0;

    D3D11_SUBRESOURCE_DATA initData;

    ZeroMemory(&initData, sizeof(initData));
    initData.pSysMem = _data;

    if (FAILED(m_device->CreateBuffer(&bufferDesc, &initData, _vertexBuffer->getBufferRef())))
    {
      
      Log(Log::LOGERROR, true) << "Vertex buffer couldn't be created.";
      return false;
    }

    Log() << "Vertex buffer created successfully.";
    return true;
  }
  bool DXDevice::createIndexBuffer(
    DXIndexBuffer * _indexBuffer,
    const void * _data,
    uint32 _dataSize)
  {
    D3D11_BUFFER_DESC bufferDesc;

    ZeroMemory(&bufferDesc, sizeof(bufferDesc));
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = _dataSize;
    bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;
    bufferDesc.StructureByteStride = 0;

    D3D11_SUBRESOURCE_DATA initData;

    ZeroMemory(&initData, sizeof(initData));
    initData.pSysMem = _data;

    if (FAILED(m_device->CreateBuffer(
      &bufferDesc,
      &initData,
      _indexBuffer->getBufferRef())))
    {

      Log(Log::LOGERROR, true) << "Index buffer couldn't be created.";
      return false;
    }

    Log() << "Index buffer created successfully.";
    return true;
  }
  bool DXDevice::createConstantBuffer(
    DXConstantBuffer * _constantBuffer,
    uint32 _structSize)
  {

    D3D11_BUFFER_DESC bufferDesc;

    ZeroMemory(&bufferDesc, sizeof(bufferDesc));
    bufferDesc.Usage = D3D11_USAGE_DEFAULT;
    bufferDesc.ByteWidth = _structSize;
    bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    bufferDesc.CPUAccessFlags = 0;
    bufferDesc.MiscFlags = 0;
    bufferDesc.StructureByteStride = 0;

    if (FAILED(m_device->CreateBuffer(
      &bufferDesc,
      NULL,
      _constantBuffer->getBufferRef())))
    {

      Log(Log::LOGERROR, true) << "Constant buffer couldn't be created.";
      return false;
    }

    Log() << "Constant buffer created successfully.";
    return true;
  }
  bool DXDevice::createShaderResourceView(
    DXTexture * _texture,
    DXShaderResourceView * _shaderResourceView)
  {

    if (FAILED(m_device->CreateShaderResourceView(
      _texture->getTexture(),
      NULL,
      _shaderResourceView->getShaderResourceViewRef())))
    {

      Log(Log::LOGERROR, true) << "Shader Resource View couldn't be created.";
      return false;
    }

    Log() << "Shader Resource View created successfully.";
    return true;
  }

  bool DXDevice::createSamplerState(DXSamplerState * _samplerState)
  {

    D3D11_SAMPLER_DESC samplerDesc;

    ZeroMemory(&samplerDesc, sizeof(samplerDesc));
    samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    samplerDesc.MinLOD = 0;
    samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

    if (FAILED(m_device->CreateSamplerState(&samplerDesc, _samplerState->getSamplerStateRef())))
    {

      Log(Log::LOGERROR, true) << "Sampler State couldn't be created.";
      return false;
    }

    Log() << "Sampler State created successfully.";

    return true;
  }
}