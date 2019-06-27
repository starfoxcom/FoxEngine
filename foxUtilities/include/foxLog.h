/**
* @file foxLog.h
* @author ---
* @date ---
* @brief Implementation for logging messages.
*
*/

#pragma once

/**
 * Includes
 */
#include "foxPrerequisitesUtilities.h"

namespace foxEngineSDK
{

  /**
  * @brief Utility class providing logging methods.
  */
  class FOX_UTILITY_EXPORT Log
  {

  public:

    enum LogLevel
    {
      LOGINFO,
      LOGWARN,
      LOGERROR
    };

  

  /**
   * @brief Constructor for the logs
   */
    Log(LogLevel _logLevel = LOGINFO, bool _headers = false);

    ~Log();

    template<class T>
    Log& operator<<(const T& _msg);

    Log& operator<<(const char* _msg);

  private:

    LogLevel m_logLevel;

    bool headers;
    bool opened = false;

    inline std::string getHeader(LogLevel _logLevel)
    {
      std::string header;
      switch (_logLevel)
      {
      case Log::LOGINFO:
        header = "INFO";
        break;
      case Log::LOGWARN:
        header = "WARN";
        break;
      case Log::LOGERROR:
        header = "ERROR";
        break;
      default:
        break;
      }
      return header;
    }
    
  };
}