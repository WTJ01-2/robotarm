#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pin1, int pin2, int power){
  this->power = power;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}
