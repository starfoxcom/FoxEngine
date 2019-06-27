/**
* @file foxRay.h
* @author --
* @date ---
* @brief Implementation of a ray in space.
*/

#pragma once
/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"
#include "foxVector3.h"

namespace foxEngineSDK
{

  class Ray
  {
    
  public:
    /**
     * @brief Default constructor.
     */
    Ray() = default;

    /**
     * @brief Default destructor.
     */
    ~Ray();

    /**
    * @brief Ray's position Vector.
    */
    Vector3 m_position;

    /**
    * @brief Ray's direction Vector.
    */
    Vector3 m_direction;

    /**
     * @brief Constructor with initial parameters.
     * @param _position The position of the ray.
     * @param _direction The direction of the ray.
     */
    Ray(const Vector3& _position, const Vector3& _direction);

    /**
     * Ray functions
     */

    Ray::~Ray() {}

    Ray::Ray(const Vector3& _position, const Vector3& _direction)
    {
      m_position = _position;
      m_direction = _direction;
    }
  };
}