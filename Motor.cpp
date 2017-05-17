#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pin1, int pin2, int power){
  this->power = power;
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->currentVolt = 0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void Motor::driveRight() {
  digitalWrite(pin1, HIGH);
  analogWrite(pin2, this->power);
}

void Motor::driveRight(int duration) {
  this->driveRight();
  delay(duration);
  this->stop();
}


void Motor::driveRight(int duration, byte power) {
  digitalWrite(pin1, HIGH);
  analogWrite(pin2, power);
  delay(duration);
  this->stop();
}


void Motor::driveLeft() {
  digitalWrite(pin1, LOW);
  analogWrite(pin2, this->power);
}

void Motor::driveLeft(int duration) {
  this->driveLeft();
  delay(duration);
  this->stop();
}


void Motor::driveLeft(int duration, byte power) {
  digitalWrite(pin1, LOW);
  analogWrite(pin2, power);
  delay(duration);
  this->stop();
}

void Motor::stop() {
  analogWrite(pin2, 0);
}

void Motor::findVolt(int volt) {
  if(currentVolt == 0){
    this->whereAmI(volt);
  }else{
    int readPower = analogRead(A0);
    Serial.println(currentVolt); 
    if((currentVolt > volt*0.90) && (currentVolt < (volt*1.1))){
      Serial.println("HIj staat er al"); 
      this->stop();
    }else{
      if(currentVolt > volt){
        Serial.println("Hij is hoger dan vorige"); 
        this->driveRight(); 
      }else if(currentVolt < volt){
        Serial.println("Hij is lager dan vorige"); 
        this->driveLeft();
      }
      if(readPower > 15){
        currentVolt = readPower;
      }      
      this->findVolt(volt);
    }
  }
}


void Motor::whereAmI(int volt) {
  int readPower = analogRead(A0);
  if(readPower > 15){
   this->currentVolt = readPower;
   this->stop();
   this->findVolt(volt);
  }else{
   this->driveRight();
   this->whereAmI(volt);
  }
}
