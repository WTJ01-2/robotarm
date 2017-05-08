#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pin1, int pin2, int power){
  this->power = power;
  this->pin1 = pin1;
  this->pin2 = pin2;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}
void Motor::driveRight() {
  digitalWrite(pin1, HIGH);
  analogWrite(pin2, this->power);
}
void Motor::driveLeft() {
  digitalWrite(pin1, LOW);
  analogWrite(pin2, this->power);
}
void Motor::stop() {
  analogWrite(pin2, 0);
}
