#include "pid_control.h"

void pid_init(PID_Controller *pid, double kp, double ki, double kd, double setpoint, double output_min, double output_max) {
	pid->kp = kp;
	pid->ki = ki;
	pid->kd = kd;
	pid->setpoint = setpoint;
	pid->integral = 0.0;
	pid->prev_error = 0.0;
	pid->output_min = output_min;
	pid->output_max = output_max;
}

double pid_compute(PID_Controller *pid, double measured_value) {
	double error = pid->setpoint - measured_value;
	pid->integral += error;
	double derivative = error - pid->prev_error;
	
	double output = (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
	
	if (output > pid->output_max) {
		output = pid->output_max;
		} else if (output < pid->output_min) {
		output = pid->output_min;
	}

	pid->prev_error = error;
	return output;
}
