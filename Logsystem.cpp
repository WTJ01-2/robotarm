#include "Arduino.h"
#include "Logsystem.h"

Logsystem::Logsystem(){
}

void Logsystem::log(String message) {
  Serial.println(message);
}
void Logsystem::log(int message) {
  Serial.println(message);
}
