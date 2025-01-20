#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

#include <avr/io.h>

#define ENA PD5   // PWM Motor 1 (OC0B pe D5)
#define IN1 PD0   // Directie Motor 1
#define IN2 PD1   // Directie Motor 1

#define ENB PD6   // PWM Motor 2 (OC0A pe D6)
#define IN3 PD2   // Directie Motor 2
#define IN4 PD4   // Directie Motor 2

// Prototipuri de functii
void motor_init();
void motor1_forward(uint8_t speed);
void motor1_backward(uint8_t speed);
void motor2_forward(uint8_t speed);
void motor2_backward(uint8_t speed);

#endif
