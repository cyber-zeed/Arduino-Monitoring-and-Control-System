#ifndef ENCAPSULATE_VARIABLES_H
#define ENCAPSULATE_VARIABLES_H

#include <Arduino.h>

String encapsulateVariables(int* digitalPins, int* analogPins) {
  String message = "&begin&";

  // Encapsulate digital values
  for (int i = 0; i < 10; i++) {
    message += "D";
    message += String(i);
    message += ":";
    message += String(digitalRead(digitalPins[i]));
    message += "&";
  }

  // Encapsulate analog values
  for (int i = 0; i < 5; i++) {
    message += "A";
    message += String(i);
    message += ":";
    message += String(analogRead(analogPins[i]));
    message += "&";
  }

  message += "&end&";
  return message;
}

#endif // ENCAPSULATE_VARIABLES_H
