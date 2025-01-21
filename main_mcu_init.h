#ifndef MAIN_MCU_INIT_H_
#define MAIN_MCU_INIT_H_

#include <avr/wdt.h>
#include <avr/interrupt.h>

#include "main_config.h"

void port_init(void);
void timer1_init(void);
void init_devices(void);


#endif /* MAIN_MCU_INIT_H_ */