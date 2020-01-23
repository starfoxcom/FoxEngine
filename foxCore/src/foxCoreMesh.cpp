/**
 * Includes
 */
#include "foxCoreMesh.h"
#include <foxCoreGraphicsAPI.h>

#include "externals/stb_image.h"

namespace foxEngineSDK
{

  foxMesh::foxMesh()
  {
  }

  foxMesh::~foxMesh()
  {
  }

  void foxMesh::loadMesh(const aiMesh * _mesh, const uint32 _indexCount, const aiMaterial * _mat)
  {   

    //Resize the vertices and indices of the mesh.
    m_vertices.resize(_mesh->mNumVertices);
    m_indices.resize(_mesh->mNumFaces * 3);

    aiString texturePath;

    //Set the texture path of the mesh.
    _mat->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath);

    int width, height, channels;

    //Set the texture data.
    auto * img = stbi_load(texturePath.data,
      &width,
      &height,
      &channels,
      STBI_rgb_alpha);

    foxGraphicsAPI::instance().createShaderResourceViewFromFile(img, width, height);
    
    std::memcpy(
      m_texture,
      foxGraphicsAPI::instance().getShaderResource(),
      sizeof(foxGraphicsAPI::instance().getShaderResource()));

    stbi_image_free(img);

    //Set the vertex position and UV coordinates data.
    for (uint32 i = 0; i < m_vertices.size(); ++i)
    {

      m_vertices[i].pos.x = _mesh->mVertices[i].x;
      m_vertices[i].pos.y = _mesh->mVertices[i].y;
      m_vertices[i].pos.z = _mesh->mVertices[i].z;

      if (_mesh->HasTextureCoords(0))
      {

        m_vertices[i].tex.x = _mesh->mTextureCoords[0][i].x;
        m_vertices[i].tex.y = _mesh->mTextureCoords[0][i].y;
      }
    }

    uint32 index = 0;

    //Set the index data.
    for (uint32 i = 0; i < _mesh->mNumFaces; ++i)
    {
      for (uint32 j = 0; j < 3; ++j)
      {

        m_indices[index] = _mesh->mFaces[i].mIndices[j] + _indexCount;
        ++index;
      }
    }
  }

  void foxMesh::SetMeshTexture()
  {
    foxGraphicsAPI::instance().setShaderResources(m_texture);
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