#include "Arduino.h"
#include "Logsystem.h"

Logsystem::Logsystem(){
}

void Logsystem::log(String message) {
  Serial.print(message);
}
