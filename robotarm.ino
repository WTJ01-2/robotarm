#include "Logsystem.h"
#include "Motor.h"

Logsystem message;

Motor motor1(7, 6, 255);
//linkerPins
Motor motor2(4, 5, 140);
//rechterPins

String command = "";
int v[5] = {510,338,251,143,30};

void setup(){
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
}

boolean wasZero = false;
void loop(){
  //int readPower = analogRead(A1);
 // Serial.println(readPower);
  if (Serial.available()) {
      command = Serial.readString();
      Serial.println(command);
      if(getStringPartByNr(command,'-',0)=="command") {
          if(getStringPartByNr(command,'-',1)=="x") {
              motor2.findVolt(v[getStringPartByNr(command,'-',2).toInt() - 1 ]);
          } else if(getStringPartByNr(command,'-',1)=="y") {
              motor1.findVoltY(v[getStringPartByNr(command,'-',2).toInt()-1]);
          }
      } else if (command == "left"){
        motor2.driveLeft(800);
      } else if (command == "right"){
        motor2.driveRight(800);
      } else if (command == "up"){
        motor1.driveLeft(600,255);
      } else if (command == "down"){
        motor1.driveRight(600, 90);
      } else {
        Serial.println("Unknown command");
        motor1.stop();
        motor2.stop();
      }
  }
}

String getStringPartByNr(String data, char separator, int index) {
    int stringData = 0;        //variable to count data part nr 
    String dataPart = "";      //variable to hole the return text

    for(int i = 0; i<data.length(); i++) {    //Walk through the text one letter at a time
        if(data[i]==separator) {
            //Count the number of times separator character appears in the text
            stringData++;
        } else if(stringData==index) {
            //get the text when separator is the rignt one
            dataPart.concat(data[i]);
        } else if(stringData>index) {
            //return text and stop if the next separator appears - to save CPU-time
            return dataPart;
            break;
        }
    }
    //return text if this is the last part
    return dataPart;
}

