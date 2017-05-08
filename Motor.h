#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin1, int pin2, int power);
  private:
    int power;
};

#endif
