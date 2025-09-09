#include "pwm.h"
#include <stdio.h>
PWM_Channel A0, A1, A6, A7, B1;
void pwm_init(PWM_Channel *ch, int a, int b, int c){
    // mock init
    (void)ch; (void)a; (void)b; (void)c;
}
void pwm_duty_update(PWM_Channel *ch, int duty, int flag){
    // mock update - in real code this updates timer CCR registers
    (void)ch; (void)flag;
    // For desktop testing, optionally print
    // printf("PWM update: duty=%d\n", duty);
}
