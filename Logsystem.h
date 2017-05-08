#ifndef Logsystem_h
#define Logsystem_h

#include "Arduino.h"

class Logsystem
{
  public:
    Logsystem();
    void log(String message);
    void log(int message);
  private:
};

#endif
