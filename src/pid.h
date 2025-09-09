#ifndef PID_H
#define PID_H

typedef struct {
    float Kp;
    float Ki;
    float Kd;
    float prev_error;
    float integral;
    float output_limit;
} PID_Controller;

void PID_Init(PID_Controller *pid, float Kp, float Ki, float Kd, float output_limit);
float PID_Compute(PID_Controller *pid, float setpoint, float measurement, float dt);

#endif // PID_H
