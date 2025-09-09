#include "pid.h"

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit) {
    pid->Kp = Kp;
    pid->Ki = Ki;
    pid->Kd = Kd;
    pid->prev_error = 0.0f;
    pid->integral = 0.0f;
    pid->output_limit = output_limit;
}

float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt) {
    float error = setpoint - measurement;
    pid->integral += error * dt;
    float derivative = 0.0f;
    if (dt > 0.0f) {
        derivative = (error - pid->prev_error) / dt;
    }
    float output = pid->Kp * error + pid->Ki * pid->integral + pid->Kd * derivative;
    // clamp
    if (output > pid->output_limit) output = pid->output_limit;
    if (output < -pid->output_limit) output = -pid->output_limit;
    pid->prev_error = error;
    return output;
}
