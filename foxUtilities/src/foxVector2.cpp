#include "foxVector2.h"
#include "foxVector3.h"

namespace foxEngineSDK
{

  Vector2::~Vector2() {}

  Vector2::Vector2() : x(0.0), y(0.0) {}

  Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

  Vector2::Vector2(const Vector2& _vec2D) : x(_vec2D.x), y(_vec2D.y) {}

  Vector2::Vector2(const Vector3& _vec3D) : x(_vec3D.x), y(_vec3D.y) {}

  Vector2 Vector2::operator+(const Vector2& _vec2D)
  {
    return Vector2(x + _vec2D.x, y + _vec2D.y);
  }

  Vector2 Vector2::operator+(float A)
  {
    return Vector2(x + A, y + A);
  }

  Vector2 Vector2::operator-(const Vector2& _vec2D)
  {
    return Vector2(x - _vec2D.x, y - _vec2D.y);
  }

  Vector2 Vector2::operator-(float A)
  {
    return Vector2(x - A, y - A);
  }

  Vector2 Vector2::operator*(const Vector2& _vec2D)
  {
    return Vector2(x * _vec2D.x, y * _vec2D.y);
  }

  Vector2 Vector2::operator*(float A)
  {
    return Vector2(x * A, y * A);
  }

  Vector2 Vector2::operator/(const Vector2& _vec2D)
  {
    return Vector2(x / _vec2D.x, y / _vec2D.y);
  }

  Vector2 Vector2::operator/(float A)
  {
    return Vector2(x / A, y / A);
  }

  float Vector2::operator|(const Vector2& _vec2D)
  {
    return x * _vec2D.x + y * _vec2D.y;
  }

  float Vector2::operator^(const Vector2 & _vec2D)
  {
    return x * _vec2D.y - y * _vec2D.x;
  }

  bool Vector2::operator<(const Vector2 & _vec2D)
  {
    return x < _vec2D.x && y < _vec2D.y;
  }

  bool Vector2::operator>(const Vector2 & _vec2D)
  {
    return x > _vec2D.x && y > _vec2D.y;
  }

  bool Vector2::operator==(const Vector2 & _vec2D)
  {
    return x == _vec2D.x && y == _vec2D.y;
  }

  bool Vector2::operator!=(const Vector2 & _vec2D)
  {
    return x != _vec2D.x || y != _vec2D.y;
  }

  Vector2 & Vector2::operator+=(const Vector2 & _vec2D)
  {
    x += _vec2D.x;
    y += _vec2D.y;
    return *this;
  }

  Vector2 & Vector2::operator-=(const Vector2 & _vec2D)
  {
    x -= _vec2D.x;
    y -= _vec2D.y;
    return *this;
  }

  Vector2 & Vector2::operator*=(const Vector2 & _vec2D)
  {
    x *= _vec2D.x;
    y *= _vec2D.y;
    return *this;
  }

  Vector2 & Vector2::operator*=(float A)
  {
    x *= A;
    y *= A;
    return *this;
  }

  Vector2 & Vector2::operator/=(const Vector2 & _vec2D)
  {
    x /= _vec2D.x;
    y /= _vec2D.y;
    return *this;
  }

  Vector2 & Vector2::operator/=(float A)
  {
    x /= A;
    y /= A;
    return *this;
  }

  bool Vector2::operator<=(const Vector2 & _vec2D)
  {
    return x <= _vec2D.x && y <= _vec2D.y;
  }

  bool Vector2::operator>=(const Vector2 & _vec2D)
  {
    return x >= _vec2D.x && y >= _vec2D.y;
  }

  float & Vector2::operator[](uint32 _index)
  {
    return ((_index == 0) ? x : y);
  }

  float Vector2::operator[](uint32 _index) const
  {
    return ((_index == 0) ? x : y);
  }
}