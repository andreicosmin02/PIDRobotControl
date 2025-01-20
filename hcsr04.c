#include "hcsr04.h"
#include "main_config.h"

#include <util/delay.h>
#include <avr/interrupt.h>

#include "main_defines.h"
#include "main_func.h"

uint16_t get_hcsr04_distance(volatile uint8_t* port, volatile uint8_t* pin, uint8_t pin_trig, uint8_t pin_echo)
{
	// Configure TRIG as output and ECHO as input
	*port |= (1 << pin_trig);  // TRIG as output
	*port &= ~(1 << pin_echo); // Ensure ECHO is input

	// Generate 10-microsecond pulse on TRIG
	*port &= ~(1 << pin_trig); // TRIG LOW
	_delay_us(2);              // Ensure a short delay
	*port |= (1 << pin_trig);  // TRIG HIGH
	_delay_us(10);             // Duration of 10 microseconds
	*port &= ~(1 << pin_trig); // TRIG LOW

	// Wait for ECHO to go HIGH
	uint16_t timeout = 60000; // Timeout for waiting
	while (!(*pin & (1 << pin_echo))) {
		if (--timeout == 0) return 0; // Timeout: No valid response
	}

	// Clear Timer1 and start counting
	TCNT1 = 0;

	// Wait for ECHO to go LOW
	while (*pin & (1 << pin_echo)) 
	{
		if (TCNT1 > 60000) return 0; // Timeout if the signal is too long
	}

	// Read the timer value to get the duration of the HIGH signal
	uint16_t pulse_duration = TCNT1;

	// Convert duration to distance
	// Distance in cm = (Pulse duration in microseconds) * 0.034 / 2
	// Since TCNT1 counts at 2 ticks per microsecond:
	uint16_t distance = (pulse_duration / 2) * 0.034 / 2;

	return distance;
}