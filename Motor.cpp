#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int pin1, int pin2, int power){
  this->power = power;
  this->upPower = 140;
  this->downPower = 50;
  this->pin1 = pin1;
  this->pin2 = pin2;
  this->currentVolt = 0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  this->startTime=0;
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
      Serial.println("Hij heeft hem gezien"); 
      this->stop();
      //this->checkVolt(volt);
    }else{
      if(currentVolt > volt) {
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

void Motor::checkVolt(int volt) {
  delay(100);
  int readPower = analogRead(A0);
  if((readPower > volt*0.90) && (readPower < (volt*1.1))){
      this->stop();
      Serial.println("Hij is er nog"); 
  } else if(currentVolt < volt) {
      Serial.println("Ik moet terug naar rechts"); 
    this->driveRight();
    if(readPower > 15){
      currentVolt = readPower;
    }   
    this->findVolt(volt);
  }else if(currentVolt > volt){
    Serial.println("Ik moet terug naar links");
    this->driveLeft();
    if(readPower > 15){
      currentVolt = readPower;
    }  
    this->findVolt(volt);
  }
}

void Motor::findVoltY(int volt) {
  Motor::checkDuur(volt);

  Serial.println("findVoltY"); 
  if(currentVolt == 0){
    this->whereAmIY(volt);
  }else{
    int readPower = analogRead(A1);
    Serial.println(currentVolt); 
    if((currentVolt > volt*0.90) && (currentVolt < (volt*1.1))){
      this->startTime = 0;
      Serial.println("Hij staat er al"); 
      this->stop();
    }else{
      if(currentVolt > volt){
        Serial.println("Hij is hoger dan vorige Y"); 
        digitalWrite(pin1, LOW);
        analogWrite(pin2, this->upPower);
      }else if(currentVolt < volt){

        Serial.println("Hij is lager dan vorige Y"); 
        digitalWrite(pin1, HIGH);
        analogWrite(pin2, this->downPower);

      }
      if(readPower > 15){
        currentVolt = readPower;
      }      
      this->findVoltY(volt);
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

void Motor::whereAmIY(int volt) {
  //Motor::checkDuur(volt);
  int readPower = analogRead(A1);
  if(readPower > 15){
   this->currentVolt = readPower;
   this->stop();
   this->findVoltY(volt);
  }else{
    digitalWrite(pin1, LOW);
    analogWrite(pin2, this->upPower);
   this->whereAmIY(volt);
  }
}

void Motor::checkDuur(int volt) {
    
  if(this->startTime!=0) {
    if(millis() - this->startTime > 10000) {
      Serial.println("Ik ben te lang bezig");
      this->startTime = millis();
      this->currentVolt=0;
      this->upPower += 20;
      this->downPower += 20;
      this->driveRight(2000, this->downPower+10);
      this->whereAmIY(volt);
    }
  } else {
    startTime = millis();
  }
}

