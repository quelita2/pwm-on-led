#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD |= (1 << PD6); //Fast PWM output at OC0A pin
  
  TCCR0A |= (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); //Non-Inverting Fast PWM mode 3 using OCR A unit
  TCCR0B |= (1 << CS00); // no prescaling
  
  while(1){
    OCR0A = 1; // Duty cycle of ~1%
    _delay_ms(200);

    OCR0A = 63; // Duty cycle of ~25%
    _delay_ms(200);

    OCR0A = 127; // Duty cycle of ~50%
    _delay_ms(200);

    OCR0A = 191; // Duty cycle of ~75%
    _delay_ms(200);

    OCR0A = 255; // Duty cycle of 100%
    _delay_ms(200);
  }
  
  return 0;
}

