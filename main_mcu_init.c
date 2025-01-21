#include "main_mcu_init.h"
#include "main_defines.h"

void port_init(void)
{	
	DDRD |= (1 << PIN_HCSR04_TRIG);	// Pinul TRIG ca output
	DDRD &= ~(1 << PIN_HCSR04_ECHO); // Pinul ECHO ca input

	PORTD = 0x00;
	PORTB = 0x00;
}

void timer1_init(void)
{
	TCCR1A |= 1 << WGM12;	// CTC Mode
	TCCR1B |= 1 << CS11;	// Prescaler 8
}

void init_devices(void)
{
	timer1_init();
	port_init();
}