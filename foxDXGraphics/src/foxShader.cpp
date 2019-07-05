#include <vector>
#include <fstream>
#include <iostream>
#include <d3dcompiler.h>

#include "foxShader.h"
#include "foxLog.h"

namespace foxEngineSDK
{

  Shader::Shader()
  {
  }

  Shader::~Shader()
  {
  }

  ID3DBlob ** Shader::getBlobRef()
  {
    return &m_blob;
  }

  ID3DBlob * Shader::getBlob()
  {
    return m_blob;
  }

  bool Shader::compileShaderFromFile(
    const char * _fileName,
    const char * _entryPoint,
    const char * _shaderModel)
  {
    std::fstream file(_fileName, std::ios::in | std::ios::binary | std::ios::ate);

    std::vector<char> dataBuffer;

    if (!file.is_open())
    {
      Log(Log::LOGWARN, true) << "The file could not be opened";
      return false;
    }

    SIZE_T fileSize = static_cast<SIZE_T>(file.tellg());

    dataBuffer.resize(fileSize);

    file.seekp(std::ios::beg);

    file.read(&dataBuffer[0], fileSize);

    file.close();

    ID3DBlob* errorBlob;

    if ((D3DCompile(
      &dataBuffer[0],
      fileSize,
      NULL,
      NULL,
      NULL,
      _entryPoint,
      _shaderModel,
      D3DCOMPILE_ENABLE_STRICTNESS,
      0,
      &m_blob,
      &errorBlob)))
    {
      if (errorBlob != NULL)
        if (errorBlob) errorBlob->Release();
      return false;
    }
    if (errorBlob) errorBlob->Release();

    Log() << "Shader compiled successfully";
    return true;
  }


}