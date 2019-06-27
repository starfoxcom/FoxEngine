#include "foxDevice.h"
#include "foxVertexShader.h"
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
      return false;
    }
    Log() << "Vertex Shader created successfully";
    return true;
  }
  
  //bool Device::createInputLayout(VertexShader * _vertexShader, InputLayout * _inputLayout)
  //{
  //  if(FAILED(m_device->CreateInputLayout(_inputLayout->getInputLayoutDesc(),)));
  //}
}
