#include "hi_uart.h"
#include <hi_lowpower.h>
#include <hi_stdlib.h>
#ifdef CONFIG_UART_DMA_SUPPORT
#include <hi_dma.h>
#endif
#include "hi_early_debug.h"
#include "uart.h"
#include "uart_drv.h"
#define UART_FR_BUSY (1 << 3)
#define UART_FR_TXFE (1 << 7)
#define UART_FR_RXFE (1 << 4)
#define WAIT_TIME 10000         /* wait 10 seconds */
#define CLKEN_UART2 6
#define CLKEN_UART2_BUS 9
#define OFFSET_14_BITS      14
#define UART_DR                     0x0
#define UART_FR                     0x18
#define UART_IBRD                   0x24
#define UART_FBRD                   0x28
#define UART_LCR_H                  0x2C
#define UART_CR                     0x30
#define UART_IFLS                   0x34
#define UART_IMSC                   0x38
#define UART_DMACR                  0x48
#define UART_DMA_DISABLE            0X04
#define UARTCR_CFG                  0x301     /* UART tx enable, rx enable, uart enable */
#ifndef UART_FR
#define UART_FR 0x18
#endif
typedef struct {
    hi_u16 ibrd;
    hi_u16 fbrd;
    hi_u16 lcr_h;
    hi_u16 cr;
    hi_u16 ifls;
} uart_regs;
#ifdef CONFIG_UART_DMA_SUPPORT
#else
#endif
#ifdef CONFIG_UART_DMA_SUPPORT
#else
#endif
#ifdef CONFIG_UART_DMA_SUPPORT
#endif
