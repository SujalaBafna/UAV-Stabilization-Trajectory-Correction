#ifndef MAIN_H
#define MAIN_H
#include <stdbool.h>
#include <stdint.h>

// Prototypes for external/board-specific functions (mocked in repo)
void sysinit(void);
void __disable_irq(void);
void __enable_irq(void);
void __HAL_RCC_GPIOA_CLK_ENABLE(void);
typedef struct { void *comm_protocol; } imu;
extern struct imu arduimu;
typedef void USART_TypeDef;
uint_least8_t UartWaitRxByte(USART_TypeDef * UART);

// PWM channel placeholders
typedef int PWM_Channel;

// timer placeholder
typedef int timer_t;
extern timer_t timer2;

// prototypes for mocked functions used in main
void pwm_init(PWM_Channel *ch, int a, int b, int c);
void pwm_duty_update(PWM_Channel *ch, int duty, int flag);
void timer_init(timer_t *t, int period_ms, void(*cb)(void));
void uart_init(void *c, uint32_t baud, void(*isr)(void));
void arduimu_init(void);
void arduimu_poll(void);

#endif
