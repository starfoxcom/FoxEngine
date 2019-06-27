/**
* @file foxMatrix4.h
* @author --
* @date ---
* @brief Implementation of a 4x4 Matrix.
*/
#pragma once

/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"
#include "foxVector2.h"
#include "foxVector3.h"
#include "foxVector4.h"

namespace foxEngineSDK
{

  class Matrix4
  {
  public:

    /**
     * @brief Default constructor
     */
    Matrix4() = default;

    /**
     * @brief Constructor from 4 3D vectors.
     * @param _vec3DA The first vector.
     * @param _vec3DB The second vector.
     * @param _vec3DC The third vector.
     * @param _vec3DD The fourth vector.
     */
    Matrix4(
      const Vector3& _vec3DA,
      const Vector3& _vec3DB,
      const Vector3& _vec3DC,
      const Vector3& _vec3DD);

    /**
     * @brief Constructor from 16 floats.
     * @param _00 first float.
     * @param _01 second float.
     * @param _02 third float.
     * @param _03 fourth float.
     * @param _10 fifth float.
     * @param _11 sixth float.
     * @param _12 seventh float.
     * @param _13 eighth float.
     * @param _20 ninth float.
     * @param _21 tenth float.
     * @param _22 eleventh float.
     * @param _23 twelfth float.
     * @param _30 thirteenth float.
     * @param _31 fourteenth float.
     * @param _32 fifteenth float.
     * @param _33 sixteenth float.
     */
    Matrix4(
      float _00, float _01, float _02, float _03,
      float _10, float _11, float _12, float _13,
      float _20, float _21, float _22, float _23,
      float _30, float _31, float _32, float _33);

    /**
     * @brief Constructor from another matrix.
     * @param _matrix The other matrix.
     */
    Matrix4(const Matrix4& _matrix);

    /**
     * @brief Transforms the matrix to its identity.
     */
    void identity();

    /**
     * @brief Transforms the matrix components into zero.
     */
    void zero();

    /**
     * @brief Transposes the matrix.
     */
    Matrix4 transposed();

    /**
     * @brief Gets the result of adding two matrix together.
     * @param _matrix The other matrix to add to this.
     * @return The result of adding the matrix together.
     */
    Matrix4 operator+(const Matrix4& _matrix);

    /**
     * @brief Gets the result of subtracting a matrix from another.
     * @param _matrix The other matrix to subtract to this.
     * @return The result of subtracting the matrix.
     */
    Matrix4 operator-(const Matrix4& _matrix);

    /**
     * @brief Gets the result of multiplying a matrix to this.
     * @param _matrix The other matrix to multiply to this.
     * @return The result of multiplying the matrix.
     */
    Matrix4 operator*(const Matrix4& _matrix);

    /**
     * @brief Gets the result of multiplying a value to this.
     * @param_value The value to multiply to this.
     * @return The result of multiplying the matrix.
     */
    Matrix4 operator*(float _value);

    /**
     * @brief Adds another matrix to this.
     * @param _matrix The other matrix to add.
     * @return Copy of the matrix after addition.
     */
    Matrix4& operator+=(const Matrix4& _matrix);

    /**
     * @brief Subtracts another matrix to this.
     * @param _matrix The other matrix to subtract.
     * @return Copy of the matrix after subtraction.
     */
    Matrix4& operator-=(const Matrix4& _matrix);

    /**
     * @brief Multiplies another matrix to this.
     * @param _matrix The other matrix to multiply.
     * @return Copy of the matrix after multiplication.
     */
    Matrix4& operator*=(const Matrix4& _matrix);

    /**
     * @brief Multiplies the matrix with a value.
     * @param _value The value to multiply to this.
     * @return Copy of the matrix after multiplication.
     */
    Matrix4& operator*=(float _value);

    /**
     * @brief Compares matrix with another for equality.
     * @param _matrix The matrix to compare against.
     * @return true if the two matrix are equal, otherwise false.
     */
    bool operator==(const Matrix4& _matrix);

    /**
     * @brief Compares matrix with another for inequality.
     * @param _matrix The matrix to compare against.
     * @return true if the two matrix are not equal, otherwise false.
     */
    bool operator!=(const Matrix4& _matrix);

    /**
     * All the ways a matrix can be created.
     */
    union
    {
      float m_dr[4][4];
      float m_sr[16];
    };

    /**
     * Matrix functions
     */

    Matrix4::Matrix4(
      const Vector3& _vec3DA,
      const Vector3& _vec3DB,
      const Vector3& _vec3DC,
      const Vector3& _vec3DD)
    {
      m_dr[0][0] = _vec3DA.x; m_dr[0][1] = _vec3DA.y; m_dr[0][2] = _vec3DA.z; m_dr[0][3] = 0.0f;
      m_dr[1][0] = _vec3DB.x; m_dr[1][1] = _vec3DB.y; m_dr[1][2] = _vec3DB.z; m_dr[1][3] = 0.0f;
      m_dr[2][0] = _vec3DC.x; m_dr[2][1] = _vec3DC.y; m_dr[2][2] = _vec3DC.z; m_dr[2][3] = 0.0f;
      m_dr[3][0] = _vec3DD.x; m_dr[3][1] = _vec3DD.y; m_dr[3][2] = _vec3DD.z; m_dr[3][3] = 1.0f;
    }

    Matrix4::Matrix4(const Matrix4& _matrix)
    {
      m_dr = _matrix.m_dr;
    }

    Matrix4::Matrix4(
      float _00, float _01, float _02, float _03,
      float _10, float _11, float _12, float _13,
      float _20, float _21, float _22, float _23,
      float _30, float _31, float _32, float _33)
    {
      m_dr[0][0] = _00; m_dr[0][1] = _01; m_dr[0][2] _02; m_dr[0][3] = _03;
      m_dr[1][0] = _10; m_dr[1][1] = _11; m_dr[1][2] _12; m_dr[1][3] = _13;
      m_dr[2][0] = _20; m_dr[2][1] = _21; m_dr[2][2] _22; m_dr[2][3] = _23;
      m_dr[3][0] = _30; m_dr[3][1] = _31; m_dr[3][2] _32; m_dr[3][3] = _33;
    }

    void Matrix4::identity()
    {
      m_dr[0][0] = 1.0f; m_dr[0][1] = 0.0f; m_dr[0][2] 0.0f; m_dr[0][3] = 0.0f;
      m_dr[1][0] = 0.0f; m_dr[1][1] = 1.0f; m_dr[1][2] 0.0f; m_dr[1][3] = 0.0f;
      m_dr[2][0] = 0.0f; m_dr[2][1] = 0.0f; m_dr[2][2] 1.0f; m_dr[2][3] = 0.0f;
      m_dr[3][0] = 0.0f; m_dr[3][1] = 0.0f; m_dr[3][2] 0.0f; m_dr[3][3] = 1.0f;
    }

    void Matrix4::zero()
    {
      m_dr[0][0] = 0.0f; m_dr[0][1] = 0.0f; m_dr[0][2] 0.0f; m_dr[0][3] = 0.0f;
      m_dr[1][0] = 0.0f; m_dr[1][1] = 0.0f; m_dr[1][2] 0.0f; m_dr[1][3] = 0.0f;
      m_dr[2][0] = 0.0f; m_dr[2][1] = 0.0f; m_dr[2][2] 0.0f; m_dr[2][3] = 0.0f;
      m_dr[3][0] = 0.0f; m_dr[3][1] = 0.0f; m_dr[3][2] 0.0f; m_dr[3][3] = 0.0f;
    }

    Matrix4 Matrix4::transposed()
    {
      Matrix4 result;
      result.m_dr[0][0] = m_dr[0][0];
      result.m_dr[0][1] = m_dr[1][0];
      result.m_dr[0][2] = m_dr[2][0];
      result.m_dr[0][3] = m_dr[3][0];

      result.m_dr[1][0] = m_dr[0][1];
      result.m_dr[1][1] = m_dr[1][1];
      result.m_dr[1][2] = m_dr[2][1];
      result.m_dr[1][3] = m_dr[3][1];

      result.m_dr[2][0] = m_dr[0][2];
      result.m_dr[2][1] = m_dr[1][2];
      result.m_dr[2][2] = m_dr[2][2];
      result.m_dr[2][3] = m_dr[3][2];

      result.m_dr[3][0] = m_dr[0][3];
      result.m_dr[3][1] = m_dr[1][3];
      result.m_dr[3][2] = m_dr[2][3];
      result.m_dr[3][3] = m_dr[3][3];

      return result;
    }

    Matrix4 Matrix4::operator+(const Matrix4& _matrix)
    {

      Matrix4 result;

      for (int32 x = 0; x < 4; ++x)
      {
        for (int32 y = 0; y < 4; ++y)
        {
          result.m_dr[x][y] = m_dr[x][y] + _matrix.m_dr[x][y];
        }
      }

      return result;
    }

    Matrix4 Matrix4::operator-(const Matrix4& _matrix)
    {
      Matrix4 result;

      for (int32 x = 0; x < 4; ++x)
      {
        for (int32 y = 0; y < 4; ++y)
        {
          result.m_dr[x][y] = m_dr[x][y] - _matrix.m_dr[x][y];
        }
      }

      return result;
    }
  };
}