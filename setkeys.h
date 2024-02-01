#ifndef ENCAPSULATE_VARIABLES_H
#define ENCAPSULATE_VARIABLES_H

#include <Arduino.h>

String encapsulateVariables(int* digitalPins, int* analogPins) {
  String message = "&begin&";

  // Encapsulate digital values
  for (int i = 0; i < 10; i++) {
    int digitalValue = digitalRead(digitalPins[i]);
    if (digitalValue != LOW && digitalValue != HIGH) {
      // Handle unexpected digital values
      digitalValue = -1;
    }
    
    message += "D";
    message += String(i);
    message += ":";
    message += String(digitalValue);
    message += "&";
  }

  // Encapsulate analog values
  for (int i = 0; i < 5; i++) {
    int analogValue = analogRead(analogPins[i]);
    // Add range check for analog values if needed
    message += "A";
    message += String(i);
    message += ":";
    message += String(analogValue);
    message += "&";
  }

  message += "&end&";
  return message;
}

#endif // ENCAPSULATE_VARIABLES_H
