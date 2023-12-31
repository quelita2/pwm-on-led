﻿# PWM

The objective of the presented work is to design a program that uses PWM to progressively change the brightness intensity of an LED. It starts turned off and gradually increases its brightness up to its maximum. This process should repeat continuously.

## 🤖 Settings

|Simulation|
|----------|
![Simulation](./assets/simulation-pwm.png)

## Implementation in C

```c
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
```
 
Code Steps:

1. Configure pin PD6 as an output to connect the LED.
2. Configure registers TCCR0A and TCCR0B to set the non-inverting fast PWM mode using register OCR0A as comparison unit A and with no prescaling.
3. In the infinite loop while(1), you change the value of register OCR0A to control the PWM duty cycle, thereby altering the LED intensity. The duty cycle varies from 1% to 100% in 25% increments, with 200-millisecond intervals between each change.
   
The program will continue to repeat these steps indefinitely, progressively changing the LED's intensity in 1-second cycles between each duty cycle configuration.

## 🔬 Prática Laboratorial

In laboratory practice we work on analyzing the generation of signals using the timer, in the practical and basic example of turning on an LED.

## ✍️ Authors

- [Ernane Ferreira](https://github.com/ernanej) 🧑🏼‍💻
- [Quelita Míriam](https://github.com/quelita2) 👩🏼‍💻
- [Thiago Lopes](https://github.com/thiagonasmto) 🧑🏼‍💻

---

<div align="center">
  DCA0119 - Digital Systems (2023.1) <br/>
  Federal University of Rio Grande do Norte - Department of Computer and Automation Engineering (DCA).
</div>
