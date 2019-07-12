#include "foxDXDevice.h"
#include "foxDXVertexShader.h"
#include "foxDXInputLayout.h"
#include "foxDXPixelShader.h"
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
  bool DXDevice::createVertexBuffer(
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
