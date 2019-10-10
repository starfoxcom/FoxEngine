/**
 * Includes
 */
#include "foxDXDevice.h"
#include "foxDXVertexShader.h"
#include "foxDXPixelShader.h"
#include "foxDXInputLayout.h"
#include "foxDXVertexBuffer.h"
#include "foxLog.h"

namespace foxEngineSDK
{

  DXDevice::DXDevice()
  {
  }

  DXDevice::~DXDevice()
  {
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
      _depthStencilView);;
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
      Log(Log::LOGERROR, true) << "Vertex Shader couldn't be created";
      return false;
    }

    Log() << "Vertex Shader created successfully";
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
      Log(Log::LOGERROR, true) << "Pixel Shader couldn't be created";
      return false;
    }

    _pixelShader->getBlob()->Release();
    Log() << "Pixel Shader created successfully";
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
      Log(Log::LOGERROR, true) << "Input layout couldn't be created";
      return false;
    }
    _vertexShader->getBlob()->Release();
    Log() << "Input layout created successfully";
    return true;
  }

  bool DXDevice::createVertexBuffer(
    DXVertexBuffer * _vertexBuffer,
    const void * _data,
    uint32 _length)
  {

    _vertexBuffer->setVertexBufferDesc(_data, _length);

    _vertexBuffer->setSubResourceData(_data);

    if (FAILED(m_device->CreateBuffer(
      &_vertexBuffer->getBufferDesc(),
      &_vertexBuffer->getSubResourceData(),
      _vertexBuffer->getBufferRef())))
    {
      
      Log(Log::LOGERROR, true) << "Vertex buffer couldn't be created";
      return false;
    }

    Log() << "Vertex buffer created successfully";
    return true;
  }
}