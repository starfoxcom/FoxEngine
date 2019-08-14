#include "foxVector4.h"
#include "foxVector3.h"
#include "foxVector2.h"
#include "foxPlatformMath.h"

namespace foxEngineSDK
{
  Vector4::Vector4() : x(0.0), y(0.0), z(0.0), w(0.0) {}

  Vector4::Vector4(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w) {}

  Vector4::Vector4(const Vector2 & _vec2Dxy, const Vector2 & _vec2Dzw) :
    x(_vec2Dxy.x), y(_vec2Dxy.y), z(_vec2Dzw.x), w(_vec2Dzw.y) {}

  Vector4::Vector4(const Vector3& _vec3D, float _w) :
    x(_vec3D.x), y(_vec3D.y), z(_vec3D.z), w(_w) {}

  Vector4::Vector4(const Vector4& _vec4D) :
    x(_vec4D.x), y(_vec4D.y), z(_vec4D.z), w(_vec4D.w) {}

  Vector4 Vector4::operator+(const Vector4& _vec4D)
  {
    return Vector4(x + _vec4D.x, y + _vec4D.y, z + _vec4D.z, w + _vec4D.w);
  }

  Vector4 Vector4::operator+(float A)
  {
    return Vector4(x + A, y + A, z + A, w + A);
  }

  Vector4 Vector4::operator-(const Vector4& _vec4D)
  {
    return Vector4(x - _vec4D.x, y - _vec4D.y, z - _vec4D.z, w - _vec4D.w);
  }

  Vector4 Vector4::operator-(float A)
  {
    return Vector4(x - A, y - A, z - A, w - A);
  }

  Vector4 Vector4::operator*(const Vector4& _vec4D)
  {
    return Vector4(x * _vec4D.x, y * _vec4D.y, z * _vec4D.z, w * _vec4D.w);
  }

  Vector4 Vector4::operator*(float A)
  {
    return Vector4(x *A, y * A, z * A, w * A);
  }

  Vector4 Vector4::operator/(const Vector4& _vec4D)
  {
    return Vector4(x / _vec4D.x, y / _vec4D.y, z / _vec4D.z, w / _vec4D.w);
  }

  Vector4 Vector4::operator/(float A)
  {
    return Vector4(x / A, y / A, z / A, w / A);
  }

  Vector4 Vector4::operator^(const Vector4& _vec4D)
  {
    return Vector4(
      y * _vec4D.z - z * _vec4D.y,
      z * _vec4D.x - x * _vec4D.z,
      x * _vec4D.y - y * _vec4D.x,
      0.0f);
  }

  float Vector4::operator|(const Vector4 & _vec4D)
  {
    return x * _vec4D.x + y * _vec4D.y + z * _vec4D.z + w * _vec4D.w;
  }

  bool Vector4::operator==(const Vector4& _vec4D)
  {
    return x == _vec4D.x && y == _vec4D.y && z == _vec4D.z && w == _vec4D.w;
  }

  bool Vector4::operator!=(const Vector4& _vec4D)
  {
    return x != _vec4D.x - x || y != _vec4D.y || z != _vec4D.z || w != _vec4D.w;
  }

  Vector4 & Vector4::operator+=(const Vector4& _vec4D)
  {
    x += _vec4D.x;
    y += _vec4D.y;
    z += _vec4D.z;
    w += _vec4D.w;
    return *this;
  }

  Vector4 & Vector4::operator*=(const Vector4& _vec4D)
  {
    x *= _vec4D.x;
    y *= _vec4D.y;
    z *= _vec4D.z;
    w *= _vec4D.w;
    return *this;
  }

  Vector4 & Vector4::operator*=(float A)
  {
    x *= A;
    y *= A;
    z *= A;
    w *= A;
    return *this;
  }

  Vector4 & Vector4::operator/=(const Vector4& _vec4D)
  {
    x /= _vec4D.x;
    y /= _vec4D.y;
    z /= _vec4D.z;
    w /= _vec4D.w;
    return *this;
  }

  float & Vector4::operator[](uint32 _index)
  {
    return (&x)[_index];
  }

  float Vector4::operator[](uint32 _index) const
  {
    return (&x)[_index];
  }
  float Vector4::magnitude()
  {
    return Math::sqrt(x * x + y * y + z * z + w * w);
  }
  Vector4 Vector4::normalized()
  {
    const float scale = Math::invSqrt(x * x + y * y + z * z);
    return Vector4(x*scale, y*scale, z*scale, 0.0f);
  }
}