#include "foxDevice.h"
#include "foxVertexShader.h"
#include "foxInputLayout.h"
#include "foxPixelShader.h"
#include "foxVertexBuffer.h"
#include "foxLog.h"


namespace foxEngineSDK
{

  Device::Device()
  {
  }


  Device::~Device()
  {
  }

  ID3D11Device ** Device::getDeviceRef()
  {
    return &m_device;
  }

  ID3D11Device * Device::getDevice()
  {
    return m_device;
  }
  bool Device::createVertexShader(VertexShader * _vertexShader)
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

  bool Device::createInputLayout(InputLayout * _inputLayout, VertexShader * _vertexShader)
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
  bool Device::createPixelShader(PixelShader * _pixelShader)
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
  bool Device::createVertexBuffer(
    VertexBuffer * _vertexBuffer,
    int32 _cpuAcces,
    int32 _miscFlag)
  {
    simpleVertex triangle[]
    {

      { 0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f},
      { 0.45f, -0.5, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f},
      { -0.45f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f}
    };

    _vertexBuffer->setBufferDesc();

    _vertexBuffer->setSubresourceData(triangle, _cpuAcces, _miscFlag);

    if (FAILED(m_device->CreateBuffer(
      _vertexBuffer->getBufferDesc(),
      _vertexBuffer->getSubresourceData(),
      _vertexBuffer->getVertexBufferRef())))
    {
      Log(Log::LOGERROR, true) << "Vertex buffer couldn't be created";
      return false;
    }
    Log() << "Vertex buffer created successfully";
    return true;
  }
}
