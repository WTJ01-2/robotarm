#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
    Motor(int pin1, int pin2, int power);
    void resetCurrentVolt();
    void driveRight();
    void driveRight(int duration);
    void driveRight(int duration, byte power);
    void driveLeft();
    void driveLeft(int duration);
    void driveLeft(int duration, byte power);
    void whereAmI(int volt);
    void whereAmIY(int volt);
    void checkVolt(int volt);
    void findVolt(int volt);
    void findVoltY(int volt);
    void checkDuur(int volt);
    void stop();
  private:
    int power;
    int upPower;
    int downPower;
    long startTime;
    long whereAmIDuur;
    int pin1;
    int pin2;

    int currentVolt;
    int searchVolt;
};

#endif
