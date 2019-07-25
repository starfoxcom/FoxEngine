/**
* @file foxPlatformMath.cpp
* @author ---
* @date ---
* @brief Utility class providing common scalar math operations.
*/

/**
 * Includes
 */

#include "foxPlatformMath.h"

namespace foxEngineSDK
{
  /*!< PI constant */
  const float Math::PI = static_cast<float>(4.0f * std::atan(1.0f));

  /*!< Inverse of PI */
  const float Math::INV_PI = static_cast<float>(1.0f / PI);

  /*!< Half PI */
  const float Math::HALF_PI = static_cast<float>(0.5f * PI);

  /*!< 2 times PI */
  const float Math::TWO_PI = static_cast<float>(2.0f * PI);

  /*!< Degree to Radian */
  const float Math::DEG2RAD = static_cast<float>(PI / 180.0f);

  /*!< Radian to Degree */
  const float Math::RAD2DEG = static_cast<float>(180.0f / PI);

  /*!< Logarithm base 2 */
  const float Math::LOG2 = static_cast<float>(std::log(2.0f));

  float abs(const float A)
  {
    return static_cast<float>(std::fabsf(A));
  }

  float Math::sin(float value)
  {
    return std::sin(value);
  }

  float Math::cos(float value)
  {
    return std::cosf(value);
  }

  float Math::tan(float value)
  {
    return std::tanf(value);
  }

  float Math::asin(float value)
  {
    return std::asinf(value);
  }

  float Math::acos(float value)
  {
    return std::acosf(value);
  }

  float Math::atan(float value)
  {
    return std::atanf(value);
  }

  float Math::sqr(float A)
  {
    return A * A;
  }

  float Math::sqrt(float value)
  {
    return std::sqrtf(value);
  }

  float Math::logE(float value)
  {
    return std::logf(value);
  }

  float Math::log2(float value)
  {
    return std::logf(value) / LOG2;
  }

  float Math::log10(float value)
  {
    return std::log10f(value);
  }

  float Math::logX(float base, float value)
  {
    return logE(value) / logE(base);
  }

  float Math::invSqrt(float value)
  {
    return 1.0f / std::sqrtf(value);
  }

  float Math::lerp(float & A, float & B, float & alpha)
  {
    return (A + alpha * (B - A));
  }

  int32 Math::trunc(float value)
  {
    return static_cast<int32>(value);
  }

  float Math::truncFloat(float value)
  {
    return static_cast<float>(trunc(value));
  }

  int32 Math::floor(float value)
  {
    return trunc(std::floorf(value));
  }

  float Math::floorFloat(float value)
  {
    return std::floorf(value);
  }

  double Math::floorDouble(double value)
  {
    return std::floor(value);
  }

  int32 Math::round(float value)
  {
    return floor(value + 0.5f);
  }

  float Math::roundFloat(float value)
  {
    return floorFloat(value + 0.5f);
  }

  double Math::roundDouble(double value)
  {
    return floorDouble(value + 0.5f);
  }

  int32 Math::ceil(float value)
  {
    return trunc(std::ceilf(value));
  }

  float Math::ceilFloat(float value)
  {
    return std::ceilf(value);
  }

  double Math::ceilDouble(double value)
  {
    return std::ceil(value);
  }

  float Math::fractional(float value)
  {
    return value - truncFloat(value);
  }

  float Math::fmod(float x, float y)
  {
    return std::fmodf(x, y);
  }

  float Math::pow(float base, float exponent)
  {
    return std::powf(base, exponent);
  }

  float Math::exp(float value)
  {
    return std::expf(value);
  }

  float Math::fMin(float A, float B)
  {
    return std::fminf(A, B);
  }

  float Math::fMax(float A, float B)
  {
    return std::fmaxf(A, B);
  }

  float Math::clamp(float X, float Min, float Max)
  {
    return X < Min ? Min : X < Max ? X : Max;
  }

  float Math::min3(float A, float B, float C)
  {
    return fMin(fMin(A, B), C);
  }

  float Math::max3(float A, float B, float C)
  {
    return fMax(fMax(A, B), C);
  }

  template<typename T>
  inline T Math::abs(const T A)
  {
    return std::abs(A);
  }
}