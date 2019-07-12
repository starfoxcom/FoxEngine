/**
* @file foxVertexBuffer.h
* @author --
* @date ---
* @brief Implementation of vertex buffer.
*/
#pragma once

/**
* Includes
*/
#include <d3d11.h>
#include "foxPrerequisitesUtilities.h"



//#include "foxVector2.h"
//#include "foxVector4.h"

/**
* Libs
*/

namespace foxEngineSDK
{

  struct vertex
  {
    FLOAT X, Y, Z, W;
    FLOAT R, G, B, A;
    FLOAT NX, NY, NZ, NW;
    FLOAT U, V;

  };

  struct simpleVertex
  {
    FLOAT X, Y, Z;
    FLOAT R, G, B, A;
  };

  class DXVertexBuffer
  {
  public:
    DXVertexBuffer();
    ~DXVertexBuffer();

    void setBufferDesc();

    void setSubresourceData(
      const void * _triangle,
      uint32 _sysMemPitch,
      uint32 _sysMemSlicePitch);

    D3D11_SUBRESOURCE_DATA * getSubresourceData();

    ID3D11Buffer  ** getVertexBufferRef();

    ID3D11Buffer  * getVertexBuffer();

    D3D11_BUFFER_DESC * getBufferDesc();
  private:

    D3D11_BUFFER_DESC * m_bufferDesc;

    ID3D11Buffer * m_vertexBuffer;

    D3D11_SUBRESOURCE_DATA * m_initData;

  };

  //struct vertex2
  //{
  //  Vector4 pos;
  //  Vector4 color;
  //  Vector4 normals;
  //  Vector2 textCoords;
  //};
}