/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  This example code is in the public domain.
 */

#include <Arduino.h>

// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13 ;
int dht22_pin = 2 ;
int val =  0 ;


void interrupt_dht022( )
{
	if( LOW == digitalRead( dht22_pin ) )
	{
		digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
	}
	else
	{
		digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	}
}

// the setup routine runs once when you press reset:
void setup()
{
	// initialize the digital pin as an output.
	attachInterrupt(0,interrupt_dht022, FALLING) ;

	Serial.begin(9600) ;
}

// the loop routine runs over and over again forever:
void loop()
{
	digitalWrite(dht22_pin, LOW);   // Send the start signal
	pinMode(dht22_pin, OUTPUT) ;
	delay( 5 ) ;
	pinMode(dht22_pin, INPUT) ;

	attachInterrupt(0,interrupt_dht022, FALLING) ;
}
