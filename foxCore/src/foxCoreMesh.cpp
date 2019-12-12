/**
 * Includes
 */
#include "foxCoreMesh.h"

namespace foxEngineSDK
{

  foxMesh::foxMesh()
  {
  }

  foxMesh::~foxMesh()
  {
  }

  void foxMesh::loadMesh(const aiMesh * _mesh)
  {

    m_vertices.resize(_mesh->mNumVertices);
    m_indices.resize(_mesh->mNumFaces * 3);

    for (uint32 i = 0; i < m_vertices.size(); ++i)
    {

      m_vertices[i].pos.x = _mesh->mVertices[i].x;
      m_vertices[i].pos.y = _mesh->mVertices[i].y;
      m_vertices[i].pos.z = _mesh->mVertices[i].z;

      if (_mesh->HasTextureCoords(0))
      {

      m_vertices[i].tex.x = _mesh->mTextureCoords[0]->x;
      m_vertices[i].tex.y = _mesh->mTextureCoords[0]->y;
      }
    }

    uint32 index = 0;

    for (uint32 i = 0; i < _mesh->mNumFaces; ++i)
    {
      for (uint32 j = 0; j < 3; ++j)
      {

        m_indices[index] = _mesh->mFaces[i].mIndices[j];
        ++index;
      }
    }
  }

  uint32 foxMesh::getVertexByteWidth()
  {
    return m_vertices.size() * sizeof(vertex);
  }

  uint32 foxMesh::getIndexByteWidth()
  {
    return m_indices.size() * sizeof(uint32);
  }

  std::vector<vertex> * foxMesh::getVertexData()
  {
    return &m_vertices;
  }

  std::vector<uint32> * foxMesh::getIndexData()
  {
    return &m_indices;
  }

}