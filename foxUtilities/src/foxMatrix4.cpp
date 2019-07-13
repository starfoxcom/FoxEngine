#include "foxMatrix4.h"
#include "foxVector3.h"
#include "foxVector4.h"

namespace foxEngineSDK
{

  Matrix4::Matrix4()
  {
    this->zero();
  }

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
    m_dr[0][0] = _matrix.m_dr[0][0];
    m_dr[0][1] = _matrix.m_dr[0][1];
    m_dr[0][2] = _matrix.m_dr[0][2];
    m_dr[0][3] = _matrix.m_dr[0][3];
    m_dr[1][0] = _matrix.m_dr[1][0];
    m_dr[1][1] = _matrix.m_dr[1][1];
    m_dr[1][2] = _matrix.m_dr[1][2];
    m_dr[1][3] = _matrix.m_dr[1][3];
    m_dr[2][0] = _matrix.m_dr[2][0];
    m_dr[2][1] = _matrix.m_dr[2][1];
    m_dr[2][2] = _matrix.m_dr[2][2];
    m_dr[2][3] = _matrix.m_dr[2][3];
    m_dr[3][0] = _matrix.m_dr[3][0];
    m_dr[3][1] = _matrix.m_dr[3][1];
    m_dr[3][2] = _matrix.m_dr[3][2];
    m_dr[3][3] = _matrix.m_dr[3][3];
  }

  Matrix4::Matrix4(
    float _00, float _01, float _02, float _03,
    float _10, float _11, float _12, float _13,
    float _20, float _21, float _22, float _23,
    float _30, float _31, float _32, float _33)
  {
    m_dr[0][0] = _00; m_dr[0][1] = _01; m_dr[0][2] = _02; m_dr[0][3] = _03;
    m_dr[1][0] = _10; m_dr[1][1] = _11; m_dr[1][2] = _12; m_dr[1][3] = _13;
    m_dr[2][0] = _20; m_dr[2][1] = _21; m_dr[2][2] = _22; m_dr[2][3] = _23;
    m_dr[3][0] = _30; m_dr[3][1] = _31; m_dr[3][2] = _32; m_dr[3][3] = _33;
  }

  void Matrix4::identity()
  {
    m_dr[0][0] = 1.0f; m_dr[0][1] = 0.0f; m_dr[0][2] = 0.0f; m_dr[0][3] = 0.0f;
    m_dr[1][0] = 0.0f; m_dr[1][1] = 1.0f; m_dr[1][2] = 0.0f; m_dr[1][3] = 0.0f;
    m_dr[2][0] = 0.0f; m_dr[2][1] = 0.0f; m_dr[2][2] = 1.0f; m_dr[2][3] = 0.0f;
    m_dr[3][0] = 0.0f; m_dr[3][1] = 0.0f; m_dr[3][2] = 0.0f; m_dr[3][3] = 1.0f;
  }

  void Matrix4::zero()
  {
    m_dr[0][0] = 0.0f; m_dr[0][1] = 0.0f; m_dr[0][2] = 0.0f; m_dr[0][3] = 0.0f;
    m_dr[1][0] = 0.0f; m_dr[1][1] = 0.0f; m_dr[1][2] = 0.0f; m_dr[1][3] = 0.0f;
    m_dr[2][0] = 0.0f; m_dr[2][1] = 0.0f; m_dr[2][2] = 0.0f; m_dr[2][3] = 0.0f;
    m_dr[3][0] = 0.0f; m_dr[3][1] = 0.0f; m_dr[3][2] = 0.0f; m_dr[3][3] = 0.0f;
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

  //Matrix4 Matrix4::operator-(const Matrix4& _matrix)
  //{
  //  Matrix4 result;

  //  for (int32 x = 0; x < 4; ++x)
  //  {
  //    for (int32 y = 0; y < 4; ++y)
  //    {
  //      result.m_dr[x][y] = m_dr[x][y] - _matrix.m_dr[x][y];
  //    }
  //  }

  //  return result;
  //}

  Matrix4 Matrix4::operator*(const Matrix4 & _matrix)
  {

    return Matrix4(
      Vector4(m_dr[0][0], m_dr[0][1], m_dr[0][2], m_dr[0][3]) |
      Vector4(_matrix.m_dr[0][0], _matrix.m_dr[1][0], _matrix.m_dr[2][0], _matrix.m_dr[3][0]),
      Vector4(m_dr[0][0], m_dr[0][1], m_dr[0][2], m_dr[0][3]) |
      Vector4(_matrix.m_dr[0][1], _matrix.m_dr[1][1], _matrix.m_dr[2][1], _matrix.m_dr[3][1]),
      Vector4(m_dr[0][0], m_dr[0][1], m_dr[0][2], m_dr[0][3]) |
      Vector4(_matrix.m_dr[0][2], _matrix.m_dr[1][2], _matrix.m_dr[2][2], _matrix.m_dr[3][2]),
      Vector4(m_dr[0][0], m_dr[0][1], m_dr[0][2], m_dr[0][3]) |
      Vector4(_matrix.m_dr[0][3], _matrix.m_dr[1][3], _matrix.m_dr[2][3], _matrix.m_dr[3][3]),

      Vector4(m_dr[1][0], m_dr[1][1], m_dr[1][2], m_dr[1][3]) |
      Vector4(_matrix.m_dr[0][0], _matrix.m_dr[1][0], _matrix.m_dr[2][0], _matrix.m_dr[3][0]),
      Vector4(m_dr[1][0], m_dr[1][1], m_dr[1][2], m_dr[1][3]) |
      Vector4(_matrix.m_dr[0][1], _matrix.m_dr[1][1], _matrix.m_dr[2][1], _matrix.m_dr[3][1]),
      Vector4(m_dr[1][0], m_dr[1][1], m_dr[1][2], m_dr[1][3]) |
      Vector4(_matrix.m_dr[0][2], _matrix.m_dr[1][2], _matrix.m_dr[2][2], _matrix.m_dr[3][2]),
      Vector4(m_dr[1][0], m_dr[1][1], m_dr[1][2], m_dr[1][3]) |
      Vector4(_matrix.m_dr[0][3], _matrix.m_dr[1][3], _matrix.m_dr[2][3], _matrix.m_dr[3][3]),

      Vector4(m_dr[2][0], m_dr[2][1], m_dr[2][2], m_dr[2][3]) |
      Vector4(_matrix.m_dr[0][0], _matrix.m_dr[1][0], _matrix.m_dr[2][0], _matrix.m_dr[3][0]),
      Vector4(m_dr[2][0], m_dr[2][1], m_dr[2][2], m_dr[2][3]) |
      Vector4(_matrix.m_dr[0][1], _matrix.m_dr[1][1], _matrix.m_dr[2][1], _matrix.m_dr[3][1]),
      Vector4(m_dr[2][0], m_dr[2][1], m_dr[2][2], m_dr[2][3]) |
      Vector4(_matrix.m_dr[0][2], _matrix.m_dr[1][2], _matrix.m_dr[2][2], _matrix.m_dr[3][2]),
      Vector4(m_dr[2][0], m_dr[2][1], m_dr[2][2], m_dr[2][3]) |
      Vector4(_matrix.m_dr[0][3], _matrix.m_dr[1][3], _matrix.m_dr[2][3], _matrix.m_dr[3][3]),

      Vector4(m_dr[3][0], m_dr[3][1], m_dr[3][2], m_dr[3][3]) |
      Vector4(_matrix.m_dr[0][0], _matrix.m_dr[1][0], _matrix.m_dr[2][0], _matrix.m_dr[3][0]),
      Vector4(m_dr[3][0], m_dr[3][1], m_dr[3][2], m_dr[3][3]) |
      Vector4(_matrix.m_dr[0][1], _matrix.m_dr[1][1], _matrix.m_dr[2][1], _matrix.m_dr[3][1]),
      Vector4(m_dr[3][0], m_dr[3][1], m_dr[3][2], m_dr[3][3]) |
      Vector4(_matrix.m_dr[0][2], _matrix.m_dr[1][2], _matrix.m_dr[2][2], _matrix.m_dr[3][2]),
      Vector4(m_dr[3][0], m_dr[3][1], m_dr[3][2], m_dr[3][3]) |
      Vector4(_matrix.m_dr[0][3], _matrix.m_dr[1][3], _matrix.m_dr[2][3], _matrix.m_dr[3][3]));
  }

  Matrix4 Matrix4::operator*(float _value)
  {
    return Matrix4(
      m_sr[0] * _value,
      m_sr[1] * _value,
      m_sr[2] * _value,
      m_sr[3] * _value,
      m_sr[4] * _value,
      m_sr[5] * _value,
      m_sr[6] * _value,
      m_sr[7] * _value,
      m_sr[8] * _value,
      m_sr[9] * _value,
      m_sr[10] * _value,
      m_sr[11] * _value,
      m_sr[12] * _value,
      m_sr[13] * _value,
      m_sr[14] * _value,
      m_sr[15] * _value);
  }

  void Matrix4::operator+=(const Matrix4 & _matrix)
  {
    *this = *this + _matrix;
  }

  void Matrix4::operator*=(const Matrix4 & _matrix)
  {
    *this = *this * _matrix;
  }

  void Matrix4::operator*=(float _value)
  {
    *this = *this * _value;
  }

  bool Matrix4::operator==(const Matrix4 & _matrix)
  {
    for (int32 x = 0; x < 4; ++x) {

      for (int32 y = 0; y < 4; ++y) {

        if (m_dr[x][y] != _matrix.m_dr[x][y]) {

          return false;
        }
      }
    }

    return true;
  }
  bool Matrix4::operator!=(const Matrix4 & _matrix)
  {
    return !(*this == _matrix);
  }
}