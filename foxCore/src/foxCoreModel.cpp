
/**
 * Includes
 */
#include "foxCoreModel.h"
#include <foxCoreGraphicsAPI.h>

namespace foxEngineSDK
{


  foxModel::foxModel()
  {
  }

  foxModel::~foxModel()
  {
  }

  void foxModel::loadModel(const char * _fileName)
  {

    m_meshes.clear();

    m_vertexData.clear();

    m_indexData.clear();

    m_vertexByteWidth = 0;
    m_indexByteWidth = 0;

    m_indexCount = 0;
    m_vertexCount = 0;

    //Create the Assimp importer
    Assimp::Importer importer;

    //Read the file with the Assimp importer
    const aiScene* model = importer.ReadFile(_fileName,
      aiProcess_CalcTangentSpace |
      aiProcess_Triangulate |
      aiProcess_JoinIdenticalVertices |
      aiProcess_SortByPType);

    m_meshes.resize(model->mNumMeshes);

    for (uint32 i = 0; i < m_meshes.size(); ++i)
    {

      //Get the Model data by Mesh
      const aiMesh* meshData = model->mMeshes[i];

      //Load the Mesh
      m_meshes[i].loadMesh(meshData, m_vertexCount, model->mMaterials[meshData->mMaterialIndex]);

      m_vertexByteWidth += m_meshes[i].getVertexByteWidth();

      m_indexByteWidth += m_meshes[i].getIndexByteWidth();

      m_vertexData.insert(
        m_vertexData.end(),
        m_meshes[i].getVertexData()->begin(),
        m_meshes[i].getVertexData()->end());

      m_indexData.insert(
        m_indexData.end(),
        m_meshes[i].getIndexData()->begin(),
        m_meshes[i].getIndexData()->end());

      m_indexCount += m_meshes[i].getIndexData()->size();

      m_vertexCount += m_meshes[i].getVertexData()->size();
    }

    foxGraphicsAPI::instance().createVertexBuffer(&m_vertexData[0], m_vertexByteWidth);

    foxGraphicsAPI::instance().setVertexBuffer(sizeof(vertex));

    foxGraphicsAPI::instance().createIndexBuffer(&m_indexData[0], m_indexByteWidth);

    foxGraphicsAPI::instance().setIndexBuffer();
  }

  void foxModel::draw()
  {

    if (m_indexCount != 0)
    {

      for (uint32 i = 0; i < m_meshes.size(); ++i)
      {
        
        m_meshes[i].loadAndSetMeshTexture();

        foxGraphicsAPI::instance().drawIndexed(m_meshes[i].getIndexData()->size(), 0, 0);
      }
    }
  }

}