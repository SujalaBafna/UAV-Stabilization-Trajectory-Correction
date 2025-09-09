#include "timer.h"
void timer_init(Timer *t, int period_ms, void(*cb)(void)){
    (void)t; (void)period_ms; (void)cb;
    // mock: in embedded this would configure a hardware timer
}
