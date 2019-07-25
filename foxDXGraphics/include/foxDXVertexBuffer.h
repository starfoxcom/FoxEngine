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
#include "foxDXBuffer.h"

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

  struct simpleVertex2
  {
    Vector3 position;
    Vector4 color;
  };

  class DXVertexBuffer : public DXBuffer
  {
  public:
    DXVertexBuffer();
    ~DXVertexBuffer();

    void setBufferDesc();

    void setSubresourceData(
      const void * _triangle);

  };
}