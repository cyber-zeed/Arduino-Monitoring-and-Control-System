#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "encapsulate_variables.h"
#include "setkeys.h"

#define LCD_ADDRESS 0x27
#define LCD_COLUMNS 20
#define LCD_ROWS 4

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

int digitalPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int analogPins[] = {A0, A1, A2, A3, A4};
bool previousDigitalStates[10];

const int SECOND_INTERVAL = 1000;
const int DIGITAL_READ_DELAY = 500;

void setup() {
  Serial.begin(9600);
  lcd.begin(LCD_COLUMNS, LCD_ROWS);
  lcd.backlight();

  for (int i = 0; i < 10; i++) {
    pinMode(digitalPins[i], OUTPUT);
    previousDigitalStates[i] = digitalRead(digitalPins[i]);
  }
}

void loop() {
  readAnalogValues();
  setDigitalPinsHigh();
  setDigitalPinsLow();
  setDigitalPortState(digitalPins);
  checkDigitalStateChanges();
  printEncapsulatedVariables();
  delay(SECOND_INTERVAL);
}

void readAnalogValues() {
  for (int i = 0; i < 5; i++) {
    int analogValue = analogRead(analogPins[i]);
    lcd.setCursor(0, i);
    lcd.print("A");
    lcd.print(i);
    lcd.print(": ");
    lcd.print(analogValue);
    lcd.print("     ");
    delay(DIGITAL_READ_DELAY);
  }
}

void setDigitalPinsHigh() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(digitalPins[i], HIGH);
    lcd.setCursor(0, i + 5);
    lcd.print("D");
    lcd.print(i);
    lcd.print(": HIGH    ");
    delay(DIGITAL_READ_DELAY);
  }
}

void setDigitalPinsLow() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(digitalPins[i], LOW);
    lcd.setCursor(0, i + 5);
    lcd.print("D");
    lcd.print(i);
    lcd.print(": LOW     ");
    delay(DIGITAL_READ_DELAY);
  }
}

void printEncapsulatedVariables() {
  String message = encapsulateVariables(digitalPins, analogPins);
  Serial.println(message);
}

void checkDigitalStateChanges() {
  static bool previousDigitalStates[10] = {false};
  bool changeDetected = false;

  for (int i = 0; i < 10; i++) {
    bool currentDigitalState = digitalRead(digitalPins[i]);
    if (currentDigitalState != previousDigitalStates[i]) {
      changeDetected = true;
      previousDigitalStates[i] = currentDigitalState;
    }
  }

  if (changeDetected || millis() % SECOND_INTERVAL == 0) {
    printEncapsulatedVariables();
  }
}
