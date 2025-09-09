#ifndef UART_H
#define UART_H
#include <stdint.h>
typedef struct {
    void *uart;
} Comm;
void uart_init(Comm *c, uint32_t baud, void(*isr)(void));
uint8_t mock_uart_receive(void);
#endif