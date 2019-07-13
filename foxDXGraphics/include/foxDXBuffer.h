#pragma once

/**
 * @file foxDXIndexBuffer.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/07/13
 * @brief
 *
 */

 /**
 * Includes
 */
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"



#include "foxVector3.h"
#include "foxVector4.h"

 /**
 * Libs
 */

namespace foxEngineSDK
{

  class DXBuffer
  {
  public:
    DXBuffer();
    ~DXBuffer();

    D3D11_SUBRESOURCE_DATA * getSubresourceData();

    ID3D11Buffer  ** getBufferRef();

    ID3D11Buffer  * getBuffer();

    D3D11_BUFFER_DESC * getBufferDesc();

  protected:

    D3D11_BUFFER_DESC * m_bufferDesc;

    ID3D11Buffer * m_Buffer;

    D3D11_SUBRESOURCE_DATA * m_initData;

  };
}