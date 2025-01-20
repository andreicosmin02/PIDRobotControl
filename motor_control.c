#include "motor_control.h"

void motor_init() {
	// Setare pinii de directie si PWM ca iesire
	DDRD |= (1 << ENA) | (1 << IN1) | (1 << IN2);
	 // Pinul ENB trebuie sa fie pe PORTD pentru OC0A/OC0B

	// Configurare PWM pe Timer0 pentru ENA (Motor 1) pe OC0B
	TCCR0A = (1 << WGM00) | (1 << WGM01) | (1 << COM0B1); // Fast PWM pe OC0B
	
	// Configurare PWM pe Timer0 pentru ENB (Motor 2) pe OC0A
	TCCR0A |= (1 << COM0A1); // Fast PWM pe OC0A
	
	TCCR0B |= (1 << CS01);   // Folosim acelasi prescaler 8 pentru PWM
}

// Roteste Motor 1 înainte la o anumita viteza
void motor1_forward(uint8_t speed) {
	PORTD |= (1 << IN1);  // IN1 la HIGH
	PORTD &= ~(1 << IN2); // IN2 la LOW
	OCR0B = speed;        // Seteaza viteza PWM pentru ENA (Motor 1)
}

// Roteste Motor 1 inapoi la o anumita viteza
void motor1_backward(uint8_t speed) {
	PORTD &= ~(1 << IN1); // IN1 la LOW
	PORTD |= (1 << IN2);  // IN2 la HIGH
	OCR0B = speed;        // Seteaza viteza PWM pentru ENA (Motor 1)
}

// Roteste Motor 2 inainte la o anumita viteza
void motor2_forward(uint8_t speed) {
	PORTD |= (1 << IN3);  // IN3 la HIGH
	PORTD &= ~(1 << IN4); // IN4 la LOW
	OCR0A = speed;        // Seteaza viteza PWM pentru ENB (Motor 2)
}

// Roteste Motor 2 înapoi la o anumita viteza
void motor2_backward(uint8_t speed) {
	PORTD &= ~(1 << IN3); // IN3 la LOW
	PORTD |= (1 << IN4);  // IN4 la HIGH
	OCR0A = speed;        // Seteaza viteza PWM pentru ENB (Motor 2)
}
