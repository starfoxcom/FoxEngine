/**
* @file foxPlatformMath.h
* @author ---
* @date ---
* @brief Utility class providing common scalar math operations.
*/

#pragma once

/**
 * Includes
 */

#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  /**
   * @brief Utility class providing common scalar math operations.
   */
  class FOX_UTILITY_EXPORT Math
  {
  public:

    /**
     * Trigonometric functions
     */
    template <typename T>
    float
      sin(float value)
    {
      return std::sin(value);
    }

    template <typename T>
    float
      cos(float value)
    {
      return std::cosf(value);
    }

    template <typename T>
    float
      tan(float value)
    {
      std::tanf(value);
    }

    template <typename T>
    T
      asin(T value)
    {
      return std::asin(value);
    }

    template <typename T>
    T
      acos(T value)
    {
      return std::acos(value);
    }

    template <typename T>
    T
      atan(T value)
    {
      return std::atan(value);
    }

    /**
     * TODO: Trigonometric functions (Taylor series)
     */


     /**
      * Other math functions
      */
    template <typename T>
    T
      sqr(const T A) //Square of a value
    {
      return A * A;
    }

    template <typename T>
    float
      sqrt(float value) //Square root of a value
    {
      return std::sqrtf(value);
    }

    template <typename T>
    float
      logE(float value) //Logarithm base 'e' of a value
    {
      return std::logf(value);
    }

    template <typename T>
    float
      log2(float value) //Logarithm base 2 of a value
    {
      return std::logf(value) / LOG2;
    }

    template <typename T>
    float
    log10(float value) //Logarithm base 10 of a value
    {
      return std::log10f(value);
    }

    template <typename T>
    float
      logX(float base, float value) //Logarithm base N of a value
    {
      return logE(value) / logE(base);
    }

    template <typename T>
    float
      invSqrt(float value) //Inverted square root of a value
    {
      return 1.0f / std::sqrtf(value);
    }

    template <class T, class U>
    T
      lerp(const T& A, const T& B, const U& alpha) //Linear interpolation alpha blend
    {
      return static_cast<T>(A + alpha * (B - A));
    }

    template <typename T>
    T
      abs(T A) //Absolute of a value
    {
      return std::abs(A);
    }

    template <typename T>
    int32
      trunc(float value) //Truncate a float value into our int value
    {
      return static_cast<int32>(value);
    }

    template <typename T>
    float
      truncFloat(float value) //Truncate a float value into a float value ??
    {
      return static_cast<float>(trunc(value));
    }

    template <typename T>
    int32
      floor(float value) //Round down an int value
    {
      return trunc(std::floorf(value));
    }

    template <typename T>
    float
      floorFloat(float value) //Round down a float value
    {
      return std::floorf(value);
    }

    template <typename T>
    double
      floorDouble(double value) //Round down a double value
    {
      return std::floor(value);
    }

    template <typename T>
    int32
      round(float value) //Rounds an int value
    {
      return floor(value + 0.5f);
    }

    template <typename T>
    float
      roundFloat(float value) //Rounds a float value
    {
      return floorFloat(value + 0.5f);
    }

    template <typename T>
    double
      roundDouble(double value) //Rounds a double value
    {
      return floorDouble(value + 0.5f);
    }

    template <typename T>
    int32
      ceil(float value) //Round up an int value
    {
      return trunc(std::ceilf(value));
    }

    template <typename T>
    float
      ceilFloat(float value) //Round up a float value
    {
      return std::ceilf(value);
    }

    template <typename T>
    double
      ceilDouble(double value) //Round up a double value
    {
      return std::ceil(value);
    }

    template <typename T>
    float
      fractional(float value) //Gets the fractional of a value
    {
      return value - truncFloat(value);
    }

    template <typename T>
    float
      exp(float value) //Gets base-e exponential of value
    {
      return std::expf(value);
    }

    template <typename T>
    T
      min(T A, T B) //Gets the lowest between two values
    {
      return (A <= B) ? A : B;
    }

    template <typename T>
    T
      max(T A, T B) //Gets the highest between two values
    {
      return (A >= B) A : B;
    }

    //TODO: spherical linear interpolation

    template <typename T>
    T
      clamp(T X, T Min, T Max) //Clamp a value within a range
    {
      return X < Min ? Min : X < Max ? X : Max;
    }

    template <typename T>
    T
      min3(T A, T B, T C) //Gets the lowest between three values
    {
      return min(min(A, B), C);
    }

    template <typename T>
    T
      max3(T A, T B, T C) //Gets the highest between three values
    {
      return max(max(A, B), C);
    }

    static const float PI;
    static const float INV_PI;
    static const float HALF_PI;
    static const float TWO_PI;

    static const float DEG2RAD;
    static const float RAD2DEG;
    static const float LOG2;

  };
}