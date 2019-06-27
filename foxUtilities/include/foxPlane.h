/**
* @file foxPlane.h
* @author --
* @date ---
* @brief Implementation of a pane in space.
*/

#pragma once
/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"
#include "foxVector3.h"
#include "foxVector4.h"

namespace foxEngineSDK
{

  class Plane : public Vector3
  {
  public:

    /**
     * @brief Default constructor.
     */
    Plane() = default;

    /**
     * @brief Default destructor.
     */
    ~Plane() = default;

    /**
     * @brief Constructor from a 4D vector.
     * @param _vec4D The 4D vector.
     */
    Plane(const Vector4& _vec4D);

    /**
     * @brief Constructor from floats for each component of the plane.
     * @param _x X coefficient.
     * @param _y Y coefficient.
     * @param _z Z coefficient.
     * @param _w W coefficient.
     */
    Plane(float _x, float _y, float _z, float _w);

    /**
     * @brief Constructor from a 3D vector and a W component.
     * @param _vec3D The 3D vector.
     * @param _w W coefficient.
     */
    Plane(const Vector3& _vec3D, float _w);

    /**
     * @brief Constructor from a 3D vector base and a 3D vector normal.
     * @param _vec3DBase The base vector.
     * @param _vec3DNormal The normal vector.
     */
    Plane(const Vector3& _vec3DBase, const Vector3& _vec3DNormal);

    /**
     * @brief Constructor from 3 3D vectors as points of the plane.
     * @param _vec3DA First point of the plane.
     * @param _vec3DB Second point of the plane.
     * @param _vec3DC Third point of the plane.
     */
    Plane(const Vector3& _vec3DA, const Vector3& _vec3DB, const Vector3& _vec3DC);

    /**
     * @brief Calculates distance between a plane and a point.
     * @param _vec3D The point to calculate the distance with.
     * @return >0: The point is in front of the plane, <0: behind, =0: on the plane.
     */
    float planeDot(const Vector3& _vec3D);

    /**
    * @brief Gets a flipped version of the plane.
    * @return A flipped version of the plane.
    */
    Plane flip();

    /**
    * TODO: 
    */
  };
}