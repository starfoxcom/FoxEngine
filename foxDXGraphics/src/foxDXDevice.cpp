#include "foxDXDevice.h"
#include "foxDXVertexShader.h"
#include "foxDXInputLayout.h"
#include "foxDXPixelShader.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
#include "foxDXConstantBuffer.h"
#include "foxDXTexture.h"
#include "foxDXDepthStencilView.h"
#include "foxLog.h"


namespace foxEngineSDK
{

  DXDevice::DXDevice()
  {
  }


  DXDevice::~DXDevice()
  {
  }

  ID3D11Device ** DXDevice::getDeviceRef()
  {
    return &m_device;
  }

  ID3D11Device * DXDevice::getDevice()
  {
    return m_device;
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

  bool DXDevice::createInputLayout(DXInputLayout * _inputLayout, DXVertexShader * _vertexShader)
  {
    if (FAILED(m_device->CreateInputLayout(
      _inputLayout->getInputLayoutDesc(),
      _inputLayout->getInputLayoutNumElements(),
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
  bool DXDevice::createVertexBuffer(DXVertexBuffer * _vertexBuffer)
  {

    vertex vertices[]
    {
      { Vector3(-1.0f, 1.0f, -1.0f), Vector3(0.0f, 0.0f, 1.0f) },
      { Vector3(1.0f, 1.0f, -1.0f),  Vector3(0.0f, 1.0f, 0.0f) },
      { Vector3(1.0f, 1.0f, 1.0f),   Vector3(0.0f, 1.0f, 1.0f) },
      { Vector3(-1.0f, 1.0f, 1.0f),  Vector3(1.0f, 0.0f, 0.0f) },
      
      { Vector3(-1.0f, -1.0f, -1.0f),Vector3(1.0f, 0.0f, 1.0f) },
      { Vector3(1.0f, -1.0f, -1.0f), Vector3(1.0f, 1.0f, 0.0f) },
      { Vector3(1.0f, -1.0f, 1.0f),  Vector3(1.0f, 1.0f, 1.0f) },
      { Vector3(-1.0f, -1.0f, 1.0f), Vector3(0.0f, 0.0f, 0.0f) },
    };

    vertex vertices2[] =
    {
        { Vector3(-1.0f, 1.0f, -1.0f), Vector3(0.0f, 1.0f, 0.0f) },
        { Vector3(1.0f, 1.0f, -1.0f),  Vector3(0.0f, 1.0f, 0.0f) },
        { Vector3(1.0f, 1.0f, 1.0f),   Vector3(0.0f, 1.0f, 0.0f) },
        { Vector3(-1.0f, 1.0f, 1.0f),  Vector3(0.0f, 1.0f, 0.0f) },

        { Vector3(-1.0f, -1.0f, -1.0f),Vector3(0.0f, -1.0f, 0.0f) },
        { Vector3(1.0f, -1.0f, -1.0f), Vector3(0.0f, -1.0f, 0.0f) },
        { Vector3(1.0f, -1.0f, 1.0f),  Vector3(0.0f, -1.0f, 0.0f) },
        { Vector3(-1.0f, -1.0f, 1.0f), Vector3(0.0f, -1.0f, 0.0f) },

        { Vector3(-1.0f, -1.0f, 1.0f), Vector3(-1.0f, 0.0f, 0.0f) },
        { Vector3(-1.0f, -1.0f, -1.0f),Vector3(-1.0f, 0.0f, 0.0f) },
        { Vector3(-1.0f, 1.0f, -1.0f), Vector3(-1.0f, 0.0f, 0.0f) },
        { Vector3(-1.0f, 1.0f, 1.0f),  Vector3(-1.0f, 0.0f, 0.0f) },

        { Vector3(1.0f, -1.0f, 1.0f),  Vector3(1.0f, 0.0f, 0.0f) },
        { Vector3(1.0f, -1.0f, -1.0f), Vector3(1.0f, 0.0f, 0.0f) },
        { Vector3(1.0f, 1.0f, -1.0f),  Vector3(1.0f, 0.0f, 0.0f) },
        { Vector3(1.0f, 1.0f, 1.0f),   Vector3(1.0f, 0.0f, 0.0f) },

        { Vector3(-1.0f, -1.0f, -1.0f),Vector3(0.0f, 0.0f, -1.0f) },
        { Vector3(1.0f, -1.0f, -1.0f), Vector3(0.0f, 0.0f, -1.0f) },
        { Vector3(1.0f, 1.0f, -1.0f),  Vector3(0.0f, 0.0f, -1.0f) },
        { Vector3(-1.0f, 1.0f, -1.0f), Vector3(0.0f, 0.0f, -1.0f) },

        { Vector3(-1.0f, -1.0f, 1.0f), Vector3(0.0f, 0.0f, 1.0f) },
        { Vector3(1.0f, -1.0f, 1.0f),  Vector3(0.0f, 0.0f, 1.0f) },
        { Vector3(1.0f, 1.0f, 1.0f),   Vector3(0.0f, 0.0f, 1.0f) },
        { Vector3(-1.0f, 1.0f, 1.0f),  Vector3(0.0f, 0.0f, 1.0f) },
    };

    _vertexBuffer->setBufferDesc(25);

    _vertexBuffer->setSubresourceData(vertices2);

    if (FAILED(m_device->CreateBuffer(
      _vertexBuffer->getBufferDesc(),
      _vertexBuffer->getSubresourceData(),
      _vertexBuffer->getBufferRef())))
    {
      Log(Log::LOGERROR, true) << "Vertex buffer couldn't be created";
      return false;
    }
    Log() << "Vertex buffer created successfully";
    return true;
  }
  bool DXDevice::createIndexBuffer(DXIndexBuffer * _indexBuffer)
  {

    uint32 indices[]
    {
      3,1,0,
        2,1,3,

        0,5,4,
        1,5,0,

        3,4,7,
        0,4,3,

        1,6,5,
        2,6,1,

        2,7,6,
        3,7,2,

        6,4,5,
        7,4,6,
    };

    uint32 indices2[] =
    {
        3,1,0,
        2,1,3,

        6,4,5,
        7,4,6,

        11,9,8,
        10,9,11,

        14,12,13,
        15,12,14,

        19,17,16,
        18,17,19,

        22,20,21,
        23,20,22
    };

    _indexBuffer->setBufferDesc(36);

    _indexBuffer->setSubresourceData(indices2);

    if (FAILED(m_device->CreateBuffer(
      _indexBuffer->getBufferDesc(),
      _indexBuffer->getSubresourceData(),
      _indexBuffer->getBufferRef())))
    {
      Log(Log::LOGERROR, true) << "index buffer couldn't be created";
      return false;
    }
    Log() << "index buffer created successfully";
    return true;
  }
  bool DXDevice::createConstantBuffer(DXConstantBuffer * _constantBuffer)
  {
    _constantBuffer->setBufferDesc();

    if (FAILED(m_device->CreateBuffer(
      _constantBuffer->getBufferDesc(),
      NULL,
      _constantBuffer->getBufferRef())))
    {
      Log(Log::LOGERROR, true) << "constant buffer couldn't be created";
      return false;
    }
    Log() << "constant buffer created successfully";
    return true;

  }

  bool DXDevice::createTexture2D(DXTexture * _texture, uint32 _width, uint32 _height, uint32 _bindFlag)
  {

    _texture->setTextureDesc(_width, _height, _bindFlag);

    if (
      FAILED(m_device->CreateTexture2D(
        _texture->getTextureDescRef(),
        NULL,
        _texture->getTextureRef())))
    {

      Log(Log::LOGERROR, true) << "Texture couldn't be created";
      return false;
    }

    Log() << "Texture created successfully";
    return true;
  }

  bool DXDevice::createDepthStencilView(DXTexture * _texture, DXDepthStencilVew * _depthStencilView)
  {

    _depthStencilView->setDepthStencilViewDesc(_texture);
    
    if (FAILED(m_device->CreateDepthStencilView(
      _texture->getTexture(),
      _depthStencilView->getDepthStencilViewDesc(),
      _depthStencilView->getDepthStencilViewRef())))
    {
      
      Log(Log::LOGERROR, true) << "Depth Stencil View couldn't be created";
      return false;
    }

    Log() << "Depth Stencil View created successfully";
    return true;
  }
}
