#ifndef I2C_LIB_H_
#define I2C_LIB_H_

#include <stdint.h>

// Functii I2C
void i2c_init(void);
void i2c_start(void);
void i2c_stop(void);
void i2c_write(uint8_t data);
uint8_t i2c_read_ack(void);
uint8_t i2c_read_nack(void);



#endif /* I2C_LIB_H_ */