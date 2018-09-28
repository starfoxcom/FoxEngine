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
}