#include "uart.h"
#include <stdio.h>
#include <stdint.h>
void uart_init(Comm *c, uint32_t baud, void(*isr)(void)){
    (void)c; (void)baud; (void)isr;
    // mock init
}
uint8_t mock_uart_receive(void){
    return 0;
}
