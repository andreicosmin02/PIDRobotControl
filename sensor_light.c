/*
 * sensor_light.c
 *
 * Created: 12/7/2024 3:59:12 PM
 *  Author: Marmelada
 */ 

#include "main_config.h"
#include "sensor_light.h"
#include <avr/io.h>
#include <util/delay.h>
#include "i2c_lib.h"

// Initializeaza senzorul AP3216
void ap3216_init(void) {
	// Activeaza modul ALS (Ambient Light Sensing)
	i2c_start();
	i2c_write(AP3216_I2C_ADDR << 1);  // Adresa slave + Write
	i2c_write(AP3216_REG_SYS_CONFIG); // Registrul de configurare
	i2c_write(0x03);                  // Activeaza ALS
	i2c_stop();
}

// Citeste lumina ambientala de la senzor
double ap3216_read_ambient_light(void) {
	uint8_t high_byte, low_byte;

	// Citeste High Byte
	i2c_start();
	i2c_write(AP3216_I2C_ADDR << 1);   // Adresa slave + Write
	i2c_write(AP3216_REG_ALS_HIGH);    // Registrul High Byte
	i2c_start();
	i2c_write((AP3216_I2C_ADDR << 1) | 1); // Adresa slave + Read
	high_byte = i2c_read_ack();         // Citeste byte-ul High
	i2c_stop();

	// Citeste Low Byte
	i2c_start();
	i2c_write(AP3216_I2C_ADDR << 1);   // Adresa slave + Write
	i2c_write(AP3216_REG_ALS_LOW);     // Registrul Low Byte
	i2c_start();
	i2c_write((AP3216_I2C_ADDR << 1) | 1); // Adresa slave + Read
	low_byte = i2c_read_nack();         // Citeste byte-ul Low
	i2c_stop();

	// Combina High si Low Byte intr-un uint16_t
	uint16_t als_data = (high_byte << 8) | low_byte;
	double ambient_light = (double) als_data * 0.35;
	return ambient_light;
}