#include "ddr_training_custom.h"
#define UART_PL01x_DR				   0x00	 /*  Data read or written from the interface. */
#define UART_PL01x_FR				   0x18	 /*  Flag register (Read only). */
#define UART_PL01x_FR_TXFF			  0x20
#define IO_WRITE(addr, val) (*(volatile unsigned int *)(addr) = (val))
#define IO_READ(addr) (*(volatile unsigned int *)(addr))
