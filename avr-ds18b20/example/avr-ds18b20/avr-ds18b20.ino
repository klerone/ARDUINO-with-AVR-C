/*
*  Source: https://github.com/Jacajack/avr-ds18b20/wiki
* 
* Reads temperature data from sensor into an int16_t variable. 
* Returned value is actual temperature multiplied by 16
* So to get the decimal, you need to divide by 16
* 
* Date: 31-04-2016
*/

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#include <ds18b20.h>

int main( )
{
  Serial.begin(57600);
  int temp;

  while ( 1 )
  {
    //Start conversion (without ROM matching)
    ds18b20convert( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL );

    //Delay (sensor needs time to perform conversion)
    _delay_ms( 1000 );

    //Read temperature (without ROM matching)
    ds18b20read( &PORTB, &DDRB, &PINB, ( 1 << 0 ), NULL, &temp );

    //Somehow use data stored in `temp` variable
	Serial.print("temperature: ");
	Serial.println((double)temp/16);
  }

  return 0;
}