/*
 * i2c_lib.c
 *
 * Created: 12/7/2024 3:57:15 PM
 *  Author: Marmelada
 */ 

#include <avr/io.h>
//#include <util/twi.h>
#include "main_config.h"

void i2c_init() {
	// Seteaza frecventa I2C (de exemplu, 100 kHz)
	TWSR = 0x00; // Prescaler 1
	TWBR = ((F_CPU / 100000UL) - 16) / 2;

	// Activeaza I2C
	TWCR = (1 << TWEN);
}

void i2c_start() {
	TWCR = (1 << TWSTA) | (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
}

void i2c_stop() {
	TWCR = (1 << TWSTO) | (1 << TWEN) | (1 << TWINT);
}

void i2c_write(uint8_t data) {
	TWDR = data;
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
}

uint8_t i2c_read_ack() {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}

uint8_t i2c_read_nack() {
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
	return TWDR;
}
