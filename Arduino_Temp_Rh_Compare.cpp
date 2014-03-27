/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

#include <Arduino.h>

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int val = 0 ;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
	Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
  val = analogRead(A0);
  digitalWrite(7, LOW);
  pinMode(7, OUTPUT);
  delay(5);
  pinMode(7, INPUT);

  Serial.println(val);

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(100);               // wait for a second
}
