#ifndef PID_CONTROL_H_
#define PID_CONTROL_H_

#include <stdint.h>

// Structura PID
typedef struct {
	double kp;        // Coeficientul proportional
	double ki;        // Coeficientul integral
	double kd;        // Coeficientul derivativ
	double setpoint;  // Valoarea dorita
	double integral;  // Valoarea integrala acumulata
	double prev_error;// Eroarea anterioara
	double output_min;// Limita minima pentru iesire
	double output_max;// Limita maxima pentru iesire
} PID_Controller;

void pid_init(PID_Controller *pid, double kp, double ki, double kd, double setpoint, double output_min, double output_max);
double pid_compute(PID_Controller *pid, double measured_value);

#endif /* PID_CONTROL_H_ */