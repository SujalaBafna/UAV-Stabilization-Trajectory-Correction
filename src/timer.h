#ifndef TIMER_H
#define TIMER_H
typedef int Timer;
void timer_init(Timer *t, int period_ms, void(*cb)(void));
#endif