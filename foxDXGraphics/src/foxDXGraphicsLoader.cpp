#include "foxDXGraphicsAPI.h"

namespace foxEngineSDK
{
  extern "C" __declspec(dllexport) void
    createObject()
  {
    foxGraphicsAPI::startUp<foxDXGraphicsAPI>();
  }
}