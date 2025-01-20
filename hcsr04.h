#ifndef HCSR04_H_
#define HCSR04_H_

#include <avr/io.h>

#define PIN_HCSR04_TRIG		PIND2
#define PIN_HCSR04_ECHO		PIND3

uint16_t get_hcsr04_distance(volatile uint8_t* port, volatile uint8_t* pin, uint8_t pin_trig, uint8_t pin_echo);



#endif /* HCSR04_H_ */