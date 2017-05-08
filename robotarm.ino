#include "Logsystem.h"

Logsystem robot;

void setup(){
  Serial.begin(9600);
}

void loop(){
  robot.log("Test");
  delay(4000);
}


