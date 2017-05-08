#include "Arduino.h"
#include "Motor.h"

Motor::Motor(){
}

void Motor::log(String message) {
  Serial.print(message);
}
