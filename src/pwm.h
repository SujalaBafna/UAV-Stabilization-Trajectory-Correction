#ifndef PWM_H
#define PWM_H
#include <stdint.h>

typedef int PWM_Channel;
extern PWM_Channel A0, A1, A6, A7, B1;
void pwm_init(PWM_Channel *ch, int a, int b, int c);
void pwm_duty_update(PWM_Channel *ch, int duty, int flag);
#endif