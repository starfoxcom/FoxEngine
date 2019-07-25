/**
* @file foxVector4.h
* @author ---
* @date ---
* @brief Implementation of a vector in a 4D space.
*
* Implementation of a vector in a 4D space with components "X", "Y", "Z" and "W".
*/

#pragma once

/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  /**
  * Forward declarations
  */
  class Vector2;
  class Vector3;
  class FOX_UTILITY_EXPORT Vector4
  {
  public:

    /**
     * @brief Default constructor
     */
    Vector4();

    /**
     * @brief Vector's X component.
     */
    float x;

    /**
     * @brief Vector's Y component.
     */
    float y;

    /**
     * @brief Vector's Z component.
     */
    float z;

    /**
     * @brief Vector's W component.
     */
    float w;

    /**
     * @brief Constructor using initial values.
     * @param _x X coordinate.
     * @param _y Y coordinate.
     * @param _z Z coordinate.
     * @param _w W coordinate.
     */
    Vector4(float _x, float _y, float _z, float _w);

    /**
     * @brief Constructor using 2 Vector2.
     * @param _vec2Dxy The first Vector2 to copy from.
     * @param _vec2Dzw The second Vector2 to copy from.
     */
    Vector4(const Vector2& _vec2Dxy, const Vector2& _vec2Dzw);

    /**
     * @brief Constructor using a Vector3.
     * @param _vec3D The vector to copy from.
     * @param _w W coordinate.
     */
    Vector4(const Vector3& _vec3D, float _w);

    /**
     * @brief Constructor using another vector4.
     * @param _vec4D The vector to copy from.
     */
    Vector4(const Vector4& _vec4D);

    /**
     * @brief Gets the result of adding two vectors together.
     * @param _vec4D The other vector to add to this.
     * @return The result of adding the vectors together.
     */
    Vector4 operator+(const Vector4& _vec4D);

    /**
     * @brief Gets the result of adding float A to this.
     * @param A Float to add to each component.
     * @return The result of this vector + float A.
     */
    Vector4 operator+(float A);

    /**
     * @brief Gets the result of subtracting a vector from this.
     * @param _vec4D The other vector to subtract from.
     * @return The result o the subtraction.
     */
    Vector4 operator-(const Vector4& _vec4D);

    /**
     * @brief Gets the result of subtraction float A from this.
     * @param A Float to subtract from each component.
     * @return The result of this vector - float A.
     */
    Vector4 operator-(float A);

    /**
     * @brief Gets the result of multiplying the vector with another.
     * @param _vec4D The other vector to multiply this.
     * @return The result of the multiplication.
     */
    Vector4 operator*(const Vector4& _vec4D);

    /**
     * @brief Gets the result of scaling the vector with float A.
     * @param A Float to multiply each component by.
     * @return The result of the scale.
     */
    Vector4 operator*(float A);

    /**
     * @brief Gets the result of dividing the vector with another.
     * @param _vec4D The other vector to divide this.
     * @return The result of the division.
     */
    Vector4 operator/(const Vector4& _vec4D);

    /**
     * @brief Gets the result of dividing the vector with float A.
     * @param A Float to divide each component by.
     * @return The result of the division.
     */
    Vector4 operator/(float A);

    /**
     * @brief Gets the cross product of this vector and another.
     * @param _vec4D The other vector.
     * @return The cross product.
     */
    Vector4 operator^(const Vector4& _vec4D);

    /**
     * @brief Gets the dot product of this vector and another.
     * @param _vec4D The other vector.
     * @return The dot product.
     */
    float operator|(const Vector4& _vec4D);

    /**
    * @brief Compares this vector with another for equality.
    * @param _vec4D The vector to compare against.
    * @return true if the two vectors are equal, otherwise false.
    */
    bool operator==(const Vector4& _vec4D);

    /**
    * @brief Compares this vector with another for inequality.
    * @param _vec4D The vector to compare against.
    * @return true if the two vectors are not equal, otherwise false.
    */
    bool operator!=(const Vector4& _vec4D);

    /**
    * @brief Adds another vector to this.
    * @param _vec4D The other vector to add.
    * @return Copy of the vector after addition.
    */
    Vector4& operator+=(const Vector4& _vec4D);

    /**
    * @brief Multiplies another vector to this.
    * @param _vec4D The vector to multiply with.
    * @return copy of the vector after multiplication.
    */
    Vector4& operator*=(const Vector4& _vec4D);

    /**
    * @brief Scales this vector.
    * @param A Float to multiply the vector by.
    * @return Copy of the vector after scaling.
    */
    Vector4& operator*=(float A);

    /**
    * @brief Divides another vector to this.
    * @param _vec4D The vector to divide with.
    * @return Copy of the vector after division.
    */
    Vector4& operator/=(const Vector4& _vec4D);

    /**
    * @brief Gets specific component of the vector.
    * @param _index The index of the vector.
    * @return The reference to the component.
    */
    float & operator[](uint32 _index);

    /**
    * @brief Gets specific component of the vector.
    * @param _index The index of the vector.
    * @return The reference to the component.
    */
    float operator[](uint32 _index) const;

    /**
     * @brief Gets the magnitude of the vector.
     */
    float magnitude();

    /**
     * @brief Gets the vector normalized.
     */
    Vector4 normalized();


  };
}