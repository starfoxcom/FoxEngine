#pragma once
/**
 * @file foxCoreMesh.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/12/11
 * @brief Mesh Class for Model.
 */
#include "foxPrerequisitesUtilities.h"
#include "foxVector2.h"
#include "foxVector3.h"

#include "assimp/Importer.hpp"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

namespace foxEngineSDK
{


  struct vertex
  {
    Vector3 pos;
    Vector2 tex;
  };

  class foxMesh
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxMesh();

    /**
     * @brief Default destructor.
     */
    ~foxMesh();

    /**
     * @brief Loads the Mesh data to their respective members of the class.
     * @param _mesh The Assimp mesh pointer.
     * @param _indexCount The Index count for the index mesh offset.
     */
    void loadMesh(const aiMesh* _mesh, const uint32 _indexCount);

    /**
     * @brief Gets the byte width of the vertices.
     */
    uint32 getVertexByteWidth();

    /**
     * @brief Gets the byte width of the indices.
     */
    uint32 getIndexByteWidth();

    /**
     * @brief Gets the vertex data.
     */
    std::vector<vertex> * getVertexData();

    /**
     * @brief Gets the index data.
     */
    std::vector<uint32> * getIndexData();

  private:

    std::vector<vertex> m_vertices; /**< The Mesh vertices.*/

    std::vector<uint32> m_indices; /**< The Mesh indices.*/
  };
}