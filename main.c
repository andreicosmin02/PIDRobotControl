#include "main_config.h"
#include "main_defines.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "main_mcu_init.h"
#include "nokia5110.h"
#include "hcsr04.h"
#include "sensor_light.h"
#include "i2c_lib.h"
#include "motor_control.h"
#include "pid_control.h"

#define PID_MIN 0.0
#define PID_MAX 255.0


int main(void) 
{
	init_devices();
	nokia_lcd_init();
	nokia_lcd_clear();
	i2c_init();         
	ap3216_init();     
	motor_init();
	
	// Se activeaza intreruperea
	SREG |= 1 << SREG_I;
	
	PID_Controller pid;
	pid_init(&pid, 5.0, 0.0, 0.0, 2000.0, PID_MIN, PID_MAX);

	
	 while (1) 
	 {
		 uint16_t distance = get_hcsr04_distance(&PORTD, &PIND, PIN_HCSR04_TRIG, PIN_HCSR04_ECHO);
		 double luminosity = ap3216_read_ambient_light();

		 double motor_speed = pid_compute(&pid, luminosity);
		 if (luminosity > pid.setpoint) 
		 {
			 motor_speed = 0.0;
		 }

		 motor1_forward((uint8_t)motor_speed);

		 // Afisare pe LCD
		 char distance_str[16];
		 snprintf(distance_str, sizeof(distance_str), "%d cm", (int)distance);
		 
		 char luminosity_str[16];
		 snprintf(luminosity_str, sizeof(luminosity_str), "%d lux", (int)luminosity);
		
		nokia_lcd_clear();
		
		nokia_lcd_write_string("Distanta:", 1);
		nokia_lcd_set_cursor(0, 10);
		nokia_lcd_write_string(distance_str, 1);
		nokia_lcd_set_cursor(0, 20);
		nokia_lcd_write_string("LUMINA:", 1);
		nokia_lcd_set_cursor(0, 30);
		nokia_lcd_write_string(luminosity_str, 1);
		
		nokia_lcd_render();

		
		 _delay_ms(100);
	 }
	return 0;
}