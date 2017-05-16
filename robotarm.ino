#include "Logsystem.h"
#include "Motor.h"

Logsystem message;

Motor motor1(7, 6, 255);
//linkerPins
Motor motor2(4, 5, 240);
//rechterPins

int command = 0;

int v1 = 510;
int v2 = 338;
int v3 = 251;
int v4 = 143;
int v5 = 30;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop(){
  int readPower = analogRead(A0);
  Serial.println(readPower); 
    
  if (Serial.available() > 0) {
      command = Serial.read();
      if (command == 49){
        motor2.findVolt(v1);
      }else if (command == 50){
       motor2.findVolt(v2);
      }else if (command == 51){
        motor2.findVolt(v3);
      }else if (command == 52){
        motor2.findVolt(v4);
      }else if (command == 53){
        motor2.findVolt(v5);
      }
      else{
        motor1.stop();
        motor2.stop();
      }
  }
}
