#include "foxDXDevice.h"
#include "foxDXVertexShader.h"
#include "foxDXInputLayout.h"
#include "foxDXPixelShader.h"
#include "foxDXVertexBuffer.h"
#include "foxDXIndexBuffer.h"
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
    DXVertexBuffer * _vertexBuffer,
    int32 _cpuAcces,
    int32 _miscFlag)
  {
    simpleVertex triangle[]
    {

      { 0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
      { 0.45f, -0.5, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
      { -0.45f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f}
    };

    simpleVertex2 triangle2[]
    {
      { Vector3(-1.0f, 1.0f, -1.0f), Vector4(0.0f, 0.0f, 1.0f, 1.0f) },
      { Vector3(1.0f, 1.0f, -1.0f),  Vector4(0.0f, 1.0f, 0.0f, 1.0f) },
      { Vector3(1.0f, 1.0f, 1.0f),   Vector4(0.0f, 1.0f, 1.0f, 1.0f) },
      { Vector3(-1.0f, 1.0f, 1.0f),  Vector4(1.0f, 0.0f, 0.0f, 1.0f) },
      { Vector3(-1.0f, -1.0f, -1.0f),Vector4(1.0f, 0.0f, 1.0f, 1.0f) },
      { Vector3(1.0f, -1.0f, -1.0f), Vector4(1.0f, 1.0f, 0.0f, 1.0f) },
      { Vector3(1.0f, -1.0f, 1.0f),  Vector4(1.0f, 1.0f, 1.0f, 1.0f) },
      { Vector3(-1.0f, -1.0f, 1.0f), Vector4(0.0f, 0.0f, 0.0f, 1.0f) },
    };

    _vertexBuffer->setBufferDesc();

    _vertexBuffer->setSubresourceData(triangle2);

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

    _indexBuffer->setBufferDesc();

    _indexBuffer->setSubresourceData(indices);

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
}
}
