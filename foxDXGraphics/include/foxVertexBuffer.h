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



//#include "foxVector2.h"
//#include "foxVector4.h"

/**
* Libs
*/

namespace foxEngineSDK
{

  class VertexBuffer
  {
  public:
    VertexBuffer();
    ~VertexBuffer();

    void setBufferDesc();

    ID3D11Buffer  ** getVertexBufferRef();

    ID3D11Buffer  * getVertexBuffer();

    D3D11_BUFFER_DESC getBufferDesc();
  private:

    D3D11_BUFFER_DESC m_bufferDesc;

    ID3D11Buffer * m_vertexBuffer;

  };

  struct vertex
  {
    FLOAT X, Y, Z, W;
    FLOAT R, G, B, A;
    FLOAT NX, NY, NZ, NW;
    FLOAT U, V;

  };

  //struct vertex2
  //{
  //  Vector4 pos;
  //  Vector4 color;
  //  Vector4 normals;
  //  Vector2 textCoords;
  //};
}