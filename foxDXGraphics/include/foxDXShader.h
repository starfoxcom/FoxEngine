#pragma once
/**
 * @file foxDXShader.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/07
 * @brief Shader base class.
 */

 /**
  * Includes
  */
#include <d3d11.h>

namespace foxEngineSDK
{

  class DXShader
  {
  public:

    /**
     * @brief Default constructor.
     */
    DXShader();

    /**
     * @brief Default destructor.
     */
    ~DXShader();

    /**
     * @brief Gets the Shader Blob.
     */
    ID3DBlob * getBlob();

    /**
     * @brief Gets the Shader Blob reference.
     */
    ID3DBlob ** getBlobRef();

    /**
     * @brief Compiles the shader file.
     * @param _fileName The name of the shader file.
     * @param _entryPoint The entry point of the shader.
     * @param _shaderModel The Shader version to use to compile the shader.
     */
    bool compileShaderFromFile(
      const char * _fileName,
      const char * _entryPoint,
      const char * _shaderModel);

  private:

    ID3DBlob * m_blob; /**< Shader Blob class object member.*/
  };
}