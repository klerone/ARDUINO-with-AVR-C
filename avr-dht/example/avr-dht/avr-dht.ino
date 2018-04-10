/*
*  Source: https://github.com/Jacajack/avr-dhtxx
*
*/

#include <avr/io.h>
#include <util/delay.h>
#include "dhtxx.h"

/** Just the setting for my board, you can ignore it **/
// write digital "high" to pin <pn> on port <prt>
#define DIGIWRITE_H(prt, pn) prt |= (1<<pn)

// write digital "low" to pin <pn> on port <prt>
#define DIGIWRITE_L(prt, pn) prt &= ~(1<<pn)

int main( )
{
  Serial.begin(57600);
  
  DDRD |= (1 << 3);
  DIGIWRITE_H(PORTD, 3);
  
  unsigned char ec; //Exit code
  int temp, humid; //Temperature and humidity

  while( 1 )
  {
    //Request DHT sensor to give it time to prepare data
    dhtxxconvert( DHTXX_DHT22, &PORTD, &DDRD, &PIND, ( 1 << 2 ) );

    _delay_ms( 1000 );

    //Read data from sensor to variables `temp` and `humid` (`ec` is exit code)
    ec = dhtxxread( DHTXX_DHT22, &PORTD, &DDRD, &PIND, ( 1 << 2 ), &temp, &humid );
	
	/** Reported data must be divede by 10 to get the decimal (only 1 decimal pressicion) **/
	Serial.print("Temperature: "); Serial.println((float)temp/10);
	Serial.print("Humidity: "); Serial.println((float)humid/10);
  }

  return 0;
}