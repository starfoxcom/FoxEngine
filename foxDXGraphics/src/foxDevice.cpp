#include "foxDevice.h"
#include "foxVertexShader.h"
#include "foxInputLayout.h"
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
}
