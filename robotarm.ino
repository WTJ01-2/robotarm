#include "Logsystem.h"
#include "Motor.h"

Logsystem message;

Motor motor1(7, 6, 240);
//linkerPins
Motor motor2(4, 5, 140);
//Motor motor2(4, 5, 240);
//rechterPins

String command = "";

int v1 = 510;
int v2 = 338;
int v3 = 251;
int v4 = 143;
int v5 = 30;

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
}

boolean wasZero = false;
void loop(){
  int readPower = analogRead(A1);
  Serial.println(readPower);
  if (Serial.available()) {
      command = Serial.readString();
      if (command == "1"){
        motor2.findVolt(v1);
      }else if (command == "2"){
       motor2.findVolt(v2);
      }else if (command == "3"){
        motor2.findVolt(v3);
      }else if (command == "4"){
        motor2.findVolt(v4);
      }else if (command == "5"){
        motor2.findVolt(v5);
      }else if (command == "left"){
        motor2.driveLeft(200,255);
      }else if (command == "right"){
        motor2.driveRight(200);
      }else if (command == "up"){
        motor1.driveLeft(600,255);
        motor1.driveLeft(2000,100);
        
      }else if (command == "down"){
        motor1.driveRight(300, 90);
        motor1.driveLeft(2000,100);
      }
      else{
        motor1.stop();
        motor2.stop();
      }
  }

/*
  
  int readPower = analogRead(A0);
  Serial.println(readPower);
 // return;
    
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
  }*/
}

