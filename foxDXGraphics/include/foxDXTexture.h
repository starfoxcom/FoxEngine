#pragma once
/**
 * @file foxDXTexture.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/10/02
 * @brief Graphics API Texture class for DirectX.
 */

/**
 * Includes
 */
#include <d3d11.h>

namespace foxEngineSDK
{

  class foxDXTexture
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxDXTexture();

    /**
     * @brief Default destructor.
     */
    ~foxDXTexture();

    /**
     * @brief Gets the DirectX texture.
     */
    ID3D11Texture2D * getTexture();

    /**
     * @brief Gets the DirectX texture reference.
     */
    ID3D11Texture2D ** getTextureRef();

  private:

    ID3D11Texture2D * m_texture = nullptr; /**< Texture class object member.*/

  };
}