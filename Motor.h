#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin1, int pin2, int power);
    void driveRight();
    void driveLeft();
    void stop();
  private:
    int power;
    int pin1;
    int pin2;
};

#endif
