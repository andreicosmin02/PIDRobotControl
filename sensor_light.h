/*
 * sensor_light.h
 *
 * Created: 12/7/2024 3:58:48 PM
 *  Author: Marmelada
 */ 


#ifndef SENSOR_LIGHT_H_
#define SENSOR_LIGHT_H_

#include <stdint.h>

// Adresa I2C a senzorului AP3216
#define AP3216_I2C_ADDR 0x1E

// Registre pentru control ?i date
#define AP3216_REG_SYS_CONFIG 0x00
#define AP3216_REG_ALS_HIGH   0x0C
#define AP3216_REG_ALS_LOW    0x0D

// Func?ii pentru senzorul AP3216
void ap3216_init(void);
double ap3216_read_ambient_light(void);


#endif /* SENSOR_LIGHT_H_ */