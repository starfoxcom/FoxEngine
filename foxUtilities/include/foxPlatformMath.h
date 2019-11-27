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

    static const float PI;
    static const float INV_PI;
    static const float HALF_PI;
    static const float TWO_PI;

    static const float DEG2RAD;
    static const float RAD2DEG;
    static const float LOG2;

    /**
     * Trigonometric functions
     */
    static float
      sin(float value);

    static float
      cos(float value);

    static float
      tan(float value);

    static float
      asin(float value);

    static float
      acos(float value);

    static float
      atan(float value);

    /**
     * TODO: Trigonometric functions (Taylor series)
     */


     /**
      * Other math functions
      */
    static float
      sqr(float A); //Square of a value

    static float
      sqrt(float value); //Square root of a value

    static float
      logE(float value); //Logarithm base 'e' of a value

    static float
      log2(float value); //Logarithm base 2 of a value

    static float
      log10(float value); //Logarithm base 10 of a value

    static float
      logX(float base, float value); //Logarithm base N of a value

    static float
      invSqrt(float value); //Inverted square root of a value

    static float
      lerp(float& A, float& B, float& alpha); //Linear interpolation alpha blend

    template <typename T>
    static T
      abs(const T A); //Absolute of a value

    static int32
      trunc(float value); //Truncate a float value into our int value

    static float
      truncFloat(float value); //Truncate a float value into a float value ??

    static int32
      floor(float value); //Round down an int value

    static float
      floorFloat(float value); //Round down a float value

    static double
      floorDouble(double value); //Round down a double value

    static int32
      round(float value); //Rounds an int value

    static float
      roundFloat(float value); //Rounds a float value

    static double
      roundDouble(double value); //Rounds a double value

    static int32
      ceil(float value); //Round up an int value

    static float
      ceilFloat(float value); //Round up a float value

    static double
      ceilDouble(double value); //Round up a double value

    static float
      fractional(float value); //Gets the fractional of a value

    static float
      fmod(float x, float y); //Gets the floating-point remainder of the x/y division

    static float
      pow(float base, float exponent); //Gets the value of base raised to the power exponent

    static float
      exp(float value); //Gets base-e exponential of value

    static float
      fMin(float A, float B); //Gets the lowest between two values

    static float
      fMax(float A, float B); //Gets the highest between two values

    //TODO: spherical linear interpolation

    static float
      clamp(float X, float Min, float Max); //Clamp a value within a range

    static float
      min3(float A, float B, float C); //Gets the lowest between three values

    static float
      max3(float A, float B, float C); //Gets the highest between three values
  };
}