/**
 * Includes
 */

#include <vector>
#include <fstream>
#include <iostream>
#include <d3dcompiler.h>

#include "foxDXShader.h"
#include "foxLog.h"

namespace foxEngineSDK
{


  foxDXShader::foxDXShader()
  {
  }

  foxDXShader::~foxDXShader()
  {
  }

  ID3DBlob * foxDXShader::getBlob()
  {
    return m_blob;
  }

  ID3DBlob ** foxDXShader::getBlobRef()
  {
    return &m_blob;
  }

  bool foxDXShader::compileShaderFromFile(
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

    uint32 flags = D3DCOMPILE_ENABLE_STRICTNESS;

#ifdef _DEBUG
    flags |= D3DCOMPILE_DEBUG;
#endif // _DEBUG



    if (FAILED(D3DCompile(
      &dataBuffer[0],
      fileSize,
      NULL,
      NULL,
      NULL,
      _entryPoint,
      _shaderModel,
      flags,
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