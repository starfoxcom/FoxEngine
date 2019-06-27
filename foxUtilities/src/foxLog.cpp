/**
 * Includes
 */
#include "foxLog.h"

namespace foxEngineSDK
{
  Log::Log(LogLevel _logLevel, bool _headers)
    : m_logLevel(_logLevel), headers(_headers)
  {
    if (headers)
    {
      operator << ("[" + getHeader(m_logLevel) + "]");
    }
  }

  Log::~Log()
  {
    if (opened)
    {
      std::cout << std::endl;
    }
    opened = false;
  }

  Log & Log::operator<<(const char * _msg)
  {
    std::cout << _msg;

    opened = true;

    return *this;
  }

  template<class T>
  Log & Log::operator<<(const T & _msg)
  {
    std::cout << _msg;

    opened = true;

    return *this;
  }
}