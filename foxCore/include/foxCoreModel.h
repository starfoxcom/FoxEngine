#pragma once
/**
 * @file foxCoreModel.h
 *
 * @author Jorge Alexandro Zamudio Arredondo (starfoxcom)
 * @date 2019/12/11
 * @brief Model Class.
 */

/**
 * Includes
 */
#include "foxCoreMesh.h"

namespace foxEngineSDK
{

  class foxModel
  {
  public:

    /**
     * @brief Default constructor.
     */
    foxModel();

    /**
     * @brief Default destructor.
     */
    ~foxModel();

    /**
     * @brief Loads the model data to their respective members on the class.
     * @param _fileName The name of the file model to load.
     */
    void loadModel(const char * _fileName);

    /**
     * @brief Gets the Model Index count.
     */
    uint32 getIndexCount();

    /**
     * @brief Draws the model.
     */
    void draw();

  private:

    std::vector<foxMesh> m_meshes; /**< The vector Mesh.*/

    std::vector<vertex> m_vertexData; /**< The Model vertex data.*/

    std::vector<uint32> m_indexData; /**< The model index data.*/

    uint32 m_vertexByteWidth = 0; /**< The Vertex byte width.*/

    uint32 m_indexByteWidth = 0; /**< The index byte width.*/

    uint32 m_indexCount = 0; /**< The Model index count.*/
  };
}