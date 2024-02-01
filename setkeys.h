#ifndef SETDIGITALPINS_H
#define SETDIGITALPINS_H

#include <Arduino.h>

void setDigitalPinState(int* digitalPins) {
  while (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command.startsWith("d") && command.length() > 3) {
      int portNumber = command.substring(1, 2).toInt();
      const int MIN_DIGITAL_PIN = 2;
      const int MAX_DIGITAL_PIN = 11;

      if (portNumber >= MIN_DIGITAL_PIN && portNumber <= MAX_DIGITAL_PIN) {
        String stateCommand = command.substring(2);
        if (stateCommand == "on") {
          digitalWrite(digitalPins[portNumber - MIN_DIGITAL_PIN], HIGH);
          Serial.println("Port D" + String(portNumber) + " turned ON.");
        } else if (stateCommand == "off") {
          digitalWrite(digitalPins[portNumber - MIN_DIGITAL_PIN], LOW);
          Serial.println("Port D" + String(portNumber) + " turned OFF.");
        } else {
          Serial.println("Invalid command for Port D" + String(portNumber) + ".");
        }
      } else {
        Serial.println("Invalid port number.");
      }
    } else {
      Serial.println("Invalid command format.");
    }
  }
}

#endif // SETDIGITALPINS_H
