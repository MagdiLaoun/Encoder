#include <Arduino.h>
#include <MLEncoder.h>
#define CHA 5
#define CHB 6
Encoder encoder; //Create an instance of the Encoder class
int position = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //Initialize serial communication at 9600 baud rate
  encoder.begin(CHA, CHB); //A and B pins of the encoder connected to pins 5 and 6 respectively
}

void loop() {
  int newPosition = encoder.getPosition(); //Read the current position of the encoder
  if (newPosition != position) {
    position = newPosition;
    Serial.print("Position: ");
    Serial.println(position); //Print the current position to the serial monitor
  }
  delay(10); //Small delay to avoid flooding the serial monitor with too many messages
}
