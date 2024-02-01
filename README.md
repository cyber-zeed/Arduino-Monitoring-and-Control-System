Arduino Monitoring and Control System
Overview
The Arduino Monitoring and Control System is a simple Arduino-based program designed to read analog sensor values, control digital outputs, and display information on an I2C LCD display. The system provides functionality for monitoring analog sensors, controlling digital pins, and sending encapsulated data through the serial port.

Components
Arduino Board: Any Arduino board compatible with the used libraries.
I2C LCD Display: 20x4 characters.
Digital Components: LEDs, switches, or other devices connected to digital pins.
Analog Sensors: Sensors connected to analog pins.
Software Modules
1. encapsulate_variables.h
This module encapsulates the state of digital and analog pins into a formatted string. It is used to create a message containing the current state of the system for serial communication.

Functions:
String encapsulateVariables(int* digitalPins, int* analogPins): Encapsulates the digital and analog pin values into a formatted string.
2. setkeys.h
This module handles serial commands for setting the state of digital pins. It processes commands received from the serial port to turn digital ports on or off.

Functions:
void setDigitalPortState(int* digitalPins): Listens for serial commands and sets the state of digital pins accordingly.
3. Main Code
The main Arduino code orchestrates the system's behavior. It includes functionality for reading analog values, controlling digital pins, handling serial commands, and displaying information on the LCD.

Functions:
void setup(): Initializes the system, sets up digital pins, and starts the serial communication.
void loop(): Contains the main loop that reads analog values, controls digital pins, handles serial commands, and prints information to the serial port.
Usage
Connecting Components:

Connect digital components to digital pins (D2 to D11).
Connect analog sensors to analog pins (A0 to A4).
Connect the I2C LCD display.
Uploading Code:

Upload the Arduino code to the board using the Arduino IDE.
Serial Commands:

Use the serial monitor to send commands like d1on or d2off to control the state of digital pins.
Monitor Serial Output:

View the serial monitor to observe system status and changes in digital and analog pin states.
LCD Display:

Observe the LCD display for real-time information on analog sensor values.
Configuration
Adjust digital and analog pin configurations in the code to match your hardware setup.
Modify constants for delay intervals as needed.
Known Issues and Limitations
None reported.
Future Enhancements
Add support for additional sensors or components.
Implement more advanced error handling and reporting.
Contributors
Flavio Ribeiro Lira

License
This software is open-source and available under the MIT License.

