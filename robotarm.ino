#include "Logsystem.h"
#include "Motor.h"

Logsystem message;
Motor robot(4, 5, 255);

void setup(){
  Serial.begin(9600);
}

void loop(){
  message.log("Test");
  delay(4000);
}
