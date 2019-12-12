/**
* @file foxVector2.h
* @author ---
* @date ---
* @brief Implementation of a vector in a 2D space.
*
* Implementation of a vector in a 2D space with components "X" and "Y".
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
  class Vector3;

  class FOX_UTILITY_EXPORT Vector2
  {
  public:

    /**
     * @brief Default constructor
     */
    Vector2();

    /**
     * @brief Default destructor
     */
    ~Vector2();

    /**
     * @brief Vector's X component.
     */
    float x;

    /**
     * @brief Vector's Y component.
     */
    float y;

    /**
     * @brief Constructor using initial values.
     * @param _x X coordinate.
     * @param _y Y coordinate.
     */
    Vector2(float _x, float _y);

    /**
     * @brief Constructor using another vector2.
     * @param _vec2D The vector to copy the components.
     */
    Vector2(const Vector2& _vec2D);

    /**
     * @brief Constructor using a vector3.
     * @param _vec3D The vector to copy the components.
     * @return The 2D vector copied from a 3D vector.
     */
    Vector2(const Vector3& _vec3D);

    /**
     * @brief Gets the result of adding two vectors together.
     * @param _vec2D The other vector to add to this.
     * @return The result of adding the vectors together.
     */
    Vector2 operator+(const Vector2& _vec2D);

    /**
    * @brief Gets the result of adding float A to this.
    * @param A Float to add to this component.
    * @return The result of this vector + float A.
    */
    Vector2 operator+(float A);

    /**
     * @brief Gets the result of subtracting a vector from this.
     * @param _vec2D The other vector to subtract from.
     * @return The result of the subtraction.
     */
    Vector2 operator-(const Vector2& _vec2D);

    /**
     * @brief Gets the result of subtracting float A from this.
     * @param A Float to subtract from each component.
     * @return The result of this vector - float A.
     */
    Vector2 operator-(float A);

    /**
     * @brief Gets the result of multiplying the vector with another.
     * @param _vec2D The other vector to multiply this.
     * @return The result of the multiplication.
     */
    Vector2 operator*(const Vector2& _vec2D);

    /**
     * @brief Gets the result of scaling the vector with float A.
     * @param A Float to multiply each component by.
     * @return The result of the scale.
     */
    Vector2 operator*(float A);

    /**
     * @brief Gets the result of dividing the vector with another.
     * @param _vec2D The other vector to divide this.
     * @return the result of the division.
     */
    Vector2 operator/(const Vector2& _vec2D);

    /**
     * @brief Gets the result of dividing the vector with float A.
     * @param A Float to divide each component by.
     * @return The result of the division.
     */
    Vector2 operator/(float A);

    /**
     * @brief Gets the dot product of this vector and another.
     * @param _vec2D The other vector.
     * @return The dot product.
     */
    float operator|(const Vector2& _vec2D);

    /**
     * @brief Gets the cross product of this vector and another.
     * @param _vec2D The other vector.
     * @return The cross product.
     */
    float operator^(const Vector2& _vec2D);

    /**
     * @brief Checks if this vector is less than another vector.
     * @param _vec2D The vector to compare against.
     * return true if this is a smaller vector, otherwise false.
     */
    bool operator<(const Vector2& _vec2D);

    /**
     * @brief Checks if this vector is more than another vector.
     * @param _vec2D The vector to compare against.
     * @return true if this is a bigger vector, otherwise false.
     */
    bool operator>(const Vector2& _vec2D);

    /**
     * @brief Compares this vector with another for equality.
     * @param _vec2D The vector to compare against.
     * @return true if the two vectors are equal, otherwise false.
     */
    bool operator==(const Vector2& _vec2D);

    /**
     * @brief Compares this vector with another for inequality.
     * @param _vec2D The vector to compare against.
     * @return true if the two vectors are not equal, otherwise false.
     */
    bool operator!=(const Vector2& _vec2D);

    /**
     * @brief Adds another vector to this.
     * @param _vec2D The other vector to add.
     * @return Copy of the vector after addition.
     */
    Vector2& operator+=(const Vector2& _vec2D);

    /**
     * @brief subtracts another vector to this.
     * @param _vec2D The other vector to subtract.
     * @return Copy of the vector after subtraction.
     */
    Vector2& operator-=(const Vector2& _vec2D);

    /**
     * @brief Multiplies another vector to this.
     * @param _vec2D The vector to multiply with.
     * @return copy of the vector after multiplication.
     */
    Vector2& operator*=(const Vector2& _vec2D);

    /**
     * @brief Scales this vector.
     * @param A Float to multiply the vector by.
     * @return Copy of the vector after scaling.
     */
    Vector2& operator*=(float A);

    /**
     * @brief Divides another vector to this.
     * @param _vec2D The vector to divide with.
     * @return Copy of the vector after division.
     */
    Vector2& operator/=(const Vector2& _vec2D);

    /**
     * @brief Divides this vector.
     * @param A Float to divide the vector by.
     * @return Copy of the vector after division.
     */
    Vector2& operator/=(float A);

    /**
    * @brief Checks if this vector is less or equal than another vector.
    * @param _vec2D The vector to compare against.
    * return true if this is a smaller or equal vector, otherwise false.
    */
    bool operator<=(const Vector2& _vec2D);

    /**
    * @brief Checks if this vector is more than another vector.
    * @param _vec2D The vector to compare against.
    * @return true if this is a bigger or equal vector, otherwise false.
    */
    bool operator>=(const Vector2& _vec2D);

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
     * Vector2 functions
     */

    

  };
}