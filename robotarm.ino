#include "Logsystem.h"
#include "Motor.h"

Logsystem message;
Motor motor1(7, 6, 255);
Motor motor2(4, 5, 255);

int command = 0;
byte old = 0;

void setup(){
  Serial.begin(9600);
  pinMode(A1, INPUT);
}

void loop(){

  if (Serial.available() > 0) {
      command = Serial.read();
      if (command == 97){
          motor1.driveRight();
          motor2.driveRight();
      }else if (command == 100){
        motor1.driveLeft();
        motor2.driveLeft();
      }else{
          motor1.stop();
          motor2.stop();
      }

  }
  //message.log("Lezen commando's");
  byte readPower = digitalRead(A1);
  if(readPower == 0 && readPower != old) {
  Serial.println(readPower);
  }
  old = readPower;
  //message.l
}
