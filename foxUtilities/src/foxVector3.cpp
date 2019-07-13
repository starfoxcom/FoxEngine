#include "foxVector2.h"
#include "foxVector3.h"

namespace foxEngineSDK
{
  Vector3::~Vector3() {}

  Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {}

  Vector3::Vector3(float _x, float _y, float _z) : x(_y), y(_y), z(_z) {}

  Vector3::Vector3(const Vector2& _vec2D, float _z) : x(_vec2D.x), y(_vec2D.y), z(_z) {}

  Vector3::Vector3(const Vector3& _vec3D) : x(_vec3D.x), y(_vec3D.y), z(_vec3D.z) {}

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

  Vector3 Vector3::operator^(const Vector3& _vec3D)
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

  float & Vector3::operator[](uint32 _index)
  {
    return (&x)[_index];
  }

  float Vector3::operator[](uint32 _index) const
  {
    return (&x)[_index];
  }
}