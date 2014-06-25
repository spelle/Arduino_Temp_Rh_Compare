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
unsigned long ulMicros = 0 ;
unsigned char ucDHT22BitCount = 40 ;



typedef enum
{
	dht22_Init,
	dht22_HostSendStart,
	dht22_HostWaitForSensorStart,
	dht22_SensorSendData,

} dht22_state_t ;
dht22_state_t DHT22_State = dht22_Init ;



void interrupt_dht022( )
{
	Serial.print( int(ucDHT22BitCount) ) ;

	if( LOW == digitalRead( dht22_pin ) )
	{
		digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
	}
	else
	{
		digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
	}

	ulMicros = micros() ;

	switch( DHT22_State )
	{
		case dht22_Init :
		case dht22_HostSendStart :
		break ;

		case dht22_HostWaitForSensorStart :
			// Nothing to do
			ucDHT22BitCount = 40 ;

			DHT22_State = dht22_SensorSendData ;
			break ;

		case dht22_SensorSendData :
			// A bit has been received !
			ucDHT22BitCount -- ;

			if( 0 == ucDHT22BitCount )
				DHT22_State = dht22_HostSendStart ;

			break ;
	}

}



// the setup routine runs once when you press reset:
void setup()
{
	// initialize the digital pin as an output.
	//attachInterrupt(0,interrupt_dht022, FALLING) ;

	Serial.begin(9600) ;

	delay( 1000 ) ;
}



// the loop routine runs over and over again forever:
void loop()
{
	DHT22_State = dht22_HostSendStart ;
	digitalWrite(dht22_pin, LOW);   // Send the start signal
	pinMode(dht22_pin, OUTPUT) ;
	delay( 5 ) ;
	pinMode(dht22_pin, INPUT) ;
	DHT22_State = dht22_HostWaitForSensorStart ;

	attachInterrupt(0,interrupt_dht022, RISING) ;

	delay( 5000 ) ;
}
