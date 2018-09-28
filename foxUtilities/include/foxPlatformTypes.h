

#pragma once

/**
 * Includes
 */

#include <cstdint>
#include "foxPlatformDefines.h"

#if FOX_PLATFORM == FOX_PLATFORM_PS4
#   include <scebase.h>
#endif

namespace foxEngineSDK
{

  //Unsigned
  using std::uint8_t;
  using std::uint16_t;
  using std::uint32_t;
  using std::uint64_t;

  //Signed
  using std::int8_t;
  using std::int16_t;
  using std::int32_t;
  using std::int64_t;

  /**
   * Basic unsigned types
   */
  using uint8 = uint8_t;    //8-bit  unsigned.
  using uint16 = uint16_t;  //16-bit unsigned.
  using uint32 = uint32_t;  //32-bit unsigned.
  using uint64 = uint64_t;  //64-bit unsigned.

  /**
   * Basic signed types
   */
  using int8 = int8_t;      //8-bit  signed.
  using int16 = int16_t;    //16-bit signed.
  using int32 = int32_t;    //32-bit signed.
  using int64 = int64_t;    //64-bit signed.

  /**
   * @class QWord
   * @brief 128-bits variable type
   */
  MS_ALIGN(16) class QWord
  {

    /**
     * Constructor
     */
  public:
    
    QWord() : m_lower(0), m_upper(0) {}
    explicit QWord(bool from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int8 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int16 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(int32 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(uint64 from) : m_lower(from), m_upper(0) {}
    explicit QWord(int64 from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(float from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}
    explicit QWord(double from) : m_lower(static_cast<uint64>(from)), m_upper(0) {}

    /**
    * @brief   The cast operator for casting/truncating to 64 bits.
    * @returns The lower 64 bits of the value.
    */
    operator int64() const { return static_cast<uint64>(m_lower); }
  
  public:

    uint64 m_lower; //The lower 64 bits of the 128 bit integer.
    int64	m_upper;  //The upper 64 bits of the 128 bit integer.

  }GCC_ALIGN(16);



  using int128 = QWord;   //Signed 128 bit integer.
  using uint128 = QWord;  //Unsigned 128 bit integer.

  /**
   * NULL data type
   */
  using TYPE_OF_NULL = int32;

  /**
   * SIZE_T is an architecture dependent data type
   */
  using SIZE_T = size_t;
};
