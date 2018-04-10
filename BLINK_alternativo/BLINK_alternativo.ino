#include <avr/io.h>
#include <util/delay.h>

#define led_Pin PB5

// write digital "high" to pin <pn> on port <prt>
#define DIGIWRITE_H(prt, pn) prt |= (1<<pn)

// write digital "low" to pin <pn> on port <prt>
#define DIGIWRITE_L(prt, pn) prt &= ~(1<<pn)


int main(void) {
  // DDRB is the "data direction register" for port B
    // the ATtinyX5 only has port B with usable pins
    // we set both LED pins to "output"
    DDRB |= (1 << led_Pin);// | (1 << PIN_LED2);

    // initially set the pins to "low"
    DIGIWRITE_L(PORTB, led_Pin);

    while(1) {
      // put your main code here, to run repeatedly:
      DIGIWRITE_L(PORTB, led_Pin);
      _delay_ms(500);
      DIGIWRITE_H(PORTB, led_Pin);
      _delay_ms(500);
    }
    
    return 0;
}
