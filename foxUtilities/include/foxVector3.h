/**
* @file foxVector3.h
* @author --
* @date ---
* @brief Implementation of a vector in a 3D space.
*
* Implementation of a vector in a 3D space with components "X", "Y" and "Z".
*/

#pragma once
/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"
#include "foxPlatformMath.h"

namespace foxEngineSDK
{

  /**
   * Forward declarations
   */
  class Vector2;

  class FOX_UTILITY_EXPORT Vector3
  {
  public:

    /**
     * @brief Default constructor.
     */
    Vector3() = default;

    /**
     * @brief Default destructor.
     */
    ~Vector3();

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
     * @brief Constructor using initial values.
     * @param _x X coordinate.
     * @param _y Y coordinate.
     * @param _z Z coordinate.
     */
    Vector3(float _x, float _y, float _z);

    /**
     * @brief Constructor using a vector2 and the z value.
     * @param _vec2D The vector2 to copy the components.
     * @param _z The z component.
     */
    Vector3(const Vector2& _vec2D, float _z);

    /**
     * @brief Gets the result of adding two vectors together.
     * @param _vec3D The other vector to add to this.
     * @return The result of adding the vectors together.
     */
    Vector3 operator+(const Vector3& _vec3D);

    /**
     * @brief Gets the result of adding float A to this.
     * @param A Float to add to this component.
     * @return The result of this vector + float A.
     */
    Vector3 operator+(float A);

    /**
     * @brief Gets the result of subtracting a vector from this.
     * @param _vec3D The other vector to subtract from.
     * @return The result of the subtraction.
     */
    Vector3 operator-(const Vector3& _vec3D);

    /**
     * @brief Gets the result of subtracting float A from this.
     * @param A Float to subtract from each component.
     * @return The result of this vector - float A.
     */
    Vector3 operator-(float A);

    /**
     * @brief Gets the result of multiplying the vector with another.
     * @param _vec3D The other vector to multiply this.
     * @return The result of the multiplication.
     */
    Vector3 operator*(const Vector3& _vec3D);

    /**
     * @brief Gets the result of scaling teh vector with float A.
     * @param A Float to multiply each component by.
     * @return The result of the scale.
     */
    Vector3 operator*(float A);

    /**
     * @brief Gets the result of dividing the vector with another.
     * @param _vec3D The other vector to divide this.
     * @return The result of the division.
     */
    Vector3 operator/(const Vector3& _vec3D);

    /**
     * @brief Gets the result of dividing the vector with float A.
     * @param A Float to divide each component by.
     * @return The result of the division.
     */
    Vector3 operator/(float A);

    /**
     * @brief Gets the dot product of this vector and another.
     * @param _vec3D The other vector.
     * @return The dot product.
     */
    float operator|(const Vector3& _vec3D);

    /**
     * @brief Gets the cross product of this vector and another.
     * @param _vec3D The other vector.
     * @return The cross product.
     */
    float operator^(const Vector3& _vec3D);

    /**
    * @brief Compares this vector with another for equality.
    * @param _vec3D The vector to compare against.
    * @return true if the two vectors are equal, otherwise false.
    */
    bool operator==(const Vector3& _vec3D);

    /**
    * @brief Compares this vector with another for inequality.
    * @param _vec3D The vector to compare against.
    * @return true if the two vectors are not equal, otherwise false.
    */
    bool operator!=(const Vector3& _vec3D);

    /**
    * @brief Adds another vector to this.
    * @param _vec3D The other vector to add.
    * @return Copy of the vector after addition.
    */
    Vector3& operator+=(const Vector3& _vec3D);

    /**
    * @brief Subtracts another vector to this.
    * @param _vec3D The other vector to subtract.
    * @return Copy of the vector after subtraction.
    */
    Vector3& operator-=(const Vector3& _vec3D);

    /**
    * @brief Multiplies another vector to this.
    * @param _vec3D The vector to multiply with.
    * @return copy of the vector after multiplication.
    */
    Vector3& operator*=(const Vector3& _vec3D);

    /**
    * @brief Scales this vector.
    * @param A Float to multiply the vector by.
    * @return Copy of the vector after scaling.
    */
    Vector3& operator*=(float A);

    /**
    * @brief Divides another vector to this.
    * @param _vec3D The vector to divide with.
    * @return Copy of the vector after division.
    */
    Vector3& operator/=(const Vector3& _vec3D);

    /**
    * @brief Divides this vector.
    * @param A Float to divide the vector by.
    * @return Copy of the vector after division.
    */
    Vector3& operator/=(float A);

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
     * Vector3 functions
     */

    Vector3::~Vector3() {}

    Vector3::Vector3(float _x, float _y, float _z) : x(_y), y(_y), z(_z) {}

    Vector3::Vector3(const Vector2& _vec2D, float _z) : x(_vec2D.x), y(_vec2D.y), z(_z) {}

    Vector3 Vector3::operator+(const Vector3& _vec3D)
    {
      return Vector3(x + _vec3D.x, y + _vec3D.y, y + _vec3D.z);
    }

    Vector3 Vector3::operator+(float A)
    {
      return Vector3(x + A, y + A, z + A);
    }

    Vector3 Vector3::operator-(const Vector3& _vec3D)
    {
      return Vector3(x - _vec3D.x, y - _vec3D.y, y - _vec3D.z);
    }

    Vector3 Vector3::operator-(float A)
    {
      return Vector3(x - A, y - A, z - A);
    }

    Vector3 Vector3::operator*(const Vector3& _vec3D)
    {
      return Vector3(x * _vec3D.x, y * _vec3D.y, z * _vec3D.z);
    }

    Vector3 Vector3::operator*(float A)
    {
      return Vector3(x * A, y * A, z * A);
    }

    Vector3 Vector3::operator/(const Vector3& _vec3D)
    {
      return Vector3(x / _vec3D.x, y / _vec3D.y, z / _vec3D.z);
    }

    Vector3 Vector3::operator/(float A)
    {
      return Vector3(x / A, y / A, z / A);
    }

    float Vector3::operator|(const Vector3& _vec3D)
    {
      return x * _vec3D.x + y * _vec3D.y + z * _vec3D.z;
    }

    float Vector3::operator^(const Vector3& _vec3D)
    {
      return Vector3(
        y * _vec3D.z - z * _vec3D.y,
        z * _vec3D.x - x * _vec3D.z,
        x * _vec3D.y - y * _vec3D.x);
    }

    bool Vector3::operator==(const Vector3& _vec3D)
    {
      return x == _vec3D.x && y == _vec3D.y && z == _vec3D.z;
    }

    bool Vector3::operator!=(const Vector3& _vec3D)
    {
      return x != _vec3D.x || y != _vec3D.y || z != _vec3D.z;
    }

    Vector3 & Vector3::operator+=(const Vector3& _vec3D)
    {
      x += _vec3D.x;
      y += _vec3D.y;
      z += _vec3D.z;
      return *this;
    }

    Vector3 & Vector3::operator-=(const Vector3& _vec3D)
    {
      x -= _vec3D.x;
      y -= _vec3D.y;
      z -= _vec3D.z;
      return *this;
    }

    Vector3 & Vector3::operator*=(const Vector3& _vec3D)
    {
      x *= _vec3D.x;
      y *= _vec3D.y;
      z *= _vec3D.z;
      return *this;
    }

    Vector3 & Vector3::operator*=(float A)
    {
      x *= A;
      y *= A;
      z *= A;
      return *this;
    }

    Vector3 & Vector3::operator/=(const Vector3& _vec3D)
    {
      x /= _vec3D.x;
      y /= _vec3D.y;
      z /= _vec3D.z;
      return *this;
    }

    Vector3 & Vector3::operator/=(float A)
    {
      x /= A;
      y /= A;
      z /= A;
      return *this;
    }

    float & operator[](uint32 _index)
    {
      return (&x)[_index];
    }

    float operator[](uint32 _index) const 
    {
      return (&x)[_index];
    }

  };
}

