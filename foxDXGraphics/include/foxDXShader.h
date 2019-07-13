/**
* @file foxShader.h
* @author --
* @date ---
* @brief Implementation of shader
*/

#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxGraphicsDefines.h"

namespace foxEngineSDK
{

  class DXShader
  {
  public:
    DXShader();
    ~DXShader();

    ID3DBlob ** getBlobRef();

    ID3DBlob * getBlob();

    bool compileShaderFromFile(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

  private:

    ID3DBlob * m_blob;
  };
};